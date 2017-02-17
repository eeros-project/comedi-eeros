#include "../include/Fqd.hpp"
#include <iostream>

using namespace comedi;

Fqd::Fqd(std::string id, 
					 void* libHandle,
					 std::string device,
					 uint32_t subDeviceNumber,
					 uint32_t channelA,
					 uint32_t channelB,
					 uint32_t channelZ,
					 double scale,
					 double offset,
					 double rangeMin,
					 double rangeMax,
					 std::string unit,
					 bool getDelta) : 
					 ScalableInput<double>(id, libHandle, scale, offset, rangeMin, rangeMax, unit), 
							      subDeviceNumber(subDeviceNumber), channelA(channelA), channelB(channelB), channelZ(channelZ) {
								
	ComediDevice *dev = ComediDevice::getDevice(device);
	this->deviceHandle = dev->getDeviceHandle();
	
	init();
}

void Fqd::init(unsigned int devInitValue){
	comedi_reset(deviceHandle, subDeviceNumber);
	
	//TODO init value
	comedi_data_write(deviceHandle, subDeviceNumber, 0, 0, 0, devInitValue); // set initial counter value by writing to channel 0
	comedi_data_write(deviceHandle, subDeviceNumber, 1, 0, 0, devInitValue); // set "load a" register to initial_value by writing to channel 1
	comedi_data_write(deviceHandle, subDeviceNumber, 2, 0, 0, devInitValue); // set "load b" register to initial_value by writing to channel 2
	
	comedi_set_gate_source(deviceHandle, subDeviceNumber, 0, 0, NI_GPCT_DISABLED_GATE_SELECT);
	comedi_set_gate_source(deviceHandle, subDeviceNumber, 0, 1, NI_GPCT_DISABLED_GATE_SELECT);
	
	comedi_set_other_source(deviceHandle, subDeviceNumber, 0, NI_GPCT_SOURCE_ENCODER_A, NI_GPCT_PFI_OTHER_SELECT(channelA));
	comedi_set_other_source(deviceHandle, subDeviceNumber, 0, NI_GPCT_SOURCE_ENCODER_B, NI_GPCT_PFI_OTHER_SELECT(channelB));
	comedi_set_other_source(deviceHandle, subDeviceNumber, 0, NI_GPCT_SOURCE_ENCODER_Z, NI_GPCT_PFI_OTHER_SELECT(channelZ));
	
	lsampl_t counterMode;
	counterMode = (NI_GPCT_COUNTING_MODE_QUADRATURE_X4_BITS | NI_GPCT_COUNTING_DIRECTION_HW_UP_DOWN_BITS);
	if (channelZ != NI_GPCT_DISABLED_GATE_SELECT) counterMode |= (NI_GPCT_INDEX_ENABLE_BIT | NI_GPCT_INDEX_PHASE_HIGH_A_HIGH_B_BITS);
	comedi_set_counter_mode(deviceHandle, subDeviceNumber, 0, counterMode);
	
	comedi_arm(deviceHandle, subDeviceNumber, NI_GPCT_ARM_IMMEDIATE);
}

double Fqd::get() {
	lsampl_t data = 0;
	comedi_data_read(deviceHandle, subDeviceNumber, 0, 0, 0, &data);
	signed int sign = static_cast<signed int>(data);
	return (static_cast<double>(sign)) / scale + offset;
}

void Fqd::reset() {	
	init();
}

extern "C"{
	eeros::hal::ScalableInput<double> *createFqd(std::string id, void* libHandle, std::string device, uint32_t subDeviceNumber, uint32_t channelA, uint32_t channelB, uint32_t channelZ, 
						     double scale, double offset, double rangeMin, double rangeMax, std::string unit){
		return new comedi::Fqd(id, libHandle, device, subDeviceNumber, channelA, channelB, channelZ, scale, offset, rangeMin, rangeMax, unit);
	}
	
	void resetFqd(comedi::Fqd *obj){
		obj->reset();
	}
}

#include <AnalogIn.hpp>

using namespace comedi;

//TODO untested!!

AnalogIn::AnalogIn(std::string id,
					 void* libHandle,
					 std::string device,
					 uint32_t subDeviceNumber,
					 uint32_t channel,
					 double scale,
					 double offset,
					 double rangeMin,
					 double rangeMax,
					 std::string unit
		  ) : ScalableInput<double>(id, libHandle, scale, offset, rangeMin, rangeMax, unit),
		      subDeviceNumber(subDeviceNumber), channel(channel){
	ComediDevice *dev = ComediDevice::getDevice(device);
	this->deviceHandle = dev->getDeviceHandle();
}

double AnalogIn::get() {
	lsampl_t data = 0;
	comedi_data_read(deviceHandle, subDeviceNumber, channel, 0, AREF_GROUND, &data);
	double inVal = static_cast<double>(data);
	if(inVal > maxIn) inVal = maxIn;
	if(inVal < minIn) inVal = minIn;
	
	return inVal / scale + offset;
}

extern "C"{
	eeros::hal::ScalableInput<double> *createAnalgIn(std::string id, 
							void* libHandle, 
							std::string device, 
							uint32_t subDeviceNumber, 
							uint32_t channel, 
							double scale, 
							double offset, 
							double rangeMin, 
							double rangeMax, 
							std::string unit){
		return new comedi::AnalogIn(id, libHandle, device, subDeviceNumber, channel, scale, offset, rangeMin, rangeMax, unit);
	}
}

#include <AnalogOut.hpp>

using namespace comedi;

AnalogOut::AnalogOut(std::string id,
					 void* libHandle,
					 std::string device,
					 uint32_t subDeviceNumber,
					 uint32_t channel,
					 double scale,
					 double offset,
					 double rangeMin,
					 double rangeMax,
					 std::string unit
		    ) : ScalableOutput<double>(id, libHandle, scale, offset, rangeMin, rangeMax, unit), subDeviceNumber(subDeviceNumber), channel(channel) {
	ComediDevice *dev = ComediDevice::getDevice(device);
	this->deviceHandle = dev->getDeviceHandle();
}

double AnalogOut::get() {
	lsampl_t data = 0;
	comedi_data_read(deviceHandle, subDeviceNumber, channel, 0, AREF_GROUND, &data);
	return (static_cast<int>(data) - offset) / scale;
}

void AnalogOut::set(double voltage) {
	int32_t value = static_cast<int32_t>((voltage - offset)/scale);
	
	if(value > maxOut) value = maxOut;
	if(value < minOut) value = minOut;
	
	lsampl_t data = static_cast<lsampl_t>(value);
	comedi_data_write(deviceHandle, subDeviceNumber, channel, 0, AREF_GROUND, data);

// TODO old code below: remove after testing
// 	if(value > maxVoltage) value = maxVoltage;
// 	if(value < minVoltage) value = minVoltage;
// 	lsampl_t data = static_cast<lsampl_t>(value * maxValue / (maxVoltage - minVoltage) + maxValue / 2.0);
}

extern "C"{
	eeros::hal::ScalableOutput<double> *createAnalogOut(std::string id, void* libHandle, std::string device, uint32_t subDeviceNumber, uint32_t channel, 
							    double scale, double offset, double rangeMin, double rangeMax, std::string unit){
		return new comedi::AnalogOut(id, libHandle, device, subDeviceNumber, channel, scale, offset, rangeMin, rangeMax, unit);
	}
}

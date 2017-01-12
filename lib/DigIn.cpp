#include <DigIn.hpp>

using namespace comedi;

DigIn::DigIn(std::string id, void* libHandle, std::string device, uint32_t subDeviceNumber, uint32_t channel, bool inverted) : 
				Input<bool>(id, libHandle), 
				subDeviceNumber(subDeviceNumber), channel(channel), inverted(inverted) {
	ComediDevice *dev = ComediDevice::getDevice(device);
	this->deviceHandle = dev->getDeviceHandle();
	
	comedi_dio_config(deviceHandle, subDeviceNumber, channel, COMEDI_INPUT);
}

bool DigIn::get() {
	lsampl_t data = 0;
	bool value;
	comedi_dio_read(deviceHandle, subDeviceNumber, channel, &data);
	value = static_cast<bool>(data);
	if(inverted) value = !value;
	return value;
}

extern "C" eeros::hal::Input<bool> *createDigIn(std::string id, void* libHandle, std::string device, uint32_t subDeviceNumber, uint32_t channel, bool inverted){
	return new comedi::DigIn(id, libHandle, device, subDeviceNumber, channel, inverted);
}
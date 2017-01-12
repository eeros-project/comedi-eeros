#include <DigOut.hpp>

using namespace comedi;

DigOut::DigOut(std::string id, void* libHandle, std::string device, uint32_t subDeviceNumber, uint32_t channel, bool inverted) : 
					Output<bool>(id, libHandle), subDeviceNumber(subDeviceNumber), channel(channel), inverted(inverted) {
	ComediDevice *dev = ComediDevice::getDevice(device);
	this->deviceHandle = dev->getDeviceHandle();
	
	comedi_dio_config(deviceHandle, subDeviceNumber, channel, COMEDI_OUTPUT);
}

bool DigOut::get() {
	lsampl_t data = 0;
	bool value;
	comedi_dio_read(deviceHandle, subDeviceNumber, channel, &data);
	value = static_cast<bool>(data);
	if(inverted) value = !value;
	return value;
}

void DigOut::set(bool value) {
	if(inverted) value = !value;
	comedi_dio_write(deviceHandle, subDeviceNumber, channel, value);
}

extern "C" eeros::hal::Output<bool> *createDigOut(std::string id, void* libHandle, std::string device, uint32_t subDeviceNumber, uint32_t channel, bool inverted){
	return new comedi::DigOut(id, libHandle, device, subDeviceNumber, channel, inverted);
}

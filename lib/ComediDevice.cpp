#include <ComediDevice.hpp>
#include <eeros/core/EEROSException.hpp>

using namespace comedi;

ComediDevice::ComediDevice(std::string deviceNode) {
	it = comedi_open(deviceNode.c_str());
	if(!it) {
		throw eeros::EEROSException("Can't open device \"" +  deviceNode + "\"!"); // TODO define error number and send error message to logger
	}
}

ComediDevice::~ComediDevice() {
	comedi_close(it);
}

comedi_t* ComediDevice::getDeviceHandle() {
	return it;
} 

#include "../include/ComediDevice.hpp"
#include <eeros/core/Fault.hpp>

using namespace comedi;

std::map<std::string, ComediDevice *> ComediDevice::devices;

ComediDevice::ComediDevice(std::string deviceNode) {
	auto devIt = devices.find(deviceNode);
	if(devIt != devices.end()){
		throw new eeros::Fault("device already open, claim already opened device via getDevice()");
	}
	it = comedi_open(deviceNode.c_str());
	if(!it) {
		throw eeros::Fault("Can't open device \"" +  deviceNode + "\"!"); // TODO define error number and send error message to logger
	}
	devices[deviceNode] = this;
}

ComediDevice::~ComediDevice() {
	comedi_close(it);
	devices.clear();
}

comedi_t* ComediDevice::getDeviceHandle() {
	return it;
} 

ComediDevice* ComediDevice::getDevice(std::string deviceNode) {
	auto devIt = devices.find(deviceNode);
	if(devIt != devices.end()){
		return devIt->second;
	}
	else{
		return new ComediDevice(deviceNode);
	}
}


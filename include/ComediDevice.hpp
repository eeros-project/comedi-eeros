#ifndef COMEDI_EEROS_DEVICE_HPP_
#define COMEDI_EEROS_DEVICE_HPP_

#include <string>
#include <comedilib.h>
#include <map>

namespace comedi {

	class ComediDevice {
	public:
		ComediDevice(std::string deviceNode);
		virtual ~ComediDevice();
		
		comedi_t* getDeviceHandle();
		static ComediDevice* getDevice(std::string deviceNode);

        private:
		comedi_t *it;
		static std::map<std::string, comedi::ComediDevice *> devices;
	};
};

#endif /* COMEDI_EEROS_DEVICE_HPP_ */ 

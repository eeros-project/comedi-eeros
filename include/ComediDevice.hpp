#ifndef COMEDI_EEROS_DEVICE_HPP_
#define COMEDI_EEROS_DEVICE_HPP_

#include <string>
#include <comedilib.h>

namespace comedi {

        class ComediDevice {
	public:
		ComediDevice(std::string deviceNode);
		virtual ~ComediDevice();
		
		comedi_t* getDeviceHandle();

        private:
		comedi_t *it;
	};
};

#endif /* COMEDI_EEROS_DEVICE_HPP_ */ 

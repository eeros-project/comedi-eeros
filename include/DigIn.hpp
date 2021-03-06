#ifndef COMEDI_EEROS_DIGIN_HPP_
#define COMEDI_EEROS_DIGIN_HPP_

#include <string>
#include <comedilib.h>
#include <eeros/hal/Input.hpp>
#include "ComediDevice.hpp"

namespace comedi {
	class DigIn : public eeros::hal::Input<bool> {
	public:
		DigIn(std::string id, void* libHandle, std::string device, uint32_t subDeviceNumber, uint32_t channel, bool inverted = false);
		virtual bool get();
		
	private:
		comedi_t* deviceHandle;
		uint32_t subDeviceNumber;
		uint32_t channel;
		
		bool inverted;
	};
};

extern "C"{
	eeros::hal::Input<bool> *createDigIn(std::string id, void* libHandle, std::string device, uint32_t subDeviceNumber, uint32_t channel, bool inverted);
}

#endif /* COMEDI_EEROS_DIGIN_HPP_ */

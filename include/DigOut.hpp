#ifndef COMEDI_EEROS_DIGOUT_HPP_
#define COMEDI_EEROS_DIGOUT_HPP_

#include <string>
#include <comedilib.h>
#include <eeros/hal/Output.hpp>
#include <ComediDevice.hpp>

namespace comedi {
	class DigOut : public eeros::hal::Output<bool> {
	public:
		DigOut(std::string id, void* libHandle, std::string device, uint32_t subDeviceNumber, uint32_t channel, bool inverted = false);
		virtual bool get();
		virtual void set(bool value);
		
	private:
		comedi_t* deviceHandle;
		uint32_t subDeviceNumber;
		uint32_t channel;
		
		bool inverted;
	};
};

extern "C"{
	eeros::hal::Output<bool> *createDigOut(std::string id, void* libHandle, std::string device, uint32_t subDeviceNumber, uint32_t channel, bool inverted);
}

#endif /* COMEDI_EEROS_DIGOUT_HPP_ */

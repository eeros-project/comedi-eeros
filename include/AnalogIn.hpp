#ifndef COMEDI_EEROS_ANALOGIN_HPP_
#define COMEDI_EEROS_ANALOGIN_HPP_

#include <string>
#include <limits>
#include <comedilib.h>
#include <eeros/hal/ScalableInput.hpp>
#include <ComediDevice.hpp>

namespace comedi {
	class AnalogIn : public eeros::hal::ScalableInput<double> {
	public:
		AnalogIn(std::string id, void* libHandle, std::string device, uint32_t subDeviceNumber, uint32_t channel, double scale = 1, double offset = 0, double rangeMin = std::numeric_limits<double>::min(), double rangeMax = std::numeric_limits<double>::max(), std::string unit = "");
		virtual double get();
		
	private:
		comedi_t* deviceHandle;
		uint32_t subDeviceNumber;
		uint32_t channel;
	};
};


extern "C"{
	eeros::hal::ScalableInput<double> *createAnalgIn(std::string id, void* libHandle, std::string device, uint32_t subDeviceNumber, uint32_t channel, double scale, double offset, double rangeMin, double rangeMax, std::string unit);
}

#endif /* COMEDI_EEROS_ANALOGIN_HPP_ */

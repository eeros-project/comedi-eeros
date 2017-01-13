#ifndef COMEDI_EEROS_FQD_HPP_
#define COMEDI_EEROS_FQD_HPP_

#include <string>
#include <limits>
#include <comedilib.h>
#include <eeros/hal/ScalableInput.hpp>
#include <ComediDevice.hpp>

namespace comedi {
	class Fqd : public eeros::hal::ScalableInput<double> {
	public:
		Fqd(std::string id, void* libHandle, std::string device, uint32_t subDeviceNumber, uint32_t channelA, uint32_t channelB, uint32_t channelZ, 
		    double scale = 1, double offset = 0, 
		    double rangeMin = std::numeric_limits<double>::min(), double rangeMax = std::numeric_limits<double>::max(), 
		    std::string unit = "", bool getDelta = false);
		virtual double get();
		virtual void reset();
		
	private:
		void init(unsigned int devInitValue = 0);
		comedi_t* deviceHandle;
		uint32_t subDeviceNumber;
		uint32_t channelA;
		uint32_t channelB;
		uint32_t channelZ;
		lsampl_t counter_mode;
	};
};

extern "C"{
	eeros::hal::ScalableInput<double> *createFqd(std::string id, void* libHandle, std::string device, uint32_t subDeviceNumber, 
						     uint32_t channelA, uint32_t channelB, uint32_t channelZ, double scale, double offset, 
						     double rangeMin, double rangeMax, std::string unit);
	void resetFqd(comedi::Fqd *obj);
}

#endif /* COMEDI_EEROS_FQD_HPP_ */

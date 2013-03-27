#ifndef RelativeHMC6352_H
#define RelativeHMC6352_H


#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#include <cmath>

class RelativeHMC6352
{
	public:
		RelativeHMC6352();
        void set_north();
        float angle_raw();
        float angle();
	private:
		float _north;
};

#endif

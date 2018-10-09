#ifndef __AHRS__
#define __AHRS__

#include "ch.hpp"
#include "hal.h"

using namespace chibios_rt;

class AHRSDataGeneric {
public:
	float q[4];
	float *getQuatern(void);
	AHRSDataGeneric(void);
};

#endif
#include "ch.hpp"
#include "hal.h"

#include "AHRS.hpp"

float * AHRSDataGeneric::getQuatern(void) {
	return q;
}

AHRSDataGeneric::AHRSDataGeneric(void) : q({1.0f, 0.0f, 0.0f, 0.0f}) {}
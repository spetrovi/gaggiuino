#ifndef THERMOCOUPLE_H
#define THERMOCOUPLE_H

#include "pindef.h"

#include <Adafruit_MAX31865.h>
Adafruit_MAX31865 thermocouple = Adafruit_MAX31865(thermoCS);

static inline void thermocoupleInit(void) {
thermocouple.begin(MAX31865_2WIRE);
}

static inline float readCelsius(void) {
#define RREF      430.0
#define RNOMINAL  100.0  
return thermocouple.temperature(RNOMINAL, RREF);

}

#endif


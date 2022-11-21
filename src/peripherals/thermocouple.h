#ifndef THERMOCOUPLE_H
#define THERMOCOUPLE_H

#include "pindef.h"

#if defined SINGLE_BOARD
  #include <Adafruit_MAX31865.h>
  Adafruit_MAX31865 thermocouple = Adafruit_MAX31865(thermoCS, thermoDI, thermoDO, thermoCLK);
#endif

static inline void thermocoupleInit(void) {
#if defined SINGLE_BOARD
  thermocouple.begin(MAX31865_2WIRE);
#endif
}

static inline float readCelsius(void) {
#if defined SINGLE_BOARD  
  #define RREF      430.0
  #define RNOMINAL  100.0  
  return thermocouple.temperature(RNOMINAL, RREF);
#endif
}

#endif


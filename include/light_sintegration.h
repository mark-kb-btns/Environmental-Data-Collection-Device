#include <Arduino.h>

#ifndef LIGHT_SINTEGRATION_H_INCLUDED
#define LIGHT_SINTEGRATION_H_INCLUDED




class LightSensor {
  private:
    int sensorPin;

  public:
    LightSensor(int pin);
    float readLight();
};

#endif // LIGHT_SINTEGRATION_H_INCLUDED

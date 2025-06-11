#include "light_sintegration.h"
#include <math.h>
#include <Arduino.h> // or #include <WProgram.h>


LightSensor::LightSensor(int pin) {
  sensorPin = pin;
}

float LightSensor::readLight() {
  int sensorValue = analogRead(sensorPin);
  float Rsensor = (float)(1023 - sensorValue) * 10 / sensorValue;

  // Print sensor and resistance values for debugging (optional)
  // Serial.print("The analog read data is: ");
  // Serial.println(sensorValue);
  // Serial.print("The sensor resistance is: ");
  // Serial.println(Rsensor);

  return Rsensor; // Return the calculated light intensity
}

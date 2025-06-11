/*
  Configuration taken from: Refrains : https://create.arduino.cc/projecthub/mircemk/diy-air-quality-monitor-with-sharp-gp2y1010au0f-sensor-7b0262
  Sensor: Sharp Optical Dust Sensor (GP2Y1010AU0F)

*/

#include "dust_sintegration.h"
#include <Arduino.h> 


SHARP::SHARP(int measurePin, int ledPin) {
  sensorPin_third = measurePin;
  sensorPin_fourth = ledPin;
}

float SHARP::readDust() {

    int samplingTime = 280;
    int deltaTime = 40;
    int sleepTime = 9680;

    float voMeasured = 0;
    float calcVoltage = 0;
    float dustDensity = 0;


  digitalWrite(sensorPin_fourth,LOW); // power on the LED
  delayMicroseconds(samplingTime);

  voMeasured = analogRead(sensorPin_third); // read the dust value

  delayMicroseconds(deltaTime);
  digitalWrite(sensorPin_fourth,HIGH); // turn the LED off
  delayMicroseconds(sleepTime);

  // 0 - 5V mapped to 0 - 1023 integer values
  // recover voltage
  calcVoltage = voMeasured * (5.0 / 1024.0);

  // linear eqaution taken from http://www.howmuchsnow.com/arduino/airquality/
  // Chris Nafis (c) 2012
  dustDensity = 170 * calcVoltage - 0.1;

  return dustDensity; // Return the calculated dust intensity
}

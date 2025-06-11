#include "hnt_sintegration.h"
#include <Arduino.h> // or #include <WProgram.h>
#include <dht11.h>


DHT11::DHT11(int pin) {
  sensorPin_second = pin;
}

int DHT11::readhnt() {
  dht11 myDHT11;
  int chk = myDHT11.read(sensorPin_second);

  Serial.print("Read sensor: ");
  switch (chk)
  {
    case DHTLIB_OK:
    Serial.println("OK");
    break;
    case DHTLIB_ERROR_CHECKSUM:
    Serial.println("Checksum error");
    break;
    case DHTLIB_ERROR_TIMEOUT:
    Serial.println("Time out error");
    break;
    default:
    Serial.println("Unknown error");
    break;
  }

}

double DHT11::humidity() {
    dht11 myDHT11;
    myDHT11.read(sensorPin_second);
    return ((float)myDHT11.humidity);
}

double DHT11::temperature() {
    dht11 myDHT11;
    myDHT11.read(sensorPin_second);
    return ((float)myDHT11.temperature);
}



double DHT11::fahrenheit(double celsius) {
  return ((float)1.8 * celsius + 32);
}

double DHT11::kelvin(double celsius){
  return ((float)celsius + 273.15);
}

double DHT11::dewPoint(double celsius, double humidity){
  // (1) Saturation Vapor Pressure = ESGG(T)
  double RATIO = 373.15 / (273.15 + celsius);
  double RHS = -7.90298 * (RATIO - 1);
  RHS += 5.02808 * log10(RATIO);
  RHS += -1.3816e-7 * (pow(10, (11.344 * (1 - 1/RATIO ))) - 1) ;
  RHS += 8.1328e-3 * (pow(10, (-3.49149 * (RATIO - 1))) - 1) ;
  RHS += log10(1013.246);

        // factor -3 is to adjust units - Vapor Pressure SVP * humidity
  double VP = pow(10, RHS - 3) * humidity;

        // (2) DEWPOINT = F(Vapor Pressure)
  double T = log(VP/0.61078);   // temp var
  return ((float)(241.88 * T) / (17.558 - T));
}

double DHT11::dewPointFast(double celsius, double humidity){
  double a = 17.271;
  double b = 237.7;
  double temp = (a * celsius) / (b + celsius) + log(humidity*0.01);
  double Td = ((float)(b * temp) / (a - temp));
  return Td;
}




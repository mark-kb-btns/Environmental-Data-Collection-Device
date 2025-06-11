#ifndef HNT_SINTEGRATION_H_INCLUDED
#define HNT_SINTEGRATION_H_INCLUDED

class DHT11 {
  private:
    int sensorPin_second;

  public:
    DHT11(int pin_second);
    int readhnt();
    double temperature();
    double humidity();
    double fahrenheit(double celsius);
    double kelvin(double celsius);
    double dewPoint(double celsius, double humidity);
    double dewPointFast(double celsius, double humidity);
};


#endif // HNT_SINTEGRATION_H_INCLUDED





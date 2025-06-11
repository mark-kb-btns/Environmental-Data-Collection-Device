#ifndef DUST_SINTEGRATION_H_INCLUDED
#define DUST_SINTEGRATION_H_INCLUDED


class SHARP {
  private:
    int sensorPin_third;
    int sensorPin_fourth;

  public:
    SHARP(int pin_third, int pin_fourth);
    float readDust();
};

#endif // DUST_SINTEGRATION_H_INCLUDED

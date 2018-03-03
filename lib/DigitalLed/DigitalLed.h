#include <Arduino.h>

const bool LED_CONFIG_SOURCE = true;
const bool LED_CONFIG_SINK = false;

class DigitalLed
{
public:
  DigitalLed(int p, int s, bool c);
  void set(int s);
  void high(void);
  void low(void);
  void toggle(void);

private:
  bool _configSource;
  int _pin;
  int _state;
};
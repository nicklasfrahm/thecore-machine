#include "DigitalLed.h"

DigitalLed::DigitalLed(int p, int s, bool c = true)
    : _pin(p), _state(s), _configSource(c) {
  pinMode(this->_pin, OUTPUT);
  this->set(this->_state);
};

void DigitalLed::set(int s) {
  this->_state = s;
  if (this->_configSource) {
    digitalWrite(this->_pin, s ? HIGH : LOW);
  } else {
    digitalWrite(this->_pin, s ? LOW : HIGH);
  }
}

void DigitalLed::high(void) { this->set(HIGH); }

void DigitalLed::low(void) { this->set(LOW); }

void DigitalLed::toggle(void) { this->set(this->_state ? LOW : HIGH); }
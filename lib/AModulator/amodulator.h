#ifndef amodulator_h
#define amodulator_h

#include <Arduino.h>
#include <mcp4141.h>

class AMODULATOR
{
public:
  AMODULATOR(uint8_t, uint8_t);
  void init();
  void modulate(uint8_t);
private:
  uint8_t pwm_pin;
  MCP4141 pot;
};

#endif

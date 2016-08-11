#include "amodulator.h"

AMODULATOR::AMODULATOR(uint8_t pwm, uint8_t cp):pot(cp){
  pwm_pin = pwm;
}

void AMODULATOR::init(){
  pinMode(pwm_pin,OUTPUT);
  analogWrite(pwm_pin,128);
}

void AMODULATOR::modulate(uint8_t inp){
  pot.set(127-inp);
}

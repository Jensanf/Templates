#ifndef LED_H
#define LED_H
#include "utils.hpp"

class Led
{
public:
	Led(GPIO_TypeDef &portName, unsigned int pinNum) : port(portName),
		pin(pinNum) {};
	inline void Toggle() const { utils::toggleBit(port.ODR, pin); }
	inline void SwitchOn() const { utils::setBit(port.ODR, pin); }
	inline void SwitchOff() const { utils::clearBit(port.ODR, pin); }
private:
	GPIO_TypeDef &port;
	unsigned int pin;
};
#endif
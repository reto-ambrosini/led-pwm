#include <Arduino.h>
#include "avr8-stub.h"

// switch

#define S_1 62
#define S_2 63
#define S_3 64
#define S_4 65

// LED

#define LED_1 66
#define LED_2 67
#define LED_3 68
#define LED_4 69

// pwm

#define LED_PWM 12

void setup() 
{
	debug_init();
	pinMode(LED_1,OUTPUT);
}

void loop() 
{
	uint8_t acceso;

	acceso=digitalRead(S_1)^0x01;
	digitalWrite(LED_1,acceso);

	analogWrite(LED_PWM,20);
}
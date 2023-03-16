#include <Arduino.h>

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
	Serial.begin(9600);
	pinMode(LED_1,OUTPUT);

}

void loop() 
{
	uint8_t acceso;
	uint8_t scrivi;
	uint8_t	valore_pwm=50;
	float duty;
	static unsigned long ultimo_print=0;
	
	scrivi=digitalRead(S_2);
	acceso=digitalRead(S_1)^0x01;
	digitalWrite(LED_1,acceso);

	analogWrite(LED_PWM,valore_pwm);
	duty=valore_pwm/255.0*100;

	if (scrivi==0)
	{
		if (millis()>(ultimo_print+1000))
		{
			ultimo_print=millis();
			Serial.print("duty cycle = ");
			Serial.print(duty);
			Serial.print("%");
			Serial.println();
		}
	}

	
}
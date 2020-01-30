/**
  ******************************************************************************
  * @file    main.c
  * @author  Ac6
  * @version V1.0
  * @date    01-December-2013
  * @brief   Default main function.
  ******************************************************************************
*/


#include "stm32f4xx.h"
#include "LCD.h"
			

int main(void)
{
	custom_drivers::LCD lcd;

	lcd.enable_port(GPIOB);
	lcd.enable_port(GPIOD);
	lcd.enable_port(GPIOE);

	lcd.enable_port(GPIOA);
	lcd.configure_pin_for_output(GPIOA,6);
	lcd.configure_pin_for_output(GPIOA,7);

	GPIOA->ODR &= (1<<6);
	GPIOA->ODR &= (1<<7);


	lcd.initialize();
	char greetings[] = "HELLO WORLD";
	lcd.send_string(greetings);

	while(1){

	}
}

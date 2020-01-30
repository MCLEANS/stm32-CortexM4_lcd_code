/*
 * LCD.h
 *
 *  Created on: Aug 24, 2019
 *      Author: MCLEANS
 */

#ifndef LCD_H_
#define LCD_H_

#define D0PORT	GPIOD
#define D0PIN	7
#define D1PORT 	GPIOD
#define D1PIN 	5
#define D2PORT	GPIOD
#define D2PIN	14
#define D3PORT	GPIOD
#define D3PIN	2
#define D4PORT	GPIOE
#define D4PIN	7
#define D5PORT	GPIOE
#define D5PIN	9
#define D6PORT	GPIOE
#define D6PIN	11
#define D7PORT	GPIOE
#define D7PIN	13
#define ENABLEPORT	GPIOB
#define ENABLEPIN	12
#define RWPORT	GPIOB
#define RWPIN	14
#define RSPORT GPIOB
#define RSPIN 1

#define TIMEDELAYBEFOREENABLE 400000
#define TIMEDELAYBEFOREDISABLE  8000000

#include "stm32f4xx.h"
#include "stdio.h"

namespace custom_drivers {



class LCD {
private:
	int duration = 0;
	char data[16];
	int row = 0;
	int column = 0;





public:
	LCD();
	virtual ~LCD();
	void enable_port(GPIO_TypeDef* PORT);
	void configure_pin_for_output(GPIO_TypeDef* PORT, uint8_t PIN);
	void configure_pins();
	void initialize();
	void delay_ms(int duration);
	void send_bit_to_pin(GPIO_TypeDef* PORT, uint8_t PIN, uint8_t state);
	void send_byte(char byte);
	void enable();
	void set_to_read_mode();
	void set_to_write_mode();
	void set_to_instruction_mode();
	void set_to_character_mode();
	void send_character(char character);
	void send_instruction(char byte);
	void clear();
	void newline();
	void send_string(char *data);
	void set_cursor_to_location(int row, int column);


};

} /* namespace custom_drivers */

#endif /* LCD_H_ */

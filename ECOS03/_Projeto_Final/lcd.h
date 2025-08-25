#include "STM32F10x.h"
#include <cmsis_os.h>

#ifndef LCD_H
	#define LCD_H

	void delay_ms(uint16_t t);
	void lcdDataNew(unsigned char valor);
	void lcd_putValue(unsigned char value);
	void lcdCommand(unsigned char cmd);
	void lcdData(unsigned char data);
	void lcdString(char * str);
	void tempo(uint16_t t);
	void lcdInit();
	void lcdPosition(int line, int col);
	void lcdPositionNew(int line, int col);
	void lcdInt(int val) ;
	void lcdTempo(int hh, int mm, int ss);
	void lcdIntNew(int val);
	void lcdStringNew(char msg[]);
	void lcdTempoNew(int hh, int mm, int ss);
	void lcdClear();
	void InternalLcdDataSwitch(unsigned char *valor, unsigned char indx);
	void lcdRepeatChar(unsigned char indx);
	void lcdDataSwitch(unsigned char valor, unsigned char indx);
	int lcdReuseChar(unsigned char valor);
	void lcdInitNew();
	void delay_us(uint16_t t);
        
#endif
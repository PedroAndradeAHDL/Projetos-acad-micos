#include <stdint.h>
#include "STM32F10x.h"
#include <cmsis_os.h>

#include "lcd.h"
#include "DataStructList.h"
#include <stdlib.h>

#define RS 0
#define EN 1
#define RW 2

//LCD display
#define LCD_RS 15
#define LCD_EN 12

int cnt; //contador de controlador de posi��o do novo lcd
unsigned char index; //contador de index de memoria do novo lcd
unsigned char constCommand;
unsigned char position;

node *head = NULL;




const unsigned char A[8] = {0x00, 0x04, 0x0a, 0x11, 0x1F, 0x11, 0x11, 0x11};
const unsigned char B[8] = {0x00, 0x0F, 0x11, 0x11, 0x0F, 0x11, 0x11, 0x0F};
const unsigned char C[8] = {0x00, 0x0e, 0x11, 0x01, 0x01, 0x01, 0x11, 0x0e};
const unsigned char D[8] = {0x00, 0x0F, 0x11, 0x11, 0x11, 0x11, 0x11, 0x0F};
const unsigned char E[8] = {0x00, 0x1F, 0x01, 0x01, 0x0F, 0x01, 0x01, 0x1F};
const unsigned char F[8] = {0x00, 0x1f, 0x01, 0x01, 0x0f, 0x01, 0x01, 0x01};
const unsigned char G[8] = {0x00, 0x0e, 0x11, 0x01, 0x1d, 0x11, 0x11, 0x0e};
const unsigned char J[8] = {0x00, 0x10, 0x10, 0x10, 0x10, 0x11, 0x11, 0x0e};
const unsigned char K[8] = {0x00, 0x11, 0x09, 0x05, 0x03, 0x05, 0x09, 0x11};
const unsigned char L[8] = {0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x1f};
const unsigned char P[8] = {0x00, 0x0f, 0x11, 0x11, 0x0f, 0x01, 0x01, 0x01};
const unsigned char Q[8] = {0x00, 0x0e, 0x11, 0x11, 0x11, 0x15, 0x19, 0x16};
const unsigned char R[8] = {0x00, 0x0f, 0x11, 0x11, 0x0f, 0x05, 0x09, 0x11};
const unsigned char T[8] = {0x00, 0x1f, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04};
const unsigned char U[8] = {0x00, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x0e};
const unsigned char V[8] = {0x00, 0x11, 0x11, 0x11, 0x0a, 0x0a, 0x0a, 0x04};
const unsigned char W[8] = {0x00, 0x11, 0x11, 0x15, 0x15, 0x1b, 0x11, 0x11};
const unsigned char X[8] = {0x00, 0x11, 0x11, 0x0a, 0x04, 0x0a, 0x11, 0x11};
const unsigned char Y[8] = {0x00, 0x11, 0x11, 0x0a, 0x04, 0x04, 0x04, 0x04};
const unsigned char Z[8] = {0x00, 0x1f, 0x11, 0x08, 0x04, 0x02, 0x11, 0x1f};

const unsigned char a[8] = {0x00, 0x00, 0x00, 0x0e, 0x10, 0x0e, 0x11, 0x1e};
const unsigned char c[8] = {0x00, 0x00, 0x00, 0x0e, 0x01, 0x01, 0x11, 0x0e};
const unsigned char d[8] = {0x00, 0x10, 0x10, 0x16, 0x19, 0x11, 0x11, 0x1e};
const unsigned char e[8] = {0x00, 0x00, 0x00, 0x0e, 0x11, 0x1f, 0x01, 0x0e};
const unsigned char f[8] = {0x00, 0x00, 0x0c, 0x12, 0x02, 0x07, 0x02, 0x02};
const unsigned char g[8] = {0x00, 0x00, 0x0e, 0x11, 0x11, 0x1e, 0x10, 0x0e};
const unsigned char h[8] = {0x01, 0x01, 0x01, 0x0d, 0x13, 0x11, 0x11, 0x11};
const unsigned char pseudoi[8] = {0x00, 0x04, 0x00, 0x06, 0x04, 0x04, 0x04, 0x0e};
const unsigned char j[8] = {0x00, 0x10, 0x00, 0x18, 0x10, 0x10, 0x11, 0x0e};
const unsigned char k[8] = {0x00, 0x01, 0x01, 0x09, 0x05, 0x03, 0x05, 0x09};
//const unsigned char l[8] = {0x00, 0x06, 0x04, 0x04, 0x04, 0x04, 0x04, 0x0e};
const unsigned char n[8] = {0x00, 0x00, 0x01, 0x0d, 0x13, 0x11, 0x11, 0x11};
const unsigned char p[8] = {0x00, 0x00, 0x00, 0x0f, 0x11, 0x0f, 0x01, 0x01};
const unsigned char r[8] = {0x00, 0x00, 0x00, 0x0d, 0x13, 0x01, 0x01, 0x01};
const unsigned char s[8] = {0x00, 0x00, 0x00, 0x0e, 0x01, 0x0e, 0x10, 0x0f};
const unsigned char t[8] = {0x00, 0x02, 0x02, 0x07, 0x02, 0x02, 0x12, 0x0c};
const unsigned char u[8] = {0x00, 0x00, 0x00, 0x11, 0x11, 0x11, 0x19, 0x16};
const unsigned char v[8] = {0x00, 0x00, 0x00, 0x11, 0x11, 0x11, 0x0a, 0x04};
const unsigned char y[8] = {0x00, 0x00, 0x00, 0x11, 0x11, 0x1e, 0x10, 0x0e};
const unsigned char z[8] = {0x00, 0x00, 0x00, 0x1f, 0x08, 0x04, 0x02, 0x1f};

const unsigned char exclamacao[8] = {0x04, 0x04, 0x04, 0x04, 0x04, 0x00, 0x00, 0x04};
const unsigned char ecomercial[8] = {0x00, 0x06, 0x09, 0x05, 0x02, 0x15, 0x09, 0x16};
const unsigned char virgula[8] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x04, 0x02};
const unsigned char ponto[8] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x06};
const unsigned char pontoevirgula[8] = {0x00, 0x00, 0x06, 0x06, 0x00, 0x06, 0x04, 0x02};
const unsigned char interrogacao[8] = {0x00, 0x0e, 0x11, 0x10, 0x08, 0x04, 0x00, 0x04};
const unsigned char potencia[8] = {0x00, 0x04, 0x0a, 0x11, 0x00, 0x00, 0x00, 0x00};
const unsigned char under[8] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f};
const unsigned char um[8] = {0x00, 0x06, 0x04, 0x04, 0x04, 0x04, 0x04, 0x0e};
const unsigned char dois[8] = {0x00, 0x0e, 0x11, 0x10, 0x08, 0x04, 0x02, 0x1f};
const unsigned char tres[8] = {0x00, 0x1f, 0x08, 0x04, 0x08, 0x10, 0x11, 0x0e};
const unsigned char quatro[8] = {0x00, 0x08, 0x0c, 0x0a, 0x09, 0x1f, 0x08, 0x08};
const unsigned char cinco[8] = {0x00, 0x1f, 0x01, 0x0f, 0x10, 0x10, 0x11, 0x0e};
const unsigned char sete[8] = {0x00, 0x1f, 0x10, 0x08, 0x04, 0x02, 0x02, 0x02};

			


void delay_ms(uint16_t t)
{
	volatile unsigned long l = 0;
	for(uint16_t i = 0; i < t; i++)
		for(l = 0; l < 6000; l++)
		{
		}
}


void delay_us(uint16_t t)
{
	volatile unsigned long l = 0;
	for(uint16_t i = 0; i < t; i++)
		for(l = 0; l < 6; l++)
		{
		}
}


//nova fun�ao de envio de caracteres para o LCD
void lcdDataNew(unsigned char valor)
{

    unsigned char internalIndex;
	
		//if(position <= 0xc0) position = 0x8f;

    int temp = lcdReuseChar(valor);

    if(temp == 1)
    {
        return;
    }

    int t = search(head, valor);
    if(t == 0)
    {
        if(index > 7)
        {
            lcdCommand(position);

            position--;

            lcdData(0xff);

            return;
        }

        add(&head, valor, index);

        lcdDataSwitch(valor, index);

        constCommand += 0x08;
        index++;

    } else
        {
            internalIndex = searchIndex(head, valor);

            lcdCommand(0x80);

            lcdRepeatChar(internalIndex);
        }
				
		
}



			
void lcd_putValue(unsigned char value)
{
	uint16_t aux;
	aux = 0x0000; //clear aux
	GPIOA->BRR = (1<<5)|(1<<6)|(1<<8)|(1<<11); /* clear PA5, PA6, PA8, PA11 */
	//GPIOA->BSRR = (value>>4)&0x0F; /* put high nibble on PA0-PA3 */	
	aux = value & 0xF0;
	aux = aux>>4;
	GPIOA->BSRR = ((aux&0x0008)<<8) | ((aux&0x0004)<<3) | ((aux&0x0002)<<5) | ((aux&0x0001)<<8);
	//GPIOA->BSRR = ;
	//GPIOA->BSRR = ;
	//GPIOA->BSRR = ;
	
	GPIOA->ODR |= (1<<LCD_EN); /* EN = 1 for H-to-L pulse */
	delay_us(40);			/* make EN pulse wider */
	GPIOA->ODR &= ~ (1<<LCD_EN);	/* EN = 0 for H-to-L pulse */
	delay_us(20);			/* wait	*/

	GPIOA->BRR = (1<<5)|(1<<6)|(1<<8)|(1<<11); /* clear PA5, PA6, PA8, PA11 */
	//GPIOA->BSRR = value&0x0F; /* put low nibble on PA0-PA3 */	
	aux = 0x0000; //clear aux
	aux = value & 0x0F;
	GPIOA->BSRR = ((aux&0x0008)<<8) | ((aux&0x0004)<<3) | ((aux&0x0002)<<5) | ((aux&0x0001)<<8);
	//GPIOA->BSRR = (aux&0x0008)<<8;
	//GPIOA->BSRR = (aux&0x0004)<<6;
	//GPIOA->BSRR = (aux&0x0002)<<5;
	//GPIOA->BSRR = (aux&0x0001)<<5;
	//GPIOA->ODR = aux;
	
	GPIOA->ODR |= (1<<LCD_EN); /* EN = 1 for H-to-L pulse */
	delay_us(40);			/* make EN pulse wider */
  GPIOA->ODR &= ~(1<<LCD_EN);	/* EN = 0 for H-to-L pulse */
  //delay_us(200);			/* wait	*/
}

void lcdCommand(unsigned char cmd)
{
	GPIOA->ODR &= ~ (1<<LCD_RS);	/* RS = 0 for command */
	//delay_us(200);
	lcd_putValue(cmd);
}

void lcdData(unsigned char data)
{
	GPIOA->ODR |= (1<<LCD_RS);	/* RS = 1 for data */
	lcd_putValue(data); 
}

void lcdString(char * str)
{
  unsigned char i = 0;

	while(str[i] != 0) /* while it is not end of string */
	{
		lcdData(str[i]); /* show str[i] on the LCD */
		i++;
	}
}

void tempo(uint16_t t)
{
	volatile unsigned long l = 0;
	for(uint16_t i = 0; i < t; i++)
		for(l = 0; l < 6; l++)
		{
		}
}

void lcdInit()
{
	delay_ms(15);
	GPIOA->ODR &= ~(1<<LCD_EN);	/* LCD_EN = 0 */
	delay_ms(3); 			/* wait 3ms */
	lcdCommand(0x33); //lcd init.
	delay_ms(5);
	lcdCommand(0x32); //lcd init.
	tempo(3000);
	lcdCommand(0x28); // 4-bit mode, 1 line and 5x8 charactere set
	delay_ms(3);
	lcdCommand(0x0e); // display on, cursor on
	delay_ms(3);
	lcdCommand(0x01); // display clear
	delay_ms(3);
	lcdCommand(0x06); // move right
	delay_ms(3);
}


void lcdInitNew()
{
	delay_ms(15);
	GPIOA->ODR &= ~(1<<LCD_EN);	/* LCD_EN = 0 */
	delay_ms(3); 			/* wait 3ms */
	lcdCommand(0x33); //lcd init.
	delay_ms(5);
	lcdCommand(0x32); //lcd init.
	tempo(3000);
	lcdCommand(0x28); // 4-bit mode, 1 line and 5x8 charactere set
	delay_ms(3);
	lcdCommand(0x0e); // display on, cursor on
	delay_ms(3);
	lcdCommand(0x01); // display clear
	delay_ms(3);
	lcdCommand(0x06); // move right
	delay_ms(3);
	
	cnt = 16; //contador de controlador de posi��o do novo lcd
	index = 0; //contador de index de memoria do novo lcd
	constCommand = 0x40;
	position = 0xcf;
	lcdCommand(0xcf);
}



void lcdPosition(int line, int col) 
{
	if (line == 0) {
		lcdCommand(0x80 + (col % 16));
	}
	if (line == 1) {
		lcdCommand(0xC0 + (col % 16));
	}
}


//nova fun�ao de configura�ao de posi�ao do crusor do LCD
void lcdPositionNew(int line, int col)
{
	if (line == 0) {
		position = 0x80 + (col % 16);
	}
	if (line == 1) {
		position = 0xC0 + (col % 16);
	}
}


void lcdInt(int val) 
{
    if (val < 0) {
        val = val * (-1);
        lcdData('-');
    }
    lcdData((val / 10000) % 10 + 48);
    lcdData((val / 1000) % 10 + 48);
    lcdData((val / 100) % 10 + 48);
    lcdData((val / 10) % 10 + 48);
    lcdData((val / 1) % 10 + 48);

}


void lcdTempo(int hh, int mm, int ss)
{
    lcdData((hh / 10 ) + '0');
    lcdData((hh % 10) + '0');
    lcdData(':');
    lcdData((mm / 10 ) + '0');
    lcdData((mm % 10) + '0');
    lcdData(':');
    lcdData((ss / 10 ) + '0');
    lcdData((ss % 10) + '0');
}


void lcdIntNew(int val) 
{
    if (val < 0) {
        val = val * (-1);
        lcdDataNew('-');
    }
    //lcdDataNew((val / 10000) % 10 + 48);
    lcdDataNew((val / 1000) % 10 + 48);
    lcdDataNew((val / 100) % 10 + 48);
    lcdDataNew((val / 10) % 10 + 48);
    lcdDataNew((val / 1) % 10 + 48);

}


//nova fun�ao de envio de string para o LCD
void lcdStringNew(char msg[]) 
{
	int i = 0;
	while (msg[i] != 0) {
		lcdDataNew(msg[i]);
		i++;
	}
}


void lcdTempoNew(int hh, int mm, int ss)
{
    lcdDataNew((hh / 10 ) + '0');
    lcdDataNew((hh % 10) + '0');
    lcdDataNew(':');
    lcdDataNew((mm / 10 ) + '0');
    lcdDataNew((mm % 10) + '0');
    lcdDataNew(':');
    lcdDataNew((ss / 10 ) + '0');
    lcdDataNew((ss % 10) + '0');
}


//limpa o LCD e reseta a lista dinamica encadeada
void lcdClear()
{
		//lcdCommand(0x01);
		//delay_ms(2);
    lcdPositionNew(1, 15);
		lcdStringNew("                ");
		lcdPositionNew(0, 15);
		lcdStringNew("                ");
		lcdPositionNew(1, 15);

    cnt = 16; //contador de controlador de posi��o do novo lcd
    index = 0; //contador de index de memoria do novo lcd
    constCommand = 0x40;
    position = 0xcf;
    //lcdCommand(0xcf);
		//delay_ms(2);
    freelist(&head);
}


//registra um bitmap personalizdo no LCD
void InternalLcdDataSwitch(unsigned char *valor, unsigned char indx)
{

    lcdCommand(constCommand);

    for(int i = 7; i >= 0; i--)
    {
        lcdData(valor[i]);
    }

    lcdCommand(position);

    position--;

    lcdData(indx);
}


//reutiliza bitmaps personalizados ja registrados no LCD
void lcdRepeatChar(unsigned char indx)
{
    lcdCommand(position);
    position--;

    lcdData(indx);
}








//envia os bitmaps dos caracteres para o LCD
void lcdDataSwitch(unsigned char valor, unsigned char indx)
{
    switch(valor) {
        case 'A':

                InternalLcdDataSwitch(A, indx);

                break;

        case 'B':

                InternalLcdDataSwitch(B, indx);

            break;

        case 'C':

                InternalLcdDataSwitch(C, indx);

            break;

        case 'D':

                InternalLcdDataSwitch(D, indx);

            break;

        case 'E':

                InternalLcdDataSwitch(E, indx);

            break;

        case 'F':

                InternalLcdDataSwitch(F, indx);

            break;

        case 'G':

                InternalLcdDataSwitch(G, indx);

            break;

        case 'J':

                InternalLcdDataSwitch(J, indx);

            break;

        case 'K':

                InternalLcdDataSwitch(K, indx);

            break;

        case 'L':

                InternalLcdDataSwitch(L, indx);

            break;


        case 'P':

                InternalLcdDataSwitch(P, indx);

            break;

        case 'Q':

                InternalLcdDataSwitch(Q, indx);

            break;

        case 'R':

                InternalLcdDataSwitch(R, indx);

            break;


        case 'T':

                InternalLcdDataSwitch(T, indx);

            break;

        case 'U':

                InternalLcdDataSwitch(U, indx);

            break;

        case 'V':

                InternalLcdDataSwitch(V, indx);

            break;

        case 'W':

                InternalLcdDataSwitch(W, indx);

            break;


        case 'Y':

                InternalLcdDataSwitch(Y, indx);

            break;

        case 'Z':

                InternalLcdDataSwitch(Z, indx);

            break;

        case 'a':

            InternalLcdDataSwitch(a, indx);

            break;


        case 'c':

            InternalLcdDataSwitch(c, indx);

            break;

        case 'd':

            InternalLcdDataSwitch(d, indx);

            break;

        case 'e':

            InternalLcdDataSwitch(e, indx);

            break;

        case 'f':

            InternalLcdDataSwitch(f, indx);

            break;

        case 'g':

            InternalLcdDataSwitch(g, indx);

            break;

        case 'h':

            InternalLcdDataSwitch(h, indx);

            break;

        case 'i':

            InternalLcdDataSwitch(pseudoi, indx);

            break;

        case 'j':

            InternalLcdDataSwitch(j, indx);

            break;

        case 'k':

            InternalLcdDataSwitch(k, indx);

            break;

        case 'n':

            InternalLcdDataSwitch(n, indx);

            break;

        case 'p':

            InternalLcdDataSwitch(p, indx);

            break;


        case 'r':

            InternalLcdDataSwitch(r, indx);

            break;

        case 's':

            InternalLcdDataSwitch(s, indx);

            break;

        case 't':

            InternalLcdDataSwitch(t, indx);

            break;

        case 'u':

            InternalLcdDataSwitch(u, indx);

            break;


        case 'v':

            InternalLcdDataSwitch(v, indx);

            break;


        case 'y':

            InternalLcdDataSwitch(y, indx);

            break;

        case 'z':

            InternalLcdDataSwitch(z, indx);

            break;

        case '!':

            InternalLcdDataSwitch(exclamacao, indx);


            break;

        case '&':

            InternalLcdDataSwitch(ecomercial, indx);


            break;

        case ',':

            InternalLcdDataSwitch(virgula, indx);


            break;

        case '.':

            InternalLcdDataSwitch(ponto, indx);


            break;

        case ';':

            InternalLcdDataSwitch(pontoevirgula, indx);


            break;

        case '?':

            InternalLcdDataSwitch(interrogacao, indx);


            break;

        case '^':

            InternalLcdDataSwitch(potencia, indx);


            break;

        case '_':

            InternalLcdDataSwitch(under, indx);


            break;

        case '1':

            InternalLcdDataSwitch(um, indx);


            break;

        case '2':

            InternalLcdDataSwitch(dois, indx);


            break;

        case '3':

            InternalLcdDataSwitch(tres, indx);


            break;

        case '4':

            InternalLcdDataSwitch(quatro, indx);


            break;

        case '5':

            InternalLcdDataSwitch(cinco, indx);


            break;

        case '7':

            InternalLcdDataSwitch(sete, indx);


            break;


        default:

            break;

    }

}


//reutiliza valores programados no LCD
int lcdReuseChar(unsigned char valor)
{
    switch(valor)
    {
        case ' ':

            lcdCommand(position);

            position--;

            lcdData(valor);

            return 1;

            break;

        case 'I':

            lcdCommand(position);

            position--;

            lcdData(valor);

            return 1;

            break;

        case 'l':

            lcdCommand(position);

            position--;

            lcdData('|');

            return 1;

            break;

        case 'O':

            lcdCommand(position);

            position--;

            lcdData(valor);

            return 1;

            break;

        case 'H':

            lcdCommand(position);

            position--;

            lcdData(valor);

            return 1;

            break;

        case 'X':

            lcdCommand(position);

            position--;

            lcdData(valor);

            return 1;

            break;

        case 'M':

            lcdCommand(position);

            position--;

            lcdData('W');

            return 1;

            break;

        case 'W':

            lcdCommand(position);

            position--;

            lcdData('M');

            return 1;

            break;

        case 'N':

            lcdCommand(position);

            position--;

            lcdData(valor);

            return 1;

            break;

        case 'S':

            lcdCommand(position);

            position--;

            lcdData(valor);

            return 1;

            break;

        case 'b':

            lcdCommand(position);

            position--;

            lcdData('q');

            return 1;

            break;

        case 'm':

            lcdCommand(position);

            position--;

            lcdData('w');

            return 1;

            break;

       /* case 'n':

            lcdCommand(position);

            position--;

            lcdData('u');

            return 1;

            break;*/

        case 'o':

            lcdCommand(position);

            position--;

            lcdData(valor);

            return 1;

            break;

        case 'q':

            lcdCommand(position);

            position--;

            lcdData('b');

            return 1;

            break;

       /* case 'u':

            lcdCommand(position);

            position--;

            lcdData('n');

            return 1;

            break;*/

        case 'w':

            lcdCommand(position);

            position--;

            lcdData('m');

            return 1;

            break;

        case 'x':

            lcdCommand(position);

            position--;

            lcdData(valor);

            return 1;

            break;

        case '#':

            lcdCommand(position);

            position--;

            lcdData(valor);

            return 1;

            break;

        case '$':

            lcdCommand(position);

            position--;

            lcdData(valor);

            return 1;

            break;

        case '%':

            lcdCommand(position);

            position--;

            lcdData(valor);

            return 1;

            break;

        case '(':

            lcdCommand(position);

            position--;

            lcdData(')');

            return 1;

            break;

        case ')':

            lcdCommand(position);

            position--;

            lcdData('(');

            return 1;

            break;

        case '*':

            lcdCommand(position);

            position--;

            lcdData(valor);

            return 1;

            break;

        case '+':

            lcdCommand(position);

            position--;

            lcdData(valor);

            return 1;

            break;

        case '-':

            lcdCommand(position);

            position--;

            lcdData(valor);

            return 1;

            break;

        case '/':

            lcdCommand(position);

            position--;

            lcdData(valor);

            return 1;

            break;

        case ':':

            lcdCommand(position);

            position--;

            lcdData(valor);

            return 1;

            break;

        case '<':

            lcdCommand(position);

            position--;

            lcdData('>');

            return 1;

           break;

        case '>':

            lcdCommand(position);

            position--;

            lcdData('<');

            return 1;

            break;

        case '=':

            lcdCommand(position);

            position--;

            lcdData(valor);

            return 1;

            break;

        case '|':

            lcdCommand(position);

            position--;

            lcdData(valor);

            return 1;

            break;

        case 0x7f:

            lcdCommand(position);

            position--;

            lcdData(0x7e);

            return 1;

            break;

        case 0x7e:

            lcdCommand(position);

            position--;

            lcdData(0x7f);

            return 1;

            break;

        case '0':

            lcdCommand(position);

            position--;

            lcdData(valor);

            return 1;

            break;

        case '6':

            lcdCommand(position);

            position--;

            lcdData('9');

            return 1;

            break;

        case '8':

            lcdCommand(position);

            position--;

            lcdData(valor);

            return 1;

            break;

        case '9':

            lcdCommand(position);

            position--;

            lcdData('6');

            return 1;

            break;


        default:

            return 0;

            break;
    }
}
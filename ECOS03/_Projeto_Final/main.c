#include "STM32F10x.h"
#include <cmsis_os.h>

/*----------------------------------------------------------------------------------------------------
_______________________________________definindo pinos_____________________________________________
----------------------------------------------------------------------------------------------------*/

//LEDs
#define LED1  0   // PA0
#define LED2  1   // PA1
#define LED3  2   // PA2
#define LED4  15  // PA15
#define LED5  8   // PA8
#define LED6  6   // PA6
#define LED7  5   // PA5
#define LED8  11  // PA11

#define iLED1  (1 << 0)   // PA0
#define iLED2  (1 << 1)   // PA1
#define iLED3  (1 << 2)   // PA2
#define iLED4  (1 << 15)  // PA15
#define iLED5  (1 << 8)   // PA8
#define iLED6  (1 << 6)   // PA6
#define iLED7  (1 << 5)   // PA5
#define iLED8  (1 << 11)  // PA11



//LCD display
#define LCD_RS 15
#define LCD_EN 12

//Switches
#define SW1 12  //PB12
#define SW2 13  //PB13
#define SW3 14  //PB14
#define SW4 15  //PB15
#define SW5 5   //PB5
#define SW6 4   //PB4
#define SW7 3   //PB3
#define SW8 3   //PA3
#define SW9 4   //PA4
#define SW10 8  //PB8
#define SW11 9  //PB9
#define SW12 11 //PB11
#define SW13 10 //PB10
#define SW14 7  //PA7
#define SW15 15 //PC15
#define SW16 14 //PC14
#define SW17 13 //PC13

#define SoftnerLedsStep 1



//Prototipos
void delay (unsigned int count);
void setup_RedPill();
void _LEDs_Mode_01();
void _LEDs_Mode_02();
void _LEDs_Mode_03();
void _LEDs_Mode_04();
void _Func_05_SW_Read();
void Buzz_Off();
void _Func_06_SW_Read();
int ADC_Read();
void _Func_06_SW_Read();
void PotLedVelCtrl();
void SoftnerLeds(int diff, char pn);
void LCD_Load();
void SoftnerLedsPot(int diff, char pn);


/*----------------------------------------------------------------------------------------------------
_______________________________________variaveis globais_____________________________________________
----------------------------------------------------------------------------------------------------*/
unsigned int _LedsTime_default = 1000;
unsigned int _LedsTime;
unsigned char mode = 0;
unsigned char nots = 0;


	
//definindo mutex pro lcd
osMutexId lcd_mutex;           // handle
osMutexDef(lcd_mutex_def);     // definição com nome diferente

//definindo mutex pro teclado
osMutexId sw_mutex;           // handle
osMutexDef(sw_mutex_def);     // definição com nome diferente


//define os IDs das threads criadas
osThreadId main_ID, _LEDs_Mode_01_ID, _LEDs_Mode_02_ID, _LEDs_Mode_03_ID, _LEDs_Mode_04_ID, _Func_05_SW_Read_ID,
_Func_06_SW_Read_ID, PotLedVelCtrl_ID, LCD_Load_ID;


/*----------------------------------------------------------------------------------------------------
_______________________________________Definição das threads_____________________________________________
----------------------------------------------------------------------------------------------------*/
osThreadDef(_LEDs_Mode_01, osPriorityNormal, 1, 0);
osThreadDef(_LEDs_Mode_02, osPriorityNormal, 1, 0);
osThreadDef(_LEDs_Mode_03, osPriorityNormal, 1, 0);
osThreadDef(_LEDs_Mode_04, osPriorityNormal, 1, 0);
osThreadDef(_Func_05_SW_Read, osPriorityNormal, 1, 0);
osThreadDef(_Func_06_SW_Read, osPriorityNormal, 1, 0);
osThreadDef(PotLedVelCtrl, osPriorityNormal, 1, 0);
osThreadDef(LCD_Load, osPriorityNormal, 1, 0);


/*----------------------------------------------------------------------------------------------------
_______________________________________Main_____________________________________________
----------------------------------------------------------------------------------------------------*/
int main (void)
{
	osKernelInitialize ();

	setup_RedPill();
	Buzz_Off();

	//inicialização ficticia do sistema
	osDelay(3000);
	lcdStringNew("hts mod: ok");
	osDelay(400);
	lcdClear();
	lcdStringNew("ann mod: ok");
	osDelay(400);
	lcdClear();
	lcdStringNew("cls mod: ok");
	osDelay(400);
	lcdClear();
	lcdStringNew("GBN mod: ok");
	osDelay(400);
	lcdClear();
	lcdStringNew("HT load: ok");
	osDelay(400);
	lcdClear();
	lcdStringNew("ms-s: ok");
	osDelay(400);
	lcdClear();
	lcdStringNew("cls mod: ok");
	osDelay(400);
	lcdClear();
	lcdStringNew("GBN mod: ok");
	osDelay(400);

	lcdClear();
	osDelay(1000);
	lcdStringNew("System load...");
	osDelay(3000);
	lcdClear();
	lcdStringNew("Elt-Kernel: ok");
	osDelay(3000);
	lcdClear();
	lcdStringNew("Welcome to EC-OS");
	osDelay(3000);
	lcdClear();
	lcdStringNew("Version: 0.3");
	osDelay(3000);
	lcdClear();
	lcdStringNew("-----ECOS03-----");
	osDelay(3000);

	_LEDs_Mode_01_ID = osThreadCreate(osThread(_LEDs_Mode_01), NULL);
	_LEDs_Mode_02_ID = osThreadCreate(osThread(_LEDs_Mode_02), NULL);
	_LEDs_Mode_03_ID = osThreadCreate(osThread(_LEDs_Mode_03), NULL);
	_LEDs_Mode_04_ID = osThreadCreate(osThread(_LEDs_Mode_04), NULL);

	_Func_05_SW_Read_ID = osThreadCreate(osThread(_Func_05_SW_Read), NULL);
	_Func_06_SW_Read_ID = osThreadCreate(osThread(_Func_06_SW_Read), NULL);

	PotLedVelCtrl_ID = osThreadCreate(osThread(PotLedVelCtrl), NULL);
	LCD_Load_ID = osThreadCreate(osThread(LCD_Load), NULL);
	
	lcd_mutex = osMutexCreate(osMutex(lcd_mutex_def));
	sw_mutex = osMutexCreate(osMutex(sw_mutex_def));

	osSignalSet(LCD_Load_ID, 0x01);

	osKernelStart ();
	while(1){
        ;
	}
}



















/*----------------------------------------------------------------------------------------------------
_______________________________________Funções_____________________________________________
----------------------------------------------------------------------------------------------------*/

//função de delay___________________________________________________________________________
void delay (unsigned int count)
{
unsigned int index;

	for(index =0;index<count;index++)
	{
		;
	}
}


//desliga o buzzer____________________________________________________
void Buzz_Off()
{
	TIM3->CR1 = 0;
	RCC->APB1ENR &= ~(1<<1);

	GPIOB->CRL &= ~(0xF << (0 * 4));
	GPIOB->CRL |=  (0x4 << (0 * 4));   // Entrada flutuante
}

//le o potenciometro____________________________________________________
int ADC_Read()
{
	ADC1->SQR3 = 9;
	ADC1->CR2 |= (1 << 0);
	while (!(ADC1->SR & (1 << 1)));
	return ADC1->DR;
}


//setup da redpill___________________________________________________________________________
void setup_RedPill()
{

	//int16_t swa, swb, swc;  //Variables to read the switches according to the port it is connected
	RCC->APB2ENR |= RCC_APB2ENR_AFIOEN; // Enable AF clock
	AFIO->MAPR |= AFIO_MAPR_SWJ_CFG_JTAGDISABLE;
	delay(100);

	RCC->APB2ENR |= 0xFC |(1<<9);		//ENABLE clocks for GPIOs and ADC1
	//Setting up outputs for leds
	ADC1->CR2 = 1;	/* ADON = 1 (power-up) */
	ADC1->CR2 |=(1<<2); //enable calibration
	ADC1->SMPR2 = 1<<3; /* SMP1 = 001 */
	delay(1);	/* wait 1us to make sure the adc module is stable */
	GPIOA->CRL = 0x43344333;	//PA3, PA4 and PA7: inputs (switches)
	GPIOA->CRH = 0x33333333;  //PA8 - PA15: outputs (leds)

	//Settig up inputs for switches
	GPIOB->CRL = 0x4444440B; //PB0 set for output+alternate wave form, since it is connected to buzzer.
	GPIOB->CRH = 0x44444444;
	GPIOB->ODR = 0xF000; //set pull-up in PB12 - PB15
	GPIOC->CRH = 0x44444444;
	GPIOC->ODR = 0xFFFFFFFF; //set pull-up in GPIOC

	delay(1); //wait for I/O setup
	GPIOA->ODR &=~(1<<LCD_RS); //Turn off LED4
	delay(1); //wait for LED4 to turn off

	// Inicializa o Timer 3 para o buzzer em PB0 (Canal 2)
	RCC->APB1ENR |= (1<<1); // Habilita clock do TIM3
	TIM3->CCER = (1 << 8); // CC2E = 1 (habilita canal 2)
	TIM3->CCMR2 = 0x0030;  // Toggle mode no canal 2
	TIM3->CR1 = 1;         // Ativa o timer

	//inicializa variaveis
	_LedsTime = _LedsTime_default;
	lcdInitNew();
}


//função 1: alterna os leds pares e impares__________________________________________________________________________
void _LEDs_Mode_01()
{
	for(;;)
		{
			osSignalWait(0x01, osWaitForever);
			osSignalSet(osThreadGetId(), 0x01);

			osMutexWait(lcd_mutex, osWaitForever);
			GPIOA->ODR &= ~(1<<LED1);
			GPIOA->ODR |= (1<<LED2);
			GPIOA->ODR &= ~(1<<LED3);
			GPIOA->ODR |= (1<<LCD_RS);
			GPIOA->ODR &= ~(1<<LED5);
			GPIOA->ODR |= (1<<LED6);
			GPIOA->ODR &= ~(1<<LED7);
			GPIOA->ODR |= (1<<LED8);
			osMutexRelease(lcd_mutex);
			
			osDelay(_LedsTime);

			osMutexWait(lcd_mutex, osWaitForever);
			GPIOA->ODR |= (1<<LED1);
			GPIOA->ODR &= ~(1<<LED2);
			GPIOA->ODR |= (1<<LED3);
			GPIOA->ODR &= ~(1<<LCD_RS);
			GPIOA->ODR |= (1<<LED5);
			GPIOA->ODR &= ~(1<<LED6);
			GPIOA->ODR |= (1<<LED7);
			GPIOA->ODR &= ~(1<<LED8);
			osMutexRelease(lcd_mutex);

			osDelay(_LedsTime);
		}
}


//função 2: pisca conforme codigo gray
void _LEDs_Mode_02()
{
	uint8_t contador = 0;

	const uint8_t LED_BITS[8] =
{
		LED1, // bit 0
		LED2, // bit 1
		LED3, // bit 2
		LED4, // bit 3
		LED5, // bit 4
		LED6, // bit 5
		LED7, // bit 6
		LED8  // bit 7
};

	for(;;)
	{
		osSignalWait(0x01, osWaitForever);
		osSignalSet(osThreadGetId(), 0x01);

		//calcula código de Gray
		uint8_t valor = contador ^ (contador >> 1);

		osMutexWait(lcd_mutex, osWaitForever);
		//joga a palavra do codigo nos leds
		for (int i = 0; i < 8; i++)
			{
					if (valor & (1 << i))
						{
								GPIOA->ODR |=  (1 << LED_BITS[i]);
						} else
							{
									GPIOA->ODR &= ~(1 << LED_BITS[i]);
							}
			}
			osMutexRelease(lcd_mutex);

		contador++;
		osDelay(_LedsTime);
	}
}



//acende os leds conforme potebnciometro__________________________________________________________________________
void _LEDs_Mode_03()
{
	uint16_t leds_mask[9] =
	{
		0,
		iLED1,
		iLED1 | iLED2,
		iLED1 | iLED2 | iLED3,
		iLED1 | iLED2 | iLED3 | iLED4,
		iLED1 | iLED2 | iLED3 | iLED4 | iLED5,
		iLED1 | iLED2 | iLED3 | iLED4 | iLED5 | iLED6,
		iLED1 | iLED2 | iLED3 | iLED4 | iLED5 | iLED6 | iLED7,
		iLED1 | iLED2 | iLED3 | iLED4 | iLED5 | iLED6 | iLED7 | iLED8
	};

	int ADC;

	for (;;)
	{
		osSignalWait(0x01, osWaitForever);
		osSignalSet(osThreadGetId(), 0x01);

		//le o potenciometro
		ADC = ADC_Read();

		//joga pros leds
		int n_leds = (ADC * 8) / 4000;
		if (n_leds > 8) n_leds = 8;

		osMutexWait(lcd_mutex, osWaitForever);
		GPIOA->ODR = leds_mask[n_leds];
		osMutexRelease(lcd_mutex);
	}
}




//acende os leds conforme potebnciometro e sincroniza o buzzer____________________________________________________
void _LEDs_Mode_04()
{
		uint16_t leds_mask[9] =
	{
		0,
		iLED1,
		iLED1 | iLED2,
		iLED1 | iLED2 | iLED3,
		iLED1 | iLED2 | iLED3 | iLED4,
		iLED1 | iLED2 | iLED3 | iLED4 | iLED5,
		iLED1 | iLED2 | iLED3 | iLED4 | iLED5 | iLED6,
		iLED1 | iLED2 | iLED3 | iLED4 | iLED5 | iLED6 | iLED7,
		iLED1 | iLED2 | iLED3 | iLED4 | iLED5 | iLED6 | iLED7 | iLED8
	};

	int ADC;

	//vetor de notas
	//const uint16_t notas[9] = {0, 111, 222, 333, 444, 555, 666, 777, 888};
	//const uint16_t notas[9] = {0, 261, 293, 329, 349, 392, 440, 493, 523};
const uint16_t notas[5][9] = {
    // { 65,  82,  98, 131, 165, 196, 262, 330, 392 }, // C (fora da escala de D)
    // { 69,  87, 104, 139, 174, 208, 277, 349, 415 }, // C# (diminuto em D maior)
    {  73,  92, 110, 147, 185, 220, 294, 370, 440 },  // D ?
    // { 78,  98, 117, 156, 196, 233, 311, 392, 466 }, // Eb (fora da escala)
    // { 82, 104, 123, 165, 208, 247, 330, 415, 494 }, // E (contém G#)
    // { 87, 110, 131, 175, 220, 262, 349, 440, 523 }, // F (fora da escala)
    // { 92, 116, 139, 185, 233, 277, 370, 466, 554 }, // F# (menor na escala de D)
    {  98, 123, 147, 196, 247, 294, 392, 494, 587 },  // G ?
    // {104, 131, 156, 208, 262, 311, 415, 523, 622 }, // Ab (fora da escala)
    {110, 139, 165, 220, 277, 330, 440, 554, 659 },   // A ?
    // {117, 147, 175, 233, 294, 349, 466, 587, 698 }, // Bb (fora da escala)
    // {123, 156, 185, 247, 311, 370, 494, 622, 740 }, // B (forma acorde menor)

    // Acordes de D e G uma oitava acima ??
    {146, 185, 220, 294, 370, 440, 588, 740, 880},    // D (oitava acima)
    {196, 247, 294, 392, 494, 588, 784, 988,1174}     // G (oitava acima)
};


	
	
	//Desliga tudo no start
	TIM3->CR1 = 0;
	RCC->APB1ENR &= ~(1<<1);

	//inicializa o buzzer
	GPIOB->CRL &= ~(0xF << (0 * 4));   // Zera config de PB0
	GPIOB->CRL |=  (0x4 << (0 * 4));   // Entrada flutuante

	for (;;)
	{
		osSignalWait(0x01, osWaitForever);
		osSignalSet(osThreadGetId(), 0x01);
	
		//leitura do potenciometro
		ADC = ADC_Read();

		//calculo dos leds
		int n_leds = (ADC * 8) / 4000;
		if (n_leds > 8) n_leds = 8;

		osMutexWait(lcd_mutex, osWaitForever);
		GPIOA->ODR = leds_mask[n_leds];
		osMutexRelease(lcd_mutex);

		if (ADC < 70 || n_leds == 0)
		{
			//desliga se menor que 70
			TIM3->CR1 = 0;
			RCC->APB1ENR &= ~(1<<1);

			GPIOB->CRL &= ~(0xF << (0 * 4));
			GPIOB->CRL |=  (0x4 << (0 * 4));   // Entrada flutuante
		}
		else
		{
			//ativa PB0 como saída alternada
			GPIOB->CRL &= ~(0xF << (0 * 4));
			GPIOB->CRL |=  (0xB << (0 * 4));   //alternate Function Push-Pull

			//ativa clock e configura frequência musical
			RCC->APB1ENR |= (1<<1);

			uint16_t freq = notas[nots][n_leds];
			uint16_t arr = 8000000 / (2 * freq); // f_APB1 = 8MHz

			TIM3->ARR = arr - 1;
			TIM3->CCR2 = arr / 2;
			TIM3->CCER = (1 << 8);        //CC2E
			TIM3->CCMR2 = 0x0030;         //toggle mode
			TIM3->CR1 = 1;                //ativa timer
		}
	}
}



//controla os modos dos leds____________________________________________________
void _Func_05_SW_Read()
{
	// array com os pinos e suas respectivas portas
	struct
	{
		GPIO_TypeDef* port;
		uint8_t pin;
	} switches[] =
	{
		{GPIOB, SW5},
		{GPIOB, SW6},
		{GPIOB, SW7},
		{GPIOA, SW8},
		{GPIOB, SW13},
		{GPIOA, SW14},
		{GPIOC, SW15},
		{GPIOC, SW16},
		{GPIOC, SW17}
	};
	for(;;)
		{
			osMutexWait(sw_mutex, osWaitForever);
			for (int i = 0; i < 9; i++)
			{
				// botão pressionado (nível baixo)
				if (!(switches[i].port->IDR & (1 << switches[i].pin)))
				{
					delay(1); // debounce

					// onfirma que continua pressionado
					if (!(switches[i].port->IDR & (1 << switches[i].pin)))
					{

						osSignalClear(_LEDs_Mode_01_ID, 0x01);
						osSignalClear(_LEDs_Mode_02_ID, 0x01);
						osSignalClear(_LEDs_Mode_03_ID, 0x01);
						osSignalClear(_LEDs_Mode_04_ID, 0x01);

						switch(i)
						{
							case 0: //SW5
							{
								Buzz_Off();
								osSignalSet(_LEDs_Mode_01_ID, 0x01);
								mode = 1;
								break;
							}
							case 1: //SW6
							{
								Buzz_Off();
								osSignalSet(_LEDs_Mode_02_ID, 0x01);
								mode = 2;
								break;
							}
							case 2: //SW7
							{
								Buzz_Off();
								osSignalSet(_LEDs_Mode_03_ID, 0x01);
								mode = 3;
								break;
							}
							case 3: //SW8
							{
								osSignalSet(_LEDs_Mode_04_ID, 0x01);
								mode = 4;
								break;
							}
							case 4: //SW13	
							{
								osSignalSet(_LEDs_Mode_04_ID, 0x01);
								nots = 0;
								break;
							}
							case 5: //SW14	
							{
								osSignalSet(_LEDs_Mode_04_ID, 0x01);
								nots = 1;
								break;
							}
							case 6: //SW15	
							{
								osSignalSet(_LEDs_Mode_04_ID, 0x01);
								nots = 2;
								break;
							}
							case 7: //SW16	
							{
								osSignalSet(_LEDs_Mode_04_ID, 0x01);
								nots = 3;
								break;
							}
							case 8: //SW17	
							{
								osSignalSet(_LEDs_Mode_04_ID, 0x01);
								nots = 4;
								break;
							}
						}
					}
				}
			}
		osMutexRelease(sw_mutex);
	}
}




//controla as velocidades dos modos dos leds____________________________________________________
void _Func_06_SW_Read()
{
	struct
	{
		GPIO_TypeDef* port;
		uint8_t pin;
	} switches[] =
	{
		{GPIOB, SW1},
		{GPIOB, SW2},
		{GPIOB, SW3},
		{GPIOB, SW4},
		{GPIOB, SW10},
		{GPIOB, SW11},
		{GPIOB, SW12},
	};

	for(;;)
	{
		osMutexWait(sw_mutex, osWaitForever);
		
		int tmp = 0;

		for (int i = 0; i < 7; i++)
		{
			// botão pressionado (nível baixo)
			if (!(switches[i].port->IDR & (1 << switches[i].pin)))
			{
				osDelay(1); // debounce

				// confirma que ainda está pressionado
				if (!(switches[i].port->IDR & (1 << switches[i].pin)))
				{
					// ação do botão
					osSignalClear(PotLedVelCtrl_ID, 0x01);
					switch(i)
					{
						case 0: //SW1
							tmp = _LedsTime - (_LedsTime/2);
							SoftnerLeds(tmp, 0);
							break;
						case 1: //SW2
							tmp = (_LedsTime*2) - _LedsTime;
							SoftnerLeds(tmp, 1);
							break;
						case 2: //SW3
							if(_LedsTime_default > _LedsTime)
							{
								tmp = _LedsTime_default - _LedsTime;
								SoftnerLeds(tmp, 1);
							} else
									{
										tmp = _LedsTime - _LedsTime_default;
										SoftnerLeds(tmp, 0);
									}
							break;
						case 3: //SW4
							osSignalSet(PotLedVelCtrl_ID, 0x01);
							break;
						case 4: //SW10
							_LedsTime_default = 500;

							if(_LedsTime_default > _LedsTime)
							{
								tmp = _LedsTime_default - _LedsTime;
								SoftnerLeds(tmp, 1);
							} else
									{
										tmp = _LedsTime - _LedsTime_default;
										SoftnerLeds(tmp, 0);
									}
							break;
						case 5: //SW11
							_LedsTime_default = 2000;

							if(_LedsTime_default > _LedsTime)
							{
								tmp = _LedsTime_default - _LedsTime;
								SoftnerLeds(tmp, 1);
							} else
									{
										tmp = _LedsTime - _LedsTime_default;
										SoftnerLeds(tmp, 0);
									}
							break;
						case 6: //SW12
							_LedsTime_default = 5000;

							if(_LedsTime_default > _LedsTime)
							{
								tmp = _LedsTime_default - _LedsTime;
								SoftnerLeds(tmp, 1);
							} else
									{
										tmp = _LedsTime - _LedsTime_default;
										SoftnerLeds(tmp, 0);
									}
							break;
					}

					// aguarda o botão ser solto
					while (!(switches[i].port->IDR & (1 << switches[i].pin)))
					{
						osDelay(10);
					}
				}
			}
		}
		osMutexRelease(sw_mutex);
	}
}



//controla as velocidades dos leds via potenciometro____________________________________________________
void PotLedVelCtrl()
{
    for (;;)
    {
        osSignalWait(0x01, osWaitForever);
        osSignalSet(osThreadGetId(), 0x01);

        int readtmp = 10 + ((ADC_Read() * (500 - 10)) / 4095);

        if (readtmp > _LedsTime)
        {
            int tmp = readtmp - _LedsTime;
            SoftnerLedsPot(tmp, 1);
        }
        else
        {
            int tmp = _LedsTime - readtmp;
            SoftnerLedsPot(tmp, 0);
        }
    }
}



//essa função suaviza as transições de velocidade do piscar dos leds
//alterar o osDelay muda a intensidade dessa suavização
//diff é a diferença entre o valor desejado e o atual
//pn é 1 para incrementos e 0 para decrementos
void SoftnerLeds(int diff, char pn)
{
		unsigned char tmp = 0;
    const int total_time_ms = 2000;  // tempo total fixo
    const int steps = 14;            // passos fixos para suavização

    if (diff == 0) return;

    int step_size = diff / steps;    // tamanho do passo
    if (step_size == 0) step_size = 1; // garante que não fique zero

    int delay_per_step = total_time_ms / steps;

    osSignalClear(LCD_Load_ID, 0x01);
    lcdClear();

    osMutexWait(lcd_mutex, osWaitForever);
		tmp = GPIOA->ODR;
    lcdStringNew("Load...");
		GPIOA->ODR = tmp;
    osMutexRelease(lcd_mutex);

    lcdPositionNew(0, 15);

    int part = diff / steps;   // feedback visual
    int partcnt = 0;

    if (pn)
    {
        int i = 0;
        while (i < diff)
        {
            _LedsTime += step_size;
            i += step_size;
            partcnt += step_size;

            if (partcnt >= part)
            {
                osMutexWait(lcd_mutex, osWaitForever);
								tmp = GPIOA->ODR;
                lcdStringNew("/");
								GPIOA->ODR = tmp;
                osMutexRelease(lcd_mutex);
                partcnt = 0;
            }

            osDelay(delay_per_step);
        }
    }
    else
    {
        int i = 0;
        while (i < diff)
        {
            _LedsTime -= step_size;
            i += step_size;
            partcnt += step_size;

            if (partcnt >= part)
            {
                osMutexWait(lcd_mutex, osWaitForever);
								tmp = GPIOA->ODR;
                lcdStringNew("/");
								GPIOA->ODR = tmp;
                osMutexRelease(lcd_mutex);
                partcnt = 0;
            }

            osDelay(delay_per_step);
        }
    }

    osSignalSet(LCD_Load_ID, 0x01);
}





void SoftnerLedsPot(int diff, char pn)
{
    const int total_time_ms = 2000;
    const int max_steps = 20;

    if (diff == 0) return;

    // Define o número de passos limitado pelo máximo
    int steps = diff / SoftnerLedsStep;
    if (steps == 0) steps = 1;           // evita divisão por zero
    if (steps > max_steps) steps = max_steps;

    // Calcula o tamanho do passo real para cobrir o diff total em 'steps' passos
    int step_size = diff / steps;
    if (step_size == 0) step_size = 1;  // garantir passo mínimo

    int delay_per_step = total_time_ms / steps;

    for (int i = 0; i < steps; ++i)
    {
        if (pn)
            _LedsTime += step_size;
        else
            _LedsTime -= step_size;

        osDelay(delay_per_step);
    }

    osSignalSet(LCD_Load_ID, 0x01);
}





//atualiza o lcd a cada 3s____________________________________________________
void LCD_Load()
{
	unsigned char tmp = 0;
	unsigned char oldState = 0xFF; // Valor impossível de 'mode' inicial, força a primeira atualização
	
	for (;;)
	{
		osSignalWait(0x01, osWaitForever);
		osSignalSet(osThreadGetId(), 0x01);

		if (oldState != mode)
		{
			oldState = mode;

			osMutexWait(lcd_mutex, osWaitForever);
			
			tmp = GPIOA->ODR;
			
			lcdClear();
			lcdStringNew("T:");
			lcdIntNew(_LedsTime);
			
			switch (mode)
			{
				case 1: lcdStringNew("ms  Mode:1"); break;
				case 2: lcdStringNew("ms  Mode:2"); break;
				case 3: lcdStringNew("ms  Mode:3"); break;
				case 4: lcdStringNew("ms  Mode:4"); break;
			}
			
			GPIOA->ODR = tmp;
			
			osMutexRelease(lcd_mutex);
		}

		osDelay(3000);
	}
}


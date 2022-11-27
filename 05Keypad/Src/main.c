#include <stdint.h>
#include <stdio.h>
#include "regF401re.h"

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

void delay(int milliseconds);

int main(void)
{
	/*
	 * Addresses:
	 *
	 * RCC   0x40023800
	 * GPIOE 0x40021000
	 * GPIOD 0x40020C00
	 * GPIOC 0x40020800
	 * GPIOB 0x40020400
	 * GPIOA 0x40020000
	 */

	/*
	 * R1-4 PA3, PA2, PA10, PB3
	 * C1-4 PB5, PB4, PB10, PA8
	 */

	RCC_AHB1ENR_t volatile *const pClk = (RCC_AHB1ENR_t*)0x40023830;
	GPIOx_MODER_t volatile *const pModeA = (GPIOx_MODER_t*)0x40020000;
	GPIOx_MODER_t volatile *const pModeB = (GPIOx_MODER_t*)0x40020400;
	GPIOx_PUPDR_t volatile *const pPullupA = (GPIOx_PUPDR_t*)0x4002000C;
	GPIOx_PUPDR_t volatile *const pPullupB = (GPIOx_PUPDR_t*)0x4002040C;
	GPIOx_ODR_t volatile *const pOutputA = (GPIOx_ODR_t*)0x40020014;
	GPIOx_ODR_t volatile *const pOutputB = (GPIOx_ODR_t*)0x40020414;
	GPIOx_IDR_t const volatile *const pInputA = (GPIOx_IDR_t*)0x40020010;
	GPIOx_IDR_t const volatile *const pInputB = (GPIOx_IDR_t*)0x40020410;

	uint8_t const LIMIT = 4;

	pClk->gpioa_en = 1; // Enables clock for GPIOA and B
	pClk->gpiob_en = 1;


	// Set output for rows
	pModeA->pin3 = 1;
	pModeA->pin2 = 1;
	pModeA->pin10 = 1;
	pModeB->pin3 = 1;

	// Set input for column
	pModeB->pin5 = 0;
	pModeB->pin4 = 0;
	pModeB->pin10 = 0;
	pModeA->pin8 = 0;

	// Set pullups for columns
	pPullupB->pupdr5 = 1;
	pPullupB->pupdr4 = 1;
	pPullupB->pupdr10 = 1;
	pPullupA->pupdr8 = 1;

	//uint32_t *row[4] = {pOutputA->odr3, pOutputA->odr2, pOutputA->odr10, pOutputB->odr3};
	//uint32_t *columns[4] = {pInputB->idr5, pInputB->idr4, pInputB->idr10, pInputA->idr8};
	//char const keypad[4][4] = { '1', '2', '3', 'A', '4', '5', '6', 'B',
	//		                    '7', '8', '9', 'C', '*', '0', '#', 'D'};

	// Set all outputs to HIGH
//	for (uint8_t i = 0; i < LIMIT; i++)
//	{
//		row[i] = 1;
//	}
	pOutputA->odr3 = 1;
	pOutputA->odr2 = 1;
	pOutputA->odr10 = 1;
	pOutputB->odr3 = 1;

	while(1)
	{
		pOutputA->odr3 = 0;

		if (pInputB->idr5 == 0)
		{
			delay(150);
			if (pInputB->idr5 == 0)
			{
				printf("1\n");
			}
		}
		else if (pInputB->idr4 == 0)
		{
			delay(150);
			if (pInputB->idr4 == 0)
			{
				printf("Key pressed is %c", '2');
			}
		}
		else if (pInputB->idr10 == 0)
		{
			delay(150);
			if (pInputB->idr10 == 0)
			{
				printf("Key pressed is %c", '3');
			}
		}
		else if (pInputA->idr8 == 0)
		{
			delay(150);
			if (pInputA->idr8 == 0)
			{
				printf("Key pressed is %c", 'A');
			}
		}

		pOutputA->odr3 = 1;
		pOutputA->odr2 = 0;

		if (pInputB->idr5 == 0)
		{
			delay(150);
			if (pInputB->idr5 == 0)
			{
				printf("Key pressed is %c", '4');
			}
		}
		else if (pInputB->idr4 == 0)
		{
			delay(150);
			if (pInputB->idr4 == 0)
			{
				printf("Key pressed is %c", '5');
			}
		}
		else if (pInputB->idr10 == 0)
		{
			delay(150);
			if (pInputB->idr10 == 0)
			{
				printf("Key pressed is %c", '6');
			}
		}
		else if (pInputA->idr8 == 0)
		{
			delay(150);
			if (pInputA->idr8 == 0)
			{
				printf("Key pressed is %c", 'B');
			}
		}

	}


//	while(1)
//	{
//		for (uint8_t i = 0; i < LIMIT; i++)
//		{
//			row[i] = 0;
//
//			if (i == 0)
//				row[LIMIT-1] = 1;
//			else
//				row[i-1] = 1;
//
//			for (uint8_t j = 0; j < LIMIT; j++)
//			{
//				if (columns[j] == 0)
//				{
//					// needs delay, reads key pad
//					for(uint32_t k = 0; k < 1000000000/2; k++)
//					{
//						if (columns[j] == 0)
//							printf("Key is '%c'", keypad[i][j]);
//						break;
//					}
//				}
//			}
//		}
//	}
}


void delay(int milliseconds)
{
	int delay = milliseconds * 2000;

	for(int i = 0; i < delay; i++)
	{
		;
	}
}

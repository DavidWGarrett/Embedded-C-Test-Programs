#include <stdint.h>
#include "regF401re.h"


#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

int main(void)
{
//	uint32_t volatile *const pRccEn = (uint32_t*)0x40023830;
//	uint32_t volatile *const pGpioMode = (uint32_t*)0x40020C00;
//	uint32_t volatile *const pGpioOutputD2 = (uint32_t*)0x40020C14;
//	uint32_t volatile *const pGpioModeC11 = (uint32_t*)0x40020800;
//	uint32_t const volatile *const pGpioInputC11 = (uint32_t*) 0x40020810;
	uint32_t on;


	RCC_AHB1ENR_t volatile *const pClk = (RCC_AHB1ENR_t*)0x40023830;
	GPIOx_MODER_t volatile *const pModeC = (GPIOx_MODER_t*)0x40020800;
	GPIOx_MODER_t volatile *const pModeD = (GPIOx_MODER_t*)0x40020C00;
	GPIOx_ODR_t volatile *const pOutputD2 = (GPIOx_ODR_t*)0x40020C14;
	GPIOx_IDR_t const volatile *const pInputC11 = (GPIOx_IDR_t*)0x40020810;


	// Enable clock on AHB1
	pClk->gpiod_en = 1;
	pClk->gpioc_en = 1;


	// clear register

	pModeC->pin11 = 0b00;
	pModeD->pin2 = 0b01;


	//*pGpioMode &= ~(0b11 << 4); //0xFFFFFFCF
	//*pGpioModeC11 &= 0x0;

	// set control mode

	//*pGpioMode |= (1 << 4); // 0x10


	// set HIGH

	// This turns on IDR2 ????
	while(1)
	{
		//uint32_t test = pModeD->pin2;
		on = (pInputC11->idr11);

		if (on)
		{
			pOutputD2->odr2 = 1; //0x4
		}
		else
		{
			pOutputD2->odr2 = 0;
		}
	}
}

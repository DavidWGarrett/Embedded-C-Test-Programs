#include <stdint.h>

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

// 0x4002 0C00 - 0x4002 0FFF GPIOD
// I'm using D2 which is the second pin above ground and is also second from the edge

// 0x4002 3800 - 0x4002 3BFF - RCC


/*
 * 0x4002 3800 - 0x4002 3BFF - RCC

6.3.9 RCC AHB1 peripheral clock enable register (RCC_AHB1ENR)
Address offset: 0x30 --- ADD TO BASE ADDRESS
Reset value: 0x0000 0000

Bit 3 GPIODEN: IO port D clock enable
Set and cleared by software.
0: IO port D clock disabled
1: IO port D clock enabled
 */

/*
 * Address of the Clock Control register (AHB1ENR)
0x40023800+0x30 = 0x40023830

Address of the GPIOD mode register (used to control mode)
0x40020C00 + 0x00 = 0x40020C00

Address of the GPIO output data register - used to write (GPIOx_ODR)
0x40020C00 + 0x14 = 0x40020C14
 */

// USE WINDOW - SHOW VIEW - SFR -- SHOWS REGISTERS


/*
 * When PC11 high, LED goes on
 * When PC11 low, LED goes off
 */

int main(void)
{
	uint32_t* pRccEn = (uint32_t*)0x40023830;
	uint32_t* pGpioMode = (uint32_t*)0x40020C00;
	uint32_t* pGpioOutputD2 = (uint32_t*)0x40020C14;
	uint32_t* pGpioModeC11 = (uint32_t*)0x40020800;
	uint32_t* pGpioInputC11 = (uint32_t*) 0x40020810;


	*pRccEn |= (0b11 << 2); // turn gpio c and d


	// clear register
	*pGpioMode &= ~(0b11 << 4); //0xFFFFFFCF
	*pGpioModeC11 &= 0x0;

	// set control mode

	*pGpioMode |= (1 << 4); // 0x10


	// set HIGH

	// This turns on IDR2 ????
	while(1)
	{
		uint32_t on = ((*pGpioInputC11 >> 11) & 0x1);

		if (on)
		{
			*pGpioOutputD2 |= (1 << 2); //0x4
		}
		else
		{
			*pGpioOutputD2 &= ~(1 << 2);
		}
	}
    /* Loop forever */
}

#ifndef H_registersF401re
#define H_registersF401re

#include <stdint.h>

typedef struct
{
	uint32_t gpioa_en:1;
	uint32_t gpiob_en:1;
	uint32_t gpioc_en:1;
	uint32_t gpiod_en:1;
	uint32_t gpioe_en:1;
	uint32_t reserved1:2;
	uint32_t gpioh_en:1;
	uint32_t reserved2:4;
	uint32_t crc_en:1;
	uint32_t reserved3:8;
	uint32_t dma1_en:1;
	uint32_t dma2_en:1;
	uint32_t reserved4:9;
}RCC_AHB1ENR_t;

typedef struct
{
	uint32_t pin0:2;
	uint32_t pin1:2;
	uint32_t pin2:2;
	uint32_t pin3:2;
	uint32_t pin4:2;
	uint32_t pin5:2;
	uint32_t pin6:2;
	uint32_t pin7:2;
	uint32_t pin8:2;
	uint32_t pin9:2;
	uint32_t pin10:2;
	uint32_t pin11:2;
	uint32_t pin12:2;
	uint32_t pin13:2;
	uint32_t pin14:2;
	uint32_t pin15:2;
}GPIOx_MODER_t;

typedef struct
{ //might not need this
	uint32_t pin0:2;
	uint32_t pin1:2;
	uint32_t pin2:2;
	uint32_t pin3:2;
	uint32_t pin4:2;
	uint32_t pin5:2;
	uint32_t pin6:2;
	uint32_t pin7:2;
	uint32_t pin8:2;
	uint32_t pin9:2;
	uint32_t pin10:2;
	uint32_t pin11:2;
	uint32_t pin12:2;
	uint32_t pin13:2;
	uint32_t pin14:2;
	uint32_t pin15:2;
}GPIOD_MODER_t;

typedef struct
{
	uint32_t idr0:1;
	uint32_t idr1:1;
	uint32_t idr2:1;
	uint32_t idr3:1;
	uint32_t idr4:1;
	uint32_t idr5:1;
	uint32_t idr6:1;
	uint32_t idr7:1;
	uint32_t idr8:1;
	uint32_t idr9:1;
	uint32_t idr10:1;
	uint32_t idr11:1;
	uint32_t idr12:1;
	uint32_t idr13:1;
	uint32_t idr14:1;
	uint32_t idr15:1;
	uint32_t reserved:16;
}GPIOx_IDR_t;

typedef struct
{
	uint32_t odr0:1;
	uint32_t odr1:1;
	uint32_t odr2:1;
	uint32_t odr3:1;
	uint32_t odr4:1;
	uint32_t odr5:1;
	uint32_t odr6:1;
	uint32_t odr7:1;
	uint32_t odr8:1;
	uint32_t odr9:1;
	uint32_t odr10:1;
	uint32_t odr11:1;
	uint32_t odr12:1;
	uint32_t odr13:1;
	uint32_t odr14:1;
	uint32_t odr15:1;
	uint32_t reserved:16;
}GPIOx_ODR_t;


#endif

#include "stm32f10x.h"
void LightSensor_Init(GPIO_TypeDef *gpix, uint16_t pin, GPIOMode_TypeDef mode, GPIOSpeed_TypeDef speed)
{
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);

    GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Mode  = mode;
    GPIO_InitStructure.GPIO_Pin   = pin;
    GPIO_InitStructure.GPIO_Speed = speed;
    GPIO_Init(gpix, &GPIO_InitStructure);
    GPIO_SetBits(gpix, pin);
}

uint8_t LightSensor_Get(GPIO_TypeDef *gpix, uint16_t pin)
{
    return GPIO_ReadInputDataBit(gpix, pin);
}
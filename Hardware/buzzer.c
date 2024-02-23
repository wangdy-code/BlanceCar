#include "stm32f10x.h"
void Buzzer_Init(GPIO_TypeDef *gpix, uint16_t pin, GPIOMode_TypeDef mode, GPIOSpeed_TypeDef speed)
{
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);

    GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Mode  = mode;
    GPIO_InitStructure.GPIO_Pin   = pin;
    GPIO_InitStructure.GPIO_Speed = speed;
    GPIO_Init(gpix, &GPIO_InitStructure);
    GPIO_SetBits(gpix, pin);
}

void Buzzer_Turn(GPIO_TypeDef *gpix, uint16_t pin)
{
    GPIO_WriteBit(gpix, pin, !GPIO_ReadOutputDataBit(gpix, pin));
}
void Buzzer_ON(GPIO_TypeDef *gpix, uint16_t pin)
{
    GPIO_WriteBit(gpix, pin, 0);
}
void Buzzer_OFF(GPIO_TypeDef *gpix, uint16_t pin)
{
    GPIO_WriteBit(gpix, pin, 1);
}
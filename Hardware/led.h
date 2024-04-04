#ifndef __LED_H__
void LED_Init(GPIO_TypeDef *gpiox, uint16_t pin, GPIOMode_TypeDef mode, GPIOSpeed_TypeDef speed);
void LED_Turn(GPIO_TypeDef *gpix, uint16_t pin);
void LED_OFF(GPIO_TypeDef *gpix, uint16_t pin);
void LED_ON(GPIO_TypeDef *gpix, uint16_t pin);
#endif // !__LED_H
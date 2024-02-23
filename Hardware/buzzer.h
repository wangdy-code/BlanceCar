#ifndef __BUZZER_H
void Buzzer_Init(GPIO_TypeDef *gpix, uint16_t pin, GPIOMode_TypeDef mode, GPIOSpeed_TypeDef speed);
void Buzzer_Turn(GPIO_TypeDef *gpix, uint16_t pin);
void Buzzer_OFF(GPIO_TypeDef *gpix, uint16_t pin);
void Buzzer_ON(GPIO_TypeDef *gpix, uint16_t pin);
#endif // !__BUZZER_H
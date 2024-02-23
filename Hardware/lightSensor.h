#ifndef __LIGHTSENSOR_H
void LightSensor_Init(GPIO_TypeDef *gpix, uint16_t pin, GPIOMode_TypeDef mode, GPIOSpeed_TypeDef speed);
uint8_t LightSensor_Get(GPIO_TypeDef *gpix, uint16_t pin);
#endif // !__LIGHTSENSOR_H
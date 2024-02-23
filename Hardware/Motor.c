#include "stm32f10x.h"
#include "pwm.h"

void Motor_Init()
{
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);

    GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_4 | GPIO_Pin_5;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStructure);

    Pwm_Init();
}

void Motor_SetSpeed(int8_t speed)
{
    if (speed >= 0) // 如果设置正转的速度值
    {
        GPIO_SetBits(GPIOA, GPIO_Pin_4);   // PA4置高电平
        GPIO_ResetBits(GPIOA, GPIO_Pin_5); // PA5置低电平，设置方向为正转
        PWM_SetCompare3(speed);            // PWM设置为速度值
    }
    if (speed < 0) // 否则，即设置反转的速度值
    {
        GPIO_ResetBits(GPIOA, GPIO_Pin_4); // PA4置低电平
        GPIO_SetBits(GPIOA, GPIO_Pin_5);   // PA5置高电平，设置方向为反转
        PWM_SetCompare3(-speed);           // PWM设置为负的速度值，因为此时速度值为负数，而PWM只能给正数
    }
}
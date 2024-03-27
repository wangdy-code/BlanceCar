#include "stm32f10x.h"

float g_middleAngle = 1.0;
float g_kpBalance   = -10;
float g_kdBalance   = 0;

int16_t ControlBalance(float Angle, float Gxro)
{
    int outSpeed    = 0;
    float angleBias = 0.0;
    float gyroBias  = 0.0;
    float tempAngle = 0.0;
    float tempGyro  = 0.0;

    tempAngle = 0 - Angle; // 极性控制
    tempGyro  = 0 - Gxro;

    angleBias = g_middleAngle - tempAngle;
    gyroBias  = 0 - tempGyro;
    outSpeed  = (g_kpBalance / 100 * angleBias + g_kdBalance * gyroBias / 100);
    return outSpeed;
}
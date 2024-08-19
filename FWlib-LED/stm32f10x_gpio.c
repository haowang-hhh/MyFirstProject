#include "stm32f10x_gpio.h"

void GPIO_SetBits(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin_x)
{
    GPIOx->BSRR |= GPIO_Pin_x;
}

void GPIO_ResetBits(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin_x)
{
    GPIOx->BRR |= GPIO_Pin_x;
}


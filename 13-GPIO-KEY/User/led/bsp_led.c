// bsp: board support package 板级支持包

#include "bsp_led.h"

void LED_GPIO_Config(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;

    RCC_APB2PeriphClockCmd(LED_G_GPIO_CLK, ENABLE);

    GPIO_InitStructure.GPIO_Pin   = LED_G_GPIO_PIN | LED_B_GPIO_PIN | LED_R_GPIO_PIN;
    GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    
    GPIO_Init(LED_G_GPIO_PORT, &GPIO_InitStructure);
}



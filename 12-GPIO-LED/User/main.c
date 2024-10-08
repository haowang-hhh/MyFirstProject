#include "stm32f10x.h"
#include "bsp_led.h"

void Delay(uint32_t count)
{
    for (; count != 0; count--);
}

int main(void)
{
    LED_GPIO_Config();

    while (1)
    {
        /* code */
        // GPIO_SetBits(LED_G_GPIO_PORT, LED_G_GPIO_PIN);
        // GPIO_ResetBits(LED_G_GPIO_PORT, LED_G_GPIO_PIN);
        LED_G(ON);
        Delay(0xFFFFF);
        LED_G(OFF);

        LED_B(ON);
        Delay(0xFFFFF);
        LED_B(OFF);

        LED_R(ON);
        Delay(0xFFFFF);
        LED_R(OFF);
    }
    
}


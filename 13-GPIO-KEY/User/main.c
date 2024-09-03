#include "stm32f10x.h"
#include "bsp_led.h"
#include "bsp_key.h"

void Delay(uint32_t count)
{
    for (; count != 0; count--);
}

int main(void)
{
    LED_GPIO_Config();
    KEY_GPIO_Config();

    LED_G(OFF);
    LED_R(OFF);
    LED_B(OFF);

    while (1)
    {
        /* code */
        if (Key_Scan(KEY_1_GPIO_PORT, KEY_1_GPIO_PIN) == KEY_ON) {
            LED_R_TOGGLE; 
        }

        if (Key_Scan(KEY_2_GPIO_PORT, KEY_2_GPIO_PIN) == KEY_ON) {
            LED_B_TOGGLE; 
        }
    }
    
}


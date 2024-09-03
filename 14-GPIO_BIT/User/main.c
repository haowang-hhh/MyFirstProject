#include "stm32f10x.h"
#include "bsp_led.h"
#include "bsp_key.h"

void Delay(uint32_t count)
{
    for (; count != 0; count--);
}

#define GPIOB_ODR_ADDR        (GPIOB_BASE + 0x0C)
#define PB_OUT(addr, bitnum)  *(unsigned int *)((addr & 0xF0000000)+0x02000000+((addr & \
0x00FFFFFF)<<5)+(bitnum<<2))

#define GPIOA_IDR_ADDR        (GPIOA_BASE + 0x08)
#define PA_IN(addr, bitnum)   *(unsigned int *)((addr & 0xF0000000)+0x02000000+((addr & \
0x00FFFFFF)<<5)+(bitnum<<2))

#define GPIOC_IDR_ADDR        (GPIOC_BASE + 0x08)
#define PC_IN(addr, bitnum)   *(unsigned int *)((addr & 0xF0000000)+0x02000000+((addr & \
0x00FFFFFF)<<5)+(bitnum<<2))

int main(void)
{
    LED_GPIO_Config();
    KEY_GPIO_Config();

    LED_G(OFF);
    LED_R(OFF);
    LED_B(OFF);
#if 0
    while (1)
    {
        // LED_B(ON);
        BITBAND(GPIOB_ODR_ADDR, 0) = 1;
        Delay(0xFFFFF);
        // LED_B(OFF);
        BITBAND(GPIOB_ODR_ADDR, 0) = 0;
        Delay(0xFFFFF);
    }

#else
    while (1)
    {
        /* code */
        if (PA_IN(GPIOA_IDR_ADDR, 0) == KEY_ON) {
            // 等待按键释放
            while(PA_IN(GPIOA_IDR_ADDR, 0) == KEY_ON);
            LED_R_TOGGLE; 
        }
        
        if (PC_IN(GPIOC_IDR_ADDR, 13) == KEY_ON) {
            // 等待按键释放
            while(PC_IN(GPIOC_IDR_ADDR, 13) == KEY_ON);
            LED_B_TOGGLE; 
        }
    }
#endif
}


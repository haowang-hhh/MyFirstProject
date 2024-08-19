#include "stm32f10x.h"

#define LED_RED_INDEX   5
#define LED_GREEN_INDEX 0
#define LED_BLUE_INDEX  1

#define LED_ON          0
#define LED_OFF         1

void delay(void)
{
	unsigned int i = 0;
	unsigned int j = 0;

	for (i = 0; i < 1000; i++) {
		for (j = 0; j < 1000; j++) {

		}
	}

}

// PB0
void led_pb_rcc_enable(void)
{
	// 使能PortB时钟
	RCC->APB2ENR |= (1<<3);
}

void led_pb_mode_set(char pb_index)
{
	// 配置PBx为输出
	GPIOB->CRL |= (1<<(4*pb_index));
}

void led_pb_output_value_set(char pb_index, char value)
{
	if (value) {
		GPIOB->ODR |= (1<<pb_index); // 高电平熄灭
	} else {
		GPIOB->ODR &= ~(1<<pb_index); // 低电平点亮
	}
}

void led_pb_output_value_set_with_bsrr(char pb_index, char value)
{
	if (value) {
		GPIOB->BSRR |= (1<<pb_index); // 熄灭
	} else {
		// GPIOB_BSRR &= ~(1<<pb_index); // 清零BS
		GPIOB->BSRR |= (1<<(pb_index+16)); // 点亮
	}
}

void led_pb_output_value_set_with_brr(char pb_index, char value)
{
	if (value) {
		led_pb_output_value_set_with_bsrr(pb_index, value); // 熄灭
	} else {
		GPIOB->BRR |= (1<<pb_index); // 点亮
	}
}

int main(void)
{
#if 0
	// 使能PortB时钟
	RCC_APB2ENR |= (1<<3);

	// 配置PB1为输出
	GPIOB_CRL |= (1<<(4*1));

	while(1) {
		// 控制ODR寄存器
		GPIOB_ODR &= ~(1<<1); // 低电平点亮
		delay();
		
		GPIOB_ODR |= (1<<1); // 高电平熄灭
		delay();
	}
#endif
	led_pb_rcc_enable();

	led_pb_mode_set(LED_GREEN_INDEX);  // G
	led_pb_mode_set(LED_BLUE_INDEX);   // B
	led_pb_mode_set(LED_RED_INDEX);    // R

	while(1) {
		led_pb_output_value_set_with_brr(LED_GREEN_INDEX, LED_ON);
		led_pb_output_value_set_with_brr(LED_BLUE_INDEX, LED_ON);
		led_pb_output_value_set_with_brr(LED_RED_INDEX, LED_ON);
		delay();
		led_pb_output_value_set_with_brr(LED_GREEN_INDEX, LED_OFF);
		led_pb_output_value_set_with_brr(LED_BLUE_INDEX, LED_OFF);
		led_pb_output_value_set_with_brr(LED_RED_INDEX, LED_OFF);
		delay();
	}

	
	return 0;
}


// 前提是不用固件库就需要定义下列函数
void SystemInit(void)
{
	// 函数体为空，目的是为了骗过编译器不报错  

	return;
}

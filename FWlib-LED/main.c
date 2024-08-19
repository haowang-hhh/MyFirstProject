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
	// ʹ��PortBʱ��
	RCC->APB2ENR |= (1<<3);
}

void led_pb_mode_set(char pb_index)
{
	// ����PBxΪ���
	GPIOB->CRL |= (1<<(4*pb_index));
}

void led_pb_output_value_set(char pb_index, char value)
{
	if (value) {
		GPIOB->ODR |= (1<<pb_index); // �ߵ�ƽϨ��
	} else {
		GPIOB->ODR &= ~(1<<pb_index); // �͵�ƽ����
	}
}

void led_pb_output_value_set_with_bsrr(char pb_index, char value)
{
	if (value) {
		GPIOB->BSRR |= (1<<pb_index); // Ϩ��
	} else {
		// GPIOB_BSRR &= ~(1<<pb_index); // ����BS
		GPIOB->BSRR |= (1<<(pb_index+16)); // ����
	}
}

void led_pb_output_value_set_with_brr(char pb_index, char value)
{
	if (value) {
		led_pb_output_value_set_with_bsrr(pb_index, value); // Ϩ��
	} else {
		GPIOB->BRR |= (1<<pb_index); // ����
	}
}

int main(void)
{
#if 0
	// ʹ��PortBʱ��
	RCC_APB2ENR |= (1<<3);

	// ����PB1Ϊ���
	GPIOB_CRL |= (1<<(4*1));

	while(1) {
		// ����ODR�Ĵ���
		GPIOB_ODR &= ~(1<<1); // �͵�ƽ����
		delay();
		
		GPIOB_ODR |= (1<<1); // �ߵ�ƽϨ��
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


// ǰ���ǲ��ù̼������Ҫ�������к���
void SystemInit(void)
{
	// ������Ϊ�գ�Ŀ����Ϊ��ƭ��������������  

	return;
}

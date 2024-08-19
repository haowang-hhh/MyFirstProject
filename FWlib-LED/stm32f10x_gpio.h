#ifndef __STM32F10X_GPIO_H
#define __STM32F10X_GPIO_H

#include "stm32f10x.h"

#define GPIO_Pin_0    ((uint16_t)0x0001)  /* !<选择Pin0> */
#define GPIO_Pin_1    ((uint16_t)0x0002)  /* !<选择Pin1> */
#define GPIO_Pin_2    ((uint16_t)0x0004)  /* !<选择Pin2> */
#define GPIO_Pin_3    ((uint16_t)0x0008)  /* !<选择Pin3> */
#define GPIO_Pin_4    ((uint16_t)0x0010)  /* !<选择Pin4> */
#define GPIO_Pin_5    ((uint16_t)0x0020)  /* !<选择Pin5> */
#define GPIO_Pin_6    ((uint16_t)0x0040)  /* !<选择Pin6> */
#define GPIO_Pin_7    ((uint16_t)0x0080)  /* !<选择Pin7> */

#define GPIO_Pin_8    ((uint16_t)0x0100)  /* !<选择Pin8> */
#define GPIO_Pin_9    ((uint16_t)0x0200)  /* !<选择Pin9> */
#define GPIO_Pin_10   ((uint16_t)0x0400)  /* !<选择Pin10> */
#define GPIO_Pin_11   ((uint16_t)0x0800)  /* !<选择Pin11> */
#define GPIO_Pin_12   ((uint16_t)0x1000)  /* !<选择Pin12> */
#define GPIO_Pin_13   ((uint16_t)0x2000)  /* !<选择Pin13> */
#define GPIO_Pin_14   ((uint16_t)0x4000)  /* !<选择Pin14> */
#define GPIO_Pin_15   ((uint16_t)0x8000)  /* !<选择Pin15> */
#define GPIO_Pin_ALL  ((uint16_t)0xFFFF)  /* !<选择Pin16> */

void GPIO_SetBits(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin_x);
void GPIO_ResetBits(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin_x);

#endif /* __STM32F10X_GPIO_H */

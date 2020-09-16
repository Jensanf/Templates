
/* Enable clock to PORTE */
/* Set PA5 to output mode */
/* Write to PE9 */

.cpu cortex-m4
.syntax unified

.equ GPIOE_BASE,            0x48001000
.equ GPIOE_MODER_OFFSET,    0x00
.equ GPIOE_ODR_OFFSET,      0x14

.equ GPIOE_MODER,           GPIOE_BASE + GPIOE_MODER_OFFSET
.equ GPIOE_ODR,             GPIOE_BASE + GPIOE_ODR_OFFSET

.equ RCC_BASE,              0x40021000
.equ AHB1ENR_OFFSET,        0x14
.equ RCC_AHB1ENR, 			RCC_BASE + AHB1ENR_OFFSET

.equ GPIOE_EN, 				0x00200000
.equ MODER9_OUT, 			0x00040000
.equ LED_ON,				0x0200

		.section .text
		.global main

main:

			BL			GPIO_Init
GPIO_Init:
		/*RCC->AHB1ENR |= GPIOE_EN*/
		//Load address of RCC_AHB1ENR TO R0
		LDR			R0,=RCC_AHB1ENR
		//Load value at address found in R0 into R1
		LDR 		R1, [R0]
		//
		ORR			R1, #GPIOE_EN
		//Store the content in R1 at the address found in R0
		STR 		R1, [R0]


		/* GPIOE -> MODER |=MODER9_OUT */
		LDR			R0, =GPIOE_MODER
		LDR			R1, [R0]
		ORR 		R1, #MODER9_OUT
		STR			R1, [R0]


		/*GPIOE-> ODR = LED_ON */
		LDR 		R0,=GPIOE_ODR
		LDR 		R1,=LED_ON
		STR			R1, [R0]

		BX			LR

		.end




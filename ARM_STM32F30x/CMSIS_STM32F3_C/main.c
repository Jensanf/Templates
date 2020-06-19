#include "stm32f3xx.h"

void delay(unsigned long delay)
{
    while(delay) delay--;
}

int main() {
    RCC -> AHBENR |= RCC_AHBENR_GPIOEEN;
    GPIOE -> MODER |= GPIO_MODER_MODER9_0 | GPIO_MODER_MODER8_0 | GPIO_MODER_MODER10_0;
    while(1)
    {   
        GPIOE->ODR |= (GPIO_ODR_8 | GPIO_ODR_9 | GPIO_ODR_10);
        delay(500000);
        GPIOE->ODR &= ~(GPIO_ODR_8 | GPIO_ODR_9 | GPIO_ODR_10);
        delay(500000);
    }
}
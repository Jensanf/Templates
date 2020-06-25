#include "stm32f3xx.h"

void delay(unsigned long delay)
{
    while(delay) delay--;
}

int main() {
    RCC -> AHBENR |= RCC_AHBENR_GPIOEEN | RCC_AHBENR_GPIOAEN;
    GPIOE -> MODER |= GPIO_MODER_MODER9_0;
    GPIOA -> MODER &= ~(1 << 0);
    while(1)
    {   
        if(GPIOA->IDR & 0x00000001){
          GPIOE->ODR |= (GPIO_ODR_9);
          delay(500000);
          GPIOE->ODR &= ~(GPIO_ODR_9);
          delay(500000);
        }
    }
}
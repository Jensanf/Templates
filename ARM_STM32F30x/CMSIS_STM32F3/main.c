#include "stm32f3xx.h"

void delay(unsigned long delay)
{
    while(delay) delay--;
}

int main() {
    RCC -> AHBENR |= (1<<21);
    GPIOE -> MODER |= 0x55550000;
    while(1)
    {
        GPIOE->ODR |= 0x0000FF00;
        delay(500000);
        GPIOE->ODR &= ~(0x0000FF00);
        delay(500000);
    }
}
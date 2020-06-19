#include "stm32f3xx.h"
#include "led.hpp"

extern "C" {
	int __low_level_init(void) {
                RCC -> AHBENR |= RCC_AHBENR_GPIOEEN;
                GPIOE -> MODER |= GPIO_MODER_MODER9_0 | GPIO_MODER_MODER8_0 | GPIO_MODER_MODER10_0;

		return 1;
	}
	inline void Delay(unsigned int mSec) {
		for (unsigned int i = 0U; i < mSec * 3000U; i++) {
			__NOP();
		};
	}
}
int main() {
	Led Led1(*GPIOE, 8U);
        while(1){
          Led1.Toggle();
          Delay(1000U);
          Led1.Toggle();
          Delay(1000U);
        }
}
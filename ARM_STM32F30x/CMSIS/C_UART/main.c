#include "stm32f3xx.h" //Описание регистров, необходимо раскоментировать строку вашей модели микроконтроллера
void UART_Init (void); // Объявляем функцию
volatile uint32_t t;//Переменная регистра приема
unsigned int i;
void UART4_Send_String (char*);

void delay () {
     for (i=0;i<1000000;i++);
}


int main (void) {
     UART_Init();//Инициализируем

     RCC->AHBENR|=(1<<21);
     GPIOE->MODER|=GPIO_MODER_MODER9_0|GPIO_MODER_MODER10_0|GPIO_MODER_MODER11_0;
     GPIOE->MODER|=0x10000;
     while (1){
          delay ();
          GPIOE->ODR|=0x100;
          delay ();
          GPIOE->ODR&=~(0x100);
          UART4_Send_String ("Ok\r\n");
          t = 3;
     }
}


void UART4_Send (char chr){
	while (!(UART4->ISR & USART_ISR_TC)); //Сравниваем регистр статуса с разрядом установки флага об окончании прерывания
	UART4->TDR = chr;
}

void UART4_Send_String (char* str){
	uint8_t i = 0;
	while(str[i])
	UART4_Send (str[i++]);

}

void UART_Init (void){
	RCC->APB1ENR |= RCC_APB1ENR_UART4EN;//Подаем тактирование на уарт 
	RCC->AHBENR|=RCC_AHBENR_GPIOCEN;//Включаем тактирование порта GPIOC 
        //Настраиваем порт Tx PC10
	GPIOC->MODER |= GPIO_MODER_MODER10_1;//10 - режим альтернативных функций
	GPIOC->OTYPER &= ~GPIO_OTYPER_OT_10;//0 - 0: двухтактный выход или push-pull сокращено PP(после сброса)
	GPIOC->PUPDR &= ~GPIO_PUPDR_PUPDR10; //Сброс
	GPIOC->PUPDR |= GPIO_PUPDR_PUPDR10_0;//01 - подтяжка к плюсу питания или pull-up сокращено PU
        GPIOC->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR10;//11 - высокочастотный выход
	GPIOC->AFR[1]|=(0x05<<(4*2));//Назначаем 10 выводу альтернативную функцию
	//Настаиваем Rx   PC11
	GPIOC->MODER |= GPIO_MODER_MODER11_1;//10 - режим альтернативных функций
	GPIOC->PUPDR &= ~GPIO_PUPDR_PUPDR11;//00 - состояние после сброса, no pull up, pull down
	GPIOC->AFR[1]|=(0x05<<(4*3));//назначаем 11 выводу альтернативную функцию

	UART4->BRR = 833;//  (16)(8000000+4800)/9600 = 0x341 (833)
	UART4->CR1|=USART_CR1_UE|USART_CR1_TE|USART_CR1_RE;//вкл. uart, приема и передачи
	UART4->CR1|=USART_CR1_RXNEIE;//Разрешаем генерировать прерывание по приему
	NVIC_EnableIRQ(UART4_IRQn);//Включаем прерывание, указываем вектор
}

void UART4_IRQHandler  (void){
	if (UART4->ISR & USART_ISR_RXNE){          //Следим за состоянием данного флага 1 - данные пришли, 0- пусто    
            UART4->ISR &= ~USART_ISR_RXNE;         //Обнулим данный бит
            t = UART4->RDR;
            GPIOE->ODR|=GPIO_ODR_9;              // Индикатор начала uart трансляции
            if (t == '0'){                           // Если отправляем нолик, то отключаем светодиод
                GPIOE->ODR&=~(GPIO_ODR_11);
                UART4_Send_String ("Off\r\n");
            }
            if (t == '1'){                           // Включаем светодиод
                GPIOE->ODR|=GPIO_ODR_11;
                UART4_Send_String ("On\r\n");
            }
	}
}

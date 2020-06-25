typedef __UINT32_T_TYPE__     uint32_t;
#define     __IO              volatile 

//Find perephirial register for PORT E
#define PERIPH_BASE           0x40000000UL
#define AHB1PERIPH_BASE       (PERIPH_BASE + 0x00020000UL)
#define RCC_BASE              (AHB1PERIPH_BASE + 0x00001000UL)
#define RCC                   ((RCC_TypeDef *) RCC_BASE)

//Find bit for clocking port E
#define RCC_AHBENR_GPIOEEN_Pos                   (21U)  
#define RCC_AHBENR_GPIOEEN_Msk                   (0x1UL << RCC_AHBENR_GPIOEEN_Pos)
#define RCC_AHBENR_GPIOEEN                        RCC_AHBENR_GPIOEEN_Msk

#define AHB2PERIPH_BASE       (PERIPH_BASE + 0x08000000UL)
#define GPIOE_BASE            (AHB2PERIPH_BASE + 0x00001000UL)
#define GPIOE                 ((GPIO_TypeDef *) GPIOE_BASE)


//#define RCCAHB1_ENR (*(unsigned long*)0x40021014)
//#define RCC_AHBENR_GPIOEEN    0x00200000
#define GPIO_ODR_9            0x0200U 

typedef struct
{
  __IO uint32_t CR;         /*!< RCC clock control register,                                  Address offset: 0x00 */
  __IO uint32_t CFGR;       /*!< RCC clock configuration register,                            Address offset: 0x04 */
  __IO uint32_t CIR;        /*!< RCC clock interrupt register,                                Address offset: 0x08 */
  __IO uint32_t APB2RSTR;   /*!< RCC APB2 peripheral reset register,                          Address offset: 0x0C */
  __IO uint32_t APB1RSTR;   /*!< RCC APB1 peripheral reset register,                          Address offset: 0x10 */
  __IO uint32_t AHBENR;     /*!< RCC AHB peripheral clock register,                           Address offset: 0x14 */
  __IO uint32_t APB2ENR;    /*!< RCC APB2 peripheral clock enable register,                   Address offset: 0x18 */
  __IO uint32_t APB1ENR;    /*!< RCC APB1 peripheral clock enable register,                   Address offset: 0x1C */
  __IO uint32_t BDCR;       /*!< RCC Backup domain control register,                          Address offset: 0x20 */
  __IO uint32_t CSR;        /*!< RCC clock control & status register,                         Address offset: 0x24 */
  __IO uint32_t AHBRSTR;    /*!< RCC AHB peripheral reset register,                           Address offset: 0x28 */
  __IO uint32_t CFGR2;      /*!< RCC clock configuration register 2,                          Address offset: 0x2C */
  __IO uint32_t CFGR3;      /*!< RCC clock configuration register 3,                          Address offset: 0x30 */
} RCC_TypeDef;

typedef struct
{
  __IO uint32_t MODER;        /*!< GPIO port mode register,               Address offset: 0x00      */
  __IO uint32_t OTYPER;       /*!< GPIO port output type register,        Address offset: 0x04      */
  __IO uint32_t OSPEEDR;      /*!< GPIO port output speed register,       Address offset: 0x08      */
  __IO uint32_t PUPDR;        /*!< GPIO port pull-up/pull-down register,  Address offset: 0x0C      */
  __IO uint32_t IDR;          /*!< GPIO port input data register,         Address offset: 0x10      */
  __IO uint32_t ODR;          /*!< GPIO port output data register,        Address offset: 0x14      */
  __IO uint32_t BSRR;         /*!< GPIO port bit set/reset register,      Address offset: 0x1A */
  __IO uint32_t LCKR;         /*!< GPIO port configuration lock register, Address offset: 0x1C      */
  __IO uint32_t AFR[2];       /*!< GPIO alternate function registers,     Address offset: 0x20-0x24 */
  __IO uint32_t BRR;          /*!< GPIO bit reset register,               Address offset: 0x28 */
}GPIO_TypeDef;

void main()
{
  //Enable port D clocking
  //*(unsigned long*)(0x40023830) |= 0x8    // for F4discovery
  
  //Enable port E clocking
  //*(unsigned long*)(0x40021014) |= 0x00200000;  
  //  RCCAHB1_ENR |= RCC_AHBENR_GPIOEEN;
  RCC->AHBENR |= RCC_AHBENR_GPIOEEN;
  
  //little delay for GPIOE get ready
  volatile unsigned long i=0;                   
  i++; i++; i++;                                
  i=0;                                          
  
  //Set PD13 as General purpose output          
  //*(unsigned long*)(0x40020C00) = (*(unsigned long*)(0x40020C00)& (~0x0C000000)) | (0x0000000);   // for F4discovery
  
  //Set PE9 as General purpose output 
  //GPIOE->MODER = (*(unsigned long*)(0x48001000)& (~0x000C0000)) | (0x00040000); 
  //GPIOE->MODER &= (~0x000C0000); 
  GPIOE->MODER |= (0x00040000);

//  //Turn LED ON!
//  *(unsigned long*)(0x48001014) |= 0x0200;      

//    while(1);
  while(1){
    //  *(unsigned long*)(0x48001014) |= 0x0200; 
    GPIOE->ODR |= GPIO_ODR_9;
    for( i=0; i<1000000 ;++i );
    //Turn LED OFF
    //  *(unsigned long*)(0x48001014) &= 0x0200; 
    GPIOE->ODR &= ~GPIO_ODR_9;
    //Delay
    for( i=0; i<1000000 ;++i );
  }
}
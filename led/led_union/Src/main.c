#include "stm32f7xx.h"

#include <stdint.h>


#define GPIOE_CLK_EN        (1U<<4)

#define USER_LED0_MODER     (1U<<0)
#define USER_LED1_MODER     (1U<<2)
#define USER_LED2_MODER     (1U<<4)
#define USER_LED3_MODER     (1U<<6)
#define USER_LED4_MODER     (1U<<8)
#define USER_LED5_MODER     (1U<<10)
#define USER_LED6_MODER     (1U<<12)
#define USER_LED7_MODER     (1U<<14)
#define USER_LED8_MODER     (1U<<16)
#define USER_LED9_MODER     (1U<<18)
#define USER_LED10_MODER    (1U<<20)
#define USER_LED11_MODER    (1U<<22)
#define USER_LED12_MODER    (1U<<24)
#define USER_LED13_MODER    (1U<<26)
#define USER_LED14_MODER    (1U<<28)
#define USER_LED15_MODER    (1U<<30)


#define USER_LED0           (1U<<0)
#define USER_LED1           (1U<<1)
#define USER_LED2           (1U<<2)
#define USER_LED3           (1U<<3)
#define USER_LED4           (1U<<4)
#define USER_LED5           (1U<<5)
#define USER_LED6           (1U<<6)
#define USER_LED7           (1U<<7)
#define USER_LED8           (1U<<8)
#define USER_LED9           (1U<<9)
#define USER_LED10          (1U<<10)
#define USER_LED11          (1U<<11)
#define USER_LED12          (1U<<12)
#define USER_LED13          (1U<<13)
#define USER_LED14          (1U<<14)
#define USER_LED15          (1U<<15)

int i;

union {
	uint16_t a;
}led;



int main(void)
{


  RCC->AHB1ENR |= GPIOE_CLK_EN;

  GPIOE->MODER |= USER_LED0_MODER | USER_LED1_MODER | USER_LED2_MODER |
		          USER_LED3_MODER | USER_LED4_MODER | USER_LED5_MODER |
				  USER_LED6_MODER | USER_LED7_MODER | USER_LED8_MODER |
				  USER_LED9_MODER |

				  USER_LED10_MODER | USER_LED11_MODER | USER_LED12_MODER |
				  USER_LED13_MODER | USER_LED14_MODER | USER_LED15_MODER;

  while(1)
  {

	 led.a = 0x0001;

	  for(i=0; i<15; i++){

		GPIOE -> BSRR = led.a <<= 1;
		GPIOE -> BSRR |= (1<<(i+16));
        for(int i=0; i<100000; i++){};

	  }


	 led.a = 0x8000;

	  for(i=0; i<15; i++){

		GPIOE -> BSRR = led.a >>= 1;
	    GPIOE -> BSRR |= (1<<(31-i));
        for(int i=0; i<100000; i++){};

	  }


  }

  }


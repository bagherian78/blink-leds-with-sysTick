#include "stm32f4xx.h"                  // Device header
uint16_t i;
void SysTick_Handler(void){
	i+=10;
	if(i==1000) i=0;
}
void delay(uint16_t delay){
i=0;
	while(i<=delay);
}
int main(){
	SysTick_Config(168000);
	RCC->AHB1ENR|=RCC_AHB1ENR_GPIODEN;
	GPIOD->MODER=1<<24|1<<26|1<<28|1<<30;
	while(1){
		GPIOD->ODR=1<<12|1<<15;
		delay(700);
		GPIOD->ODR=0x00000000;
		GPIOD->ODR=1<<13|1<<14;
		delay(700);
	}
}

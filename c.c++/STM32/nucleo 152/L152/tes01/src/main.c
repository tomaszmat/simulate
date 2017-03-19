/**
  ******************************************************************************
  * @file    main.c
  * @author  Ac6
  * @version V1.0
  * @date    01-December-2013
  * @brief   Default main function.
  ******************************************************************************
*/


#include "stm32l1xx.h"
#include "stm32l1xx_nucleo.h"
void delay(int time)
{
    int i;
    for (i = 0; i < time * 4000; i++) {}
}

int main(void)
{
    GPIO_InitTypeDef gpio; // obiekt gpio z konfiguracja portow GPIO

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE); // uruchomienie zegara modulu GPIO

    GPIO_StructInit(&gpio); // domyslna konfiguracja
    gpio.GPIO_Pin = GPIO_Pin_5; // konfigurujemy pin 5
    gpio.GPIO_Mode = GPIO_Mode_OUT;
    GPIO_Init(GPIOA, &gpio); // inicjalizacja modulu GPIOA

    while (1) {
        GPIO_SetBits(GPIOA, GPIO_Pin_5); // zapalenie diody
        delay(100);
        GPIO_ResetBits(GPIOA, GPIO_Pin_5); // zgaszenie diody
        delay(400);
    }
}
#include "HeatingSystem.h"

GPIO_InitTypeDef  GPIO_InitStructure;

void ledInit(void)
{
    /* GPIOG Periph clock enable */
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);

    /* Configure PD12 in output mode */
    GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_12 | GPIO_Pin_14 ;
    GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_OUT;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
    GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_NOPULL;
    GPIO_Init(GPIOD, &GPIO_InitStructure);

}

void delay(void)
{
    int t = 2000000;
    while(t){
        t--;
    }
}

void vTaskA(void *pvParameters)
{
	for( ; ; ){
        GPIO_SetBits(GPIOD, GPIO_Pin_12);
		vTaskDelay(500);
        GPIO_ResetBits(GPIOD, GPIO_Pin_12);

	}
	vTaskDelete( NULL );

}

void vTaskB(void *pvParameters)
{
	for( ; ; ){
        GPIO_SetBits(GPIOD, GPIO_Pin_14);
		vTaskDelay(500);
        GPIO_ResetBits(GPIOD, GPIO_Pin_14);
	}
	vTaskDelete( NULL );

}


int main(void)
{

    ledInit();

	xTaskCreate(vTaskA, (signed char*)"TaskA",
		configMINIMAL_STACK_SIZE, NULL, 2,(xTaskHandle*)NULL);

	xTaskCreate(vTaskB, (signed char*)"TaskB",
		configMINIMAL_STACK_SIZE, NULL, 2,(xTaskHandle*)NULL);

	vTaskStartScheduler();

    for( ; ; ){
    }
}

/*
* led.h
*
*  Created on: 2024-01-01 13:20:27
*      Author: lime7git
*/

#include "esp_log.h"
#include "driver/gpio.h"
#include "stdbool.h"

#ifndef LED_H_
#define LED_H_

#define LED_GPIO_NUM GPIO_NUM_38

typedef enum 
{
    LED_INIT    = 0,
    LED_ON      = 1,
    LED_OFF     = 2,
    LED_BLINK   = 3,
    LED_CODE2   = 4,
    LED_CODE3   = 5
}ledState_e;

void led_configure(void);
void led_update(void); 
void led_set_state(ledState_e state);

#endif /* LED_H_ */
#ifndef TASK_LED_H_
#define TASK_LED_H_

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "led.h"

void ledTask(void *pvParameter);

#endif /* TASK_LED_H_ */

#ifndef TASK_BUTTON_H_
#define TASK_BUTTON_H_

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "iot_button.h"
#include "esp_log.h"

void buttonTask(void *pvParameter);
void buttonInit(uint32_t button_num);

#endif /* TASK_LED_H_ */

#ifndef TASK_LOG_H_
#define TASK_LOG_H_

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"

void logTask(void *pvParameter);

#endif /* TASK_LOG_H_ */

#include <stdio.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "task_led.h"
#include "task_log.h"
#include "task_button.h"

void app_main()
{
    TaskHandle_t ledTaskHandle;

    xTaskCreate(&ledTask, "ledTask", 4096, NULL, configMAX_PRIORITIES, &ledTaskHandle);
    xTaskCreate(&logTask, "logTask", 2048, NULL, configMAX_PRIORITIES, NULL);
    xTaskCreate(&buttonTask, "buttonTask", 4096, ledTaskHandle, configMAX_PRIORITIES, NULL);
}
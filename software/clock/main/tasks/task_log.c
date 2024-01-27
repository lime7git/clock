#include "task_log.h"

void logTask(void *pvParameter)
{
    while(1) 
    {
        ESP_LOGI("log task", "hello log task!");
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}
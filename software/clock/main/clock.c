#include <stdio.h>

#include "driver/gpio.h"
#include "esp_log.h"

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

void app_main(void)
{

    gpio_config_t cfg = {
        .pin_bit_mask = BIT64(GPIO_NUM_38),
        .mode = GPIO_MODE_OUTPUT,
        .pull_up_en = GPIO_PULLUP_DISABLE,
        .pull_down_en = GPIO_PULLDOWN_DISABLE,
        .intr_type = GPIO_INTR_DISABLE,
    };
    gpio_config(&cfg);

    while (1) {
        gpio_set_level(GPIO_NUM_38, 0);
        vTaskDelay(50);
        gpio_set_level(GPIO_NUM_38, 1);
        vTaskDelay(100);
    }
}

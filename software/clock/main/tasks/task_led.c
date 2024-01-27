#include "task_led.h"

void ledTask(void *pvParameter)
{
    led_configure();
    led_set_state(LED_BLINK);

    while(1) 
    {
        led_update();
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}
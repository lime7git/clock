#include "task_button.h"

#define BOOT_BUTTON_NUM         0
#define BUTTON_ACTIVE_LEVEL     0

static const char *TAG = "button task";

static TaskHandle_t ledTaskHandle;

const char *button_event_table[] = {
    "BUTTON_PRESS_DOWN",
    "BUTTON_PRESS_UP",
    "BUTTON_PRESS_REPEAT",
    "BUTTON_PRESS_REPEAT_DONE",
    "BUTTON_SINGLE_CLICK",
    "BUTTON_DOUBLE_CLICK",
    "BUTTON_MULTIPLE_CLICK",
    "BUTTON_LONG_PRESS_START",
    "BUTTON_LONG_PRESS_HOLD",
    "BUTTON_LONG_PRESS_UP",
};

static void button_event_cb(void *arg, void *data)
{
    ESP_LOGI(TAG, "Button event %s", button_event_table[(button_event_t)data]);

    switch ((button_event_t)data)
    {
        case BUTTON_SINGLE_CLICK:
        {
            vTaskSuspend(ledTaskHandle);
            ESP_LOGI(TAG, "Suspend led task!");
            break;
        }
        case BUTTON_DOUBLE_CLICK:
        {
            vTaskResume(ledTaskHandle);
            ESP_LOGI(TAG, "Resume led task!");
            break;
        }
        case BUTTON_LONG_PRESS_UP:
        {

            break;
        }
        case BUTTON_LONG_PRESS_START:
        {

            break;
        }
        default:
        {
            ESP_LOGI(TAG, "Wrong button event!");
            break;
        }
    }
}

void button_init(uint32_t button_num)
{
    button_config_t btn_cfg = {
        .type = BUTTON_TYPE_GPIO,
        .gpio_button_config = {
            .gpio_num = button_num,
            .active_level = BUTTON_ACTIVE_LEVEL,
        },
    };
    button_handle_t btn = iot_button_create(&btn_cfg);
        assert(btn);

    esp_err_t err = ESP_OK;
    err |= iot_button_register_cb(btn, BUTTON_SINGLE_CLICK, button_event_cb, (void *)BUTTON_SINGLE_CLICK);
    err |= iot_button_register_cb(btn, BUTTON_DOUBLE_CLICK, button_event_cb, (void *)BUTTON_DOUBLE_CLICK);
    err |= iot_button_register_cb(btn, BUTTON_LONG_PRESS_UP, button_event_cb, (void *)BUTTON_LONG_PRESS_UP);
    err |= iot_button_register_cb(btn, BUTTON_LONG_PRESS_START, button_event_cb, (void *)BUTTON_LONG_PRESS_START);
    //err |= iot_button_register_cb(btn, BUTTON_PRESS_DOWN, button_event_cb, (void *)BUTTON_PRESS_DOWN);
    //err |= iot_button_register_cb(btn, BUTTON_PRESS_UP, button_event_cb, (void *)BUTTON_PRESS_UP);
    //err |= iot_button_register_cb(btn, BUTTON_PRESS_REPEAT, button_event_cb, (void *)BUTTON_PRESS_REPEAT);
    //err |= iot_button_register_cb(btn, BUTTON_PRESS_REPEAT_DONE, button_event_cb, (void *)BUTTON_PRESS_REPEAT_DONE);
    //err |= iot_button_register_cb(btn, BUTTON_LONG_PRESS_HOLD, button_event_cb, (void *)BUTTON_LONG_PRESS_HOLD);
    ESP_ERROR_CHECK(err);
}

void buttonTask(void *pvParameter)
{
    ledTaskHandle = (TaskHandle_t)pvParameter;

    button_init(BOOT_BUTTON_NUM);   // initialize button 
    vTaskSuspend(NULL);             // suspend itself

    // We cannot get here unless another task calls vTaskResume
    // with buttonTask as the parameter.
    while(1)
    {   
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}
/*
* led.c
*
*  Created on: 2024-01-01 13:20:27
*      Author: lime7git
*/

#include "led.h"

static void led_update_gpio_state(void);

typedef struct 
{
    enum  {
        LED_GPIO_ON = 0,
        LED_GPIO_OFF = 1
    } gpioState;

    ledState_e ledState;
    unsigned int blinkCount;
    bool initialized;
}led_t;

static led_t led;

void led_configure(void)
{
    gpio_config_t cfg = {
        .pin_bit_mask = BIT64(LED_GPIO_NUM),
        .mode = GPIO_MODE_OUTPUT,
        .pull_up_en = GPIO_PULLUP_DISABLE,
        .pull_down_en = GPIO_PULLDOWN_DISABLE,
        .intr_type = GPIO_INTR_DISABLE,
    };

    if(ESP_OK == gpio_config(&cfg))
    {
        ESP_LOGI("led component", "Led configuration success!");
        led.initialized = true;
    }
    else
    {
        ESP_LOGI("led component", "Led configuration error!"); 
        led.initialized = false;
        return;
    }

    led.ledState = LED_INIT;
    led_update();
}

void led_update(void)
{
    assert(led.initialized);

    switch(led.ledState)
    {
        case LED_INIT:
        {
            led.blinkCount = 0;
            led.gpioState = LED_GPIO_OFF;

            break;
        }
        case LED_ON:
        {
            led.gpioState = LED_GPIO_ON;

            break;
        }
        case LED_OFF:
        {
            led.gpioState = LED_GPIO_OFF;

            break;
        }
        case LED_BLINK:
        {
            led.gpioState = !led.gpioState;

            break;
        }
        case LED_CODE2:
        {
            led.blinkCount++;

            if(led.blinkCount <= 4)
            {
                led.gpioState = !led.gpioState;
            }
            else if(led.blinkCount == 10)
            { 
                led.blinkCount = 0;
            }

            break;
        }
        case LED_CODE3:
        {
            led.blinkCount++;

            if(led.blinkCount <= 6)
            {
                led.gpioState = !led.gpioState;
            }
            else if(led.blinkCount == 10)
            { 
                led.blinkCount = 0;
            }

            break;
        }
        default:
        {
            led.ledState = LED_INIT;
        }
    }

    led_update_gpio_state();
}

void led_set_state(ledState_e state)
{
    assert(led.initialized);

    led.ledState = state;
    led.blinkCount = 0;
}

static void led_update_gpio_state(void)
{
    assert(led.initialized);

    gpio_set_level(LED_GPIO_NUM, led.gpioState);
    ESP_LOGI("led component", "Led state %d", !led.gpioState);
}
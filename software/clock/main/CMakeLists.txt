idf_component_register(SRCS "clock.c" "tasks/task_led.c" "tasks/task_log.c" "tasks/task_button.c"
                    INCLUDE_DIRS "tasks"
                    REQUIRES led)

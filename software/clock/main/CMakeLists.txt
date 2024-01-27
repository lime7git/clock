idf_component_register(SRCS "clock.c" "tasks/task_led.c" "tasks/task_log.c"
                    INCLUDE_DIRS "tasks"
                    REQUIRES led)

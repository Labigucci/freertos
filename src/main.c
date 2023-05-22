#include "FreeRTOS.h"
#include "task.h"

// LED pin number
#define LED_PIN 13

// Task function
void blinkTask(void *pvParameters) {
  pinMode(LED_PIN, OUTPUT);
  
  while (1) {
    digitalWrite(LED_PIN, HIGH);
    vTaskDelay(pdMS_TO_TICKS(500));
    digitalWrite(LED_PIN, LOW);
    vTaskDelay(pdMS_TO_TICKS(500));
  }
}

void setup() {
  // Create a FreeRTOS task
  xTaskCreate(blinkTask, "BlinkTask", configMINIMAL_STACK_SIZE, NULL, 1, NULL);

  // Start the scheduler
  vTaskStartScheduler();
}

void loop() {
  // Empty loop, not used in FreeRTOS
}

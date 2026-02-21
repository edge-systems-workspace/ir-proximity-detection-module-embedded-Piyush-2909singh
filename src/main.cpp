#include <Arduino.h>

/**
 * @file main.cpp
 * @brief Embedded Obstacle Detection System using IR Sensor
 * @author Piyush-2909singh
 * @date 2026-02-21
 *
 * @details
 * Reads digital input from an IR sensor module
 * and displays obstacle presence via Serial Monitor.
 */

// Hardware Definition
#define IR_SENSOR_PIN 2

// State variable
int sensorState = 0;

/**
 * @brief System initialization for serial telemetry and GPIO.
 */
void setup() {
    Serial.begin(9600);

    // Configure IR sensor pin as input
    pinMode(IR_SENSOR_PIN, INPUT);

    Serial.println("System: IR Obstacle Detection Active");
    Serial.println("------------------------------------");
}

/**
 * @brief Main logic loop for real-time obstacle monitoring.
 */
void loop() {
    // Read digital signal from IR sensor
    sensorState = digitalRead(IR_SENSOR_PIN);

    // Evaluate signal: Typically LOW (0) means obstacle detected
    // depending on the specific IR module calibration.
    if (sensorState == LOW) {
        Serial.println("Status: [Obstacle Detected]");
    } else {
        Serial.println("Status: [No Obstacle]");
    }

    // Polling rate stabilizatioNN
    delay(300);
}
#include "ultrasonic.h"

int ultrasonic_timer = 0;

void printDistance(Ultrasonic sensor) {
    if (millis() - ultrasonic_timer > 500) {
        Serial.print("Ultrasonic : ");
        Serial.println(sensor.read());
        ultrasonic_timer = millis();
    }
}
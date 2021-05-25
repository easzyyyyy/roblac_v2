#include "ultrasonic.h"

void printDistance(Ultrasonic sensor) {
    Serial.print("Ultrasonic : ");
    Serial.println(sensor.read());
}
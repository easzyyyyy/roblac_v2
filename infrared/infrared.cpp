#include "infrared.h"

Infrared::Infrared(int dPin) {
    pin = dPin;
}

int Infrared::read() {
    pinMode(pin, INPUT);
    return digitalRead(pin); // 1 = black and 0 = white
}

int infrared_timer = 0;

void printColor(Infrared sensor) {
    if (millis() - infrared_timer > 500) {
        Serial.print("Infrared : ");
        Serial.println(sensor.read());
        infrared_timer = millis();
    }
}

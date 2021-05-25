#include "infrared.h"

Infrared::Infrared(int dPin)
{
    pin = dPin;
}

int Infrared::read()
{
    pinMode(pin, INPUT);
    lastValue = digitalRead(pin); // 1 = black and 0 = white
    return lastValue;
}

void Infrared::print()
{
    Serial.print("Infrared : ");
    Serial.println(read());
}
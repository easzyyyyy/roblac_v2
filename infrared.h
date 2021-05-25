#ifndef __INFRARED_H__
#define __INFRARED_H__

// Basic arduino library
#include <Arduino.h>

class Infrared {
    private:
        int pin;
        int lastValue;

    public:
        Infrared(int dPin);
        int read();
        void print();
};

// Infrared.read() to get the curent value
// Infrared.print() to print the curent value

#endif
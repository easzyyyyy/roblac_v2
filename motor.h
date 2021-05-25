#ifndef __MOTOR_H__
#define __MOTOR_H__

// Basic arduino library
#include <Arduino.h>
// https://github.com/adafruit/Adafruit-Motor-Shield-library
// MotorShieldLibrary by Adafruit
#include <AFMotor.h>

void motor_1_Update();
void motor_2_Update();

void equal();

class Motor
{
    public:
        Motor(int mNb, int cPin);
        void run(int speed, float time = 0);
        void acc();
        void increment();
        void calcSpeed();

        int expectSpeed = 0; // !! LES METTRE EN PRIVÉ !!
        int realSpeed = 0;

    private:
        int nb = 0;
        int inc = 0;
        int endAcc = 0;
        int timeAcc = 0;
        int nextCalc = 0;
        bool accelerating = false;
        AF_DCMotor* motor;
};

// Motor.setSpeed(int) to set the speed of the motor
// Motor.run(FORWARD/BACKWARD/RELEASE) to set the direction of the motor

#endif
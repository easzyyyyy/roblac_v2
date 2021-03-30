#include "servo.h"

int servo_1_val = 0;
int servo_2_val = 0;

void servoInit() {
    // attaches the servo pin
    servo_1.attach(servo_pin_1);
    servo_2.attach(servo_pin_2);
}

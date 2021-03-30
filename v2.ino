#include "motor/motor.cpp"
#include "servo/servo.cpp"
#include "ultrasonic/ultrasonic.cpp"
#include "infrared/infrared.cpp"

void setup() {
    Serial.begin(115200);
    Serial.println("START");
    servoInit();
}

void loop() {
    motor_1.setSpeed(255);
    motor_2.setSpeed(255);
    motor_1.run(FORWARD);
    motor_2.run(FORWARD);
    delay(1); // do not put delay elsewhere
}

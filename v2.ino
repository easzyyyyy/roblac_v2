#include "motor.h"
#include "drive.h"
#include "servo.h"
#include "ultrasonic.h"
#include "infrared.h"

Motor* motor_1;
Motor* motor_2;

void setup()
{
  Serial.begin(115200);
}

void loop()
{
  Serial.println("INIT START");

  // Pass as a parameter the D0 pin
  Infrared i_sensor_1(38);
  Infrared i_sensor_2(39);

  // Pass as a parameter the trigger and echo pin, respectively
  Ultrasonic u_sensor_1(22, 23);
  Ultrasonic u_sensor_2(24, 25);

  // Definition of servos
  Servo servo_1;
  Servo servo_2;
  servo_1.attach(10);
  servo_2.attach(9);

  Serial.println("INIT END");

  Serial.println("CONFIG MOTORS START");
  motor_1 = new Motor(1, 19);
  motor_2 = new Motor(2, 18);
  Serial.println("CONFIG MOTORS END");

  while (true)
  {
    motor_1->run(255);
    motor_2->run(255);

    motor_1->calcSpeed();
    motor_2->calcSpeed();

    delay(1); // do not put delay elsewhere
  }
}
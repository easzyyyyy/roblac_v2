#include "motor.h"

extern Motor* motor_1;
extern Motor* motor_2;

void equal()
{
  int rs1 = motor_1->realSpeed;
  int rs2 = motor_2->realSpeed;

  int es1 = motor_1->expectSpeed;
  int es2 = motor_2->expectSpeed;

  if ((rs1 - rs2) > 0)
  {
    int diff = rs1 - rs2;
    if ((float)rs1 > 0.8*(float)es1)
    {
      es1 = constrain(es1 -= diff, 0, 255);
    }
    else
    {
      es2 = constrain(es2 += diff, 0, 255);
    }
  }
  else if ((rs1 - rs2) < 0)
  {
    int diff = rs2 - rs1;
    if ((float)rs2 > 0.8*(float)es2)
    {
      es2 = constrain(es2 -= diff, 0, 255);
    }
    else
    {
      es1 = constrain(es1 += diff, 0, 255);
    }
  }

  motor_1->run(es1);
  motor_2->run(es2);
}

Motor::Motor(int mNb, int cPin)
{
  motor = new AF_DCMotor(mNb);
  nb = mNb;

  pinMode(cPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(cPin), (mNb == 1 ? motor_1_Update : motor_2_Update), FALLING);
}

void Motor::acc()
{
  unsigned long m = millis();
  int remainingTime = endAcc - m;

  if (remainingTime > 0)
  {
    float diff = expectSpeed - realSpeed;
    float ratio = 1 - ((float)remainingTime / (float)timeAcc);

    motor->setSpeed(ratio * diff + realSpeed);
  }
  else
  {
    motor->setSpeed(expectSpeed);
    accelerating = false;
  }
}

void Motor::run(int speed, float time)
{
  switch (speed)
  {
    case 0:
      motor->run(RELEASE);
      motor->setSpeed(0);
      break;
    case -256:
      motor->run(BRAKE);
      motor->setSpeed(0);
      break;
    default:
      if (speed > 0)
        motor->run(FORWARD);
      else
        motor->run(BACKWARD);

      motor->setSpeed(speed);
      expectSpeed = speed;

      // if (!accelerating)
      // {
      //   expectSpeed = speed;
      //   timeAcc = time*1000;
      //   endAcc = millis() + timeAcc;
      //   accelerating = true;
      // }
  }
}

void Motor::increment()
{
  inc++;
}

void motor_1_Update()
{
  motor_1->increment();
}

void motor_2_Update()
{
  motor_2->increment();
}

void Motor::calcSpeed()
{
  const float ratio = 0.0189074; // distance in cm compared to the number of pulses
  const int time = 100; // time between two calculs of the speed

  if (millis() > nextCalc)
  {
    float cmsSpeed = (ratio*(float)inc) / ((float)time/1000);
    realSpeed = (cmsSpeed + 0.283) / 0.464;
    (realSpeed < 2) ? realSpeed = 0 : realSpeed += 145;

    inc = 0;
    nextCalc = millis() + time;
  }
  equal();
}
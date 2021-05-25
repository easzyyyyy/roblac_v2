#include "drive.h"

extern Motor* motor_1;
extern Motor* motor_2;

void dStraight(int speed)
{
    int rs1 = motor_1->realSpeed;
    int rs2 = motor_2->realSpeed;

    int* es1 = &motor_1->expectSpeed;
    int* es2 = &motor_2->expectSpeed;

    Serial.print("real 1 : ");
    Serial.println(rs1);
    Serial.print("expe 1 : ");
    Serial.println(*es1);
    Serial.print("real 2 : ");
    Serial.println(rs2);
    Serial.print("expe 2 : ");
    Serial.println(*es2);

    if ((rs1 + rs2) == 0)
    {
        motor_1->run(speed, 0.5);
        motor_2->run(speed, 0.5);
        return;
    }

    if ((rs1 - rs2) > 0)
    {
        int diff = rs1 - rs2;
        if (rs1 > speed)
        {
            *es1 = constrain(*es1 -= diff, 0, 255);
        }
        else
        {
            *es2 = constrain(*es2 += diff, 0, 255);
        }
    }
    else if ((rs1 - rs2) < 0)
    {
        int diff = rs2 - rs1;
        if (rs2 > speed)
        {
            *es2 = constrain(*es2 -= diff, 0, 255);
        }
        else
        {
            *es1 = constrain(*es1 += diff, 0, 255);;
        }
    }

    motor_1->run(*es1);
    motor_2->run(*es2);
}
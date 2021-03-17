#include "ultrasonic/ultrasonic.cpp"
#include "infrared/infrared.cpp"

void setup() {
    Serial.begin(115200);
    Serial.println("START");
}

void loop() {
    printDistance(u_sensor_1);
    printColor(i_sensor_1);
    delay(1); // do not put delay elsewhere
}

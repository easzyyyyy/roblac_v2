class Infrared {
    public:
        Infrared(int dPin);
        int read();

    private:
        int pin;
};

Infrared i_sensor_1(38);
Infrared i_sensor_2(39);

// Infrared.read() to get the color value

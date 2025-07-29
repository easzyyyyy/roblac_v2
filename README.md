# RobLac v2

RobLac v2 is an **autonomous Arduino-based robot** designed to participate in **three RoboRAVE competitions**.  
It integrates multiple sensors (infrared, ultrasonic, encoders) and actuators (motors, servos) to perform tasks autonomously and adapt to different challenges.

## Features

- **Autonomous navigation** using infrared and ultrasonic sensors.
- **Motor control** with incremental encoder support for precise movement.
- **Servo management** for articulated components.
- Modular code for easy extension and customization.
- Designed to comply with RoboRAVE competition requirements.

## Example Use Cases

- **Line following** using infrared sensors.
- **Obstacle detection and avoidance** with ultrasonic sensors.
- **Competition-ready routines** for RoboRAVE challenges (e.g., line following, jousting, firefighting).

## Repository Structure

- `v2.ino` – Main Arduino sketch.
- `drive.cpp`, `drive.h` – Drive control implementation.
- `motor.cpp`, `motor.h` – Motor management with encoder support.
- `servo.cpp`, `servo.h` – Servo control.
- `infrared.cpp`, `infrared.h` – Infrared sensor integration.
- `ultrasonic.cpp`, `ultrasonic.h` – Ultrasonic sensor integration.

## Installation & Setup

1. Clone the repository:
    ```bash
    git clone https://github.com/easzyyyyy/roblac_v2.git
    ```
2. Open `v2.ino` in the **Arduino IDE** or **VS Code with PlatformIO**.
3. Install the required Arduino libraries (for motors, sensors, and servos).
4. Upload the code to your Arduino board.

## Usage

1. Assemble the robot with the required sensors and actuators.
2. Upload the code to your Arduino.
3. Configure competition-specific parameters in the code if needed.
4. Deploy the robot to perform RoboRAVE tasks autonomously.

## Roadmap

- Add configurable parameters through a serial interface.
- Improve sensor fusion for more precise navigation.
- Develop separate routines for each RoboRAVE challenge.

## License

This project is distributed under the **MIT License**.

---

**Repository:** [https://github.com/easzyyyyy/roblac_v2](https://github.com/easzyyyyy/roblac_v2)

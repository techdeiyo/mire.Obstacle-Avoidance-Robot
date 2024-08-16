# Ultrasonic Obstacle Avoidance Robot

This Arduino-based project uses an ultrasonic sensor and a servo motor to create a simple obstacle-avoidance robot. The robot moves forward when there's no obstacle in front of it, and when it detects an obstacle within a certain range, it stops, scans the area, and changes its direction to avoid the obstacle.

## Features

- **Obstacle Detection**: Uses an HC-SR04 ultrasonic sensor to detect obstacles in front of the robot.
- **Servo Motor Scanning**: The servo motor scans the environment by rotating left and right to determine the best path to avoid obstacles.
- **Movement Control**: The robot can move forward, backward, and turn left based on the sensor readings.

## Components Required

- Arduino (e.g., Uno, Nano)
- HC-SR04 Ultrasonic Sensor
- L298N Motor Driver
- DC Motors (x2)
- Servo Motor (e.g., SG90)
- Power Supply (for motors and Arduino)
- Chassis with wheels (for building the robot)
- Jumper wires

## Pin Connections

### Ultrasonic Sensor (HC-SR04):
- **Trig Pin**: Pin 9
- **Echo Pin**: Pin 8

### Servo Motor:
- **Control Pin**: Pin 10

### Motor A (Left Motor):
- **`leftMotorA`**: Pin 4
- **`leftMotorB`**: Pin 5

### Motor B (Right Motor):
- **`rightMotorA`**: Pin 6
- **`rightMotorB`**: Pin 7

## Code Overview

- **`setup()`**: Initializes the pins and starts serial communication.
- **`loop()`**: Continuously checks the distance to an obstacle and decides the robot's movement (move forward, stop, scan, move backward, turn left).
- **`getDistance()`**: Measures the distance using the ultrasonic sensor.
- **`moveForward()`**: Moves the robot forward.
- **`moveBackward()`**: Moves the robot backward.
- **`turnLeft()`**: Turns the robot to the left.
- **`stopMovement()`**: Stops the robot's movement.
- **`scanAndAvoidObstacle()`**: Uses the servo motor to scan the area and find a clear path.

## Installation

1. **Clone the repository**:
   ```bash
   git clone https://github.com/techdeiyo/obstacle-avoidance-robot.git
   cd obstacle-avoidance-robot
   ```

2. **Upload the code to your Arduino**:
   - Open the `obstacle_avoidance_robot.ino` file in the Arduino IDE.
   - Select your Arduino board and the correct COM port.
   - Upload the sketch.

3. **Connect the components** as per the pin connections mentioned above.

## Usage

1. Power on the robot.
2. The robot will move forward until it detects an obstacle.
3. Upon detecting an obstacle, it will stop, scan the surroundings using the servo motor, and then attempt to avoid the obstacle by moving backward and turning left.

## Customization

- **Adjusting Distance Thresholds**: Modify the distance values in the `loop()` function to change when the robot starts avoiding obstacles.
- **Tuning Servo Scan Time**: Adjust the `delay()` values in the `scanAndAvoidObstacle()` function to change the time spent scanning.

## License

This project is open-source and licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

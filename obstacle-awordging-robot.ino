#include <Servo.h>  // Include the Servo library to control the servo motor

// Create a Servo object to control the servo motor
Servo Myservo;

// Define pin numbers for ultrasonic sensor and motor control
#define trigPin 9           // Trig Pin of HC-SR04 (Ultrasonic sensor)
#define echoPin 8           // Echo Pin of HC-SR04 (Ultrasonic sensor)
#define leftMotorA 4        // Left motor 1st pin
#define leftMotorB 5        // Left motor 2nd pin
#define rightMotorA 6       // Right motor 1st pin
#define rightMotorB 7       // Right motor 2nd pin

// Variables to store the duration of the ultrasonic pulse and the calculated distance
long duration, distance;

void setup() {
  // Initialize serial communication at 9600 bits per second
  Serial.begin(9600);
  
  // Set motor control pins as output
  pinMode(leftMotorA, OUTPUT);     
  pinMode(leftMotorB, OUTPUT);
  pinMode(rightMotorA, OUTPUT);
  pinMode(rightMotorB, OUTPUT);
  
  // Set the Trig pin as output to transmit ultrasonic waves
  pinMode(trigPin, OUTPUT); 
  // Set the Echo pin as input to receive the reflected ultrasonic waves
  pinMode(echoPin, INPUT);  
  
  // Attach the servo motor to pin 10
  Myservo.attach(10);
}

void loop() {
  // Get the distance from an obstacle
  distance = getDistance();
  
  // Print the distance to the Serial Monitor for debugging purposes
  Serial.println(distance);
  
  // If the distance is greater than 15 cm, move forward
  if (distance > 15) {               
    moveForward();
  } 
  // If the distance is less than 10 cm, stop and avoid the obstacle
  else if (distance > 0 && distance < 10) { 
    stopMovement();           // Stop the robot
    scanAndAvoidObstacle();   // Scan and avoid the obstacle using the servo motor
    moveBackward();           // Move backward to create space
    stopMovement();           // Stop again
    turnLeft();               // Turn left to change direction
  }
  
  delay(10);  // Small delay to prevent excessive loop iteration
}

// Function to measure distance using the ultrasonic sensor
long getDistance() {
  // Send a short LOW pulse to ensure a clean HIGH pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);   
  
  // Send a HIGH pulse for 10 microseconds to trigger the sensor
  digitalWrite(trigPin, HIGH);       
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Measure the duration of the incoming pulse on the Echo pin
  duration = pulseIn(echoPin, HIGH); 
  
  // Convert the time (duration) to distance (in cm) and return it
  return duration / 58.2;            
}

// Function to move the robot forward
void moveForward() {
  Myservo.write(90);  // Keep the servo motor centered (for scanning)
  
  // Set motor pins to move the robot forward
  digitalWrite(rightMotorB, HIGH);       
  digitalWrite(rightMotorA, LOW);
  digitalWrite(leftMotorB, HIGH);                                
  digitalWrite(leftMotorA, LOW);
}

// Function to move the robot backward
void moveBackward() {
  // Set motor pins to move the robot backward
  digitalWrite(rightMotorB, LOW);             
  digitalWrite(rightMotorA, HIGH);
  digitalWrite(leftMotorB, LOW);                                
  digitalWrite(leftMotorA, HIGH);
  
  delay(500);  // Move backward for 500 milliseconds
}

// Function to turn the robot to the left
void turnLeft() {
  // Set motor pins to turn the robot left
  digitalWrite(rightMotorB, HIGH);       
  digitalWrite(rightMotorA, LOW);   
  digitalWrite(leftMotorA, LOW);                                 
  digitalWrite(leftMotorB, LOW);  
  
  delay(500);  // Turn left for 500 milliseconds
}

// Function to stop all motor movement
void stopMovement() {
  // Set motor pins to stop the robot
  digitalWrite(rightMotorB, LOW);        
  digitalWrite(rightMotorA, LOW);
  digitalWrite(leftMotorB, LOW);                                
  digitalWrite(leftMotorA, LOW);
  
  delay(100);  // Pause for 100 milliseconds to ensure a complete stop
}

// Function to scan for obstacles and avoid them using the servo motor
void scanAndAvoidObstacle() {
  Myservo.write(0);   // Rotate the servo to the leftmost position
  delay(500);         // Wait for 500 milliseconds
  
  Myservo.write(180); // Rotate the servo to the rightmost position
  delay(500);         // Wait for 500 milliseconds
  
  Myservo.write(90);  // Return the servo to the center position
  delay(500);         // Wait for 500 milliseconds
}

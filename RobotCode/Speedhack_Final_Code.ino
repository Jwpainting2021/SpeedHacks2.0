
// Servo
#include <Servo.h>
#define s_seed 5
//#define s_water 6 SCRAPPED WATER
Servo s_servo;
//Servo w_servo; SCRAPPED WATER
int s_angle = 0;
//int w_angle = 0; SCRAPPED WATER

// Ultrasonic Sensor Pins
const int trigPin = 11;
const int echoPin = 12;

// L298N Motor Driver Variables, motor1 is the OUT1&2 and motor2 is the OUT3&4
#define speedm1 3 
#define m1p1 4 // motor 1 pin 1
#define m1p2 5
#define m2p2 8
#define m2p1 9
#define speedm2 10
#define mspeed 255

// Photocell & RGB
#define photopin A1
#define yellow 7
#define green 13

long duration;
int distance;
int lightlevel;

void setup() {
  // Sensor
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // Motors
  pinMode(m1p1, OUTPUT);
  pinMode(m1p2, OUTPUT);
  pinMode(m2p1, OUTPUT);
  pinMode(m2p2, OUTPUT);

  // Random seed for left/right
  randomSeed(analogRead(A0));

  // Servo motor
  s_servo.attach(s_seed);
  //w_servo.attach(s_water); SCRAPPED WATER

  // Photocell & RGB
  pinMode(photopin, INPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);

  //Serial.begin(9600);

  delay(10000); // have it delay when we start the robot up
}

void loop() {
  // Get distance
  distance = getDistance();
  //Serial.print("Distance: ");
  //Serial.println(distance);
  lightlevel = analogRead(photopin);


  // distance check
  if (distance < 50) {

    stopMotors();
    turnRight();

  } else { 
    moveForward();
  }

  // Photoresistor Activation

  if (lightlevel > 900) {
    digitalWrite(green, HIGH);
    digitalWrite(yellow,LOW);
    stopMotors();
    //open
    s_servo.write(45);
    //w_servo.write(45); SCRAPPED WATER

    delay(200);
    
    //close
    s_servo.write(0);
    //w_servo.write(0); SCRAPPED WATER

    moveForward();

  }
  else{
    digitalWrite(yellow, HIGH);
    digitalWrite(green, LOW);
    moveForward();
  }
  delay(100); // Small delay to reduce false triggers
}

int getDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  return duration * 0.034 / 2;
}
void moveForward() {
  digitalWrite(m1p1, HIGH);
  digitalWrite(m1p2, LOW);
  digitalWrite(m2p1, HIGH);
  digitalWrite(m2p2, LOW);

  digitalWrite(speedm1, mspeed);
  digitalWrite(speedm2, mspeed);
}
void moveForward_slow() {
  digitalWrite(m1p1, HIGH);
  digitalWrite(m1p2, LOW);
  digitalWrite(m2p1, HIGH);
  digitalWrite(m2p2, LOW);

  digitalWrite(speedm1, 50);
  digitalWrite(speedm2, 50);
}
void stopMotors() {
  digitalWrite(speedm1, 0);
  digitalWrite(speedm2, 0);
  delay(100);
}
void avoidObstacle() {
  stopMotors();
  delay(200);

  int direction = random(0, 2); // 0 = left, 1 = right
  if (direction == 0) {
    turnLeft();
  } else {
    turnRight();
  }

  delay(500); // Turn time
  stopMotors();
  delay(200);
}
void turnLeft() {
  digitalWrite(m1p1, HIGH);
  digitalWrite(m1p2, LOW);
  digitalWrite(m2p1, HIGH);
  digitalWrite(m2p2, LOW);

  digitalWrite(speedm1, mspeed);
  digitalWrite(speedm2, 0);
}
void turnRight() {
  digitalWrite(m1p1, HIGH);
  digitalWrite(m1p2, LOW);
  digitalWrite(m2p1, HIGH);
  digitalWrite(m2p2, LOW);

  digitalWrite(speedm1, 0);
  digitalWrite(speedm2, mspeed);

  delay(1000);

}
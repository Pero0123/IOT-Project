#include <ESP32Servo360.h>

//pins for front ultrasonic
#define frontTrig 33
#define frontEcho 34

//pins for side ultrasonic
#define sideTrig 25
#define sideEcho 26

//pins for servo
#define continuesServo 27

//motor pins
#define RightMotorEnable 20
#define RightMotorDir 21

#define LeftMotorEnable 22
#define LeftMotorDir 23

#define UltrasonicOffset 40//physical offset of the ultrasonic in mm

float distanceFront, distanceSide;
int coords[2];

void setup() {
  Serial.begin(115200);

//sets pinmodes for all ultrasonic pins
  pinMode(frontTrig, OUTPUT);
  pinMode(sideTrig, OUTPUT);
  pinMode(frontEcho, INPUT);
  pinMode(sideEcho, INPUT);

}
void loop() {

  getDistance(0);
  getDistance(1);
  
}

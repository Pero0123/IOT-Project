#include<Servo.h>

//pins for front ultrasonic
#define frontTrig 33
#define frontEcho 34
 
//pins for side ultrasonic
#define sideTrig 25
#define sideEcho 26
 
//pins for servo
#define continuesServo 27

 
//motor pins
#define RightMotorEnable 18
#define RightMotorDir 19
#define LeftMotorEnable 16
#define LeftMotorDir 15
 
#define UltrasonicOffset 40//physical offset of the ultrasonic in mm
 
float distanceFront, distanceSide;
int coords[2];
 
Servo Servo1;

void setup() {
  Serial.begin(115200);
//sets pinmodes for all ultrasonic pins
  pinMode(frontTrig, OUTPUT);
  pinMode(sideTrig, OUTPUT);
  pinMode(frontEcho, INPUT);
  pinMode(sideEcho, INPUT);

  pinMode(LeftMotorEnable, OUTPUT);
  pinMode(RightMotorEnable, OUTPUT);
  pinMode(RightMotorDir, OUTPUT);
  pinMode(LeftMotorDir, OUTPUT);

//create servo object for continues servo
  Servo1.attach(continuesServo);
}
void loop() {



  turnWithReverse(0, -200);
  delay(10);




  /*
  getDistance(0);
  getDistance(1);
  forwards(130);
  delay(1000);
  reverse(130);
  delay(1000);
  stop();
  delay(1000);
  Turn(255,0);
  delay(1000);
  Turn(0,255);
  delay(1000);
  */
  //Servo1.write(90);
  //delay(1000);
  //Servo1.write(92);
  //delay(1000);
 // Servo1.write(0);
 // delay(1000);
 
}
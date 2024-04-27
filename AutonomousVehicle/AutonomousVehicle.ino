#include<Servo.h>
#include <BluetoothSerial.h>
#include <Wire.h>
#include <QMC5883L.h>

//pins for front ultrasonic
#define Trig 32
#define Echo 34
 
//motor pins
#define RightMotorEnable 26
#define RightMotorDir 25
#define LeftMotorEnable 33
#define LeftMotorDir 32


int vehicleHeading = 999;//stores vehicle heading from compass
int targetHeading = 140;//the heading the vehicle should drive towards
int maxHeading, minHeading;
int headingRange = 12;

//bluetooth stuff here
char BTmessage;

//sensor objects
Servo UltrasonicServo;
BluetoothSerial SerialBT;
QMC5883L compass;

void setup() {
  Serial.begin(115200);
  //bluetoothSetup();//setup code for bluetooth
  compassSetup();

  //motor pins setup
  pinMode(RightMotorDir,OUTPUT);
  pinMode(RightMotorEnable,OUTPUT);
  pinMode(LeftMotorDir,OUTPUT);
  pinMode(LeftMotorEnable,OUTPUT);
}

void loop() {
 
  // //Vehicle driving towards a set heading
  // vehicleHeading = getHeading();
  // configureVehicleHeading();
  // driveTowardHeading();
  // delay(50);
 
}
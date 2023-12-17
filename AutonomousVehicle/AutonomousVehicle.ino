#include<Servo.h>
#include <BluetoothSerial.h>
#include <QMC5883L.h>
#include <Wire.h>
#include "DFRobot_BMM150.h"

//pins for front ultrasonic
#define frontTrig 32
#define frontEcho 34
 
//pins for side ultrasonic
#define sideTrig 33
#define sideEcho 35
 
//motor pins
#define RightMotorEnable 18
#define RightMotorDir 19
#define LeftMotorEnable 16
#define LeftMotorDir 15

//pins for servo
#define continuesServo 27
 
//physical offset of the ultrasonic in mm
#define UltrasonicOffsetSide 40
#define UltrasonicOffsetFront 40
 
// variables to store distance from ultrasonics
float distanceFront, distanceSide;
float coords[2] = {1,1};//stores co-ordinates of the vehicle
int vehicleHeading = 999;//stores vehicle heading from compass1
int platformHeading = 999;//stores ultrasonic heading from compass2
int targetHeading = 140;//the heading the vehicle should drive towards
int maxHeading, minHeading;
int headingRange = 12;

int targetPlatformHeading = 80;//the heading the ultrasonic platform should point towards
int maxPlatformHeading, minPlatformHeading;
int headingRangePlatform = 4;

//bmm150 compass definitions
DFRobot_BMM150_I2C bmm150(&Wire, I2C_ADDRESS_4);

//creates objects for sensors
Servo Servo1;
BluetoothSerial SerialBT;
QMC5883L compass1;

void setup() {
  Serial.begin(115200);
  bluetoothSetup();//setup code for bluetooth
  ultrasonicSetup();//setup code for the ultrasonic sensor on the tracking platform
  Servo1.attach(continuesServo);//create servo object for continues servo
  compassSetup();
  //bmm155Setup();//setup code for the bmm150 compass module
}

void loop() {
  //bluetoothControlRead();//code for bluetooth control
  platformHeading = getCompassHeading();
  //platformHeading = bmm150.getCompassDegree();
  correctPlatformHeading();
  printCoordsToBluetooth();
  //delay(100);
}
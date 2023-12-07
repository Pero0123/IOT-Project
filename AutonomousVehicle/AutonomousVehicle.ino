#include<Servo.h>
#include "BluetoothSerial.h"
#include <QMC5883L.h>
#include <Wire.h>

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

#define UltrasonicOffsetSide 40//physical offset of the ultrasonic in mm#
#define UltrasonicOffsetFront
 
// variables to store distance from ultrasonics
float distanceFront, distanceSide;
int coords[2];//stores co-ordinates of the vehicle
int vehicleHeading;//stores vehicle heading from compass1
int trackerHeading;//stores ultrasonic heading from compass2
int targetHeading = 5;//the heading the vehicle should drive towards
int maxHeading, minHeading;

Servo Servo1;
BluetoothSerial SerialBT;
QMC5883L compass;

void setup() {
  Serial.begin(115200);
  compassSetup();//setup code for compass
  bluetoothSetup();//setup code for bluetooth

//sets pinmodes for all ultrasonic pins
  pinMode(frontTrig, OUTPUT);
  pinMode(sideTrig, OUTPUT);
  pinMode(frontEcho, INPUT);
  pinMode(sideEcho, INPUT);
//pinmodes for hbrdige motor controller
  pinMode(LeftMotorEnable, OUTPUT);
  pinMode(RightMotorEnable, OUTPUT);
  pinMode(RightMotorDir, OUTPUT);
  pinMode(LeftMotorDir, OUTPUT);

//create servo object for continues servo
  Servo1.attach(continuesServo);
}
void loop() {
  //bluetoothControlRead();//code for bluetooth control
  vehicleHeading = getCompassHeading();//reads heading from compass
  //correctPlatformHeading();
  //Servo1.write(90);
  bluetoothHeadingControl();

  //sets min and max heading
  //takes into account that heading is continues from 0-360
  if((targetHeading-10)<0)
  {
    maxHeading=(targetHeading-10)+360;
    minHeading=targetHeading+10;
  }
  else if((targetHeading+10)>360)
  {
    minHeading=(targetHeading+10)-360;
    maxHeading=targetHeading-10;
  }
  else
  {
    minHeading=targetHeading-10;
    maxHeading=targetHeading+10;
  }



  if (vehicleHeading<maxHeading && vehicleHeading>minHeading)
  {
     turnWithReverse(190, 180);
  }
  else if (vehicleHeading>targetHeading)
  {
  turnWithReverse(-150,150);
  }
   else if (vehicleHeading<targetHeading)
  {
  turnWithReverse(150,-150);
  }

  delay(5);
}
#include <Servo.h>
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
#define headingRange 12


uint8_t vehicleHeading = 20;//stores vehicle heading from compass// initiates to 20 just to avoid anything weired happening druing callibration
uint8_t targetHeading = 140;//the heading the vehicle should drive towards
uint8_t maxHeading, minHeading;

//bluetooth stuff here
char BTmessage;

//sensor objects
//Servo UltrasonicServo;
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
targetHeading = 270;
vehicleHeading = getHeading();
configureVehicleHeading();//sets up min and max heading before vehcile tries to correct
driveTowardHeading();//vehicle attempts to face in the specified heading in targetHeading
delay(10);

}
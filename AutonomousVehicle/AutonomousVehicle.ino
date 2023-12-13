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

//bmm150 compass definitions
DFRobot_BMM150_I2C bmm150(&Wire, I2C_ADDRESS_4);

/*can probalby delete all this but ill have to test it so im not bothered to do it now
//When using SPI communication, use the following program to construct an object by DFRobot_BMM150_SPI
#if defined(ESP32) || defined(ESP8266)
  #define BMM150_CS D3
#elif defined(__AVR__) || defined(ARDUINO_SAM_ZERO)
  #define BMM150_CS 3
#elif (defined NRF5)
  #define BMM150_CS 2  //The corresponding silkscreen on the development board is the pin P2
#endif
*/

//creates objects for sensors
Servo Servo1;
BluetoothSerial SerialBT;
QMC5883L compass1;

void setup() {
  Serial.begin(115200);
  bluetoothSetup();//setup code for bluetooth
  ultrasonicSetup();//setup code for the ultrasonic sensor on the tracking platform
  Servo1.attach(continuesServo);//create servo object for continues servo
  //compassSetup();
  //bmm155Setup();//setup code for the bmm150 compass module
}

void loop() {
 // bluetoothControlRead();//code for bluetooth control
  //platformHeading = getCompassHeading();//reads heading from compass
  //correctPlatformHeading();
  //vehicleHeading = bmm150.getCompassDegree();
  //getCoords();
  printCoordsToBluetooth();
  delay(100);
}
#include<Servo.h>
#include "BluetoothSerial.h"

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
 
float distanceFront, distanceSide;
int coords[2];

float vehicleHeading, ultrasonicsHeading;
 
Servo Servo1;

//BLUETOOTH STUFF
String device_name = "PeroS21";//bluetooth name of the esp32
//defintions for bluetooth setup
#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

#if !defined(CONFIG_BT_SPP_ENABLED)
#error Serial Bluetooth not available or not enabled. It is only available for the ESP32 chip.
#endif

BluetoothSerial SerialBT;


void setup() {
  Serial.begin(115200);

//bluetooth setup code
  SerialBT.begin(device_name); //Bluetooth device name
  Serial.printf("The device with name \"%s\" is started.\nNow you can pair it with Bluetooth!\n", device_name.c_str());
  //Serial.printf("The device with name \"%s\" and MAC address %s is started.\nNow you can pair it with Bluetooth!\n", device_name.c_str(), SerialBT.getMacString()); // Use this after the MAC method is implemented
  #ifdef USE_PIN
    SerialBT.setPin(pin);
    Serial.println("Using PIN");
  #endif

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
  //reads and sends information between bluetooth app and serial console
  if (Serial.available()) {
    SerialBT.write(Serial.read());
  }
  if (SerialBT.available()) {
    Serial.write(SerialBT.read());
  }
  delay(100);




}
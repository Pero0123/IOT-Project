// This code is derived from the HelloServer Example
// in the (ESP32) WebServer library .
//
// It hosts a webpage which has one temperature reading to display.
// The webpage is always the same apart from the reading which would change.
// The getTemp() function simulates getting a temperature reading.
// homePage.h contains 2 constant string literals which is the two parts of the
// webpage that never change.
// handleRoot() builds up the webpage by adding as a C++ String:
// homePagePart1 + getTemp() +homePagePart2
// It then serves the webpage with the command:
// server.send(200, "text/html", message);
// Note the text is served as html.
//
// Replace the code in the homepage.h file with your own website HTML code.
//
// This example requires only an ESP32 and download cable. No other hardware is reuired.
// A wifi SSID and password is required.
// Written by: Natasha Rohan  12/3/23

#include <WiFi.h>
#include <WiFiClient.h>
#include <WebServer.h>
#include <ESPmDNS.h>
#include "homepage.h"
#include <Servo.h>
#include <BluetoothSerial.h>
#include <Wire.h>
#include <QMC5883L.h>
#include <DFRobot_DHT11.h>

//dht variables and pins
#define DHT11_PIN 15
int temperature;
int humidity;

//switch pin
#define sw 34

int vehicleHeading = 140;  //stores vehicle heading from compass//
int targetHeading = 140;   //the heading the vehicle should drive towards
int maxHeading, minHeading;
int operationMode = 4;  //0:Manual, 1:Autonomous, 2:Drive to Heading

unsigned long startMillis;
unsigned long currentMillis;
const unsigned long period = 50;  //the value is a number of milliseconds, ie 1 second

/////Ultrasonic pins and variables/////
//right sensor
#define Trig1 12
#define Echo1 25
//front sensor
#define Trig2 13
#define Echo2 26
//left sensor
#define Trig3 14
#define Echo3 27
// ultrasonic distance variable
float frontDistance;
float rightDistance;
float leftDistance;

bool obstacleFront = false;
bool obstacleLeft = false;
bool obstacleRight = false;
#define collisionDistance 25
#define headingRange 14

//website collision indicators//
String CollisionLeft = "Green";
String CollisionCenter = "Red";
String CollisionRight = "Green";
String vehicleMode = "Select Mode";

//bluetooth stuff here
char BTmessage;

//Sensor objects
BluetoothSerial SerialBT;
QMC5883L compass;
DFRobot_DHT11 DHT;
Servo servoRight;
Servo servoLeft;

const char* ssid = "Pero";
const char* password = "pero1234";

WebServer server(80);

void handleKeyPress() {
  String receivedData = server.arg("button");
  operationMode = receivedData.toInt();
  switch (operationMode) {
    case 0:
      vehicleMode = "Bluetooth";
      break;
    case 1:
      vehicleMode = "Autonomous";
      break;
    case 2:
      vehicleMode = "Drive Toward Heading";
      break;
    default:
      vehicleMode = "Select Mode";
      break;
  }

  //Serial.println(receivedData);
  server.send(200);
}
void handleHeading() {
  String receivedHeading = server.arg("heading");
  if (operationMode == 2) {
    targetHeading = receivedHeading.toInt();
    configureVehicleHeading();
  }
  server.send(200);
}

void handleRoot() {
  String message =
    homePagePart1 + vehicleHeading + homePagePart2 + temperature + homePagePart3 + humidity + homePagePart4 + vehicleMode + homePagePart5 + CollisionLeft + homePagePart6 + CollisionCenter + homePagePart7 + CollisionRight + homePagePart8;
  server.send(200, "text/html", message);
}

void handleNotFound() {
  String message = "File Not Found\n\n";
  message += "URI: ";
  message += server.uri();
  message += "\nMethod: ";
  message += (server.method() == HTTP_GET) ? "GET" : "POST";
  message += "\nArguments: ";
  message += server.args();
  message += "\n";
  for (uint8_t i = 0; i < server.args(); i++) {
    message += " " + server.argName(i) + ": " + server.arg(i) + "\n";
  }
  server.send(404, "text/plain", message);
}

void setup(void) {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.println("");

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  if (MDNS.begin("esp32")) {
    Serial.println("MDNS responder started");
  }

  server.on("/", handleRoot);
  server.on("/sentKeyPressToWebServer", handleKeyPress);
  server.on("/sentHeadingToWebServer", handleHeading);
  server.on("/inline", []() {
    server.send(200, "text/plain", "this works as well");
  });
  server.onNotFound(handleNotFound);
  server.begin();
  Serial.println("HTTP server started");

  bluetoothSetup();

  //Compass setup Code//
  Wire.begin();
  compass.init();
  compass.setSamplingRate(200);
  Serial.println("QMC5883L Compass Demo");
  Serial.println("Turn compass in all directions to calibrate....");

  //Servo Setup Code//
  servoLeft.attach(2);
  servoRight.attach(4);

  startMillis = millis();  //initial start time for millis timing

  //Configure the pins for ultrasonic sensors
  pinMode(Echo1, INPUT);
  pinMode(Echo2, INPUT);
  pinMode(Echo3, INPUT);
  pinMode(Trig1, OUTPUT);
  pinMode(Trig2, OUTPUT);
  pinMode(Trig3, OUTPUT);

  //switch setup//
  pinMode(sw, INPUT);

  delay(3000);  //delay to allow user to switch on vheicle safely

//stop the servos
  servoRight.write(90);
  servoLeft.write(90);
  
  Serial.print("Pleas connect to the webserver at ");
  Serial.print(WiFi.localIP());
  Serial.print(" to access the Dashboard");
  Serial.println("");
  delay(100);
}

void loop(void) {
  currentMillis = millis();  //current time passed since start in milliseconds
  if (currentMillis - startMillis >= period) {  //check if the period has elapsed
  server.handleClient();
  startMillis = currentMillis;
  delay(1);  //allow the cpu to switch to other tasks
  }
  checkForObstacles();
  vehicleHeading = compass.readHeading();
  //check if bluetooth switch is on. switch to bluetooth mode if it is
  if (digitalRead(sw) == HIGH) {
    operationMode = 0;
  }

  
    //check which mode the vehicle should run in
    switch (operationMode) {
      case 0:  //Bluetooth Mode
        Serial.println("Bluetooth Mode");
        stopForObstacle();
        configureVehicleHeading();
        bluetoothControl();
        break;
      case 1:                      //Autonomous Mode
        Serial.println("Autonomous mode");
        Serial.println(vehicleHeading);
        driveTowardHeading();
          if (obstacleFront || obstacleRight || obstacleLeft) {
          servoRight.write(0);
          servoLeft.write(180);
          delay(1500);
          servoRight.write(90);
          servoLeft.write(90);
          //pick a new direction
          int newHeading;
          if (obstacleLeft == false) {
            newHeading = targetHeading - 100;
          } 
          else if (obstacleRight == false) {
            newHeading = targetHeading + 100;
          } 
          else {
            newHeading = targetHeading + 180;
          }

          //correct heading to be between 0 and 360
          if (newHeading > 360) {
            newHeading = newHeading - 360;
          } 
          else if (newHeading < 0) {
            newHeading = newHeading + 360;
          }
          targetHeading = newHeading;
        }
        break;

      case 2:  //Drive towards heading Mode
        driveTowardHeading();
        stopForObstacle();
        break;

      default:
        server.handleClient();
        Serial.print("Pleas connect to the webserver at ");
        Serial.print(WiFi.localIP());
        Serial.print(" to access the Dashboard");
        Serial.println("");
        delay(100);
        servoRight.write(90);
        servoLeft.write(90);
        Serial.println("defualt mode");
        break;
    }
 
    //update temperature and humidity
    DHT.read(DHT11_PIN);
    temperature = DHT.temperature;
    humidity = DHT.humidity;
//    Serial.println("mode =");
//    Serial.print(operationMode);
//    Serial.println("targetHeading =");
//    Serial.print(targetHeading);
//    Serial.println("vehicleHeading =");
//    Serial.print(vehicleHeading);
    delay(5);
  
}

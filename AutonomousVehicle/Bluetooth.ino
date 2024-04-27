
void bluetoothSetup()
{
String device_name = "PeroS21";//bluetooth name of the esp32
//defintions for bluetooth setup
#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

#if !defined(CONFIG_BT_SPP_ENABLED)
#error Serial Bluetooth not available or not enabled. It is only available for the ESP32 chip.
#endif

//bluetooth setup code
  SerialBT.begin(device_name); //Bluetooth device name
  Serial.printf("The device with name \"%s\" is started.\nNow you can pair it with Bluetooth!\n", device_name.c_str());
  //Serial.printf("The device with name \"%s\" and MAC address %s is started.\nNow you can pair it with Bluetooth!\n", device_name.c_str(), SerialBT.getMacString()); // Use this after the MAC method is implemented
  #ifdef USE_PIN
    SerialBT.setPin(pin);
    Serial.println("Using PIN");
  #endif
}

void bluetoothControlRead()
{
    char message;
  //reads and sends information between bluetooth app and serial console
  if (SerialBT.available()) {
    message=SerialBT.read();
  }

  switch(message)
  {
      case 'w':
      drive(200, 200);//go forwards
    break;

        case 's':
        drive(-200, -200);//reverse obvisoulsy
    break;

        case 'a':
        drive(-150, 150);//turn left
    break;

        case 'd':
        drive(150, -150);//turn right
    break;

        case 'g':
        drive(1,1);//stop.
    break;
  }
}

void bluetoothHeadingControl()
{
    char message;
  //reads and sends information between bluetooth app and serial console
  if (SerialBT.available()) {
    message=SerialBT.read();
  }

  switch(message)
  {
      case 'w':
      targetHeading = 0;
    break;

        case 's':
        targetHeading = 90;
    break;

        case 'a':
        targetHeading = 180;
    break;

        case 'd':
        targetHeading = 270;
    break;

        case 'g':
        drive(1,1);//stop.
    break;
  }
  configureVehicleHeading();
  driveTowardHeading();
}

  

// void printCoordsToBluetooth()
// {
//  char temp[170];
//  sprintf(temp, "Vehicle is at (%.1f,%.1f)\nVehicle Heading: %d\nPlatform Heading: %d\nMax Heading: %d\nMin Heading: %d\n%c\n------------------------------------------------\n\n",coords[0],coords[1],vehicleHeading,platformHeading,maxHeading,minHeading,BTmessage);
//  SerialBT.println(temp);
//  Serial.println(temp);
// }

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
      turnWithReverse(200, 200);//go forwards
    break;

        case 's':
        turnWithReverse(200, 200);//reverse obvisoulsy
    break;

        case 'a':
        turnWithReverse(-150, 150);//turn left
    break;

        case 'd':
        turnWithReverse(150, -150);//turn right
    break;

        case 'g':
        forwards(1);//stop. actual stop function needs to be fixed
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
      targetHeading=0;
    break;

        case 's':
        targetHeading=90;
    break;

        case 'a':
        targetHeading=180;
    break;

        case 'd':
        targetHeading=270;
    break;

        case 'g':
        forwards(1);//stop. actual stop function needs to be fixed
    break;
  }
}
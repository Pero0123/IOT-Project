
void bluetoothSetup() {
  String device_name = "AutonomousVehicle";  //bluetooth name of the esp32
  //defintions for bluetooth setup
#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

#if !defined(CONFIG_BT_SPP_ENABLED)
#error Serial Bluetooth not available or not enabled. It is only available for the ESP32 chip.
#endif

  //bluetooth setup code
  SerialBT.begin(device_name);  //Bluetooth device name
  Serial.printf("The device with name \"%s\" is started.\nNow you can pair it with Bluetooth!\n", device_name.c_str());
  //Serial.printf("The device with name \"%s\" and MAC address %s is started.\nNow you can pair it with Bluetooth!\n", device_name.c_str(), SerialBT.getMacString()); // Use this after the MAC method is implemented
#ifdef USE_PIN
  SerialBT.setPin(pin);
  Serial.println("Using PIN");
#endif
}

void bluetoothControl() {
  char message;
  //reads and sends information between bluetooth app and serial console
  if (SerialBT.available()) {
    message = SerialBT.read();
  }

  switch (message) {
    case 'w':
    servoRight.write(180);
    servoLeft.write(0);  //go forwards
      break;

    case 's':
    servoRight.write(0);
    servoLeft.write(180);  //reverse obvisoulsy
      break;

    case 'a':
    servoRight.write(45);
    servoLeft.write(45);  //turn left
      break;

    case 'd':
    servoRight.write(135);
    servoLeft.write(135);  //turn right
      break;

    case 'g':
    servoRight.write(90);
    servoLeft.write(90);  //stop.
      break;
  }
}

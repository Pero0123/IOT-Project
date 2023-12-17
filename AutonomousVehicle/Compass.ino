
void compassSetup()
{
  Wire.begin();
	compass1.init();
	compass1.setSamplingRate(120);
	Serial.begin(115200);
	Serial.println("QMC5883L Compass Demo");
	Serial.println("Turn compass in all directions to calibrate....");
}

void bmm155Setup()
{
  //bmm150 compass setup code

  while(!Serial);
  while(bmm150.begin()){
    Serial.println("bmm150 init failed, Please try again!");
    delay(1000);
  } Serial.println("bmm150 init success!");
  bmm150.setOperationMode(BMM150_POWERMODE_NORMAL);
  bmm150.setPresetMode(BMM150_PRESETMODE_HIGHACCURACY);
  bmm150.setRate(BMM150_DATA_RATE_20HZ);
  bmm150.setMeasurementXYZ();
}


//gets heading from the gy-271 compass module
int getCompassHeading()
{
	int heading = compass1.readHeading();
	if(heading==0) {
		/* Still calibrating, so measure but don't print */
	} else {
		Serial.println(heading);
	}
  return heading;
}
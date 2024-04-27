/*
void compassSetup()
{
  Wire.begin();
	compass1.init();
	compass1.setSamplingRate(120);
	Serial.begin(115200);
	Serial.println("QMC5883L Compass Demo");
	Serial.println("Turn compass in all directions to calibrate....");
}
*/
void qmcSetup()
{
  while (!compass.begin())
  {
    Serial.println("Could not find a valid 5883 sensor, check wiring!");
    delay(500);
  }
  if(compass.isQMC())
  {
    Serial.println("Initialize QMC5883");
    // compass.setRange(QMC5883_RANGE_2GA);
    // Serial.print("compass range is:");
    // Serial.println(compass.getRange());

     compass.setMeasurementMode(QMC5883_CONTINOUS);
     Serial.print("compass measurement mode is:");
     Serial.println(compass.getMeasurementMode());

    compass.setDataRate(QMC5883_DATARATE_50HZ);
    Serial.print("compass data rate is:");
    Serial.println(compass.getDataRate());

    compass.setSamples(QMC5883_SAMPLES_8);
    Serial.print("compass samples is:");
    Serial.println(compass.getSamples());
  }
  delay(1000);
}


float getDFCompasData()
{
  float declinationAngle = (4.0 + (26.0 / 60.0)) / (180 / PI);
  compass.setDeclinationAngle(declinationAngle);
  sVector_t mag = compass.readRaw();
  compass.getHeadingDegrees();
  Serial.print("Degress = ");
  Serial.println(mag.HeadingDegress);
  return mag.HeadingDegress;
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

/*
//gets heading from the gy-271 compass module
int getCompassHeading()
{
	int heading = compass1.readHeading();
	if(heading==0) {

	} else {
		Serial.println(heading);
	}
  return heading;
}
*/
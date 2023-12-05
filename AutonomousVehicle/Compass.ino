
void compassSetup()
{
  Wire.begin();

	compass.init();
	compass.setSamplingRate(50);

	Serial.begin(115200);
	Serial.println("QMC5883L Compass Demo");
	Serial.println("Turn compass in all directions to calibrate....");
}

int getCompassHeading()
{
	int heading = compass.readHeading();
	if(heading==0) {
		/* Still calibrating, so measure but don't print */
	} else {
		Serial.println(heading);
	}
  return heading;
}
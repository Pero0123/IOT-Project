void compassSetup()//setup code for the gy-271 magnetometer
{
	Wire.begin();

	compass.init();
	compass.setSamplingRate(50);

	Serial.begin(115200);
  compass.resetCalibration();
}

int getHeading()//returns the heading of the compass. includes auto calibration
{
	uint8_t h = compass.readHeading();
	if(h==0) {
		/* Still calibrating, so measure but don't print */
	} else {
		Serial.println(h);
    return h;
	}
}
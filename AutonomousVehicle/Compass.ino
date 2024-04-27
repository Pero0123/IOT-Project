void compassSetup()//setup code for the gy-271 magnetometer
{
	Wire.begin();

	compass.init();
	compass.setSamplingRate(50);

	Serial.begin(115200);
	Serial.println("QMC5883L Compass Demo");
	Serial.println("Turn compass in all directions to calibrate....");
  compass.resetCalibration();
}

int getHeading()//returns the heading of the compass. includes auto calibration
{
	int h = compass.readHeading();
	if(h==0) {
		/* Still calibrating, so measure but don't print */
    Serial.println("compass is calibrating");
	} else {
		Serial.println(h);
    return h;
	}
}

//checks heading of ultrasonics platform and corrects it
void correctPlatformHeading()
{
  int heading;
  heading = getCompassHeading();

  if (heading<92&&heading>88) 
  {
     Servo1.write(90);
     Serial.print("platform is aligned to 90");
  }
  else if (heading>90)
  {
  Servo1.write(80);
  Serial.print("roating counterclockwise");
  }
   else if (heading<90)
  {
  Servo1.write(100);
  Serial.print("platform heading is greater than 90");
  }
}

//checks heading of ultrasonics platform and corrects it
void correctPlatformHeading()
{
  int heading;
  heading = getCompassHeading();

  if (heading<92&&heading>88) 
  {
     Servo1.write(90);
  }
  else if (heading>90)
  {
  Servo1.write(80);
  }
   else if (heading<90)
  {
  Servo1.write(100);
  }
}
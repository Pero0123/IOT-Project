
//checks heading of ultrasonics platform and corrects it
void correctPlatformHeading()
{
  int heading;
  heading = getCompassHeading();

  if (heading<94&&heading>86) 
  {
     Servo1.write(90);
  }
  else if (heading>84)
  {
  Servo1.write(80);
  }
   else if (heading<86)
  {
  Servo1.write(100);
  }
}
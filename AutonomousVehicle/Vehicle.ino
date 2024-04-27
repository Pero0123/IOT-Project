//functions to controll the vehicle
//functions may not work correcly if called more than once every ~10ms


//function to turn. speedLeft and speedRight controlled the speed of each wheel
//if speed is set to negative motor will reverse at the absolute value set
//can also be used for driving forwars and reversing with more control than forwards() and reverse()
void drive(int speedLeft ,int speedRight)
{

  //checks if speed is negative or postive
  //if negative, motor direction is reversed and speed is multiplied by -1 to get the absolute value
  if(speedLeft>0)
  {
    digitalWrite(LeftMotorDir,HIGH);
  }
  else 
  {
    digitalWrite(LeftMotorDir,LOW);
    speedLeft = speedLeft*(-1);
  }

    if(speedRight>0)
  {
    digitalWrite(RightMotorDir,LOW);
  }
  else 
  {
    digitalWrite(RightMotorDir,HIGH);
    speedRight = speedRight*(-1);    
  }

  //sets the speed of both motors to the respective speed variable
  analogWrite(RightMotorEnable,speedRight);
  analogWrite(LeftMotorEnable,speedLeft);
}

void stop()
{
  digitalWrite(RightMotorEnable,HIGH);//motor off
  digitalWrite(LeftMotorEnable,HIGH);//motor off 
}

//drives vehicle toward passed heading
void driveTowardHeading()
{
  if (vehicleHeading<maxHeading && vehicleHeading>minHeading)
  {
     drive(100, 110);//facing the correct heading. should drive straight
  }
  else if (vehicleHeading>maxHeading)
  {
  drive(-90,90);//facing to the right. steer left
  }
   else if (vehicleHeading<minHeading)
  {
  drive(90,-90);//facing to the left. steer right
  }
}


//sets min and max heading
//takes into account that heading is continues from 0-360. gets kinda weird but it works
void configureVehicleHeading()
{
   if((targetHeading-headingRange)<0)
  {
    maxHeading=(targetHeading-headingRange)+360;
    minHeading=targetHeading+headingRange;
  }
  else if((targetHeading+headingRange)>360)
  {
    minHeading=(targetHeading+headingRange)-360;
    maxHeading=targetHeading-headingRange;
  }
  else
  {
    minHeading=targetHeading-headingRange;
    maxHeading=targetHeading+headingRange;
  }
}


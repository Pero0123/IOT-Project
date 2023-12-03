//functions to controll the vehicle
//functions may not work correcly if called more than once every ~10ms


//drive forwards at set speed
void forwards(int speed)
{
  //set direction of motors
  digitalWrite(RightMotorDir,LOW);
  digitalWrite(LeftMotorDir,HIGH);

  //sets speed of each motor
  analogWrite(RightMotorEnable,speed);
  analogWrite(LeftMotorEnable,speed);
}

//reverse at set speed
void reverse(int speed)
{
  //sets direction of both motors
  digitalWrite(RightMotorDir,HIGH);
  digitalWrite(LeftMotorDir,LOW);

  //sets speed of the motors
  analogWrite(RightMotorEnable,speed);
  analogWrite(LeftMotorEnable,speed);
}

//function to turn. speedLeft and speedRight controlled the speed of each wheel
//if speed is set to negative motor will reverse at the absolute value set
void turnWithReverse(int speedLeft ,int speedRight)
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

  //sets the speed of both motors to the respevtive speed variable
  analogWrite(RightMotorEnable,speedRight);
  analogWrite(LeftMotorEnable,speedLeft);
}


// simpleafunction to turn. speedLeft and speedRight controlled the speed of each wheel
//does not support reversing a motor. use turnWithReverse() instead
void Turn(int speedLeft ,int speedRight)
{
  analogWrite(RightMotorEnable,speedRight);
  analogWrite(LeftMotorEnable,speedLeft);

  digitalWrite(RightMotorDir,LOW);//motor off
  digitalWrite(LeftMotorDir,LOW);//motor on 
}

void stop()
{
  digitalWrite(RightMotorEnable,LOW);//motor off
  digitalWrite(LeftMotorEnable,LOW);//motor off 
}


//functions to controll the vehicle




//drive forwards at x speed
void forwards(int speed)
{
  Serial.print("Forwards\n");
  analogWrite(RightMotorEnable,speed);
  analogWrite(LeftMotorEnable,speed);

  digitalWrite(RightMotorDir,LOW);
  digitalWrite(LeftMotorDir,HIGH);
}

//reverse at x speed
void reverse(int speed)
{
  Serial.print("Reverse\n");
  analogWrite(RightMotorEnable,speed);
  analogWrite(LeftMotorEnable,speed);

  digitalWrite(RightMotorDir,HIGH);
  digitalWrite(LeftMotorDir,LOW);
}

//turn left
//speed and radius can be controlled using speed variables
void left(int speedRight ,int speedLeft)
{
  Serial.print("Left\n");
  analogWrite(RightMotorEnable,speedRight);
  analogWrite(LeftMotorEnable,speedLeft);

  digitalWrite(LeftMotorDir,LOW);//motor off
  digitalWrite(RightMotorDir,LOW);//motor on
}

//turn right
//speed and radius can be controlled using speed variables
void right(int speedRight ,int speedLeft)
{
  Serial.print("Right\n");
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



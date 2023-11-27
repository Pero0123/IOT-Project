//functions to controll the vehicle




//drive forwards at x speed
void forwards(int speed)
{
  Serial.print("Forwards");
  analogWrite(RightMotorEnable,speed);
  analogWrite(LeftMotorEnable,speed);

  digitalWrite(RightMotorDir,LOW);
}

//reverse at x speed
void reverse(int speed)
{
  Serial.print("Reverse");
  analogWrite(RightMotorEnable,speed);
  analogWrite(LeftMotorEnable,speed);

  digitalWrite(RightMotorDir,HIGH);
}

//turn left
//speed and radius can be controlled using speed variables
void left(int speedRight ,int speedLeft)
{
  Serial.print("Left");
  analogWrite(RightMotorEnable,speedRight);
  analogWrite(LeftMotorEnable,speedLeft);

  digitalWrite(LeftMotorDir,HIGH);//motor off
  digitalWrite(RightMotorDir,LOW);//motor on
}

//turn right
//speed and radius can be controlled using speed variables
void right(int speedRight ,int speedLeft)
{
  Serial.print("Right");
  analogWrite(RightMotorEnable,speedRight);
  analogWrite(LeftMotorEnable,speedLeft);

  digitalWrite(RightMotorDir,HIGH);//motor off
  digitalWrite(LeftMotorDir,LOW);//motor on 
}



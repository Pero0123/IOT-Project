//funtion to get distance from a specified ultrasonic sensor
//0 for front, 1 for side sensor
//temporary solution to selecting the sensor to read from
float getDistance(int sensor)
{
  float duration;
  if(sensor == 0){//reads from front sensor
 
  digitalWrite(frontTrig, LOW);
  delayMicroseconds(3);
  digitalWrite(frontTrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(frontTrig, LOW);

  duration = pulseIn(frontEcho, HIGH);
  distanceFront = (duration * 003.514);
  return distanceFront;

  // Prints the distance on the Serial Monitor
  Serial.print("Distance Front: ");
  Serial.println(distanceFront);
  delay(100);
  }
  else{//reads from side sensor
  digitalWrite(sideTrig, LOW);
  delayMicroseconds(3);
  digitalWrite(sideTrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(sideTrig, LOW);

  duration = pulseIn(sideEcho, HIGH);
  distanceSide = (duration * 003.514);
  return distanceSide;

  // Prints the distance on the Serial Monitor
  Serial.print("Distance side: ");
  Serial.println(distanceSide);
  delay(100);
  }
}

  void getCoords()
  {
    coords[0] = getDistance(1)+ UltrasonicOffset;//x coordinates. the ultrasonicOffeset is the physical offset of the sensor
    coords[1] = getDistance(0)+ UltrasonicOffset;//y coordinates. the ultrasonicOffset is the physical offset of the sensor
  }
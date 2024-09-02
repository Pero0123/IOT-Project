void configureVehicleHeading() {
  //configurs the max and min headings before the vehicle corrects itself
  //ie. if target = 355 and range is +- 6. max will be 355+6= 361 which is actually 1 degrees.
  if ((targetHeading - headingRange) < 0) {
    maxHeading = (targetHeading - headingRange) + 360;
    minHeading = targetHeading + headingRange;
  } else if ((targetHeading + headingRange) > 360) {
    minHeading = (targetHeading + headingRange) - 360;
    maxHeading = targetHeading - headingRange;
  } else {
    minHeading = targetHeading - headingRange;
    maxHeading = targetHeading + headingRange;
  }
}

void driveTowardHeading() {
  configureVehicleHeading();
  if (vehicleHeading < maxHeading && vehicleHeading > minHeading) {
    servoRight.write(180);
    servoLeft.write(0);
  } else if (vehicleHeading > maxHeading) {
    servoRight.write(87);
    servoLeft.write(87);  //facing to the right. steer left
  } else if (vehicleHeading < minHeading) {
    servoRight.write(93);
    servoLeft.write(93);  //facing to the left. steer right
  }
}

void checkForObstacles() {
  float duration;
  float distance;
  //check for collision on the Right
  digitalWrite(Trig1, LOW);
  delayMicroseconds(2);
  digitalWrite(Trig1, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trig1, LOW);
  duration = pulseIn(Echo1, HIGH, 3000);
  rightDistance = (duration * 0.034 / 2);
  if (rightDistance <= collisionDistance && duration != 0) {
    obstacleRight = true;
    CollisionRight = "Red";
  } else {
    obstacleRight = false;
    CollisionRight = "Green";
  }
  delayMicroseconds(100);

  //check for collision on the front
  digitalWrite(Trig2, LOW);
  delayMicroseconds(2);
  digitalWrite(Trig2, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trig2, LOW);
  duration = pulseIn(Echo2, HIGH, 3000);
  frontDistance = (duration * 0.034 / 2);
  if (frontDistance <= collisionDistance && duration != 0) {
    obstacleFront = true;
    CollisionCenter = "Red";
  } else {
    obstacleFront = false;
    CollisionCenter = "Green";
  }
  delayMicroseconds(100);

  //check for collision on the Left
  digitalWrite(Trig3, LOW);
  delayMicroseconds(2);
  digitalWrite(Trig3, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trig3, LOW);
  duration = pulseIn(Echo3, HIGH, 3000);
  leftDistance = (duration * 0.034 / 2);
  if (leftDistance <= collisionDistance & duration != 0) {
    obstacleLeft = true;
    CollisionLeft = "Red";
  } else {
    obstacleLeft = false;
    CollisionLeft = "Green";
  }


}

void stopForObstacle()
{
  if (obstacleFront || obstacleRight || obstacleLeft) {
    servoRight.write(90);
    servoLeft.write(90);
  }
}

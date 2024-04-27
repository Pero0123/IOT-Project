// //funtion to get distance from a specified ultrasonic sensor
// //0 for front, 1 for side sensor
// //temporary solution to selecting the sensor to read from


// //ultrasonic setup code
// void ultrasonicSetup()
// {
//   //sets pinmodes for all ultrasonic pins
//   pinMode(frontTrig, OUTPUT);
//   pinMode(sideTrig, OUTPUT);
//   pinMode(frontEcho, INPUT);
//   pinMode(sideEcho, INPUT);
// //pinmodes for hbrdige motor controller
//   pinMode(LeftMotorEnable, OUTPUT);
//   pinMode(RightMotorEnable, OUTPUT);
//   pinMode(RightMotorDir, OUTPUT);
//   pinMode(LeftMotorDir, OUTPUT);

// }

// float getDistance(int sensor)
// {
//   float duration;
//   if(sensor == 0){//reads from front sensor
 
//   digitalWrite(frontTrig, LOW);
//   delayMicroseconds(3);
//   digitalWrite(frontTrig, HIGH);
//   delayMicroseconds(10);
//   digitalWrite(frontTrig, LOW);

//   duration = pulseIn(frontEcho, HIGH);
//   distanceFront = (duration * 0.034 / 2);
  
//   return distanceFront;
//   }
//   else{//reads from side sensor
//   digitalWrite(sideTrig, LOW);
//   delayMicroseconds(3);
//   digitalWrite(sideTrig, HIGH);
//   delayMicroseconds(10);
//   digitalWrite(sideTrig, LOW);

//   duration = pulseIn(sideEcho, HIGH);
//   distanceSide = (duration * 0.034 / 2);
  
//   return distanceSide;
//   }
// }

//   //function to get the co ordinates of the vehicle
//   //uses getDistan
//   void getCoords()
//   {
//     coords[0] = getDistance(1);//x coordinates. the ultrasonicOffeset is the physical offset of the sensor
//     delay(20);//delay ensures that the ultrasonics don't interfere with each other. may need to be adjusted
//     coords[1] = getDistance(0);//y coordinates. the ultrasonicOffset is the physical offset of the sensor
//   }
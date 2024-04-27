
// //checks heading of ultrasonics platform and corrects it
// void correctPlatformHeading()
// {
  
//   //configures min and max values for heading
//    if((targetPlatformHeading-headingRangePlatform)<0)
//   {
//     maxPlatformHeading=(targetPlatformHeading-headingRangePlatform)+360;
//     minPlatformHeading=targetPlatformHeading+headingRangePlatform;
//   }
//   else if((targetPlatformHeading+headingRangePlatform)>360)
//   {
//     minPlatformHeading=(targetPlatformHeading+headingRangePlatform)-360;
//     maxPlatformHeading=targetPlatformHeading-headingRangePlatform;
//   }
//   else
//   {
    
//     minPlatformHeading=targetPlatformHeading-headingRangePlatform;
//     maxPlatformHeading=targetPlatformHeading+headingRangePlatform;
//   }


// //keeps platform aligned using servo
//   if (platformHeading<maxPlatformHeading&&platformHeading>minPlatformHeading) 
//   {
//     Servo1.write(90);
//   }
//   if (platformHeading>minPlatformHeading)
//   {
//   Servo1.write(92);
//   }
//   if (platformHeading<maxPlatformHeading)
//   {
//   Servo1.write(88);
//   }
// }
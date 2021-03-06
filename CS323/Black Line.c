#pragma config(Sensor, S1,     RightLight,          sensorLightActive)
#pragma config(Sensor, S4,     LeftLight,           sensorLightActive)
#pragma config(Motor,  motorA,          RightTire,     tmotorNormal, PIDControl, encoder)
#pragma config(Motor,  motorC,          LeftTire,      tmotorNormal, PIDControl, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*
This code is designed to allow a robot to follow a black line on the floor.
Author: Donovan Torgerson
Email: Donovan@Torgersonlabs.com

*/

int RightRead = 100;
int LeftRead = 100;

task WatchLight()
{
 while(true)
 {
  RightRead = SensorValue[RightLight];
  LeftRead = SensorValue[LeftLight];
  nxtDisplayClearTextLine(5);
  nxtDisplayClearTextLine(6);
  nxtDisplayTextLine(5,"R: %d",RightRead);
  nxtDisplayTextLine(6,"L: %d",LeftRead);
  wait1Msec(90);
 }
}

task WatchTires()
{
 int leftrotation = 0;
 int rightrotation = 0;
 while(true)
  {
   leftrotation = nMotorEncoder[LeftTire];
   rightrotation = nMotorEncoder[RightTire];
   nxtDisplayTextLine(2,"L: %d",leftrotation);
   nxtDisplayTextLine(3,"R: %d",rightrotation);
   wait1Msec(500);
 }
}



task main()
{
  motor[RightTire] = 30;
  motor[LeftTire] = 30;
  //StartTask(WatchTires);
  //wait1Msec(500);
  StartTask(WatchLight);
  wait1Msec(100);
  while(true)
  {
    if (RightRead < 45) // If Right sensor reading is greater than 45, adjust right.
    {
      motor[RightTire] = -10;
      motor[LeftTire] = 40;
    }
    else if (LeftRead < 45) // If Left sensor reading is greater than 45, adjust left.
    {
      motor[RightTire] = 40;
      motor[LeftTire] = -10;
    }
    else
    {
      motor[RightTire] = 100;
      motor[LeftTire] = 100;
    }
  }
}

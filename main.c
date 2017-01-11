#pragma config(Sensor, dgtl1,  touchSensor,    sensorTouch)
#pragma config(Motor,  port2,           rightMotor,    tmotorVex393, openLoop)
#pragma config(Motor,  port3,           leftMotor,     tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port4,           climbMotor1,   tmotorVex393, openLoop)
#pragma config(Motor,  port5,           climbMotor2,   tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port6,           armTurnMotor,  tmotorVex393, openLoop)
#pragma config(Motor,  port7,           armWheelMotor, tmotorVex393, openLoop)

#pragma platform(VEX)

#pragma competitionControl(Competition)
#pragma autonomousDuration(15)
#pragma userControlDuration(120)

#include "Vex_Competition_Includes.c"
void pre_auton()
{
  bStopTasksBetweenModes = true;
}

task autonomous() {
   motor[rightMotor]  = motor[leftMotor] = 127;
   Sleep(4000);
   motor[rightMotor]  = motor[leftMotor] = -127;
   Sleep(2000);
   motor[rightMotor]  = motor[leftMotor] = 0;
}

task usercontrol() {
  while(1==1) {
    motor[rightMotor]  = vexRT[Ch2];
    motor[leftMotor] = vexRT[Ch3];
   while (SensorValue[touchSensor]==1)
   {
     motor[armTurnMotor]=127; motor[armTurnMotor]=0;}
   motor[climbMotor1] = motor[climbMotor2] = motor[armWheelMotor] = (vexRT[Btn5U] - vexRT[Btn5D]) * 127;
    motor[armTurnMotor] = (vexRT[Btn7R] - vexRT[Btn7L]) * 127;
  }
}

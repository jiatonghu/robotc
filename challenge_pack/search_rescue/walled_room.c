#pragma config(StandardModel, "Clawbot IQ With Sensors")
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//
void turnRightByGyro(int degrees)
{
	resetGyro(port4);
	while(getGyroDegrees(port4)>-degrees + 1)
	{
		setMotorSpeed(motor1,35);
		setMotorSpeed(motor6,-35);
	}
	setMotorSpeed(motor1,0);
	setMotorSpeed(motor6,0);
}

void turnLeftByGyro(int degrees)
{
	resetGyro(port4);
	while(getGyroDegrees(port4)<degrees - 1)
	{
		setMotorSpeed(motor1,-35);
		setMotorSpeed(motor6,35);
	}
	setMotorSpeed(motor1,0);
	setMotorSpeed(motor6,0);
}

task main()
{
	setMultipleMotors(50, leftmotor, rightMotor);
	while(getDistanceValue(port7) > 100){}
	stopMultipleMotors(leftMotor, rightMotor);
  turnLeftByGyro(90);
  setMultipleMotors(50, leftmotor, rightMotor);
	while(getDistanceValue(port7) > 100){}
	stopMultipleMotors(leftMotor, rightMotor);
  turnRightByGyro(90);
  forward(7.2, rotations, 50);
  turnLeftByGyro(90);
  forward(2, rotations, 50);
}

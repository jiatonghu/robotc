#pragma config(StandardModel, "Clawbot IQ With Sensors")
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

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
	moveMotor(motor11, 2, seconds, 50);
	moveMotor(motor10, 5, seconds, 50);
	moveMotor(motor11, 2, seconds, -50);
	moveMotor(motor10, 5, seconds, -50);
	forward(1, rotations, 50);
	turnLeftByGyro(90);
	forward(5, rotations, 50);
}

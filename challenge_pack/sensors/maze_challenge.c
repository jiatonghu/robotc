#pragma config(StandardModel, "Clawbot IQ With Sensors")
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

// For this challenge, create a maze with walls, similarly to the one illustrated below.
// Then program your robot to navigate the maze, from start to end, using the Ultrasonic Sensor
// AND not touching any walls. Note: When going through this challenge, the Ultrasonic Sensor is
// located on the BACK of the robot, facing BACKWARDS.
void turnRightByGyro(int degrees)
{
	resetGyro(port4);
	while(getGyroDegrees(port4)>-degrees)
	{
		setMotorSpeed(motor1,50);
		setMotorSpeed(motor6,-50);
	}
	setMotorSpeed(motor1,0);
	setMotorSpeed(motor6,0);
}

void turnLeftByGyro(int degrees)
{
	resetGyro(port4);
	while(getGyroDegrees(port4)<degrees)
	{
		setMotorSpeed(motor1,-50);
		setMotorSpeed(motor6,50);
	}
	setMotorSpeed(motor1,0);
	setMotorSpeed(motor6,0);
}
task main()
{
	moveMotor(motor10, 4, seconds, 50);
	backward(3.5, rotations, 50);
	turnLeftByGyro(90);
	setMultipleMotors(-50, leftMotor, rightMotor);
	while(getDistanceValue(port7) > 100){
	}
	stopAllMotors();
	turnRightByGyro(90);
	setMultipleMotors(-50, leftMotor, rightMotor);
	while(getDistanceValue(port7) > 100){
	}
	stopAllMotors();
	turnRightByGyro(90);
	backward(2, rotations, 50);
}

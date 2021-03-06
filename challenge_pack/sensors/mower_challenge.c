#pragma config(StandardModel, "Clawbot IQ With Sensors")
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

// For this challenge, program the robot to erase or clear the entire surface of debris.
// The robot is able to move freely. However, there are three zones marked on the surface.
// When the robot enters these zone, the robot must picked up, then place back down,
// then resume going through the rest of its program.
// Note: In the virtual challenge, the robot will be picked up automatically,
// then placed back down after a few seconds.
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

	forward(7, rotations, 100);
	turnRightByGyro(90);
	forward(2, rotations, 100);
	turnRightByGyro(90);
	forward(7, rotations, 100);
	turnLeftByGyro(90);
	forward(2, rotations, 100);
	turnLeftByGyro(90);
	forward(7, rotations, 100);
	turnRightByGyro(90);
	forward(2, rotations, 100);
	turnRightByGyro(90);
	forward(7, rotations, 100);
}

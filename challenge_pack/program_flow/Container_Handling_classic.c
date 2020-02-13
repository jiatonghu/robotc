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
	while(1){
		setTouchLEDColor(port2, colorGreen);
		setMultipleMotors(50, leftMotor, rightMotor);
		while(getDistanceValue(port7) > 70){
		}
		stopMultipleMotors(leftMotor, rightMotor);
		setTouchLEDColor(port2, colorBlue);
		moveMotor(motor11, 2, seconds, 50);
		setTouchLEDColor(port2, colorYellow);
		turnRightByGyro(180);
		setMultipleMotors(50, leftMotor, rightMotor);
		while(getColorHue(port3) != 85){
		}
		stopMultipleMotors(leftMotor, rightMotor);
		setTouchLEDColor(port2, colorBlue);
		moveMotor(motor11, 2, seconds, -50);
		setTouchLEDColor(port2, colorYellow);
		turnLeftByGyro(180);
	}
}
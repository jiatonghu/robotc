#pragma config(Sensor, port2,  touchLED,       sensorVexIQ_LED)
#pragma config(Sensor, port3,  colorDetector,  sensorVexIQ_Color12Color)
#pragma config(Sensor, port4,  gyroSensor,     sensorVexIQ_Gyro)
#pragma config(Sensor, port7,  distanceMM,     sensorVexIQ_Distance)
#pragma config(Sensor, port8,  bumpSwitch,     sensorVexIQ_Touch)
#pragma config(Motor,  motor1,          leftMotor,     tmotorVexIQ, openLoop, driveLeft, encoder)
#pragma config(Motor,  motor6,          rightMotor,    tmotorVexIQ, openLoop, reversed, driveRight, encoder)
#pragma config(Motor,  motor10,         armMotor,      tmotorVexIQ, openLoop, encoder)
#pragma config(Motor,  motor11,         clawMotor,     tmotorVexIQ, openLoop, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

void turnRightByGyro(int degrees)
{
	resetGyro(port4);
	while(getGyroDegrees(port4)>-degrees)
	{
		setMotorSpeed(motor1,20);
		setMotorSpeed(motor6,-20);
	}
	setMotorSpeed(motor1,0);
	setMotorSpeed(motor6,0);
}

void turnLeftByGyro(int degrees)
{
	resetGyro(port4);
	while(getGyroDegrees(port4)<degrees)
	{
		setMotorSpeed(motor1,-30);
		setMotorSpeed(motor6,30);
	}
	setMotorSpeed(motor1,0);
	setMotorSpeed(motor6,0);
}

void forwardBySteps(float n) {
	forward(0.74 * n, rotations, 50);
}

const int center = 820;

task main()
{
	while(true){
		setTouchLEDColor(port2, colorNone);
		sleep(2000);
		if (getDistanceValue(port7) > 1000) {
			// clear room or fire room
			forwardBySteps(4);
			if (getColorName(port3) == colorDarkYellow || getColorName(port3) == colorYellow) {
				// in fire room
				setTouchLEDColor(port2, colorRed);
				while(getColorName(port3) != colorViolet && getColorName(port3) != colorRed){}
			}
			else {
				// in clear room
				setTouchLEDColor(port2, colorOrange);
			}
			turnLeftByGyro(90);
			forwardBySteps(8.5);
		}
		else if (getDistanceValue(port7) < 300) {
			// in walled room
			setTouchLEDColor(port2, colorBlue);
			turnLeftByGyro(90);
			forwardBySteps(4);
			turnRightByGyro(90);
			forwardBySteps(4);
			turnLeftByGyro(90);
			forwardBySteps(4.5);
		}
		else {
			// in rescue room
			moveMotor(clawMotor, 1, seconds, -50);
			setTouchLEDColor(port2, colorGreen);
			setMultipleMotors(50, motor1, motor6);
			while(getDistanceValue(port7) > 75){}
			stopMultipleMotors(motor1, motor6);
			moveMotor(clawMotor, 2, seconds, 50);
			moveMotor(armMotor, 5, seconds, 50);
			moveMotor(clawMotor, 2, seconds, -50);
			moveMotor(armMotor, 5, seconds, -50);
			moveMotor(armMotor, 5, degrees, 25);
			setMultipleMotors(50, motor1, motor6);
			while(getDistanceValue(port7) > center){}
			stopMultipleMotors(motor1, motor6);
			turnLeftByGyro(90);
			forwardBySteps(8.5);
		}
	}
}
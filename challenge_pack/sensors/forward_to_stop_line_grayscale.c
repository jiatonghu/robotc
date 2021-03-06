#pragma config(Sensor, port2,  touchLED,       sensorVexIQ_LED)
#pragma config(Sensor, port3,  colorDetector,  sensorVexIQ_ColorGrayscale)
#pragma config(Sensor, port4,  gyroSensor,     sensorVexIQ_Gyro)
#pragma config(Sensor, port7,  distanceMM,     sensorVexIQ_Distance)
#pragma config(Sensor, port8,  bumpSwitch,     sensorVexIQ_Touch)
#pragma config(Motor,  motor1,          leftMotor,     tmotorVexIQ, openLoop, driveLeft, encoder)
#pragma config(Motor,  motor6,          rightMotor,    tmotorVexIQ, openLoop, reversed, driveRight, encoder)
#pragma config(Motor,  motor10,         armMotor,      tmotorVexIQ, openLoop, encoder)
#pragma config(Motor,  motor11,         clawMotor,     tmotorVexIQ, openLoop, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

// Using a Color Sensor, program the robot to move forward until it detects a line!
// NOTE: This mini-challenge is a two-part challenge. Place a dark colored tape on
// a light colored surface. Start the robot away from the tape, then program the robot to
// move forward towards to tape, then stop when it detects it. Next, place a light colored
// tape on a dark surface, then program the robot to do that same behavior.
// In virtual worlds, two complete this activity correctly, you must do this activity from
// both starting points.

task main()
{
	unsigned short gray_scale = getColorGrayscale(port3);
	setMultipleMotors(50, motor1, motor6);
	while(abs(getColorGrayscale(port3) - gray_scale) < 100) {
	}
	stopMultipleMotors(motor1, motor6);
}

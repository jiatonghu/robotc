#pragma config(StandardModel, "Clawbot IQ With Sensors")
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()
{
	setTouchLEDColor(port2, colorRed);
	while(joy1Btn(Btn1) == 0){}
	setTouchLEDColor(port2, colorGreen);
	resetTimer(T1);
	while(getTimer(T1, seconds) <= 60){
		if(joy1Pov(Pov0) == 1){
			setMultipleMotors(100, rightMotor, leftMotor);
			setTouchLEDColor(port2, colorBlue);
		}
		else if(joy1Pov(Pov4) == 1){
			setMultipleMotors(-100, rightMotor, leftMotor);
			setTouchLEDColor(port2, colorRed);
		}
		else if(joy1Pov(Pov2) == 1){
			setMotorSpeed(rightMotor, -100);
			setMotorSpeed(leftMotor, 100);
		}
		else if(joy1Pov(Pov6) == 1){
			setMotorSpeed(rightMotor, 100);
			setMotorSpeed(leftMotor, -100);
		}
		else if(joy1Btn(Btn6) == 1){
			moveMotor(clawMotor, 2, seconds, -50);
			moveMotor(armMotor, 3, seconds, -50);
			setMultipleMotors(50, leftMotor, rightMotor);
			while(getDistanceValue(port7) > 100){}
			stopAllMotors();
			moveMotor(clawMotor, 2, seconds, 50);
			moveMotor(armMotor, 1, seconds, 50);
		}
		else{
			tankControl(JoyY2, JoyY1, 10);
			armControl(motor10, Btn4, Btn1);
			armControl(motor11, Btn2, Btn3);
		}
	}
}

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
		else{
			tankControl(JoyY2, JoyY1, 10);
			armControl(motor10, Btn4, Btn1);
			armControl(motor11, Btn2, Btn3);
		  setTouchLEDColor(port2, colorYellow);
			getJoystickSettings(joystick);
			displayTextLine(line1, "%d",joystick.joy1_Buttons );
		}
	}
}

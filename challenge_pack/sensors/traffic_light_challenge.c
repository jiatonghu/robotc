#pragma config(StandardModel, "Clawbot IQ With Sensors")
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

// For this challenge, attach the Color Sensor for that it is facing forward. Place three pieceof
// taped lines, representing intersection. Create an object that represents traffic lights, an object
// that is either hand-held or placed on the ground. Next, program your robot to navigate through
// the intersections, stopping at any intersection that has red traffic lights.

task main()
{
	 while(1){
		setMultipleMotors(50, motor1, motor6);
		setTouchLEDColor(port2, colorGreen);
		while(getColorName(port3) != colorRed){
		}
		stopMultipleMotors(motor1, motor6);
		setTouchLEDColor(port2, colorRed);
		while(getColorName(port3) != colorGreen){
		}
	}
}

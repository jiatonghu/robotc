#pragma config(StandardModel, "Clawbot IQ With Sensors")
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()
{
	while(1) {
		forward(1, rotations, 50);
		backward(1, rotations, 50);
	}
}
// Created on Thu April 16 2015

#include "RobotMovement.h"


int main()
{
	int test = 2;
	printf("Enable servos \n");
	enable_servos();
	printf("Setting servo to 2047\n");
	set_servo_position(SRVARM,2047);
	//240-790
	set_servo_position(SRVARM2, 240);
	
	
	while(digital(PRESSENSOR)==0)
	{
		printf("Going forward and checking for presses\n");
		forward(90, 0.2);
		
	}
	printf("Set top servo to position\n");
	set_servo_position(SRVARM, 1700);
	printf("Wait so the program termination doesn't interrupt this process\n");
	msleep(2000);
	printf("Set top servo to position\n");
	set_servo_position(SRVARM2, 900);
	msleep(5000);
	printf("Program has been terminated\n");
	return 0;
}

void forward(int power, float duration) 
{
		// engage both motors
	motor(LEFTWHEEL, power);
	motor(RIGHTWHEEL, power);
		
	msleep(duration*1000); // sleep so that the motors run for the correct amount of time
	
	ao(); // all off
	
	return;
}

void turnRight (int power, float duration) 
{
	motor(LEFTWHEEL, 0); // ensure left motor is off
	motor(RIGHTWHEEL, power); // engage right motor to turn right
		
	msleep(duration*1000); // sleep so that the motors run for the correct amount of time
		
	ao(); // all off
	return;
}

void turnLeft (int power, float duration) 
{
	motor(RIGHTWHEEL, 0); // ensure right motor is off
	motor(LEFTWHEEL, power); // engage left motor to turn left

	msleep(duration*1000); 	// sleep so that the motors run for the correct amount of time
	ao();
	return;
}

void reverse (int power, float duration) 
{
		// engage both motors
	motor(LEFTWHEEL, power*-1); 
	motor(RIGHTWHEEL, power*-1);
	 	// sleep so that the motors run for the correct amount of time
	msleep(duration*1000);
	
	ao();
	
	return;
}

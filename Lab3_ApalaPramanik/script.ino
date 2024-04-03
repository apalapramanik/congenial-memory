
/* 

Ringo Robot
Ringo_Base_Sketch_Rev06
Version 6.2 03/2018

This is a basic sketch that can be used as a starting point
for various functionality of the Ringo robot.

Significant portions of this code written by
Dustin Soodak for Plum Geek LLC. Some portions
contributed by Kevin King.
Portions from other open source projects where noted.
This code is licensed under:
Creative Commons Attribution-ShareAlike 2.0 Generic (CC BY-SA 2.0)
https://creativecommons.org/licenses/by-sa/2.0/
Visit http://www.plumgeek.com for Ringo information.
Visit http://www.arduino.cc to learn about the Arduino.

*/

/*

Author: Apala Pramanik
Date: Feb 8th, 2024

*/

//import libraries
#include <Arduino_FreeRTOS.h>
#include "RingoHardware.h"

// Variables
// int desiredHz = 20.0;
// int Hz = 1.0/desiredHz;
// int error = 0.0;
// int last_error = 0;
// int integral = 0;
// int P =0;
// int I = 0;
// int D = 0;
// int Kp = 0;
// int Ki = 0;
// int Kd = 0;

// int target = 304.8; //in mm (1ft)
// int steps = 400;

// int vel = 0.0;
// int currentPos = 0.0;




// Task Handles 
/*
Type by which tasks are referenced. 
For example, a call to xTaskCreate returns (via a pointer parameter)
an TaskHandle_t variable that can then be used as a parameter to 
vTaskDelete to delete the task.
 */
TaskHandle_t straightLineTaskHandle = NULL;
TaskHandle_t rotateTaskHandle = NULL;



// Function Prototypes:
void straightTask(void *pvParameters);
void rotateTask(void *pvParameters);



//Main function......................................................................................

//Initialize setup
void setup(){
  HardwareBegin();    
  PlayStartChirp();
  delay(1000);
  NavigationBegin();
  

  Serial.begin(57600); //9600
  // Start the FreeRTOS task scheduler
  vTaskStartScheduler();
  
  



  //Create tasks:
  // xTaskCreate(straightLineTask, "Straight", 128, NULL, 1, &straightLineTaskHandle);
  xTaskCreate(rotateTask, "Rotate", 128, NULL, 1, &rotateTaskHandle);
 
 

}

// Function definitions:................................................................................


// Straight line task
// void straightLineTask(void *pvParameters) {
  
//   // MoveWithOptions(PresentHeading(), 100, 304.8, 1000, 100, 0, 0);
//   // for (int i = 1; i <= steps; i++){
//   //   error = target -currentPos;
//   //   P = error;
//   //   I = I + error;
//   //   D = error - last_error;

//   //   if(i ==1){
//   //     D = 0.0;
//   //     I = 0.0;
//   //   }
  
//   // }

//   // vel = (Kp*P) + (Ki*I) + (Kd*D);
//   // Serial.print("Heree");
//   // Serial.println();
//   // int min_value = -0.025;
//   // int max_value = 0.025;

//   // int random_number = rand(); 
//   // int noise = (max_value - min_value) * random_number + min_value;
//   // Serial.print(vel);
//   // // if (vel > 255.0){
//   // //   vel = 255.0;
//   // // } 
//   // int distanceTraveled = vel * Hz;
//   // currentPos = currentPos + distanceTraveled;
//   // last_error = error;

//   // // Print current position
//   // // Serial.print("Step: ");
//   // // Serial.print(i);
//   // Serial.print(", Current Pose: ");
//   // Serial.print(currentPos);
//   // Serial.println(" mm");

//   // Move the robot
//   // MoveWithOptions(PresentHeading(), vel, target, 6000, 100, 0, 0);
//   Motors(100,100);

//   // Delay for the desired Hz
//   delay(Hz);
        
   
  
// }


void rotateTask(void *pvParameters){

  // DriveArc(90, 200, 75, 500, 0);
  RotateAccurate(-90, 500);
  int heading = PresentHeading();
  Serial.print(heading);

  
}

    
void loop(){ 

} // end of loop() function










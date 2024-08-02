#include "Calibration.h"
#include "ColorSensor.h"
#include <GyroSensor.h>
#include "Clock.h"
#include "Motor.h" 

#include <Clock.h>

Calibration::Calibration():
  leftWheel(PORT_C), rightWheel(PORT_B), colorSensor(PORT_2), gyroSensor(PORT_4), sonarSensor(PORT_3) { // <2>
}

void Calibration::init() {
  init_f("DoubleLoop");
}

void Calibration::terminate() {
  msg_f("Stopped.", 1);
  leftWheel.stop();  // <1>
  rightWheel.stop();
}


void Calibration::run() {
  
   int Count = 250;
    leftWheel.setPWM(60);
    rightWheel.setPWM(-60);

    int currentCountC = ev3_motor_get_counts(EV3_PORT_C);
    
    // Populate the array with brightness values
    for (int i = 0; i < N; i++) {
        arr[i] = colorSensor.getBrightness();
    }

    if (currentCountC >= Count) {
        ev3_motor_stop(EV3_PORT_C, true); // Stop motor C
        ev3_motor_stop(EV3_PORT_B, true); // Stop motor B
        
        for (int i = 0; i < N; i++) {
            if (arr[i] > max) {
                max = arr[i]; // Update max if a larger value is found
            }
            if (arr[i] < min) {
                min = arr[i]; // Update min if a smaller value is found
            }
        }

        // Calculate target line sum
        int target_line_sum = (max + min) / 2;

        // Print max, min, and target line sum values
        //printf("Maximum value: %d Minimum value: %d Target line sum: %d\n", max, min, target_line_sum);
        

        // Write target line sum to file
        FILE *file = fopen("target_line.txt", "w");
        if (file != NULL) {
            fprintf(file, "%d\n", target_line_sum);
            fclose(file);
            //printf("Successfully wrote target line sum to file.\n");
        } else {
            perror("Error opening file for writing on calibration.cpp");
        }
    }

   

  



       

       
        
    
       
        

        
        
       
    }

      
      
      
      
        
       
        
        
        

        
       

        
         
         

        
        
        
      

       

  

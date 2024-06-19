#include "Motor.h"       // <1>
#include "ColorSensor.h" // <2>
#include "util.h"        // <3>
#include <GyroSensor.h>
#include <Clock.h>
#include <SonarSensor.h>
#include <limits.h>
#include <stdio.h>
#include <math.h>




//#include <stdio.h>  //printf使うため


//#include "ev3rt.h"

using namespace ev3api;  // <4>

class Tracer {  // <1>
public:
  Tracer();
  void run();       // <2>
  void init();
  void terminate();
  void calibration();
  void colorscan();

  
private:
  Motor leftWheel;
  Motor rightWheel;
  ColorSensor colorSensor;
  GyroSensor gyroSensor; 
  SonarSensor sonarSensor;
  Clock clock;

  





int arr[2000];
int N = 2000;
// Initialize max and min with the first element of the array
int max = arr[0];
int min = arr[0];

int calibration_program(void)
{

   int Count = 300;
         leftWheel.setPWM(65);
         rightWheel.setPWM(-65);
          int currentCountC = ev3_motor_get_counts(EV3_PORT_C);
         
            //printf("Current Counts: C=%d\n", currentCountC);
          if (currentCountC >= Count ) {
            ev3_motor_stop(EV3_PORT_C, true); // モーターCを停止
            ev3_motor_stop(EV3_PORT_B, true); // モーターBを停止
            for (int i = 1; i < N; i++) {
                if (arr[i] > max) {
                    max = arr[i]; // Update max if a larger value is found
                }
            
            
                if (arr[i] < min) {
                    min = arr[i]; // Update min if a smaller value is found
                }
            }
            
            //printf("Maximum value: %d\n", max);
            //printf("Minimum value: %d\n", min);
                  
        }  

   //int N = sizeof(arr)/sizeof(arr[0]);
   
   for (int i = 0; i<N; i++)
   {
    arr[i] = colorSensor.getBrightness();
    //printf("%d\n", arr[i]);

   }

   
    
int target_line_sum =(max +  min)/2;
//printf("max:%d,min:%d,target:%d\n", max,min,target_line_goal);

return target_line_sum;
   
}




//int pwm = 25;

//printf("%d\n",target_line);
//int target_line =22;
};

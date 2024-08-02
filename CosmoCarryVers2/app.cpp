#include "app.h" // <1>
#include "Tracer.h" // <2>
#include "Clock.h"  // <3>
#include <ColorSensor.h>
#include "ev3api.h"
#include <math.h>
#include <Motor.h>
#include <TouchSensor.h>
#include <SonarSensor.h>
#include <math.h>
#include <stdio.h>
#include <GyroSensor.h>



using namespace ev3api;

Tracer tracer;  // <4>
Clock clock; 

ColorSensor colorSensor(PORT_2);
Motor leftWheel(PORT_C);
Motor rightWheel(PORT_B);
TouchSensor touchSensor(PORT_1);
SonarSensor sonarSensor(PORT_3);
GyroSensor gyroSensor(PORT_4);
// <5>





void tracer_task(intptr_t exinf) {
  
   
    tracer.run(); // <2>
          
      
    ext_tsk();

  
}

void main_task(intptr_t unused) 
{ // <1>
   const uint32_t duration = 100*1000;
 ev3_sensor_config(EV3_PORT_3, ULTRASONIC_SENSOR);

  

  while(true){
    int sonar_dist = sonarSensor.getDistance();
      //printf("%d\n",sonar_dist);

 
   if( sonar_dist == 4){
     
      while(true)
                {
                    rgb_raw_t rgb;
                    
                  colorSensor.getRawColor(rgb);
                  int r = rgb.r; int g = rgb.g; int b = rgb.b;
                  leftWheel.setPWM(40);
                  rightWheel.setPWM(40);
                    
                  printf("r:%d g:%d b:%d\n",r,g,b);
                  if(rgb.r >= 10 && rgb.g >= 30 && rgb.b >= 60)
                  {
                      leftWheel.stop();
                      rightWheel.stop();
                      
                                             
                  }
                }
               
    
    
    
    }
    
    
    
    
    clock.sleep(10 * 1000);
  }
    
    
 // <2>
  while (!ev3_button_is_pressed(LEFT_BUTTON)) { // <1>
      clock.sleep(duration);   // <2>
    }
    
  stp_cyc(TRACER_CYC); // <3>
  tracer.terminate(); // <4>
  ext_tsk(); // <5>

  
  
}




   
/*void main_task(intptr_t unused)
 
{       ev3_sensor_config(EV3_PORT_1, TOUCH_SENSOR);
      ev3_sensor_config(EV3_PORT_2, COLOR_SENSOR);
     
    
       
while(true)
{ 
          
      while(true)
      {
            
        int touch_sensor_middle = ev3_button_is_pressed(ENTER_BUTTON);
        int touch_sensor_right = ev3_button_is_pressed(RIGHT_BUTTON);
        if( touch_sensor_right == true)
        { 
          tracer.init();
          tracer.calibration();
          sta_cyc(CALIBRATION_CYC);
                
        }
        clock.sleep(100000);
      
        if( touch_sensor_middle == true)
        {  
          tracer.init(); 
          sta_cyc(TRACER_CYC);
        }
        clock.sleep(100000);
          
      }
        }
          
      
   
    
  while (!ev3_button_is_pressed(LEFT_BUTTON)) 
  { // <1>
    clock.sleep(100*1000);  
  }

  
  stp_cyc(TRACER_CYC);
  tracer.terminate(); 
  ext_tsk(); // <5>
  
  

  
}*/
  



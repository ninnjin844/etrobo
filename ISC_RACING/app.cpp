#include "app.h" // <1>
#include "Tracer.h" // <2>
#include "Clock.h"  // <3>
#include "Calibration.h"
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
Calibration calibration;

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

void calibration_task(intptr_t exinf) {
  
   
    calibration.run(); // <2>
          
      
    ext_tsk();

  
}






   
void main_task(intptr_t unused)
 
{       
    ev3_sensor_config(EV3_PORT_1, TOUCH_SENSOR);
      ev3_sensor_config(EV3_PORT_2, COLOR_SENSOR);
     
   
while(true)
{ 
          
         
     
          
          
        
      while(true)
      {
            int touch_sensor_middle = ev3_button_is_pressed(ENTER_BUTTON);
                 
          int touch_sensor_right = ev3_button_is_pressed(RIGHT_BUTTON);
          
            
      
          if( touch_sensor_right == true)
          { 
                calibration.init();
                calibration.run();
                sta_cyc(CALIBRATION_CYC);
                //printf("no calibration\n");
                
                
                
                
          }
           clock.sleep(100000);
      
          if( touch_sensor_middle == true)
          {  
            
             
              stp_cyc(CALIBRATION_CYC);
                   // <3>
              calibration.terminate();
                
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
}
  



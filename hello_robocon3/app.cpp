#include "app.h" // <1>
#include "Tracer.h" // <2>
#include "Clock.h"  // <3>
#include "DoubleLoop.h"
#include <ColorSensor.h>
#include "ev3api.h"
#include <Motor.h>
#include <TouchSensor.h>
#include <SonarSensor.h>



using namespace ev3api;

Tracer tracer;  // <4>
Clock clock; 
DoubleLoop doubleloop; 
ColorSensor colorSensor(PORT_2);
Motor leftWheel(PORT_C);
Motor rightWheel(PORT_B);
TouchSensor touchSensor(PORT_1);
SonarSensor sonarSensor(PORT_3);
// <5>



void tracer_task(intptr_t exinf) { // <1>

  
 
 tracer.run(); // <2>
     ext_tsk();
  
}


void calibration_task(intptr_t exinf) { // <1>

 tracer.calibration();
 ext_tsk();
  
 
 
  
  
  
 
 
  
}
void doubleloop_task(intptr_t exinf)
{
  leftWheel.stop();
  rightWheel.stop();
  clock.wait(1000);
  doubleloop.run();
  ext_tsk();
}

void main_task(intptr_t unused)
 
 { 
   
   ev3_sensor_config(EV3_PORT_3, ULTRASONIC_SENSOR);
   ev3_sensor_config(EV3_PORT_1, TOUCH_SENSOR);
   
  const uint32_t duration = 100*1000; // <2>
   
   
   //clock.sleep(10*1000);
   
   // <3>
   
   
while(true){
    
 while(true){
   int sonar_dist = sonarSensor.getDistance();
      //printf("%d\n",sonar_dist);
        int touch_sensor_middle = ev3_button_is_pressed(ENTER_BUTTON);
        int touch_sensor_right = ev3_button_is_pressed(RIGHT_BUTTON);
        //int count = 0;
   if( touch_sensor_right == true){
   //if( sonar_dist==4 ){
     
     tracer.init();
   tracer.calibration();
   sta_cyc(CALIBRATION_CYC);
   
     
      
      break;
    
    
    
    }
    
    
    
    
    clock.sleep(50* 1000);
    
     if( sonar_dist==4 ){
     //if( touch_sensor_middle == true){
       
     tracer.init(); // <3>
  sta_cyc(TRACER_CYC); // <4>
     
      
      break;
    
    
    
    }
    
    
    
    
    clock.sleep(50 * 1000);
  }
  
  
}
  
  
  while (!ev3_button_is_pressed(LEFT_BUTTON)) { // <1>
      clock.sleep(duration);  
      }

   
stp_cyc(CALIBRATION_CYC);
 
  stp_cyc(TRACER_CYC); // <3>
  tracer.terminate(); // <4>
  ext_tsk(); // <5>
  
  
}


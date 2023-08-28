#include "app.h" // <1>
#include "Tracer.h" // <2>
#include "Clock.h"  // <3>
#include <SonarSensor.h>
using namespace ev3api;

Tracer tracer;  // <4>
Clock clock;  
SonarSensor sonarSensor(PORT_3);  // <5>

void tracer_task(intptr_t exinf) { // <1>
  tracer.run(); // <2>
  ext_tsk();
}

void main_task(intptr_t unused) 
{ // <1>
   const uint32_t duration = 100*1000;
 ev3_sensor_config(EV3_PORT_3, ULTRASONIC_SENSOR);
  

  while(true){
    int sonar_dist = sonarSensor.getDistance();
      printf("%d\n",sonar_dist);

 
   if( sonar_dist == 4)  // <1>} { 
    {
     
      tracer.init(); // <3>
  sta_cyc(TRACER_CYC); // <4>
      break;
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


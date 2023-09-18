#include "app.h" // <1>
#include "Tracer.h" // <2>
#include "Clock.h"  // <3>
#include "DoubleLoop.h"
#include <ColorSensor.h>
#include "ev3api.h"
#include <Motor.h>
#include <GyroSensor.h>
#include "parameters.h"




using namespace ev3api;

Tracer tracer;  // <4>
Clock clock; 
DoubleLoop doubleloop; 
ColorSensor colorSensor(PORT_2);
Motor leftWheel(PORT_C);
Motor rightWheel(PORT_B);
GyroSensor gyroSensor(PORT_4);
// <5>



void tracer_task(intptr_t exinf) { // <1>
  tracer.run(); // <2>
  ext_tsk();
}

void doubleloop_task(intptr_t exinf)
{    
  doubleloop.run();
  ext_tsk();
}

void main_task(intptr_t unused)

 { 
    const uint32_t duration = 100*1000;
    
      doubleloop.init();
      sta_cyc(DOUBLELOOP_CYC);
      
  while (!ev3_button_is_pressed(LEFT_BUTTON)) { // <1>
      clock.sleep(duration);   // <2>
  }
  stp_cyc(DOUBLELOOP_CYC); // <3>
  doubleloop.terminate();
  
  ext_tsk(); // <5>
  
  
}


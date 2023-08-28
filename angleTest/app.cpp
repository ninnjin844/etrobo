#include "app.h" // <1>
#include "Tracer.h" // <2>
#include "Clock.h"  // <3>
#include "DoubleLoop.h"
#include <ColorSensor.h>
#include "ev3api.h"
#include <Motor.h>



using namespace ev3api;

Tracer tracer;  // <4>
Clock clock; 
DoubleLoop doubleloop; 
ColorSensor colorSensor(PORT_2);
Motor leftWheel(PORT_C);
Motor rightWheel(PORT_B);
// <5>



void tracer_task(intptr_t exinf) { // <1>
  tracer.run(); // <2>
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
   
   /*ev3_sensor_config(EV3_PORT_2, COLOR_SENSOR);
   
   // <2>
   

     tracer.init(); // <3>
  sta_cyc(TRACER_CYC); // <4>
  


  colorid_t colorid;*/
 //while(true){
    //colorid = colorSensor.getColorNumber();

 
    
   // if( colorid == 2)  // <1>} { 
    //{
      const uint32_t duration = 100*1000;
      doubleloop.init();
      sta_cyc(DOUBLELOOP_CYC);
      //break;
    //}
    //clock.sleep(10 * 1000);
  //}
   
   
  

  
  
  while (!ev3_button_is_pressed(LEFT_BUTTON)) { // <1>
      clock.sleep(duration);   // <2>
  }
  stp_cyc(DOUBLELOOP_CYC); // <3>
  doubleloop.terminate();
  //stp_cyc(TRACER_CYC); // <3>
  //tracer.terminate(); // <4>
  ext_tsk(); // <5>
  
  
}


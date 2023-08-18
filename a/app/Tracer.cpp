#include "Tracer.h"
#include <ColorSensor.h>



Tracer::Tracer():
  leftWheel(PORT_C), rightWheel(PORT_B), colorSensor(PORT_2){ // <2>
}

void Tracer::init() {
  init_f("Tracer");
}

void Tracer::terminate() {
  msg_f("Stopped.", 1);
  leftWheel.stop();  // <1>
  rightWheel.stop();
}

void Tracer::run() 
{
  //int sonar_dist = sonarSensor.getDistance	();
 

  

    
      msg_f("running...", 1);
      int light_val = colorSensor.getBrightness(); //mThreshold
      int dist_val = (light_val - mThreshold);
      int turn_val = (dist_val*3.5);
      int DGain = (dist_val - light_val);
      leftWheel.setPWM((PWM+(turn_val-DGain))*0.5);
      rightWheel.setPWM((PWM-(turn_val+DGain))*0.5);
      //printf("%d\n",light_val);
      //printf("走れーーー\n");
     
}

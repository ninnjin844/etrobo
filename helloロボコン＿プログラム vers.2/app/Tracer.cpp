#include "Tracer.h"
#include "ColorSensor.h"
#include <GyroSensor.h>
#include "Clock.h"
#include <SonarSensor.h>

Tracer::Tracer():
  leftWheel(PORT_C), rightWheel(PORT_B), colorSensor(PORT_2), gyroSensor(PORT_4), sonarSensor(PORT_3) { // <2>
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
  msg_f("running...", 1);

      int light_val = colorSensor.getBrightness(); 
      //printf("%d\n",light_val);
      int dist_val = (light_val - mThreshold);
      int turn_val = (dist_val*2.0);
      int DGain = (dist_val - light_val);
      leftWheel.setPWM((pwm+(turn_val-DGain))*0.5);
      rightWheel.setPWM((pwm-(turn_val+DGain))*0.5);
    
  
  
  

}
#include "Tracer.h"
#include "ColorSensor.h"
#include <GyroSensor.h>
#include "Clock.h"
#include <SonarSensor.h>
#include "ev3api.h"
#include <math.h>


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
  int PWM = 50;
  leftWheel.setPWM(PWM);
  rightWheel.setPWM(PWM);

}

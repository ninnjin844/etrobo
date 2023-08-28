#include "DoubleLoop.h"
#include "ColorSensor.h"
#include <GyroSensor.h>
#include "Clock.h"
#include <SonarSensor.h>
#include <Clock.h>
//#include "lego_spike_library.h"

DoubleLoop::DoubleLoop():

  leftWheel(PORT_C), rightWheel(PORT_B), colorSensor(PORT_2), gyroSensor(PORT_4), sonarSensor(PORT_3) { // <2>
}

void DoubleLoop::init() {
  init_f("DoubleLoop");
}

void DoubleLoop::terminate() {
  msg_f("Stopped.", 1);
  leftWheel.stop();  // <1>
  rightWheel.stop();
}


void DoubleLoop::run() {
    while (true) {
        int currentAngle = gyroSensor.getAngle();
        //float angle_degree = get_angle /360 ;
        
        

        
       
        
          printf("degree: %d\n", currentAngle);
          leftWheel.setPWM(-50);
          rightWheel.setPWM(50);
          
          
          if(currentAngle==90)
          {
            leftWheel.stop();
            rightWheel.stop();
            clock.sleep(10*1000);
            
          }
        
       
        
        /*if(currentAngle <90)
        {
          leftWheel.stop();
          rightWheel.stop();
          break;
        }*/
        
          

        }
       
       
    }


  

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
  
  
  //int currentAngle = gyroSensor.getAngle();
  
  int base_angle = 0;
  int pwm = 40;
  
      
      
     
    
   
      while(true)
      {
        
            //leftWheel.setPWM(pwm);
            //rightWheel.setPWM(pwm);
        while(true)
        {
             
          
          int currentAngle = gyroSensor.getAngle();
          int angle_error = (currentAngle + base_angle);
        
          if(currentAngle <0)
          {
            int turn_val = (angle_error/3);
            //47
            leftWheel.setPWM(43-turn_val);
            rightWheel.setPWM(47+turn_val);
            
          }else if(currentAngle >0)
          {
            int turn_val = -(angle_error/3);   // diveded by 3
            leftWheel.setPWM(43+turn_val);
            rightWheel.setPWM(47-turn_val);
            
            
            
        
          }else if(currentAngle == 0)
          {
            leftWheel.setPWM(47);
            rightWheel.setPWM(47);
          }
          
        }
          
        
      }
  
      
      
  
  
  

}

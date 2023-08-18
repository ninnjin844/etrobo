#include "DoubleLoop.h"
#include <ColorSensor.h>
#include <GyroSensor.h>
#include <Clock.h>
#include <stdint.h>




DoubleLoop::DoubleLoop():

  leftWheel(PORT_C), rightWheel(PORT_B), colorSensor(PORT_2), gyroSensor(PORT_4){ // <2>
}

void DoubleLoop::init() {
  init_f("DoubleLoop");
}

void DoubleLoop::terminate() {
  msg_f("Stopped.", 1);
  leftWheel.stop();  // <1>
  rightWheel.stop();
}


void DoubleLoop::run() 
{
        msg_f("running...", 1);
        int colorid=colorSensor.getColorNumber();
      //printf("%d\n",colorid);
      int16_t gyro_angle=gyroSensor.getAngle();
      //printf("%d\n",gyro_angle);


      //int blueScanCount = 0;
     
      if(colorid==2)
      {
        leftWheel.stop();
      rightWheel.stop();
      //gyroSensor.reset();
      
      while(true)
    {
      int turn_speed = 10;
      leftWheel.setPWM(turn_speed);
      rightWheel.setPWM(-(turn_speed));
      break;
    }
      
       
      
      if(colorid == 1)
      {
       leftWheel.setPWM(PWM);
      rightWheel.setPWM(PWM);
      }
      

    }
}
  
        
       

        
         
          
        
        
           
      
      
      
        
       
        
        
        

        
       

        
         
         

        
        
        
      

       

  

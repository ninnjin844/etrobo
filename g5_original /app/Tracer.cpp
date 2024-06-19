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


void Tracer::calibration() {
  msg_f("calibrating...", 1);
  
  
  calibration_program();

  

 
  
}


  

 
  


void Tracer::run() 

{
  
  msg_f("running...", 1);
  ev3_sensor_config(EV3_PORT_2, COLOR_SENSOR);
   int target_line = calibration_program();
   //int target_line = 90;
  
   
   
   //run time 34 seconds

  



      int PWM = 40;


      
      
       //left course
      int light_val = colorSensor.getBrightness();
      int dist_val = (light_val - target_line);
      int turn_val = (dist_val*2);//2.3
      /*int DGain = 1.3;//2
      int turn_speed_PWM = (dist_val)*1;//1
      
      int left_motor_rate =(PWM+turn_speed_PWM)+(turn_val*DGain)+dist_val;
      int right_motor_rate =(PWM-turn_speed_PWM)-(turn_val*DGain)+dist_val;
      //printf("target line: %d,left: %d, right: %d\n",target_line,left_motor_rate,right_motor_rate);
      leftWheel.setPWM(left_motor_rate*1.5);
      rightWheel.setPWM(right_motor_rate*1.5);*/
      leftWheel.setPWM(PWM+turn_val);
      rightWheel.setPWM(PWM-turn_val);
    
      
      /*
     
      //right course
      int light_val = colorSensor.getBrightness();
      int dist_val = (light_val - target_line);
      int turn_val = (dist_val*2);//2.3
      int DGain = 1.3;//2
      int turn_speed_PWM = (dist_val)*1;//1
      
      int left_motor_rate =(PWM+turn_speed_PWM)+(turn_val*DGain)+dist_val;
      int right_motor_rate =(PWM-turn_speed_PWM)-(turn_val*DGain)+dist_val;
      leftWheel.setPWM(right_motor_rate*1.5);//1.5
      rightWheel.setPWM(left_motor_rate*1.5);
      */
   

   
   
  

}

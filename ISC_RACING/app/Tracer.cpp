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
  ev3_sensor_config(EV3_PORT_2, COLOR_SENSOR);

  const char *path = "target_line.txt";
   FILE *file = fopen(path, "r");
  if (file == NULL) {
        perror("Error opening file");
        
    }
    
    
    int target_line;
    if (fscanf(file, "%2d", &target_line) == 1) { // %2d reads up to 2 digits
        //printf("target_line: %d\n", target_line);
    } else {
        printf("Error reading integer from file\n");
    }

    // Close the file
    fclose(file);
    
    
    //right course
      //int PWM = pwm;
      //int light_val = colorSensor.getBrightness();
      //printf("%d",light_val);
      //int dist_val = (light_val - target_line);
      //int turn_val = (dist_val*1.5);//2.3
      //int DGain = dist_val*turn_val;//2
      //int turn_speed_PWM = (dist_val)*1;//1
      //int Left_power = (PWM+turn_val);
      //int Right_power = (PWM-turn_val);
      //printf("debug: left power %d right power %d\n",Left_power,Right_power);
      
      
      
      
      //leftWheel.setPWM(Left_power);//1.5
     // rightWheel.setPWM(Right_power);

      
   
   //zig-zag run
   
    if(colorSensor.getBrightness() <= target_line) { // <1>
    leftWheel.setPWM(0);
    rightWheel.setPWM(pwm);
  } else {   // <2>
    leftWheel.setPWM(pwm);
    rightWheel.setPWM(0);
    
  }
    
      


   
}

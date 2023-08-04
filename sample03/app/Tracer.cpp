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
  int sonar_dist = sonarSensor.getDistance	();
 

  if(sonar_dist<=5)
  {
    while (1)
    {
      msg_f("running...", 1);
      int light_val = colorSensor.getBrightness(); //mThreshold
      int dist_val = (light_val - mThreshold);
      int turn_val = (dist_val*2);
      leftWheel.setPWM(pwm+turn_val);
      rightWheel.setPWM(pwm-turn_val);
      printf("%d\n",light_val);
      //printf("走れーーー\n");
      int colorid=colorSensor.getColorNumber();
      //printf("%d\n",colorid);
      int16_t gyro_angle =gyroSensor.getAngle();
      printf("%d\n",gyro_angle);

      //int blueScanCount = 0;

      if(colorid==2)
      {
      leftWheel.stop();
      rightWheel.stop();

      gyroSensor.reset();

      leftWheel.setPWM(pwm/2);
      rightWheel.setPWM(-(pwm)/2);
      }
    }
  
  }
}
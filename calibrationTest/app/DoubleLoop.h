#include "Motor.h"       // <1>
#include "ColorSensor.h" // <2>
#include "util.h"        // <3>
#include <GyroSensor.h>
#include <Clock.h>
#include <SonarSensor.h>

//#include <stdio.h>  //printf使うため


//#include "ev3rt.h"

using namespace ev3api;  // <4>

class DoubleLoop {  // <1>
public:
  DoubleLoop();
  void run();       // <2>
  void init();
  void terminate();

private:
  Motor leftWheel;
  Motor rightWheel;
  ColorSensor colorSensor;
  GyroSensor gyroSensor; 
  SonarSensor sonarSensor;
  Clock clock;
// <3>
//const int8_t mThreshold = 20;  // <4>
/*#ifndef MAKE_RASPIKE
  const int8_t pwm = (Motor::PWM_MAX) / 6;
#else
  const int8_t pwm = 60;
#endif*/
int PWM = 60;
};

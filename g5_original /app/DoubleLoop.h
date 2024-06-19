#include "Motor.h"       // <1>
#include "ColorSensor.h" // <2>
#include "util.h"        // <3>
#include <GyroSensor.h>
#include <Clock.h>
#include <SonarSensor.h>
#include <limits.h>
#include <stdio.h>

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




int PWM = 60;
};

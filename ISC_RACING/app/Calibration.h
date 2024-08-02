#include "Motor.h"       // <1>
#include "ColorSensor.h" // <2>
#include "util.h"        // <3>
#include <GyroSensor.h>
#include <Clock.h>
#include <SonarSensor.h>
#include <limits.h>
#include <stdio.h>
#include <limits.h>
#include <stdio.h>
#include <math.h>

//#include <stdio.h>  //printf使うため


//#include "ev3rt.h"

using namespace ev3api;  // <4>

class Calibration {  // <1>
public:
  Calibration();
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



int arr[2000];
int N = 2000;
int max = arr[0];
int min = arr[0];




 
 


};

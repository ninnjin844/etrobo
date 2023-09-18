#include "DoubleLoop.h"
#include "ColorSensor.h"
#include <GyroSensor.h>
#include "Clock.h"
#include <SonarSensor.h>
#include <stdio.h>
#include <parameters.h>
#include "ev3api.h"

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
      float wheelDiameter = 5.6; // ホイールの直径（単位: センチメートル）
    float wheelCircumference = wheelDiameter * 3.14159265359; // ホイールの周囲の距離（単位: センチメートル）
      int targetDistance = 40000;//40メートル = 4000センチメートル
          ev3_motor_steer(EV3_PORT_C, EV3_PORT_B, 50, 0);
         
    while (true) {
          
          int currentCountC = ev3_motor_get_counts(EV3_PORT_C);
          int currentCountB = ev3_motor_get_counts(EV3_PORT_B);
            //printf("Current Counts: C=%d, B=%d\n", currentCountC, currentCountB);
          if ((currentCountC + currentCountB) * wheelCircumference / 2 >= targetDistance) {
            ev3_motor_stop(EV3_PORT_C, true); // モーターCを停止
            ev3_motor_stop(EV3_PORT_B, true); // モーターBを停止
            break;
        }
          
          
        }
       
        ext_tsk();
    }


  


  

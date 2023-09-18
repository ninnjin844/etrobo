#include "DoubleLoop.h"
#include "ColorSensor.h"
#include <GyroSensor.h>
#include "Clock.h"
#include <SonarSensor.h>
#include <Clock.h>
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
 
 
         
    while (true) {

          int minValue = 42; // 初期値を高めに設定
      int maxValue = 0;   // 初期値を低めに設定
        // カラーセンサーから値を読み取る
        int sensorValue = colorSensor.getBrightness();
         // 最小値と最大値を更新
        if (sensorValue < minValue) {
            minValue = sensorValue;
        }
        if (sensorValue > maxValue) {
            maxValue = sensorValue;
        }
          

           int Count = 515;
         leftWheel.setPWM(50);
         rightWheel.setPWM(-50);
          int currentCountC = ev3_motor_get_counts(EV3_PORT_C);
         
            //printf("Current Counts: C=%d\n", currentCountC);
          if (currentCountC >= Count ) {
            ev3_motor_stop(EV3_PORT_C, true); // モーターCを停止
            ev3_motor_stop(EV3_PORT_B, true); // モーターBを停止
            break;
        }
           int mThreshold = (maxValue + minValue)/2;
             printf("%d\n",mThreshold);
          
        }
       
        ext_tsk();
      
      
    }


    
       



  

#include <stdio.h>


//カラーセンサーピン
#define color_sensor_pin 1
//左モーターピン
#define left_motor_pin 2
//右モーターピン
#define right_motor_pin 3
//タッチセンサーピン
#define force_sensor_pin 4
//波センサーピン
#define haptic_sensor_pin 5
//通信ポートピン
#define serial_port_pin 6
//モーターの速度
#define base_speed 100
//ラインの目標値


/*
//キャリブレーション

void calibration()
{
    int maximum = 0;
analogwrite(left_motor_pin,250);
analogwrite(right_motor_pin,-250);
delay(3000);
analogwrite(left_motor_pin,-250);
analogwrite(right_motor_pin,250);
delay();
if(color_sensor_pin>maximum)
    {
        int maximum = (color_sensor_pin)
    }

}*/
void lineTrace()
{
    
    int target_line = 9;
    //ラインセンサーの値を読み取る
    int SensorValue = analogRead(color_sensor_pin);
    //ラインがある場合はライントレース
    if ( SensorValue> target_line )
    {
        digitalWrite(left_motor_pin, 250);
        digitalWrite(right_motor_pin, 0);
    }
    else
    {
        digitalWrite(left_motor_pin, 0);
        digitalWrite(right_motor_pin, 250);
    }
    return 0;

}


/*void doubleLoop()
{

}

void treasureHunt()
{

}*/

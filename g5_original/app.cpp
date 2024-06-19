#include "app.h" // <1>
#include "Tracer.h" // <2>
#include "Clock.h"  // <3>
#include "DoubleLoop.h"
#include <ColorSensor.h>
#include "ev3api.h"
#include <math.h>
#include <Motor.h>
#include <TouchSensor.h>
#include <SonarSensor.h>
#include <math.h>
#include <stdio.h>
#include <GyroSensor.h>



using namespace ev3api;

Tracer tracer;  // <4>
Clock clock; 
DoubleLoop doubleloop; 
ColorSensor colorSensor(PORT_2);
Motor leftWheel(PORT_C);
Motor rightWheel(PORT_B);
TouchSensor touchSensor(PORT_1);
SonarSensor sonarSensor(PORT_3);
GyroSensor gyroSensor(PORT_4);
// <5>


typedef struct {
    int h;
    int s;
    int v;
} HSVValues;

void rgbToHsv(int r, int g, int b, float *h, float *s, float *v) {
    float min, max, delta;

    min = fmin(fmin(r, g), b);
    max = fmax(fmax(r, g), b);
    *v = max; // V is max color value

    delta = max - min;

    if (max != 0) {
        *s = delta / max; // S is saturation
    } else {
        // R, G, and B are all 0, so S is 0 and H is undefined
        *s = 0;
        *h = -1;
        return;
    }

    if (delta == 0) {
        *h = 0; // H is undefined when S is 0
    } else {
        if (r == max) {
            *h = (g - b) / delta + (g < b ? 6 : 0);
        } else if (g == max) {
            *h = 2 + (b - r) / delta;
        } else {
            *h = 4 + (r - g) / delta;
        }

        *h /= 6; // Normalize H to be in [0, 1]
    }
}

    
HSVValues rgbConverted(void)
{
rgb_raw_t rgb ;
      colorSensor.getRawColor(rgb);
      //int r = rgb.r;
      //int g = rgb.g;
      //int b = rgb.b;

      // Convert RGB to HSV
      
    float h, s, v;
    rgbToHsv(rgb.r, rgb.g, rgb.b, &h, &s, &v);
    int hConvert = (int)round(h);
    int sConvert = (int)round(s);
    int vConvert = (int)round(v);
      //printf("Raw RGB Values: R=%d, G=%d, B=%d\n", r, g, b);
       //printf("HSV Values: H=%f, S=%f, V=%f\n", h, s, v);
        //printf("Converted Values: H=%d, S=%d, V=%d\n", hConvert, sConvert, vConvert);
        HSVValues convertedValues;
        convertedValues.h = hConvert;
        convertedValues.s = sConvert;
        convertedValues.v = vConvert;
        //printf("Converted Values: H=%d, S=%d, V=%d\n", convertedValues.h, convertedValues.s, convertedValues.v);
      
        return convertedValues;
}


void tracer_task(intptr_t exinf) {
  
   
    tracer.run(); // <2>
          
      
    ext_tsk();

  
}


void calibration_task(intptr_t exinf) { // <1>

 tracer.calibration();
 ext_tsk();
  
 }

 
void doubleloop_task(intptr_t exinf)
{
    leftWheel.stop();
    rightWheel.stop();
  
  //doubleloop.run();
  //ext_tsk();
}



   
void main_task(intptr_t unused)
 
{       ev3_sensor_config(EV3_PORT_1, TOUCH_SENSOR);
      ev3_sensor_config(EV3_PORT_2, COLOR_SENSOR);
     
    
       
while(true)
{ 
          
         
     
          
          
        
      while(true)
      {
            int touch_sensor_middle = ev3_button_is_pressed(ENTER_BUTTON);
                 
          int touch_sensor_right = ev3_button_is_pressed(RIGHT_BUTTON);
            
      
          if( touch_sensor_right == true)
          { 
                tracer.init();
                tracer.calibration();
                sta_cyc(CALIBRATION_CYC);
                
                
          }
           clock.sleep(100000);
      
          if( touch_sensor_middle == true)
          {  
            
              tracer.init(); 
              sta_cyc(TRACER_CYC);
              
              
              
          }
        
          
          clock.sleep(100000);
          
          
          
        }
      
    
          
    }
          
      
   
    
  while (!ev3_button_is_pressed(LEFT_BUTTON)) 
  { // <1>
    clock.sleep(100*1000);  
  }

  stp_cyc(CALIBRATION_CYC);
  stp_cyc(DOUBLELOOP_CYC); // <3>
  doubleloop.terminate(); 
  stp_cyc(TRACER_CYC);
  tracer.terminate(); 
  ext_tsk(); // <5>
  
  

  
}
  



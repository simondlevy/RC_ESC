/*
  ESC_Calibration
    It's important to calibrate the ESC with the values (uS / microseconds) he will expect to be for Min and Max speed.
    This one require a little procedure:  
      1 - Load the sketch to your Arduino board
      2 - Connect your ESC to the Arduino board
      3 - Power your Arduino board
      4 - Once the LED (LED_PIN) is HIGH/ON connect the power to your ESC, you have 5sec to do so
      5 - Once the LED is LOW/OFF the calibration should be done
      6 - Should now be calibrated between 1000us and 2000us
    
  27 April 2017
  by Eric Nantel
  
  Servo & Knob links
  http://www.arduino.cc/en/Tutorial/Knob
  http://people.interaction-ivrea.it/m.rinott
 */

#include "ESC.h"

static const uint8_t LED_PIN = 13;

static const uint8_t ACTIVE_STATE = LOW;

ESC myESC (9, 1000, 2000, 500);   

void setup()
{
  pinMode(LED_PIN, OUTPUT);       
  digitalWrite(LED_PIN, ACTIVE_STATE);    
  myESC.calib();                 
  myESC.stop();                  
  digitalWrite(LED_PIN, !ACTIVE_STATE);    
}

void loop()
{
}

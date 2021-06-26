/*
  ESC calibration for STM32L4 boards (Tlera Butterfly et al.)

    It's important to calibrate the ESC with the values (uS / microseconds) he will expect to be for Min and Max speed.
    This one require a little procedure:  

      1 - Load the sketch to your Arduino board
      2 - Connect your ESC to the Arduino board
      3 - Power your Arduino board
      4 - Once the LED on, connect the power to your ESC, you have 5sec to do so
      5 - Once the LED is off, the calibration should be done
      6 - Should now be calibrated between 1000us and 2000us
    
  27 April 2017
  by Eric Nantel
 */

#include "ESC.h"

static const uint8_t LED_PIN = 13;
static const uint8_t MOTOR_PIN = 25;

ESC esc(MOTOR_PIN, 1000, 2000, 500);   

void setup()
{
  pinMode(LED_PIN, OUTPUT);       
  digitalWrite(LED_PIN, LOW);    
  esc.calib();                 
  esc.stop();                  
  digitalWrite(LED_PIN, HIGH);    
}

void loop()
{
}

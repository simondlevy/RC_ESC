/*
  ESC_Ramp
    Based on the Sweep example in the Servo library, this allow a ramp up and down of the ESC speed based on the Min and Max values.
    The Min and Max speed are defined so you can change them at one location and it will be used in the ramp as well.
    
  27 April 2017
  by Eric Nantel
 */

#include "ESC.h"

static const uint16_t MIN_VAL = 1000;
static const uint16_t MAX_VAL = 2000;
static const uint16_t ARM_VAL = 500;

ESC esc(25, MIN_VAL, MAX_VAL, ARM_VAL);    

static uint16_t val;                       

void setup() 
{
  esc.arm();                                            // Send the Arm value so the ESC will be ready to take commands
  delay(5000);                                            // Wait for a while
}

void loop() 
{
  for (val = MIN_VAL; val <= MAX_VAL; val += 1) {  // goes from 1000 microseconds to 2000 microseconds
    esc.speed(val);                                    // tell ESC to go to the val speed value
    delay(10);                                            // waits 10ms for the ESC to reach speed
  }

  delay(1000);

  for (val = MAX_VAL; val >= MIN_VAL; val -= 1) {  // goes from 2000 microseconds to 1000 microseconds
    esc.speed(val);                                    // tell ESC to go to the val speed value
    delay(10);                                            // waits 10ms for the ESC to reach speed  
   }

  delay(5000);                                            // Wait for a while befor restart
}

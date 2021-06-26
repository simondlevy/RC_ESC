/*
  ESC_Ramp
    Based on the Sweep example in the Servo library, this allow a ramp up and down of the ESC speed based on the Min and Max values.
    The Min and Max speed are defined so you can change them at one location and it will be used in the ramp as well.
    
  27 April 2017
  by Eric Nantel
 */

#include "ESC.h"

static const uint16_t SPEED_MIN = 1000;
static const uint16_t SPEED_MAX = 2000;

ESC myESC (25, SPEED_MIN, SPEED_MAX, 500);    

static uint16_t oESC;                       

void setup() 
{
  myESC.arm();                                            // Send the Arm value so the ESC will be ready to take commands
  delay(5000);                                            // Wait for a while
}

void loop() 
{
  for (oESC = SPEED_MIN; oESC <= SPEED_MAX; oESC += 1) {  // goes from 1000 microseconds to 2000 microseconds
    myESC.speed(oESC);                                    // tell ESC to go to the oESC speed value
    delay(10);                                            // waits 10ms for the ESC to reach speed
  }

  delay(1000);

  for (oESC = SPEED_MAX; oESC >= SPEED_MIN; oESC -= 1) {  // goes from 2000 microseconds to 1000 microseconds
    myESC.speed(oESC);                                    // tell ESC to go to the oESC speed value
    delay(10);                                            // waits 10ms for the ESC to reach speed  
   }

  delay(5000);                                            // Wait for a while befor restart
}

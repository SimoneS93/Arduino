/**
 * EVERY lib example: exec a piece of code when not on time
 * @author Salerno Simone
 */
 
#include "EVERY.h"

void setup() {
  Serial.begin(9600);
  
  //init timers
  EVERY_INIT();
}

void loop() {  
  /*
   * @param index The timer index, from 0 to 9 (by default)
   * @param interval The timer interval
   */
  EVERY(0, 3000) {
    Serial.println("3 seconds have passed since last tick");
  }
  //since EVERY is translated in an IF at compile time, we can use IF-ELSE construct
  else {
    Serial.println("3 seconds have not elapsed yet");
  }
  
  delay(1);
}

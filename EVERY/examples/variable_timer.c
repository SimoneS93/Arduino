/**
 * EVERY lib example: exec code on variable time
 * @author Salerno Simone
 */
 
#include "EVERY.h"

unsigned int interval = 1000;

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
  EVERY(0, interval) {
    Serial.print("Elapsed ");
    Serial.print(interval);
    Serial.println(" since last tick");
    
    interval += 1000;
  }

  
  delay(1);
}

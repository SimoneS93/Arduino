/**
 * EVERY lib example: exec code on several timers
 * extend max number of distinct timers
 */
 
#define EVERY_MAX_COUNT 20
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
  EVERY(0, 1000) {
    Serial.println("1 second has passed since last tick");
  }
  
  //use a different index
  EVERY(1, 2000) {
    Serial.println("2 seconds have passed since last tick");
  }
  
  //another different index. You don't have to keep a specific order
  //this will cause an error if EVERY_MAX_COUNT is not defined (default is 10, so 0 <= index <= 9)
  EVERY(10, 5000) {
    Serial.println("5 seconds have passed since last tick");
  }
  
  delay(1);
}

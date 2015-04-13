#EVERY

##A library to exec code on time in Arduino

EVERY lets you easily run pieces of code on time with minimal cost (every usage requires about 100 bytes). It is implemented as a macro, not as a function: this means that it is replaced by actual code at compile time (an if-condition), which is good because is fast. On the other side, you completely lose type safety, which means your errors don't get caught on compile time: your code will compile but not work once uploaded!

###How to use
You can find a few examples in the *examples* directory, here's an overview:

 1. A single timer
 <pre><code>#include "EVERY.h"

  void setup() {
    Serial.begin(9600);
    //init timers
    EVERY_INIT();
  }

  void loop() {  
    EVERY(0, 3000) {
      Serial.println("3 seconds have passed since last tick");
    }
    delay(1);
  }</code></pre>
  
 2. Multiple timers:
 <pre><code>#include "EVERY.h"

 void setup() {
   Serial.begin(9600);
    //init timers
    EVERY_INIT();
 }

 void loop() {  
   EVERY(0, 1000) {
     Serial.println("1 second has passed since last tick");
    }
  
    //use a different index
    EVERY(1, 2000) {
      Serial.println("2 seconds have passed since last tick");
    }
   
    //another different index. It doesn't have to be in order
    EVERY(8, 5000) {
      Serial.println("5 seconds have passed since last tick");
    }
   
    delay(1);
}</code></pre>

/**
 * A macro definition to exec code on time
 * @author Salerno Simone
 * @date 2015-04-12
 */
 
#ifndef _EVERY_H_
  #define _EVERY_H_ 1
  
  /**
   * Define the maximum number of distinct timers (user-overridable)
   */
  #ifndef EVERY_MAX_COUNT
    #define EVERY_MAX_COUNT 10
  #endif
  
  /**
   * Hold the current time in millis()
   */
  unsigned long __EVERY_NOW;
  
  /**
   * Keep track of last execution for every timer
   */
  unsigned long __EVERY_PAST[EVERY_MAX_COUNT];
  
  /**
   * Init all timers with current time
   */
  #define EVERY_INIT() for (unsigned long now = millis(), i = 0; i < EVERY_MAX_COUNT; i++) __EVERY_PAST[i] = now;
  
  /**
   * Check if interval is elapsed since last execution
   * To distinguish between timers, you have to pass a unique timer index
   * from 0 to EVERY_MAX_COUNT-1
   * NOTE: (__EVERY_PAST[i] = __EVERY_NOW) >= 0 is a fake condition since __EVERY_NOW is always >= 0. It's used as an inline assignement.
   */
  #define EVERY(i, interval) (__EVERY_NOW = millis()); if (__EVERY_NOW - __EVERY_PAST[i] >= interval && (__EVERY_PAST[i] = __EVERY_NOW) >= 0)
  
#endif

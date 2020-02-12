/*
  MLoop.h - Main Loop for Arduino
*/

#ifndef MLOOP_H
#define MLOOP_H

#include <Arduino.h>

#include "MlTimer.h"


#define ML_TIMER_MAX 8


class MLoop
{
public:
  MLoop();
  bool add_timer(MlTimer *timer);
  void once(void);
  void run(void);
private:
  size_t timers_len;
  MlTimer *timers[ML_TIMER_MAX];
};


#endif /* MLOOP_H */

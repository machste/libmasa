#include "MLoop.h"


MLoop::MLoop()
  : timers_len(0)
{}

bool MLoop::add_timer(MlTimer *timer)
{
  if (timer == NULL || timer->added) {
    return false;
  }
  if (timers_len < ML_TIMER_MAX - 1) {
    timers[timers_len++] = timer;
    timer->added = true;
    return true;
  } else {
    return false;
  }
}

void MLoop::run(void)
{
  while(true) {
    unsigned long now = millis();
    for (int i = 0; i < timers_len; i++) {
      if (timers[i]->active && timers[i]->due <= now) {
        timers[i]->execute();
      }
    }
  }
}

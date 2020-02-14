/*
  MlTimer.h - Timer for the Main Loop
*/

#ifndef ML_TIMER_H
#define ML_TIMER_H

#include <Arduino.h>

#include "MlAction.h"


class MlTimer : public MlAction
{
public:
  typedef enum {
    MODE_SINGLE,
    MODE_CONTINUOUS
  } Mode;
  typedef void (*RunCb)(MlTimer *timer, void *arg);

  MlTimer(Mode mode, unsigned long ms);
  MlTimer(Mode mode, unsigned long ms, RunCb cb, void *arg=NULL);
  bool start(void);
  bool stop(void);

protected:
  virtual void run(void);

private:
  Mode mode;
  unsigned long ival;
  unsigned long due;
  RunCb run_cb;
  void *run_arg;

  bool check(unsigned long now);
  void done(void);
};

#endif /* ML_TIMER_H */

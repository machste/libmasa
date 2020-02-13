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

  MlTimer(MlTimer::Mode mode, unsigned long ms);
  MlTimer(MlTimer::Mode mode, unsigned long ms, MlAction::Callback run_cb);
  bool start(void);
  bool stop(void);

protected:
  virtual void run(void);

private:
  MlTimer::Mode mode;
  unsigned long ival;
  unsigned long due;
  bool check(unsigned long now);
  void done(void);

  friend class MLoop;
};

#endif /* ML_TIMER_H */

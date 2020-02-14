#include "MlTimer.h"


MlTimer::MlTimer(Mode mode, unsigned long ms)
  : mode(mode), ival(ms), due(0)
{}

MlTimer::MlTimer(Mode mode, unsigned long ms, RunCb cb, void *arg)
  : mode(mode), ival(ms), due(0), run_cb(cb), run_arg(arg)
{}

bool MlTimer::start(void)
{
  if (!added) {
    return false;
  }
  due = millis() + ival;
  active = true;
  return true;
}

bool MlTimer::stop(void)
{
  active = false;
}

bool MlTimer::check(unsigned long now)
{
  return now >= due;
}

void MlTimer::run(void)
{
  if (run_cb != NULL) {
    run_cb(this, run_arg);
  }
}

void MlTimer::done(void)
{
  if (mode == MODE_CONTINUOUS) {
    due = millis() + ival;
  } else {
    active = false;
  }
}

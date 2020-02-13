#include "MlTimer.h"


MlTimer::MlTimer(MlTimer::Mode mode, unsigned long ms)
  : mode(mode), ival(ms), due(0)
{}

MlTimer::MlTimer(MlTimer::Mode mode, unsigned long ms,
    MlAction::Callback run_cb)
  : MlAction(run_cb), mode(mode), ival(ms), due(0)
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

void MlTimer::done(void)
{
  if (mode == MODE_CONTINUOUS) {
    due = millis() + ival;
  } else {
    active = false;
  }
}

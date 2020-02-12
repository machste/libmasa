#include "MlTimer.h"


MlTimer::MlTimer(MlTimer::Mode mode, unsigned long ms)
  : mode(mode), cb(NULL), ival(ms), added(false), active(false), due(0)
{}

MlTimer::MlTimer(MlTimer::Mode mode, unsigned long ms, MlTimer::Callback cb)
  : mode(mode), cb(cb), ival(ms), added(false), active(false), due(0)
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

void MlTimer::run(void)
{
  if (cb != NULL) {
    cb(*this);
  }
}

void MlTimer::execute(void)
{
  run();
  if (mode == MODE_CONTINUOUS) {
    due = millis() + ival;
  } else {
    active = false;
  }
}

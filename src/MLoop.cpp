#include "MLoop.h"

#include "MlAction.h"


MLoop::MLoop(void)
  : actions_len(0)
{}

bool MLoop::add(MlAction *action)
{
  if (action == NULL || action->added) {
    return false;
  }
  if (actions_len < ML_ACTIONS_MAX - 1) {
    actions[actions_len++] = action;
    action->added = true;
    return action->add(this);
  } else {
    return false;
  }
}

void MLoop::once(void)
{
  unsigned long now = millis();
  for (int i = 0; i < actions_len; i++) {
    if (actions[i]->active && actions[i]->check(now)) {
      actions[i]->run();
      actions[i]->done();
    }
  }
}

void MLoop::run(void)
{
  while(true) {
    once();
  }
}

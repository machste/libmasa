#include "MlAction.h"


MlAction::MlAction(void)
  : added(false), active(false), run_cb(NULL)
{}

MlAction::MlAction(MlAction::Callback run_cb)
  : added(false), active(false), run_cb(run_cb)
{}

void MlAction::run(void)
{
  if (run_cb != NULL) {
    run_cb(this);
  }
}

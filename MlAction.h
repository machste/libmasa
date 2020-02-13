/*
  MlAction.h - Action for the Main Loop
*/

#ifndef ML_ACTION_H
#define ML_ACTION_H

#include <Arduino.h>

#include "MLoop.h"


class MlAction
{
public:
  typedef void (*Callback)(MlAction *self);

  MlAction(void);
  MlAction(MlAction::Callback run_cb);
  bool is_added(void) { return added; };
  bool is_active(void) { return active; };

protected:
  bool added;
  bool active;

  virtual bool add(MLoop *mloop) {};
  virtual bool check(unsigned long now) { return true; };
  virtual void run(void);
  virtual void done(void) {};

private:
  MlAction::Callback run_cb;

  friend class MLoop;
};

#endif /* ML_ACTION_H */

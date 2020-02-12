/*
  MlTimer.h - Timer for the Main Loop
*/

#ifndef MLTIMER_H
#define MLTIMER_H

#include <Arduino.h>


class MlTimer
{
public:
  typedef enum {
    MODE_SINGLE,
    MODE_CONTINUOUS
  } Mode;
  typedef void (*Callback)(MlTimer &self);

  MlTimer(MlTimer::Mode mode, unsigned long ms);
  MlTimer(MlTimer::Mode mode, unsigned long ms, MlTimer::Callback cb);
  bool is_added(void) { return added; };
  bool is_active(void) { return active; } ;
  bool start(void);
  bool start(unsigned long ms);
  bool stop(void);
protected:
  virtual void run(void);
private:
  MlTimer::Mode mode;
  MlTimer::Callback cb;
  unsigned long ival;
  bool added;
  bool active;
  unsigned long due;
  void execute(void);
  friend class MLoop;
};

#endif /* MLOOP_H */

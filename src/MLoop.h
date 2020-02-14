/*
  MLoop.h - Main Loop for Arduino
*/

#ifndef M_LOOP_H
#define M_LOOP_H

#include <Arduino.h>


#define ML_ACTIONS_MAX 16


class MlAction;


class MLoop
{
public:
  MLoop(void);
  bool add(MlAction *action);
  void once(void);
  void run(void);

private:
  size_t actions_len;
  MlAction *actions[ML_ACTIONS_MAX];
};

#endif /* M_LOOP_H */

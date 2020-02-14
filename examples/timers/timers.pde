#include <MLoop.h>
#include <MlTimer.h>

void digitalToggle(int pin)
{
  digitalWrite(pin, !digitalRead(pin));
}

void timer1_cb(MlTimer *timer, void *arg)
{
  Serial.print("timer1: ");
  Serial.println(millis());
  digitalToggle(LED_BUILTIN);
}

void timer2_cb(MlTimer *timer, void *arg)
{
  Serial.print("timer2: ");
  Serial.println(millis());
  digitalToggle(LED_BUILTIN);
}

void setup()
{
  Serial.begin(115200);
  Serial.println("libmasa: timer example");
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
  MLoop mloop;
  MlTimer timer1(MlTimer::MODE_CONTINUOUS, 1000, timer1_cb);
  mloop.add(&timer1);
  timer1.start();
  MlTimer timer2(MlTimer::MODE_CONTINUOUS, 1700, timer2_cb);
  mloop.add(&timer2);
  timer2.start();
  mloop.run();
}
#define RIGHT_PWM 6
#define RIGHT_DC  7
#define LEFT_PWM  5
#define LEFT_DC   4

#include "engine.h"
#include "go.h"

void setup() {
  setup_pins();
}

void loop() {
  delay(3000);
  go(STRAIGHT);
  delay(500);
  turn(RIGHT);
  delay(500);
  go(BACK);
  delay(500);
  turn(LEFT);
  delay(500);
  stop_all();
  delay(5000);
}

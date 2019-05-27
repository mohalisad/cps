#define RIGHT_PWM 6
#define RIGHT_DC  7
#define LEFT_PWM  5
#define LEFT_DC   4

#include "engine.h"
#include "go.h"

void setup() {
  setup_pins();
  Serial.begin(9600);
}

void loop() {
  delay(5000);
  move_to(128,180);
  delay(5000);
  stop_all();
}

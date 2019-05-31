#define RIGHT_PWM 6
#define RIGHT_DC  7
#define LEFT_PWM  5
#define LEFT_DC   4

#include "engine.h"
#include "go.h"
#include "command.h"

void setup() {
  setup_pins();
  init_serial(9600);
}

void loop() {
  byte command[2];
  if(Serial.available() == 2){
    command[0] = Serial.read();
    command[1] = Serial.read();
    parse_command(command);
  }
}

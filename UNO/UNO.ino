#define RIGHT_PWM1 10
#define RIGHT_PWM2 11
#define LEFT_PWM1  5
#define LEFT_PWM2  6

#include "engine.h"
#include "go.h"
#include "command.h"

byte command[COMMAND_LENGTH];

void setup() {
  setup_pins();
  init_serial(9600);
}

void loop() {
  read_command(command);
  if(valid_command(command)){
    parse_command(command);
  }
  delay(4);
}

#define RIGHT_PWM1 10
#define RIGHT_PWM2 11
#define LEFT_PWM1  5
#define LEFT_PWM2  6

#include "engine.h"
#include "go.h"
#include "command.h"

void setup() {
  setup_pins();
  init_serial(9600);
}

void loop() {
   byte command[2];
   if(Serial.available() >= 2){
     command[0] = Serial.read();
     command[1] = Serial.read();
     parse_command(command);
   }
}

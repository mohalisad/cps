#define RIGHT_PWM 6
#define RIGHT_DC  7
#define LEFT_PWM  5
#define LEFT_DC   4

#include "engine.h"
#include "go.h"

#define JAVA_STOP         0
#define JAVA_MOVE         1
#define JAVA_REVERSE_MOVE 2
#define JAVA_GO_STRAIGHT  3
#define JAVA_GO_BACK      4
#define JAVA_TURN_RIGHT   5
#define JAVA_TURN_LEFT    6

void parse_command(byte inp[2]){
  byte speedy,angle
  speedy = inp[0] >>6;
  angle  = (inp[0]&0x3F);
  angle  = angle*3;

}

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

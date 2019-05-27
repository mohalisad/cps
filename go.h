#define MOVE_SPEED  128
#define TURN_SPEED  64

#define STRAIGHT false
#define BACK     true

#define RIGHT true
#define LEFT  false


void go(bool reverse){
  right_motor(reverse,MOVE_SPEED);
  left_motor (reverse,MOVE_SPEED);
}
void turn(bool reverse){
  right_motor(reverse ,TURN_SPEED);
  left_motor (!reverse,TURN_SPEED);
}

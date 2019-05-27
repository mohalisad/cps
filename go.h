#define MOVE_SPEED  128

#define GO_STRAIGHT 0
#define GO_BACK     1
#define TURN_RIGHT  2
#define TURN_LEFT   3

void change_state(byte state,byte speedy = MOVE_SPEED){
  switch(state){
    case GO_STRAIGHT:
      right_motor(false,speedy);
      left_motor (false,speedy);
      break;
    case GO_BACK:
      right_motor(true,speedy);
      left_motor (true,speedy);
      break;
    case TURN_RIGHT:
      right_motor(true ,speedy);
      left_motor (false,speedy);
      break;
    case TURN_LEFT:
      right_motor(false,speedy);
      left_motor (true ,speedy);
      break;
  }
}

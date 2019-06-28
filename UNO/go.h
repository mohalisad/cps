#define MOVE_SPEED  128

#define GO_STRAIGHT 0
#define GO_BACK     1
#define TURN_RIGHT  2
#define TURN_LEFT   3

#define MULTI1 0.6
#define MULTI2 1.5


void change_state(byte state,short speedy = MOVE_SPEED){
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
//angle from 0 to 180
void move_to(short speedy,byte angle = 0,bool reverse = false){
  bool right = false;
  int max_speed,min_speed;
  if (angle > 90){
    angle = angle-90;
    right = true;
  }else{
    angle = 90-angle;
  }
  max_speed = speedy + MULTI1*angle;
  min_speed = speedy - MULTI2*angle;
  if (right){
    right_motor(reverse,min_speed);
    left_motor (reverse,max_speed);
  }else{
    right_motor(reverse,max_speed);
    left_motor (reverse,min_speed);
  }
}

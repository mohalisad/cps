#define MOVE_SPEED  128

#define GO_STRAIGHT 0
#define GO_BACK     1
#define TURN_RIGHT  2
#define TURN_LEFT   3

#define MAX_DEGREE    60
#define MULTIPLICAND  0.3

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
//angle from 0 to 180
void move_to(byte speedy,byte angle = 0,bool reverse = false){
  bool right = false;
  byte max_speed,min_speed;
  if (angle > 90){
    angle = angle-90;
    right = true;
  }else{
    angle = 90-angle;
  }
  angle = min(MAX_DEGREE,angle);
  max_speed = speedy + MULTIPLICAND*angle;
  min_speed = speedy - MULTIPLICAND*angle;
  Serial.println(String(max_speed)+"," + String(min_speed));
  if (right){
    //right_motor(false,min_speed);
    //left_motor (false,max_speed);
  }else{
    //right_motor(false,max_speed);
    //left_motor (false,min_speed);
  }
}

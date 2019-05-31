#define JAVA_STOP         0
#define JAVA_MOVE         1
#define JAVA_REVERSE_MOVE 2
#define JAVA_GO_STRAIGHT  3
#define JAVA_GO_BACK      4
#define JAVA_TURN_RIGHT   5
#define JAVA_TURN_LEFT    6

void parse_command(byte inp[2]){
  byte speedy,angle,mode;
  speedy = inp[0] >>6;
  speedy = speeds[speedy];
  angle  = (inp[0]&0x3F);
  angle  = angle*3;
  mode   = inp[1] >>5;
  switch (mode){
    case JAVA_STOP:
      stop_all();
      break;
    case JAVA_MOVE:
      move_to(speedy,angle);
      break;
    case JAVA_REVERSE_MOVE:
      move_to(speedy,angle,true);
      break;
    case JAVA_GO_STRAIGHT:
      change_state(GO_STRAIGHT,speedy);
      break;
    case JAVA_GO_BACK:
      change_state(GO_BACK,speedy);
      break;
    case JAVA_TURN_RIGHT:
      change_state(TURN_RIGHT,speedy);
      break;
    case JAVA_TURN_LEFT:
      change_state(TURN_LEFT,speedy);
      break;
  }
}

void clear_serial_buffer(){
  while(Serial.available()){
    Serial.read();
  }
}

void init_serial(int baud){
  Serial.begin(baud);
  delay(100);
  clear_serial_buffer();
}
#define JAVA_STOP         0
#define JAVA_MOVE         1
#define JAVA_REVERSE_MOVE 2
#define JAVA_GO_STRAIGHT  3
#define JAVA_GO_BACK      4
#define JAVA_TURN_RIGHT   5
#define JAVA_TURN_LEFT    6

#define COMMAND_LENGTH    4

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

void read_command(byte *command){
  if(Serial.available() >= 1){
    command[0] = Serial.read();
    if(command[0] == 170){
      while(Serial.available() < COMMAND_LENGTH-1);
      command[1] = Serial.read();
      command[2] = Serial.read();
      command[3] = Serial.read();
    }
  }else{
    command[0] = 0;
  }
}

bool valid_command(byte *command){
  if(command[0] == 170){
    if((command[3]&15) == 10){
      return true;
    }
  }
  clear_serial_buffer();
  return false;
}

void parse_command(byte inp[4]){
  byte speedy,angle,mode;
  speedy = inp[1] >>6;
  speedy = speeds[speedy];
  angle  = (inp[1]&0x3F);
  angle  = angle*3;
  mode   = inp[2] >>5;
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

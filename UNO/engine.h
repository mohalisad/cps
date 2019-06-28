#define RIGHT_BIAS 0
#define LEFT_BIAS  0
byte speeds[] = {196,210,232,255};

void setup_pins(){
  pinMode(RIGHT_PWM1, OUTPUT);
  pinMode(RIGHT_PWM2, OUTPUT);
  pinMode(LEFT_PWM1 , OUTPUT);
  pinMode(LEFT_PWM2 , OUTPUT);
}

void stop_right(){
  digitalWrite(RIGHT_PWM1, 0);
  digitalWrite(RIGHT_PWM2, 0);
}
void stop_left(){
  digitalWrite(LEFT_PWM1, 0);
  digitalWrite(LEFT_PWM2, 0);
}
void stop_all(){
  stop_right();
  stop_left();
}

void right_motor(bool reverse,byte motor_speed){
  motor_speed += RIGHT_BIAS;
  if (reverse){
    analogWrite (RIGHT_PWM2, motor_speed);
    digitalWrite(RIGHT_PWM1,           0);
  }else{
    analogWrite (RIGHT_PWM1, motor_speed);
    digitalWrite(RIGHT_PWM2,           0);
  }
}
void left_motor(bool reverse,byte motor_speed){
  motor_speed += LEFT_BIAS;
  if (reverse){
    analogWrite (LEFT_PWM2, motor_speed);
    digitalWrite(LEFT_PWM1,           0);
  }else{
    analogWrite (LEFT_PWM1, motor_speed);
    digitalWrite(LEFT_PWM2,           0);
  }
}

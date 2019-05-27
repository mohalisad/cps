void setup_pins(){
  pinMode(RIGHT_DC , OUTPUT);
  pinMode(RIGHT_PWM, OUTPUT);
  pinMode(LEFT_DC,  OUTPUT);
  pinMode(LEFT_PWM, OUTPUT);
}

void stop_right(){
  digitalWrite(RIGHT_DC , 0);
  digitalWrite(RIGHT_PWM, 0);
}
void stop_left(){
  digitalWrite(LEFT_DC , 0);
  digitalWrite(LEFT_PWM, 0);
}
void stop_all(){
  stop_right();
  stop_left();
}

void right_motor(bool reverse,byte motor_speed){
  if (reverse){
    analogWrite (RIGHT_PWM, 255-motor_speed);
    digitalWrite(RIGHT_DC ,               1);
  }else{
    analogWrite (RIGHT_PWM, motor_speed);
    digitalWrite(RIGHT_DC ,           0);
  }
}
void left_motor(bool reverse,byte motor_speed){
  if (!reverse){
    analogWrite (LEFT_PWM, 255-motor_speed);
    digitalWrite(LEFT_DC ,               1);
  }else{
    analogWrite (LEFT_PWM, motor_speed);
    digitalWrite(LEFT_DC ,           0);
  }
}

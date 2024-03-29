#define RIGHT_BIAS 5
#define LEFT_BIAS  -15
#define MAX_SPEED  255
#define MIN_SPEED  0

byte speeds[] = {205,220,235,250};

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

void right_motor(bool reverse,short motor_speed){
  motor_speed += RIGHT_BIAS;
  motor_speed = min(MAX_SPEED,motor_speed);
  motor_speed = max(MIN_SPEED,motor_speed);
  if (reverse){
    analogWrite (RIGHT_PWM2, motor_speed);
    digitalWrite(RIGHT_PWM1,           0);
  }else{
    analogWrite (RIGHT_PWM1, motor_speed);
    digitalWrite(RIGHT_PWM2,           0);
  }
}
void left_motor(bool reverse,short motor_speed){
  motor_speed += LEFT_BIAS;
  motor_speed = min(MAX_SPEED,motor_speed);
  motor_speed = max(MIN_SPEED,motor_speed);
  if (reverse){
    analogWrite (LEFT_PWM2, motor_speed);
    digitalWrite(LEFT_PWM1,           0);
  }else{
    analogWrite (LEFT_PWM1, motor_speed);
    digitalWrite(LEFT_PWM2,           0);
  }
}

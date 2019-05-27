#define RIGHT_PWM 5
#define RIGHT_DC  4
#define LEFT_PWM  6
#define LEFT_DC   7

#define MOVE_SPEED  128
#define TURN_SPEED  64

#define STRAIGHT false
#define BACK     true

#define RIGHT true
#define LEFT  false

void setup() {
  // put your setup code here, to run once:
  pinMode(RIGHT_DC , OUTPUT);
  pinMode(RIGHT_PWM, OUTPUT);
  pinMode(LEFT_DC, OUTPUT);
  pinMode(LEFT_PWM, OUTPUT);
}
//stop functions
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
//motor functions
void right_motor(bool reverse,byte motor_speed){
  if (!reverse){
    analogWrite (RIGHT_PWM, 255-motor_speed);
    digitalWrite(RIGHT_DC ,               1);
  }else{
    analogWrite (RIGHT_PWM, motor_speed);
    digitalWrite(RIGHT_DC ,           0);
  }
}
void left_motor(bool reverse,byte motor_speed){
  if (reverse){
    analogWrite (LEFT_PWM, 255-motor_speed);
    digitalWrite(LEFT_DC ,               1);
  }else{
    analogWrite (LEFT_PWM, motor_speed);
    digitalWrite(LEFT_DC ,           0);
  }
}
//move function
void go(bool reverse){
  right_motor(reverse,MOVE_SPEED);
  left_motor (reverse,MOVE_SPEED);
}
void turn(bool reverse){
  right_motor(reverse ,TURN_SPEED);
  left_motor (!reverse,TURN_SPEED);
}
void loop() {
  // put your main code here, to run repeatedly:
  delay(3000);
  go(STRAIGHT);
  delay(500);
  turn(RIGHT);
  delay(500);
  go(BACK);
  delay(500);
  turn(LEFT);
  delay(500);
  stop_all();
  delay(5000);
}

//motors logic pins
#define m01 30
#define m02 32
#define m0Pwm 10
#define m11 26
#define m12 28
#define m1Pwm 9
#define m21 22
#define m22 24
#define m2Pwm 8

//encoder pins
#define enc0A 18
#define enc0B 19
#define enc1A 3
#define enc1B 7
#define enc2A 2
#define enc2B 34

//encoder variables
volatile int count0 = 0, prevCount0 = 0, count1 = 0, prevCount1 = 0, count2 = 0, prevCount2 = 0;

//motor pin configuration
void motor_pin_config(){
  pinMode(m01, OUTPUT);
  pinMode(m02, OUTPUT);
  pinMode(m0Pwm, OUTPUT);
  pinMode(m11, OUTPUT);
  pinMode(m12, OUTPUT);
  pinMode(m1Pwm, OUTPUT);
  pinMode(m21, OUTPUT);
  pinMode(m22, OUTPUT);
  pinMode(m2Pwm, OUTPUT);
  
}
//encoder pin configuration
void enc_pin_config(){
  pinMode(enc0A, INPUT);
  pinMode(enc0B, INPUT);
  pinMode(enc1A, INPUT);
  pinMode(enc1B, INPUT);
  pinMode(enc2A, INPUT);
  pinMode(enc2B, INPUT);
}
//forward and reverse
// dir = 1 (forward), dir = -1 (back)
void move(int speed, int dir){
  
  if(dir > 0){
    digitalWrite(m01, HIGH);
    digitalWrite(m02, LOW); 
    digitalWrite(m11, LOW);
    digitalWrite(m12, HIGH);
    digitalWrite(m21, HIGH);
    digitalWrite(m22, HIGH);
  }
  else{
    digitalWrite(m01, LOW);
    digitalWrite(m02, HIGH);
    digitalWrite(m11, HIGH);
    digitalWrite(m12, LOW);
    digitalWrite(m21, HIGH);
    digitalWrite(m22, HIGH);
  }
  analogWrite(m0Pwm, speed);
  analogWrite(m1Pwm, speed);
  analogWrite(m2Pwm, 0);
}

//rotation
void rotate(int speed, int dir){
  
  if(dir > 0){
    digitalWrite(m01, HIGH);
    digitalWrite(m02, LOW); 
    digitalWrite(m11, HIGH);
    digitalWrite(m12, LOW);
    digitalWrite(m21, LOW);
    digitalWrite(m22, HIGH);
  }
  else{
    digitalWrite(m01, LOW);
    digitalWrite(m02, HIGH);
    digitalWrite(m11, LOW);
    digitalWrite(m12, HIGH);
    digitalWrite(m21, HIGH);
    digitalWrite(m22, LOW);
  }
  analogWrite(m0Pwm, speed);
  analogWrite(m1Pwm, speed);
  analogWrite(m2Pwm, speed);
}

void stop(){
  digitalWrite(m01, HIGH);
  digitalWrite(m02, HIGH);
  digitalWrite(m11, HIGH);
  digitalWrite(m12, HIGH);
  digitalWrite(m21, HIGH);
  digitalWrite(m22, HIGH);
}
void m0Enc(){
  if(digitalRead(enc0B)> 0){
    count0++;
  }
  else{
    count0--;
  }
//  Serial.print("m0 = ");
  //Serial.println(count0);
}
void m1Enc(){
  if(digitalRead(enc1B)> 0){
    count1++;
  }
  else{
    count1--;
  }
//  Serial.print("m1 = ");
//   Serial.println(count1);
}
void m2Enc(){
 
  if(digitalRead(enc2B)> 0){
    count2++;
  }
  else{
    count2--;
  }
//  Serial.print("m2 = ");
//   Serial.println(count2);
}
// dir = 1 (forward), dir = -1 (back) 
void linear_dis_mm(int speed, int dir, int dis){
  move(speed, dir);
  float reqCount = dis/0.95; //wheel travels 0.95mm per tick 
  count0 = 0;
  count1 = 0;
  while((abs(count0) < int(reqCount))||(abs(count1) < int(reqCount))){
    Serial.println(count0);
  }
  stop();
}

// dir = 1 (forward), dir = -1 (back) 
void rotate_degree(int speed, int dir, int deg){
  rotate(speed, dir);
  float reqCount = deg/0.2444; //wheel rotates 0.2444deg per tick
  count0 = 0;
  count1 = 0;
  count2 = 0;
 while((abs(count0) < int(reqCount))||(abs(count1) < int(reqCount))||(abs(count2) < int(reqCount))){
    Serial.println(count0);
  }
  stop();
}

void setup() {
  delay(5000);
  //cli();
  Serial.begin(9600);
  motor_pin_config();
  enc_pin_config();
  attachInterrupt(digitalPinToInterrupt(18), m0Enc, FALLING);
  attachInterrupt(digitalPinToInterrupt(3), m1Enc, FALLING);
  attachInterrupt(digitalPinToInterrupt(2), m2Enc, FALLING);
  
 
  stop();
  //sei();
  linear_dis_mm(50, 1, 1200);
//  delay(2000);
//  rotate_degree(45, 1, 180);
//  delay(2000);
//  linear_dis_mm(50, 1, 1200);
  //rotate(50,1);
}

void loop() {
  
  
//  if(count0 != prevCount0){
//    Serial.print("m0  ");
//    Serial.println(count0);
//
//    prevCount0 = count0;
//  }
//  if(count1 != prevCount1){
//    Serial.print("m1  ");
//    Serial.println(count1);
//    prevCount1 = count1;
//  }
//  if(count2 != prevCount2){
//    Serial.print("m2  ");
//    Serial.println(count2);
//    prevCount2 = count2;
//  }

}

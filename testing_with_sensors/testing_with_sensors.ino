//********      Declaration of Pins of Sharp Sensors     ********//
const int sharpIR1 = A0;
const int sharpIR2 = A1;
const int trig1 = 26;
const int echo = 25;
const int ping1 = 27;
const int trig1 = 26;
const int echo = 25;
const int ping1 = 27;
int recv;

//*****  Motor Pin Configuration *******//
void m0pinconfig(){
   pinMode(15,1);
   pinMode(16,1);
   pinmode(11,1);
}

void m1pinconfig(){
   pinMode(18,1);
   pinMode(19,1);
   pinMode(10,1);
}
void m2pinconfig(){
   pinMode(22,1);
   pinMode(23,1);
   pinMode(9,1);
}

void m3pinconfig(){
   pinMode(33,1);
   pinMode(34,1);
   pinMode(6,1);
}

//*****  Foreward *******//
void forward(int speed1,int speed2){
digitalWrite(15,0);
digitalWrite(16,1);
analogWrite(11,speed1);
digitalWrite(18,0);
digitalWrite(19,1);
analogWrite(10,speed2);
}
//*****  Backward *******//
void forward(int speed1,int speed2){
digitalWrite(15,1);
digitalWrite(16,0);
analogWrite(11,speed1);
digitalWrite(18,1);
digitalWrite(19,0);
analogWrite(10,speed2);
}

//*****  Left Direction *******//

void Left(int speed1,int speed2){
digitalWrite(22,0);
digitalWrite(23,1);
analogWrite(9,speed1);
digitalWrite(33,0);
digitalWrite(34,1);
analogWrite(6,speed2);
}

//*****  Right Direction *******//

void Right(int speed1,int speed2){
digitalWrite(22,1);
digitalWrite(23,0);
analogWrite(9,speed1);
digitalWrite(33,1);
digitalWrite(34,0);
analogWrite(6,speed2);
}

//*****  STOP *******//
void stop(){
  digitalWrite(22,1);
  digitalWrite(23,1);
  analogWrite(9,0);
  digitalWrite(18,1);
  digitalWrite(19,1);
  analogWrite(10,0);
  digitalWrite(15,1);
  digitalWrite(16,1);
  analogWrite(11,0);
  digitalWrite(33,1);
  digitalWrite(34,1); 
  analogWrite(6,0); 
}


//*****  ClockWise Direction *******//
void clockwise(){

}

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}

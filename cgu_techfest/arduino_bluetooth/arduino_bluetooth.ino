#include <Servo.h>
Servo servoLift;
Servo myservo;
int pos = 80;
int top = 10;
int bottom = 120;
int recieve;
int middle = 145;
int minimum = 135;
int maximum = 120;

  void motor1PinConfig(){
  pinMode(18,OUTPUT);
  pinMode(19,OUTPUT);
  pinMode(10,OUTPUT);}

  
  void motor3PinConfig(){
  pinMode(33,OUTPUT);
  pinMode(34,OUTPUT);
  pinMode(06,OUTPUT);}

  void motor0PinConfig(){
  pinMode(15,OUTPUT);
  pinMode(16,OUTPUT);
  pinMode(11,OUTPUT);}

  void motor2PinConfig(){
  pinMode(22,OUTPUT);
  pinMode(23,OUTPUT);
  pinMode(9,OUTPUT);}



void setup() {
  Serial.begin(9600);
  servoLift.attach(2);
  servoLift.write(pos);
  myservo.attach(3);
  myservo.write(middle);
  motor1PinConfig();
  motor3PinConfig();
  motor0PinConfig();
  motor2PinConfig();
}
void m1CW(int speed){
  digitalWrite(18,1);
  digitalWrite(19,0);
  analogWrite(10,speed);
}
void m1ACW(int speed){
  digitalWrite(18,0);
  digitalWrite(19,1);
  analogWrite(10,speed);
}
  void m0LW(int speed){
  digitalWrite(15,1);
  digitalWrite(16,0);
  analogWrite(11,speed);
}
  void m0RW(int speed){
  digitalWrite(15,0);
  digitalWrite(16,1);
  analogWrite(11,speed);
}
  
  void m3CW(int speed){
  digitalWrite(33,0);
  digitalWrite(34,1);
  analogWrite(06,speed);}

  void m3ACW(int speed){
  digitalWrite(33,1);
  digitalWrite(34,0);
  analogWrite(06,speed);}

  void m2LW(int speed){
  digitalWrite(22,0);
  digitalWrite(23,1);
  analogWrite(9,speed);}

  void m2RW(int speed){
  digitalWrite(22,1);
  digitalWrite(23,0);
  analogWrite(9,speed);
  }

 void stop(){
  digitalWrite(15,0);
  digitalWrite(16,0);
  digitalWrite(22,0);
  digitalWrite(23,0);
   digitalWrite(33,0);
  digitalWrite(34,0);
  digitalWrite(18,0);
  digitalWrite(19,0);
 }

void loop() 
{
  
//    m1ACW(120);
//    m3CW(120);
//    m2LW(120);
//    m0RW(120);

   if(recieve == '3' && pos<61)
   {
    pos=pos+5;
    servoLift.write(pos);
   }
   else if(recieve == '1'&&pos>10){
    pos=pos-5;
    servoLift.write(pos);
    
    }
    else if(recieve == '9')
    {
      middle = middle - 5;
      myservo.write(middle);
     
    }
   else if(recieve == '0')
    {
       middle = middle + 5;
       myservo.write(middle);
      
    }
   
    else if(recieve =='5'){
      m1CW(120);
      m3ACW(120);
      m2RW(120);
      m0LW(120);
      delay(80);
      stop();
     }
  
     else if(recieve =='7'){
      m1ACW(120);
      m3CW(120);
      m2LW(120);
      m0RW(120);
      delay(80);
      m1ACW(0);
      m3ACW(0);
      m0RW(0);
      m2RW(0);
      m0LW(0);
      m2LW(0);
      m1CW(0);
      m3CW(0);
     }
  
     else if(recieve == '8'){
     m1CW(120);
     m3CW(120);
     m0LW(0);
     m2LW(0);
     m0RW(0);
     m2RW(0);
     delay(130);
     stop();
     }
     
     else if(recieve=='2') {
      m1ACW(120);
      m3ACW(120);
      m0LW(0);
      m2LW(0);
      m0RW(0);
      m2RW(0);
      delay(130);
      m1ACW(0);
      m3ACW(0);
      m0RW(0);
      m2RW(0);
      m0LW(0);
      m2LW(0);
      m1CW(0);
      m3CW(0);
     
      
    }
   
     else if(recieve == '6'){
      m0LW(120);
      m2LW(120);
      m1CW(0);
      m3CW(0);
      m1ACW(0);
      m3ACW(0);
      delay(130);
      stop();
    }
   
     else if(recieve=='4'){
      m0RW(120);
      m2RW(120);
      m1CW(0);
      m3CW(0);
      m1ACW(0);
      m3ACW(0);
      delay(130);
      stop();


   
   }
}

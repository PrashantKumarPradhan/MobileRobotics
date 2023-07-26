#define sensor A9
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

 // Motor configuration.
void m0_pin_config(){
  pinMode(15,OUTPUT);
  pinMode(16,OUTPUT);
  pinMode(11,OUTPUT);
}

void m2_pin_config(){
  pinMode(33,OUTPUT);
  pinMode(34,OUTPUT);
  pinMode(06,OUTPUT);
}
void m1_pin_config(){
  pinMode(22,OUTPUT);
  pinMode(23,OUTPUT);
  pinMode(9,OUTPUT);
}

void m3_pin_config(){
  pinMode(18,OUTPUT);
  pinMode(19,OUTPUT);
  pinMode(10,OUTPUT);
}

// **** clockwise of motor 0********
void m0b(int speed){
  digitalWrite(15,1);
  digitalWrite(16,0);
  analogWrite(11,speed);
}

// **** anti-clockwise of motor 0********
void m0f(int speed){
  digitalWrite(15,0);
  digitalWrite(16,1);
  analogWrite(11,speed);
}

// **** clockwise of motor 2 ********
void m2f(int speed){
  digitalWrite(33,1);
  digitalWrite(34,0);
  analogWrite(06,speed);
}

// **** right of motor 2 ********
void m2b(int speed){
  digitalWrite(33,0);
  digitalWrite(34,1);
  analogWrite(06,speed);
}

// **** left of motor 1 ********
void m1r(int speed){
  digitalWrite(22,1);
  digitalWrite(23,0);
  analogWrite(9,speed);
}

// **** right of motor 1 ********
void m1l(int speed){
  digitalWrite(22,0);
  digitalWrite(23,1);
  analogWrite(9,speed);
}

// **** left of motor 3 ********
void m3l(int speed){
  digitalWrite(18,1);
  digitalWrite(19,0);
  analogWrite(10,speed);
}

// **** right of motor 3 ********
void m3r(int speed){
  digitalWrite(18,0);
  digitalWrite(19,1);
  analogWrite(10,speed);
}

// ***** Different Directions**********

void CW(){
  m1l(140);
  m2b(140);
  m0f(140);
  m3r(140);
}
void ACW(){
  m0b(140);
  m2f(140);
  m1r(140);
  m3l(140);
}
void right(){
  m1r(200);
  m3r(200); 
}

void left(){
  m1l(200);
  m3l(200); 
}

void foreward(){
  m0f(200);
  m2f(200);
}

void backward(){
  m0b(200);
  m2b(200);
}
void stop(){
  digitalWrite(15,1);
  digitalWrite(16,1);
  digitalWrite(22,1);
  digitalWrite(23,1);
  digitalWrite(33,1);
  digitalWrite(34,1);
  digitalWrite(18,1);
  digitalWrite(19,1);
  
}

void setup() {
  Serial.begin(9600);
  servoLift.attach(2);
  servoLift.write(pos);
  myservo.attach(3);
  myservo.write(middle);
  m0_pin_config();
  m1_pin_config();
  m2_pin_config();
  m3_pin_config();
}


void loop() 
{
  float volts = analogRead(sensor)*0.00488;  // value from sensor * (5/1024)
  int distance = 29.988*pow(volts, -1.173); // worked out from datasheet graph
  if(distance<20) {
    stop();
  }

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
     foreward();
     }
  
     else if(recieve =='7'){
     backward();
     }
  
     else if(recieve == '8'){
     CW();
     delay(130);
     stop();
     }
     
     else if(recieve=='2') {
      ACW();
      delay(130);
      stop();
      
    }
   
     else if(recieve == '6'){
     left();
      delay(130);
      stop();
    }
   
     else if(recieve=='4'){
     right();
      delay(130);
      stop();

     }
   
}

#include<Servo.h>
Servo servoLift;
Servo myservo;
int pos = 80;
int top = 10;
int bottom = 120;
int recieve;
int middle = 145;
int minimum = 135;
int maximum = 120;

// *******The input connections of RX to the Arduino.********//
// *******2,3,4,7,12,13 are pins of arduino to which the particular pins are connected.****//
#define ch1 2
#define ch2 3        
#define ch3 4
#define ch4 5
#define ch5 7
#define ch6 13

// *******Integers to represent the values of different channels.
//*****  channel 5 is for the gripper if true the gripper closes else opens.******//
int ch1Value;
int ch2Value;
int ch3Value;
int ch4Value;
bool ch5Value; 
int ch6Value;

//************ Motor configuration.************//
void m0_pin_config(){
  pinMode(30,OUTPUT);
  pinMode(32,OUTPUT);
  pinMode(10,OUTPUT);
}

void m1_pin_config(){
  pinMode(26,OUTPUT);
  pinMode(28,OUTPUT);
  pinMode(9,OUTPUT);
}
void m2_pin_config(){
  pinMode(22,OUTPUT);
  pinMode(24,OUTPUT);
  pinMode(8,OUTPUT);
}

// **** backward of motor 0********
void m0b(int speed){
  digitalWrite(30,0);
  digitalWrite(32,1);
  analogWrite(10,speed);
}

// **** forward of motor 0********
void m0f(int speed){
  digitalWrite(30,1);
  digitalWrite(32,0);
  analogWrite(10,speed);
}

// **** backward of motor 1 ********
void m1b(int speed){
  digitalWrite(26,1);
  digitalWrite(28,0);
  analogWrite(9,speed);
}

// **** forward of motor 1 ********
void m1f(int speed){
  digitalWrite(26,0);
  digitalWrite(28,1);
  analogWrite(9,speed);
}

// **** backward of motor 2 ********
void m2b(int speed){
  digitalWrite(22,1);
  digitalWrite(24,0);
  analogWrite(8,speed);
}

// **** forward of motor 2 ********
void m2f(int speed){
  digitalWrite(22,0);
  digitalWrite(24,1);
  analogWrite(8,speed);
}

// ***** Different Directions**********//

//**Forward Direction**//
void forward(){
  m0f(100);
  m1f(100);
}

//** Backward Direction**//
void backward(){
  m0b(100);
  m1b(100);
}

//** Right direction**//
void right(){
  m1b(100);
  m2b(100);
}

//** Left Direction**//
void left(){
  m0b(100);
  m2f(100);
}

//** Clockwise Rotation**//
void CW(){
  m0b(100);
  m1f(100);
  m2b(100);
}

//** Anti-Clockwise Rotation**//
void ACW(){
  m0f(100);
  m1b(100);
  m2f(100);
}

//**  Stop  **//
void stop(){
  digitalWrite(30,1);
  digitalWrite(32,1);
  digitalWrite(26,1);
  digitalWrite(28,1);
  digitalWrite(22,1);
  digitalWrite(24,1);
}


//******* Transmitter Pin Configuration*****
void TX_pin_config(){
  pinMode(ch1,INPUT);
  pinMode(ch2,INPUT);
  pinMode(ch3,INPUT);
  pinMode(ch4,INPUT);
  pinMode(ch5,INPUT);
  pinMode(ch6,INPUT);
}

int readchannel(int ch,int low,int high,int defaultvalue)  {   // this will read the channel no. , highest and lowest value and the default value
int chValue_temp=(pulseIn(ch,HIGH));
 if(chValue_temp<100){   //********this code is to stop the motors when nothing is done.
    chValue_temp = defaultvalue;       
  }
//  else if(chValue_temp > 2000 || chValue_temp < 1000){
//    chValue_temp = defaultvalue;
//  }
  int chValue = map(chValue_temp,1000, 2300, low, high); 
  if(chValue>-40 && chValue<40){   //********this code is to stop the motors when nothing is done.
    chValue = defaultvalue;       
  }
  return chValue;
}

void setup() {
  Serial.begin(9600);
  m0_pin_config();
  m1_pin_config();
  m2_pin_config();
  servoLift.attach(11);
  servoLift.write(pos);
  myservo.attach(10);
  myservo.write(middle);
  TX_pin_config();
  stop();
  delay(2000);


}

void loop() {
  int ch1Value = readchannel(ch1,-70,70,0);
  int ch2Value = readchannel(ch2,-70,70,0);
  int ch4Value = readchannel(ch4,-70,70,0);
  int ch3Value = readchannel(ch3,-70,70,0);
  if((ch1Value<40 && ch1Value>-40)&& (ch2Value<40 && ch2Value>-40) && (ch4<20 &&ch4>-20)){
    stop();
  }

  
  if(ch4Value<-20){
    CW();
  }

  else if(ch4Value>20){
   ACW();
  }
 else if(ch1Value>40){
    foreward(); 
  }
  else if(ch1Value<-40){
    backward();
  }
  
   else if(ch2Value>40){
    left();
  }
  
  else if(ch2Value<-40){
   right();
  }
}

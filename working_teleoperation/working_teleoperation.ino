//#include <Servo.h>
//Servo servoLift;
//Servo myservo;
//int pos = 80;
//int top = 10;
//int bottom = 120;
//int recieve;
//int middle = 145;
//int minimum = 135;
//int maximum = 120;

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

// **** backward of motor 0********
void m0b(int speed){
  digitalWrite(15,1);
  digitalWrite(16,0);
  analogWrite(11,speed);
}

// **** forward of motor 0********
void m0f(int speed){
  digitalWrite(15,0);
  digitalWrite(16,1);
  analogWrite(11,speed);
}

// **** backward of motor 2 ********
void m2b(int speed){
  digitalWrite(33,1);
  digitalWrite(34,0);
  analogWrite(06,speed);
}

// **** forward of motor 2 ********
void m2f(int speed){
  digitalWrite(33,0);
  digitalWrite(34,1);
  analogWrite(06,speed);
}

// **** left of motor 1 ********
void m1l(int speed){
  digitalWrite(22,1);
  digitalWrite(23,0);
  analogWrite(9,speed);
}

// **** right of motor 1 ********
void m1r(int speed){
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

// **** right of motor 3 ********//
void m3r(int speed){
  digitalWrite(18,0);
  digitalWrite(19,1);
  analogWrite(10,speed);
}

// ***** Different Directions**********//

void CW(){
  m2f(140);
  m1l(140);
  m0b(140);
  m3r(140);
}
void ACW(){
  m0f(140);
  m1r(140);
  m2b(140);
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
  m0b(200);
  m2b(200);
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
  //Serial.begin(115200);
//  servoLift.attach(2);
//  servoLift.write(pos);
//  myservo.attach(7);
//  myservo.write(middle);
  TX_pin_config();
  m0_pin_config();
  m1_pin_config();
  m2_pin_config();
  m3_pin_config();
  stop();
  delay(2000);
}

void loop() {
  int ch1Value = readchannel(ch1,-70,70,0);
  int ch2Value = readchannel(ch2,-70,70,0);
  int ch4Value = readchannel(ch4,-70,70,0);
  //int ch3Value = readchannel(ch3,-70,70,0);
  if((ch1Value<40 && ch1Value>-40)&& (ch2Value<40 && ch2Value>-40) && (ch4<20 &&ch4>-20)){
    stop();
  }

  
  // if(ch4Value<-20){
  //   CW();
  // }

  // else if(ch4Value>20){
  //  ACW();
  // }
//  else if(ch1Value>40){
//     foreward(); 
//   }
  // else if(ch1Value<-40){
  //   backward();
  // }
  // }
  //  else if(ch2Value>40){
  //   left();
  // }
  
  // else if(ch2Value<-40){
  //  right();
  // }

}


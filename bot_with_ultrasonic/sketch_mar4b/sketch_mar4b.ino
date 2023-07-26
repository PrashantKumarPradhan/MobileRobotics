#include <Servo.h>
//#define sensor A9

// Adding Servo library
Servo lifter;
Servo gripper;

// Globally declaration of variables
int top = 110, bottom = 5, pos = 60, gri = 120,distance;
char rec;


const int trigPin = 25; // Trigger Pin of Ultrasonic Sensor
const int echoPin = 26; // Echo Pin of Ultrasonic Sensor
long duration, inches, cm;
float volts;


   // Function for stop
void stop() {
  digitalWrite(18, LOW);
  digitalWrite(19, LOW);
  digitalWrite(33, LOW);
  digitalWrite(34, LOW);
  digitalWrite(15, LOW);
  digitalWrite(16, LOW);
  digitalWrite(22, LOW);
  digitalWrite(23, LOW);
}

// Function for pin configuration for motor0

void m0config() {
  pinMode(15, OUTPUT);
  pinMode(16, OUTPUT);
  pinMode(11, OUTPUT);
}

// Function for clockwise rotation of m0

void m0Cw(int speed) {
  digitalWrite(15, HIGH);
  digitalWrite(16, LOW);
  analogWrite(11, speed);
}

// Function for anti-clockwise rotation of m0

void m0aCw(int speed) {
  digitalWrite(15, LOW);
  digitalWrite(16, HIGH);
  analogWrite(11, speed);
}

// ..........................................................................


// Function for pin configuration for motor1

void m1config() {
  pinMode(18, OUTPUT);
  pinMode(19, OUTPUT);
  pinMode(10, OUTPUT);
}

// Function for clockwise rotation of m1

void m1Cw(int speed) {
  digitalWrite(18, HIGH);
  digitalWrite(19, LOW);
  analogWrite(10, speed);
}

// Function for anti-clockwise rotation of m1

void m1aCw(int speed) {
  digitalWrite(18, LOW);
  digitalWrite(19, HIGH);
  analogWrite(10, speed);
}

// Function for pin configuration for motor2

void m2config() {
  pinMode(22, OUTPUT);
  pinMode(23, OUTPUT);
  pinMode(9, OUTPUT);
}

// Function for clockwise rotation of m2

void m2Cw(int speed) {
  digitalWrite(22, HIGH);
  digitalWrite(23, LOW);
  analogWrite(9, speed);
}

// Function for anti-clockwise rotation of m2

void m2aCw(int speed) {
  digitalWrite(22, LOW);
  digitalWrite(23, HIGH);
  analogWrite(9, speed);
}

// ........................................................................

// Function for pin configuration for motor3

void m3config() {
  pinMode(33, OUTPUT);
  pinMode(34, OUTPUT);
  pinMode(6, OUTPUT);
}

// Function for clockwise rotation of m3

void m3Cw(int speed) {
  digitalWrite(33, HIGH);
  digitalWrite(34, LOW);
  analogWrite(6, speed);
}

// Function for anti-clockwise rotation of m3

void m3aCw(int speed) {
  digitalWrite(33, LOW);
  digitalWrite(34, HIGH);
  analogWrite(6, speed);
}


void right() {
  m1aCw(180);
  m3Cw(180);
}

void left() {
  m1Cw(180);
  m3aCw(180);
}


void backward() {
  m0Cw(180);
  m2aCw(180);
}

void forward() {
  m0aCw(180);
  m2Cw(180);
}


void rightTurn() {
  m0Cw(180);
  m1Cw(180);
  m2Cw(180);
  m3Cw(180);
}
// ..................
void leftTurn() {
  m0aCw(180);
  m1aCw(180);
  m2aCw(180);
  m3aCw(180);
}
// .................................................................

void Omnimove() {
  if (rec == 'a') {
    right();
    delay(165);
    stop();
  }

  else if (rec == 'b') {
    left();
    delay(165);
    stop();
  }

  else if (rec == 'c') {
    backward();
    delay(165);
    stop();
  }

  else if (rec == 'd'&& cm>30) {
    forward();
    delay(165);
    stop();
  }

  else if (rec == 'e') {
    rightTurn();
    delay(165);
    stop();
  }

  else if (rec == 'f') {
    leftTurn();
    delay(165);
    stop();
  }
}

// Function for movement of the lifter

void Lifter() {
  if (rec == 'h' && pos <= top) {
    pos = pos + 3;
    lifter.write(pos);
  }

  else if (rec == 'i' && pos >= bottom) {
    pos = pos - 3;
    lifter.write(pos);
  }
}

// ........................................................

// Function for movement of gripper

void Gripper() {  
  if (rec == 'g') {
    gri = gri + 3;
    gripper.write(gri);
    //delay(10);
  }

  else if (rec == 'r') {
    gri = gri - 3;
    gripper.write(gri);
    //delay(10);
  }
}

// .........................................................


//void sharp()
//{
//  if(distance>30)
//  {
//    forward();
//  }
//   else if(distance<30)
//  {
//    stop();
//  }
//}



void setup() 
{
     Serial.begin(9600); // Starting Serial Terminal

     lifter.attach(2);
     lifter.write(pos);

     gripper.attach(3);
     gripper.write(gri);
     
     pinMode(trigPin, OUTPUT);
     pinMode(echoPin, INPUT);

//     pinMode(sensor,INPUT);
     
     m0config();
     m1config();
     m2config();
     m3config();
}

void loop() 
{
   digitalWrite(trigPin, LOW);
   delayMicroseconds(2);
   digitalWrite(trigPin, HIGH);
   delayMicroseconds(10);
   digitalWrite(trigPin, LOW);
   
   duration = pulseIn(echoPin, HIGH);
   inches = microsecondsToInches(duration);
   cm = microsecondsToCentimeters(duration);

//    volts = analogRead(sensor)*0.0048828125;
//    distance = 13*pow(volts, -1);

//   sharp();
  
//  stop();
 if (Serial.available()) {
    rec=Serial.read();
    Omnimove();
    Lifter();
    Gripper();
  }
//   Serial.print(inches);
//   Serial.print("in, ");
//   Serial.print(cm);
//   Serial.print("cm");
//   Serial.println();
//   delay(100);
  
}

long microsecondsToInches(long microseconds) {
   return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds) {
   return microseconds/29/2;
}

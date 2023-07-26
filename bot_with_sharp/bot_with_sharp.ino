
const int sharpIR1 = A11; // sharp IR Sensor pin
//const int trig1 = 26, echo1 = 25;
const int ping1 = 27;
char rec;
// const int trigPin = 25; // Trigger Pin of Ultrasonic Sensor
// const int echoPin = 26; // Echo Pin of Ultrasonic Sensor
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

// void SR04_sonic_pin_config(){
//   pinMode(trig1, OUTPUT);
//   pinMode(echo1, INPUT);
// }

//fuction to read ultrasonic sensor distance in cm
// int read_sonic_distance(int trig, int echo){
//   digitalWrite(trig, LOW);
//   delayMicroseconds(2);
//   digitalWrite(trig, HIGH);
//   delayMicroseconds(10);
//   int distance = (pulseIn(echo, HIGH)/2)/29;
//   return distance;
// }

//read ping ultrasonic distnace in cm
// int read_ping_distance(int ping){
//   pinMode(ping, OUTPUT);
//   digitalWrite(ping, LOW);
//   delayMicroseconds(2);
//   digitalWrite(ping, HIGH);
//   delayMicroseconds(5);
//   digitalWrite(ping, LOW);
//   pinMode(ping, INPUT);
//   long microSeconds = pulseIn(ping, HIGH);
//   long distance = (microSeconds/2)/29;
//   return distance;
// }

//fuction to read sharp IR sensor distance in cm
int read_sharpIR_distance(int sharpIR){
  float volts = analogRead(sharpIR)*0.0048828125;
  int distance = 65*pow(volts,-1.10);
  if(distance >80){
    distance = 80;
  }
  return distance;
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


void backward() {
  m1aCw(180);
  m3Cw(180);
}

void forward() {
  m1Cw(180);
  m3aCw(180);
}


void right() {
  m0Cw(180);
  m2aCw(180);
}

void left() {
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

void setup(){
  m3config();
  m0config();
  m1config();
  m2config();
  Serial.begin(9600);
  //SR04_sonic_pin_config();

  
}

void loop(){
  static long int duration = millis();
  
  Serial.print("Sharp IR distance is = ");
  int distance = read_sharpIR_distance(A0);
  Serial.println(distance);
  if(distance<30){
    stop();
  }
  else{
    forward();
  }
  delay(1000);
//   if(distance <30){
//     stop();
//   }
//  if(distance > 30){
//     backward();
//   }
//   delay(100);
}
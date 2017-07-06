//L293D
//Motor A
const int motorPin1  = 9;  // Pin 14 of L293
const int motorPin2  = 10;  // Pin 10 of L293
const int enablePinA = 7;
//Motor B
const int motorPin3  = 6; // Pin  7 of L293
const int motorPin4  = 5;  // Pin  2 of L293
const int enablePinB = 12;

//This will run only one time.
void setup(){
    //Set pins as outputs
    pinMode(motorPin1, OUTPUT);
    pinMode(motorPin2, OUTPUT);
    pinMode(motorPin3, OUTPUT);
    pinMode(motorPin4, OUTPUT);
    pinMode(enablePinA, OUTPUT);
    pinMode(enablePinB, OUTPUT);
    digitalWrite(motorPin3, HIGH);
    digitalWrite(motorPin4, LOW);
    digitalWrite(enablePinB, HIGH);
    delay(2000);
    northStack();
    
}
void northStack(){
  rotate(180, 0);
}

void rotate(int degrees, int direction){
  // 0 = clockwise
  // 1 = counterClockwise
  double time = (degrees/72.0) * 1000;
  if(direction == 0){
    digitalWrite(motorPin1, HIGH);
    digitalWrite(motorPin2, LOW);
  }
  else{
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, HIGH);
  }
  digitalWrite(enablePinA, HIGH);
  delay(time);
  digitalWrite(enablePinA, LOW);
}

void loop(){ 
    
}    
void lock(){
  digitalWrite(motorPin3, HIGH);
  digitalWrite(motorPin4, LOW);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, HIGH);
  
}

/*
MOTOR A (BASE):
  Look at rotate function
MOTOR B (LIN MOT)
  OUT: HIGH LOW
  IN: LOW HIGH
 */

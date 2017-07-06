//L293D
//Motor A
const int motorPin1  = 9;  // Pin 14 of L293
const int motorPin2  = 10;  // Pin 10 of L293
const int enablePinA = 7;
//Motor B
const int motorPin3  = 6; // Pin  7 of L293
const int motorPin4  = 5;  // Pin  2 of L293
const int enablePinB = 12;
boolean lockVar = false;

//This will run only one time.
void setup(){
    //Serial.begin(9600);
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
    delay(1000);
    while(true){
    lock();

    }
    
}
void lock(){
  digitalWrite(motorPin3, HIGH);
  digitalWrite(motorPin4, LOW);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, HIGH);
  
}


void loop(){ 
  
}      

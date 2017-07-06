

/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Sweep
*/

#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position

const int buttonPin = 7; // Digital Pin 2 connects to the toggle switch
const int motorTerminal1 = 3; // Digital Pin 3 connects to motor terminal 1
const int motorTerminal2 = 2; // Digital Pin 4 connects to motor terminal 2

int buttonState = 0;
int flipDirection = 1;

void setup() {
  myservo.attach(13);  // attaches the servo on pin 13 to the servo object
  // initialize the LED pin as an output:
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
  pinMode(motorTerminal1, OUTPUT);
  pinMode(motorTerminal2, OUTPUT);
}

void loop() {
  buttonState = digitalRead(buttonPin);

  if(buttonState == HIGH){
    flip(flipDirection);
    flipDirection = flipDirection * -1;
  }
  digitalWrite(motorTerminal1, HIGH); // these logic levels create reverse direction
digitalWrite(motorTerminal2, LOW); 
}

void flip(int direction){
  if(direction == 1){
    for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15); 
    }// waits 15ms for the servo to reach the position
  }
  else{
    for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
 }
}


//ARDUINO CODE
class SmartMotor {
    /**documenttion
      logPin1 & logPin2 - connect these to 2 digital ports
    **/
    public:
    int mSpeed; // speed of the motor -1 is right 0 is locked 1 is left
    int logPin1, logPin2; //the 2 logic pins for control
    //class to control a motor
  public:
    SmartMotor() {
      logPin1 = A0;
      logPin2 = A1;
      mSpeed = 0;
      pinMode(logPin1, OUTPUT);
      pinMode(logPin2, OUTPUT);
    }
    void exist() {
      switch (mSpeed) {
        case -1:
          //this means the motor is set to go left


          digitalWrite(logPin1, LOW);
          digitalWrite(logPin2, HIGH);
          break;
        case 0:
          //this means the motor is locked


          digitalWrite(logPin1, HIGH);
          digitalWrite(logPin2, HIGH);
          break;
        case 1:
          //this means the motor is set to go right


          digitalWrite(logPin1, HIGH);
          digitalWrite(logPin2, LOW);
          break;
      }
    }
    void setMSpeed(int newSpeed) {
      if (newSpeed == -1 || newSpeed == 0 || newSpeed == 1) {
        mSpeed = newSpeed;
      }
    }

};

SmartMotor base;
SmartMotor shoulder;

void setup() {
  Serial.begin(9600);
  shoulder.logPin1 = A0;
  shoulder.logPin2 = A1;
}
void loop() {
  base.exist();
  if (Serial.available()) {  // Returns true if there is serial input.
    char command = Serial.read();
    //base
    if (command == 'a') { //base go left
      base.setMSpeed(-1);
    } else if (command == 'b') { //base go right
      base.setMSpeed(1);
    } else if (command == 'c'){ // base go stop
      base.setMSpeed(0);     
    }
    
     if (command == 'd') {
      shoulder.setMSpeed(-1); //shoulder go up
    } else if (command == 'e') {
      shoulder.setMSpeed(1); //shoulder go down
    } else if (command == 'f'){
      shoulder.setMSpeed(0); //shoulder go stop    
    }   
    
    
  }
}
//PROCESSING CODE:


import processing.serial.*;


Serial myPort = new Serial(this, "COM3", 9600);       


void setup() {
  //myPort.begin(9600);
}
void draw() {
  if (keyPressed && keyCode == UP) {
    myPort.write("d"); //shoulder go up
  } else if (keyPressed && keyCode == DOWN) {
    myPort.write("e");  // shoulder go down
  } else {
    myPort.write("f"); //shoulder go stop
  }
  if (keyPressed && keyCode == LEFT) {
    myPort.write("b"); //base go elf
  } else if (keyPressed && keyCode == RIGHT) {
    myPort.write("a"); //base go right
  } else {
    myPort.write("c"); //base go stop
  }
}


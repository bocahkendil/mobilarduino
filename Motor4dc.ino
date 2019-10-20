// Adafruit Motor shield library
// copyright Adafruit Industries LLC, 2009
// this code is public domain, enjoy!

#include <AFMotor.h>

AF_DCMotor motorFL(1); //depan kiri
AF_DCMotor motorBL(2); //belakang kiri
AF_DCMotor motorBR(3); //belakang kanan
AF_DCMotor motorFR(4); //depan kanan

int command;             //Int to store app command state.
int speedCar = 100;     // 50 - 255.

void setup() {
  // turn on motor
  //Then you can set the speed of the motor using setSpeed(speed) where the speed ranges from 0 (stopped) to 255 (full speed)
  motorFL.setSpeed(speedCar);
  motorBL.setSpeed(speedCar);
  motorBR.setSpeed(speedCar);
  motorFR.setSpeed(speedCar);
   
  motorFL.run(RELEASE); //// stopped
  motorBL.run(RELEASE);
  motorBR.run(RELEASE);
  motorFR.run(RELEASE);

  Serial.begin(9600);           // set up Serial library at 9600 bps
  }

void goAhead(){ 

  motorFL.run(FORWARD);  //// turn it on going forward
  motorFL.setSpeed(speedCar); 
  motorBL.run(FORWARD);  //// turn it on going forward
  motorBL.setSpeed(speedCar); 
  motorBR.run(FORWARD);  //// turn it on going forward
  motorBR.setSpeed(speedCar); 
  motorFR.run(FORWARD);  //// turn it on going forward
  motorFR.setSpeed(speedCar); 
  }

void goBack(){ 
  motorFL.run(BACKWARD);  //// turn it on going forward
  motorFL.setSpeed(speedCar); 
  motorBL.run(BACKWARD);  //// turn it on going forward
  motorBL.setSpeed(speedCar); 
  motorBR.run(BACKWARD);  //// turn it on going forward
  motorBR.setSpeed(speedCar); 
  motorFR.run(BACKWARD);  //// turn it on going forward
  motorFR.setSpeed(speedCar); 
  }


void goRight(){ 
  motorFL.run(FORWARD);  //// turn it on going forward
  motorFL.setSpeed(speedCar); 
  motorBL.run(FORWARD);  //// turn it on going forward
  motorBL.setSpeed(speedCar); 
  motorBR.run(FORWARD);  //// turn it on going forward
  motorBR.setSpeed(speedCar); 
  motorFR.run(RELEASE);  //// turn it on going forward
  motorFR.setSpeed(speedCar);    
  }

void goLeft(){ 
  motorFL.run(RELEASE);  //// turn it on going forward
  motorFL.setSpeed(speedCar); 
  motorBL.run(FORWARD);  //// turn it on going forward
  motorBL.setSpeed(speedCar); 
  motorBR.run(FORWARD);  //// turn it on going forward
  motorBR.setSpeed(speedCar); 
  motorFR.run(FORWARD);  //// turn it on going forward
  motorFR.setSpeed(speedCar);   
  }

void goAheadRight(){  
  motorFL.run(RELEASE);  //// turn it on going forward
  motorFL.setSpeed(speedCar); 
  motorBL.run(RELEASE);  //// turn it on going forward
  motorBL.setSpeed(speedCar); 
  motorBR.run(FORWARD);  //// turn it on going forward
  motorBR.setSpeed(speedCar); 
  motorFR.run(FORWARD);  //// turn it on going forward
  motorFR.setSpeed(speedCar);     
  }

void goAheadLeft(){
  motorFL.run(FORWARD);  //// turn it on going forward
  motorFL.setSpeed(speedCar); 
  motorBL.run(FORWARD);  //// turn it on going forward
  motorBL.setSpeed(speedCar); 
  motorBR.run(RELEASE);  //// turn it on going forward
  motorBR.setSpeed(speedCar); 
  motorFR.run(RELEASE);  //// turn it on going forward
  motorFR.setSpeed(speedCar);     
  }

void goBackRight(){ 
  motorFL.run(FORWARD);  //// turn it on going forward
  motorFL.setSpeed(speedCar); 
  motorBL.run(RELEASE);  //// turn it on going forward
  motorBL.setSpeed(speedCar); 
  motorBR.run(FORWARD);  //// turn it on going forward
  motorBR.setSpeed(speedCar); 
  motorFR.run(FORWARD);  //// turn it on going forward
  motorFR.setSpeed(speedCar);  
  
  } 

void goBackLeft(){
  motorFL.run(FORWARD);  //// turn it on going forward
  motorFL.setSpeed(speedCar); 
  motorBL.run(FORWARD);  //// turn it on going forward
  motorBL.setSpeed(speedCar); 
  motorBR.run(RELEASE);  //// turn it on going forward
  motorBR.setSpeed(speedCar); 
  motorFR.run(FORWARD);  //// turn it on going forward
  motorFR.setSpeed(speedCar);  
  
  }

void stopRobot(){ 
  motorFL.run(RELEASE); //// stopped
  motorBL.run(RELEASE);
  motorBR.run(RELEASE);
  motorFR.run(RELEASE);  
  
  }   
void loop(){
  
if (Serial.available() > 0) {
  command = Serial.read();
  stopRobot();      //Initialize with motors stopped.

  switch (command) {
  case 'F':goAhead();break;
  case 'B':goBack();break;
  case 'L':goLeft();break;
  case 'R':goRight();break;
  case 'I':goAheadRight();break;
  case 'G':goAheadLeft();break;
  case 'J':goBackRight();break;
  case 'H':goBackLeft();break;
  case '0':speedCar = 100;break;
  case '1':speedCar = 115;break;
  case '2':speedCar = 130;break;
  case '3':speedCar = 145;break;
  case '4':speedCar = 160;break;
  case '5':speedCar = 175;break;
  case '6':speedCar = 190;break;
  case '7':speedCar = 205;break;
  case '8':speedCar = 220;break;
  case '9':speedCar = 235;break;
  case 'q':speedCar = 255;break;
//  case 'W':lightFront = true;break;
//  case 'w':lightFront = false;break;
//  case 'U':lightBack = true;break;
//  case 'u':lightBack = false;break;
//  case 'V':horn = true;break;
//  case 'v':horn = false;break;
  }
}

}

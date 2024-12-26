#include <Servo.h>
Servo servo1;
int servoPin = 2;
int motorspinny = 0;
const int eastLDR = A1; // Assign pins to the LDR's
const int westLDR = A2;
int eastLight;
int westLight;
int difference1 = 0;
int difference = 0;
  //difference = eastLDR - westLDR ;

void setup(){
  pinMode(eastLDR, INPUT);
  pinMode(westLDR, INPUT);
  servo1.attach(servoPin);
  
  //int eastLight, high = 1023, low = 0;
  //int westLight, high = 1023, low = 0;
 
  
  Serial.begin(9600); 
}

void loop(){
  motormovewhere();
  //servo1.write(90);
  
}

void motormovewhere()
{
  eastLight = analogRead(eastLDR);
  westLight = analogRead(westLDR);
  Serial.print("West: ");
  Serial.println(westLight);

  Serial.print("East: ");
  Serial.println(eastLight);
  

  difference1 = westLight - eastLight ;
  difference = abs(difference1);
  
  if (eastLight > westLight){
    motorspinny = 155;
    servo1.write(motorspinny);
  }
  if (westLight > eastLight){
    motorspinny = 25;
    servo1.write(motorspinny);
  }
  
  //if (westLight == eastLight){
    //motorspinny = 90;
    //servo1.write(motorspinny);
  //} 

  if (difference < 45){
    motorspinny = 90;
    servo1.write(motorspinny);
  } 


  
  
  
  //lightLevel = map(lightLevel, low+30, high-30, 0, 255);
 // lightLevel = constrain(lightLevel, 0, 255);
}


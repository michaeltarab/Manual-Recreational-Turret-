#include <Servo.h>
Servo Y;
int currentDegree = 150;
int yStartState;
int vrY = A0;

void setup() {
  Serial.begin(9600);
  
  Y.attach(8);
  Y.write(currentDegree);
  yStartState = analogRead(vrY);

 digitalWrite(7,HIGH);
 pinMode(7,OUTPUT);
 pinMode(2,INPUT);
 digitalWrite(2,HIGH);
 pinMode(A0,INPUT);
 
  delay(1000);
}

void loop() {

  if (digitalRead(2) == 0){
    digitalWrite(7,LOW);
  }else{
    digitalWrite(7,HIGH);
  }
  int yPosition = analogRead(A0);
   if (abs(yStartState-yPosition) > 300){
    if (currentDegree < 130){
      currentDegree++;
    }
    else if (currentDegree > 200){
      currentDegree--;
    }
    if (yPosition < yStartState){
      currentDegree++;
    }else{
      currentDegree--;
    }
    Y.write(currentDegree);
   }
  delay(100);
}

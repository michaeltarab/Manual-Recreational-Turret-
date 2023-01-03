int xStartState;
int vrX = A1;

void setup() 
{ 
  pinMode(A1,INPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);

  xStartState = analogRead(vrX);
  Serial.begin(9600);
  Serial.print(xStartState);
} 

void loop(){
 int xPosition = analogRead(A1);
 if (abs(xStartState-xPosition) > 300){
  if (xPosition < xStartState){
    digitalWrite(9,HIGH);
  }
  else{
    digitalWrite(9,LOW);
  }
  digitalWrite(8,HIGH);
  digitalWrite(8,LOW);
 }
  delayMicroseconds(800);
}

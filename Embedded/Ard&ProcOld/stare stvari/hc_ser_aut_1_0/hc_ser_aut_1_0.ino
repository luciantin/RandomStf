#include <Servo.h> 
 #define echoPin 2 
#define trigPin 3 
Servo myservo;  
int pos ;    
int led = 13;
long vrijeme, udaljenost;
void setup() {
   pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);
  pinMode(led, OUTPUT);
  myservo.attach(9);


 
}




void udaljenost11()
{
  digitalWrite(trigPin, LOW); 
 delayMicroseconds(5); 

 digitalWrite(trigPin, HIGH);
 delayMicroseconds(10); 
 
 digitalWrite(trigPin, LOW);
 vrijeme = pulseIn(echoPin, HIGH);
 
 udaljenost = vrijeme/52;
 
 delay(100);
 }


void loop()
{
  
  
  myservo.write(90);
udaljenost11();
delay(200);
  
 while (udaljenost>30)
{
 digitalWrite(led, HIGH); 
 myservo.write(90);
udaljenost11();
  
  
}  



}
 

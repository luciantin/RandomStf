
#include <Servo.h> 
 #define echoPin 2 
#define trigPin 3 
Servo myservo;  
int pos ;    

int maximumRange = 500; 
int minimumRange = 0;
long vrijeme, udaljenost;
void setup() {
   pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);
 
  myservo.attach(9);
 Serial.begin (9600);

 Serial.println("Enter Number 0 to 180 ");
}




void udaljenost11()
{
  digitalWrite(trigPin, LOW); 
 delayMicroseconds(5); 

 digitalWrite(trigPin, HIGH);
 delayMicroseconds(10); 
 
 digitalWrite(trigPin, LOW);
 vrijeme = pulseIn(echoPin, HIGH);
 
 
 udaljenost = vrijeme/45;
 
 Serial.println(udaljenost);

 delay(1000);
 }


void loop() {

  
 if (Serial.available())
{
 char kod = Serial.read ();
  if (kod = '1')
  {
myservo.write(6); 
delay(2000);
Serial.print("0 ==  ");
udaljenost11();
 
myservo.write(90);
delay(2000);
Serial.print("90 ==  ");
udaljenost11();

myservo.write(180);
delay(2000);
Serial.print("180 ==  ");
udaljenost11();


  }
  
 

}
delay(50);
myservo.write(90);

}





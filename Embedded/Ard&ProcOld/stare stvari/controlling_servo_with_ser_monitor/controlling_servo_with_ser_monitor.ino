#include <Servo.h> 

Servo myservo;  
int pos ;    

void setup() {
  myservo.attach(9);
Serial.begin (9600);

 Serial.println("Enter Number 0 to 180 ");
}





void loop() {

 if (Serial.available())
{
char ch = Serial.read() ;
if (ch >= '0' && ch <= '180')
{
int led = ch- '0' ;

Serial.println("Turning ");
myservo.write(led);
}

}
}
 
  // broj po broj se ucitava ne svi odjednom
 




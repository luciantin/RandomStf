
#include <Servo.h> 
Servo myservo1; 
 Servo myservo2;  
Servo myservo3;  
int pos = 0;   
void setup() 
{ 
   myservo2.attach(11);
  myservo3.attach(10);
  myservo1.attach(9);
} 
 
 
void loop() 
{ 
 
 myservo1.write(90);
  delay(20);   
    myservo2.write(90);
    delay(20);   
   myservo3.write(90);             
    delay(20);                   
 
} 

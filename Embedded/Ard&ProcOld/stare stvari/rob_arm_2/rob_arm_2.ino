
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
 for(pos=0;pos<=180;pos++)
 {
 myservo3.write(pos);  
 delay(20); 
 }
 for(pos=180;pos>=0;pos--)
 {
 myservo3.write(pos);  
 delay(20); 
 }
  myservo3.write(90);
 
 delay(20); 
 for(pos=0;pos<=140;pos++)
 {
 myservo2.write(pos);  
 delay(20); 
 }
 for(pos=140;pos>=0;pos--)
 {
 myservo2.write(pos);  
 delay(20); 
 }
 
 myservo2.write(70);  
 delay(20); 
 
 
 
 for(pos=0;pos<=180;pos++)
 {
 myservo1.write(pos);  
 delay(20); 
 }
 for(pos=180;pos>=0;pos--)
 {
 myservo1.write(pos);  
 delay(20); 
 }
 
  myservo1.write(90);  
 delay(20); 
 
 
 
  for(pos=0;pos<=140;pos++)
 {
 myservo2.write(pos);  
 delay(20); 
 }
 for(pos=140;pos>=0;pos--)
 {
 myservo2.write(pos);  
 delay(20); 
 }
 
 myservo2.write(70);  
 delay(20); 
 
 
 
 
 
 
 delay(1000000);
 
 
 
 
}   








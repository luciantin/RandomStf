
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
  for(pos = 0; pos < 180; pos += 1) 
  {   
 myservo1.write(pos);
  delay(20);   
  
    
   myservo3.write(pos);             
    delay(20);  

if (pos>=80 && pos<=130)  myservo2.write(pos);

    delay(20);   
  } 
  for(pos = 180; pos>=0; pos-=1)    
  {                                
  myservo1.write(pos);
  delay(20);   
  if (pos>=80 && pos<=130)  myservo2.write(pos);

    delay(20); 
   myservo3.write(pos);             
    delay(20);                      
  } 
} 

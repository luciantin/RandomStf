#include <Servo.h> 
Servo myservo;

int pos = 0; 

int led1 = 8;
int led2 = 4;

void setup() {
  // put your setup code here, to run once:
 pinMode(led1, OUTPUT);
   pinMode(led2, OUTPUT);
    myservo.attach(9); 
}




void servo ()
{
  for(pos = 0; pos < 180; pos += 1) 
  {                                  // in steps of 1 degree 
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  } 
  for(pos = 180; pos>=1; pos-=1)     // goes from 180 degrees to 0 degrees 
  {                                
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  } 
}

void loop() {
  // put your main code here, to run repeatedly: 
   servo();
  
  digitalWrite(led2, LOW);   
   digitalWrite(led1, LOW); 
  delay (1000);
 digitalWrite(led1, HIGH); 
  delay (1000); 
  digitalWrite(led1, LOW); 
  digitalWrite(led2, HIGH);   
  delay (1000); 
  
  
  
  
  
  
}

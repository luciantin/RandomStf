

 
#include <Servo.h> 
 
Servo myservo;
 
 
int potpin = 0;  
int val;    
int servom = 0;
void setup() 
{ 
  Serial.begin(9600);
 myservo.attach(9);  
} 
 
void loop() 
{ 
  val = analogRead(potpin);
  val = map(val, 0, 1023, 0, 255); 
  Serial.print("sensor = " );                       
  Serial.println(val);
if (val>140 && val<160)
{
if (servom < 180)
    {
    servom ++ ;
    myservo.write(servom);
        
    }

}
if (val<100 )
{
if (servom > 0)
    {
    servom -- ;
    myservo.write(servom);
        
    }

}

  
  delay(25);     



   
} 

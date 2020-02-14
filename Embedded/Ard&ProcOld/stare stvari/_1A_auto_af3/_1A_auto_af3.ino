#include <Servo.h>
int echoPin = 2; 
int trigPin = 3; 
int kotac2  = 4;
int kotac1  = 5;
Servo myservo1;

int poz;

long vrijeme;
 

int ud90,ud0,ud180;


void setup() {
 Serial.begin (9600);
 pinMode(kotac1, OUTPUT);   
 pinMode(kotac2, OUTPUT);     
 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);
 myservo1.attach(9);
}


int udaljenost()
{
 digitalWrite(trigPin, LOW); 
 delayMicroseconds(5); 
 digitalWrite(trigPin, HIGH);
 delayMicroseconds(10);  
 digitalWrite(trigPin, LOW);
 vrijeme = pulseIn(echoPin, HIGH);
 return (vrijeme/2)/32;
}


void provjera_udaljenosti()
{
  myservo1.write(0);
  delay(600);
  ud0=udaljenost();
  Serial.print ("Ud0 = ");
  Serial.println(ud0);
  
  myservo1.write(90);
  delay(600);
  ud90=udaljenost();
  Serial.print ("Ud90 = ");
  Serial.println(ud90);
  
  myservo1.write(180);
  delay(600);
  ud180=udaljenost();
  Serial.print ("Ud180 = ");
  Serial.println(ud180);
}


void kretanje()
{
  
if(ud90>20)
{
 digitalWrite(kotac1, HIGH);
 digitalWrite(kotac2, HIGH); 
}

else
{
  
 if(ud180>20)
 {
 digitalWrite(kotac1, LOW);
 digitalWrite(kotac2, HIGH); 
}

else if (ud0>20)
{
 digitalWrite(kotac1, HIGH);
 digitalWrite(kotac2, LOW); 
}

 digitalWrite(kotac1, LOW);
 digitalWrite(kotac2, LOW); 
 
}

}

void loop() {
/*
myservo1.write(90);
delay(500);

ud90=provjera();
Serial.println(ud90);

if(ud90>10)
{
 digitalWrite(kotac1, HIGH);
 digitalWrite(kotac2, HIGH); 
}
else
{
 digitalWrite(kotac1, LOW);
 digitalWrite(kotac2, LOW); 
}
*/

provjera_udaljenosti();
kretanje();
 
}

#include <Servo.h>
int echoPin = 2; 
int trigPin = 3; 
int kotac2  = 4;
int kotac1  = 5;
Servo myservo1;

int poz;

long vrijeme;
long udaljenost;


int ud90,ud0,ud180;


void setup() {
 Serial.begin (9600);
 pinMode(kotac1, OUTPUT);   
 pinMode(kotac2, OUTPUT);     
 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);
 myservo1.attach(9);
}


int provjera()
{
 digitalWrite(trigPin, LOW); 
 delayMicroseconds(5); 
 digitalWrite(trigPin, HIGH);
 delayMicroseconds(10);  
 digitalWrite(trigPin, LOW);
 vrijeme = pulseIn(echoPin, HIGH);
 return (vrijeme/2)/32;
}

void loop() {

myservo1.write(90);
delay(1000);

ud90=provjera();

myservo1.write(180);
delay(1000);

ud180=provjera();

myservo1.write(0);
delay(1000);

ud0=provjera();


if(ud90>ud0&&ud90>ud180)
{
 digitalWrite(kotac1, HIGH);
 digitalWrite(kotac2, HIGH); 
}

else if(ud0>ud90&&ud0>ud180)
{
 digitalWrite(kotac1, LOW);
 digitalWrite(kotac2, HIGH); 
}

else if(ud180>ud90&&ud180>ud0)
{
 digitalWrite(kotac2, LOW);
 digitalWrite(kotac1, HIGH); 
}




 delay(2000);
}



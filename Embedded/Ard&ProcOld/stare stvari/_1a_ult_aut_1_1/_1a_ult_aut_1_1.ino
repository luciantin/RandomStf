#include <Servo.h>
int echoPin = 2; 
int trigPin = 3; 
int kotac2  = 4;
int kotac1  = 5;
Servo myservo1;

int poz;

long vrijeme;
 

int ud90,ud0,ud180,ud45,ud135;


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
  
  myservo1.write(88);
  delay(600);
  ud90=udaljenost();
  Serial.print ("Ud90 = ");
  Serial.println(ud90);
  
  myservo1.write(180);
  delay(650);
  ud180=udaljenost();
  Serial.print ("Ud180 = ");
  Serial.println(ud180);
}

void provjera_udaljenosti_2()
{
  myservo1.write(45);
  delay(600);
  ud45=udaljenost();
  Serial.print ("Ud45 = ");
  Serial.println(ud45);
  
  myservo1.write(135);
  delay(600);
  ud135=udaljenost();
  Serial.print ("Ud135 = ");
  Serial.println(ud135);
  
}

void loop() 
{

  
provjera_udaljenosti();

while(ud90<10&&ud180<10&&ud0<10)
{
 digitalWrite(kotac1,LOW);
 digitalWrite(kotac2, LOW );
provjera_udaljenosti(); 
}

while(ud90>35)
{
  myservo1.write(90);
  
  digitalWrite(kotac1, HIGH);
 digitalWrite(kotac2, HIGH); 
 delay(300);
  digitalWrite(kotac1,LOW);
 digitalWrite(kotac2, LOW );  

  provjera_udaljenosti(); 
}

while(ud90>25)
{
  myservo1.write(90);
  
  digitalWrite(kotac1, HIGH);
 digitalWrite(kotac2, HIGH); 
 delay(200);
  digitalWrite(kotac1,LOW);
 digitalWrite(kotac2, LOW );  

  provjera_udaljenosti(); 
}


 if(ud180>ud0&&ud90<25&&ud180>10)
{
digitalWrite(kotac2,LOW);
digitalWrite(kotac1, HIGH ); 
delay(500);
 digitalWrite(kotac1,LOW);
 digitalWrite(kotac2, LOW );
} 
else if(ud180<ud0&&ud90<25&&ud0>10)
{
digitalWrite(kotac1,LOW);
digitalWrite(kotac2, HIGH ); 
delay(500);
 digitalWrite(kotac1,LOW);
 digitalWrite(kotac2, LOW );
}

 
}

int echoPin= 2;
int trigPin= 3;

int pin7 = 7;
int pin6 = 6;


int maxdomet = 1000; 
int mindomet = 0;
long vrijeme, udaljenost;

void setup() {

 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);

pinMode(pin7, OUTPUT);
pinMode(pin6, OUTPUT);

}


void loop() {

  mjerenje();
  
 if (udaljenost < 40) 
 {
 
 digitalWrite(pin7, HIGH); 
 digitalWrite(pin6, LOW);   
 }

else
{
 
digitalWrite(pin7, HIGH); 
 digitalWrite(pin6, HIGH);  

}

delay(10);
 
}

void mjerenje()
{


 digitalWrite(trigPin, LOW); 
 delayMicroseconds(5); 

 digitalWrite(trigPin, HIGH);
 delayMicroseconds(10); 
 
 digitalWrite(trigPin, LOW);
 vrijeme = pulseIn(echoPin, HIGH);

 
 udaljenost = vrijeme/34.03;

}

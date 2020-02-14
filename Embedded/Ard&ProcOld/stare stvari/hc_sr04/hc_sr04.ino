#define echoPin 2 
#define trigPin 3 
#define LEDPin 13 

int maximumRange = 1000; 
int minimumRange = 0;
long vrijeme, udaljenost;

void setup() {
 Serial.begin (9600);
 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);
 pinMode(LEDPin, OUTPUT); 
}






void loop() {

 digitalWrite(trigPin, LOW); 
 delayMicroseconds(5); 

 digitalWrite(trigPin, HIGH);
 delayMicroseconds(10); 
 
 digitalWrite(trigPin, LOW);
 vrijeme = pulseIn(echoPin, HIGH);
 
 
 udaljenost = vrijeme/45;
 
 Serial.println(udaljenost);

 delay(50);
}

int led1 = 10;
int led2 = 11;
int sensorPin = A0;     
int ledPin = 13;       
int sensorValue = 0;  

void setup() {
   
  pinMode(ledPin, OUTPUT);  
  Serial.begin(9600);
    pinMode(led1, OUTPUT);
   pinMode(led2, OUTPUT);  
}

void loop() {
  
  sensorValue = analogRead(sensorPin);    
  sensorValue  = map(sensorValue, 0, 1023, 0, 100);
  Serial.println(sensorValue);
  if(sensorValue>35) digitalWrite(led1, HIGH); 
  if(sensorValue<30) digitalWrite(led2, HIGH); 
  else
  {
   digitalWrite(led1, LOW);   
   digitalWrite(led2, LOW);    
  }
  
  delay(10);                  
}

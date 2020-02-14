// RF Blink - Receiver sketch 
     
 #define rfReceivePin A0  
 #define ledPin 13        
int data = 0;   
 void setup(){
   pinMode(ledPin, OUTPUT);
   Serial.begin(9600);
 }
 void loop()
{ 
   data=analogRead(rfReceivePin);    
  Serial.println(data);
   delay(10); 
 }


char val; 
 int led  = 9;
 
  void setup() {
   pinMode(led , OUTPUT); 
   Serial.begin(9600); 
 }
 
 
 
 
 
 
 
 void loop() {
   if (Serial.available()) 
   {
     val = Serial.read(); 
      analogWrite(led,val-50);
   }
   
   delay(5); 
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 

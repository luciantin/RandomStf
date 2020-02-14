 #include <RCSwitch.h>

RCSwitch mySwitch = RCSwitch();
 
 char val; 
 int led  = 9;
 
  void setup() {
  Serial.begin(9600); 
  
    mySwitch.enableTransmit(10);
   
    
   pinMode(led , OUTPUT); 
   
 }
 
 
 
 void loop() {
   if (Serial.available()) 
   {
    
     val = Serial.read(); 
     if(val=='S')
     {
       digitalWrite(led,HIGH); 
     mySwitch.send(23, 24);
     //delay(50);
     }
    else if(val=='L') 
    {
       digitalWrite(led,HIGH); 
     mySwitch.send(532, 24);
     //delay(50);
     }
    else if(val=='D')  
    {
       digitalWrite(led,HIGH); 
       mySwitch.send(2630, 24);
     //delay(50);
     }
     
     else   digitalWrite(led,LOW);
    // val='0';
    // mySwitch.send(5393, 24);
    // delay(1000);
   }
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 

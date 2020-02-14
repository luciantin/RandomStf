#include <RCSwitch.h>

RCSwitch mySwitch = RCSwitch();
RCSwitch tran = RCSwitch();
void setup() {
  Serial.begin(9600);
  mySwitch.enableReceive(0);
   tran.enableTransmit(13);
   
  tran.send(4, 24);
  delay(50);  
 tran.send(4, 24);
   
}





void loop() {
  
 
 
  if (mySwitch.available()) {
    
    int value = mySwitch.getReceivedValue();
    
    if (value > 4)
    {
      Serial.print("Received ");
      Serial.println( mySwitch.getReceivedValue() );
    }
    mySwitch.resetAvailable();
  }
 delay(500);  
}

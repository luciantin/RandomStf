#include <RCSwitch.h>
int led = 13;
RCSwitch mySwitch = RCSwitch();
RCSwitch tran = RCSwitch();
void setup() {
  pinMode(led, OUTPUT);
 // Serial.begin(9600);
  mySwitch.enableReceive(0);
   tran.enableTransmit(10);
}





void loop() {
  
 
 
  if (mySwitch.available()) {
    
    int value = mySwitch.getReceivedValue();
 if(value== 5 ) digitalWrite(led, HIGH);
else digitalWrite(led, LOW);
    mySwitch.resetAvailable();
  }
 delay(500);  
}

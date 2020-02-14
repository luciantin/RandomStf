#include <RCSwitch.h>
int a;
RCSwitch mySwitch = RCSwitch();
RCSwitch tran = RCSwitch();
void setup() {
 Serial.begin(9600);
  mySwitch.enableReceive(0);
   tran.enableTransmit(13);
}

void loop() {
  if (mySwitch.available()) {
    
    int value = mySwitch.getReceivedValue();
    
    if (value == 0) {
     // Serial.print("Unknown encoding");
    a=0;
    } else {
     Serial.print("Received ");
     Serial.println( mySwitch.getReceivedValue() );
        
     tran.send(6, 24);
       delay(60);
         tran.send(6, 24);
    }
    mySwitch.resetAvailable();
  }
 

}

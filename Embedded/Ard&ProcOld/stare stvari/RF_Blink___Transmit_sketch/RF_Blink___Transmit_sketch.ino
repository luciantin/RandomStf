/*
RF Blink - Transmit sketch
Transmitter: FS1000A - piše na njemu
*/

#define rfTransmitPin 4  
#define ledPin 13 
  

void setup()
{
pinMode(rfTransmitPin, OUTPUT);
pinMode(ledPin, OUTPUT);
}
void loop(){
 
digitalWrite(rfTransmitPin, HIGH);     // šajle  HIGH signal                           
digitalWrite(ledPin, HIGH);  
delay(1000);                           // čeka sekundu

digitalWrite(rfTransmitPin,LOW);      // šajle LOW signal

digitalWrite(ledPin, LOW);            
delay(1200);   // čeka sekundu

}     


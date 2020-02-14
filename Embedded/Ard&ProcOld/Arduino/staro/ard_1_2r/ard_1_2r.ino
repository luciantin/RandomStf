 #include <RCSwitch.h>

RCSwitch Predajnik = RCSwitch();
RCSwitch Prijamnik = RCSwitch();
int led=13;

void setup() {
  

  
    Serial.begin(9600); 
    
    Predajnik.enableTransmit(10);
    Prijamnik.enableReceive(0);  //interupt - pin 2
   
    Predajnik.setRepeatTransmit(5);
}
 
 
int primanje ()
{

boolean primljeno=false;
int i=0;
  
while(primljeno==false)
{
  
if (Prijamnik.available()) 
{
int podatak = Prijamnik.getReceivedValue();
Prijamnik.resetAvailable();
return podatak;
//primljeno=true;
}  
if(i==10000) return 0;
i++;
}

}
 
 
 
 
 
 void loop() {
   
int primljeno;


   if (Serial.available()) 
   {
      char Serial_pod = Serial.read(); 

      if(Serial_pod=='L') Predajnik.send(1, 24);
      else if (Serial_pod=='D') Predajnik.send(2, 24);
      else if (Serial_pod=='N') Predajnik.send(3, 24);
   }

}
 
 

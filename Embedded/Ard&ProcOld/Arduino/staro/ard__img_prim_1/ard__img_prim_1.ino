#include <RCSwitch.h>

int Kotac_1 = 8;
int Kotac_2 = 7;
RCSwitch Prijamnik = RCSwitch();


void setup() {                
 Prijamnik.enableReceive(0);
 pinMode(Kotac_1, OUTPUT);    
 pinMode(Kotac_1, OUTPUT);      
}


////////////////////////////

void kretanje(int smjer)
{
 
  if(smjer==10) //stop
  {
  digitalWrite(Kotac_2, LOW);   
  digitalWrite(Kotac_1, LOW);   
  }
 
   if(smjer==1)
  {
  digitalWrite(Kotac_2, HIGH);   
  digitalWrite(Kotac_1, LOW);   
  }
 
  if(smjer==1)
  {
  digitalWrite(Kotac_2, HIGH);   
  digitalWrite(Kotac_1, LOW);   
  }

digitalWrite(Kotac_1, HIGH);
digitalWrite(Kotac_2, LOW);   
delay(100);     
digitalWrite(Kotac_2, HIGH);
digitalWrite(Kotac_1, LOW);   
delay(100); 

}

///////////////////////////

void loop() {
int primljeni_podatak ;
  if (Prijamnik.available()) 
  {
   primljeni_podatak  = Prijamnik.getReceivedValue();
    Prijamnik.resetAvailable();
  }
 
 if(primljeni_podatak<=3&&primljeni_podatak>=1) kretanje(primljeni_podatak);
 if(primljeni_podatak==10) kretanje(10);
 
  
  
}











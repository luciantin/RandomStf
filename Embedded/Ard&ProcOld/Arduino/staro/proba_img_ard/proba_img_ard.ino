#include <RCSwitch.h>

RCSwitch Predajnik = RCSwitch();
RCSwitch Prijamnik = RCSwitch();

int led=13;

void setup() {
  
    Serial.begin(9600); 
    
    Predajnik.enableTransmit(10);
    Prijamnik.enableReceive(0);  //interupt - pin 2
    Predajnik.setRepeatTransmit(1);
    Predajnik.setPulseLength(380);
    pinMode(led, OUTPUT);     
}


void loop() 
{

  if(Serial.available() > 0)
    {
        
        
        String Serial_Podatak = Serial.readStringUntil('\n');
             
        int broj=Serial_Podatak.toInt();
        
        if (Serial_Podatak=="Stop")  
        {
        Predajnik.send(10, 24);
        Predajnik.send(10, 24);
        Predajnik.send(10, 24);
        }
        else if (Serial_Podatak=="Desno") Predajnik.send(1, 24);
        else if (Serial_Podatak=="Lijevo") Predajnik.send(2, 24);
        else if (Serial_Podatak=="Napred") Predajnik.send(3, 24);
        else if (broj<400) Predajnik.send(broj, 24);
        
            
  }
       
   


}




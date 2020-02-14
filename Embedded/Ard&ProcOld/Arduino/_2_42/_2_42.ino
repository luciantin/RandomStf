#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

const uint64_t Adrese[2] = { 0xF0F0F0F0E1LL, 0xF0F0F0F0D2LL };
int Serial_Podatak_int=0,Primljeni_podatak;
String Serial_Podatak;
long vrijeme_ser_prim;

RF24 radio(9,10); 
long vrijeme;

void setup()  
{
  Serial.begin(9600);
  radio.begin();
  radio.openWritingPipe(Adrese[0]);
  radio.openReadingPipe(1,Adrese[1]);
  radio.stopListening();
}

int Primanje()
{
  boolean primio=false;
radio.startListening();
  while(primio==false)
  {
    if ( radio.available() )
    {    
      radio.read( &Primljeni_podatak, sizeof(Primljeni_podatak) );
    if(vrijeme_ser_prim>300)
  {
    Serial.println(Primljeni_podatak);
  vrijeme_ser_prim=millis();
  }
      Primljeni_podatak=0;
      primio=true; 
      vrijeme=millis();
    }
    else if(millis()-vrijeme>1000) 
    {
      Primljeni_podatak=1;
  Serial.println(Primljeni_podatak);
      primio=true;
      vrijeme=millis();
    }
  }
}

void Slanje(int kod)
{
radio.stopListening();
for(int i=0;i<=2;i++) radio.write( &kod, sizeof(kod) );
}


int Senzor(int ponavljanje)
{
vrijeme_ser_prim=millis();
Slanje(Serial_Podatak_int);
Primanje();
//Serial.println(Primljeni_podatak);
//if(Primljeni_podatak==1) return Senzor(ponavljanje-1);
}

void loop()   
{
  if(Serial.available())
  {
  Serial_Podatak =  Serial.readStringUntil('\n');
  Serial_Podatak_int=Serial_Podatak.toInt();
  if(Serial_Podatak_int==901) 
  {
  vrijeme=millis();
  Serial.println("902");
  }
  if(Serial_Podatak_int>=500&&Serial_Podatak_int<600) Senzor(5);
  Slanje(Serial_Podatak_int);
  }
}







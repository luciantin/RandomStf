#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

const uint64_t Adrese[2] = { 0xF0F0F0F0E1LL, 0xF0F0F0F0D2LL };
int Serial_Podatak_int=0,Primljeni_podatak;
String Serial_Podatak;
long vrijeme_ser_prim;

#define J_Y  A0
#define J_X  A1
#define J_G  8


int J_G_stanje;
int A_J_Y;
int A_J_X;
boolean Skretanje=false;
int Vrijeme_D_P=millis();

RF24 radio(9,10); 
long vrijeme;

void Joy_stanje()
{
J_G_stanje = digitalRead(J_G); 
A_J_Y = analogRead(J_Y); 
A_J_X = analogRead(J_X);
}

void setup()  
{
  Serial.begin(9600);
  radio.begin();
  radio.openWritingPipe(Adrese[0]);
  radio.openReadingPipe(1,Adrese[1]);
  radio.stopListening();
  pinMode(J_G, INPUT);
  digitalWrite(J_G,HIGH);
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
Joy_stanje();


if(J_G_stanje==0&&Vrijeme_D_P<100) 
{
Vrijeme_D_P=millis();
!Skretanje;
}/*
else 
{
Vrijeme_D_P=millis();
Slanje(6);
}
*/
Serial.println(Skretanje);

if(A_J_Y<400&&A_J_X<400) Slanje(7); //NAPRED DESNO
else if(A_J_Y<400&&A_J_X>600) Slanje(8); //NAPRED LIJEVO

else if(A_J_Y>600&&A_J_X<400) Slanje(9); //NAZAD DESNO
else if(A_J_Y>600&&A_J_X>600) Slanje(10); //NAZAD LIJEVO

else if(A_J_Y<400) Slanje(3);
else if(A_J_Y>600) Slanje(2);
else if(A_J_X<400) Slanje(4);
else if(A_J_X>600) Slanje(5);
delay(20);
}




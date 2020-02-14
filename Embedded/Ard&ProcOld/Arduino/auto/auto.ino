/*
digitalWrite(Kotac_1_2, HIGH);  <-- NAPRED
 digitalWrite(Kotac_2_2, HIGH);
 
 //**\\ BRZINA //**\\
 
 101 - 199
 
 //**\\ SMJER //**\\
 
 1 - STOP
 2 - NAPRED
 3 - NAZAD
 4 - LIJEVO
 5 - DESNO
 6 - NAZAD_DESNO
 6 - NAZAD_LIJEVO
 
 
 */
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <dht.h>

dht DHT;
#define DHT11_PIN 8
const uint64_t pipes[2] = {0xF0F0F0F0E1LL, 0xF0F0F0F0D2LL };

RF24 radio(9,10);
int Primljeni_podatak=0,Primljena_brzina=0;
int podaci=0;

int Enable_A = 5;
int Enable_B = 3;
int Kotac_1_1 = 4;
int Kotac_1_2 = 2;
int Kotac_2_1 = 7;
int Kotac_2_2 = 6;
int mn_brzine=30;
 //int chk = DHT.read11(DHT11_PIN);

void setup() 
{
 
  pinMode(Enable_A, OUTPUT);    
  pinMode(Enable_B, OUTPUT);    
  pinMode(Kotac_1_1, OUTPUT);    
  pinMode(Kotac_1_2, OUTPUT);    
  pinMode(Kotac_2_1, OUTPUT);    
  pinMode(Kotac_2_2, OUTPUT);
  digitalWrite(Enable_A, HIGH);
  digitalWrite(Enable_B, HIGH);
  digitalWrite(Kotac_1_2, LOW);
  digitalWrite(Kotac_1_1, LOW);
  digitalWrite(Kotac_2_2, LOW);
  digitalWrite(Kotac_2_1, LOW);    
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(1,pipes[0]);
  radio.openWritingPipe(pipes[1]);
  radio.startListening();
    
}

void Primanje()
{
  boolean primio=false;
  long vrijeme=millis();
  //radio.startListening();
radio.startListening();
  while(primio==false)
  {
    if ( radio.available() )
    {    
      radio.read( &Primljeni_podatak, sizeof(Primljeni_podatak) );
      F_dek(Primljeni_podatak);
      primio=true; 
      vrijeme=millis();
    }
    else if(millis()-vrijeme>600) 
    {
      Primljeni_podatak=1;
      F_dek(Primljeni_podatak);
    }
  }
}

void Slanje(int kod)
{
  radio.stopListening();
  delay(20);
  for(int i=0;i<=15;i++) radio.write( &kod, sizeof(kod) );
}

void Kratko_slanje(int kod)
{
  radio.stopListening();
  delay(20);
  for(int i=0;i<=1;i++) radio.write( &kod, sizeof(kod) );
}

void Smjer (int kod)
{ 
 // Serial.print(kod);
  //radio.stopListening();
  if(kod==1) 
  {
    digitalWrite(Kotac_1_2, LOW);
    digitalWrite(Kotac_1_1, LOW);
    digitalWrite(Kotac_2_2, LOW);
    digitalWrite(Kotac_2_1, LOW);
    analogWrite(Enable_A, 0);
    analogWrite(Enable_B, 0);
   }

  else if(kod==3) //napred
  {
    digitalWrite(Kotac_2_1, HIGH);
    digitalWrite(Kotac_1_1, HIGH);
    analogWrite(Enable_A, mn_brzine*Primljena_brzina); 
    analogWrite(Enable_B, mn_brzine*Primljena_brzina-40);    
  }
 
  else if(kod==2) //nazad
  {
    digitalWrite(Kotac_2_2, HIGH);
    digitalWrite(Kotac_1_2, HIGH);
    analogWrite(Enable_A, mn_brzine*Primljena_brzina); 
    analogWrite(Enable_B, mn_brzine*Primljena_brzina-40);    
  } 
 
   else if(kod==4) 
  {
   digitalWrite(Kotac_1_2, HIGH);
   analogWrite(Enable_A, mn_brzine*Primljena_brzina);
  } 
  
   else if(kod==5) 
  {
   digitalWrite(Kotac_2_2, HIGH);
   analogWrite(Enable_B, mn_brzine*Primljena_brzina-40);
   } 
Primljeni_podatak=0; 
}

void Senzor(int broj)
{
DHT.read11(DHT11_PIN);  
int Vl_zraka=DHT.humidity;
int Temp=DHT.temperature;
Serial.println(Vl_zraka);
Serial.println(Temp);
if(broj==2) Slanje(Vl_zraka);
if(broj==3) Slanje(Temp);
}

void F_dek (int kod)
{
  //Serial.println(kod);
  if(kod<199&&kod>=101) Primljena_brzina=kod%100;
  if(kod<99&&kod>=1) Smjer(kod);
  if(kod==500) Kratko_slanje(501);
  if(kod>500&&kod<600) Senzor(kod%100);
}


void loop() 
{
Primanje();
}




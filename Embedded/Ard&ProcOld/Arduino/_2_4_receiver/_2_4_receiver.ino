#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

const uint64_t pipes[2] = { 0xF0F0F0F0E1LL, 0xF0F0F0F0D2LL };

RF24 radio(9,10);

int podaci;


void setup()   
{
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(1,pipes[0]);
  radio.openWritingPipe(pipes[1]);
  radio.startListening();
}

void Slanje(int kod)
{
radio.stopListening();
delay(20);
for(int i=0;i<=5;i++) radio.write( &kod, sizeof(kod) );
}

void loop()   
{

  if ( radio.available() )
  {    
  radio.read( &podaci, sizeof(podaci) );
  Serial.println(podaci);
  if(podaci==10001) Slanje(324);
  }
  
  
}








#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

const uint64_t adrese [2] = { 0xF0F0F0F0E1LL, 0xF0F0F0F0D2LL };
int podatak;

RF24 radio(9,10);

void setup()    
{
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(1,adrese[0]);
  radio.startListening();
} 

void loop()  
{
  if ( radio.available() )
  {
    bool done = false;
    while (!done)
    {
      done = radio.read( &podatak, sizeof(podatak) );
      Serial.println(podatak);
    }
  }
} 































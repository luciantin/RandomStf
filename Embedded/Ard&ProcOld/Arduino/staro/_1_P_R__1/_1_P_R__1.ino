
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

const uint64_t pipe = 0xF0F0F0F0E1LL; 

int podatak=2937;

RF24 radio(9,10);

void setup()   
{
  Serial.begin(9600);
  radio.begin();
  radio.openWritingPipe(pipe);
  radio.stopListening();
}


void loop()  
{
   radio.write( &podatak, sizeof(podatak) );
}

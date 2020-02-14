 
#include <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"

RF24 radio(9,10);

const uint64_t pipes[2] = { 0xF0F0F0F0E1LL, 0xF0F0F0F0D2LL };

void setup(void)
{
 
  Serial.begin(9600);
 
  radio.begin();

// radio.setRetries(15,15);

// radio.setPayloadSize(8);

    radio.openWritingPipe(pipes[0]);
  //  radio.openReadingPipe(1,pipes[1]);
   radio.stopListening();

}

void loop(void)
{
 
   
  

     
  unsigned long time = 53284;
   
   for(int i=0;i<15;i++) radio.write( &time, sizeof(unsigned long) );
    Serial.println(time);
     
    delay(100);
}


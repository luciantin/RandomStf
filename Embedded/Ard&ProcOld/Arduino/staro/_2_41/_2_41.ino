#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
/*-----( Declare Constants and Pin Numbers )-----*/

// NOTE: the "LL" at the end of the constant is "LongLong" type
const uint64_t pipe = 0xE8E8F0F0E1LL; // Define the transmit pipe


/*-----( Declare objects )-----*/
RF24 radio(9,10); // Create a Radio
/*-----( Declare Variables )-----*/
int joystick[2];  // 2 element array holding Joystick readings

void setup()   /****** SETUP: RUNS ONCE ******/
{
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(1,pipe);
  radio.startListening();;
}//--(end setup )---


void loop()   /****** LOOP: RUNS CONSTANTLY ******/
{
  if ( radio.available() )
  {
    // Read the data payload until we've received everything
    bool done = false;
    while (!done)
    {
      // Fetch the data payload
      done = radio.read( joystick, sizeof(joystick) );
      Serial.print("X = ");
      Serial.print(joystick[0]);
      Serial.print(" Y = ");      
      Serial.println(joystick[1]);
    }
  }
  else
  {    
      Serial.println("No radio available");
  }

}//--(end main loop )---

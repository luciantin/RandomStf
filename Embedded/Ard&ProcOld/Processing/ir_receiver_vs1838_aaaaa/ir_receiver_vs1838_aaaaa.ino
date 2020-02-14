/*
 * IRremote: IRrecvDemo - demonstrates receiving IR codes with IRrecv
 * An IR detector/demodulator must be connected to the input RECV_PIN.           http://arduino-info.wikispaces.com/IR-RemoteControl
 * Version 0.1 July, 2009
 * Copyright 2009 Ken Shirriff
 * http://arcfn.com
 */

#include <IRremote.h>
int led1 = 2;
int led2 = 3;
int RECV_PIN = 11;

IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
   pinMode(led1, OUTPUT);
    pinMode(led2, OUTPUT);
}

void loop() {
  if (irrecv.decode(&results)) {
    
    irrecv.resume(); // Receive the next value
  }
  
  switch(results.value)

  {

  case 0xFF02FD:  
    Serial.println(" tin            "); 
    break;

  case 0xFF629D:  
    Serial.print(" lucian             "); 
    break;

  

  }

  
}



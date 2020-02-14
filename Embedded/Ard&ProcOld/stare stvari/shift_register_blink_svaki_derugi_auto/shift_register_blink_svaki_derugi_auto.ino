int latchPin = 5; // pin 12  st_cp

int clockPin = 6; // pin 11 sh_cp
int dataPin = 4; // ds pin 14
 int led ;
byte leds = 0;
 
void setup()
{
pinMode(latchPin, OUTPUT);
pinMode(dataPin, OUTPUT);
pinMode(clockPin, OUTPUT);
updateShiftRegister();

}
 
void loop()
{
 
  
  
bitSet(leds, 1);  
bitSet(leds, 3);
bitSet(leds, 5);
bitSet(leds, 7);
updateShiftRegister();
delay(500);
leds = 0;
updateShiftRegister();
delay(10); 
bitSet(leds, 0);  
bitSet(leds, 2);
bitSet(leds, 4);
bitSet(leds, 6);
updateShiftRegister();

delay(500); 
leds = 0;
updateShiftRegister();
delay(10); 

}

 
void updateShiftRegister()
{
digitalWrite(latchPin, LOW);
shiftOut(dataPin, clockPin, LSBFIRST, leds);
digitalWrite(latchPin, HIGH);
}

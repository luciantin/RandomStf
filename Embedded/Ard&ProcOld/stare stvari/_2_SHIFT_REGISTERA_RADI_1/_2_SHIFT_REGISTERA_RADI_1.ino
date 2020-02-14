int dataPin = 9;              
int latchPin = 8;             
int clockPin = 7;             
int seq[14] = {
  1,2,4,8,16,32,64,128,64,32,16,8,4,2};
int seq2[14] = {
  128,64,32,16,8,4,2,1,2,4,8,16,32,64};
int value = 0;
int value2 = 0;

void setup()
{
  pinMode(dataPin, OUTPUT);    // Configure Digital Pins
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
}

void loop()
{
  for (int n=0; n < 14; n++)
  {
    value = seq[n];             // 1. shift reg.
    value2 = seq2[n];          //2. shift reg.
    writeOutput();
    delay(1000);
  }
}

void writeOutput()
{
  digitalWrite(latchPin, LOW);                       // Pull latch LOW to send data
  shiftOut(dataPin, clockPin, MSBFIRST, value);      // Send the data byte 1
  shiftOut(dataPin, clockPin, MSBFIRST, value2);     // Send the data byte 2
  digitalWrite(latchPin, HIGH);                      // Pull latch HIGH to stop sending data
}



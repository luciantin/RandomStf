int brightness = 0;   
int fadeAmount = 1;   
unsigned long currentTime;
unsigned long loopTime;
const int pin_A = 12;  
const int pin_B = 11;  
unsigned char encoder_A;
unsigned char encoder_B;
unsigned char encoder_A_prev=0;

int dataPin = 9;              
int latchPin = 8;             
int clockPin = 7;             
int seq[15] = {  1,2,4,8,16,32,64,128,64,32,16,8,4,2,1};
int seq2[15] = {  128,192,224,240,248,252,254,255,254,252,248,240,224,192,128};
int value = 0;
int value2 = 0;


void setup()  {
  
   pinMode(dataPin, OUTPUT);    // Configure Digital Pins
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  
  
  pinMode(pin_A, INPUT);
  pinMode(pin_B, INPUT);
  currentTime = millis();
  loopTime = currentTime; 
 Serial.begin (9600);
} 

void loop()  {
  // get the current elapsed time
  currentTime = millis();
  if(currentTime >= (loopTime + 5)){
    // 5ms since last check of encoder = 200Hz  
    encoder_A = digitalRead(pin_A);    // Read encoder pins
    encoder_B = digitalRead(pin_B);   
    if((!encoder_A) && (encoder_A_prev)){
      // A has gone from high to low 
      if(encoder_B) {
        // B is high so clockwise
        // increase the brightness, dont go over 255
        if(brightness + fadeAmount <= 14) brightness += fadeAmount;               
      }   
      else {
        // B is low so counter-clockwise      
        // decrease the brightness, dont go below 0
        if(brightness - fadeAmount >= 0) brightness -= fadeAmount;               
      }   

    }   
    encoder_A_prev = encoder_A;     // Store value of A for next time    
   
  
    loopTime = currentTime;  // Updates loopTime
  }
  // Other processing can be done here
   Serial.println (brightness);
  
  
    value = seq[brightness];             // 1. shift reg.
    value2 = seq2[brightness];          //2. shift reg.
    writeOutput();
                          
}



void writeOutput()
{
  digitalWrite(latchPin, LOW);                       // Pull latch LOW to send data
  shiftOut(dataPin, clockPin, MSBFIRST, value);      // Send the data byte 1
  shiftOut(dataPin, clockPin, MSBFIRST, value2);     // Send the data byte 2
  digitalWrite(latchPin, HIGH);                      // Pull latch HIGH to stop sending data
}


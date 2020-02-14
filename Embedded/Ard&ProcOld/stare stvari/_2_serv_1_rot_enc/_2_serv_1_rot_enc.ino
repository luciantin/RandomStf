int buttonState = 0; 
int brightness = 90;   
int fadeAmount = 10;   
unsigned long currentTime;
unsigned long loopTime;
const int pin_A = 2;  
const int pin_B = 3;  
unsigned char encoder_A;
unsigned char encoder_B;
unsigned char encoder_A_prev=0;
#include <Servo.h> 
int tin;
const int buttonPin = 12;
Servo myservo1;  
   Servo myservo2;  

void setup()  {
   myservo1.attach(9);
myservo2.attach(10);
   pinMode(buttonPin, INPUT);    
  pinMode(pin_A, INPUT);
  pinMode(pin_B, INPUT);
  currentTime = millis();
  loopTime = currentTime; 
 Serial.begin (9600);
} 

void loop()  {
 
 
  currentTime = millis();
  if(currentTime >= (loopTime + 5)){
   
    encoder_A = digitalRead(pin_A);   
    encoder_B = digitalRead(pin_B);   
    if((!encoder_A) && (encoder_A_prev)){
    
      if(encoder_B) {
        
        if(brightness + fadeAmount <= 180) brightness += fadeAmount;               
      }   
      else {
        
        if(brightness - fadeAmount >= -9) brightness -= fadeAmount;               
      }   

    }   
    encoder_A_prev = encoder_A;      
   
  
    loopTime = currentTime; 
  }
 
 
 
 buttonState = digitalRead(buttonPin);
 if (buttonState == LOW) 
 {     
    tin=0;
  } 
  else 
  {
    tin=1;
    
  }
  
 
 Serial.println (tin);
 
 if (tin=0) myservo1.write(brightness);    
 if (tin=1) myservo2.write(brightness); 
 
 
                        
}


int brightness = 90;   
int fadeAmount = 10;   
unsigned long currentTime;
unsigned long loopTime;
const int pin_A = 8;  
const int pin_B = 7;  
unsigned char encoder_A;
unsigned char encoder_B;
unsigned char encoder_A_prev=0;

const int buttonPin = 6;    
const int ledPin =  13;      


int buttonState = 0;        
 int z;

#include <Servo.h> 
Servo myservo1; 
Servo myservo2;  
Servo myservo3;
Servo  a;
void setup()  {
  
   pinMode(ledPin, OUTPUT);      
  
  pinMode(buttonPin, INPUT);   
  
  myservo2.attach(11);
  myservo3.attach(10);
  myservo1.attach(9);
  pinMode(pin_A, INPUT);
  pinMode(pin_B, INPUT);
  currentTime = millis();
  loopTime = currentTime; 
  Serial.begin (9600);
} 

void loop()  {



  
 buttonState = digitalRead(buttonPin);

  
  if (buttonState == HIGH) {     
  z++;
   
  
  } 
  
  Serial.println (z);


  if(z==4)
  {
  z=1;
  }
  
  delay(50);
 
  if (z=1) myservo1.write(brightness);
  if (z=2) myservo2.write(brightness);
  if (z=3) myservo3.write(brightness);

   

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

  Serial.println (brightness);






}



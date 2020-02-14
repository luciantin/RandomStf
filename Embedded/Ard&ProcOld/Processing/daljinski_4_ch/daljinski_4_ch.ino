const int buttonPin1 = 2;   
const int buttonPin2 = 3;  
const int buttonPin3 = 4;  
const int buttonPin4 = 5;  
    
int buttonState1 = 0;        

int buttonState2 = 0;       
        
int buttonState3 = 0;       

int buttonState4 = 0;         

void setup() {
 pinMode(buttonPin1, INPUT);     
     pinMode(buttonPin2, INPUT);     
  pinMode(buttonPin3, INPUT);     
  pinMode(buttonPin4, INPUT);
 Serial.begin(9600); 
}



void loop(){
 
  buttonState1 = digitalRead(buttonPin1);
buttonState2 = digitalRead(buttonPin2);
buttonState3 = digitalRead(buttonPin3);
buttonState4 = digitalRead(buttonPin4);
  if (buttonState1 == HIGH) 
  {     
 Serial.println(1);  
  } 
  
  else if (buttonState2 == HIGH) 
  {     
 Serial.println(2);  
  } 
  
  
  
  else 
  {
  delay (10);
  }
  
  
  
  
  
}

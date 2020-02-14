
int red;
int green;
int blue;

const int redPin = 11;
const int greenPin = 10;
const int bluePin = 9;

void setup() {
 
  Serial.begin(9600);
  
  pinMode(redPin, OUTPUT); 
  pinMode(greenPin, OUTPUT); 
  pinMode(bluePin, OUTPUT); 

}

void loop() {
   
  if (Serial.available() > 1)
  {
    red = Serial.parseInt();    
    green = Serial.parseInt();    
    blue = Serial.parseInt();      
    Serial.println(red);
    Serial.println(green);
    Serial.println(blue);
    
}
     
    
      analogWrite(redPin, red);
      analogWrite(greenPin, green);
      analogWrite(bluePin, blue);
  
  
}


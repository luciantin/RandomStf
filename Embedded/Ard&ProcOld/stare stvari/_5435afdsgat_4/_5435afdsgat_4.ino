
JoyState_t joySt;
int sensorPin = A0;   
int buttonPin = 2;
int sensorValue = 0; 
int buttonState = 0;
int a;

void setup() {
joySt.xAxis = 0;
joySt.yAxis = 0;
joySt.zAxis = 0;
joySt.xRotAxis = 0;
joySt.yRotAxis = 0;
joySt.zRotAxis = 0;
joySt.throttle = 0;
joySt.rudder = 0;
joySt.hatSw1 = 0;
joySt.hatSw2 = 0;
joySt.buttons = 0;
pinMode(buttonPin, INPUT);     
 Serial.begin(9600); 
}

void loop() {
joySt.yAxis = 0;
joySt.zAxis = 0;
joySt.xRotAxis = 0;
joySt.yRotAxis = 0;
joySt.zRotAxis = 0;
joySt.throttle = 0;
joySt.rudder = 0;
joySt.hatSw1 = 0;
joySt.hatSw2 = 0;
joySt.buttons = 0;

  sensorValue = analogRead(sensorPin);
  a = map(sensorValue, 1, 1023, 0, 255); 
  Serial.println(a);
  joySt.xAxis=a;
  joySt.xRotAxis = a;
 
 
  buttonState = digitalRead(buttonPin);
 
  if (buttonState == HIGH) {     
 
    
  } 
  else {
   
    
  }
 

  
  Joystick.setState(&joySt);
}

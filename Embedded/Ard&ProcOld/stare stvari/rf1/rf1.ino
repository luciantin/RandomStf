 #define rfReceivePin A0  //RF Receiver pin = Analog pin 0
 #define ledPin 13        //Onboard LED = digital pin 13
int a;

 unsigned int data = 0;   // variable used to store received data
 const unsigned int upperThreshold = 70;  //upper threshold value
 const unsigned int lowerThreshold = 50;  //lower threshold value

 void setup(){
   pinMode(ledPin, OUTPUT);
   Serial.begin(9600);
 }

 void loop(){
   data=analogRead(rfReceivePin);
  a = map(data, 0, 1023, 0, 255);    //listen for data on Analog pin 0
  Serial.println( a);
  
  
    if(data>140) digitalWrite(ledPin,HIGH);
   else digitalWrite(ledPin,LOW);
delay(100);
}

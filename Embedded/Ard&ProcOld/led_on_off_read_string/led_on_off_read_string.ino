#include <RCSwitch.h>

RCSwitch mySwitch = RCSwitch();
RCSwitch tran = RCSwitch();

int led = 13;
String data; 

void setup()
{
pinMode(led, OUTPUT);
Serial.begin(9600);
}
 
void loop()
{

if (Serial.available())
{
data = Serial.readStringUntil('\n');
//data-=48;
Serial.println(data);

if(data=="s1") digitalWrite(led, HIGH);
else digitalWrite(led, LOW);

}

}


 
 

#include <RCSwitch.h>

RCSwitch mySwitch = RCSwitch();
RCSwitch tran = RCSwitch();
bool zastava;
int led = 13;
String data; 

void setup()
{
  mySwitch.enableReceive(0);
  tran.enableTransmit(10);
  pinMode(led, OUTPUT);
  mySwitch.setRepeatTransmit(5);
  Serial.begin(9600);
}

void loop()
{

  if (Serial.available())
  {
    data = Serial.readStringUntil('\n');

    Serial.println(data);

    if(data=="s2") tran.send(2, 24);
    if(data=="s3") tran.send(3, 24);
    if(data=="r2")
    {
      tran.send(22, 24);
      delay(10);
      while(zastava==false)
      {
        if (mySwitch.available())
        {
          int value = mySwitch.getReceivedValue();
          if (value == 8)  
          {    
            digitalWrite(led, HIGH);
            Serial.println( mySwitch.getReceivedValue() );
            zastava=true;
          }
        }
      }
      zastava=false;
    }
    if(data=="r3")
    {
      tran.send(23, 24);
      delay(10);
      while(zastava==false)
      {
        if (mySwitch.available())
        {
          int value = mySwitch.getReceivedValue();
          if (value == 7)  
          {
            digitalWrite(led, LOW);
            Serial.println( mySwitch.getReceivedValue() );
            zastava=true;
          }
        }
      }
      zastava=false;
    }

    if(data=="reset")
    {
      delay(150);
      tran.send(5, 24);
      delay(350);
      digitalWrite(led, LOW);
    }


  }

}




float temp;
int tempPin = 0;

void setup()

{

Serial.begin(9600);

}

void loop()

{

temp = (5.0 * analogRead(tempPin) * 100.0) / 1024;

//temp *=0.48828125;

Serial.print("TEMPRATURE = ");

Serial.print(temp);

Serial.print("*C");

Serial.println();

delay(1000);

}

#define J_Y  A0
#define J_X  A1
#define J_G  8


int J_G_stanje;
int A_J_Y;
int A_J_X;


void Joy_stanje()
{
J_G_stanje = digitalRead(J_G); 
A_J_Y = analogRead(J_Y); 
A_J_X = analogRead(J_X);
}

void setup() 
{
Serial.begin(9600);
pinMode(J_G, INPUT);
digitalWrite(J_G,HIGH);
}

void loop() 
{
Joy_stanje();  

  Serial.print(J_G_stanje);
  Serial.print("      ");
  Serial.print(analogRead(J_X)); 
  Serial.print("      ");
  Serial.println(analogRead(J_Y)); 
  
  
delay(200);    
}



























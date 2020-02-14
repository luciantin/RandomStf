int Primljena_brzina;
int Enable_A = 5;
int Enable_B = 3;
int Kotac_1_1 = 4;
int Kotac_1_2 = 2;
int Kotac_2_1 = 7;
int Kotac_2_2 = 6;
int mn_brzine=40;
int brzina;
int Serial_Podatak_int;

void setup() 
{
  Serial.begin(9600);
  pinMode(Enable_A, OUTPUT);    
  pinMode(Enable_B, OUTPUT);    
  pinMode(Kotac_1_1, OUTPUT);    
  pinMode(Kotac_1_2, OUTPUT);    
  pinMode(Kotac_2_1, OUTPUT);    
  pinMode(Kotac_2_2, OUTPUT);
  digitalWrite(Enable_A, HIGH);
  digitalWrite(Enable_B, HIGH);
  digitalWrite(Kotac_1_2, LOW);
  digitalWrite(Kotac_1_1, LOW);
  digitalWrite(Kotac_2_2, LOW);
  digitalWrite(Kotac_2_1, LOW);    
 }
 
void Smjer (int kod)
{ 
 // Serial.print(kod);
  //radio.stopListening();
  if(kod==1) 
  {
    digitalWrite(Kotac_1_2, LOW);
    digitalWrite(Kotac_1_1, LOW);
    digitalWrite(Kotac_2_2, LOW);
    digitalWrite(Kotac_2_1, LOW);
    analogWrite(Enable_A, 0);
    analogWrite(Enable_B, 0);
   }

  else if(kod==3) //napred
  {
    digitalWrite(Kotac_2_1, HIGH);
    digitalWrite(Kotac_1_1, HIGH);
    analogWrite(Enable_A, mn_brzine*Primljena_brzina); 
    analogWrite(Enable_B, mn_brzine*Primljena_brzina-30);    
  }
 
  else if(kod==2) //nazad
  {
    digitalWrite(Kotac_2_2, HIGH);
    digitalWrite(Kotac_1_2, HIGH);
    analogWrite(Enable_A, mn_brzine*Primljena_brzina); 
    analogWrite(Enable_B, mn_brzine*Primljena_brzina-30);    
  } 
 
   else if(kod==4) 
  {
   digitalWrite(Kotac_1_2, HIGH);
   analogWrite(Enable_A, mn_brzine*Primljena_brzina);
  } 
  
   else if(kod==5) 
  {
   digitalWrite(Kotac_2_2, HIGH);
   analogWrite(Enable_B, mn_brzine*Primljena_brzina-30);
   } 
}



void loop() 
{
if(Serial.available())
  {
String  Serial_Podatak =  Serial.readStringUntil('\n');
 Serial_Podatak_int=Serial_Podatak.toInt();
  }
 else
 {
  if(Serial_Podatak_int>10) Primljena_brzina=Serial_Podatak_int%10; 
Smjer(Serial_Podatak_int);
 }
}












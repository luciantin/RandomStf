int Enable_A = 5;
int Enable_B = 3;
int Kotac_1_1 = 4;
int Kotac_1_2 = 2;
int Kotac_2_1 = 7;
int Kotac_2_2 = 6;
void setup() 
{
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

 
void loop() 
{
 analogWrite(Enable_A, 140); 
 analogWrite(Enable_B, 140-40);    

delay(1000); 
digitalWrite(Kotac_2_1, HIGH);

delay(1000); 
digitalWrite(Kotac_2_1, LOW);
digitalWrite(Kotac_1_1, LOW);
delay(1000); 
digitalWrite(Kotac_2_2, HIGH);
digitalWrite(Kotac_1_2, HIGH);
delay(1000);   
digitalWrite(Kotac_2_2, LOW);
digitalWrite(Kotac_1_2, LOW); /*
digitalWrite(Kotac_1_1, HIGH); 
delay(1000);  
digitalWrite(Kotac_1_1, LOW);
digitalWrite(Kotac_2_1, HIGH);
delay(1000);  
digitalWrite(Kotac_2_1, LOW); 
digitalWrite(Kotac_1_2, HIGH); 
delay(1000);  
digitalWrite(Kotac_1_2, LOW);
digitalWrite(Kotac_2_2, HIGH);*/
delay(1000);
}




















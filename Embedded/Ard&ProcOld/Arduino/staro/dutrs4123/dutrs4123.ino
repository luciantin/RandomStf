int flw_cont = 5; //1
int Kotac_1 = 4 ; //3
int Kotac_2 = 6 ; //2


void setup() {                
   pinMode(Kotac_1, OUTPUT);     
  pinMode(flw_cont, OUTPUT); 
   pinMode(Kotac_2, OUTPUT);     
    Serial.begin(9600);

}


void kretanje(String smjer)
{
  
Serial.println(smjer);
//if(smjer=="Desno")
//if(smjer=="Lijevo")
if(smjer=="napred")
{
digitalWrite(13, HIGH);
digitalWrite(Kotac_1, HIGH);
digitalWrite(Kotac_2, HIGH);
digitalWrite(flw_cont,HIGH);
}
  
Serial.println(smjer);
if(smjer=="nazad")
{
digitalWrite(Kotac_1, LOW);
digitalWrite(Kotac_2, LOW);
digitalWrite(flw_cont,HIGH);
}
if(smjer=="Stop")
{
digitalWrite(Kotac_1, LOW);
digitalWrite(Kotac_2, LOW);
digitalWrite(flw_cont,LOW);
}
if(smjer=="Nazad_Desno")
{
digitalWrite(Kotac_1, LOW);
digitalWrite(Kotac_2, LOW);
digitalWrite(flw_cont,HIGH);
}
if(smjer=="Nazad_Lijevo")
{
digitalWrite(Kotac_1, LOW);
digitalWrite(Kotac_2, LOW);
digitalWrite(flw_cont,HIGH);
}
}


void loop() {
if(Serial.available() > 0)
    {
    String Serial_Podatak = Serial.readStringUntil('\n');
    Serial.println(Serial_Podatak);
   // kretanje(Serial_Podatak);
    if(Serial_Podatak=="napred")
{
digitalWrite(13, HIGH);
digitalWrite(Kotac_1, HIGH);
digitalWrite(Kotac_2, HIGH);
digitalWrite(flw_cont,HIGH);
}
  
Serial.println(Serial_Podatak);
if(Serial_Podatak=="nazad")                                                                                        
{
digitalWrite(Kotac_1, LOW);
digitalWrite(Kotac_2, LOW);
digitalWrite(flw_cont,HIGH);
}
if(Serial_Podatak=="Stop")
{
  digitalWrite(13, LOW);
digitalWrite(Kotac_1, LOW);
digitalWrite(Kotac_2, LOW);
digitalWrite(flw_cont,LOW);
}
if(Serial_Podatak=="Nazad_Desno")
{                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    
digitalWrite(Kotac_1, LOW);
digitalWrite(Kotac_2, LOW);
digitalWrite(flw_cont,HIGH);
}
if(Serial_Podatak=="Nazad_Lijevo")
{
digitalWrite(Kotac_1, LOW);
digitalWrite(Kotac_2, LOW);
digitalWrite(flw_cont,HIGH);
}
    }          
}

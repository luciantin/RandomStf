int Y_os = A0;   
int Y_os_vrijednost = 0;  
int Y_os_pomak;
int Y_os_pocetna_vrijednost;

int X_os = A1;   
int X_os_vrijednost = 0;  
int X_os_pomak;
int X_os_pocetna_vrijednost;

int Z_os = A2;   
int Z_os_vrijednost = 0;  
int Z_os_pomak;
int Z_os_pocetna_vrijednost;

void setup() {   
Y_os_pocetna_vrijednost=analogRead(Y_os);  
X_os_pocetna_vrijednost=analogRead(X_os);
Z_os_pocetna_vrijednost=analogRead(Z_os);

 Serial.begin(9600);
}





void loop() {
  
  Y_os_vrijednost = analogRead(Y_os);
  X_os_vrijednost = analogRead(X_os);
  Z_os_vrijednost = analogRead(Z_os);
  
  if(X_os_vrijednost>X_os_pocetna_vrijednost-20 && X_os_vrijednost>X_os_pocetna_vrijednost+20) Serial.write(1);// Serial.println(1);
  else if(X_os_vrijednost<X_os_pocetna_vrijednost-20 && X_os_vrijednost<X_os_pocetna_vrijednost+20) Serial.write(2);// Serial.println(1);
  else if(X_os_vrijednost>X_os_pocetna_vrijednost-20 && X_os_vrijednost<X_os_pocetna_vrijednost+20) Serial.write(3);// Serial.println(1);
  
  
  
  //Serial.write(Y_os_vrijednost);
  delay(50);   
}
















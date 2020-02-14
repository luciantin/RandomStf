int led1 = 2;
int led2 = 3;
int led3 = 4;
int led4 = 5  ;
// the setup routine runs once when you press reset:
void setup() {                
   pinMode(led1, OUTPUT);
   pinMode(led2, OUTPUT);
   pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);     
}

// the loop routine runs over and over again forever:
void loop() {
    
  digitalWrite(led1, HIGH); 
 digitalWrite(led4, HIGH); 
  digitalWrite(led2, LOW);   
  digitalWrite(led3, LOW);  
  
 
  delay(5000); 
 
  digitalWrite(led1, LOW);   
  digitalWrite(led4, LOW);   
   
digitalWrite(led3, HIGH); 
digitalWrite(led2, HIGH); 

delay(5000); 

}

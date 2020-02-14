/*
    made by : Lucian Tin
    
   random(min, max) 

*/
const int red_1= 11;
const int green_1 = 10; 
const int blue_1 = 9;

int red [] = {0,200             };    
int green[]= {0,200             };
int bue [] = {0,200             };

int r;
int g;
int b;

void setup() {
 
  Serial.begin(9600);
 
  pinMode(red_1, OUTPUT); 
  pinMode(green_1, OUTPUT); 
  pinMode(blue_1, OUTPUT); 

}

void loop() {
   
  for (int n = 0 ; n< 5  ; n++    )
   {
   r = red [n] ;
   g = green[n];
   b = bue [n] ;
   
    boje();
    delay (500); // time between color change
   }
}




void boje()
{

      analogWrite(red_1 , r);
      analogWrite(green_1 , g);
      analogWrite(blue_1  , b);


}



















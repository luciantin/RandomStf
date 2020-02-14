/*  RANDOM RGB COLORS
    made by : Lucian Tin
    
   random(min, max) 

*/
const int red_1= 11;
const int green_1 = 10; 
const int blue_1 = 9;



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
   
 
   r = random(0, 20) ;
   g = random(0, 20) ;
   b = random(0, 20) ;
   
    boje();
    delay (500); // time between color change
  
}




void boje()
{

      analogWrite(red_1 , r);
      analogWrite(green_1 , g);
      analogWrite(blue_1  , b);


}


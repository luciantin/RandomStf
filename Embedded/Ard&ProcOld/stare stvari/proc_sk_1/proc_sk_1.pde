// import processing.serial.*;
// Serial ard1;

int misy0_pl_10 ;
int misy0_min_10 ;
int misy1_pl_10 ;
int misy1_min_10 ;


void setup() {
   
  ard1 = new Serial(this, Serial.list()[0], 9600);
  size(1600 , 900); 
 background(255); 
 frameRate(60); 

}

void draw() {


  background(255);
  fill(0);
 strokeWeight(5);
 line(1470, 50, 1470, 324);
 fill(23,27,123);
  if (mousePressed == true && mouseY >= 60    &&  mouseX >= 1420 && mouseY <=  315   &&  mouseX <= 1520 ) {
 
 misy1_pl_10 = mouseY+10 ;
 misy1_min_10 = mouseY-10 ;
misy0_pl_10 =  misy1_pl_10   ;
misy0_min_10 =   misy1_min_10   ;
      
  }
  else 
{
  misy0_pl_10 =  misy1_pl_10   ;
misy0_min_10 =   misy1_min_10   ;

}
  
  ard1.write(misy0_min_10);
  
  quad(1460, misy0_pl_10, 1480,misy0_pl_10, 1480,misy0_min_10, 1460,misy0_min_10);
}




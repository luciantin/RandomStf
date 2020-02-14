import processing.serial.*;
boolean zastava=false;
Serial Port_1; 
int primljen_podatak;
int broj_ser_port;
int prosli_primljen_podatak;
int x,y;

int primanje_podataka()
{
  primljen_podatak=0;
 while (Port_1.available () > 0)
 {
    primljen_podatak = Port_1.read();
 // println(primljen_podatak);
  }
     return primljen_podatak;
}


void setup() {
  size(960,720);
  x=width/2 ;
  y= height/2;
  println(Serial.list());
  Port_1 = new Serial(this, Serial.list()[1], 9600);
  textSize(32);
  fill(165, 27, 27);
}
 
void draw() {
  background(200);
 //primanje_podataka();
 //println(primljen_podatak);
prosli_primljen_podatak=primljen_podatak;
 while (Port_1.available () > 0)
 {
    primljen_podatak = Port_1.read();
  println(primljen_podatak);
  }
  fill(255);
ellipse(x, y, 100, 100);
 if(primljen_podatak==1&&primljen_podatak!=prosli_primljen_podatak) 
 {
 x+=100;
 }
 if(primljen_podatak==3&&primljen_podatak!=prosli_primljen_podatak) 
 {
 x=width/2;
 }
 if(primljen_podatak==2&&primljen_podatak!=prosli_primljen_podatak) 
 {
 x-=100;
 }
 
 
 // text(char(inByte), width/2, height/2);
}













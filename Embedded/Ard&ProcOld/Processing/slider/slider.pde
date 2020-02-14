
int bpoz1,R,G,B;
float boja1, e,vex,vey;
void setup() {
   bpoz1 = 255 ;
  size(640, 360); 
 background(bpoz1); 
 frameRate(5000); 

}

void odabirboje1 ()
{ 
  if (mouseX < 510 && mouseX > 490 && mouseY > 40 && mouseY < 60)
  {
  vex= 10;
  vey= 10;
  R =0;
  G=0;
  B =0;
   }
}

void draw() {
  fill(0);
  quad(50,50,100, 60,70,70,50,50);
 odabirboje1 ();
 
  

}


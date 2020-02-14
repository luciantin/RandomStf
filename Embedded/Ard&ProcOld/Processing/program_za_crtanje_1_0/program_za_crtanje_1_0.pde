
int bpoz1,R,G,B;
float boja1, e,vex,vey;
int num = 60;
float mx[] = new float[num];
float my[] = new float[num];

void setup() {
   bpoz1 = 255 ;
  size(640, 360); 
 background(bpoz1); 
 frameRate(5000); 

}


void mouseWheel(MouseEvent event) {
 e = event.getAmount();
  println(e);
 
  
  
}


void crtanje()
{  
fill(R,G,B);
ellipse(mouseX,mouseY,vex,vey);
noStroke();
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
void pozadina()
{  
   if(keyPressed)
      {
      if (key== 'a' || key== 'A')
      {
     exit();
      }
      else if (key== 's' || key== 'S')
      {
      background(bpoz1);
      R =bpoz1;
      G=bpoz1;
      B =bpoz1;
      fill(random(5));
      ellipse(500,50,10,10);
      }
       if (key== 'd' || key== 'D' )
      {
         background(51);
        fill(255, 153);
   int which = frameCount % num;
  mx[which] = mouseX;
  my[which] = mouseY;
  
  for (int i = 0; i < num; i++) {
    // which+1 is the smallest (the oldest in the array)
    int index = (which+1 + i) % num;
    ellipse(mx[index], my[index], i, i);
  }
      }
     
      }
}
void draw() {
  
  ellipse(500,50,10,10);
 odabirboje1 ();
 crtanje();
 pozadina(); 

}


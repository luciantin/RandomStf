




void setup() {
  
  size(960,720);
 background(255); 
 frameRate(60); 

}

void draw() {
  
  background(255); 
  textSize(32);
  fill(165, 27, 27);
  int a = mouseX;
  int b = mouseY;
 text( a, 220, height/2);
 text( b, 350, height/2);
 
 ellipse(mouseX,mouseY,5,5);

}







boolean b;
boolean pmousePressed;
 
void setup(){
  size(400,400);
  background(255);
  pmousePressed = false;
  b = false;
}
 
void draw() {
  fill(125);
   
  
   
  if((mouseX <= 250) && (mouseX >= 150) && (mouseY <= 200) && (mouseY >= 150) && mousePressed && (!pmousePressed)) {
    b = !b;
  }
   
  if (b == true) {
   fill(255,0,0);
  }
 
  rect(150,150,100,50);
  pmousePressed = mousePressed;
} 


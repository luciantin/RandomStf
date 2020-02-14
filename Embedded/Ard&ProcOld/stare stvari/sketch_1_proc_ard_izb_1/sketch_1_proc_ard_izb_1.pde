String poc1 = "Dobrodošli na glavni izbornik";
String izb1 = "1 - potencjometar";
String izb2 = "2 - Led diode";
String izb3 = "3 - svjetlina";
String izb4 = "4 - gumb";


void setup() {
  
  size(640,480); 
 background(255); 
 frameRate(60); 
textSize(32);
  noStroke();
  fill(#0CCAF7);
}

void draw() {  
  textSize(32);
  noStroke();
  fill(#0CCAF7);
if (keyPressed)
{
  if (key == 'b' || key == 'B') {
 text(poc1, 100, 100);
 text(izb1, 100, 150);
 text(izb2, 100, 200);
 text(izb3, 100, 250);
 text(izb4, 100, 300);
  }
}

int a = key;
a-=48;
println(a);
switch(a) {
  case 1: 
    background(255); 
    println("Zero");  // Does not execute
    break;
  case 2: 
  background(255); 
    println("One");  // Prints "One"
    break;
}

}




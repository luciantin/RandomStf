String poc1 = "Dobrodošli na glavni izbornik";
String izb1 = "1 - potencjometar";
String izb2 = "2 - Led diode";
String izb3 = "3 - svjetlina";
String izb4 = "4 - gumb";
int a,b=1;

void setup() {
  
  size(640,480); 
 background(255); 
 frameRate(60); 
textSize(32);
  noStroke();
  fill(#0CCAF7);
 }

void potencjometar()
{



}

void LedDioda()
{
 
}

void svjetlina()
{
 
}

void gumb()
{
 
}

// crvena #EA0909
void draw() { 
 background(255);
 fill(#3FFA03);
  textSize(64);
  text("Tin",300,450) ;
  textSize(32);
  noStroke();
  fill(#0CCAF7);
//if (keyPressed)
//{
 // if (key == 'b' || key == 'B') {
 text(poc1, 100, 100); // 0
 text(izb1, 100, 150); // 1
 text(izb2, 100, 200); // 2
 text(izb3, 100, 250); // 3
 text(izb4, 100, 300); // 4
  //} 
//} 
fill(#EA0909);


// 1
     if(mouseY >= 125 && mouseY <= 155 ) 
{
  ellipse(90,140,10,10);
if(mousePressed == true) a=1;

}
// 2
     if(mouseY >= 175 && mouseY <= 220 ) 
{
  ellipse(90,190,10,10);
if(mousePressed == true) a=2;

}
// 3
     if(mouseY >= 225 && mouseY <= 270 ) 
{
  ellipse(90,240,10,10);
if(mousePressed == true) a=3;

}
// 4
     if(mouseY >= 265 && mouseY <= 310 ) 
{
  ellipse(90,290,10,10);
if(mousePressed == true) a=4;

}
switch(a) {
  case 1: 
    background(255); 
    potencjometar();
    println("1"); 
    break;
  case 2: 
  background(255); 
  LedDioda();
    println("2");  
    break;
case 3: 
  background(255);
 svjetlina(); 
    println("3");  
    break;  
 case 4: 
  background(255); 
  gumb();
    println("4");  
    break;    
        
}
}


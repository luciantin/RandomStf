int boja_batuna1;
int boja_batuna2;
boolean i=false;
int crvena=#F70000;
int zelena=#66FF03;
int a=0;
import processing.serial.*;
Serial ard_Tin;
boolean b;
boolean pmousePressed;
int boja_1=0,boja_2=0;
int misy0_pl_10 ;
int misy0_min_10 ;
int misy1_pl_10 ;
int misy1_min_10 ;
void setup() {
    String ime_porta = Serial.list()[0]; 
  ard_Tin = new Serial(this, ime_porta, 9600);
   pmousePressed = false;
  b = false;
  size(640 , 480); 
 background(255); 
 frameRate(60); 

}

void draw() {
  background(255);
  gumb();
  crta_vuc();
  slanje_pod();
 
}

/////////**********************************************************
void gumb()
{
///////////////////////////////////////////***************************************  
  if (boja_2==1 && boja_1==1) boja_2=0; // nemogu oba biti upaljena
  if(boja_1==1)fill(zelena);
 else fill(crvena);
 quad(20,180,140,180,140,300,20,300);
 if(boja_2==1)fill(zelena);
 else fill(crvena);
 
  quad(20,10,140,10,140,140,20,140);
///////////////////////////////////////////***************************************  
  
   
   
   
  
  
if ( mousePressed == true && mouseX>20 && mouseX<140 && mouseY>180 && mouseY<300&& (!pmousePressed) ) {
  i=!i; 
boja_1=1;
  }
  
if (i==true )
{

 boja_1=0;
}
 
if (mouseX>20 && mouseX<140 && mouseY>180 && mouseY<300) pmousePressed = mousePressed;



////////////////////////////////////////////////////////////////////




 if (mousePressed == true && mouseX>20 && mouseX<140 && mouseY>10 && mouseY<140 ) {
boja_2=1;
  }
  else 
{
boja_2=0;
}





}
/////////**********************************************************






/////////**********************************************************
void crta_vuc()
{
strokeWeight(5);
fill(23,27,123);
line(310, 110, 310, 355);

  if (mousePressed == true && mouseX>280 && mouseX<340 && mouseY>110 && mouseY<355 )
{
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
 quad(290, misy0_pl_10, 330,misy0_pl_10, 330,misy0_min_10, 290,misy0_min_10);
}
/////////**********************************************************




void slanje_pod()
{
  //   ard_Tin.write();
println(misy0_min_10-100);
int pod1=misy0_min_10-100;
 if (pod1>0 && pod1<255) ard_Tin.write(pod1);
 else if (boja_1==1) ard_Tin.write(400); 
   else if (boja_2==1) ard_Tin.write(500); 
}

















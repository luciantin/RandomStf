void kretanje()
{
background(255);
/*
1. STOP
2. GORE
3. LIJEVO
4. DESNO 
5. NAZAD
*/ 

fill(255);
strokeWeight(10);

rect(x_sredina,y_sredina,64,64);  
rect(x_sredina,y_sredina-100,64,64);
rect(x_sredina+100,y_sredina,64,64);  
rect(x_sredina-100,y_sredina,64,64);
rect(x_sredina,y_sredina+100,64,64);  

/////////////////////////
///////
/////////////////////////
  
brzina(); 
  
if(mouseX>x_sredina&&mouseX<x_sredina+64&&mouseY>y_sredina&&mouseY<y_sredina+64||tipka==' ')
 {
  if (mousePressed == true||tipka==' ')
 {
  b_tipka_stop=true;
  Slanje("1\n"); //STOP
  b_stop_slanje=true;
 }
  else b_tipka_stop=false;
  
 }
  else b_tipka_stop=false;

/////////////////////////////////////////////////////////////////////////////

  if(mouseX>x_sredina&&mouseX<x_sredina+64&&mouseY>y_sredina-100&&mouseY<y_sredina-32||tipka=='W'||tipka=='w')
 {
  if (mousePressed == true||tipka=='w'||tipka=='W') 
  {
  b_tipka_gore=true;
  Slanje("2\n"); //NAPRED
  b_stop_slanje=true;
  }
  else b_tipka_gore=false;
 }
  else b_tipka_gore=false;
      
//////////////////////////////////////////////////////////////////////////////

if(mouseX>x_sredina-100&&mouseX<x_sredina-36&&mouseY>y_sredina&&mouseY<y_sredina+64||tipka=='A'||tipka=='a')
 {
  if (mousePressed == true||tipka=='A'||tipka=='a')
 {
  b_tipka_lijevo=true;
  Slanje("4\n"); //LIJEVO
  b_stop_slanje=true;
 }
  else b_tipka_lijevo=false;
 }
  else b_tipka_lijevo=false;

/////////////////////////////////////////////////////////////////////////////

if(mouseX>x_sredina+100&&mouseX<x_sredina+164&&mouseY>y_sredina&&mouseY<y_sredina+64||tipka=='d'||tipka=='D')
 {
  if (mousePressed == true||tipka=='d'||tipka=='D')
 {
  b_tipka_desno=true;
  Slanje("5\n"); //DESNO
  b_stop_slanje=true;
 }
  else b_tipka_desno=false;
 }
  else b_tipka_desno=false;

/////////////////////////////////////////////////////////////////////////////

if(mouseX>x_sredina&&mouseX<x_sredina+64&&mouseY>y_sredina+100&&mouseY<y_sredina+164||key=='S'||key=='s')
 {
  if (mousePressed == true||key=='s'||key=='S')
 {
  b_tipka_nazad=true;
  Slanje("3\n"); //NAZAD
  b_stop_slanje=true;
 }
  else b_tipka_nazad=false;
 }
  else b_tipka_nazad=false;

/////////////////////////////////////////////////////////////////////////////

if(b_tipka_stop==false)  image(tipka_stop_1, x_sredina,y_sredina);
  else image(tipka_stop_2, x_sredina,y_sredina);
  
if(b_tipka_gore==false)  image(tipka_gore_1, x_sredina,y_sredina-100);
  else image(tipka_gore_2, x_sredina,y_sredina-100);

if(b_tipka_lijevo==false)  image(tipka_lijevo_1, x_sredina-100,y_sredina);
  else image(tipka_lijevo_2, x_sredina-100,y_sredina);
  
if(b_tipka_desno==false)  image(tipka_desno_1, x_sredina+100,y_sredina);
  else image(tipka_desno_2, x_sredina+100,y_sredina);

if(b_tipka_nazad==false)  image(tipka_nazad_1, x_sredina,y_sredina+100);
  else image(tipka_nazad_2, x_sredina,y_sredina+100);
 
 
if(b_tipka_desno==false&&b_tipka_stop==false&&b_tipka_lijevo==false&&b_tipka_gore==false&&b_tipka_nazad==false&&b_stop_slanje==true)
{
b_stop_slanje=false;
for(int i=0;i<2;i++)Port_1.write("1\n"); //STOP
}

///////////////////////////////////////////////////*******************//////////////////////
fill(255);
strokeWeight(10);
rect(x_sredina+340,y_sredina-200,64,64);  
image(tipka_natrag,x_sredina+340,y_sredina-200);

if(mouseX>x_sredina+340&&mouseX<x_sredina+404&&mouseY>y_sredina-200&&mouseY<y_sredina-136)
{
if (mousePressed == true) b_tipka_izbornik_upravljanje=false; 
}
///////////////////////////////////////////////////*******************//////////////////////

}

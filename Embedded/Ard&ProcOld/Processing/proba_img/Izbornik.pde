void izbornik()
{

//stroke(0);
//strokeWeight(10);
background(255);
//fill(0);


Status();

rect(x_sredina-250,y_sredina-150,64,64); 
rect(x_sredina-250,y_sredina-60,64,64); 

fill(0, 102, 153); 
textSize(32);
text("IZBORNIK", 10, 30); 

fill(0); 
textSize(15);

image(tipka_izbornik_upravljanje,x_sredina-250,y_sredina-150);
image(tipka_izbornik_senzori,x_sredina-250,y_sredina-60);

if(mouseX>x_sredina-250&&mouseX<x_sredina-186&&mouseY>y_sredina-150&&mouseY<y_sredina-86) 
{
if (mousePressed == true) b_tipka_izbornik_upravljanje=true;
text("Ručno upravljanje",x_sredina-150,y_sredina-128);                         
}

if(mouseX>x_sredina-250&&mouseX<x_sredina-186&&mouseY>y_sredina-60&&mouseY<y_sredina+4) 
{
if (mousePressed == true) b_tipka_izbornik_senzori=true;
text("Senzori",x_sredina-150,y_sredina-40);                         
}

}

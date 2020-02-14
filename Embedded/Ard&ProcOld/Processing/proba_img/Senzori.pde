void senzori()
{
  
 background(255);
 fill(0);
 textSize(16);
 strokeWeight(10);
  
 rect(x_sredina-250,y_sredina-150,64,64); 
 rect(x_sredina-250,y_sredina-60,64,64);
 image(tipka_senzor_temperatura_1, x_sredina-250,y_sredina-150);
 image(tipka_senzor_vlaga_1, x_sredina-250,y_sredina-60);
/////////////////////////////////////////////////
 
 rect(x_sredina+340,y_sredina-200,64,64);  
 image(tipka_natrag,x_sredina+340,y_sredina-200);

if(mouseX>x_sredina+340&&mouseX<x_sredina+404&&mouseY>y_sredina-200&&mouseY<y_sredina-136&&mousePressed == true) b_tipka_izbornik_senzori=false; 


///////////////////////////////////////

if(mouseX>x_sredina-250&&mouseX<x_sredina-186&&mouseY>y_sredina-150&&mouseY<y_sredina-86) 
{
  if (mousePressed == true)   
   {
    Port_1.write("503\n");          
    Primanje(); 
    if(in_serial_Broj!=0&&in_serial_Broj<45)  text(in_serial_Broj,x_sredina,y_sredina);
   } 
text("Temperatura",x_sredina-150,y_sredina-128);                         
}

if(mouseX>x_sredina-250&&mouseX<x_sredina-186&&mouseY>y_sredina-60&&mouseY<y_sredina+4) 
{
    if (mousePressed == true)   
    {
    Port_1.write("502\n");           
    Primanje(); 
    if(in_serial_Broj!=0&&in_serial_Broj>40) text(in_serial_Broj,x_sredina,y_sredina);
    } 
text("Vlaga",x_sredina-150,y_sredina-40);                         
}

 
}

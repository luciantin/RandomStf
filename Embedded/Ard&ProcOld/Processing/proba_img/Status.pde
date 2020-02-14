void Status()
{ 
  textSize(16);
  fill(0);
  text("Status : ", 680, 30);
  
  if(status)  fill(#00FC1B);
  else fill(#F02913);
  
  strokeWeight(1);
  ellipse(750, 25, 15, 15); 
  strokeWeight(10);
  
if(b_tipka_izbornik_upravljanje==false&&b_tipka_izbornik_senzori==false)
{
  if(millis()-vrijeme>2000&&status==true) status=Provjera_statusa();
  if(millis()-vrijeme>100&&status==false) status=Provjera_statusa();  
} 

}
 
//////////////////////////
//////////////////////////
//////////////////////////

boolean Provjera_statusa()
{
  vrijeme=millis();
  for(int i=0;i<=1;i++) Port_1.write("500\n");
  Primanje(); 
  if(in_serial_Broj==501) return true;
  else  return false;  
}


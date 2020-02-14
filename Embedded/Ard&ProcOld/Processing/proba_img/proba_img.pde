
/*
Napravio : Lucian Tin Udovičić
*/

import processing.serial.*;

Serial Port_1; 


PImage tipka_stop_1,tipka_stop_2;  
PImage tipka_gore_1,tipka_gore_2;  
PImage tipka_lijevo_1,tipka_lijevo_2; 
PImage tipka_desno_1,tipka_desno_2; 
PImage tipka_izbornik_upravljanje;
PImage tipka_natrag;
PImage tipka_nazad_1,tipka_nazad_2;
PImage tipka_brzina_1;
PImage tipka_izbornik_senzori;
PImage tipka_senzor_temperatura_1;
PImage tipka_senzor_vlaga_1;
PImage tipka_senzor_temperatura_2;
PImage tipka_senzor_vlaga_2;

int x_sredina,y_sredina;
int mis_y_os_1,mis_y_os_2=height/2;
int vrijeme=millis();
int brzina_1=1,brzina_2;
int maksimalna_brzina=5;

float mis_kotac;

boolean b_tipka_stop,b_tipka_gore,b_tipka_lijevo,b_tipka_desno;
boolean b_tipka_izbornik_upravljanje=false,b_stop_slanje=false;
boolean b_tipka_izbornik_senzori=false;
boolean b_tipka_nazad;
boolean status=false;
boolean b_tipka_senzor_vlaga,b_tipka_senzor_temperatura;

char tipka;

int in_serial_Broj;
String in_serial_String;

void setup() {
  
 
 Port_1 = new Serial(this, Serial.list()[1], 9600); 
 
 size(800,500);
 frameRate(60);
 
 mis_y_os_2=height/2;
 
 x_sredina=width/2-32;
 y_sredina=height/2-32;

  tipka_stop_1 = loadImage("tipka_stop_1.png");  
  tipka_stop_2 = loadImage("tipka_stop_2.png");  

  tipka_gore_1 = loadImage("tipka_gore_1.png");  
  tipka_gore_2 = loadImage("tipka_gore_2.png");  
  
  tipka_lijevo_1 = loadImage("tipka_lijevo_1.png");  
  tipka_lijevo_2 = loadImage("tipka_lijevo_2.png");  
  
  tipka_desno_1 = loadImage("tipka_desno_1.png");  
  tipka_desno_2 = loadImage("tipka_desno_2.png");  
  
  tipka_izbornik_upravljanje =  loadImage("tipka_izbornik_upravljanje.png");  
  tipka_izbornik_senzori =  loadImage("tipka_izbornik_senzori.png");  
   
  tipka_natrag = loadImage("tipka_natrag.png");
 
  tipka_nazad_1 = loadImage("tipka_nazad_1.png");
  tipka_nazad_2 = loadImage("tipka_nazad_2.png");
  
  tipka_brzina_1 = loadImage("tipka_brzina_1.jpg");
  
  
  tipka_senzor_temperatura_1 = loadImage("tipka_senzor_temperatura_1.png");
  tipka_senzor_vlaga_1 = loadImage("tipka_senzor_vlaga_1.png");
  tipka_senzor_temperatura_2 = loadImage("tipka_senzor_temperatura_2.png");
  tipka_senzor_vlaga_2 = loadImage("tipka_senzor_vlaga_2.png");
}

//////////////////////////
//////////////////////////
//////////////////////////

void mouseWheel(MouseEvent event){ mis_kotac = event.getAmount();}

//////////////////////////
//////////////////////////
//////////////////////////

void keyPressed() 
{
   if(tipka=='+'&&brzina_1<maksimalna_brzina) brzina_1++;
   if(tipka=='-'&&brzina_1>1) brzina_1--;
   if (keyPressed) tipka=key;    
}

//////////////////////////
//////////////////////////
//////////////////////////

void Slanje(String kod)
{
  if(millis()-vrijeme>300) 
  {
    vrijeme=millis();
    Port_1.write(kod);
  }
}

//////////////////////////
//////////////////////////
//////////////////////////

void brzina()
{

  if(mis_kotac==-1&&brzina_1<maksimalna_brzina) brzina_1++;
  else if(mis_kotac==1&&brzina_1>1) brzina_1--;
  mis_kotac=0; 

  for(int i = 1;i<=brzina_1;i++) image(tipka_brzina_1,x_sredina-300,y_sredina-(30*i));
 
  if(brzina_1!=brzina_2)  
  {
    for(int i=0;i<2;i++) Port_1.write((brzina_1+100)+"\n");
    brzina_2=brzina_1;
  }
  
}

//////////////////////////
//////////////////////////
//////////////////////////



void draw() 
{  

if(b_tipka_izbornik_upravljanje==false||b_tipka_izbornik_senzori==false) izbornik();

if(b_tipka_izbornik_upravljanje==true&&status==true) kretanje();

if(b_tipka_izbornik_senzori==true&&status==true) senzori();
 
}














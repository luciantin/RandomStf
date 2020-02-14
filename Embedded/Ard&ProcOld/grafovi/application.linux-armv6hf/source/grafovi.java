import processing.core.*; 
import processing.data.*; 
import processing.event.*; 
import processing.opengl.*; 

import java.util.HashMap; 
import java.util.ArrayList; 
import java.io.File; 
import java.io.BufferedReader; 
import java.io.PrintWriter; 
import java.io.InputStream; 
import java.io.OutputStream; 
import java.io.IOException; 

public class grafovi extends PApplet {

boolean pauza = false; //pauziranje grafa (za kasnije , ako bude trebalo)

//u polja se upisuje na prvo mjesto nakon \u0161ta se pomaknu svi , oni koji ne stanu nema ih jbg
//                               0-T   1-sek
float[][] podMr = new float[360][2];
float[][] podSk = new float[360][2];

// 
float otvor_sk = 543;


public void setup() {  
 
surface.setResizable(true);
 
for(int tmp1=359;tmp1>=0;tmp1--)
{ 
podMr[tmp1][0] = random(0,50);
podMr[tmp1][1] = random(0,60);
//println(podMr[tmp1][0]+","+podMr[tmp1][1]);
}

for(int tmp1=359;tmp1>=0;tmp1--)
{  
podSk[tmp1][0] = random(0,50);
podSk[tmp1][1] = random(0,60);
//println(podMr[tmp1][0]+","+podMr[tmp1][1]);
}

}

public void draw() {
fill(255);
background(255);

//println (mouseX +"," + mouseY); //debg
  
 
 GrafSk();
 GrafMr();
 OtvorSk();


if(keyPressed) //debg
{  
  if (key == 'f' || key == 'F') 
  {
    fill(0, 102, 153);
    text("Frame rate: " + PApplet.parseInt(frameRate), 5, 15); 
  }
  
  if (key == ' ')  pauza = !pauza; //cemo rijesit kasnije
}


}


public int GrafMr() {
  
//Dinami\u010dko odre\u0111ivanje temperature (zaokru\u017eivanje tako\u0111er,ne za sve , samo za ovo)
float proslaT = 55 ;
//float Tmax = proslaT+proslaT*0.1;
float Tmax = proslaT;
float[] ozT = new float[4];
ozT[0] =  Tmax*0.25f; 
ozT[1] =  Tmax*0.5f; 
ozT[2] =  Tmax*0.75f;
ozT[3] =  Tmax;

 // Struktura - osi , glavne crte , znakovi i strelice(kasnije,mozda)
  
int udaljenost_grfsk = 500 ;

int[] max_temp = new int [2]; // X Y
max_temp[0] = 60+udaljenost_grfsk;
max_temp[1] = 60;

int[] srediste = new int [2]; // X Y
srediste[0] = 60+udaljenost_grfsk;
srediste[1] = 200+max_temp[1];

int[] max_vr = new int [2]; // X Y
max_vr[0] = 360+max_temp[0];
max_vr[1] = 200+max_temp[1];

//CRTE I OZNAKE

//Osi

line(srediste[0],srediste[1],max_temp[0],max_temp[1]);
line(srediste[0],srediste[1],max_vr[0],max_vr[1]);


fill(0);
text("min",max_vr[0] - 10,max_vr[1]+15);
text("\u00b0C",max_temp[0] - 20,max_temp[1]+15);


//Crte na x 

for(int komada = 5;komada>0;komada--)
{
line(srediste[0]+60*komada,srediste[1]+10,srediste[0]+60*komada,srediste[1]-10);
text(komada*10,srediste[0]+60*komada-5,srediste[1]+25);
}

//Pomocne linije na x 

int pomoX = srediste[0] + 33;
for(int komada = 4;komada>=0;komada--)
{
line(pomoX+60*komada,srediste[1]+5,pomoX+60*komada,srediste[1]-5);
}

//Crte na y 

for(int komada = 3;komada>0;komada--)
{
line(max_temp[0]+10,max_temp[1]+50*komada,max_temp[0]-10,max_temp[1]+50*komada);
text(ozT[(komada-3)*-1],max_temp[0]-60,max_temp[1]+50*komada+5);
}

//Pomocne linije na y 

int pomoY = max_temp[1] + 25;
for(int komada = 3;komada>=0;komada--)
{
line(max_temp[0]+5,pomoY+50*komada,max_temp[0]-5,pomoY+50*komada);
}

//*************************
float mno_temp = (srediste[1]-max_temp[1])/Tmax; //BITNO!!!!111
//*************************

//Mi\u0161
if(mouseY>=max_temp[1] && mouseY<=srediste[1] && mouseX >= srediste[0] && mouseX <= max_vr[0])
{  
  float tmp1,tmp2;
  tmp1 = (mouseX-srediste[0])/6;
  tmp2 = ((mouseY-max_temp[1]-200)*-1)/mno_temp;
 // text(tmp1+","+tmp2,20,20);  
 text("Mi\u0161 : ",srediste[0],srediste[1]+60);
 text("Vrijeme : "+tmp1+" min",srediste[0],srediste[1]+80);
 text("Temperatura : "+tmp2+" \u00b0C",srediste[0],srediste[1]+100);
}
 
textSize(18);
text("Temperatura mora",max_temp[0]-5,max_temp[1]-20);
textSize(14);

//ZADNJA VRIJEDNOS TEKST
text("Zadnja vrijednost : ",srediste[0]+max_vr[0]/4,srediste[1]+60);
text("Vrijeme : "+podMr[359][1]+" min",srediste[0]+max_vr[0]/4,srediste[1]+80);
text("Temperatura : "+podMr[359][0]+" \u00b0C",srediste[0]+max_vr[0]/4,srediste[1]+100);
  
 
//Crtanje to\u010daka

strokeWeight(2);
stroke(0,0,255);
for(int tmp1 = 359;tmp1>=0;tmp1--)
{
float x,y;
x=srediste[0]+(podSk[tmp1][1]*6);
y=srediste[1]-podSk[tmp1][0]*mno_temp;
//ellipse(x,y,2,2);
point(x,y);
}
fill(255);
stroke(0);
strokeWeight(1);

return 0; 

}


public int GrafSk() {
  
  //Dinami\u010dko odre\u0111ivanje temperature (zaokru\u017eivanje tako\u0111er,ne za sve , samo za ovo)
float proslaT = 60;
float Tmax = proslaT+proslaT*0.1f;
//float Tmax = proslaT;
float[] ozT = new float[4];
ozT[0] =  Tmax*0.25f; 
ozT[1] =  Tmax*0.5f; 
ozT[2] =  Tmax*0.75f;
ozT[3] =  Tmax;
  
  
 // Struktura - osi , itd...
  
  
 

int[] max_temp = new int [2]; // X Y
max_temp[0] = 100;
max_temp[1] = 60;

int[] srediste = new int [2]; // X Y
srediste[0] = max_temp[0];
srediste[1] = 200+max_temp[1];

int[] max_vr = new int [2]; // X Y
max_vr[0] = 360+max_temp[0];
max_vr[1] = 200+max_temp[1];

//quad(60,20,60+396,20,396+60,220,60,220);
line(srediste[0],srediste[1],max_temp[0],max_temp[1]);
line(srediste[0],srediste[1],max_vr[0],max_vr[1]);

fill(0);
text("min",max_vr[0] - 10,max_vr[1]+15);
text("\u00b0C",max_temp[0] - 20,max_temp[1]+15);



//Crte na x 

for(int komada = 5;komada>0;komada--)
{
line(srediste[0]+60*komada,srediste[1]+10,srediste[0]+60*komada,srediste[1]-10);
text(komada*10,srediste[0]+60*komada-5,srediste[1]+25);
}

//Pomocne linije na x 

int pomoX = srediste[0] + 33;
for(int komada = 4;komada>=0;komada--)
{
line(pomoX+60*komada,srediste[1]+5,pomoX+60*komada,srediste[1]-5);
}

//Crte na y 

for(int komada = 3;komada>0;komada--)
{
line(max_temp[0]+10,max_temp[1]+50*komada,max_temp[0]-10,max_temp[1]+50*komada);
text(ozT[(komada-3)*-1],max_temp[0]-60,max_temp[1]+50*komada+5);
}

//Pomocne linije na y 

int pomoY = max_temp[1] + 25;
for(int komada = 3;komada>=0;komada--)
{
line(max_temp[0]+5,pomoY+50*komada,max_temp[0]-5,pomoY+50*komada);
}

//Crtanje to\u010daka

//*************************
float mno_temp = (srediste[1]-max_temp[1])/Tmax; //BITNO!!!!111
//*************************
//println(mno_temp);
//Mi\u0161

if(mouseY>=max_temp[1] && mouseY<=srediste[1] && mouseX >= srediste[0] && mouseX <= max_vr[0])
{  
  float tmp1,tmp2;
  tmp1 = (mouseX-srediste[0])/6;
  tmp2 = ((mouseY-max_temp[1]-200)*-1)/mno_temp;
 // text(tmp1+","+tmp2,20,20);  
 text("Mi\u0161 : ",srediste[0],srediste[1]+60);
 text("Vrijeme : "+tmp1+" min",srediste[0],srediste[1]+80);
 text("Temperatura : "+tmp2+" \u00b0C",srediste[0],srediste[1]+100);
}
strokeWeight(2);
stroke(255,0,0);


textSize(18);
text("Temperatura \u0161koljke",max_temp[0]-5,max_temp[1]-20);
textSize(14);


//ZADNJA VRIJEDNOS TEKST
text("Zadnja vrijednost : ",srediste[0]+max_vr[0]/2,srediste[1]+60);
text("Vrijeme : "+podSk[359][1]+" min",srediste[0]+max_vr[0]/2,srediste[1]+80);
text("Temperatura : "+podSk[359][0]+" \u00b0C",srediste[0]+max_vr[0]/2,srediste[1]+100);
 
//Crtanje to\u010daka
for(int tmp1 = 359;tmp1>=0;tmp1--)
{
float x,y;
x=srediste[0]+(podSk[tmp1][1]*6);
y=srediste[1]-podSk[tmp1][0]*mno_temp;
//ellipse(x,y,3,3);
point(x,y);
}
fill(255);
stroke(0);
strokeWeight(1);


return 0; 
}
public int OtvorSk()
{     
  
// glavne kordinate
int duljina_li = 300;  // duljina obje crte
int pomakY = 700; //koliko je dolje
int pomakX = 100; //koliko je u desno

int[] srediste = new int [2]; // X Y
srediste[0] = pomakX;
srediste[1] = pomakY;

int[] max_desno = new int [2]; // X Y
max_desno[0] = pomakX+duljina_li;
max_desno[1] = pomakY;

int[] max_gore = new int [2]; // X Y
max_gore[0] = pomakX;
max_gore[1] = pomakY-duljina_li;

//otvor_sk u kutA

float kutA = 15.68f;
float radA = radians(kutA);
float duljinaC = PApplet.parseFloat(duljina_li)/cos(radA);

float y2 = max_desno[1]-duljinaC*sin(radA);
float x2 = max_desno[0];
//println(radA);

// Crtanje glavnih linija
line(srediste[0],srediste[1],max_desno[0],max_desno[1]);// ne mi\u010de se
line(srediste[0],srediste[1],x2,y2);//  mi\u010de se
noFill();

//polukrug
strokeWeight(3);
stroke(56,182,17);
arc(srediste[0],srediste[1], 200, 200,2*PI-radA,2*PI);
stroke(0);
strokeWeight(1);

//oznake (txt)
fill(0);
textSize(18);
text("Otvor \u0161koljke",srediste[0],srediste[1]-duljina_li/2);

text("\u03b1 = "+kutA+" \u00b0",srediste[0]+20,srediste[1]+20);
textSize(14);
fill(255);
return 0;
}
  public void settings() { 
size(1024, 768); }
  static public void main(String[] passedArgs) {
    String[] appletArgs = new String[] { "grafovi" };
    if (passedArgs != null) {
      PApplet.main(concat(appletArgs, passedArgs));
    } else {
      PApplet.main(appletArgs);
    }
  }
}

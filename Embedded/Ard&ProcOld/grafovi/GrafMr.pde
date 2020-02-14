

int GrafMr() {
  
//Dinamičko određivanje temperature (zaokruživanje također,ne za sve , samo za ovo)
float proslaT = 55 ;
//float Tmax = proslaT+proslaT*0.1;
float Tmax = proslaT;
float[] ozT = new float[4];
ozT[0] =  Tmax*0.25; 
ozT[1] =  Tmax*0.5; 
ozT[2] =  Tmax*0.75;
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
text("°C",max_temp[0] - 20,max_temp[1]+15);


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

//Miš
if(mouseY>=max_temp[1] && mouseY<=srediste[1] && mouseX >= srediste[0] && mouseX <= max_vr[0])
{  
  float tmp1,tmp2;
  tmp1 = (mouseX-srediste[0])/6;
  tmp2 = ((mouseY-max_temp[1]-200)*-1)/mno_temp;
 // text(tmp1+","+tmp2,20,20);  
 text("Miš : ",srediste[0],srediste[1]+60);
 text("Vrijeme : "+tmp1+" min",srediste[0],srediste[1]+80);
 text("Temperatura : "+tmp2+" °C",srediste[0],srediste[1]+100);
}
 
textSize(18);
text("Temperatura mora",max_temp[0]-5,max_temp[1]-20);
textSize(14);

//ZADNJA VRIJEDNOS TEKST
text("Zadnja vrijednost : ",srediste[0]+max_vr[0]/4,srediste[1]+60);
text("Vrijeme : "+podMr[359][1]+" min",srediste[0]+max_vr[0]/4,srediste[1]+80);
text("Temperatura : "+podMr[359][0]+" °C",srediste[0]+max_vr[0]/4,srediste[1]+100);
  
 
//Crtanje točaka

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
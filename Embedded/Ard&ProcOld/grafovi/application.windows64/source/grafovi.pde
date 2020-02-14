boolean pauza = false; //pauziranje grafa (za kasnije , ako bude trebalo)

//u polja se upisuje na prvo mjesto nakon šta se pomaknu svi , oni koji ne stanu nema ih jbg
//                               0-T   1-sek
float[][] podMr = new float[360][2];
float[][] podSk = new float[360][2];

// 
float otvor_sk = 543;


void setup() {  
size(1024, 768); 
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

void draw() {
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
    text("Frame rate: " + int(frameRate), 5, 15); 
  }
  
  if (key == ' ')  pauza = !pauza; //cemo rijesit kasnije
}


}
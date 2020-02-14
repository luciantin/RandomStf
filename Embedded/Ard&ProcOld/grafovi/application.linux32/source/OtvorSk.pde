int OtvorSk()
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

float kutA = 15.68;
float radA = radians(kutA);
float duljinaC = float(duljina_li)/cos(radA);

float y2 = max_desno[1]-duljinaC*sin(radA);
float x2 = max_desno[0];
//println(radA);

// Crtanje glavnih linija
line(srediste[0],srediste[1],max_desno[0],max_desno[1]);// ne miče se
line(srediste[0],srediste[1],x2,y2);//  miče se
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
text("Otvor školjke",srediste[0],srediste[1]-duljina_li/2);

text("α = "+kutA+" °",srediste[0]+20,srediste[1]+20);
textSize(14);
fill(255);
return 0;
}
  
   import processing.serial.*;
   float unos;
     Serial tin;        
   int xPoz = 1;        
   
   void setup () {
   size(960, 640);        
   tin = new Serial(this, Serial.list()[0], 9600);
   tin.bufferUntil('\n');
   frameRate(60);
    background(255);
   }
   void draw () {
     background(255);
  
    textSize(32);
    noStroke();
    fill(#0CCAF7);
  
  text("Napravio : Lucian Tin",height/2,width/2);
      strokeWeight(10);
      stroke(127,34,255);
  line(unos, 0,unos, 33);
 
   
   
   }
  void serialEvent (Serial tin) {
     
     String inString = tin.readStringUntil('\n');
   
   if (inString != null) {
   inString = trim(inString);
   unos = float(inString); 
   unos = map(unos, 0, width-10, 0,width-10);
   
   }
  
   }
   


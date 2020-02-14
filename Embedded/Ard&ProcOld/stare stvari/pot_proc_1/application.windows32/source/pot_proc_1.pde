
 import processing.serial.*;
 float inByte;
 Serial myPort;        
 int xPos = 1;        
 
 void setup () {
 size(640, 480);        
 myPort = new Serial(this, Serial.list()[0], 9600);
 myPort.bufferUntil('\n');
 frameRate(60);
  background(0);
 }
 void draw () {
    
    stroke(127,34,255);
 line(xPos, height, xPos, height - inByte);
 
 if (xPos >= width) {
 xPos = 0;
 background(0); 
 } 
 else {
 xPos++;
 }
 }
 
void serialEvent (Serial myPort) {
   
   String inString = myPort.readStringUntil('\n');
 
 if (inString != null) {
 inString = trim(inString);
 inByte = float(inString); 
 inByte = map(inByte, 0, 1023, 0,1023);
 
 }

 }
 
 /*
 
 strokeWeight(10);
  text(inByte,height/2,width/2);
   line(100,100,inByte,100);
 
 
 
 
 */

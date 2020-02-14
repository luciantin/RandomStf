import processing.core.*; 
import processing.data.*; 
import processing.event.*; 
import processing.opengl.*; 

import processing.serial.*; 

import java.util.HashMap; 
import java.util.ArrayList; 
import java.io.File; 
import java.io.BufferedReader; 
import java.io.PrintWriter; 
import java.io.InputStream; 
import java.io.OutputStream; 
import java.io.IOException; 

public class pot_proc_1 extends PApplet {


 
 float inByte;
 Serial myPort;        
 int xPos = 1;        
 
 public void setup () {
 size(640, 480);        
 myPort = new Serial(this, Serial.list()[0], 9600);
 myPort.bufferUntil('\n');
 frameRate(60);
  background(0);
 }
 public void draw () {
    
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
 
public void serialEvent (Serial myPort) {
   
   String inString = myPort.readStringUntil('\n');
 
 if (inString != null) {
 inString = trim(inString);
 inByte = PApplet.parseFloat(inString); 
 inByte = map(inByte, 0, 1023, 0,1023);
 
 }

 }
 
 /*
 
 strokeWeight(10);
  text(inByte,height/2,width/2);
   line(100,100,inByte,100);
 
 
 
 
 */
  static public void main(String[] passedArgs) {
    String[] appletArgs = new String[] { "--full-screen", "--bgcolor=#6134F7", "--stop-color=#FC0A0A", "pot_proc_1" };
    if (passedArgs != null) {
      PApplet.main(concat(appletArgs, passedArgs));
    } else {
      PApplet.main(appletArgs);
    }
  }
}

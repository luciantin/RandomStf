 import processing.serial.*;
 
Serial myPort; // The serial port:
int inByte = -1;
 
void setup() {
  size(400, 300);
 
  println(Serial.list());
 
  // You may need to change the number in [ ] to match 
  // the correct port for your system
  myPort = new Serial(this, Serial.list()[0], 9600);
 
  textSize(32);
  fill(165, 27, 27);
}
 
void draw() {
  background(200);
 
 
 
  while (myPort.available () > 0) {
    inByte = myPort.read();
    println(inByte);
  }
 
  text(char(inByte), width/2, height/2);
}

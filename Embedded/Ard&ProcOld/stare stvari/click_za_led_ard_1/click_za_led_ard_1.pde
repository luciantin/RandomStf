 import processing.serial.*;
  
     Serial tin;        




void setup() {
  
  size(640 , 480); 
 background(255); 
 frameRate(60); 
 tin = new Serial(this, Serial.list()[0], 9600);
   tin.bufferUntil('\n');
}

void draw() {
  
  background(255); 
 if (mousePressed == true) 
  {                           //if we clicked in the window
  tin.write('1');         //send a 1
   println("1");   
  } else 
  {                           //otherwise
  tin.write('0');          //send a 0
  }   

}


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

public class koordinate_640_X_360 extends PApplet {






public void setup() {
  
  size(1600 , 900); 
 background(255); 
 frameRate(60); 

}

public void draw() {
  
  background(255); 
  textSize(32);
  fill(165, 27, 27);
  int a = mouseX;
  int b = mouseY;
 text( a, 220, height/2);
 text( b, 350, height/2);
 text("Tin", 520, 350);
 ellipse(mouseX,mouseY,5,5);

}






  static public void main(String[] passedArgs) {
    String[] appletArgs = new String[] { "koordinate_640_X_360" };
    if (passedArgs != null) {
      PApplet.main(concat(appletArgs, passedArgs));
    } else {
      PApplet.main(appletArgs);
    }
  }
}

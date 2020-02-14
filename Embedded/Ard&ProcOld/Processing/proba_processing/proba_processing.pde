PImage img;

void setup() {
  size(1200,700);
  img = loadImage("abcdd.jpg");
}

void draw() {
  clear();
  image(img, mouseX-200, mouseY-121);
}

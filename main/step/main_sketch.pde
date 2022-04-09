import processing.serial.*;
import controlP5.*;

Serial port;
ControlP5 gui;
PFont pfont;

void setup() {
  
  color blue = color(10, 10, 255);
  color red = color(255, 10, 10);
  color green = color(10, 255, 10);
  color light_blue = color(125, 125, 255);
  color light_red = color(255, 125, 125);
  color light_green = color(125, 255, 125);
  color black = color(0, 0, 0);
  color white = color(255, 255, 255);
  
  size(1000, 800);
  background(white);
  pfont = createFont("Arial", 30);
  ControlFont font = new ControlFont(pfont);
  
  //port = new Serial(this, "COM8", 9600);
  
  gui = new ControlP5(this);
  gui.setFont(font);
  
  gui.addButton("Start")
    .setPosition(50,50)
    .setSize(300,75)
    .setColorBackground(green)
    .setColorForeground(light_green)
    .setColorLabel(black)
    ;
    
  gui.addButton("Stop")
    .setPosition(50,150)
    .setSize(300, 75)
    .setColorBackground(red)
    .setColorForeground(light_red)
    .setColorLabel(black)
    ;
  gui.addButton("Send")
    .setPosition(650,675)
    .setSize(300, 75)
    .setColorBackground(blue)
    .setColorForeground(light_blue)
    .setColorLabel(black)
    ;
    
  gui.addSlider("X Position")
    .setPosition(500, 500)
    .setSize(300, 50)
    .setMax(300)
    ;

}    

public void Start() {
  // port.write(b);
  println("starting");
}

public void Stop() {
  // port.write(e);
  println("ending");
}

public void controlEvent(ControlEvent event) {
  
}

void draw() {}

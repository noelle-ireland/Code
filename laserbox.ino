#include <Adafruit_NeoPixel.h>

// digital pin 2 has a pushbutton attached to it. Give it a name:
// init other pins
int zero = A0;
int one = A1;
#define PIN 9
int ten = 10;

// arguments: number of pixels, pin number, weird one
Adafruit_NeoPixel strip = Adafruit_NeoPixel(5, PIN, NEO_GRB + NEO_KHZ800); // init strip

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  // make the potent, pressure an input:
  pinMode(zero, INPUT);
  pinMode(one, INPUT);
  // define output:
  pinMode(ten, OUTPUT);
  // put your setup code here, to run once:
  strip.begin(); // startin our LEF Strip
  strip.show(); // init all pixels to "off"
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input pin:
  int lightRead = analogRead(zero);
  int pressureRead = analogRead(one);

  // map the input to frequencies between 200 and 550
  int potentNine = map(lightRead, 0, 1023, 200, 550);
  // play tone for 10 milliseconds 100 times
  for(int i = 0; i < 100; i++){
    tone(ten, potentNine, 10);
  }
  // print sound value
  Serial.print("SOUND= ");
  Serial.print(potentNine);

  int pressureTen = map(pressureRead, 0, 1023, 0, 255);
  // put your main code here, to run repeatedly:
  for(int i=0; i<strip.numPixels(); i++){
    // strip.setPixelColor(index, red, green, blue)
    strip.setPixelColor(i, pressureTen/7,pressureTen/2,pressureTen); // set pixel to red
  }
  strip.show(); //update the strip

  // print neopixel value
  Serial.print(" NEO= ");
  Serial.println(pressureTen);
  
    
}

#include <Adafruit_NeoPixel.h>

#define PIN      6
#define N_LEDS 30

Adafruit_NeoPixel strip = Adafruit_NeoPixel(N_LEDS, PIN, NEO_GRB + NEO_KHZ800);

const int GSR=A2;
int threshold=0;
int sensorValue;

int led = 5;

void setup(){
  strip.begin();
  strip.show();
  long sum=0;
  //Serial.begin(9600);
  //delay(1000);

  pinMode(led, OUTPUT);
}
void loop(){
  sensorValue=analogRead(GSR);
  //Serial.print("sensorValue=");
  //Serial.println(sensorValue);
  int LED_map = map(sensorValue,0, 300, 0, 30); 
  numberofLEDS(LED_map);
  //delay(500);
} 
/*
  if (sensorValue < 400 && sensorValue > 300) {
    numberofLEDS(1);
    strip.setPixelColor(0, 255, 0, 0);
    strip.setPixelColor(1, 0, 0, 0);
    strip.setPixelColor(2, 0, 0, 0);
    strip.setPixelColor(3, 0, 0, 0);
    strip.show();
  }else if (sensorValue < 300 && sensorValue > 200) {
    
    strip.setPixelColor(0, 255, 0, 0);
    strip.setPixelColor(1, 255, 0, 0);
    strip.setPixelColor(2, 0, 0, 0);
    strip.setPixelColor(3, 0, 0, 0);
    strip.show();
  }else if (sensorValue < 200 && sensorValue > 100) {
    strip.setPixelColor(0, 255, 0, 0);
    strip.setPixelColor(1, 255, 0, 0);
    strip.setPixelColor(2, 255, 0, 0);
    strip.setPixelColor(3, 0, 0, 0);
    strip.show();
  }else if (sensorValue < 100) {
    strip.setPixelColor(0, 255, 0, 0);
    strip.setPixelColor(1, 255, 0, 0);
    strip.setPixelColor(2, 255, 0, 0);
    strip.setPixelColor(3, 255, 0, 0);
    strip.show();
  }   
  strip.show();
  
}
*/
void numberofLEDS(int num){
  for(int i=1; i <= num; i++){
  strip.setPixelColor(i-1, 0, 0, 0);
  strip.show();
  }
  for(int j=num+1; j <= 30; j++){
  strip.setPixelColor(j, 255, 0, 0); 
  strip.show();    
  }
}

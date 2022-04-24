// FastLED library allows access of WS2812 LED strip
#include <FastLED.h>

// define pin connection and no of LEDs
#define LED_PIN     10
#define NUM_LEDS    80

// define stuff
char value = '0'; // this will be the incoming message from serial
int ran = 0; // random number used to randomise colour
int analogpin = A1; // potentiometer analog in 1
int analogpin2 = A3; // potentiometer analog in 1
float analogin = 0; // analog in 1 value 
float analogin2 = 0; // analog in 2 value 
char modeSelect = 'b'; // this is used to select the LED mode
int actionParam; // this is used as the mode parameter

// define no of leds
CRGB leds[NUM_LEDS];

void setup() {
  // init FastLED 
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
  FastLED.clear(true);
  //begin comms
  Serial.begin(9600);
}

// blinker mode function
void blinker(int analogin2) {
  // map potentiometer in to 0-255
  actionParam = map(analogin2, 0, 1023, 0, 255);
  // turn all leds on
  fill_solid( leds, NUM_LEDS, CRGB(actionParam,0,200));
  FastLED.show();
  // wait the time specified by the analogin2
  delay(actionParam);
  // turn off the LEDs
  FastLED.clear(true);
}


// shooter mode
void sharpshooter(int analogin2){
    // map potentiometer in
    actionParam = map(analogin2, 0, 1023, 0, 200);
    // init random no
    ran = random(1,14);
    
    // choose if statement (color) by ran
    if(ran == 1) {
      // length of LEDs is split into 4
      // a shooter will start from 4 equally spaced points and move along the strip
      // LED location incremented by for loop
      for (int i = 0; i < NUM_LEDS/4; i++) {
        int quarter = floor((NUM_LEDS*0.25));
        int half = floor((NUM_LEDS*0.5));
        int three_quarter = floor((NUM_LEDS*0.75)); 
        // turn on corresponding value at each quarter section
        leds[i] = CRGB(0, 255, 0);               
        leds[quarter+i] = CRGB(0, 255, 0);
        leds[half+i] = CRGB(0, 255, 0);
        leds[three_quarter+i] = CRGB(0, 255, 0);
        FastLED.show();
        // speed of movement dictated by actionParam
        delay(actionParam);
        // turn off current LED
        leds[i] = CRGB(0, 0, 0);
        leds[quarter+i] = CRGB(0, 0, 0);
        leds[half+i] = CRGB(0, 0, 0);
        leds[three_quarter+i] = CRGB(0, 0, 0);
        FastLED.show();
      }
    }
    
      else if(ran == 2) {
      for (int i = 0; i < NUM_LEDS/4; i++) {
        leds[i] = CRGB(255, 0, 0);
        int quarter = floor((NUM_LEDS*0.25));
        int half = floor((NUM_LEDS*0.5));
        int three_quarter = floor((NUM_LEDS*0.75));                
        leds[quarter+i] = CRGB(255, 0, 0);
        leds[half+i] = CRGB(255, 0, 0);
        leds[three_quarter+i] = CRGB(255, 0, 0);
        FastLED.show();
        delay(actionParam);
        leds[i] = CRGB(0, 0, 0);
        leds[quarter+i] = CRGB(0, 0, 0);
        leds[half+i] = CRGB(0, 0, 0);
        leds[three_quarter+i] = CRGB(0, 0, 0);
        FastLED.show();
      }
    }
    
      else if(ran == 3) {
      for (int i = 0; i < NUM_LEDS/4; i++) {
        leds[i] = CRGB(0, 0, 255);
        int quarter = floor((NUM_LEDS*0.25));
        int half = floor((NUM_LEDS*0.5));
        int three_quarter = floor((NUM_LEDS*0.75));                
        leds[quarter+i] = CRGB(0, 0, 255);
        leds[half+i] = CRGB(0, 0, 255);
        leds[three_quarter+i] = CRGB(0, 0, 255);
        FastLED.show();
        delay(actionParam);
        leds[i] = CRGB(0, 0, 0);
        leds[quarter+i] = CRGB(0, 0, 0);
        leds[half+i] = CRGB(0, 0, 0);
        leds[three_quarter+i] = CRGB(0, 0, 0);
        FastLED.show();
      }
    }
    
      else if(ran == 4) {
      for (int i = 0; i < NUM_LEDS/4; i++) {
        leds[i] = CRGB(51, 0, 102);
        int quarter = floor((NUM_LEDS*0.25));
        int half = floor((NUM_LEDS*0.5));
        int three_quarter = floor((NUM_LEDS*0.75));                
        leds[quarter+i] = CRGB(51, 0, 102);
        leds[half+i] = CRGB(51, 0, 102);
        leds[three_quarter+i] = CRGB(51, 0, 102);
        FastLED.show();
        delay(actionParam);
        leds[i] = CRGB(0, 0, 0);
        leds[quarter+i] = CRGB(0, 0, 0);
        leds[half+i] = CRGB(0, 0, 0);
        leds[three_quarter+i] = CRGB(0, 0, 0);
        FastLED.show();
      }
    }
    
      else if(ran == 5) {
      for (int i = 0; i < NUM_LEDS/4; i++) {
        leds[i] = CRGB(245, 30, 30);
        int quarter = floor((NUM_LEDS*0.25));
        int half = floor((NUM_LEDS*0.5));
        int three_quarter = floor((NUM_LEDS*0.75));                
        leds[quarter+i] = CRGB(245, 30, 30);
        leds[half+i] = CRGB(245, 30, 30);
        leds[three_quarter+i] = CRGB(245, 30, 30);
        FastLED.show();
        delay(actionParam);
        leds[i] = CRGB(0, 0, 0);
        leds[quarter+i] = CRGB(0, 0, 0);
        leds[half+i] = CRGB(0, 0, 0);
        leds[three_quarter+i] = CRGB(0, 0, 0);
        FastLED.show();
      }
    }
    
      else if(ran == 6) {
      for (int i = 0; i < NUM_LEDS/4; i++) {
        leds[i] = CRGB(55, 255, 0);
        int quarter = floor((NUM_LEDS*0.25));
        int half = floor((NUM_LEDS*0.5));
        int three_quarter = floor((NUM_LEDS*0.75));                
        leds[quarter+i] = CRGB(55, 255, 0);
        leds[half+i] = CRGB(55, 255, 0);
        leds[three_quarter+i] = CRGB(55, 255, 0);
        FastLED.show();
        delay(actionParam);
        leds[i] = CRGB(0, 0, 0);
        leds[quarter+i] = CRGB(0, 0, 0);
        leds[half+i] = CRGB(0, 0, 0);
        leds[three_quarter+i] = CRGB(0, 0, 0);
        FastLED.show();
      }
    }
    
      else if(ran == 7) {
      for (int i = 0; i < NUM_LEDS/4; i++) {
        leds[i] = CRGB(0, 102, 51);
        int quarter = floor((NUM_LEDS*0.25));
        int half = floor((NUM_LEDS*0.5));
        int three_quarter = floor((NUM_LEDS*0.75));                
        leds[quarter+i] = CRGB(0, 102, 51);
        leds[half+i] = CRGB(0, 102, 51);
        leds[three_quarter+i] = CRGB(0, 102, 51);
        FastLED.show();
        delay(actionParam);
        leds[i] = CRGB(0, 0, 0);
        leds[quarter+i] = CRGB(0, 0, 0);
        leds[half+i] = CRGB(0, 0, 0);
        leds[three_quarter+i] = CRGB(0, 0, 0);
        FastLED.show();
      }
    }
    
      else if(ran == 8) {
      for (int i = 0; i < NUM_LEDS/4; i++) {
        leds[i] = CRGB(250, 0, 190);
        int quarter = floor((NUM_LEDS*0.25));
        int half = floor((NUM_LEDS*0.5));
        int three_quarter = floor((NUM_LEDS*0.75));                
        leds[quarter+i] = CRGB(250, 0, 190);
        leds[half+i] = CRGB(250, 0, 190);
        leds[three_quarter+i] = CRGB(250, 0, 190);
        FastLED.show();
        delay(actionParam);
        leds[i] = CRGB(0, 0, 0);
        leds[quarter+i] = CRGB(0, 0, 0);
        leds[half+i] = CRGB(0, 0, 0);
        leds[three_quarter+i] = CRGB(0, 0, 0);
        FastLED.show();
      }
    }
    
      else if(ran == 9) {
      for (int i = 0; i < NUM_LEDS/4; i++) {
        leds[i] = CRGB(55, 255, 10);
        int quarter = floor((NUM_LEDS*0.25));
        int half = floor((NUM_LEDS*0.5));
        int three_quarter = floor((NUM_LEDS*0.75));                
        leds[quarter+i] = CRGB(55, 255, 10);
        leds[half+i] = CRGB(55, 255, 10);
        leds[three_quarter+i] = CRGB(55, 255, 10);
        FastLED.show();
        delay(actionParam);
        leds[i] = CRGB(0, 0, 0);
        leds[quarter+i] = CRGB(0, 0, 0);
        leds[half+i] = CRGB(0, 0, 0);
        leds[three_quarter+i] = CRGB(0, 0, 0);
        FastLED.show();
      }
    }
    
      else if(ran == 10) {
      for (int i = 0; i < NUM_LEDS/4; i++) {
        leds[i] = CRGB(0, 243, 122);
        int quarter = floor((NUM_LEDS*0.25));
        int half = floor((NUM_LEDS*0.5));
        int three_quarter = floor((NUM_LEDS*0.75));                
        leds[quarter+i] = CRGB(0, 243, 122);
        leds[half+i] = CRGB(0, 243, 122);
        leds[three_quarter+i] = CRGB(0, 243, 122);
        FastLED.show();
        delay(actionParam);
        leds[i] = CRGB(0, 0, 0);
        leds[quarter+i] = CRGB(0, 0, 0);
        leds[half+i] = CRGB(0, 0, 0);
        leds[three_quarter+i] = CRGB(0, 0, 0);
        FastLED.show();
      }
    }
    
      else if(ran == 11) {
      for (int i = 0; i < NUM_LEDS/4; i++) {
        leds[i] = CRGB(255, 0, 255);
        int quarter = floor((NUM_LEDS*0.25));
        int half = floor((NUM_LEDS*0.5));
        int three_quarter = floor((NUM_LEDS*0.75));                
        leds[quarter+i] = CRGB(255, 0, 255);
        leds[half+i] = CRGB(255, 0, 255);
        leds[three_quarter+i] = CRGB(255, 0, 255);
        FastLED.show();
        delay(actionParam);
        leds[i] = CRGB(0, 0, 0);
        leds[quarter+i] = CRGB(0, 0, 0);
        leds[half+i] = CRGB(0, 0, 0);
        leds[three_quarter+i] = CRGB(0, 0, 0);
        FastLED.show();
      }
    }
    
      else if(ran == 12) {
      for (int i = 0; i < NUM_LEDS/4; i++) {
        leds[i] = CRGB(122, 106, 0);
        int quarter = floor((NUM_LEDS*0.25));
        int half = floor((NUM_LEDS*0.5));
        int three_quarter = floor((NUM_LEDS*0.75));                
        leds[quarter+i] = CRGB(122, 106, 0);
        leds[half+i] = CRGB(122, 106, 0);
        leds[three_quarter+i] = CRGB(122, 106, 0);
        FastLED.show();
        delay(actionParam);
        leds[i] = CRGB(0, 0, 0);
        leds[quarter+i] = CRGB(0, 0, 0);
        leds[half+i] = CRGB(0, 0, 0);
        leds[three_quarter+i] = CRGB(0, 0, 0);
        FastLED.show();
      }
    }
    
      else if(ran == 13) {
      for (int i = 0; i < NUM_LEDS/4; i++) {
        leds[i] = CRGB(135, 255, 12);
        int quarter = floor((NUM_LEDS*0.25));
        int half = floor((NUM_LEDS*0.5));
        int three_quarter = floor((NUM_LEDS*0.75));                
        leds[quarter+i] = CRGB(135, 255, 12);
        leds[half+i] = CRGB(135, 255, 12);
        leds[three_quarter+i] = CRGB(135, 255, 12);
        FastLED.show();
        delay(actionParam);
        leds[i] = CRGB(0, 0, 0);
        leds[quarter+i] = CRGB(0, 0, 0);
        leds[half+i] = CRGB(0, 0, 0);
        leds[three_quarter+i] = CRGB(0, 0, 0);
        FastLED.show();
      }
    }
      e
      lse if(ran == 14) {
      for (int i = 0; i < NUM_LEDS/4; i++) {
        leds[i] = CRGB(255, 255, 255);
        int quarter = floor((NUM_LEDS*0.25));
        int half = floor((NUM_LEDS*0.5));
        int three_quarter = floor((NUM_LEDS*0.75));                
        leds[quarter+i] = CRGB(255, 255, 255);
        leds[half+i] = CRGB(255, 255, 255);
        leds[three_quarter+i] = CRGB(255, 255, 255);
        FastLED.show();
        delay(actionParam);
        leds[i] = CRGB(0, 0, 0);
        leds[quarter+i] = CRGB(0, 0, 0);
        leds[half+i] = CRGB(0, 0, 0);
        leds[three_quarter+i] = CRGB(0, 0, 0);
        FastLED.show();
      }
    } 

}
void loop() {
  // while messages coming in
  while(Serial.available()){
    value = Serial.read();
    analogin = analogRead(analogpin);
    analogin2 = analogRead(analogpin2);

    // mode selector
    if(analogin > 500){
      modeSelect = 'b';
    }
     else if(analogin < 500){
      modeSelect = 's';
    }
    
    //map pin 2 to action parameter (delaytime, colourskew)
    if((value == '1')&&(modeSelect == 'b')){ 
      sharpshooter(analogin2);
    }
    else if ((value == '1')&&(modeSelect == 's')){ 
      blinker(analogin2);
    }
   
    //end serial
  }



      
}

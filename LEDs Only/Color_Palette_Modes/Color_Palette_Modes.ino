#include <FastLED.h>
#define LED_PIN     5
#define NUM_LEDS    50
#define BRIGHTNESS  200
#define LED_TYPE    WS2811
#define COLOR_ORDER RGB
#define STROBE 0.5
#define CLOCK_PIN 1
#define GAP 1
#define COLOR_CHANGE_RATE 0
#define MODE_CHANGE_RATE 100
#define NUM_PATTERN1 400

int j= 255;
int h= 0;

CRGB leds[NUM_LEDS];
int palette_1[] = {0, 32, 64, 96, 128, 160, 192, 224};
int palette_size = sizeof(palette_1) / sizeof(palette_1[0]);
//int palette_2[] = {0, 32, 64, 96, 128, 160, 192, 224};



void setup() {

//  delay( 3000 ); // power-up safety delay
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
  FastLED.setBrightness(  BRIGHTNESS );
  Serial.begin(9600);
  Serial.print("test");

}

void loop() {

  for(int i = 0; i < NUM_LEDS; i++) { 
      h = h + 5;  
      leds[i] = CHSV( h, 255, 255 );
      delay(GAP);
      FastLED.show();
  }
  
//  delay(COLOR_CHANGE_RATE);
  for(int i = 50; i > NUM_LEDS; i--) { 
      j = j - 5;  
      leds[i] = CHSV( j, 255, 255 );
      delay(GAP);
      FastLED.show();
  }
  
//  delay(COLOR_CHANGE_RATE);

}



//  for (int i = 0; i < NUM_LEDS; i++){
//    Serial.print(i);
//      if (i > NUM_LEDS) {
//        i--;
//        Serial.print(i);
//      }
//      else if (h <= -1){
//        i++;
//        Serial.print(" " + String(i) + " ");
//      }
//  }

//void mode() {

//  for (int i = 0; i < NUM_PATTERN1; i++) {
//    mode();
//  }
//
////  for(int i = 0; i < NUM_LEDS; i++) { 
////      h = h ;  
////      int h = palette_1[i];
////      leds[i] = CHSV( h, 255, 255 );
////      delay(GAP);
////
////  }
//
//  for (int i = 0; i < NUM_LEDS; i++){
//    if (h > palette_size) {
//      j--;
////      h = palette_1[j];
////      leds[i] = CHSV( h, 255, 255 );
////      delay(GAP);
////      FastLED.show();
//    }
//    else if (h <= -1){
//      j++;
//    }
////      int h = palette_1[i];
////      leds[i] = CHSV( h, 255, 255 );
////      delay(GAP);
////      FastLED.show();
//
//  }
////      FastLED.show();
////      delay(COLOR_CHANGE_RATE);
//}

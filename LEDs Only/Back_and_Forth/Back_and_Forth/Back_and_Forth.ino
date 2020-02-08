#include <FastLED.h>
#define LED_PIN     5
#define NUM_LEDS    100
#define BRIGHTNESS  255
#define LED_TYPE    WS2811
#define COLOR_ORDER RGB
#define STROBE 0.5
#define GAP 100
CRGB leds[NUM_LEDS];

//int a = 1;
//int b = 2;
//int c = 3;
int h = 0;
int dot;

void setup() {
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );

}

void loop() {
  for(int dot = 0; dot < NUM_LEDS; dot++){
//    int pos = sin(NUM_LEDS);
    leds[sin16(dot)] = CRGB::Blue;
    FastLED.show();
    delay(STROBE);
    // clear this led for the next time around the loop
    leds[dot] = CRGB::Black;
    FastLED.show();
    delay(GAP);
//    FastLED.show();
  }

//  for(int dot = 0; dot < NUM_LEDS; dot++){ 
//    
//    leds[NUM_LEDS - dot] = CRGB::Blue;
//    FastLED.show();
//    
//    // clear this led for the next time around the loop
//    leds[NUM_LEDS - dot] = CRGB::Black;
//    
//    delay(30);
//  }
}

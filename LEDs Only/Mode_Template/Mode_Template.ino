#include <FastLED.h>
#define LED_PIN     5
#define NUM_LEDS    100
#define BRIGHTNESS  255
#define LED_TYPE    WS2811
#define COLOR_ORDER RGB
#define STROBE 0.1
#define GAP 50
#define RATE
CRGB leds[NUM_LEDS];

int h = 0;

void setup() {
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );

}

void loop() {
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CHSV( 1, 255, 255 );

    FastLED.show();
//    delay(STROBE);
    leds[i] = CHSV( 0, 0, 0 );
    FastLED.show();
//    delay(GAP);
  }

}

//
//void loop() {
//
//  for (int i = 0; i < NUM_LEDS; i++) {
//    leds[i] = CHSV( 1, 255, 255 );
//
//    FastLED.show();
//    delay(STROBE)
//    leds[i] = CHSV( 1, 0, 255 );
//    FastLED.show();
//    delay(GAP)
//  }
//}



//
////int h = 0;
////
////void loop() {
////  for (int i = 0; i < NUM_LEDS; i++) {
////    h = h + 5;
////    leds[i] = CHSV( h, 255, 255 );
////    //    delay(STROBE);
////  }
////  FastLED.show();
////  delay(STROBE);
////  fill_solid(leds, NUM_LEDS, CHSV( 0, 0, 0 )); // Set all to red.
////  FastLED.show();
////  delay(GAP);
////
////}

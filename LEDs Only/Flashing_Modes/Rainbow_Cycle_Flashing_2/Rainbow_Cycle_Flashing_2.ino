#include <FastLED.h>
#define LED_PIN     5
#define NUM_LEDS    50
#define BRIGHTNESS  100
#define LED_TYPE    WS2811
#define COLOR_ORDER RGB
#define STROBE 0.5
#define GAP 100
CRGB leds[NUM_LEDS];

//int a = 1;
//int b = 2;
//int c = 3;
int h = 0;
long randNumber_1;
long randNumber_2;
long randNumber_3;
long randNumber_4;
long randNumber_5;
long randNumber_6;

void setup() {
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );

}

void loop() {
  // put your main code here, to run repeatedly:
      // Turn the first led red for 1 second
//      leds[0] = CRGB::Red; 
//      FastLED.show();
//      delay(1000);
//      
//      // Set the first led back to black for 1 second
//      leds[0] = CRGB::Black;
//      FastLED.show();
//      delay(1000);
      
      for(int i = 0; i < NUM_LEDS; i++) { 
          h = h + 5;  
          randNumber_1 = random(255);
          leds[i] = CHSV( h, 255, 255 );
//          FastLED.show();
          // clear this led for the next time around the loop
//          delay(GAP);
//          leds[i] = CRGB::Black;
      }
      FastLED.show();
      
      delay(GAP);
//      int v = 0;
//      for(int h = 0; h < 255; h = h + 5) { 
////        if (i > 255){
////          int i = 0
////          fill_solid(leds, NUM_LEDS, CHSV( i, 255, 255 )); // Set all to red.
////          FastLED.show();
////          delay(DELAY);
////        }
//        v = v + 5;
//        randNumber = random(255);
//        // Turn All LEDs On
//        fill_solid(leds, NUM_LEDS, CHSV( randNumber, 255, 255 )); // Set all to red.
//        FastLED.show();
//        delay(STROBE);
//        // Turn All LEDs Off
//        fill_solid(leds, NUM_LEDS, CHSV( 0, 0, 0 ));
//        FastLED.show();
//        delay(GAP);
//      }
//        fill_solid(leds, NUM_LEDS, CHSV( 0, 255, 255 )); // Set all to red.
//        FastLED.show();
//        delay(DELAY);
//        fill_solid(leds, NUM_LEDS, CHSV( 32, 255, 255 )); // Set all to red.
//        FastLED.show();
//        delay(DELAY);
//        fill_solid(leds, NUM_LEDS, CHSV( 64, 255, 255 )); // Set all to red.
//        FastLED.show();
//        delay(DELAY);
//        fill_solid(leds, NUM_LEDS, CHSV( 96, 255, 255 )); // Set all to red.
//        FastLED.show();
//        delay(DELAY);
//        fill_solid(leds, NUM_LEDS, CHSV( 128, 255, 255 )); // Set all to red.
//        FastLED.show();
//        delay(DELAY);
//        fill_solid(leds, NUM_LEDS, CHSV( 160, 255, 255 )); // Set all to red.
//        FastLED.show();
//        delay(DELAY);
//        fill_solid(leds, NUM_LEDS, CHSV( 192, 255, 255 )); // Set all to red.
//        FastLED.show();
//        delay(DELAY);
//        fill_solid(leds, NUM_LEDS, CHSV( 224, 255, 255 )); // Set all to red.
//        FastLED.show();
//        delay(DELAY);

}

#include <FastLED.h>
#define LED_PIN     5
#define NUM_LEDS    50
#define BRIGHTNESS  100
#define LED_TYPE    WS2811
#define COLOR_ORDER RGB
#define STROBE 0.5
#define GAP 10
CRGB leds[NUM_LEDS];

//int a = 1;
//int b = 2;
//int c = 3;
int h = 0;
long randNumber;

void setup() {
  // put your setup code here, to run once:
//  FastLED.addLeds<NEOPIXEL, DATA_PIN, COLOR_ORDER>(leds, NUM_LEDS);
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
      
//      for(int i = 0; i < NUM_LEDS; i++) { 
//          h = h + 5;  
//          leds[i] = CHSV( h, 255, 255 );
//          leds[i+1] = CHSV( h+5, 255, 255 );
//          leds[i+2] = CHSV( h+10, 255, 255 );
//          leds[i+3] = CHSV( h+15, 255, 255 );
//          leds[i+4] = CHSV( h+20, 255, 255 );
//          leds[i+5] = CHSV( h+25, 255, 255 );
//          FastLED.show();
//          // clear this led for the next time around the loop
//          leds[i] = CRGB::Black;
//          delay(30);
//      }
      int v = 0;
      for(int h = 0; h < 255; h = h + 5) { 
        v = v + 5;
        randNumber = random(255);
        // Turn All LEDs On
        fill_solid(leds, NUM_LEDS, CHSV( randNumber, 255, 255 )); // Set all to red.
        FastLED.show();
        delay(STROBE);
        // Turn All LEDs Off
        fill_solid(leds, NUM_LEDS, CHSV( 0, 0, 0 ));
        FastLED.show();
        delay(GAP);
      }
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

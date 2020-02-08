#include <FastLED.h>
#define LED_PIN     5
#define NUM_LEDS    50
#define BRIGHTNESS  100
#define LED_TYPE    WS2811
#define COLOR_ORDER RGB
#define STROBE 0.5
#define CLOCK_PIN 1
#define GAP 1
#define RATE 1
CRGB leds[NUM_LEDS];

int h = 128;

void setup() {
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );

}

//void setup() { 
//        FastLED.addLeds<APA102, LED_PIN, CLOCK_PIN, RGB, DATA_RATE_MHZ(24)>(leds, NUM_LEDS);
//}

void loop() {
      
      for(int i = 0; i < NUM_LEDS; i++) { 
        if (h >= 192) {
          int h = 128;
          h = h + 2.54;  
          leds[i] = CHSV( h, 255, 255 );
          delay(GAP);
        }
        else if (h >= 128){
          int h = 128;
          h = h + 2.54;  
          leds[i] = CHSV( h, 255, 255 );
          delay(GAP);
        }
      }
      FastLED.show();
      delay(RATE);


}

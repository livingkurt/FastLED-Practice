#include <FastLED.h>
#define LED_PIN     5
#define NUM_LEDS    100
#define BRIGHTNESS  255
#define LED_TYPE    WS2811
#define COLOR_ORDER RGB
#define GAP 1
#define RATE 50
CRGB leds[NUM_LEDS];
int h = 0;

void setup() {
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );

}

//void setup() {
//        FastLED.addLeds<APA102, LED_PIN, CLOCK_PIN, RGB, DATA_RATE_MHZ(24)>(leds, NUM_LEDS);
//}

void loop() {

  for (int i = 0; i < NUM_LEDS; i++) {
    h = h + 1;
    leds[i] = CHSV( h, 255, 255 );
    FastLED.show();
    delay(GAP);
  }
//  delay(RATE);
  FastLED.show();
  delay(RATE);
  


}

#include <FastLED.h>
#define LED_PIN     5
#define NUM_LEDS    50
#define BRIGHTNESS  100
#define LED_TYPE    WS2811
#define COLOR_ORDER RGB
#define STROBE 1
#define GAP 0
#define COLOR_CHANGE_RATE 0
CRGB leds[NUM_LEDS];

//int a = 1;
//int b = 2;
//int c = 3;
int h = 0;


void setup() {
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
  FastLED.setBrightness(BRIGHTNESS);

}

void loop() {
    for(int i = 0; i < NUM_LEDS; i++) {
//        h = h + 5;
        leds[random(NUM_LEDS)] = CHSV( random(127, 192), 255, 255 ); // Change To Random LED and change color to White
        FastLED.show();
        delay(STROBE);
        fill_solid(leds, NUM_LEDS, CHSV( 0, 0, 0 )); // Set all to Off.
        FastLED.show();
        delay(GAP);
 
    }
      
}

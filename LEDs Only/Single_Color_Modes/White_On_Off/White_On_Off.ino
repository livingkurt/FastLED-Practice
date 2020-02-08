#include <FastLED.h>
#define LED_PIN     2
#define NUM_LEDS    50
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
  FastLED.setBrightness(  BRIGHTNESS );

}

void loop() {
//  fill_solid(leds, NUM_LEDS, CHSV( 255, 0, 255 )); // Set all to red.
  fill_solid(leds, NUM_LEDS, CRGB( 255, 255, 255 )); // Set all to red.
//  fill_solid(leds, NUM_LEDS, CRGB( Candle )); // Set all to red.
  FastLED.show();
}

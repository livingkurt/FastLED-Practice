#include <FastLED.h>
#define LED_PIN     5
#define NUM_LEDS    50
#define BRIGHTNESS  100
#define LED_TYPE    WS2811
#define COLOR_ORDER RGB
#define STROBE 0.5
#define GAP 50
#define COLOR_CHANGE_RATE 0
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
      for(int i = 0; i < NUM_LEDS; i++) { 
          h = h + 5;  
          leds[i] = CHSV( h, 255, 255 );
          delay(COLOR_CHANGE_RATE);
      }
      FastLED.show();
      delay(STROBE);
      fill_solid(leds, NUM_LEDS, CHSV( 0, 0, 0 )); // Set all to red.
      FastLED.show();
      delay(GAP);
      
}

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
//#define NUM_PATTERN2 60
//#define NUM_PATTERN3 400
//#define NUM_PATTERN4 60
int h = 0;

CRGB leds[NUM_LEDS];
int palette_1[] = {0, 32, 64, 96, 128, 160, 192, 224};
//int palette_1[] = {0, 32, 64, 96, 128, 160, 192, 224};



void setup() {

  delay( 3000 ); // power-up safety delay
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
  FastLED.setBrightness(  BRIGHTNESS );

}

void loop() {
  
  for (int i = 0; i < NUM_PATTERN1; i++) {
    mode();
  }

}


void mode() {
  for(int i = 0; i < NUM_LEDS; i++) { 
        h = h + 5;  
        leds[i] = CHSV( h, 255, 255 );
        delay(GAP);
  }
  FastLED.show();
  delay(RATE);
}

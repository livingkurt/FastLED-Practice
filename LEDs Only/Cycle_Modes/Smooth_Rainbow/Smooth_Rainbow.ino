#include <FastLED.h>
#define LED_PIN     5
#define NUM_LEDS    50
#define BRIGHTNESS  255
#define LED_TYPE    WS2811
#define COLOR_ORDER RGB
#define RATE 2
CRGB leds[NUM_LEDS];

int start_hue;
int delta_hue;

void setup() {
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
  Serial.begin(9600);
}

void loop() {

 start_hue = -1*millis()/RATE;
 delta_hue = 10;
 
 fill_rainbow( leds, NUM_LEDS, start_hue, delta_hue );
 FastLED.show();

//    start_hue = -1*millis()/RATE;
    // delta_hue = 10;
    // for (int i = 0; i < NUM_LEDS; i++) {
    //   fill_rainbow( leds, NUM_LEDS, i, delta_hue );
    //   FastLED.show();
    // }
    // for (int i = NUM_LEDS; i > 0; i--) {
    //   fill_rainbow( leds, NUM_LEDS, i, delta_hue );
    //   FastLED.show();
    // }
    
    



}

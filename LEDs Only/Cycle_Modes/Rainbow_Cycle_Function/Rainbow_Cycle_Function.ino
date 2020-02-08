#include <FastLED.h>
#define LED_PIN     5
#define NUM_LEDS    50
#define BRIGHTNESS  100
#define LED_TYPE    WS2811
#define COLOR_ORDER RGB
#define STROBE 0.5
#define CLOCK_PIN 1
#define GAP 1
#define RATE 0.5
CRGB leds[NUM_LEDS];
int h = 0;

void setup() {
    FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );

}

void loop() {
    int k;
    k = Rainbow_Cycle();


}


int Rainbow_Cycle(){
//    for(int i = 0; i < NUM_LEDS; i++) { 
//        h = h + 1;  
//        leds[i] = CHSV( h, 255, 255 );
//        FastLED.delay(GAP);
//    }
//    FastLED.show();
//    FastLED.delay(RATE);
    for (int i = 0; i < 255; i++) {
      fill_rainbow(leds, NUM_LEDS, i, 1);
      FastLED.show();
      FastLED.delay(100);
    }
}

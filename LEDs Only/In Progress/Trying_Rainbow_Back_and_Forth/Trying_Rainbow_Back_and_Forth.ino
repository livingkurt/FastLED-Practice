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
int dot;

void setup() {
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );

}

void loop() {
  for(int dot = 0; dot < NUM_LEDS; dot++){
    
    leds[dot] = CHSV( h, 255, 255 );
    leds[dot+1] = CHSV( h+5, 255, 255 );
    leds[dot+2] = CHSV( h+10, 255, 255 );
    leds[dot+3] = CHSV( h+15, 255, 255 );
    leds[dot+4] = CHSV( h+20, 255, 255 );
    leds[dot+5] = CHSV( h+25, 255, 255 );
    leds[dot+6] = CHSV( h+30, 255, 255 );
    leds[dot+7] = CHSV( h+35, 255, 255 );
    leds[dot+8] = CHSV( h+40, 255, 255 );
    leds[dot+9] = CHSV( h+45, 255, 255 );
    FastLED.show();
    
    // clear this led for the next time around the loop
    leds[dot] = CRGB::Black;
    
    delay(30);
  }

  for(int dot = 0; dot < NUM_LEDS; dot++){ 
    
//    leds[NUM_LEDS - dot] = CRGB::Blue;
    leds[NUM_LEDS - dot] = CHSV( h, 255, 255 );
    leds[NUM_LEDS - dot+1] = CHSV( h+5, 255, 255 );
    leds[NUM_LEDS - dot+2] = CHSV( h+10, 255, 255 );
    leds[NUM_LEDS - dot+3] = CHSV( h+15, 255, 255 );
    leds[NUM_LEDS - dot+4] = CHSV( h+20, 255, 255 );
    leds[NUM_LEDS - dot+5] = CHSV( h+25, 255, 255 );
    leds[NUM_LEDS - dot+6] = CHSV( h+30, 255, 255 );
    leds[NUM_LEDS - dot+7] = CHSV( h+35, 255, 255 );
    leds[NUM_LEDS - dot+8] = CHSV( h+40, 255, 255 );
    leds[NUM_LEDS - dot+9] = CHSV( h+45, 255, 255 );
    FastLED.show();
    
    // clear this led for the next time around the loop
    leds[NUM_LEDS - dot] = CRGB::Black;
    
    delay(30);
  }
}

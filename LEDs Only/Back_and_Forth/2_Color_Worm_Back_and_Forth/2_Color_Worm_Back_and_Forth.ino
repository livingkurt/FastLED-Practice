#include <FastLED.h>
#define LED_PIN     5
#define NUM_LEDS    50
#define BRIGHTNESS  100
#define LED_TYPE    WS2811
#define COLOR_ORDER RGB
#define STROBE 0.5
#define GAP 100
#define COLOR_RATE 50
CRGB leds[NUM_LEDS];

//int a = 1;
//int b = 2;
//int c = 3;
int h = 0;

void setup() {
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );

}


void loop(){
  
  for(int dot=(NUM_LEDS-1) ; dot >=0 ; dot--){ 
    leds[dot] = CRGB::HotPink;
  
    FastLED.show();
    
    delay(COLOR_RATE);
    
    }
  
  for(int dot = 0;dot < NUM_LEDS; dot++){
  
    leds[dot] = CRGB::Blue;
    
    FastLED.show();
    
    delay(COLOR_RATE);
  
  }

}

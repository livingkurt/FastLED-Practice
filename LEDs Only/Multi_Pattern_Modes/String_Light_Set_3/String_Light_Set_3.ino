#include <FastLED.h>
#define LED_PIN     5
#define NUM_LEDS    50
#define BRIGHTNESS  100
#define LED_TYPE    WS2811
#define COLOR_ORDER RGB
#define STROBE 0.5
#define CLOCK_PIN 1
#define GAP 1
#define COLOR_CHANGE_RATE 0
#define MODE_CHANGE_RATE 100
#define NUM_PATTERN1 500
#define NUM_PATTERN2 10



CRGB leds[NUM_LEDS];

#define UPDATES_PER_SECOND 100
int h = 0;

void setup() {
  delay( 3000 ); // power-up safety delay
    FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
    FastLED.setBrightness(  BRIGHTNESS );

}

void loop() {

    for(int i=0; i<NUM_PATTERN1; i++) {
      Rainbow_Cycle();
     }

    for(int i=0; i<NUM_PATTERN2; i++) {
      Sparkle_White();
    } 

}

void Rainbow_Cycle(){
    for(int i = 0; i < NUM_LEDS; i++) { 
        h = h + 5.1;  
        leds[i] = CHSV( h, 255, 255 );
        delay(GAP);
    }
    FastLED.show();
    delay(COLOR_CHANGE_RATE);
}

void Sparkle_White(){
  for(int i = 0; i < NUM_LEDS; i++) {
//      h = h + 5;
      leds[random(NUM_LEDS)] = CHSV( 255, 0, 255 ); // Change To Random LED and change color to White
      FastLED.show();
      delay(STROBE);
      fill_solid(leds, NUM_LEDS, CHSV( 0, 0, 0 )); // Set all to Off.
      FastLED.show();
      delay(GAP);

  }
}

    
    

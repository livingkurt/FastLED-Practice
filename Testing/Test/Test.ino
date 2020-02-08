#include <FastLED.h>
#define LED_PIN     5
#define NUM_LEDS    100
#define BRIGHTNESS  255
#define LED_TYPE    WS2811
#define COLOR_ORDER RGB
#define STROBE 1
#define GAP 50
#define RATE 50
CRGB leds[NUM_LEDS];
int h = 0;
int start_hue;
int delta_hue;

void setup() {
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
  Serial.begin(9600);
}

//void setup() {
//        FastLED.addLeds<APA102, LED_PIN, CLOCK_PIN, RGB, DATA_RATE_MHZ(24)>(leds, NUM_LEDS);
//}

void loop() {

  //  fill_rainbow(leds, NUM_LEDS, 5, 1);

  //  for (int i = 0; i < NUM_LEDS; i++) {
//  for (int h = 0; h < 255; h++) {
//    fill_rainbow(leds, NUM_LEDS, h, 0);
//    FastLED.show();
//    FastLED.delay(STROBE);
//    fill_solid(leds, NUM_LEDS, CHSV( 0, 0, 0 ));
//    FastLED.show();
//    FastLED.delay(GAP);
//  }
  //  }
  start_hue = -1*millis()/20;
  delta_hue = 1;
  
  fill_rainbow( leds, NUM_LEDS, start_hue, delta_hue );
  FastLED.show();

//    for (int i = 0; i < 255; i++) {
//      fill_rainbow(leds, NUM_LEDS, sin(i), 2);
//      FastLED.show();
////      FastLED.delay(100);
//    }

//    for (int i = 0; i < NUM_LEDS; i++) {
//      h = h + 1;
//  //    leds[i] = CHSV( h, 255, 255 );
//      fill_rainbow(leds, NUM_LEDS, h, 10);
//      Serial.println(h);
//      FastLED.show();
//      delay(GAP);
//    }
//    delay(RATE);
//    FastLED.show();
//    delay(RATE);



}

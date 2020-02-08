#include <FastLED.h>
#define LED_PIN     5
#define NUM_LEDS    100
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
long randNumber;

//long randNumber_1;
//long randNumber_2;
//long randNumber_3;
//long randNumber_4;
//long randNumber_5;
//long randNumber_6;
//long randNumber_7;
//long randNumber_8;
//long randNumber_9;
//long randNumber_10;

int counttx = 0;

void setup() {
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );

}

void loop() {
//      , countup = true;
//
//{
//  if (countup)
//  {
//    ++counttx;
//    if (counttx >= 3)
//      countup = false;
//  }
//  else
//  {
//    --counttx;
//    if (counttx <= 0)
//      countup = true;
//  }
//}
      for(int i = 0; i < NUM_LEDS; i++) { 
          h = h + 5;  
          randNumber = random(255);
          leds[i] = CHSV( randNumber, 255, 255 );
          randNumber = random(255);
          leds[i+1] = CHSV( randNumber, 255, 255 );
          randNumber = random(255);
          leds[i+2] = CHSV( randNumber, 255, 255 );
          randNumber = random(255);
          leds[i+3] = CHSV( randNumber, 255, 255 );
          randNumber = random(255);
          leds[i+4] = CHSV( randNumber, 255, 255 );
          randNumber = random(255);
          leds[i+5] = CHSV( randNumber, 255, 255 );
          randNumber = random(255);
          leds[i+6] = CHSV( randNumber, 255, 255 );
          randNumber = random(255);
          leds[i+7] = CHSV( randNumber, 255, 255 );
          randNumber = random(255);
          leds[i+8] = CHSV( randNumber, 255, 255 );
          randNumber = random(255);
          leds[i+9] = CHSV( randNumber, 255, 255 );
          FastLED.show();
          // clear this led for the next time around the loop
          leds[i] = CRGB::Black;
          delay(GAP);
//          h = h + 5;  
//          randNumber_1 = random(255);
//          leds[i] = CHSV( randNumber_1, 255, 255 );
//          randNumber_2 = random(255);
//          leds[i+1] = CHSV( randNumber_2, 255, 255 );
//          randNumber_3 = random(255);
//          leds[i+2] = CHSV( randNumber_3, 255, 255 );
//          randNumber_4 = random(255);
//          leds[i+3] = CHSV( randNumber_4, 255, 255 );
//          randNumber_5 = random(255);
//          leds[i+4] = CHSV( randNumber_5, 255, 255 );
//          randNumber_6 = random(255);
//          leds[i+5] = CHSV( randNumber_6, 255, 255 );
//          FastLED.show();
//          // clear this led for the next time around the loop
//          leds[i] = CRGB::Black;
//          delay(GAP);
      }

}

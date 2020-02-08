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
//    ChangePalettePeriodically();
//    static uint8_t startIndex = 0;
//    startIndex = startIndex + 1; /* motion speed */
    
//    FillLEDsFromPaletteColors( startIndex);
    
//    FastLED.show();
//    FastLED.delay(1000 / UPDATES_PER_SECOND);

    for(int i=0; i<NUM_PATTERN1; i++) {
//      pattern1();
      Rainbow_Cycle();
     }

    for(int i=0; i<NUM_PATTERN2; i++) {
//      pattern2();
      Sparkle_White();
    } 

//    Rainbow_Cycle();
////    delay(MODE_CHANGE_RATE);
//    Sparkle_White();
//    delay(MODE_CHANGE_RATE);

}

//void ChangePalettePeriodically()
//{
//    uint8_t secondHand = (millis() / 1000) % 60;
//    static uint8_t lastSecond = 99;
//    
////    if( lastSecond != secondHand) {
////        lastSecond = secondHand;
////        if( secondHand ==  0)  { 
////          Rainbow_Cycle(); 
////          }
////        if( secondHand == 10)  {
////          Sparkle_White();
////          }
////
////    }
//}



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

    
    

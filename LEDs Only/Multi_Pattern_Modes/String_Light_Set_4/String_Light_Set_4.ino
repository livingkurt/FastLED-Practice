#include <FastLED.h>
#define LED_PIN     5
#define NUM_LEDS    50
#define BRIGHTNESS  200
#define LED_TYPE    WS2811
#define COLOR_ORDER RGB
#define STROBE 0.5
#define CLOCK_PIN 1
#define GAP 1
#define COLOR_CHANGE_RATE 1
#define MODE_CHANGE_RATE 100
#define NUM_PATTERN1 400
#define NUM_PATTERN2 60
#define NUM_PATTERN3 400
#define NUM_PATTERN4 60
int h = 0;

CRGB leds[NUM_LEDS];




void setup() {

  delay( 3000 ); // power-up safety delay
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
  FastLED.setBrightness(  BRIGHTNESS );

}

void loop() {

  for (int i = 0; i < NUM_PATTERN1; i++) {
    Rainbow_Cycle();
  }

  for (int i = 0; i < NUM_PATTERN2; i++) {
    Sparkle_White();
  }
   for(int i=0; i<NUM_PATTERN3; i++) {
      rainbow_cycle_flashing();
   }
//  for (int i = 0; i < NUM_PATTERN4; i++) {
//    Full_Flash_Rainbow_Color();
//  }


}


//Pattern 1
void Rainbow_Cycle() {
  for (int i = 0; i < NUM_LEDS; i++) {
    h = h + 5;
    leds[i] = CHSV( h, 255, 255 );
    delay(GAP);
  }
  FastLED.show();
  //    delay(COLOR_CHANGE_RATE);
}

//Pattern 2
void Sparkle_White() {
  for (int i = 0; i < NUM_LEDS; i++) {
    //      h = h + 5;
    leds[random(NUM_LEDS)] = CHSV( 255, 0, 255 ); // Change To Random LED and change color to White
    FastLED.show();
    delay(STROBE);
    fill_solid(leds, NUM_LEDS, CHSV( 0, 0, 0 )); // Set all to Off.
    FastLED.show();
    delay(GAP);

  }
}



//Pattern 3
void rainbow_cycle_flashing() {

      for(int i = 0; i < NUM_LEDS; i++) { 
          h = h + 5;  
//          randNumber_1 = random(255);
          leds[i] = CHSV( h, 255, 255 );

          delay(GAP);
      }
      FastLED.show();
      delay(COLOR_CHANGE_RATE);
      fill_solid(leds, NUM_LEDS, CHSV( 0, 0, 0 )); // Set all to red.
      FastLED.show();
      delay(COLOR_CHANGE_RATE);

      }

int randNumber;

void Full_Flash_Rainbow_Color() {
//  int GAP= 50;
  int rainbow_palette[] = {0, 32, 64, 96, 128, 160, 192, 224};
  int array_size = sizeof(rainbow_palette) / sizeof(rainbow_palette[0]);
  for (int h = 0; h < array_size; h++) {
    // Turn All LEDs On
    fill_solid(leds, NUM_LEDS, CHSV( rainbow_palette[h], 255, 255 )); // Set all to red.
    FastLED.show();
    delay(STROBE);
    // Turn All LEDs Off
    fill_solid(leds, NUM_LEDS, CHSV( 0, 0, 0 ));
    FastLED.show();
    delay(50);
  }
}

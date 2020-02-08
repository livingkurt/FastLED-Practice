#include <FastLED.h>
#define LED_PIN     5
#define NUM_LEDS    100
#define BRIGHTNESS  200
#define LED_TYPE    WS2811
#define COLOR_ORDER RGB
#define STROBE 0.5
#define CLOCK_PIN 1
#define GAP 1
#define GAP_2 50
#define GAP_3 20
#define GAP_4 30
#define COLOR_CHANGE_RATE 1
#define MODE_CHANGE_RATE 100
#define NUM_PATTERN_1 400
#define NUM_PATTERN_2 60
#define NUM_PATTERN_3 400
#define NUM_PATTERN_4 60
#define NUM_PATTERN_5 60
#define NUM_PATTERN_6 5
#define NUM_PATTERN_7 60
#define NUM_PATTERN_8 2
int h = 0;

CRGB leds[NUM_LEDS];




void setup() {

  delay( 3000 ); // power-up safety delay
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
  FastLED.setBrightness(  BRIGHTNESS );

}

void loop() {

  for (int i = 0; i < NUM_PATTERN_1; i++) {
    Rainbow_Cycle();
  }
  for (int i = 0; i < NUM_PATTERN_2; i++) {
    Sparkle_White();
  }
  for (int i = 0; i < NUM_PATTERN_3; i++) {
    rainbow_cycle_flashing();
  }
  for (int i = 0; i < NUM_PATTERN_4; i++) {
    Sparkle_Rainbow();
  }
  for (int i = 0; i < NUM_PATTERN_5; i++) {
    Full_Flash_Rainbow_Color();
  }
  for (int i = 0; i < NUM_PATTERN_8; i++) {
    Color_Palette_B_n_F_Dim();
  }
  for (int i = 0; i < NUM_PATTERN_6; i++) {
    Full_Color_Rainbow_Fade();
  }
  for (int i = 0; i < NUM_PATTERN_7; i++) {
    Rainbow_B_n_F();
  }
  



}


// Pattern 1
void Rainbow_Cycle() {
  for (int i = 0; i < NUM_LEDS; i++) {
    h = h + 5;
    leds[i] = CHSV( h, 255, 255 );
    delay(GAP);
  }
  FastLED.show();
  //    delay(COLOR_CHANGE_RATE);
}

// Pattern 2
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



// Pattern 3
void rainbow_cycle_flashing() {

  for (int i = 0; i < NUM_LEDS; i++) {
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

// Pattern 4
void Sparkle_Rainbow() {
  for (int i = 0; i < NUM_LEDS; i++) {
    h = h + 5;
    leds[random(NUM_LEDS)] = CHSV( h, 255, 255 ); // Change To Random LED and change color to White
    FastLED.show();
    delay(STROBE);
    fill_solid(leds, NUM_LEDS, CHSV( 0, 0, 0 )); // Set all to Off.
    FastLED.show();
    delay(GAP);

  }

}

// Pattern 5

void Full_Flash_Rainbow_Color() {
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
    delay(GAP_2);
  }
}

// Pattern 6


void Full_Color_Rainbow_Fade() {

  for (int h = 0; h < 255; h = h + 5) {
    for (int dot = 0; dot < NUM_LEDS; dot++) {
      leds[dot] = CHSV( h, 255, 255 );
      FastLED.show();
    }
    h = h + 5;
    for (int dot = 0; dot < NUM_LEDS; dot++) {
      leds[NUM_LEDS - dot] = CHSV( h, 255, 255 );
      FastLED.show();

    }
  }
}
// Pattern 7

void Rainbow_B_n_F() {

  for (int h = 0; h < 255; h = h + 10) {
    for (int dot = 0; dot < NUM_LEDS; dot++) {
      leds[dot] = CHSV( h, 255, 255 );
      FastLED.show();

      delay(GAP_3);
    }
    h = h + 10;
    for (int dot = 0; dot < NUM_LEDS; dot++) {
      leds[NUM_LEDS - dot] = CHSV( h, 255, 255 );
      FastLED.show();

      delay(GAP_3);
    }
  }
}

void Color_Palette_B_n_F_Dim() {
  int rainbow_palette[] = {0, 32, 64, 96, 128, 160, 192, 224};
  int array_size = sizeof(rainbow_palette) / sizeof(rainbow_palette[0]);
  for (int h = 0; h < array_size;  h++) {
    for (int dot = 0,  k = 255; dot < NUM_LEDS, k > 0; dot++, k = k - 5) {
      leds[dot] = CHSV( rainbow_palette[h], 255, k );
      FastLED.show();
      delay(GAP_4);
    }
    
    h++;
    for (int dot = 0,  k = 255; dot < NUM_LEDS, k > 0; dot++, k = k - 5) {
      leds[NUM_LEDS - dot] = CHSV( rainbow_palette[h], 255, k );
      FastLED.show();
      delay(GAP_4);
    }

  }
}

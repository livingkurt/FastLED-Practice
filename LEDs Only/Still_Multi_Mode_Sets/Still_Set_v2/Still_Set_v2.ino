#include <FastLED.h>

FASTLED_USING_NAMESPACE

#if defined(FASTLED_VERSION) && (FASTLED_VERSION < 3001000)
#warning "Requires FastLED 3.1 or later; check github for latest code."
#endif

#define DATA_PIN    5
//#define CLK_PIN   41
#define LED_TYPE    WS2811
#define COLOR_ORDER RGB
#define NUM_LEDS    50

CRGB leds[NUM_LEDS];

#define BRIGHTNESS         255
#define FRAMES_PER_SECOND  120

// Pattern 1
#define GAP_1 1
int a;

// Pattern 2
#define STROBE_2 0.5
#define GAP_2 1
int b;

// Pattern 3
//#define STROBE_2 0.5
#define GAP_3 1
int c;

// Pattern 4
#define STROBE_4 0.5
#define GAP_4 0
int d;

// Pattern 5
#define GAP_5 30

// Pattern 6
#define GAP_6 500
int f;

// Pattern 9
#define GAP_9 100





void setup() {
  delay(3000); // 3 second delay for recovery
  Serial.begin(9600);

  // tell FastLED about the LED strip configuration
  FastLED.addLeds<LED_TYPE, DATA_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
  //FastLED.addLeds<LED_TYPE,DATA_PIN,CLK_PIN,COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);

  // set master brightness control
  FastLED.setBrightness(BRIGHTNESS);
}


// List of patterns to cycle through.  Each is defined as a separate function below.
typedef void (*SimplePatternList[])();
SimplePatternList gPatterns = { 
  rainbow_cycle, 
  sparkle_white, 
  full_color_rainbow_fade, 
  sparkle_rainbow, 
  color_palette_bnf_on, 
  color_palette_blinky, 
//  color_palette_bnf_on_off
  };
//, pattern_5, pattern_6, pattern_7, pattern_8, pattern_9, pattern_10

uint8_t gCurrentPatternNumber = 0; // Index number of which pattern is current
uint8_t gHue = 0; // rotating "base color" used by many of the patterns

void loop()
{
  // Call the current pattern function once, updating the 'leds' array
  gPatterns[gCurrentPatternNumber]();

  // send the 'leds' array out to the actual LED strip
  FastLED.show();
  // insert a delay to keep the framerate modest
  FastLED.delay(1000 / FRAMES_PER_SECOND);

  //  // do some periodic updates
  //  EVERY_N_MILLISECONDS( 20 ) {
  //    gHue++;  // slowly cycle the "base color" through the rainbow
  //  }
  EVERY_N_SECONDS( 10 ) {
    nextPattern();  // change patterns periodically
  }
}

#define ARRAY_SIZE(A) (sizeof(A) / sizeof((A)[0]))

void nextPattern()
{
  // add one to the current pattern number, and wrap around at the end

  gCurrentPatternNumber = (gCurrentPatternNumber + 1) % ARRAY_SIZE( gPatterns);
}


// Pattern 1
void rainbow_cycle() {
  Serial.println("pattern_1");
  for (int i = 0; i < NUM_LEDS; i++) {
    a = a + 5;
    leds[i] = CHSV( a, 255, 255 );
    delay(GAP_1);
  }
  FastLED.show();
}

// Pattern 2
void sparkle_white() {
  Serial.println("pattern_2");
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[random(NUM_LEDS)] = CHSV( 255, 0, 255 ); // Change To Random LED and change color to White
    FastLED.show();
    delay(STROBE_2);
    fill_solid(leds, NUM_LEDS, CHSV( 0, 0, 0 )); // Set all to Off.
    FastLED.show();
    delay(GAP_2);

  }
}

// Pattern 3
void full_color_rainbow_fade() {
  Serial.println("pattern_3");
  for (int h = 0; h < 255; h = h + 5) {
    for (int dot = 0; dot < NUM_LEDS; dot++) {
      leds[dot] = CHSV( h, 255, 255 );
      FastLED.show();
    }
  }

}
// Pattern 4
void sparkle_rainbow() {
  Serial.println("pattern_4");
  for (int i = 0; i < NUM_LEDS; i++) {
    d = d + 5;
    leds[random(NUM_LEDS)] = CHSV( d, 255, 255 ); // Change To Random LED and change color to White
    FastLED.show();
    delay(STROBE_4);
    fill_solid(leds, NUM_LEDS, CHSV( 0, 0, 0 )); // Set all to Off.
    FastLED.show();
    delay(GAP_5);

  }
}


// Pattern 5
void color_palette_bnf_on() {
  Serial.println("pattern_5");
  int rainbow_palette[] = {0, 32, 64, 96, 128, 160, 192, 224};
  int array_size = sizeof(rainbow_palette) / sizeof(rainbow_palette[0]);
  for (int h = 0; h < array_size; h++) {
    for (int dot = 0; dot < NUM_LEDS; dot++) {
      Serial.print("Forward " + String(rainbow_palette[h]) + "\n");
      leds[dot] = CHSV( rainbow_palette[h], 255, 255 );
      FastLED.show();
      delay(GAP_5);
    }
    h++;
    for (int dot = 0; dot < NUM_LEDS; dot++) {
      Serial.print("Backward " + String(rainbow_palette[h]) + "\n");
      leds[NUM_LEDS - dot] = CHSV( rainbow_palette[h], 255, 255 );
      FastLED.show();
      delay(GAP_5);
    }
  }
}



// Pattern 6
void color_palette_blinky() {
  Serial.println("pattern_6");
  int rainbow_palette[] = {0, 32, 64, 96, 128, 160, 192, 224};
  int numColors = (sizeof(rainbow_palette) / sizeof(rainbow_palette[0]));
  for (int i = 0; i <= NUM_LEDS; i++) {
    int color = rainbow_palette[(i + f) % numColors];    // mod 3 means the color number will be 0-2.
    Serial.println(color);
    leds[i] = CHSV( color, 255, 255 );
  }
  FastLED.show();
  f = (f + 1) % numColors;        // Cycle through the starting LED#, 0 to numcolors-1
  delay(GAP_6);

}

// Pattern 7
void pattern_7() {
  Serial.println("pattern_7");
}

// Pattern 8
void pattern_8() {
  Serial.println("pattern_8");
}

// Pattern 9
void color_palette_bnf_on_off() {
  Serial.println("pattern_9");
  int rainbow_palette[] = {0, 32, 64, 96, 128, 160, 192, 224};
  int array_size = sizeof(rainbow_palette) / sizeof(rainbow_palette[0]);
  for (int h = 0; h < array_size; h++) {
    for (int dot = 0; dot < NUM_LEDS; dot++) {
      Serial.print("Forward " + String(rainbow_palette[h]) + "\n");
      leds[dot] = CHSV( rainbow_palette[h], 255, 255 );
      FastLED.show();
      leds[dot] = CRGB::Black;
      delay(GAP_9);
    }
//    h++;
    for (int dot = 0; dot < NUM_LEDS; dot++) {
      Serial.print("Backward " + String(rainbow_palette[h]) + "\n");
      leds[NUM_LEDS - dot] = CHSV( rainbow_palette[h], 255, 255 );
      FastLED.show();
      leds[dot] = CRGB::Black;
      delay(GAP_9);
    }
  }
}

// Pattern 10
void pattern_10() {
  Serial.println("pattern_10");
}

#include <FastLED.h>

FASTLED_USING_NAMESPACE

// FastLED "100-lines-of-code" demo reel, showing just a few
// of the kinds of animation patterns you can quickly and easily
// compose using FastLED.
//
// This example also shows one easy way to define multiple
// animations patterns and have them automatically rotate.
//
// -Mark Kriegsman, December 2014

#if defined(FASTLED_VERSION) && (FASTLED_VERSION < 3001000)
#warning "Requires FastLED 3.1 or later; check github for latest code."
#endif

#define DATA_PIN    5
//#define CLK_PIN   4
#define LED_TYPE    WS2811
#define COLOR_ORDER GRB
#define NUM_LEDS    50

CRGB leds[NUM_LEDS];

#define BRIGHTNESS          96
#define FRAMES_PER_SECOND  120

// Pattern 1
#define GAP_1 1
int h;

// Pattern 2
#define STROBE_2 0.5
#define GAP_2 1

// Pattern 3
//#define STROBE_2 0.5
#define GAP_3 1




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
SimplePatternList gPatterns = { rainbow_cycle, sparkle_white, pattern_3, pattern_4, pattern_5, pattern_6, pattern_7, pattern_8, pattern_9, pattern_10 };

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

  // do some periodic updates
  EVERY_N_MILLISECONDS( 20 ) {
    gHue++;  // slowly cycle the "base color" through the rainbow
  }
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
    h = h + 5;
    leds[i] = CHSV( h, 255, 255 );
    delay(GAP_1);
  }
  FastLED.show();
}


void sparkle_white() {
  Serial.println("pattern_2");
  for (int i = 0; i < NUM_LEDS; i++) {
    //      h = h + 5;
    leds[random(NUM_LEDS)] = CHSV( 255, 0, 255 ); // Change To Random LED and change color to White
    FastLED.show();
    delay(STROBE_2);
    fill_solid(leds, NUM_LEDS, CHSV( 0, 0, 0 )); // Set all to Off.
    FastLED.show();
    delay(GAP_2);

  }
}

void pattern_3() {
  Serial.println("pattern_3");
  for (int i = 0; i < NUM_LEDS; i++) {
    h = h + 5;
    //          randNumber_1 = random(255);
    leds[i] = CHSV( h, 255, 255 );

    delay(GAP_3);
  }
  FastLED.show();
//  delay(COLOR_CHANGE_RATE);
  fill_solid(leds, NUM_LEDS, CHSV( 0, 0, 0 )); // Set all to red.
  FastLED.show();
//  delay(COLOR_CHANGE_RATE);
}

void pattern_4() {
  Serial.println("pattern_4");
}

void pattern_5() {
  Serial.println("pattern_5");
}

void pattern_6() {
  Serial.println("pattern_6");
}

void pattern_7() {
  Serial.println("pattern_7");
}

void pattern_8() {
  Serial.println("pattern_8");
}

void pattern_9() {
  Serial.println("pattern_9");
}

void pattern_10() {
  Serial.println("pattern_10");
}

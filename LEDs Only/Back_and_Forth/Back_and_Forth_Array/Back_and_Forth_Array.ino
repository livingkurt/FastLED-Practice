#include <FastLED.h>
#define LED_PIN     5
#define NUM_LEDS    50
#define BRIGHTNESS  100
#define LED_TYPE    WS2811
#define COLOR_ORDER RGB
#define STROBE 0.5
#define GAP 100
CRGB leds[NUM_LEDS];
int h = 0;

int dot;

void setup() {
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
  Serial.begin(9600);


}

void loop() {
  int rainbow_palette[] = {0, 32, 64, 96, 128, 160, 192, 224};
  int array_size = sizeof(rainbow_palette) / sizeof(rainbow_palette[0]);
  for (int h = 0; h < array_size; h++) {
    for (int dot = 0; dot < NUM_LEDS; dot++) {
      Serial.print("Forward " + String(rainbow_palette[h]) + "\n");
      leds[dot] = CHSV( rainbow_palette[h], 255, 255 );
      FastLED.show();

      // clear this led for the next time around the loop
//      leds[dot] = CRGB::Black;

      delay(30);
    }
    h++;
    for (int dot = 0; dot < NUM_LEDS; dot++) {
      Serial.print("Backward " + String(rainbow_palette[h]) + "\n");
      leds[NUM_LEDS - dot] = CHSV( rainbow_palette[h], 255, 255 );
      FastLED.show();

      // clear this led for the next time around the loop
//      leds[NUM_LEDS - dot] = CRGB::Black;

      delay(30);
    }
  }
}

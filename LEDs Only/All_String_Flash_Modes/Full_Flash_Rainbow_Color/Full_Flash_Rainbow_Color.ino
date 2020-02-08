#include <FastLED.h>
#define LED_PIN     5
#define NUM_LEDS    100
#define BRIGHTNESS  100
#define LED_TYPE    WS2811
#define COLOR_ORDER RGB
#define STROBE 0.5
#define GAP 50
CRGB leds[NUM_LEDS];

int h = 0;

void setup() {

  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );

}

void loop() {
//  void Full_Flash_Rainbow_Color() {
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
    delay(GAP);
  }
}

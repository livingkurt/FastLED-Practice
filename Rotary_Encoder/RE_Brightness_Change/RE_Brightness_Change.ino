#include <FastLED.h>
#define LED_PIN     5
#define NUM_LEDS    50
#define BRIGHTNESS  255
#define LED_TYPE    WS2811
#define COLOR_ORDER RGB
CRGB leds[NUM_LEDS];

#define outputA 6
#define outputB 7
#define outputC 8

int counter = 255;
int counter_b = 0;
int aState;
int aLastState;
int counttx = 0;
int countup = true;

void setup() {
  pinMode (outputA, INPUT);
  pinMode (outputB, INPUT);
  pinMode (outputC, INPUT);

  Serial.begin (9600);
  // Reads the initial state of the outputA
  aLastState = digitalRead(outputA);
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
  FastLED.setBrightness(  BRIGHTNESS );
}

void loop() {
  aState = digitalRead(outputA); // Reads the "current" state of the outputA
  // If the previous and the current state of the outputA are different, that means a Pulse has occured
  if (aState != aLastState) {
    // If the outputB state is different to the outputA state, that means the encoder is rotating clockwise
    if (digitalRead(outputB) != aState) {
      if (counter >= 245) {
        counter = 255;
      }
      else {
        counter = counter + 10;
      }
    } else {
      if (counter <= 5) {
        counter = 1;
      }
      else {
        counter = counter - 10;
      }
    }
//    if (digitalRead(outputC) != aState) {
    Serial.println(counter);
    Serial.println(digitalRead(outputC));
    fill_solid(leds, NUM_LEDS, CHSV( 100, 255, counter ));
    FastLED.show();
  }

  aLastState = aState; // Updates the previous state of the outputA with the current state
}

//if (countup)
//{
//  ++counttx;
//  if (counttx >= 3)
//    countup = false;
//}
//else
//{
//  --counttx;
//  if (counttx <= 0)
//    countup = true;
//}

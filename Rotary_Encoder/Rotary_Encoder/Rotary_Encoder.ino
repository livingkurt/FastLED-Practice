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

int counter = 0;
int counter_b = 0;
int aState;
int aLastState;

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
      counter++;
      
    } else {
      counter--;
    }
//    Serial.print("Position: ");
    Serial.print(outputC);
    Serial.print(counter);
    fill_solid(leds, NUM_LEDS, CHSV( counter, 255, 255 ));
    FastLED.show();
  }
  
  aLastState = aState; // Updates the previous state of the outputA with the current state
}

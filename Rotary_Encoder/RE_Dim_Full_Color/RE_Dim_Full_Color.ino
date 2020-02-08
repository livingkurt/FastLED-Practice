#include "FastLED.h"

FASTLED_USING_NAMESPACE

#define DATA_PIN    5
//#define CLK_PIN   4
#define LED_TYPE    WS2812B
#define COLOR_ORDER GRB
#define NUM_LEDS    6
CRGB leds[NUM_LEDS];

volatile byte BRIGHTNESS = 0;
#define FRAMES_PER_SECOND  120

static int pinA = 2; // Our first hardware interrupt pin is digital pin 2
static int pinB = 3; // Our second hardware interrupt pin is digital pin 3
static int pinC = 4;
volatile long pinCignoreCycles = 0;         // the last time the output pin was sampled
volatile byte aFlag = 0; // let's us know when we're expecting a rising edge on pinA to signal that the encoder has arrived at a detent
volatile byte bFlag = 0; // let's us know when we're expecting a rising edge on pinB to signal that the encoder has arrived at a detent (opposite direction to when aFlag is set)
volatile byte encoderPos = 0; //this variable stores our current value of encoder position. Change to int or uin16_t instead of byte if you want to record a larger range than 0-255
volatile byte oldEncPos = 0; //stores the last encoder position value so we can compare to the current reading and see if it has changed (so we know when to print to the serial monitor)
volatile byte reading = 0; //somewhere to store the direct values we read from our interrupt pins before checking to see if we have moved a whole detent
volatile bool encoderMode = true; // 0 brightness // 1 pattern
// List of patterns to cycle through.  Each is defined as a separate function below.
typedef void (*SimplePatternList[])();
SimplePatternList gPatterns = { rainbow, rainbowWithGlitter, confetti, sinelon, juggle, bpm, white, red,redglitter, green,greenglitter, blue };

uint8_t gCurrentPatternNumber = 0; // Index number of which pattern is current
uint8_t gHue = 0; // rotating "base color" used by many of the patterns


void setup() {
    delay(3000); // 3 second delay for recovery

  // tell FastLED about the LED strip configuration
  FastLED.addLeds<LED_TYPE,DATA_PIN,COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
  //FastLED.addLeds<LED_TYPE,DATA_PIN,CLK_PIN,COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);

  // set master brightness control
  FastLED.setBrightness(BRIGHTNESS);

  pinMode(pinA, INPUT_PULLUP); // set pinA as an input, pulled HIGH to the logic voltage (5V or 3.3V for most cases)
  pinMode(pinB, INPUT_PULLUP); // set pinB as an input, pulled HIGH to the logic voltage (5V or 3.3V for most cases)
  attachInterrupt(0,PinA,RISING); // set an interrupt on PinA, looking for a rising edge signal and executing the "PinA" Interrupt Service Routine (below)
  attachInterrupt(1,PinB,RISING); // set an interrupt on PinB, looking for a rising edge signal and executing the "PinB" Interrupt Service Routine (below)
  pinMode(pinC, INPUT_PULLUP);
  Serial.begin(115200); // start the serial monitor link
}

void PinA(){
  cli(); //stop interrupts happening before we read pin values
  reading = PIND & 0xC; // read all eight pin values then strip away all but pinA and pinB's values
  if(reading == B00001100 && aFlag) { //check that we have both pins at detent (HIGH) and that we are expecting detent on this pin's rising edge
  encoderPos ++; //decrement the encoder's position count
  bFlag = 0; //reset flags for the next turn
  aFlag = 0; //reset flags for the next turn
  }
  else if (reading == B00000100) bFlag = 1; //signal that we're expecting pinB to signal the transition to detent from free rotation
  sei(); //restart interrupts
}

void PinB(){
  cli(); //stop interrupts happening before we read pin values
  reading = PIND & 0xC; //read all eight pin values then strip away all but pinA and pinB's values
  if (reading == B00001100 && bFlag) { //check that we have both pins at detent (HIGH) and that we are expecting detent on this pin's rising edge
  encoderPos --; //increment the encoder's position count
  bFlag = 0; //reset flags for the next turn
  aFlag = 0; //reset flags for the next turn
  }
  else if (reading == B00001000) aFlag = 1; //signal that we're expecting pinA to signal the transition to detent from free rotation
  sei(); //restart interrupts
}
byte b; // used to detect if brighness have overflowed
void loop(){

  if(oldEncPos != encoderPos) {
    if (encoderMode) {
      if (oldEncPos > encoderPos) {
        b = BRIGHTNESS;
        BRIGHTNESS -= 15;
        if(BRIGHTNESS > b) {
          BRIGHTNESS = 0;
        }
      } else {
        b = BRIGHTNESS;
        BRIGHTNESS += 15;
        if(BRIGHTNESS < b) {
          BRIGHTNESS = 255;
        }
      }
      FastLED.setBrightness(BRIGHTNESS);
    }
    if (!encoderMode) {
      if (oldEncPos > encoderPos) {
        prevPattern();
      } else {
        nextPattern();
      }
    }

    Serial.print("C:");
    Serial.print(BRIGHTNESS);
    Serial.print(",");
    Serial.print(gCurrentPatternNumber);
    Serial.println(".");
    oldEncPos = encoderPos;
  }

  if (pinCignoreCycles > 0) {
    pinCignoreCycles--;
  }

  if(pinCignoreCycles == 0) {
    if(digitalRead(pinC) == LOW) {
      pinCignoreCycles = 25;
      Serial.println("Btn");
      encoderMode = !encoderMode;

    }
  }

  // Call the current pattern function once, updating the 'leds' array
  gPatterns[gCurrentPatternNumber]();

  // send the 'leds' array out to the actual LED strip
  FastLED.show();
  // insert a delay to keep the framerate modest
  FastLED.delay(1000/FRAMES_PER_SECOND);

  // do some periodic updates
  EVERY_N_MILLISECONDS( 20 ) { gHue++; } // slowly cycle the "base color" through the rainbow
  EVERY_N_SECONDS(30) {
    if(BRIGHTNESS > 0) {
      BRIGHTNESS--;
      Serial.print("A:");
      Serial.print(BRIGHTNESS);
      Serial.print(",");
      Serial.print(gCurrentPatternNumber);
      Serial.println(".");
      if (BRIGHTNESS == 0) {
        encoderMode = true; //fall back to brightness mode
      }
      FastLED.setBrightness(BRIGHTNESS);
    }
  }
}


#define ARRAY_SIZE(A) (sizeof(A) / sizeof((A)[0]))

void nextPattern()
{
  // add one to the current pattern number, and wrap around at the end
  gCurrentPatternNumber = (gCurrentPatternNumber + 1) % ARRAY_SIZE( gPatterns);
}
void prevPattern()
{
  gCurrentPatternNumber = (gCurrentPatternNumber - 1);
  if (gCurrentPatternNumber > ARRAY_SIZE(gPatterns)) {
    gCurrentPatternNumber = ARRAY_SIZE(gPatterns)-1;
  }
}

void rainbow()
{
  // FastLED's built-in rainbow generator
  fill_rainbow( leds, NUM_LEDS, gHue, 7);
}

void rainbowWithGlitter()
{
  // built-in FastLED rainbow, plus some random sparkly glitter
  rainbow();
  addGlitter(80);
}

void addGlitter( fract8 chanceOfGlitter)
{
  if( random8() < chanceOfGlitter) {
    leds[ random16(NUM_LEDS) ] += CRGB::White;
  }
}

void confetti()
{
  // random colored speckles that blink in and fade smoothly
  fadeToBlackBy( leds, NUM_LEDS, 10);
  int pos = random16(NUM_LEDS);
  leds[pos] += CHSV( gHue + random8(64), 200, 255);
}

void sinelon()
{
  // a colored dot sweeping back and forth, with fading trails
  fadeToBlackBy( leds, NUM_LEDS, 20);
  int pos = beatsin16(13,0,NUM_LEDS);
  leds[pos] += CHSV( gHue, 255, 192);
}

void bpm()
{
  // colored stripes pulsing at a defined Beats-Per-Minute (BPM)
  uint8_t BeatsPerMinute = 62;
  CRGBPalette16 palette = PartyColors_p;
  uint8_t beat = beatsin8( BeatsPerMinute, 64, 255);
  for( int i = 0; i < NUM_LEDS; i++) { //9948
    leds[i] = ColorFromPalette(palette, gHue+(i*2), beat-gHue+(i*10));
  }
}

void juggle() {
  // eight colored dots, weaving in and out of sync with each other
  fadeToBlackBy( leds, NUM_LEDS, 20);
  byte dothue = 0;
  for( int i = 0; i < 8; i++) {
    leds[beatsin16(i+7,0,NUM_LEDS)] |= CHSV(dothue, 200, 255);
    dothue += 32;
  }
}
void white() {
  for(int i=0; i < NUM_LEDS; i++) {
    leds[i] = 0xFFFFFF;
  }
}
void red() {
  for(int i=0; i < NUM_LEDS; i++) {
    leds[i] = 0x00FF00;
  }
}
void redglitter() {
  for(int i=0; i < NUM_LEDS; i++) {
    leds[i] = 0x00FF00;
  }
  addGlitter(80);
}
void green() {
  for(int i=0; i < NUM_LEDS; i++) {
    leds[i] = 0xFF0000;
  }
}
void greenglitter() {
  for(int i=0; i < NUM_LEDS; i++) {
    leds[i] = 0xFF0000;
    addGlitter(80);
  }
}
void blue() {
  for(int i=0; i < NUM_LEDS; i++) {
    leds[i] = 0x0000FF;
  }
}

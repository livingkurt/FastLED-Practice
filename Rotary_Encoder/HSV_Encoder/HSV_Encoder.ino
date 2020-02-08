///*
//
//This example demonstrates the use of the library on an ESP8266. without using a timer interrupt
//
// */
//
//#include <ClickEncoder.h>
////#include <TimerOne.h>
//
//
//#define ENCODER_PINA     6
//#define ENCODER_PINB     7
//#define ENCODER_BTN      8
//
//#define ENCODER_STEPS_PER_NOTCH    4   // Change this depending on which encoder is used
//
//ClickEncoder encoder = ClickEncoder(ENCODER_PINA,ENCODER_PINB,ENCODER_BTN,ENCODER_STEPS_PER_NOTCH);
//
//void setup() {
//  Serial.begin(9600);
//
////  encoder.setButtonHeldEnabled(true);
//  encoder.setDoubleClickEnabled(true);
//
//  // Enable the button to be on pin 0.  Normally pin 0 is not recognized as a valid pin for a button,
//  // this is to maintain backward compatibility with an old version of the library
//  // This version can have the button on pin zero, and this call enables the feature.
//  // in this version best to use pin -1 instead of 0 to disable button functions
////  encoder.setButtonOnPinZeroEnabled(true);
//
//}
//
//void loop() {
//
//  //Call Service in loop becasue using timer interrupts may affect ESP8266 WIFI
//  //however call no more than 1 time per millisecond to reduce encoder bounce
//  static uint32_t lastService = 0;
//  if (lastService + 1000 < micros()) {
//    lastService = micros();
//    encoder.service();
//  }
//
//
//static int16_t last, value;
//    value += encoder.getValue();
//
//  if (value != last) {
//    last = value;
//    Serial.print("Encoder Value: ");
//    Serial.println(value);
//
//  }
//
//  ClickEncoder::Button b = encoder.getButton();
//  if (b != ClickEncoder::Open) {
//    Serial.print("Button: ");
//    #define VERBOSECASE(label) case label: Serial.println(#label); break;
//    switch (b) {
//      VERBOSECASE(ClickEncoder::Pressed);
//      VERBOSECASE(ClickEncoder::Held)
//      VERBOSECASE(ClickEncoder::Released)
//      VERBOSECASE(ClickEncoder::Clicked)
//      VERBOSECASE(ClickEncoder::DoubleClicked)
//    }
//  }
//}


#include <ClickEncoder.h>
#include <TimerOne.h>
#include <FastLED.h>
#define LED_PIN     5
#define NUM_LEDS    50
#define BRIGHTNESS  255
#define LED_TYPE    WS2811
#define COLOR_ORDER RGB
CRGB leds[NUM_LEDS];

int16_t oldEncPos, encPos;
uint8_t buttonState;
int aState;
int counter = 0;

#define pinA 7
#define pinB 6
#define pinSw 8 //switch
#define STEPS 4

ClickEncoder encoder(pinA, pinB, pinSw, STEPS);

void setup() {
  Serial.begin(9600);

  Timer1.initialize(1000);
  Timer1.attachInterrupt(timerIsr);

  encoder.setAccelerationEnabled(true);

  Serial.print("Acceleration is ");
  Serial.println((encoder.getAccelerationEnabled()) ? "enabled" : "disabled");
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
  FastLED.setBrightness(  BRIGHTNESS );

  oldEncPos = -1;
}

int change_hue(int h) {
  Serial.print(h);
  fill_solid(leds, NUM_LEDS, CHSV( h, 255, 255 ));
  FastLED.show();
}

//int change_brightness(encPos) {
//  fill_solid(leds, NUM_LEDS, CHSV( 255, encPos, 255 ));
//  FastLED.show();
//}
//
//int change_saturation(encPos) {
//  fill_solid(leds, NUM_LEDS, CHSV( 255, 255, encPos ));
//  FastLED.show();
//}

void loop() {
  encPos += encoder.getValue();

  if (encPos != oldEncPos) {
    oldEncPos = encPos;
    Serial.print("Encoder Value: ");
    Serial.println(encPos);
  }

  buttonState = encoder.getButton();

  if (buttonState != 0) {
    Serial.print("Button: "); Serial.println(buttonState);
    switch (buttonState) {
      case ClickEncoder::Open:          //0
        fill_solid(leds, NUM_LEDS, CHSV( encPos, 255, 255 ));
        FastLED.show();
        break;

      case ClickEncoder::Closed:        //1
        break;

      case ClickEncoder::Pressed:       //2
        break;

      case ClickEncoder::Held:          //3
        break;

      case ClickEncoder::Released:      //4
        change_hue(encPos);
        break;

      case ClickEncoder::Clicked:       //5
        //        change_brightness(s)

        break;

      case ClickEncoder::DoubleClicked: //6
        //        change_saturation(v)
        break;
    }
  }
}

void timerIsr() {
  encoder.service();
}

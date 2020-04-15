#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <FastLED.h>
#include "value.h"
#include "Output.h"
#include "encode.h"
#include "menu.h"

#define debug 1

#define NUM_LEDS 4
CRGB leds[NUM_LEDS];
#define COLOR_ORDER RGB
#define CHIPSET     WS2811
#define BRIGHTNESS  200
#define FRAMES_PER_SECOND 10

TwoWire Wire(PB6, PB7, SOFT_STANDARD);
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  FastLED.addLeds<CHIPSET, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
  FastLED.setBrightness( BRIGHTNESS );
  lcd.init();
  lcd.backlight();
  pinMode (encoder0PinA, INPUT);
  pinMode (encoder0PinB, INPUT);
  pinMode (Taster_enco_pin, INPUT);
  pinMode (Taster1, INPUT);
  pinMode (Taster2, INPUT);
  pinMode (Taster3, INPUT);
  pinMode (Taster4, INPUT);
  pinMode (NTC_pin, INPUT);
  pinMode (3D_Printer_pin, INPUT);

  pinMode (Relais1_pin, OUTPUT);
  pinMode (Relais2_pin, OUTPUT);
  pinMode (Relais3_pin, OUTPUT);
  pinMode (Relais4_pin, OUTPUT);
  pinMode (Relais5_pin, OUTPUT);
  pinMode (Relais6_pin, OUTPUT);
  pinMode (Relais7_pin, OUTPUT);
  pinMode (Relais8_pin, OUTPUT);

  attachInterrupt(encoder0PinA, doEncoderA, CHANGE);
  attachInterrupt(encoder0PinB, doEncoderB, CHANGE);

  lcd.clear()
  lcd.setCursor(0, 0);
  lcd.print("Init");
  Relais1 = true;
  LED_INIT_SHOW();
}

void loop() {
  input_read();
#ifdef debug
  debug_print();
#endif

  Menu();

  LED_SET();

  Relais3 = Relais2;
  Relais_Output();
}

void debug_print() {

  Serial.print("+");
}

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
#include "value.h"
#include <FastLED.h>
CRGB leds[NUM_LEDS];
#include "Output.h"
#include "encode.h"
#include "menu.h"
#include "input.h"



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
  pinMode (Printer_Bed_pin, INPUT);

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

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Init");
  Relais1 = true;
  LED_INIT_SHOW();
}
//________________________________________________________________________ Main
void loop() {

  input_read();
  taster();
  logik();            //  ----------  NEXT

#ifdef debug
  debug_print();
#endif
  encoder_calc();
  Menu();
  Menu_Inhalt();
  LCD_OUTPUT();

  LED_SET();

  Relais3 = Relais2;
  Relais_Output();

#ifdef debug
  debug_print();
#endif
} //__________________________________________________________end loop()

void logik(){
  
}

void debug_print() {

  Serial.print("+");
}

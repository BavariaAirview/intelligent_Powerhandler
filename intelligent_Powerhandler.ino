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
  //pinMode (Relais8_pin, OUTPUT);
  pinMode (Buzzer_pin, OUTPUT);

  attachInterrupt(encoder0PinA, doEncoderA, CHANGE);
  attachInterrupt(encoder0PinB, doEncoderB, CHANGE);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Init");
  Relais1 = true;
  LED_INIT_SHOW();
  lcd.setCursor(0, 0);
  lcd.print("System is ON");
  LED_Status();
  LED_SET();
  delay(1000);
#ifdef debug
  Serial.begin(115200);
#endif
}
//________________________________________________________________________ Main
void loop() {

  input_read();
  taster();
  backlight_control();
  Menu();
  Menu_Inhalt();
  LCD_OUTPUT();
  temp_control();
  LED_Status();
  LED_SET();

  allesAndere = (licht || PC || tools);
  if (drucker && !licht &&  !PC && !tools) {
    soll_temp = 12;
    printer_ready();
  }

  Relais_Output();

#ifdef debug
  debug_print();
#endif
} //__________________________________________________________end loop()


void debug_print() {

  Serial.println("");
  Serial.print("Relais    :");
  Serial.print(Relais1);
  Serial.print("\t");
  Serial.print(Relais2);
  Serial.print("\t");
  Serial.print(Relais3);
  Serial.print("\t");
  Serial.print(Relais4);
  Serial.print("\t");
  Serial.print(Relais5);
  Serial.print("\t");
  Serial.print(Relais6);
  Serial.print("\t");
  Serial.print(Relais7);
  Serial.print("\t");
  Serial.print(Relais8);
  Serial.println("");

  Serial.print("Taster");
  Serial.print(Taster1);
  Serial.print("\t");
  Serial.print(Taster2);
  Serial.print("\t");
  Serial.print(Taster3);
  Serial.print("\t");
  Serial.print(Taster4);
  Serial.print("\t");
  Serial.print(Taster_enco);
  Serial.println("");

  Serial.print("Menüeinstieg  :");
  Serial.print(Menuauswahl);
  Serial.println("");

}

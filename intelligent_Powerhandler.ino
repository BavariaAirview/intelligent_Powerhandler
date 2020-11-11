#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <WiFi.h>
#include <SPIFFS.h>
#include <ESPAsyncWebServer.h>
#include <WebSocketsServer.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
#include "Constants"
#include "Variables.h"
#include <FastLED.h>
CRGB leds[NUM_LEDS];
#include "Output.h"
#include "encode.h"
#include "menu.h"
#include "input.h"
#include "debug.h"
#include "Webserver.h"



void setup() {
  FastLED.addLeds<CHIPSET, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
  FastLED.setBrightness( BRIGHTNESS );
  lcd.init();
  lcd.backlight();
  pinMode (encoder0PinA, INPUT);
  pinMode (encoder0PinB, INPUT);
  pinMode (Taster_enco_pin, INPUT);
  pinMode (Taster1_pin, INPUT);
  pinMode (Taster2_pin, INPUT);
  pinMode (Taster3_pin, INPUT);
  pinMode (Taster4_pin, INPUT);
  pinMode (NTC_pin, INPUT);
  pinMode (Printer_Bed_pin, INPUT);

  pinMode (Relais1_pin, OUTPUT);
  pinMode (Relais2_pin, OUTPUT);
  //  pinMode (Relais3_pin, OUTPUT);
  pinMode (Relais4_pin, OUTPUT);
  pinMode (Relais5_pin, OUTPUT);
  pinMode (Relais6_pin, OUTPUT);
  pinMode (Relais7_pin, OUTPUT);
  pinMode (Relais8_pin, OUTPUT);
  pinMode (Buzzer_pin, OUTPUT);

  attachInterrupt(0, doEncoderA, CHANGE);
  //  attachInterrupt(1, doEncoderB, CHANGE);

  remind_timer_alt = remind_timer;

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
  lcd.clear();

  ledcSetup(channel, freq, resolution);
  ledcAttachPin(Buzzer_pin, channel);
}


//________________________________________________________________________ Main
void loop() {
#ifdef debug
  cycletime = millis();
#endif
  Minuten = millis() / 1000 / 60;
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

  if (drucker && !allesAndere) {
    soll_temp = 12;
    printer_ready();
  } else {
    printdelay = 0;
    printwait = false;
    if (Printer_done) {
      printprogress == false;
    }
  }

  AllOff = (!licht && !PC && !tools && !drucker);

  if ( AllOff ) {

    SystemON = false;

  } else if ( reminder ) {
    if (!timer_set) {
      remind_counter = Minuten + remind_timer;
      remind_timer_alt = remind_timer;
      timer_set = true;
    }
    remind_timer = remind_counter - Minuten;
    if (remind_timer < 5) {
      diplaytimer = millis() + 10000;
    }
    if (remind_timer < 5 && beepdelay < millis()) {
      beepdelay = millis() + (30 * 1000);
      ledcWriteTone(channel, freq);
      delay(Beeptime);
      ledcWriteTone(channel, 0);
    }
    if (remind_timer <= 0) {
      licht = false;
      reminder = false;
    }
  } else {
    timer_set = false;
  }

  if (SystemON == false) {
    drucker = false;
    licht = false;
    tools = false;
    PC = false;
    Heizung = false;
    Heizung_relais = false;
    Menuauswahl = false;
    DisplayON = true;
    reminder = false;
  }
  Relais_Output();

#ifdef debug
  debug_print();
#endif
} //__________________________________________________________end loop()

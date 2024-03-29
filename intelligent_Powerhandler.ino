#include <LiquidCrystal_I2C.h>
#include <Arduino.h>
#include <Wire.h>
#include <WiFi.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
#include "Constants.h"
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
  pinMode (Relais3_pin, OUTPUT);
  pinMode (Relais4_pin, OUTPUT);
  pinMode (Relais5_pin, OUTPUT);
  pinMode (Relais6_pin, OUTPUT);
  pinMode (Relais7_pin, OUTPUT);
  pinMode (Relais8_pin, OUTPUT);
  pinMode (Buzzer_pin, OUTPUT);

  attachInterrupt(0, doEncoderA, CHANGE);
  //  attachInterrupt(1, doEncoderB, CHANGE);

  remind_timer_alt = remind_timer;
#ifdef debug
  Serial.begin(115200);
#endif

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Init");
  
  Relais1 = true;
  LED_INIT_SHOW();
  Relais_Output();

  lcd.setCursor(0, 0);
  lcd.print("System is ON");
  LED_Status();
  LED_SET();
  delay(1000);

  lcd.clear();

  ledcSetup(channel, freq, resolution);
  ledcAttachPin(Buzzer_pin, channel);
}


//________________________________________________________________________ Main
void loop() {
  lcd.init();
  lcd.backlight();

  while(boot_init){
      lcd.setCursor(1, 0);
      lcd.print("Press for power on");
      Taster_enco = digitalRead(Taster_enco_pin); 
   if (Taster_enco) {
      boot_init = false;
      lcd.clear();
      Taster_enco = false;
      delay(500);
      break;
   }
   if(millis() > Bootwait){
     aus=true;
     lcd.noBacklight();
     digitalWrite(Relais1_pin, LOW);
     digitalWrite(Relais2_pin, LOW);
     digitalWrite(Relais3_pin, LOW);
     digitalWrite(Relais4_pin, LOW);
     digitalWrite(Relais5_pin, LOW);
     digitalWrite(Relais6_pin, LOW);
     digitalWrite(Relais7_pin, LOW);
     digitalWrite(Relais8_pin, LOW);
     leds[0] = CRGB(0, 0, 0);
     leds[1] = CRGB(0, 0, 0);
     leds[2] = CRGB(0, 0, 0);
     leds[3] = CRGB(0, 0, 0);
     leds[4] = CRGB(0, 0, 0);
     FastLED.show();
    }
    delay(100);
  }
  

  if (status != WL_CONNECTED && millis() < wificonnecttime + routerbootdelay && missconnectcounter < 100 && millis() > routerbootdelay) {
    Wificonnect();
  }
  if (status == WL_CONNECTED && !serverisset) {
    serverisset = true;
    myip = WiFi.localIP();
  }


#ifdef debug
  if (missconnectcounter >= 100) Serial.println("Wifi Unable");
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
  Webserver();

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

void Wificonnect() {
  WiFi.begin(ssid, pass);

  serverisset = false;
}

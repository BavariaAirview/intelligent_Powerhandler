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
  //attachInterrupt(1, doEncoderB, CHANGE);

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
}
//________________________________________________________________________ Main
void loop() {
#ifdef debug
  cycletime = millis();
#endif
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

  AllOff = (!licht && !PC && !tools && !drucker && !Heizung);

  if ( AllOff ) {
    if (!timer_set) {
      reminder = false;
      timer_set = true;
      remind_counter = (millis() / 1000 / 60) + 1;
    }

    if (remind_counter < ((millis() / 1000 / 60) + 1) && timer_set) {
      SystemON = false;
    }
  } else if ( reminder ) {
    if (!timer_set) {
      remind_counter = (millis() / 1000 / 60) + remind_timer;
      remind_timer_alt = remind_timer;
      timer_set = true;
    }
    remind_timer = remind_counter - (millis() / 1000 / 60);
    if (remind_timer < 5) {
      diplaytimer = millis() + 10000;
    }
    if (remind_timer < 5 && beepdelay < millis()) {
      beepdelay = millis() + (30 * 1000);
      tone(Buzzer_pin, freq + 2000, remindbeep);
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
    DisplayON = false;
    SystemON = false;
    reminder = false;
  }
  Relais_Output();

#ifdef debug
  debug_print();
#endif
} //__________________________________________________________end loop()

#ifdef debug
void debug_print() {
  Serial.println("");

  Serial.print("\t");
  Serial.print("Netzteil");
  Serial.print("\t");
  Serial.print("Heizung");
  Serial.print("\t");
  Serial.print("\t");
  Serial.print("not used");
  Serial.print("\t");
  Serial.print("3DDruck");
  Serial.print("\t");
  Serial.print("\t");
  Serial.print("Licht");
  Serial.print("\t");
  Serial.print("Tools");
  Serial.print("\t");
  Serial.print("PC");
  Serial.print("\t");
  Serial.print("Netzwerk");
  Serial.println("");

  Serial.print("\t");
  Serial.print(Relais1);
  Serial.print("\t");
  Serial.print("\t");
  Serial.print(Relais2);
  Serial.print("\t");
  Serial.print("\t");
  Serial.print(Relais3);
  Serial.print("\t");
  Serial.print("\t");
  Serial.print(Relais4);
  Serial.print("\t");
  Serial.print("\t");
  Serial.print(Relais5);
  Serial.print("\t");
  Serial.print(Relais6);
  Serial.print("\t");
  Serial.print(Relais7);
  Serial.print("\t");
  Serial.print(Relais8);
  Serial.println("");

  Serial.println("");

  Serial.print("Courser  :");
  Serial.print(courser_pos);
  Serial.println("");

  Serial.print("nMainMenu  :");
  Serial.print(nMainMenu);
  Serial.println("");

  Serial.print("nValue2  :");
  Serial.print(nValue2);
  Serial.println("");

  Serial.print("Menüeinstieg  :");
  Serial.print(Menuauswahl);
  Serial.println("");

  Serial.print("Temp eingang  :");
  Serial.print("\t");
  Serial.print(temp, 1);
  Serial.println("");

  if (printprogress && Printer_done) {
    Serial.print("Drucker shutdown :");
    Serial.print(printdelay - (millis() / 1000 / 60));
    Serial.println("");
  }

  if (reminder || AllOff) {
    Serial.print("Remindtimer :");
    Serial.print(remind_timer);
    Serial.print("\t");
    Serial.print(remind_timer_alt);
    Serial.println("");
  }
  Serial.print(millis() - cycletime);

  Serial.println("");
}
#endif

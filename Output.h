
// ##############  Bluepill   HW zuweisung  falsch
#define DATA_PIN PB1
#define Relais1_pin PB12
#define Relais2_pin PB13
#define Relais3_pin PB14
#define Relais4_pin PB15
#define Relais5_pin PA8
#define Relais6_pin PA9
#define Relais7_pin PA10
#define Relais8_pin PA15

#define NTC_pin PA0
#define 3D_Printer_pin PA7
#define Taster1_pin PA6
#define Taster2_pin PA5
#define Taster3_pin PA4
#define Taster4_pin PA3
#define Taster_enco_pin PB10
#define encoder0PinA PA2
#define encoder0PinB PA1

void LED_INIT_SHOW() {
  leds[0] = CRGB(255, 255, 255);
  leds[1] = CRGB(255, 255, 255);
  leds[2] = CRGB(255, 255, 255);
  leds[3] = CRGB(255, 255, 255);
  FastLED.show();
  delay(800);
}

void LED_SET() {
  leds[0] = CRGB(LED1_r, LED1_g, LED1_b);
  leds[1] = CRGB(LED2_r, LED2_g, LED2_b);
  leds[2] = CRGB(LED3_r, LED3_g, LED3_b);
  leds[3] = CRGB(LED4_r, LED4_g, LED4_b);
  FastLED.show();
}

void Relais_Output(){
  if (Relais1 == true){
    Relais1_pin = HIGH;
  } else {
    Relais1_pin = LOW;
  }
    if (Relais2 == true){
    Relais2_pin = HIGH;
  } else {
    Relais2_pin = LOW;
  }
    if (Relais3 == true){
    Relais3_pin = HIGH;
  } else {
    Relais3_pin = LOW;
  }
    if (Relais4 == true){
    Relais4_pin = HIGH;
  } else {
    Relais4_pin = LOW;
  }
    if (Relais5 == true){
    Relais5_pin = HIGH;
  } else {
    Relais5_pin = LOW;
  }
    if (Relais6 == true){
    Relais6_pin = HIGH;
  } else {
    Relais6_pin = LOW;
  }
    if (Relais7 == true){
    Relais7_pin = HIGH;
  } else {
    Relais7_pin = LOW;
  }
    if (Relais8 == true){
    Relais8_pin = HIGH;
  } else {
    Relais8_pin = LOW;
  }
}

void input_read() {

  NTC = analogRead(NTC_pin) * 100 / 4095;
  NTC_lowpass[i] = NTC;
  i++;
  if (i > NUM_FILTER) i = 1;
  NTC = 0;
  for (int j; j >= NUM_FILTER; j++) {
    NTC = NTC + NTC_lowpass[j];
  }
  NTC = NTC / NUM_FILTER;
  temp = (NTC / 100 * temp_scaler) + temp_offset ;
  
  Taster1 = digitalRead(Taster1_pin);
  Taster2 = digitalRead(Taster2_pin);
  Taster3 = digitalRead(Taster3_pin);
  Taster4 = digitalRead(Taster4_pin);
  Taster_enco = digitalRead(Taster_enco_pin);


  3D_done = digitalRead(3D_Printer_pin);
}


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

void Relais_Output() {
  if (Relais1 == true) {
    digitalWrite(Relais1_pin, HIGH);
  } else {
    digitalWrite(Relais1_pin, LOW);
  }
  if (Relais2 == true) {
    digitalWrite(Relais2_pin, HIGH);
  } else {
    digitalWrite(Relais2_pin, LOW);
  }
  if (Relais3 == true) {
    digitalWrite(Relais3_pin, HIGH);
  } else {
    digitalWrite(Relais3_pin, LOW);
  }
  if (Relais4 == true) {
    digitalWrite(Relais4_pin, HIGH);
  } else {
    digitalWrite(Relais4_pin, LOW);
  }
  if (Relais5 == true) {
    digitalWrite(Relais5_pin, HIGH);
  } else {
    digitalWrite(Relais5_pin, LOW);
  }
  if (Relais6 == true) {
    digitalWrite(Relais6_pin, HIGH);
  } else {
    digitalWrite(Relais6_pin, LOW);
  }
  if (Relais7 == true) {
    digitalWrite(Relais7_pin, HIGH);
  } else {
    digitalWrite(Relais7_pin, LOW);
  }
  if (Relais8 == true) {
    digitalWrite(Relais8_pin, HIGH);
  } else {
    digitalWrite(Relais8_pin, LOW);
  }
}

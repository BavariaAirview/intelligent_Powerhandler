void LED_Status() {
  if (DisplayON) {
    if (drucker) {
      LED1[0] = 0;
      LED1[1] = LED_MAX;
      LED1[2] = 0;
    } else {
      LED1[0] = LED_MAX;
      LED1[1] = 0;
      LED1[2] = 0;
    }
    if (licht) {
      LED2[0] = 0;
      LED2[1] = LED_MAX;
      LED2[2] = 0;
    } else {
      LED2[0] = LED_MAX;
      LED2[1] = 0;
      LED2[2] = 0;
    }
    if (tools) {
      LED3[0] = 0;
      LED3[1] = LED_MAX;
      LED3[2] = 0;
    } else {
      LED3[0] = LED_MAX;
      LED3[1] = 0;
      LED3[2] = 0;
    }
    if (PC) {
      LED4[0] = 0;
      LED4[1] = LED_MAX;
      LED4[2] = 0;
    } else {
      LED4[0] = LED_MAX;
      LED4[1] = 0;
      LED4[2] = 0;
    }
  }
  else
  {
    LED1[0] = 0;
    LED1[1] = 0;
    LED1[2] = LED_LOW;

    LED2[0] = 0;
    LED2[1] = 0;
    LED2[2] = LED_LOW;

    LED3[0] = 0;
    LED3[1] = 0;
    LED3[2] = LED_LOW;

    LED4[0] = 0;
    LED4[1] = 0;
    LED4[2] = LED_LOW;

  }

}


void LED_INIT_SHOW() {
  leds[0] = CRGB(255, 255, 255);
  leds[1] = CRGB(255, 255, 255);
  leds[2] = CRGB(255, 255, 255);
  leds[3] = CRGB(255, 255, 255);
  FastLED.show();
  delay(800);
}

void LED_SET() {
  leds[0] = CRGB(LED1[0], LED1[1], LED1[2]);
  leds[1] = CRGB(LED2[0], LED2[1], LED2[2]);
  leds[2] = CRGB(LED3[0], LED3[1], LED3[2]);
  leds[3] = CRGB(LED4[0], LED4[1], LED4[2]);
  FastLED.show();
}

void Relais_Output() {
  
  if (SystemON) {
    Relais1 = true;
  } else {
    Relais1 = false;
  }
  if (Heizung) {
    Relais2 = true;
  } else {
    Relais2 = false;
  }
  Relais3 = Relais2;
  if (drucker) {
    Relais4 = true;
  } else {
    Relais4 = false;
  }
  if (licht) {
    Relais5 = true;
  } else {
    Relais5 = false;
  }
  if (tools) {
    Relais6 = true;
  } else {
    Relais6 = false;
  }
  if (PC) {
    Relais7 = true;
  } else {
    Relais7 = false;
  }
  if (drucker || PC ) {
    Relais8 = true;
  } else {
    Relais8 = false;
  }

  if (Relais1) {
    digitalWrite(Relais1_pin, HIGH);
  } else {
    digitalWrite(Relais1_pin, LOW);
  }
  if (Relais2) {
    digitalWrite(Relais2_pin, HIGH);
  } else {
    digitalWrite(Relais2_pin, LOW);
  }
  if (Relais3) {
    digitalWrite(Relais3_pin, HIGH);
  } else {
    digitalWrite(Relais3_pin, LOW);
  }
  if (Relais4) {
    digitalWrite(Relais4_pin, HIGH);
  } else {
    digitalWrite(Relais4_pin, LOW);
  }
  if (Relais5 == true) {
    digitalWrite(Relais5_pin, HIGH);
  } else {
    digitalWrite(Relais5_pin, LOW);
  }
  if (Relais6) {
    digitalWrite(Relais6_pin, HIGH);
  } else {
    digitalWrite(Relais6_pin, LOW);
  }
  if (Relais7) {
    digitalWrite(Relais7_pin, HIGH);
  } else {
    digitalWrite(Relais7_pin, LOW);
  }
  if (Relais8) {
    digitalWrite(Relais8_pin, HIGH);
  } else {
    digitalWrite(Relais8_pin, LOW);
  }
}

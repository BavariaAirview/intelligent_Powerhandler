void LED_Status() {
  if (DisplayON == true) {
    if (drucker == true) {
      LED1[0] = 0;
      LED1[1] = LED_MAX;
      LED1[2] = 0;
    } else {
      LED1[0] = LED_MAX;
      LED1[1] = 0;
      LED1[2] = 0;
    }
    if (licht == true) {
      LED2[0] = 0;
      LED2[1] = LED_MAX;
      LED2[2] = 0;
    } else {
      LED2[0] = LED_MAX;
      LED2[1] = 0;
      LED2[2] = 0;
    }
    if (tools == true) {
      LED3[0] = 0;
      LED3[1] = LED_MAX;
      LED3[2] = 0;
    } else {
      LED3[0] = LED_MAX;
      LED3[1] = 0;
      LED3[2] = 0;
    }
    if (PC == true) {
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
  
  if (SystemON == true) {
    Relais1 == true;
  } else {
    Relais1 == false;
  }
  if (Heizung == true) {
    Relais2 == true;
  } else {
    Relais2 == false;
  }
  Relais3 = Relais2;
  if (drucker == true) {
    Relais4 == true;
  } else {
    Relais4 == false;
  }
  if (licht == true) {
    Relais5 == true;
  } else {
    Relais5 == false;
  }
  if (tools == true) {
    Relais6 == true;
  } else {
    Relais6 == false;
  }
  if (PC == true) {
    Relais7 == true;
  } else {
    Relais7 == false;
  }
  if (drucker == true || PC == true) {
    Relais8 == true;
  } else {
    Relais8 == false;
  }

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

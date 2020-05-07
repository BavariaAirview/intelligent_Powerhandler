void Menu() {
  if ( Taster_enco && !Taster_enco_alt && DisplayON && waittime < millis() ) {
    Taster_enco_alt = true;
    waittime = millis() + tasterdelay;
    tone(Buzzer_pin, freq, tasterdelay);
    Menuauswahl = !Menuauswahl;
    if (courser_pos == 2 && Menuauswahl == true) {
      set_boolValue = true;
    }
  }
  if (!Taster_enco)  Taster_enco_alt = false;

  if (!DisplayON) {
    Menuauswahl = false;
  }

  if ((nMainMenu == 0 || nMainMenu == 4 || nMainMenu == 6) && courser_pos >= 4 ) courser_pos = 1;
  if ((nMainMenu == 1 || nMainMenu == 3 || nMainMenu == 2 || nMainMenu == 5) && courser_pos >= 3 ) courser_pos = 1;
  if ((nMainMenu == 0 || nMainMenu == 4 || nMainMenu == 6) && courser_pos <= 0 ) courser_pos = 3;
  if ((nMainMenu == 1 || nMainMenu == 3 || nMainMenu == 2 || nMainMenu == 5) && courser_pos <= 0 ) courser_pos = 2;

  if (nMainMenu < 0) nMainMenu = 6;
  if (nMainMenu >= 7) nMainMenu = 0;

  if (nValue1 < 0) nValue1 = 1;
  if (nValue1 >= 2) nValue1 = 0;

  if (Menuauswahl && courser_pos == 1) {
    if (nMainMenu == 0) {
      boolValue = drucker;
      nValue2 = 2;
    }
    else if (nMainMenu == 1) {
      boolValue = licht;
      nValue2 = 0;
    }
    else if (nMainMenu == 2) {
      boolValue = tools;
      nValue2 = 0;
    }
    else if (nMainMenu == 3) {
      boolValue = PC;
      nValue2 = 0;
    }
    else if (nMainMenu == 4) {
      boolValue = Heizung;
      nValue2 = 1;
    }
    else if (nMainMenu == 5) {
      boolValue = SystemON;
      nValue2 = 0;
    }
    else if (nMainMenu == 6) {
      boolValue = reminder;
      nValue2 = 2;
    }
  }

  if (boolValue) {
    nValue1 = 1;
  } else {
    nValue1 = 0;
  }

  if (set_boolValue == true && courser_pos == 2 && Menuauswahl == false && Taster_enco_alt == true ) {
    if (nMainMenu == 0) {
      drucker = boolValue;
    }
    else if (nMainMenu == 1) {
      licht = boolValue;
    }
    else if (nMainMenu == 2) {
      tools = boolValue;
    }
    else if (nMainMenu == 3) {
      PC = boolValue;
    }
    else if (nMainMenu == 4) {
      Heizung = boolValue;
    }
    else if (nMainMenu == 5) {
      SystemON = boolValue;
    }
    else if (nMainMenu == 6) {
      reminder = boolValue;
    }
    set_boolValue = false;
  }

}

void Menu_Inhalt() {

  if (nMainMenu == 0) M_Menu = "3Dprint";
  if (nMainMenu == 1) M_Menu = "Licht  ";
  if (nMainMenu == 2) M_Menu = "Tools  ";
  if (nMainMenu == 3) M_Menu = "PC     ";
  if (nMainMenu == 4) M_Menu = "Heater ";
  if (nMainMenu == 5) M_Menu = "System ";
  if (nMainMenu == 6) M_Menu = "Remind ";

  if (nValue1 == 0) v1_Menu = "OFF";
  if (nValue1 == 1) v1_Menu = "ON ";

  if (nValue2 == 1) v2_Menu = "temp  ";
  if (nValue2 == 2) v2_Menu = "delay ";

  if (nValue2 == 0) {
    numValue2 = 0;
  }
  else if (nValue2 == 1) {
    numValue2 = soll_temp;
  }
  else if (nValue2 == 2) {
    if (nMainMenu == 0) {
      numValue2 = delay_printer;
    }
    else if (nMainMenu == 6) {
      numValue2 = remind_timer;
    }
  }
}

void backlight_control() {
  if (Taster_enco || Taster1 || Taster2 || Taster3 || Taster4 ) {
    diplaytimer = millis() + 15000;
  }
  if (diplaytimer > millis()) {
    DisplayON = true;
    lcd.backlight(); // turn on backlight.
  } else {
    DisplayON = false;
    lcd.noBacklight(); // turn off backlight
  }
}

void LCD_OUTPUT() {
  //lcd.clear();
  lcd.setCursor(1, 0);
  lcd.print(M_Menu);
  lcd.setCursor(10, 0);
  lcd.print(temp, 1);
  lcd.setCursor(15, 0);
  lcd.print((char)223);

  lcd.setCursor(1, 1);
  lcd.print(v1_Menu);

  if (nValue2 != 0) {
    lcd.setCursor(6, 1);
    lcd.print(v2_Menu);
    lcd.setCursor(12, 1);
    lcd.print(numValue2, 1);
  } else {
    lcd.setCursor(6, 1);
    lcd.print("            ");
  }

  if (courser_pos == 1) {
    lcd.setCursor(0, 0);
    if (Menuauswahl == false) {
      lcd.print(">");
    } else {
      lcd.print("*");
    }
  } else {
    lcd.setCursor(0, 0);
    lcd.print(" ");
  }
  if (courser_pos == 2) {
    lcd.setCursor(0, 1);
    if (Menuauswahl == false) {
      lcd.print(">");
    } else {
      lcd.print("*");
    }
  } else {
    lcd.setCursor(0, 1);
    lcd.print(" ");
  }
  if (courser_pos == 3) {
    lcd.setCursor(5, 1);
    if (Menuauswahl == false) {
      lcd.print(">");
    } else {
      lcd.print("*");
    }
  } else {
    lcd.setCursor(5, 1);
    lcd.print(" ");
  }
}

void Menu() {
  if ( Taster_enco == true && Taster_enco_alt == false && DisplayON == true ) {
    Taster_enco_alt = true;
    Menuauswahl = !Menuauswahl;
    if (courser_pos == 2 && Menuauswahl == true) {
      set_boolValue == true;
    }
  }
  if (Taster_enco == false)  Taster_enco_alt = false;

  if (DisplayON == false) {
    Menuauswahl = false;
  }

  if ((nMainMenu == 0 || nMainMenu == 3 || nMainMenu == 4) && courser_pos >= 4 )courser_pos = 1;
  if ((nMainMenu == 1 || nMainMenu == 2 || nMainMenu == 5) && courser_pos >= 3 )courser_pos = 1;

  if (nMainMenu < 0) nMainMenu = 5;
  if (nMainMenu >= 6) nMainMenu = 0;

  if (Menuauswahl == false) {
    if (nMainMenu == 0) {
      boolValue = drucker;
    }
    else if (nMainMenu == 1) {
      boolValue = licht;
    }
    else if (nMainMenu == 2) {
      boolValue = tools;
    }
    else if (nMainMenu == 3) {
      boolValue = PC;
    }
    else if (nMainMenu == 4) {
      boolValue = Heizung;
    }
    else if (nMainMenu == 5) {
      boolValue == SystemON;
    }
  }

  if (boolValue == true) {
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
    set_boolValue = false;
  }

}

void Menu_Inhalt() {
  MainMenu = M_Menu[nMainMenu];
  Value1 = v1_Menu[nValue1];
  Value2 = v1_Menu[nValue2];
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
    else if (nMainMenu == 3) {
      numValue2 = delay_PC;
    }
    else if (nMainMenu == 4) {
      numValue2 = millis() / 1000 / 60;
    }
  }
}

void backlight_control() {
  if (Taster_enco == true || Taster1 == true || Taster2 == true || Taster3 == true || Taster4 == true) {
    diplaytimer = millis() + 10000;
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
  lcd.clear();
  lcd.setCursor(1, 0);
  lcd.print(MainMenu);
  lcd.setCursor(8, 0);
  lcd.print("ist");
  lcd.setCursor(11, 0);
  lcd.print(temp);
  lcd.setCursor(15, 0);
  lcd.print("°");

  lcd.setCursor(1, 1);
  lcd.print(Value1);

  if (nValue2 != 0) {
    lcd.setCursor(6, 1);
    lcd.print(Value2);
    lcd.setCursor(11, 1);
    lcd.print(numValue2);
  }

  if (courser_pos = 1) {
    lcd.setCursor(0, 0);
    lcd.print("*");
  } else if (courser_pos = 2) {
    lcd.setCursor(0, 1);
    lcd.print("*");
  } else if (courser_pos = 3) {
    lcd.setCursor(5, 1);
    lcd.print("*");
  }
}

void Menu() {
  if (Taster_enco == true && Taster_enco_alt == false) {
    Taster_enco_alt = true;
    courser_pos++;
  }
  if (Taster_enco == false)  Taster_enco_alt = false;

  if ((nMainMenu == 0 || nMainMenu == 3 || nMainMenu == 4) && courser_pos >= 4 )courser_pos = 1;
  if ((nMainMenu == 1 || nMainMenu == 2 || nMainMenu == 5) && courser_pos >= 3 )courser_pos = 1;

  if (nMainMenu < 0) nMainMenu = 5;
  if (nMainMenu >= 6) nMainMenu = 0;
  if (nValue1 < 0) nValue1 = 1;
  if (nValue1 >= 2) nValue1 = 0;
}

void Menu_Inhalt() {
  MainMenu = M_Menu[nMainMenu];
  Value1 = v1_Menu[nValue1];
  Value2 = v1_Menu[nValue2];
  if (nValue2 == 0) {
    numValue2 = 0;
  } else if (nValue2 == 1) {
    numValue2 = soll_temp;
  } else if (nValue2 == 2) {
    if (nMainMenu == 0) {
      numValue2 = delay_printer;
    }
    else if (nMainMenu == 3) {
      numValue2 = delay_PC;
    }
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

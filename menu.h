void Menu() {

  if (courser_pos != courser_pos_alt || nOption != nOption_alt || nMainMenu != nMainMenu_alt) {
    Menu_Inhalt();
    LCD_OUTPUT();
  }
}

void Menu_Inhalt() {
  MainMenu = M_Menu[nMainMenu];
  Option = O_Menu[nOption];
  if (numValue1 == true) {
    nValue1 = ueberhame1;
  } else {
    Value1 = v1_Menu[nValue1];
  }
  if (numValue2 == true) {
    nValue2 = ueberhame2;
  } else {
    Value2 = v1_Menu[nValue2];
  }
}

void LCD_OUTPUT() {
  lcd.clear()
  lcd.setCursor(1, 0);
  lcd.print(MainMenu);
  lcd.setCursor(11, 0);
  lcd.print(temp);
  lcd.setCursor(15, 0);
  lcd.print("°");
  lcd.setCursor(1, 1);
  lcd.print(Option);

  if (Value1 != "" && numValue1 == false ) {
    lcd.setCursor(8, 1);
    lcd.print(Value1);
  } else if (numValue1 == true) {
    lcd.setCursor(8, 1);
    lcd.print(nValue1);
  }

  if (Value2 != "" && numValue1 == false ) {
    lcd.setCursor(13, 1);
    lcd.print(Value2);
  } else if (numValue2 == true) {
    lcd.setCursor(13, 1);
    lcd.print(nValue2);
  }

  if (courser_pos = 1) {
    lcd.setCursor(0, 0);
    lcd.print("*");
  } else if (courser_pos = 2) {
    lcd.setCursor(0, 1);
    lcd.print("*");
  } else if (courser_pos = 3) {
    lcd.setCursor(7, 1);
    lcd.print("*");
  } else if (courser_pos = 4) {
    lcd.setCursor(12, 1);
    lcd.print("*");
  }

}

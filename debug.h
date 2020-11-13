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

  Serial.print("My IP address: ");
  Serial.println(myip);

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

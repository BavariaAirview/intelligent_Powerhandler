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
  Printer_done = digitalRead(Printer_Bed_pin);
  alleTaster = ( Taster1 || Taster2 || Taster3 || Taster4 || Taster_enco);

  if (Printer_done == false && printprogress == false) printprogress == true;
}

void temp_control() {
  if (temp < soll_temp - 0.5 && ( NTC_lowpass[NUM_FILTER - 1] != 0 ) ) {
    Heizung = true;
  }
  if (temp > soll_temp + 0.5) {
    Heizung = false;
  }
}

void printer_ready() {
  if (printprogress == true && Printer_done == true && printdelay == 0) {
    printdelay = millis() + (delay_printer * 60 * 60 * 1000);
  }
  if (printdelay < millis && allesAndere == false) SystemON = false;
  if (allesAndere == true) printdelay = 0;
}

void taster() {
  if (Taster1 == true && Taster1_alt == false && waittime < millis()) {
    drucker = !drucker;
    Taster1_alt = true;
    waittime = millis() + 500;
  }
  if (Taster1 == false) Taster1_alt = false;

  if (Taster2 == true && Taster2_alt == false && waittime < millis()) {
    licht = !licht;
    Taster2_alt = true;
    waittime = millis() + 500;
  }
  if (Taster2 == false) Taster2_alt = false;

  if (Taster3 == true && Taster3_alt == false && waittime < millis()) {
    tools = !tools;
    Taster3_alt = true;
    waittime = millis() + 500;
  }
  if (Taster3 == false) Taster3_alt = false;

  if (Taster4 == true && Taster4_alt == false && waittime < millis()) {
    PC = !PC;
    Taster4_alt = true;
    waittime = millis() + 500;
  }
  if (Taster4 == false) Taster4_alt = false;
}

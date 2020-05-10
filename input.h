void input_read() {

  NTC = analogRead(NTC_pin);
  NTC_OHM = 3300*(((double)NTC/1024)/(1-((double)NTC/1024)));
  TKelvin = 1/((1/((double)273.15+25))+((double)1/3950)*log((double)NTC_OHM/2500));
  temp = TKelvin - 273.15;

  Taster1ana = analogRead(Taster1_pin);
  Taster2 = digitalRead(Taster2_pin);
  Taster3 = digitalRead(Taster3_pin);
  Taster4 = digitalRead(Taster4_pin);
  Taster_enco = digitalRead(Taster_enco_pin);
  Printer_done_ana = analogRead(Printer_Bed_pin);
  alleTaster = ( Taster1 || Taster2 || Taster3 || Taster4 || Taster_enco);

  if (Taster1ana >= 100) {
    Taster1 = true;
  }
  else {
    Taster1 = false;
  }
  if (Printer_done_ana >= 100) {
    Printer_done = true;
  }
  else {
    Printer_done = false;
  }

  if (Printer_done == false && printprogress == false) {
    printprogress = true;
  }
}

void temp_control() {
  if (Heizung && temp < soll_temp - 0.5) {
    Heizung_relais = true;
  }
  if (temp > soll_temp + 0.5 || Heizung == false) {
    Heizung_relais = false;
  }
}

void printer_ready() {
  if (printprogress == true && Printer_done == true && printwait == false) {
    printdelay = (millis()/1000/60) + delay_printer;
    printwait = true;
  }
  if (printdelay >= (millis()/1000/60) && allesAndere == false &&  printwait == true) {
    SystemON = false;
  }  
  if (allesAndere == true) {
    printdelay = 0;
    printwait = false;
  }
  if (allesAndere && Printer_done){
    printprogress == false;
  }
}

void taster() {
  if (Taster1 == true && Taster1_alt == false && waittime < millis()) {
    drucker = !drucker;
    Taster1_alt = true;
    tone(Buzzer_pin, freq, tasterdelay);
    waittime = millis() + tasterdelay;
  }
  if (!Taster1) Taster1_alt = false;

  if (Taster2 == true && Taster2_alt == false && waittime < millis()) {
    licht = !licht;
    Taster2_alt = true;
    tone(Buzzer_pin, freq, tasterdelay);
    waittime = millis() + tasterdelay;
  }
  if (!Taster2) Taster2_alt = false;

  if (Taster3 == true && Taster3_alt == false && waittime < millis()) {
    tools = !tools;
    Taster3_alt = true;
    tone(Buzzer_pin, freq, tasterdelay);
    waittime = millis() + tasterdelay;
  }
  if (!Taster3) Taster3_alt = false;

  if (Taster4 == true && Taster4_alt == false && waittime < millis()) {
    PC = !PC;
    Taster4_alt = true;
    tone(Buzzer_pin, freq, tasterdelay);
    waittime = millis() + tasterdelay;
  }
  if (!Taster4) Taster4_alt = false;
}

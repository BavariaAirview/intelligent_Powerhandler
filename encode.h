void doEncoderA() {
  // look for a low-to-high on channel A
  if (digitalRead(encoder0PinA) == HIGH) {

    // check channel B to see which way encoder is turning
    if (digitalRead(encoder0PinB) == LOW) {
      if (Menuauswahl == false) {
        courser_pos++;
      }
      else {
        if (courser_pos == 1) {
          nMainMenu++;
        } else if (courser_pos == 2) {
          boolValue = !boolValue;
        } else if (courser_pos == 3) {
          if (nValue2 == 1) {
            soll_temp = soll_temp + 0.5;
          }
          if (nValue2 == 2) {
            if (nMainMenu == 0) {
              delay_printer++;
            }
            else if (nMainMenu == 6) {
              remind_timer++;
              timer_set = false;
            }
          }
        }
      }
    }
    else {
      if (Menuauswahl == false) {
        courser_pos--;
      }
      else {
        if (courser_pos == 1) {
          nMainMenu--;
        } else if (courser_pos == 2) {
          boolValue = !boolValue;
        } else if (courser_pos == 3) {
          if (nValue2 == 1) {
            soll_temp = soll_temp - 0.5;
          }
          if (nValue2 == 2) {
            if (nMainMenu == 0) {
              delay_printer--;
              if (delay_printer <= 1) delay_printer = 1;
            }
            else if (nMainMenu == 6) {
              remind_timer--;
              if (remind_timer <= 1) remind_timer = 1;
              timer_set = false;
            }
          }
        }
      }
    }
  }
  else   // must be a high-to-low edge on channel A
  {
    // check channel B to see which way encoder is turning
    if (digitalRead(encoder0PinB) == HIGH) {
      if (Menuauswahl == false) {
        courser_pos++;
      }
      else {
        if (courser_pos == 1) {
          nMainMenu++;
        } else if (courser_pos == 2) {
          boolValue = !boolValue;
        } else if (courser_pos == 3) {
          if (nValue2 == 1) {
            soll_temp = soll_temp + 0.5;
          }
          if (nValue2 == 2) {
            if (nMainMenu == 0) {
              delay_printer++;
            }
            else if (nMainMenu == 6) {
              remind_timer++;
              timer_set = false;
            }
          }
        }
      }
    }
    else
    {
      if (Menuauswahl == false) {
        courser_pos--;
      }
      else {
        if (courser_pos == 1) {
          nMainMenu--;
        } else if (courser_pos == 2) {
          boolValue = !boolValue;
        } else if (courser_pos == 3) {
          if (nValue2 == 1) {
            soll_temp = soll_temp - 0.5;
          }
          if (nValue2 == 2) {
            if (nMainMenu == 0) {
              delay_printer--;
              if (delay_printer <= 1) delay_printer = 1;
            }
            else if (nMainMenu == 6) {
              remind_timer--;
              if (remind_timer <= 1) remind_timer = 1;
              timer_set = false;
            }
          }
        }
      }
    }
  }
  diplaytimer = millis() + 10000;
  ledcWriteTone(channel, freq);
  delay(Beeptime);
  ledcWriteTone(channel, 0);
}

/*
  void doEncoderB() {
  // look for a low-to-high on channel B
  if (digitalRead(encoder0PinB) == HIGH) {

    // check channel A to see which way encoder is turning
    if (digitalRead(encoder0PinA) == HIGH) {
      if (Menuauswahl == false) {
        courser_pos++;
      }
      else {
        if (courser_pos == 1) {
          nMainMenu++;
        } else if (courser_pos == 2) {
          boolValue = !boolValue;
        } else if (courser_pos == 3) {
          if (nValue2 == 1) {
            soll_temp = soll_temp + 0.5;
          }
          if (nValue2 == 2) {
            if (nMainMenu == 0) {
              delay_printer++;
            }
            else if (nMainMenu == 6) {
              remind_timer++;
              timer_set = false;
            }
          }
        }
      }
    }
    else
    {
      if (Menuauswahl == false) {
        courser_pos--;
      }
      else {
        if (courser_pos == 1) {
          nMainMenu--;
        } else if (courser_pos == 2) {
          boolValue = !boolValue;
        } else if (courser_pos == 3) {
          if (nValue2 == 1) {
            soll_temp = soll_temp - 0.5;
          }
          if (nValue2 == 2) {
            if (nMainMenu == 0) {
              delay_printer--;
              if (delay_printer <= 1) delay_printer = 1;
            }
            else if (nMainMenu == 6) {
              remind_timer--;
              if (remind_timer <= 1) remind_timer = 1;
              timer_set = false;
            }
          }
        }
      }
    }
  }

  // Look for a high-to-low on channel B

  else
  {
    // check channel B to see which way encoder is turning
    if (digitalRead(encoder0PinA) == LOW) {
      if (Menuauswahl == false) {
        courser_pos++;
      }
      else {
        if (courser_pos == 1) {
          nMainMenu++;
        } else if (courser_pos == 2) {
          nValue1++;
        } else if (courser_pos == 3) {
          if (nValue2 == 0) {
            soll_temp = soll_temp + 0.5;
          }
          if (nValue2 == 1) {
            if (nMainMenu == 0) {
              delay_printer++;
            }
            else if (nMainMenu == 6) {
              remind_timer++;
              timer_set = false;
            }
          }
        }
      }
    }
    else
    {
      if (Menuauswahl == false) {
        courser_pos--;
      }
      else {
        if (courser_pos == 1) {
          nMainMenu--;
        } else if (courser_pos == 2) {
          nValue1--;
        } else if (courser_pos == 3) {
          if (nValue2 == 0) {
            soll_temp = soll_temp - 0.5;
          }
          if (nValue2 == 1) {
            if (nMainMenu == 0) {
              delay_printer--;
              if (delay_printer <= 1) delay_printer = 1;
            }
            else if (nMainMenu == 6) {
              remind_timer--;
              if (remind_timer <= 1) remind_timer = 1;
              timer_set = false;
            }
          }
        }
      }
    }
  }
  diplaytimer = millis() + 10000;
      ledcWriteTone(channel, freq);
      delay(Beeptime);
      ledcWriteTone(channel, 0);
  }
*/

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
          if (nValue2 = 0) {
            soll_temp = soll_temp + 0.5;
          }
          if (nValue2 = 1) {
            delay_printer++;
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
          if (nValue2 = 0) {
            soll_temp = soll_temp - 0.5;
          }
          if (nValue2 = 1) {
            delay_printer--;
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
          if (nValue2 = 0) {
            soll_temp = soll_temp + 0.5;
          }
          if (nValue2 = 1) {
            delay_printer++;
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
          if (nValue2 = 0) {
            soll_temp = soll_temp - 0.5;
          }
          if (nValue2 = 1) {
            delay_printer--;
          }
        }
      }
    }
  }
  diplaytimer = millis() + 10000;
}

void doEncoderB() {
  // look for a low-to-high on channel B
  if (digitalRead(encoder0PinB) == HIGH) {

    // check channel A to see which way encoder is turning
    if (digitalRead(encoder0PinA) == HIGH) {
      if (courser_pos == 1) {
        nMainMenu++;
      } else if (courser_pos == 2) {
        boolValue = !boolValue;
      } else if (courser_pos == 3) {
        if (nValue2 = 0) {
          soll_temp = soll_temp + 0.5;
        }
        if (nValue2 = 1) {
          delay_printer++;
        }
      }
    }
    else
    {
      if (courser_pos == 1) {
        nMainMenu--;
      } else if (courser_pos == 2) {
        boolValue = !boolValue;
      } else if (courser_pos == 3) {
        if (nValue2 = 0) {
          soll_temp = soll_temp - 0.5;
        }
        if (nValue2 = 1) {
          delay_printer--;
        }
      }
    }
  }

  // Look for a high-to-low on channel B

  else
  {
    // check channel B to see which way encoder is turning
    if (digitalRead(encoder0PinA) == LOW) {
      if (courser_pos == 1) {
        nMainMenu++;
      } else if (courser_pos == 2) {
        nValue1++;
      } else if (courser_pos == 3) {
        if (nValue2 = 0) {
          soll_temp = soll_temp + 0.5;
        }
        if (nValue2 = 1) {
          delay_printer++;
        }
      }
    }
    else
    {
      if (courser_pos == 1) {
        nMainMenu--;
      } else if (courser_pos == 2) {
        nValue1--;
      } else if (courser_pos == 3) {
        if (nValue2 = 0) {
          soll_temp = soll_temp - 0.5;
        }
        if (nValue2 = 1) {
          delay_printer--;
        }
      }
    }
  }
  diplaytimer = millis() + 10000;
}

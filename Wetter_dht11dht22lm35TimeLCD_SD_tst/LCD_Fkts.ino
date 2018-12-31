
void LCDdigitalClockDisplay(){
  int cursorPos = 0;
  lcd.setCursor(cursorPos, 0);             // Cursor to column 0, line 0; 
  lcd.print("                    ");       // Zeile löschen
  lcd.setCursor(cursorPos, 0);             // Cursor to column 0, line 0; 
  LCDprintDigits(hour(), false, cursorPos);
  cursorPos = cursorPos + 2;
  LCDprintDigits(minute(), true, cursorPos);
  cursorPos = cursorPos + 3;
  LCDprintDigits(second(), true, cursorPos);
  cursorPos = cursorPos + 3;
  lcd.setCursor(cursorPos, 0);             // Cursor to column cursorPos, line 0 
  LCDprintDigits(day(), false, cursorPos);
//  lcd.print(day());
  cursorPos = cursorPos + 2;
  lcd.setCursor(cursorPos, 0);             // Cursor to column cursorPos, line 0 
  LCDprintDigits(month(), false, cursorPos);
//  lcd.print(month());
  cursorPos = cursorPos + 2;
  lcd.setCursor(cursorPos, 0);             // Cursor to column cursorPos, line 0 
  LCDprintDigits(year(), false, cursorPos);
//  lcd.print(year()); 
}

void LCDprintDigits(int digits, int dPunkt, int cursorPos){
  // utility function for digital clock display: prints preceding colon and leading 0
  if (dPunkt)
  {
    lcd.setCursor(cursorPos, 0);             // Cursor to column 0, line 0; 
    lcd.print(":");
    cursorPos++;
  }
  if(digits < 10)
  {
    lcd.setCursor(cursorPos, 0);             // Cursor to column 0, line 0; 
    lcd.print('0');
    cursorPos++;
  }  
  lcd.setCursor(cursorPos, 0);             // Cursor to column 0, line 0; 
  lcd.print(digits);
}


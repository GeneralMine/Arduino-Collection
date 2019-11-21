void Ausgabe()
{
  lcd.setCursor(0,0);
  lcd.print(text1);
  lcd.print(result);
  
  sec = millis()/1000.0;
  
  lcd.setCursor(0,1);
  lcd.print(sec);
  lcd.print(text2);
}

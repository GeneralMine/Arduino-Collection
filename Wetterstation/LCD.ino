void LCD_Ausgabe(float temperature, float humidity)
{
  lcd.setCursor(0,0);
  lcd.print(tempString1);
  lcd.print(temperature);
  lcd.print(tempString2);
  /*
  lcd.setCursor(0,1);
  lcd.print(humidString1);
  lcd.print(humidity);
  lcd.print(humidString2);
  */
}

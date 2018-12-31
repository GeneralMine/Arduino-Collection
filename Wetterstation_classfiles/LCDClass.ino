class LCD 
{
  public:
  
  LCD()
  {
    //LiquidCrystal lcd (LCD_RS, LCD_Enable, LCD_D4, LCD_D5, LCD_D6, LCD_D7);
    lcd.begin(20,3);
  }
  
  void InnTemperatur(float innTemp)
  {
    lcd.setCursor(0,0);
    lcd.print(innTemp);
  }
  
  void AusTemperatur(float ausTemp)
  {
    lcd.setCursor(0,0);
    lcd.print(ausTemp);
  }
  
  void InnFeuchtigkeit(float innHumid)
  {
    lcd.setCursor(0,0);
    lcd.print(innHumid);
  }
  
  void AusFeuchtigkeit(float ausHumid)
  {
    lcd.setCursor(0,0);
    lcd.print(ausHumid);
  }
  
  void Ausgabe(int col, int row, String text)
  {
    lcd.setCursor(col, row);
    lcd.print(text);
  }
    
};

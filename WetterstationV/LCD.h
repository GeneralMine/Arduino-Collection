class LCD : public LiquidCrystal
{
  public:
  
  LCD(int LCD_RS, int LCD_Enable, int LCD_D4, int LCD_D5, int LCD_D6, int LCD_D7) : LiquidCrystal(LCD_RS, LCD_Enable, LCD_D4, LCD_D5, LCD_D6, LCD_D7)
  {
    begin(20,3);
  }
  
  float InnTemperatur(float innTemp)
  {
    setCursor(0,0);
    print(innTemp);
    return(innTemp);
  }
  
  float AusTemperatur(float ausTemp)
  {
    setCursor(0,0);
    print(ausTemp);
    return(ausTemp);
  }
  
  float InnFeuchtigkeit(float innHumid)  
  {
    setCursor(0,0);
    print(innHumid);
    return(innHumid);
  }
  
  float AusFeuchtigkeit(float ausHumid)
  {
    setCursor(0,0);
    print(ausHumid);
    return(ausHumid);
  }
  
  void Ausgabe(int col, int row, String text)
  {
    setCursor(col, row);
    print(text);
  }
    
};

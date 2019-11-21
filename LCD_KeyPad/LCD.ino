class LCD:public LiquidCrystal
{
  LCD(int LCD_RS, int LCD_Enable, int LCD_D4, int LCD_D5, int LCD_D6, int LCD_D7):LiquidCrystal(LCD_RS, LCD_Enable, LCD_D4, LCD_D5, LCD_D6, LCD_D7)
  {
      setCursor(0,0);
      print("Tastatur: ");
      setCursor(1,0);
      print("Poti: ")
  }
  
  
  public:
  
  void TastWert(int Taste)
  {
    setCursor(0,  
  }
  
  
  
  
  
  
  
};

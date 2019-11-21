class LCD: public LiquidCrystal
{
  
  public:
  
  
    LCD(int LCD_RS, int LCD_Enable, int LCD_D4, int LCD_D5, int LCD_D6, int LCD_D7): LiquidCrystal(LCD_RS, LCD_Enable, LCD_D4, LCD_D5, LCD_D6, LCD_D7)
    {
      setCursor(0, 0);
      //print("Tastatur");
    }



 

    void setTastatur(int Ziffer)
    {
      setCursor(0,0);
      print("Tastatur ");
      write(Ziffer);
    }












};

// Fkt. blinkt rote LED und zeigt 99 == Fehler an
void blinken()
{
  digitalWrite(ledPinRot, HIGH);    // Rot  EIN
  digitalWrite(ledPinGelb, LOW);    // Gelb AUS
  digitalWrite(ledPinGruen, LOW);   // Grün AUS
  for (byte i=0; i<40; i++)         // Blink Schleife 
  {
    digitalWrite(ledPinRot, (i%2 == 0)?HIGH:LOW); // "20 x ein" und "20 x aus"
    for (byte j=0; j<10; j++) // Wert 1o mal anzeigen, als delay Fkt
      anzeige(99);
  }  // for
}  // fct

// Auf Anfangswerte zurücksetzen
void reset()
{
  phase = 0, startPunkt = 0, endZeit = 0, startZeit = 0, reakZeit = 0;
  anzeigeWert = 0;
  taster = false, gestoppt = false;
  digitalWrite(ledPinRot, LOW);
  digitalWrite(ledPinGelb, LOW);
  digitalWrite(ledPinGruen, LOW);
}  // fct  


    

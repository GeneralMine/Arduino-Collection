void test()                              // 7 Segment Testroutine
{
  digitalWrite(einerStelle, HIGH);       // T1 == EIN 
  digitalWrite(zehnerStelle, HIGH);      // T2 == EIN
  for (byte i=0; i<3; i++)               // dreimal Segmenttest und LED Test
  {
    digitalWrite(ledPinRot, HIGH);       // Rot EIN 
    digitalWrite(ledPinGelb, HIGH);      // Gelb EIN
    digitalWrite(ledPinGruen, HIGH);     // Grün EIN
    for (byte j=0; j<7; j++)             // alle Segmente ansteuern (ohne DP) 
      digitalWrite(pinArray[j], HIGH);   // --> EIN 
    delay(800);                          // kurze Pause
    digitalWrite(ledPinRot, LOW);        // Rot AUS
    digitalWrite(ledPinGelb, LOW);       // Gelb AUS
    digitalWrite(ledPinGruen, LOW);      // Grün AUS
    for (byte j=0; j<7; j++)             // alle Segmente ansteuern (ohne DP)
      digitalWrite(pinArray[j], LOW);    // --> AUS
    delay(200);                          // kurze Pause
  }
  digitalWrite(einerStelle, LOW);        // T1 == AUS
  digitalWrite(zehnerStelle, LOW);       // T2 == AUS 
  for (byte k=0; k<100; k++)             // 0 - 99 anzeigen
  {
    for (byte j=0; j<8; j++)             // Wert "8" mal anzeigen, entspricht delay
      anzeige(k);                        // Zähler "k" anzeigen 
  }
}  // fkt test  

void ansteuerung(int a)                  // 7 Segmente einer Zahl "a" ansteuern 
{                                        // Abfragen der Bits für die Segmente für
  for (byte j=7; j>0; j--)               // Zahl "a", außer "0", da dies DP 
    digitalWrite(pinArray[7-j], bitRead(segmente[a], j) == 1?HIGH:LOW);
  delay(5);                  // kurze Pause, sonst zuviele unnötige Wechsel
}    // fkt ansteuerung

void anzeige(byte wert)             // zerlegt eine 2stellige Zahl und zeigt die Ziffern an  
{
  byte einer, zehner;               // Variable für die beiden Ziffern
  zehner = (wert / 10);             // Zehnerstelle berechnen
  einer = wert - (zehner * 10);     // Einerstelle berechnen
  digitalWrite(einerStelle, HIGH);  // Transistor für Einerstelle ein = HIGH (NPN)  
  digitalWrite(zehnerStelle, LOW);  // Transistor für Zehnerstelle aus = LOW (NPN)
  ansteuerung(einer);               // Segmente der Einerstelle ansteuern 
  digitalWrite(einerStelle, LOW);   // Transistor für Einerstelle aus = LOW (NPN) 
  digitalWrite(zehnerStelle, HIGH); // Transistor für Zehnerstelle ein = HIGH (NPN
  ansteuerung(zehner);              // Segmente der Zehnerstelle ansteuern 
}    // fkt anzeige


/*   Steuert zwei LED 7-Segment Anzeigen per Multiplex an und zeigt die
Reaktionszeit an. Mit eindimensionalen Array & Fkt "bitRead"; gemeinsame Kathode */

const byte segmente[11] = {B11111100,    // 0   Type "const" kann nicht geändert werden,
                           B01100000,    // 1   dafür schneller 
                           B11011010,    // 2
                           B11110010,    // 3
                           B01100110,    // 4
                           B10110110,    // 5
                           B10111110,    // 6
                           B11100000,    // 7
                           B11111110,    // 8
                           B11110110,    // 9
                           B00000001};   // Punkt
const byte pinArray[] = {2,3,4,5,6,7,8};       // Array mit Out Pins für 7Segmente, ohne DP
const byte einerStelle = 12,
           zehnerStelle = 13;                  // Transistor Ausgang Pins
const byte ledPinRot = 9, 
           ledPinGelb = 10, ledPinGruen = 11;  // LED  Ausgang Pins
const byte tasterPin  = A1;                    // Analog Eingang 1 fuer Taster 
byte anzeigeWert = 0;                          // byte, da nur Werte von 0 - 99
byte phase = 0;                                // phase 0,1,2,3, usw.
long startPunkt = 0;                           // ms Zaehler daher long 
long startZeit = 0;                            // ms Startzeit daher long 
long endZeit = 0;                              // ms Endzeit daher long 
int reakZeit = 0;
boolean taster = false;                        // speichert Zustand des Tasters
boolean tasterNeu = false;                     // speichert Flanke eines Tastendruckes 
boolean gestoppt = false;                      // Status ob Spiel korrekt gestoppt wurde
                                                                         
void setup()
{
  for (int i=0; i<7; i++)              // Schleife über alle Segmente
    pinMode(pinArray[i], OUTPUT);      // jeder Segmentpin als Ausgang
  pinMode(einerStelle, OUTPUT);        // Ansteuerung T1 als Output
  pinMode(zehnerStelle, OUTPUT);       // Ansteuerung T2 als Output 
  pinMode(ledPinRot, OUTPUT);          // Ansteuerung LED als Output 
  pinMode(ledPinGelb, OUTPUT);         // Ansteuerung LEDals Output 
  pinMode(ledPinGruen, OUTPUT);        // Ansteuerung LED als Output 
  test();                              // steuert alle Segmente & LEDs an
  Serial.begin(9600);                  // serielle Schnittstelle starten
}   // setup

void loop()
{
  // permanente Tastenabfrage
  if (analogRead(tasterPin) > 900)     // Spannung > Schwelle
  {                                    // dann ist Taste gedrückt   
    if (!taster)                       // war taste noch nicht gedrückt
    {
      tasterNeu = true;                // dann ist taste neu gedrückt (Flanke) 
      taster = true;                   // Status Taste setzen       
    }  // if
  }  // if
  else                                 // Spannung < Schwelle
  {                                    // Taste nicht gedrückt 
    taster = false;                    // Status Taste setzen
  }  // else
  // Es muss immer was angezeigt werden, sonst geht 7 Seg. Anzeige aus
  if (gestoppt) {                      // Spiel gestoppt?  
    anzeige(reakZeit);                 // dann Stopzeit (Reaktionszeit) anzeigen 
  }  // if
  else {
    anzeige(0);                        // sonst "0" anzeigen 
  }  // else   
  if ((tasterNeu) && (phase == 0))  // Taste gedrückt und Spiel bereit?
  {                                 // dann Spiel los 
    tasterNeu = false;              // Tastenaktion ausgeführt daher zurücksetzen 
    phase = 1;                      // Phase "1" der Ampel starten (ROT)
    startPunkt = millis();          // Timer auf aktuelle (Start)Zeit setzen 
  }
  if ((phase == 1) && (millis() - startPunkt > 400))  // nach 400ms startet ROT
    digitalWrite(ledPinRot, HIGH);  // ROT an
  if ((phase == 1) && (millis() - startPunkt > 2400)) // nach 2 Sec ROT startet GELB
  {
    digitalWrite(ledPinGelb, HIGH); // GELB an
    phase = 2;                      // start Phase2 == GELB & Fehlererkennung
  }  //if
  if ((phase == 2) && (tasterNeu))  // Wird Taste in Phase 2 (Gelb) gedrückt ?             
  {                                 // dann zu früh --> Fehler      
    tasterNeu = false;              // Tastenaktion ausgeführt daher zurücksetzen 
    blinken();                      // "99" anzeigen und blinken 
    reset();                        // neues Spiel 
  }  // if  
  if ((phase == 2) && (millis() - startPunkt > 4400)) // nach 2 Sec 
  {
    digitalWrite(ledPinRot, LOW);        // ROT aus 
    digitalWrite(ledPinGelb, LOW);       // GELB aus
    digitalWrite(ledPinGruen, HIGH);     // GRUEN an
    phase = 3;                           // Start Phase "3"
    startZeit = millis();                // Start der Reaktionszeit
  }  // if
  if ((phase == 3) && (!gestoppt))       // Spiel in Phase Gruen (3) und läuft
  {
    if (tasterNeu)                       // Taste gedrückt?
    {
      endZeit = millis();                // dann Spiel regulaer zu Ende
      tasterNeu = false;                 // Tastenaktion ausgeführt daher zurücksetzen
      gestoppt = true;                   // Spiel regulär gestoppt
      reakZeit = endZeit - startZeit;    // Reaktionszeit berechnen
      Serial.println(reakZeit);          // Stopzeit einmal seriel ausgeben
      if (reakZeit > 999) {
        reakZeit = 99;                   // Reaktionszeit anzeigen
      }  // if
      else {
        reakZeit = reakZeit / 10;        // nur Zehntel und Hundertstel anzeigen
      }  // else
    }   // if
    else {
      anzeige(anzeigeWert++);        // Anzeigewert hochzählen und anzeigen
    }  // else
  }  
  if (anzeigeWert > 98) {            // keine Reaktion 
    blinken();                       // "99" anzeigen und blinken                         
    reset();                         // neues Spiel
  }  // if
  if ((gestoppt)&&(tasterNeu))       // Spiel gestoppt und Taste gedrückt
  {
    tasterNeu = false;               // Tastenaktion ausgeführt daher zurücksetzen
    reset();                         // neues Spiel
  }  // if
}  // loop

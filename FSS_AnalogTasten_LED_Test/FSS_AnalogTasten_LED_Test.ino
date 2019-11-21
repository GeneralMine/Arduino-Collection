/* Test der 4 Tasten an analog Eingängen und LEDs an digitalen Ausgängen
  Jede LED kann per Taster jederzeit ein- und ausgeschaltet werden
  Zustand der Tasten werden SERIAL angezeigt */

#define MAXLED 4                        // Anzahl der LEDs und Taster
#define TST_SCHWELLE 800

#define LED_PIN_ROT 2
#define LED_PIN_GRUEN 3
#define LED_PIN_GELB 4
#define LED_PIN_BLAU 5

#define TST_PIN_ROT A1
#define TST_PIN_GRUEN A2
#define TST_PIN_GELB A3
#define TST_PIN_BLAU A4

int ledPin[] = {LED_PIN_ROT, LED_PIN_BLAU, LED_PIN_GRUEN, LED_PIN_GELB};     // LED-Array mit Pin-Werten
int tasterPin[] = {TST_PIN_ROT, TST_PIN_BLAU, TST_PIN_GRUEN, TST_PIN_GELB};  // Taster-Array mit Pin-Werten
int tasterStatus[] = {LOW, LOW, LOW, LOW};  // Taster-Array mit Status
int tasterStatusOld[] = {LOW, LOW, LOW, LOW};  // Taster-Array mit altem Status
int tasterSumChange;

void setup()
{
  Serial.begin(9600);                   // Serielle Schnittstelle initialisieren (einschalten)
  for(int i = 0; i < MAXLED; i++)
  {
    pinMode(ledPin[i], OUTPUT);         // LED-Pins als OUTPUT programmieren
  } // for
}  // fkt

void loop()
{
  tasterSumChange = LOW;                // Initialwert keine Taste hat sich geändert
  for(int i = 0; i < MAXLED; i++)       // Schleife über Anzahl MAXLED 
  {
    if(analogRead(tasterPin[i]) < TST_SCHWELLE)   // Array tasterPin[i] lesen
    {                                   // Wenn Pin == LOW, dann Taste gedrückt, da Taster auf pull up 
      tasterStatus[i] = HIGH;            // Tastenstatus in einem Array speichern
      digitalWrite(ledPin[i], HIGH);     // Array ledPin[i] LOW, d.h. aus
    }  // if
    else                                // else --> d.h. Pin == LOW, dann Taste gedrückt, da Taster auf pull down
    {
      tasterStatus[i] = LOW;           // Tastenstatus in einem Array speichern 
      digitalWrite(ledPin[i], LOW);    // Array ledPin[i] HIGH, d.h. ein
    }  // else
    if (tasterStatusOld[i] != tasterStatus[i])  // hat sich Tastenstatus geändert?
    {
      tasterStatusOld[i] = tasterStatus[i];     // dann neuen Status wieder als "Alt" merken
      tasterSumChange = HIGH;                   // es hat sich an 1 - x Taster was geändert 
    }  //if  
  }  // for

  if (tasterSumChange)                          // nur wenn sich eine der Tasten ändert, Status aller Tasten ausgeben
  {
    for(int i = 0; i < MAXLED; i++)             // Status aller MAXLED Tasten ausgeben 
    {
      Serial.print("Taste ");                   // Einen Text in einer Zeile zusammenbauen 
      Serial.print(i);                          // Nummer der Taste [i]
      Serial.print(" = Status: ");              // Text Status          
      Serial.print(tasterStatus[i]);            // Status der Taste [i]    
      Serial.print(";    ");                    // Trennzeichen zur nächsten Taste
    }  // for
    Serial.println("");                         // new line für nächste Status Ausgabe    
    tasterSumChange = LOW;                      // Ausgabe erledigt, also Änderungsvariable wieder rücksetzen  
  } // if   
}  // loop

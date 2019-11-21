/* Test der 4 Tasten und LEDs
  Jede LED kann per Taster jederzeit ein- und ausgeschaltet werden
*/

#define MAXLED 4                        // Anzahl der LEDs und Taster
int ledPin[] = {2, 3, 4, 5};            // LED-Array mit Pin-Werten
int tasterPin[] = {6, 7, 8, 9};         // Taster-Array mit Pin-Werten
int tasterStatus[] = {LOW, LOW, LOW, LOW};  // Taster-Array mit Status
int tasterStatusOld[] = {LOW, LOW, LOW, LOW};  // Taster-Array mit altem Status
int tasterSumChange;

void setup()
{
  Serial.begin(9600);                   // Serielle Schnittstelle initialisieren (einschalten)
  for(int i = 0; i < MAXLED; i++)
  {
    pinMode(ledPin[i], OUTPUT);         // LED-Pins als OUTPUT programmieren
    pinMode(tasterPin[i], INPUT);       // Taster-Pins als INPUT programmieren 
    digitalWrite(tasterPin[i], HIGH);   // Pull-Up Widerstände einschalten
  } // for
}  // fkt

void loop()
{
  tasterSumChange = LOW;                // Initialwert keine Taste hat sich geändert
  for(int i = 0; i < MAXLED; i++)       // Schleife über Anzahl MAXLED 
  {
    if(digitalRead(tasterPin[i]))       // Array tasterPin[i] lesen
    {                                   // Wenn Pin == HIGH, dann Taste nicht gedrückt, da Taster auf pull down 
      tasterStatus[i] = LOW;            // Tastenstatus in einem Array speichern
      digitalWrite(ledPin[i], LOW);     // Array ledPin[i] LOW, d.h. aus
    }  // if
    else                                // else --> d.h. Pin == LOW, dann Taste gedrückt, da Taster auf pull down
    {
      tasterStatus[i] = HIGH;           // Tastenstatus in einem Array speichern 
      digitalWrite(ledPin[i], HIGH);    // Array ledPin[i] HIGH, d.h. ein
    }  // else
    if (tasterStatusOld[i] != tasterStatus[i])  // hat sich Tastenstatus geändert?
    {
      tasterStatusOld[i] = tasterStatus[i];     // dann neuen Status wieder als "Alt" merken
      tasterSumChange = HIGH;                   // es hat sich an 1 - x Taster was geändert 
    }  //if  
  }  // for

  if (tasterSumChange)                          // nur wenn sich was an einer der Tasten ändert, Status aller Tasten ausgeben
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

// definition aller Tasten
#define KEY_1 '1'
#define KEY_2 '2'
#define KEY_3 '3'
#define KEY_4 '4'
#define KEY_5 '5'
#define KEY_6 '6'
#define KEY_7 '7'
#define KEY_8 '8'
#define KEY_9 '9'
#define KEY_0 '0'
#define KEY_STAR '*'
#define KEY_HASH '#'
#define KEY_A 'A'
#define KEY_B 'B'
#define KEY_C 'C'
#define KEY_D 'D'

long lastValue;              // Letzte Zeit der millis-Funktion
long debounceTime = 400;     // Tastenwiederholzeit in ms setzen

const byte row[] = {2, 3, 4, 5};       // Array mit Zeilen Pin-Nummern initialisieren
const byte col[] = {6, 7, 8, 9};       // Array mit Spalten Pin-Nummern initialisieren

void setKeyPad()             // Ein- Ausgänge des KeyPad initialisieren
{
  for(int r = 0; r < 4; r++)
    pinMode(row[r], OUTPUT);
  for(int c = 0; c < 4; c++)
    pinMode(col[c], INPUT);
}  // fct

char readKey()        // Funktion zum Ermitteln des gedrückten Tasters auf dem KeyPad
{
  char key = KEY_NOT_PRESSED;    // Standard ist keine Taste ist gedrückt
  for(int r = 0; r < 4; r++)     // Zeilen nacheinander auf HIGH legen
  {
    digitalWrite(row[r], HIGH);  // Zeile auf HIGH
    delay(1);                    // kurz warten
    for(int c = 0; c < 4; c++)   // Spalten nacheinander lesen
    {
      if((digitalRead(col[c]) == HIGH)&&(millis() - lastValue) >= debounceTime)
      {      // wenn eine Taste gedrückt also HIGH und Tastenwiederholzeit abgelaufen
        if((c==3)&&(r==3)) key = KEY_1;    // dann Code der gedrückten Taste
        if((c==2)&&(r==3)) key = KEY_2;    // abhängig von Zeilen- und Spaltennummer
        if((c==1)&&(r==3)) key = KEY_3;    // in Variable setzen
        if((c==0)&&(r==3)) key = KEY_A;
        if((c==3)&&(r==2)) key = KEY_4;
        if((c==2)&&(r==2)) key = KEY_5;
        if((c==1)&&(r==2)) key = KEY_6;
        if((c==0)&&(r==2)) key = KEY_B;
        if((c==3)&&(r==1)) key = KEY_7;
        if((c==2)&&(r==1)) key = KEY_8;
        if((c==1)&&(r==1)) key = KEY_9;
        if((c==0)&&(r==1)) key = KEY_C;
        if((c==3)&&(r==0)) key = KEY_STAR; 
        if((c==2)&&(r==0)) key = KEY_0;
        if((c==1)&&(r==0)) key = KEY_HASH;
        if((c==0)&&(r==0)) key = KEY_D;
        lastValue = millis();      // Intervall zurück setzen
      }  // if
    }  // for
    digitalWrite(row[r], LOW);     // Zurücksetzten der Zeile auf Ursprungspegel LOW
    delay(1);                      // kurz warten
  }  // for
  return key;                      // Tastencode zurückgeben
}  // fct

/*     */

// diese Constanten ändern sich nicht:
const int analogPinX = A2;     // der Pin mit dem das Potentiometer verbunden ist
const int analogPinY = A0;     // der Pin mit dem das Potentiometer verbunden ist
const int analogPinT = A1;     // der Pin mit dem das Potentiometer verbunden ist

unsigned long interval = 700;          // Intervallzeit (2 Sekunden)
unsigned long prev;           // Zeit-Variable

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  int XWert = analogRead(analogPinX);                  // Wert des Potentiometer lesen
  int YWert = analogRead(analogPinY);                  // Wert des Potentiometer lesen
  int TWert = analogRead(analogPinT);                  // Wert des Potentiometer lesen

  if((millis() - prev) > interval)          
  {
    prev = millis();                        // jetzigen Zeitstempel wieder merken (quasi reset)
    Serial.print("X-Wert: =  ");                // Print ohne new line (LN)
    Serial.print(XWert);
    Serial.print("  : ");
    Serial.print("Y-Wert: =  ");                // Print ohne new line (LN)
    Serial.print(YWert);
    Serial.print("  : ");
    Serial.print("T-Wert: =  ");                // Print ohne new line (LN)
    Serial.println(TWert);
  }  // if
}         // loop


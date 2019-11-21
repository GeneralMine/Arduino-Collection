/*
Daten von der USB lesen und wieder an den PC senden
 */
int ledPin = 13;
int empfangenesByte = 0;       // Speichert die empfangenen Daten
int empfZahl = -1;             // default == -1 == keime Ziffer 
 
void setup()
{
    pinMode(ledPin, OUTPUT);  // Fkt. "pinMode" definiert "ledPin" als Ausgang
    Serial.begin(9600);       // öffnet die serielle Schnittstelle
}                             // und legt die Baudrate auf 9600 bps
 
void loop()
{                           // sendet daten nur wenn welche empfangen wurden
  if (Serial.available() > 0)                  // gibt es ein Zeichen
  {   // read the incoming byte:
    empfangenesByte = Serial.read();           // Datenbyte lesen
    Serial.print("Arduino hat empfangen: ");   // Text ausgeben
    Serial.print(empfangenesByte);             // Datenbyte wieder ausgeben 
    Serial.print(" = ");
    Serial.println((char)empfangenesByte);     // nach ASCII wandeln
    // prüfen ob Zeichen eine Zahl ist
    if ((empfangenesByte < 58) && (empfangenesByte > 47))   
      empfZahl = empfangenesByte - '0';  // Zahl ist "ASCII-Wert" - "ASCII-0"
    else  
      empfZahl = -1;                     // "-1" == keime Ziffer
    switch(empfZahl) {                   // mehrfache Kontrollstruktur
      case 1:                            //  einmal blinken  
        for (int i=0; i<empfZahl; i++)
        {
          digitalWrite(ledPin, HIGH);    // schaltet die LED ein
          delay(1500);
          digitalWrite(ledPin, LOW);     // schaltet die LED ein
          delay(200);
        }
        break;                           // Sprung zum SWITCH Ende 
      case 2:                            // 2 mal schneller blinken
        for (int i=0; i<empfZahl; i++)
        {
          digitalWrite(ledPin, HIGH);    // schaltet die LED ein
          delay(1000);
          digitalWrite(ledPin, LOW);     // schaltet die LED ein
          delay(200);
        }
        break;                           // Sprung zum SWITCH Ende
      case 3:                            // 3 mal noch schneller blinken
        for (int i=0; i<empfZahl; i++)
        {
          digitalWrite(ledPin, HIGH);    // schaltet die LED ein
          delay(500);
          digitalWrite(ledPin, LOW);     // schaltet die LED ein
          delay(200);
        }
        break;                           // Sprung zum SWITCH Ende
      default:                           // bei allen anderen Zeichen
         for (int i=0; i<10; i++)
        {                                //  10 mal ganz schnell blinken
          digitalWrite(ledPin, HIGH);    // schaltet die LED ein
          delay(100);
          digitalWrite(ledPin, LOW);     // schaltet die LED ein
          delay(50);
        }  // default
    }      // switch  
  }        // if
  delay(2000);  
}          // loop

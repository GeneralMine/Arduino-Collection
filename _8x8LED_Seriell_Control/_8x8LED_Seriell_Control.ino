/* Matrix Animation sketch
   per PC Monitor kann ein Herzschlag-Bild, ein Demo Lauflicht oder jede einzelne LED von 1-64 angesteuert werden
   Eingabe von:
   H     -->  Herzschlag
   D     -->  Demolauflicht
   1-64  -->  die entsprechende LED einschalten
Alle Zeichen werden empfangen & zur Kontrolle wieder an PC zurück geschickt. Buchstaben & Zahlen werden untersucht */   

byte bigHeart[] = {            // Symbol für großes Herz. "1" bedeutet LED an
  B01100110,
  B11111111,
  B11111111,
  B11111111,
  B01111110,
  B00111100,
  B00011000,
  B00000000};

byte smallHeart[] = {          // Symbol für kleines Herz. "1" bedeutet LED an
  B00000000,
  B00000000,
  B00010100,
  B00111110,
  B00111110,
  B00011100,
  B00001000,
  B00000000};

const int columnPins[] = {2, 3, 4, 5, 6, 7, 8, 9};
const int rowPins[]    = {10,11,12,15,16,17,18,19};
const int onTime = 250;      // Mikro Sekunden pro LED. Mal 64 ergibt Frame Zeit

char chSerial = 0;           // speichert die empfangenen Daten
char chLetter = 0;           // speichert den empfangenen Buchstaben 
int empfZahl = 0;            // 0 - 64, als0 max. 2 Ziffern, default == 0,  
int pulseDelay = 800 ;       // milliseconds to wait between beats
int zahl = -1;               // default == -1 ==> keime Ziffer 

void setup()
{
  for (int i = 0; i < 8; i++)
  {
    pinMode(rowPins[i], OUTPUT);                      // make all the LED pins outputs
    pinMode(columnPins[i], OUTPUT);
  }  // for
  Serial.begin(9600);                                 // öffnet die serielle Schnittstelle
}  // setup

void loop()
{
  if (Serial.available() > 0)                         // gibt es ein Zeichen
  {                                                   // read the incoming byte:
    chSerial = Serial.read();                         // Datenbyte lesen
    Serial.print("Arduino hat empfangen (ASCII: ");   // Text ausgeben
    Serial.print(chSerial);                           // empfangenes Datenbyte wieder ausgeben ASCII 
    Serial.print(" = (DEC): ");
    Serial.println((int)chSerial);                    // nach interger wandeln und ausgeben
    
    if (isDigit(chSerial))                            // prüfen ob Zeichen eine Zahl ist
    {
      empfZahl = (empfZahl*10) + (chSerial - '0');    // Zahl ist "ASCII-Wert" - "ASCII-0"
      zahl = empfZahl;                                // für weitere Anwendung speichern
      chLetter = 0;                                   // Da "zahl" empfangen wurde "chLetter" löschen 
    }
    else
    {
      if ((chSerial < 91) && (chSerial > 64))         // prüfen ob Zeichen eine Buchstabe ist
      {
        chLetter = chSerial;                          // für weitere Anwendung speichern
        empfZahl = 0;                                 // Zifferneingabe zu Ende,  bereit für neue Zahlenumwandlung 
        zahl = -1;                                    // Da "chLetter" empfangen wurde "zahl" löschen
      }    
      else
      {
        if ((chSerial == 10) || (chSerial == 13))    // NL newline oder carriage return CR
        {
          empfZahl = 0;                              // Zifferneingabe zu Ende,  bereit für neue Zahlenumwandlung
        }
      }  
    }  // else  
  }        // if serial available

  if ((zahl >= 0) && (zahl < 65))                    // wenn eine Zahl zwischen 1 und 64
  {
    showPixel(zahl);                                 // diese LED einschalten 
  }
  else
  {
    if (zahl > 64)                                    // wenn Zahl > 64
    {
        empfZahl = 0;                                 // Zifferneingabe zu groß,  bereit für neue Zahlenumwandlung 
        zahl = -1;                                    // und "zahl" löschen
    }      
  }
  if (chLetter == 'H')                                // Wenn Buchstabe 'H' Herzschlag anzeigen
  {
    show(smallHeart, 100);                            // 80 show the small heart image for 100 ms
    show(bigHeart, 200);                              // 160 followed by the big heart for 200ms
    delay(pulseDelay);                                // show nothing between beats
  }  // if
  
  if (chLetter == 'D')                                // wenn Buchstabe 'D' Demo Lauflicht anzeigen
  {
    showDemo();
  }  // if
}  // loop  


// routine to show a frame of an image stored in the array pointed to 
// by the image parameter.
// the frame is repeated for the given duration in milliseconds
void show( byte * image, unsigned long duration)
{
  unsigned long start = millis();            // begin timing the animation
  while (start + duration > millis())        // loop until duration period has passed
  {
    for(int row = 0; row < 8; row++)
    {
      digitalWrite(rowPins[row], HIGH);          // connect row to +5 volts
      for(int column = 0; column < 8; column++)
      {
        boolean pixel = bitRead(image[row],column);
        if(pixel == 1)
        {
          digitalWrite(columnPins[column], LOW);  // connect column to Gnd
        }
        delayMicroseconds(300);                   // a small delay for each LED
        digitalWrite(columnPins[column], HIGH);   // disconnect column from Gnd
      }  // for column
      digitalWrite(rowPins[row], LOW);            // disconnect LEDs
    }    // for row
  }    // while
}    // fct fct. show

void showDemo()
{
  for (int pixel = 0; pixel < 64; pixel++)
  {
    showPixel(pixel);  
  }  // for pixel
  delay(100);  
}  // fct. demo

void showPixel(int pixelNr)
{
  int columnLevel = pixelNr / 8;                     // map to the number of columns
  int rowLevel = pixelNr % 8;                        // get the fractional value
  for (int column = 0; column < 8; column++)
  {
    digitalWrite(columnPins[column], LOW);           // connect this column to Ground
    for(int row = 0; row < 8; row++)
    {
      if (columnLevel > column)
      {
        digitalWrite(rowPins[row], HIGH);            // connect all LEDs in row to +5 volts
      }  // if
      else
      {
        if (columnLevel == column && rowLevel > row)
        {
          digitalWrite(rowPins[row], HIGH);
        }  // if
        else
        {
          digitalWrite(columnPins[column], LOW); // turn off all LEDs in this row
        }  // else
      }  // else  
      delayMicroseconds(onTime);               // gives frame time (64 LEDs mal 300 = 20ms)
      digitalWrite(rowPins[row], LOW);         // turn off LED
    }  // for "row"
    digitalWrite(columnPins[column], HIGH);   // disconnect this column from GND
  }  // for "column"
}  // fct, showPixel
    

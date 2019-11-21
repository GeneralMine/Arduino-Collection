/*  Register setzen mit HC595
    Setzt Register A oder B mit Werten zw 0 und 255
    und nutzt dabei ein Schieberegister HC595
    und zeigt die Werte der Register und die Summe "DEZ" und "BIN" an
*/

int taktPin = 8;        // SH_CP = Schieberegister Takteingang (Shiftregister Clock Input)
int speicherPin = 9;    // ST_CP = Speicherregister Takteingang (Storageregister Clock Input)
int datenPin = 10;      // DS = Serieller Eingang (Serial data Input)
int regA_Clk_Pin = 11;  // Pin taktet Register A
int regB_Clk_Pin = 12;  // Pin taktet Register A
byte regWertA = 0;      // Variable mit Wert für Register A
byte regWertB = 0;      // Variable mit Wert für Register B
byte empfByte = 0;      // Variable für empfangenes BYTE
boolean showSum = false;

void setup()
{
  Serial.begin(9600);               // öffnet die serielle Schnittstelle und legt die Baudrate auf 9600 bps
  pinMode(taktPin,OUTPUT);          // "taktPin" als Ausgang definieren
  pinMode(speicherPin,OUTPUT);      // "speicherPin" als Ausgang definieren
  pinMode(datenPin,OUTPUT);         // "datenPin" als Ausgang definieren 
  pinMode(regA_Clk_Pin,OUTPUT);     // Clock-Pin für Register A
  pinMode(regB_Clk_Pin,OUTPUT);     // Clock-Pin für Register B
  delay(5);                         // kurze Verarbeitungs-Pause
}

void loop()
{
  // if there's any serial available, read it:
  while (Serial.available() > 0)
  {
    empfByte = Serial.read();
    switch(empfByte)
    {                   // mehrfache Kontrollstruktur
      case 'A':                            //  einmal blinken  
        // look for the next valid integer in the incoming serial stream:
        regWertA = Serial.parseInt(); 
        SetRegX('A',regWertA);
        Serial.print("A:  DEZ: ");
        Serial.print(regWertA);
        Serial.print(";  HEX: ");
        Serial.print(regWertA, HEX);
        Serial.print(";  BIN: ");
        Serial.println(regWertA, BIN);
        showSum = true;
        break;                           // Sprung zum SWITCH Ende 
      case 'B':
        // look for the next valid integer in the incoming serial stream:
        regWertB = Serial.parseInt(); 
        SetRegX('B',regWertB);
        Serial.print("B:  DEZ: ");
        Serial.print(regWertB);
        Serial.print(";  HEX: ");
        Serial.print(regWertB, HEX);
        Serial.print(";  BIN: ");
        Serial.println(regWertB, BIN);
        showSum = true;
        break;
      default:                           // bei allen anderen Zeichen
        break;
    }      // switch  
  }  //while
  if (showSum)
  {
    SerOutSum(regWertA, regWertB);
    showSum = false;
  }
}    // loop

void SetRegX(char type, byte wert)  // Fkt setzt Register A oder B "type" mit Zahl "wert"
{
  shiftOut(datenPin, taktPin, MSBFIRST, wert);  // Daten ins Register schreiben
  delay(1);
  digitalWrite(speicherPin, HIGH);  // ST_CP  --> Speicherregisterinhalt an Ausgang
  delay(1);
  digitalWrite(speicherPin, LOW);   // ST_CP  Clock wieder zurück
  delay(1);
  if (type == 'A')                  // Register A
  {
    digitalWrite(regA_Clk_Pin, HIGH);  // RegisterA Clk Pin auf HIGH
    delay(2);
    digitalWrite(regA_Clk_Pin, LOW);   // RegisterA Clk Pin wieder LOW
    delay(1);
  }  // if
  else                              // Register B
  {
    digitalWrite(regB_Clk_Pin, HIGH);  // RegisterB Clk Pin auf HIGH
    delay(2);
    digitalWrite(regB_Clk_Pin, LOW);  // RegisterB Clk Pin wieder LOW
    delay(1);
  }  // else
}    // SetRegX

void SerOutSum(byte a, byte b)
{
  Serial.print("Sum:  DEZ: ");
  Serial.print(a + b);
  Serial.print(";  HEX: ");
  Serial.print(a + b, HEX);
  Serial.print(";  BIN: ");
  Serial.println(a + b, BIN);
}
  

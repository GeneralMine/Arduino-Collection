/*   Zwei Motoren per Befehl über Schnittstelle ansteuern und auch einen Wert für Power senden
V = Vorwärts; Z = Zurück; L = Links; R = Rechts; S = Stop
plus Zahl zwischen 0 un 255  z.B.  V120   */

// Bewegungsrichtungen + Pause
enum Motion        // Liste mit Konstanten
{
  FORWARD = 1,     // nit "1" beginnend
  BACKWARD,
  RIGHT,
  LEFT,
  PAUSE
};

int motor1_Pin1 = 2;          // Motorpins
int motor1_Pin2 = 3; 
int motor2_Pin1 = 4;
int motor2_Pin2 = 5;
int enableM1Pin  = 9;         // Motor1 Enable Pin
int enableM2Pin  = 10;        // Motor2 Enable Pin

byte empfByte = 0;            // Variable für empfangenes BYTE
int moveModus = PAUSE;        // speichert die Richtung bzw. Modus
int oldMoveModus = PAUSE;     // speichert alten Modus 
int power1 = 0;                // aktuelleGeschwindigkeit Motor1 
int oldPower1 = 0;             // alte Geschwindigkeit Motor1 
int power2 = 0;                // aktuelleGeschwindigkeit Motor2
int oldPower2 = 0;             // alte Geschwindigkeit Motor2


void setup()
{
  MotorenSet();         // Ausgänge der Motoren definieren 
  Serial.begin(9600);   // öffnet die serielle Schnittstelle und legt die Baudrate auf 9600 bps
}

void loop()
{
  while (Serial.available() > 0)     // if there's any serial available, read it:
  {
    empfByte = Serial.read();
    switch(empfByte)
    {                   // mehrfache Kontrollstruktur
      case 'V':         // Vorwärts                     
        moveModus = FORWARD;
        break;          // Sprung zum SWITCH Ende 
      case 'Z':         // rückwärts
        moveModus = BACKWARD;
        break;
      case 'L':         // links
        moveModus = LEFT;
        power1 = (power1 + power2) / 2;
        power2 = power1;
        break;
      case 'R':         // rechts
        moveModus = RIGHT;
        power1 = (power1 + power2) / 2;        
        power2 = power1;
        break;
      case 'S':         // Stop                     
        moveModus = PAUSE;
        power1 = 0;
        power2 = 0;
        break;                      
      case 'P':
        power1 = Serial.parseInt();           // Fkt liest einen ZahlenString und liefert Wert zurück
        power1 = constrain(power1, 0, 255);    // begrenzt "power" zwischen 0 und 255 (PWM)
        empfByte = Serial.read();
        if (empfByte == '&')
        {
          power2 = Serial.parseInt();           // Fkt liest einen ZahlenString und liefert Wert zurück
          power2 = constrain(power2, 0, 255);    // begrenzt "power" zwischen 0 und 255 (PWM)
          if ((moveModus == RIGHT) || (moveModus == LEFT))
          {
            power1 = (power1 + power2) / 2;        
            power2 = power1;
          }
        }       
        else
        {
          power1 = 0;
          power2 = 0;
        }
        break;  
      default:          // alle anderen Tasten STOP
        moveModus = PAUSE;
        power1 = 0;
        power2 = 0;
      break;
    }      // switch  
    // look for the next valid integer in the incoming serial stream:
//    power = Serial.parseInt();           // Fkt liest einen ZahlenString und liefert Wert zurück
//    power = constrain(power, 0, 255);    // begrenzt "power" zwischen 0 und 255 (PWM)
    Serial.print("Modus:  ");
    Serial.print(moveModus);
    Serial.print("     Power1:  ");
    Serial.print(power1);
    Serial.print("     Power2:  ");
    Serial.println(power2);
  }  //while
  if ((moveModus != oldMoveModus) || (power1 != oldPower1) || (power2 != oldPower2))
  {   // nur wenn neuer Modus
    MotorenMove(moveModus, power1, power2);   // dann neuer Move Befehl
    oldMoveModus = moveModus;        // neuer Zustand speichern
    oldPower1 = power1;                // damit wird Fkt nur aufgerufen bei Änderung  
    oldPower2 = power2;                // damit wird Fkt nur aufgerufen bei Änderung  
  }   // if
}    // loop

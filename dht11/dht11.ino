/* Programm steuert einen DHT11 Sensor an. Dieser misst Luft-Temperatur und -Feuchte
Dazu wird die Bibliothek dht11.h verwendet. Die Kommunikation mit dem Sensor findet seriell
über nur einen Pin statt  */

#include <dht11.h>                          // Bibliothek einbinden  
  
dht11 DHT;                                  // Object DHT erzeugen
#define DHT11_PIN 2                        // Pin für serielle Kommunikation
 
void setup()
{
  Serial.begin(9600);                       // Seriellen Monitor öffnen 
  Serial.println("DHT TEST PROGRAM ");      
  Serial.print("LIBRARY VERSION: ");
  Serial.println(DHT11LIB_VERSION);
  Serial.println();
  Serial.println("Type,\tstatus,\tHumidity (%),\tTemperature (C)");  // Überschrift ausgeben
}  // fct "setup"
 
void loop()
{
  int chk;                                  // empfängt Zeichen vom Sensor
  Serial.print("DHT11, \t");    
  chk = DHT.read(DHT11_PIN);                // Read Sensor Data
  switch (chk)                              // erstes Zeichen ist Sensor Status
  {
    case DHTLIB_OK:                         // Sensor ist OK  
                Serial.print("OK,\t"); 
                break;
    case DHTLIB_ERROR_CHECKSUM:             // Übertragungsfehler
                Serial.print("Checksum error,\t"); 
                break;
    case DHTLIB_ERROR_TIMEOUT:              // Time Out Error 
                Serial.print("Time out error,\t"); 
                break;
    default:                                // unbekannter Fehler 
                Serial.print("Unknown error,\t"); 
                break;
  }  // switch
  Serial.print(DHT.humidity,1);             // Feuchte lesen mit eine Kommastelle und anzeigen
  Serial.print(",\t\t");                    // TAB ausgeben 
  Serial.println(DHT.temperature,1);        // Temp lesen mit eine Kommastelle und anzeigen
  delay(3000);                              // alle 3 Sekunden anzeigen
}   // fct "loop"

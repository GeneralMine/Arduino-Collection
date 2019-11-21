/*
Author:        Erik Bartmann
 Website:       http://www.erik-bartmann.de
 Blog:          http://www.tumblr.com/tumblelog/arduino-processing
 Twitter:       https://twitter.com/#!/ErikBartmann
 Flickr:        http://www.flickr.com/photos/erikbartmann/6318122805
 Scope:         Die Netzwerkkommunikation
 Version:       1.0
 Date:          03.10.2011
 Last modified:
 Description:   Dieser Sketch zeigt die Netzwerkkommunikation über ein Ethernet-Shield
 Referenz:      http://arduino.cc/en/Reference/Array
                http://www.arduino.cc/en/Reference/Ethernet
                http://www.arduino.cc/en/Reference/SPI
                http://arduino.cc/en/Reference/If
                http://arduino.cc/en/Reference/Delay
                http://arduino.cc/en/Reference/For
 */
#include <SPI.h>
#include <Ethernet.h>

byte MACAddress[] = {0x90, 0xA2, 0xDA, 0x0D, 0xAD, 0xF7}; // MACAdresse vom Ethernet-Label
byte IPAddress[] = {192, 168, 178, 110};                  // IP-Adresse, von Fritz Box ... 119 ist gewählt
int const HTTPPORT = 80;                                  // HTTP-Port 80 (Standardport)
String barColor[] = {"ff0000", "00ff00", "00ffff", "ffff00", "ff00ff", "550055"}; // RGB-Farben für Color-Bars

// #define HTML_TOP "<html>\n<head><title>Arduino Web-Server</title></head>\n<body>"  // ohne refresh seitens Browser
#define HTML_TOP "<html>\n<head><title>Arduino Web-Server</title></head>\n <meta http-equiv=\"refresh\" content=\"1\">\n<body>"
#define HTML_BOTTOM "</body>\n</html>"

EthernetServer myServer(HTTPPORT);             // Web-Server auf angegebenen Port starten

void setup(){
  Ethernet.begin(MACAddress, IPAddress);       // Ethernet initialisieren
  myServer.begin();                            // Server starten
}

void loop(){
  EthernetClient myClient = myServer.available();
  if(myClient){
    myClient.println("HTTP/1.1 200 OK");
    myClient.println("Content-Type: text/html");
    myClient.println();
    myClient.println(HTML_TOP);                 // HTML-Top
    showValues(myClient);                       // HTML-Content
    myClient.println(HTML_BOTTOM);              // HTML-Bottom
  }
  delay(1);                                     // Kurze Pause für Web-Browser
  myClient.stop();                              // Client-Verbindung schließen
}

void showValues(EthernetClient &myClient){
  for(int i = 0; i < 6; i++){
    myClient.print("Analog Pin ");
    myClient.print(i);
    myClient.print(": ");
    myClient.print(analogRead(i));
    myClient.print("<div style=\"height: 15px; background-color: #");
    myClient.print(barColor[i]);
    myClient.print("; width:");
    myClient.print(analogRead(i));
    myClient.println("px; border: 2px solid;\"></div>");
  }
}


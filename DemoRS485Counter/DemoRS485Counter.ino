#include <SPI.h>
#include <Controllino.h>  /* Usage of CONTROLLINO library allows you to use CONTROLLINO_xx aliases in your sketch. */

bool testWithCounter = 1;    //IF 1 -> Sending all the time a counter with short delay         IF 0 -> using example testing
/* EXAMPLE TEST: This function will test RS485 functionality. Possible modes are 0-2. 0 is all enabled, sended message should come back, 1 means RE is low,  so message should not be recieved, 
2 means DE is disabled, so no message should be sent at all.*/
void TestRS485 (int mode)
{
  DDRJ = DDRJ | B01100000;
  PORTJ = PORTJ & B10011111;
  /*pinMode(CONTROLLINO_RS485_TX, OUTPUT);
  pinMode(CONTROLLINO_RS485_RX, INPUT);
  pinMode(CONTROLLINO_RS485_RE, OUTPUT);
  pinMode(CONTROLLINO_RS485_DE, OUTPUT);*/
  switch (mode)
  {
    case 0:
      PORTJ = PORTJ & B10011111;
      PORTJ = PORTJ | B01000000;
      /*digitalWrite (CONTROLLINO_RS485_RE, HIGH);
      digitalWrite (CONTROLLINO_RS485_DE, HIGH);*/
      delay (10);
      Serial.print("Test with counter: " + String(testWithCounter) + " | Mode: " + String(mode) + "  |  ");
      Serial.println ("Sending test message, expected to return;"); 
      Serial3.print("UUUUU Controllino RS485 test Message.UUUUU");
      break;
      
    case 1:
      PORTJ = PORTJ & B10011111;
      PORTJ = PORTJ | B01100000;
      /*digitalWrite (CONTROLLINO_RS485_RE, LOW);
      digitalWrite (CONTROLLINO_RS485_DE, HIGH);*/
      delay (10);
      Serial.print("Test with counter: " + String(testWithCounter) + " | Mode: " + String(mode) + "  |  ");
      Serial.println ("Sending test message, not expected to return;");
      Serial3.print("UUUUU Controllino RS485 test Message.UUUUU");
      break;
      
    case 2:
      PORTJ = PORTJ & B10011111;
      PORTJ = PORTJ | B00100000;
     /* digitalWrite (CONTROLLINO_RS485_RE, HIGH);
      digitalWrite (CONTROLLINO_RS485_DE, LOW);*/
      delay (10);
      Serial.print("Test with counter: " + String(testWithCounter) + " | Mode: " + String(mode) + "  |  ");
      Serial.println ("Sending test message, not expected to be sended;"); 
      Serial3.print("UUUUU Controllino RS485 test Message.UUUUU");
      break;
      
    default:
      Serial.println("Wrong mode!");
      return; 
  }
}

/* This function enters loop and waits for any incoming data on serial 3.*/
void RecieveRS485()
{
  Serial.println("Recieving RS485.");
  while(true)
  {
    if (Serial3.available()) 
    {
      // print the new byte:
      Serial.print((char)Serial3.read()); 
    }
  }
}

void setup() {
  /* Here we initialize USB serial at 9600 baudrate for reporting */
  Serial.begin(9600);
  /* Here we initialize RS485 serial at 9600 baudrate for communication */
  Serial3.begin(9600);
  /* This will initialize Controllino RS485 pins */
  Controllino_RS485Init();

  Serial.println("Der Test startet mit Counter 0-255 und durchläuft 3 hardware ansteuer modi");
  Serial.println("Man kann mit der Eingabe in den Seriellen Monitor zwischen dem Counter Test oder dem Example Test wechseln");
  Serial.println("Zahl eingeben -> Enter -> warten");
  Serial.println("  1   ->   Test mit Counter (Standart)");
  Serial.println("  0   ->   Example Test (3 Text Nachrichten)");
  Serial.println("Die Test Arten wechseln nur nach jedem Zyklus (ist kein Interrupt)");
  Serial.println("Modes: 0 is all enabled,sended message should come back | 1 means RE is low,so message should not be recieved|");
  Serial.println("2 means DE is disabled, so no message should be sent at all \n");
  Serial.println("Wenn ihr einen richtigen der 3 Modi gefunden habt könnt ihr die anderen einfach aus der loop Funktion rausnehmen");
  Serial.println("Der Übergabeparameter der TestRS485 Funktionen gibt den Modus an");
  delay(20000);
}

void loop() {
  /* Use only one of the two functions, either send or recieve */
  // RecieveRS485();

  //Change Test Category
  if(Serial.read() == '1') {
    testWithCounter=1;
  }
  if(Serial.read() == '0') {
    testWithCounter=0;
  }
  
  if(testWithCounter==1)    //Execute Test with Counter        
  {
    Serial.println("Test started with Counter!");
    delay(3000);
    TestRS485Counter(0);
    delay(2000);
    TestRS485Counter(1);
    delay(2000);
    TestRS485Counter(2);
    delay(2000);    
  }
  else              /* Send test. 2 seconds apart sending messages with 3 types of different settings. Check the function comment for more infromation */
  {
    Serial.println("Test started without Counter!");
    delay(3000);
    TestRS485(0);
    delay(2000);
    TestRS485(1);
    delay(2000);
    TestRS485(2);
    delay(2000);
  }

}

/* COUNTER TEST: This function will test RS485 functionality. Possible modes are 0-2. 0 is all enabled, sended message should come back, 1 means RE is low,  so message should not be recieved, 
2 means DE is disabled, so no message should be sent at all.*/
void TestRS485Counter(byte mode) {
  byte counterValue = 0;
  DDRJ = DDRJ | B01100000;
  PORTJ = PORTJ & B10011111;
  /*pinMode(CONTROLLINO_RS485_TX, OUTPUT);
  pinMode(CONTROLLINO_RS485_RX, INPUT);
  pinMode(CONTROLLINO_RS485_RE, OUTPUT);
  pinMode(CONTROLLINO_RS485_DE, OUTPUT);*/
  while (counterValue < 255){  
    switch (mode)
    {
      case 0:
        PORTJ = PORTJ & B10011111;
        PORTJ = PORTJ | B01000000;
        /*digitalWrite (CONTROLLINO_RS485_RE, HIGH);
        digitalWrite (CONTROLLINO_RS485_DE, HIGH);*/
        delay (10);
        Serial.print("Test with counter: " + String(testWithCounter) + " | Mode: " + String(mode) + " | Value: " + counterValue + "  |  ");
        Serial.println ("Sending test message, expected to return;"); 
        Serial3.print("UUUUU " + String(counterValue) + ".UUUUU");
        break;
        
      case 1:
        PORTJ = PORTJ & B10011111;
        PORTJ = PORTJ | B01100000;
        /*digitalWrite (CONTROLLINO_RS485_RE, LOW);
        digitalWrite (CONTROLLINO_RS485_DE, HIGH);*/
        delay (10);
        Serial.print("Test with counter: " + String(testWithCounter) + " | Mode: " + String(mode) + " | Value: " + counterValue + "  |  ");
        Serial.println ("Sending test message, not expected to return;");
        Serial3.print("UUUUU " + String(counterValue) + ".UUUUU");
        break;
        
      case 2:
        PORTJ = PORTJ & B10011111;
        PORTJ = PORTJ | B00100000;
       /* digitalWrite (CONTROLLINO_RS485_RE, HIGH);
        digitalWrite (CONTROLLINO_RS485_DE, LOW);*/
        delay (10);
        Serial.print("Test with counter: " + String(testWithCounter) + " | Mode: " + String(mode) + " | Value: " + counterValue + "  |  ");
        Serial.println ("Sending test message, not expected to be sended;"); 
        Serial3.print("UUUUU " + String(counterValue) + ".UUUUU");
        break;
        
      default:
        Serial.println("Wrong mode!");
        return; 
    }
    counterValue++;
  }
}


/* 2017-01-12: The sketch was successfully tested with Arduino 1.6.13, Controllino Library 1.0.0 and CONTROLLINO MAXI and MEGA. */

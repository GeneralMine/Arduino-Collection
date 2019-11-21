/*
 * SerialFormatting
 * Print values in various formats to the serial port
 */
char textValue[] = "Harald Elmer";
int WarteZeit = 30000;
char chrValue = 65;  // these are the starting values to print
byte byteValue = 65;
int intValue  = 2065;
float floatValue = 65.0;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  Serial.println("chrValue: ");
  Serial.print("Serial.println(chrValue) : ");
  Serial.println(chrValue);
  Serial.print("Serial.println(chrValue, DEC) : ");
  Serial.println(chrValue,DEC);
  Serial.print("Serial.println(chrValue, HEX) : ");
  Serial.println(chrValue,HEX);
  Serial.print("Serial.println(chrValue, OCT) : ");
  Serial.println(chrValue,OCT);
  Serial.print("Serial.println(chrValue, BIN) : ");
  Serial.println(chrValue,BIN);
  Serial.print("Serial.write(chrValue) : ");
  Serial.write(chrValue);
  Serial.println();
  Serial.println();
  
  Serial.println("byteValue: ");
  Serial.print("Serial.println(byteValue) : ");
  Serial.println(byteValue);
  Serial.print("Serial.println(byteValue, DEC) : ");
  Serial.println(byteValue,DEC);
  Serial.print("Serial.println(byteValue, HEX) : ");
  Serial.println(byteValue,HEX);
  Serial.print("Serial.println(byteValue, OCT) : ");
  Serial.println(byteValue,OCT);
  Serial.print("Serial.println(byteValue, BIN) : ");
  Serial.println(byteValue,BIN);
  Serial.print("Serial.write(byteValue) : ");
  Serial.write(byteValue);
  Serial.println();
  Serial.println();
  
  Serial.println("intValue: ");
  Serial.print("Serial.println(intValue) : ");
  Serial.println(intValue);
  Serial.print("Serial.println(intValue, DEC) : ");
  Serial.println(intValue,DEC);
  Serial.print("Serial.println(intValue, HEX) : ");
  Serial.println(intValue,HEX);
  Serial.print("Serial.println(intValue, OCT) : ");
  Serial.println(intValue,OCT);
  Serial.print("Serial.println(intValue, BIN) : ");
  Serial.println(intValue,BIN);
  Serial.print("Serial.write(intValue) : ");
  Serial.write(intValue);
  Serial.println();
  Serial.println();
  
  Serial.println("Werte direkt: ");
  Serial.print("Serial.println(65) : ");
  Serial.println(65);
  Serial.print("Serial.println('A') : ");
  Serial.println('A');
  Serial.print("Serial.write(65) : ");
  Serial.write(65);
  Serial.println();
  Serial.println();
  
  Serial.println("floatValue: ");
  Serial.print("Serial.println(floatValue) : ");
  Serial.println(floatValue);
  Serial.println();

  Serial.println("textValue: ");
  Serial.print("Serial.println(textValue) : ");
  Serial.println(textValue);
  Serial.print("Serial.write(textValue) : ");
  Serial.write(textValue);
  Serial.println();
  Serial.println();


  delay(WarteZeit); // delay a second between numbers
  chrValue++;  // to the next value
  byteValue++;
  intValue++;
  floatValue +=1;
}

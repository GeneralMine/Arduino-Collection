int counter = 1;
int mapped_counter;

String text1 = "Zeile ";
String text2 = ": ";
String text_name = "Adrian Raiser";
String text_birthday = "10.02.1998";

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  mapped_counter = counter%2;
  Print(counter, mapped_counter);
  counter++;
  delay(5000);
}


void Print (int counter1, int mapped_counter2)
{
  Serial.print("Zeile ");
  Serial.print(counter);
  Serial.print(text2);
  if(mapped_counter == 0)
    Serial.println(text_birthday);
  else
    Serial.println(text_name);
}

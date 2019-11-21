

void showZahl(int value)
{
  resetCounter();
  for(int i = 0; i < value; i++)
  {
    digitalWrite(counterClockPin, HIGH);
    delay(1);
    digitalWrite(counterClockPin, LOW);
    delay(1);
  }
}

void resetCounter()
{
  digitalWrite(counterResetPin, HIGH);
  delay(2);
  digitalWrite(counterResetPin, LOW);
  delay(1);
}

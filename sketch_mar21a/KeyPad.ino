#define KEY_1 '1'
#define KEY_2 '2'
#define KEY_3 '3'
#define KEY_4 '4'
#define KEY_5 '5'
#define KEY_6 '6'
#define KEY_7 '7'
#define KEY_8 '8'
#define KEY_9 '9'
#define KEY_0 '0'
#define KEY_STAR '*'
#define KEY_HASH '#'
#define KEY_A 'A'
#define KEY_B 'B'
#define KEY_C 'C'
#define KEY_D 'D'

long lastV;
long debounceTime = 500;

int row[] = {2, 3, 4, 5};
int col[] = {6, 7, 8, 9};

void setKeyPad() {
  for (int r = 0; r < 4; r++)
  {
    pinMode(row[r], OUTPUT);
    //digitalWrite(r,1);
  }
  for (int c = 0; c < 4; c++)
  {
    pinMode(col[c], INPUT);
    digitalWrite(col[c], HIGH);
  }
}

char readKey()
{
  char key = KEY_NOT_PRESSED;
  for (int r = 0; r < 4; r++)
  {
    digitalWrite(row[r], HIGH);
    delay(1);
    for (int c = 0; c < 4; c++)
    {
      if ((digitalRead(col[c]) == LOW) && (millis() - lastV) >= debounceTime)
      {
        if ((c == 3) && (r == 3)) key = KEY_1;
        if ((c == 2) && (r == 3)) key = KEY_2;
        if ((c == 1) && (r == 3)) key = KEY_3;
        if ((c == 0) && (r == 3)) key = KEY_A;
        if ((c == 3) && (r == 2)) key = KEY_4;
        if ((c == 2) && (r == 2)) key = KEY_5;
        if ((c == 1) && (r == 2)) key = KEY_6;
        if ((c == 0) && (r == 2)) key = KEY_B;
        if ((c == 3) && (r == 1)) key = KEY_7;
        if ((c == 2) && (r == 1)) key = KEY_8;
        if ((c == 1) && (r == 1)) key = KEY_9;
        if ((c == 0) && (r == 1)) key = KEY_C;
        if ((c == 3) && (r == 0)) key = KEY_STAR;
        if ((c == 2) && (r == 0)) key = KEY_0;
        if ((c == 1) && (r == 0)) key = KEY_HASH;
        if ((c == 0) && (r == 0)) key = KEY_D;
        lastV = millis();
      }
    }
    digitalWrite(row[r], LOW);
    delay(1);
  }
  return key;
}

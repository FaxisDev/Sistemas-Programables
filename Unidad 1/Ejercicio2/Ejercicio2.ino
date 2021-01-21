
void setup()
{

  for (int i = 1; i < 13; i++)
  {
    pinMode(i, OUTPUT);
  }
}

void loop()
{
  int ap = 0;
  for (int i = 12; i > 0; i--)
  {
    ap = i + 1;
    digitalWrite(ap, LOW);
    digitalWrite(i, HIGH);
    delay(1000);
    if (i == 1)
    {
      digitalWrite(1, LOW);
    }
  }
}

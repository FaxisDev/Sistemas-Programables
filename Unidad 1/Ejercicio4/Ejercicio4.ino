void setup() {

  for (int i = 1; i <= 6; i++) {
    pinMode(i, OUTPUT);
  }

}

void loop() {
  digitalWrite(3, LOW);
  digitalWrite(1, HIGH);
  if (digitalRead(1) == HIGH) {
    digitalWrite(6, HIGH);
    digitalWrite(5, LOW);
    digitalWrite(4, LOW);
  }

  delay(2500);

  cambioVerde1(1);

  digitalWrite(2, HIGH);
  delay(1000);

  digitalWrite(2, LOW);
  digitalWrite(3, HIGH);

  if (digitalRead(3) == HIGH) {
    digitalWrite(6, LOW);
    digitalWrite(5, LOW);
    digitalWrite(4, HIGH);
  }
  delay(2500);

  cambioVerde1(4);

  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
  delay(1000);

}

void cambioVerde1(int i) {
  int c = 1;
  while (c <= 3) {
    digitalWrite(i, HIGH);
    delay(500);
    digitalWrite(i, LOW);
    delay(500);
    c++;
  }


}

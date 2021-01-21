void setup() {
  // Declarando entradas
  int ui = 0;
  for (ui = 11; ui <= 12; ui++) {
    pinMode(ui, INPUT);
  }
  for (ui = 1; ui <= 10; ui++) {
    pinMode(ui, OUTPUT);
  }
}

void loop() {

  int i;
  if (digitalRead(11) == HIGH) {

    for (i = 10; i > 0; i--) {
      digitalWrite(i, LOW);
      delay(200);
      digitalWrite(i, HIGH);
      delay(300);

    }

  } else if (digitalRead(12) == HIGH) {

    for (i = 1; i <= 10; i++) {
      digitalWrite(i, LOW);
      delay(200);
      digitalWrite(i, HIGH);
      delay(300);

    }
  }

  i = 1;
  while (i <= 10) {
    digitalWrite(i, HIGH);
    i++;
  }

}

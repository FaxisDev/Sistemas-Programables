void setup() {
  // Declarando entradas
  int ui = 0;
  for (ui = 11; ui <= 13; ui++) {
    pinMode(ui, INPUT);
  }
  for (ui = 1; ui <= 10; ui++) {
    pinMode(ui, OUTPUT);
  }

  pinMode(0, INPUT);
}

void loop() {

  int i;
  if (digitalRead(11) == HIGH) {

    while (true) {
      for (i = 10; i > 0; i--) {
        digitalWrite(i, LOW);
        delay(200);
        digitalWrite(i, HIGH);
        delay(300);

        if (digitalRead(0) == HIGH) {
          break;
        }

      }
      if (digitalRead(0) == HIGH) {
        break;
      }
    }


  } else if (digitalRead(12) == HIGH) {
    while (true) {
      for (i = 1; i <= 10; i++) {
        digitalWrite(i, LOW);
        delay(200);
        digitalWrite(i, HIGH);
        delay(300);

        if (digitalRead(0) == HIGH) {
          break;
        }

      }

      if (digitalRead(0) == HIGH) {
        break;
      }
    }
  } else if (digitalRead(13) == HIGH) {
    while (true) {
      for (i = 1; i <= 5; i++) {
        digitalWrite(i, LOW);
        delay(200);
        digitalWrite(i, HIGH);
        delay(300);

        if (digitalRead(0) == HIGH) {
          break;
        }

      }

      for (i = 10; i >= 1; i--) {
        digitalWrite(i, LOW);
        delay(200);
        digitalWrite(i, HIGH);
        delay(300);

        if (digitalRead(0) == HIGH) {
          break;
        }

      }

      if (digitalRead(0) == HIGH) {
        break;
      }
    }
  }


  i = 1;
  while (i <= 10) {
    digitalWrite(i, HIGH);
    i++;
  }

}

void setup() {
  // Declarando entradas
  int ui = 0;
  for (ui = 0; ui <= 3; ui++) {
    pinMode(ui, INPUT);
  }
  for (ui = 4; ui <= 7; ui++) {
    pinMode(ui, OUTPUT);
  }
}

void loop() {
  int i = 0;
  if ((digitalRead(0) == HIGH && digitalRead(1) == HIGH) && (digitalRead(2) == HIGH && digitalRead(3) == HIGH)) {
    for (int i = 4; i <= 7; i++) {
      if (i <= 7 && i >= 3) {
        digitalWrite(i - 1, LOW);
        digitalWrite(i, HIGH);
        delay(200);
        if (i == 7) {
          digitalWrite(7, LOW);
        }
      }

    }
  } else if ((digitalRead(0) == LOW && digitalRead(1) == LOW) && (digitalRead(2) == LOW && digitalRead(3) == LOW)) {
    for (int i = 7; i >= 4; i--) {
      if (i <= 7 && i >= 3) {
        digitalWrite(i + 1, LOW);
        digitalWrite(i, HIGH);
        delay(200);
        if (i == 4) {
          digitalWrite(4, LOW);
        }
      }

    }
  } else {
    i = 0;
    while (i <= 3) {
      if (digitalRead(0 + i) == HIGH) {
        digitalWrite(4 + i, HIGH);
        delay(500);
      } else {
        digitalWrite(4 + i, LOW);
        delay(500);
      }
      i++;
    }
  }
}

int autox = 0;

void setup() {
  pinMode(0, INPUT);


  pinMode(1, OUTPUT);

}

void loop() {
  if (digitalRead(0) == HIGH) {
    autox += 1;
    delay(400);
  }
  if (autox > 1 || autox < 0) {
    autox = 0;
  }

  if (autox == 1) {
    digitalWrite(1, HIGH);
  }

  if (autox == 0) {
    digitalWrite(1, LOW);
  }


}

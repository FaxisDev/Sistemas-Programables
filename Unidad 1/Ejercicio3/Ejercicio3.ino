void setup() {

for (int i = 1; i <= 10; i++) {
    pinMode(i, OUTPUT);
  }

}

void loop() {

for (int i = 10; i >= 1; i--) {
    digitalWrite(i, HIGH);
    delay(400);
  }

for (int i = 1; i >= 10; i--) {
    digitalWrite(i, HIGH);
    delay(400);
  }
  
}

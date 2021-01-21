int salida = 9;
void setup() {
  pinMode(salida, OUTPUT);

}

void loop() {
  digitalWrite(salida, HIGH);
  delay(3000);
  digitalWrite(salida, LOW);
  delay(1000);
}

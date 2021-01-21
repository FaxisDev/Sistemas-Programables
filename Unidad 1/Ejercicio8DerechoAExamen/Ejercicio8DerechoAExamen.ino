int inc = 0;

void triangle() {
  digitalWrite(1, LOW);
  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
}

void square() {
  digitalWrite(1, HIGH);
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
  digitalWrite(6, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(8, HIGH);
  digitalWrite(9, HIGH);
}

void diamond() {
  for (int u = 2; u <= 8; u += 2) {
    digitalWrite(u, HIGH);
  }
  for (int u = 1; u <= 9; u += 2) {
    digitalWrite(u, LOW);
  }
}

void setup() {

  pinMode(10, INPUT);


  int i = 1;
  while (i <= 9) {
    pinMode(i, OUTPUT);
    i++;
  }
}
int e = 1;
void loop() {


  if (digitalRead(10) == HIGH) {
    e++;
    
  }

  delay(500);

  
  if (e > 3 || e < 0) {
    e = 0;
  }
  else if (e == 1) {
    triangle();
  } else if (e == 2) {
    square();
  } else if (e == 3) {
    diamond();
  }

}

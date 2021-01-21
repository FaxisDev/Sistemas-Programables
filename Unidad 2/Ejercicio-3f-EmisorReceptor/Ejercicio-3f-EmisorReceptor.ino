void setup()
{

  pinMode(12, INPUT);

  for (int i = 0; i <= 6; i++) {
    pinMode(i, OUTPUT);
  }
}
int vel = 500;
int rep = 0;
void loop() {
  if (digitalRead(12) == HIGH) {
    digitalWrite(13, HIGH);
  } else {
    digitalWrite(13, LOW);
  }


  if (rep < 0 || rep > 15)
  {
    rep = 0;
  }

  proceso();

  if (digitalRead(12) == HIGH)
  {
    rep += 1;

    while (true) {
      delay(vel);
      if (digitalRead(12) != HIGH) {

        break;
      }
    }



  } else if (digitalRead(12) == LOW) {
    while (true) {
      if (digitalRead(12) == HIGH) {
        break;
        delay(vel);
      }
    }
  }

}

void proceso() {


  if (rep == 0)
  {
    display(0, 0, 0, 0, 0, 0, 1);
    //delay(vel);
  }
  else if (rep == 1)
  {
    display(1, 0, 0, 1, 1, 1, 1); // 1
    //delay(vel);
  }
  else if (rep == 2)
  {
    display(0, 0, 1, 0, 0, 1, 0); // 2
    //delay(vel);
  }
  else if (rep == 3)
  {
    display(0, 0, 0, 0, 1, 1, 0); // 3
    //delay(vel);
  }
  else if (rep == 4)
  {
    display(1, 0, 0, 1, 1, 0, 0); // 4
    //delay(vel);
  }
  else if (rep == 5)
  {
    display(0, 1, 0, 0, 1, 0, 0); // 5
    //delay(vel);
  }
  else if (rep == 6)
  {
    display(0, 1, 0, 0, 0, 0, 0); // 6
    //delay(vel);
  }
  else if (rep == 7)
  {
    display(0, 0, 0, 1, 1, 1, 1); // 7
    //delay(vel);
  }
  else if (rep == 8)
  {

    display(0, 0, 0, 0, 0, 0, 0); // 8
    //delay(vel);
  }
  else if (rep == 9)
  {

    display(0, 0, 0, 0, 1, 0, 0); // 9
    //delay(vel);
  }
  else if (rep == 10)
  {
    display(0, 0, 0, 1, 0, 0, 0); // A
    //delay(vel);
  }
  else if (rep == 11)
  {
    display(1, 1, 0, 0, 0, 0, 0); // b
    //delay(vel);
  }
  else if (rep == 12)
  {

    display(0, 1, 1, 0, 0, 0, 1); // c
    //delay(vel);
  }
  else if (rep == 13)
  {
    display(1, 0, 0, 0, 0, 1, 0); // d
    //delay(vel);
  }
  else if (rep == 14)
  {
    display(0, 1, 1, 0, 0, 0, 0); // e
    //delay(vel);
  }
  else if (rep == 15)
  {

    display(0, 1, 1, 1, 0, 0, 0); // f
    //delay(vel);
  }
}

void display(int a, int b, int c, int d, int e, int f, int g)
{
  digitalWrite(0, a);
  digitalWrite(1, b);
  digitalWrite(2, c);
  digitalWrite(3, d);
  digitalWrite(4, e);
  digitalWrite(5, f);
  digitalWrite(6, g);
}

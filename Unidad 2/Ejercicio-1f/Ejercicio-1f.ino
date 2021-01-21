void setup()
{
  DDRD = 255; //Se declara todo el puerto como salida
}

int vel = 500;
void loop()
{
  //Al puerto "D" le asignamos los valores obtenidos haciendo una pausa de 1segundo entre cada numero

  // A  B C D E F G


  display(0, 0, 0, 0, 0, 0, 1);
  delay(vel);


  display(1, 0, 0, 1, 1, 1, 1); // 1
  delay(vel);


  display(0, 0, 1, 0, 0, 1, 0); // 2
  delay(vel);

  display(0, 0, 0, 0, 1, 1, 0); // 3
  delay(vel);


  display(1, 0, 0, 1, 1, 0, 0); // 4
  delay(vel);


  display(0, 1, 0, 0, 1, 0, 0); // 5
  delay(vel);


  display(0, 1, 0, 0, 0, 0, 0); // 6
  delay(vel);


  display(0, 0, 0, 1, 1, 1, 1); // 7
  delay(vel);


  display(0, 0, 0, 0, 0, 0, 0); // 8
  delay(vel);

  display(0, 0, 0, 0, 1, 0, 0); // 9
  delay(vel);


  display(0, 0, 0, 1, 0, 0, 0); // A
  delay(vel);

  display(1, 1, 0, 0, 0, 0, 0); // b
  delay(vel);


  display(0, 1, 1, 0, 0, 0, 1); // c
  delay(vel);

  display(1, 0, 0, 0, 0, 1, 0); // d
  delay(vel);


  display(0, 1, 1, 0, 0, 0, 0); // e
  delay(vel);


  display(0, 1, 1, 1, 0, 0, 0); // f
  delay(vel);
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

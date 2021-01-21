int vel = 500;
int rep = 0;


void setup() {


  //Esto es del display de 7 segmentos && LEDS verde | rojo && tambien leds de carro
  for (int i = 0; i <= 8; i++) {
    pinMode(i, OUTPUT);
  }
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);

  //EMISOR_ RECEPTOR
  for (int i = 11; i <= 12; i++) {
    pinMode(i, INPUT);
  }

}

void disponibilidad() {
  if (rep >= 9) {
    digitalWrite(10, LOW);
    digitalWrite(9, HIGH);
    rep = 9;
  } else if (rep < 9) {
    digitalWrite(10, HIGH);
    digitalWrite(9, LOW);

  }
  if (rep < 0) {
    rep = 0;
  }
}

void cambio_rojo() {
  digitalWrite(0, HIGH);
  digitalWrite(1, LOW);
}

void cambio_verde() {
  digitalWrite(1, HIGH);
  digitalWrite(0, LOW);
}

void loop() {
  //Esta recibiendo el infrarojo
  if (digitalRead(11) == HIGH) { //entrada
    while (true) {
      cambio_verde();
      if (digitalRead(11) == LOW) {
        rep += 1;
        break;
      }
    }
    cambio_rojo();

  }

  if (digitalRead(12) == HIGH) { //salida
    while (true) {
      cambio_verde();
      if (digitalRead(12) == LOW) {
        rep -= 1;
        break;
      }
    }
    cambio_rojo();
    
  }


  //Si esta disponible o no el Estacionamiento.
  disponibilidad();

  //Contador del display : modo catodo comun
  proceso(1, 0);

}

void proceso(int primero, int segundo) {

  if (rep == 0)
  {
    display(primero, primero, primero, primero, primero, primero, segundo);
    //delay(vel);
  }
  else if (rep == 1)
  {
    display(segundo, primero, primero, segundo, segundo, segundo, segundo); // 1
    //delay(vel);
  }
  else if (rep == 2)
  {
    display(primero, primero, segundo, primero, primero, segundo, primero); // 2
    //delay(vel);
  }
  else if (rep == 3)
  {
    display(primero, primero, primero, primero, segundo, segundo, primero); // 3
    //delay(vel);
  }
  else if (rep == 4)
  {
    display(segundo, primero, primero, segundo, segundo, primero, primero); // 4
    //delay(vel);
  }
  else if (rep == 5)
  {
    display(primero, segundo, primero, primero, segundo, primero, primero); // 5
    //delay(vel);
  }
  else if (rep == 6)
  {
    display(primero, segundo, primero, primero, primero, primero, primero); // 6
    //delay(vel);
  }
  else if (rep == 7)
  {
    display(primero, primero, primero, segundo, segundo, segundo, segundo); // 7
    //delay(vel);
  }
  else if (rep == 8)
  {

    display(primero, primero, primero, primero, primero, primero, primero); // 8
    //delay(vel);
  }
  else if (rep == 9)
  {

    display(primero, primero, primero, primero, segundo, primero, primero); // 9
    //delay(vel);
  }
}



void display(int a, int b, int c, int d, int e, int f, int g)
{
  digitalWrite(2, a);
  digitalWrite(3, b);
  digitalWrite(4, c);
  digitalWrite(5, d);
  digitalWrite(6, e);
  digitalWrite(7, f);
  digitalWrite(8, g);
}

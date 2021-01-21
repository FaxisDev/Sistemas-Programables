int vel = 500;
int rep = 0;

int cambio = 0, original = 0;
void setup() {

  Serial.begin(9600);

  //Esto es del display de 7 segmentos && LEDS verde | rojo
  for (int i = 2; i <= 8; i++) {
    pinMode(i, OUTPUT);
  }


}

void loop() {

  original = analogRead(A0);
  if (original != cambio) {
    cambio = original;
    Serial.println(analogRead(A0));
  }

  if(original >= 0 && original <= 96.5){
    rep = 0;
  } else if(original >= 96.6 && original <= 193){
    rep = 1;
  } else if(original >= 193.1 && original <= 289.5){
    rep = 2;
  } else if(original >= 289.6 && original <= 386){
    rep = 3;
  } else if(original >= 386.1 && original <= 482.5){
    rep = 4;
  } else if(original >= 482.6 && original <= 579){
    rep = 5;
  } else if(original >= 579 && original <= 675.5){
    rep = 6;
  } else if(original >= 675.6 && original <= 772){
    rep = 7;
  } else if(original >= 772.1 && original <= 868.5){
    rep = 8;
  } else if(original > 868.5){
    rep = 9;
  }

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

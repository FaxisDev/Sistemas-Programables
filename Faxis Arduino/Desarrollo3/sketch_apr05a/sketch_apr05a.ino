void setup()
{
  DDRD = 255; //Se declara todo el puerto como salida
}
void loop()
{
  //Al puerto "D" le asignamos los valores obtenidos haciendo una pausa de 1segundo entre cada numero
  PORTD = '0110000';       //0
  delay(1000);

}

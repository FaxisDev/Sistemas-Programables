#include <SPI.h> //Aqui incluimos la libreria SPI
#include <Ethernet.h> //Aqui incluimos la libreria Ethernet
byte mac[] = {0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED}; //Declaracion de la direccion MAC
IPAddress ip(192, 168, 1, 45); //Declaracion de la IP
EthernetServer servidor(80); //Declaracion del puerto 80

int PIN_LED = 8; //Aqui establecemos la variable PIN_LED como un valor entero
String readString = String(30); //lee los caracteres de una secuencia en una cadena.
//Los strings se representan como arrays de caracteres (tipo char)
String state = String(3);
float gradosC;

void setup() {
  Ethernet.begin(mac, ip); //Inicializamos con las direcciones asignadas
  servidor.begin(); //inicia el servidor
  pinMode(PIN_LED, OUTPUT);
  pinMode(4,OUTPUT);
  digitalWrite(PIN_LED, LOW);
  state = "OFF";
}

void loop() {
  //EthernetClient Crea un cliente que se puede conectar a
  //una dirección específica de Internet IP
  EthernetClient cliente = servidor.available();
  if (cliente) {

    boolean lineaenblanco = true;
    while (cliente.connected()) {
      if (cliente.available()) {
        char c = cliente.read();
        if (readString.length() < 30) {
          readString.concat(c);
          //Cliente conectado
          //Leemos petición HTTP caracter a caracter
          //Almacenar los caracteres en la variable readString
        } if (c == '\n' && lineaenblanco) { //Si la petición HTTP ha finalizado


          //Cabecera HTTP estándar
          cliente.println("HTTP/1.1 200 OK");
          cliente.println("Content-Type: text/html");
          cliente.println(); //Página Web en HTML
          cliente.println("<html>");
          cliente.println("<head>");


          cliente.println("<title>Encender y apagar</title>");
          cliente.println("</head>");
          cliente.println("<body width=100% height=100%>");
          cliente.println("<center>");
          cliente.println("<h1>Temperatura</h1>");
          cliente.print("<br><br>");

          gradosC = (5.0 * analogRead(A1) * 100.0) / 1024;
          cliente.println("Estado del Ventilador: ");
          cliente.print(gradosC);
            cliente.println("<BR>");
            cliente.println("<META HTTP-EQUIV='REFRESH' CONTENT='3'>");
          if (gradosC >= 30) {
            digitalWrite(4, HIGH);
            cliente.print("Estado del Ventilador: Encendido\n");
          } else {
            digitalWrite(4, LOW);
            cliente.print("Estado del Ventilador: Apagado\n");
          }

          cliente.println("</center>");
          cliente.println("</body>");
          cliente.println("</html>");
          cliente.stop();
          //Cierro conexión con el cliente
          readString = "";

        }
      }
    }
  }
}

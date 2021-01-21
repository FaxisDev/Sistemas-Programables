#include <SPI.h>
#include <Ethernet.h>

byte mac[] = {
  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED
};
IPAddress ip(192, 168, 1, 100); //dirección ip
EthernetServer server(80);
void setup() {
  Serial.begin(9600);
  // inicia la conexion y el servidor:
  Ethernet.begin(mac, ip);
  server.begin();
  Serial.print("servidor en lista");
  Serial.println(Ethernet.localIP());
}
void loop() {
  // Detectar los clientes entrantes
  EthernetClient client = server.available();
  if (client) {
    Serial.println("Nuevo cliente");
    boolean currentLineIsBlank = true;
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        Serial.write(c);

        if (c == '\n' && currentLineIsBlank) {
          client.println("HTTP/1.1 200 OK");
          client.println("Content-Type: text/html");
          client.println("Conexion Cerrada: cerrada");
          client.println();
          client.println("<!DOCTYPE HTML>");
          client.println("<html><center>");
          client.print("<span style='background: #ccc;'>VALORES DE ENTRADAS ANALOGICAS</span> ");
          client.println("<br />");
          // Añadir una etiqueta para conseguir que el navegador se actualice cada 5 segundos:
          client.println("<meta http-equiv=\"refresh\" content=\"3\">");
          // salida del valor de cada entrada analogica
          for (int analogChannel = 0; analogChannel < 1; analogChannel++) {
            int sensorReading = analogRead(analogChannel);
            client.print("Entrada analogica: ");
            client.print(analogChannel);
            client.print(" es <b>");
            client.print(sensorReading);
            client.println("</b><br />");
          }
          client.println("</center></html>");
          break;
        }
  
      }
    }
    // facilita al navegador web un tiempo para recibir los datos
    delay(1);
    // cierra la conexión:
    client.stop();
    Serial.println("Cliente desconectado");
  }
}

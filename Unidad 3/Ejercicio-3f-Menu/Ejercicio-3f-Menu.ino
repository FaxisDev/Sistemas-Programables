int opcion_menu = 0, plot = 0, original = 0, temp = 0;

void setup() {

  Serial.begin(9600);

  pinMode(2, OUTPUT);
  Serial.println("Presiona ENTER para iniciar");

}


void loop() {

  menu_principal();

}

void menu_principal() {
  //Menu de Opciones
  if (plot != 1) {
    Serial.println("=== > Bienvenido al monitoreo de Arduino < ==== ");
    Serial.println("a - Foto-Resistencia");
    Serial.println("b - Control de Temperatura");
    Serial.println("c - Potenciometro");
    Serial.println("d - Encendido/Apagado LED");
  }
  plot = 1;
  //Esto es del menu
  if (Serial.available() > 0) {

    opcion_menu = Serial.read();


    //    Serial.println("Escogiste: ");
    //    Serial.println(opcion_menu);
    //    if((Serial.read() != 1 && Serial.read() != 2) && (Serial.read() != 3 && Serial.read() != 4)){
    //        Serial.println("## Esa opcino no existe");
    //    }

    if (opcion_menu == 'a') {
      op_1();
      plot = 0;
    } else if (opcion_menu == 'b') {
      op_2();
      plot = 0;
    } else if (opcion_menu == 'c') {
      op_3();
      plot = 0;
    } else if (opcion_menu == 'd') {
      op_4();
      plot = 0;
    }

  }
}

void op_1() {
  Serial.println("El valor de la foto-resistencia actual:");
  while (true) {

    if (original != analogRead(A0)) {
      Serial.print("Registro: ");
      Serial.println(analogRead(A0));
      original = analogRead(A0);
    }

    if (Serial.read() == 'z') {
      break;
    }
  }
}

void op_2() {
  Serial.println("Valores de Control de Temperatura:");
  while (true) {

    if (original != analogRead(A1)) {
      Serial.print("Registro: ");
      temp = analogRead(A1) / 2;
      Serial.println(temp);
      delay(100);
      
      original = analogRead(A1);
    }

    if (Serial.read() == 'z') {
      break;
    }
  }
}

void op_3() {
  Serial.println("Potenciometro Valores:");
  while (true) {

    if (original != analogRead(A2)) {
      Serial.print("Registro: ");
      Serial.println(analogRead(A2));
      original = analogRead(A2);
    }

    if (Serial.read() == 'z') {
      break;
    }
  }
}


void op_4() {
  Serial.println("Enciende y apaga el led [h | Enciende][l | Apaga]:");
  while (true) {
    if (Serial.read() == 'h') {
      digitalWrite(2, HIGH);
    }
    if (Serial.read() == 'l') {
      digitalWrite(2, LOW);
    }

    if (Serial.read() == 'z') {
      break;
    }
  }
}

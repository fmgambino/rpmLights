// Definición de pines
const int frio = 1;   // Primer LED conectado al pin 3
const int calido = 0; // Segundo LED conectado al pin 4
const int RESET = 5;  // Pulsador conectado al pin 5
const int OK = 4;     // Pulsador conectado al pin 1
const int NXT = 2;    // Pulsador conectado al pin 2
const int PRV = 3;    // Pulsador conectado al pin 0

// Variable para almacenar el estado del pulsador
int estadoRESET;
int estadoPRV;
int estadoOK;
int estadoNXT;
int caso = 1;
int i = 0;

void setup() {
  // Configurar pines como entrada o salida
  pinMode(frio, OUTPUT);      // Funcionando
  pinMode(calido, OUTPUT);    // Funcionando
  pinMode(PRV, INPUT);        // Agregar resistencia pull-up externa si es necesario
  pinMode(OK, INPUT_PULLUP);  // Funcionando
  pinMode(NXT, INPUT);        // Agregar resistencia pull-up externa si es necesario
}

void loop() {
  // Leer el estado de los pulsadores
  estadoPRV = digitalRead(PRV);
  estadoNXT = digitalRead(NXT);

  switch (caso) {
    case 1:
      analogWrite(frio, 255);
      analogWrite(calido, 255);
      break;
    case 2:
      analogWrite(frio, i);
      analogWrite(calido, 255);
      break;
    case 3:
      analogWrite(frio, 255);
      analogWrite(calido, i);
      break;
  }

  // Incrementar o disminuir el valor de i según los botones presionados
  if (estadoPRV == LOW && i > 0) {
    i--;
    delay(100); // Puedes ajustar este valor según sea necesario
  } else if (estadoNXT == LOW && i < 255) {
    i++;
    delay(100); // Puedes ajustar este valor según sea necesario
  }

  // Cambiar de caso si se presiona el botón OK
  if (digitalRead(OK) == LOW) {
    caso++;
    if (caso > 3) {
      caso = 2;
    }
    delay(200); // Puedes ajustar este valor según sea necesario
  }
}

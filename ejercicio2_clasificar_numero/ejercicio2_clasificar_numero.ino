/*
  Taller de Estructuras de Decisión - Ejercicio 2
  Clasificar Número Real
  
  Determina si un número real ingresado es:
  - Positivo
  - Negativo
  - Cero
 */

void setup() {
  Serial.begin(115200);
  while (!Serial) {
    ; // Esperar a que el puerto serie se conecte
  }
  
  Serial.println("=== CLASIFICADOR DE NÚMEROS ===");
  Serial.println("Determina si un número es positivo, negativo o cero");
  Serial.println();
}

void loop() {
  float numero;
  
  // Solicitar el número
  Serial.println("Ingrese un número real: ");
  numero = leerNumero();
  
  // Mostrar el número ingresado
  Serial.print("Número ingresado: ");
  Serial.println(numero, 4);
  Serial.println();
  
  // Estructura de decisión múltiple para clasificar el número
  if (numero > 0) {
    Serial.println("Resultado: El número es POSITIVO (+)");
    Serial.println("El número es mayor que cero.");
  } 
  else if (numero < 0) {
    Serial.println("Resultado: El número es NEGATIVO (-)");
    Serial.println("El número es menor que cero.");
  } 
  else {
    Serial.println("Resultado: El número es CERO (0)");
    Serial.println("El número no es ni positivo ni negativo.");
  }
  
  Serial.println();
  Serial.println("================================");
  Serial.println("Presione Enter para clasificar otro número...");
  
  // Esperar a que el usuario presione Enter
  esperarEnter();
  Serial.println();
}

// Función para leer un número desde el puerto serie
float leerNumero() {
  while (Serial.available() == 0) {
    // Esperar entrada del usuario
  }
  
  float numero = Serial.parseFloat();
  
  // Limpiar el buffer
  while (Serial.available() > 0) {
    Serial.read();
  }
  
  return numero;
}

// Función para esperar que el usuario presione Enter
void esperarEnter() {
  // Limpiar buffer
  while (Serial.available() > 0) {
    Serial.read();
  }
  
  // Esperar entrada
  while (Serial.available() == 0) {
    // Esperar
  }
  
  // Limpiar buffer
  while (Serial.available() > 0) {
    Serial.read();
  }
}

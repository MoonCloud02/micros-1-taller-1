/*
  Taller de Estructuras de Decisión - Ejercicio 1
  Cálculo de Nota Definitiva
  
  Calcula la nota definitiva de programación con:
  - Primer parcial: 30%
  - Segundo parcial: 20%
  - Tercer parcial: 20%
  - Examen final: 30%
  
  Determina si el estudiante aprueba, reprueba o queda en transición
 */

void setup() {
  Serial.begin(115200);
  while (!Serial) {
    ; // Esperar a que el puerto serie se conecte
  }
  
  Serial.println("=== CÁLCULO DE NOTA DEFINITIVA ===");
  Serial.println("Ingeniería Mecatrónica - Programación");
  Serial.println();
}

void loop() {
  float parcial1, parcial2, parcial3, examenFinal;
  float notaDefinitiva;
  
  // Solicitar las notas
  Serial.println("Ingrese la nota del primer parcial (0-5): ");
  parcial1 = leerNota();
  
  Serial.println("Ingrese la nota del segundo parcial (0-5): ");
  parcial2 = leerNota();
  
  Serial.println("Ingrese la nota del tercer parcial (0-5): ");
  parcial3 = leerNota();
  
  Serial.println("Ingrese la nota del examen final (0-5): ");
  examenFinal = leerNota();
  
  // Calcular la nota definitiva
  notaDefinitiva = (parcial1 * 0.30) + (parcial2 * 0.20) + (parcial3 * 0.20) + (examenFinal * 0.30);
  
  // Mostrar resultados
  Serial.println();
  Serial.println("========== RESULTADOS ==========");
  Serial.print("Primer parcial (30%): ");
  Serial.println(parcial1);
  Serial.print("Segundo parcial (20%): ");
  Serial.println(parcial2);
  Serial.print("Tercer parcial (20%): ");
  Serial.println(parcial3);
  Serial.print("Examen final (30%): ");
  Serial.println(examenFinal);
  Serial.println("--------------------------------");
  Serial.print("NOTA DEFINITIVA: ");
  Serial.println(notaDefinitiva, 2);
  
  // Estructura de decisión múltiple
  if (notaDefinitiva >= 3.0) {
    Serial.println("Estado: APRUEBA ✓");
    Serial.println("¡Felicitaciones! Has aprobado la materia.");
  } 
  else if (notaDefinitiva >= 2.5 && notaDefinitiva < 3.0) {
    Serial.println("Estado: REPRUEBA ✗");
    Serial.println("No has alcanzado la nota mínima de aprobación.");
  } 
  else {
    Serial.println("Estado: TRANSICIÓN ⚠");
    Serial.println("Debes presentar un examen de transición.");
  }
  
  Serial.println("================================");
  Serial.println();
  Serial.println("Presione Enter para realizar otro cálculo...");
  
  // Esperar a que el usuario presione Enter
  esperarEnter();
  Serial.println();
}

// Función para leer una nota desde el puerto serie
float leerNota() {
  while (Serial.available() == 0) {
    // Esperar entrada del usuario
  }
  
  float nota = Serial.parseFloat();
  
  // Limpiar el buffer
  while (Serial.available() > 0) {
    Serial.read();
  }
  
  // Validar que la nota esté en el rango correcto
  if (nota < 0.0 || nota > 5.0) {
    Serial.println("Error: La nota debe estar entre 0 y 5. Intente nuevamente.");
    return leerNota();
  }
  
  return nota;
}

/* Función para esperar que el usuario presione Enter
 El buffer se limpia antes y después de esperar la entrada
 debido a posibles entradas erróneas previas del usuario */
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

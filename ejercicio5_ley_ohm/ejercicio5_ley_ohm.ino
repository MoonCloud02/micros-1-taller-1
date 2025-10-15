/*
  Taller de Estructuras de Decisión - Ejercicio 5
  Calculadora de Ley de Ohm
  
  Permite calcular:
  1. Resistencia (R = V / I)
  2. Voltaje (V = I × R)
  3. Corriente (I = V / R)
  
  Ley de Ohm: V = I × R
 */

void setup() {
  Serial.begin(115200);
  while (!Serial) {
    ; // Esperar a que el puerto serie se conecte
  }
  
  Serial.println("=== CALCULADORA LEY DE OHM ===");
  Serial.println("V = I × R");
  Serial.println();
}

void loop() {
  int opcion;
  float voltaje, corriente, resistencia;
  float resultado;
  
  // Mostrar menú principal
  Serial.println("========== MENÚ PRINCIPAL ==========");
  Serial.println("Seleccione qué desea calcular:");
  Serial.println("1. Resistencia (R = V / I)");
  Serial.println("2. Voltaje (V = I × R)");
  Serial.println("3. Corriente (I = V / R)");
  Serial.println("====================================");
  Serial.print("Opción (1-3): ");
  
  opcion = leerEntero();
  Serial.println();
  
  // Estructura switch case para procesar la opción
  switch (opcion) {
    case 1:
      {
        // Calcular Resistencia: R = V / I
        Serial.println("--- CÁLCULO DE RESISTENCIA ---");
        Serial.println("Fórmula: R = V / I");
        Serial.println();
        
        Serial.print("Ingrese el voltaje (V) en voltios: ");
        voltaje = leerNumeroPositivo();
        
        Serial.print("Ingrese la corriente (I) en amperios: ");
        corriente = leerNumeroPositivo();
        
        if (corriente == 0) {
          Serial.println();
          Serial.println("Error: La corriente no puede ser cero.");
          Serial.println("No se puede dividir entre cero.");
        } else {
          resultado = voltaje / corriente;
          
          Serial.println();
          Serial.println("========== RESULTADO ==========");
          Serial.print("Voltaje (V): ");
          Serial.print(voltaje, 4);
          Serial.println(" V");
          Serial.print("Corriente (I): ");
          Serial.print(corriente, 4);
          Serial.println(" A");
          Serial.println("-------------------------------");
          Serial.print("Resistencia (R): ");
          Serial.print(resultado, 4);
          Serial.println(" Ω (Ohmios)");
          Serial.println("===============================");
        }
      }
      break;
      
    case 2:
      {
        // Calcular Voltaje: V = I × R
        Serial.println("--- CÁLCULO DE VOLTAJE ---");
        Serial.println("Fórmula: V = I × R");
        Serial.println();
        
        Serial.print("Ingrese la corriente (I) en amperios: ");
        corriente = leerNumeroPositivo();
        
        Serial.print("Ingrese la resistencia (R) en ohmios: ");
        resistencia = leerNumeroPositivo();
        
        resultado = corriente * resistencia;
        
        Serial.println();
        Serial.println("========== RESULTADO ==========");
        Serial.print("Corriente (I): ");
        Serial.print(corriente, 4);
        Serial.println(" A");
        Serial.print("Resistencia (R): ");
        Serial.print(resistencia, 4);
        Serial.println(" Ω");
        Serial.println("-------------------------------");
        Serial.print("Voltaje (V): ");
        Serial.print(resultado, 4);
        Serial.println(" V (Voltios)");
        Serial.println("===============================");
      }
      break;
      
    case 3:
      {
        // Calcular Corriente: I = V / R
        Serial.println("--- CÁLCULO DE CORRIENTE ---");
        Serial.println("Fórmula: I = V / R");
        Serial.println();
        
        Serial.print("Ingrese el voltaje (V) en voltios: ");
        voltaje = leerNumeroPositivo();
        
        Serial.print("Ingrese la resistencia (R) en ohmios: ");
        resistencia = leerNumeroPositivo();
        
        if (resistencia == 0) {
          Serial.println();
          Serial.println("Error: La resistencia no puede ser cero.");
          Serial.println("No se puede dividir entre cero.");
        } else {
          resultado = voltaje / resistencia;
          
          Serial.println();
          Serial.println("========== RESULTADO ==========");
          Serial.print("Voltaje (V): ");
          Serial.print(voltaje, 4);
          Serial.println(" V");
          Serial.print("Resistencia (R): ");
          Serial.print(resistencia, 4);
          Serial.println(" Ω");
          Serial.println("-------------------------------");
          Serial.print("Corriente (I): ");
          Serial.print(resultado, 4);
          Serial.println(" A (Amperios)");
          Serial.println("===============================");
        }
      }
      break;
      
    default:
      Serial.println("Error: Opción no válida.");
      Serial.println("Por favor seleccione una opción entre 1 y 3.");
      break;
  }
  
  Serial.println();
  Serial.println("Presione Enter para realizar otro cálculo...");
  esperarEnter();
  Serial.println();
}

// Función para leer un número positivo
float leerNumeroPositivo() {
  while (Serial.available() == 0) {
    // Esperar entrada del usuario
  }
  
  float numero = Serial.parseFloat();
  
  // Limpiar el buffer
  while (Serial.available() > 0) {
    Serial.read();
  }
  
  if (numero < 0) {
    Serial.println("Advertencia: Se ingresó un número negativo.");
    Serial.print("Usando valor absoluto: ");
    Serial.println(abs(numero), 4);
    return abs(numero);
  }
  
  return numero;
}

// Función para leer un número entero
int leerEntero() {
  while (Serial.available() == 0) {
    // Esperar entrada del usuario
  }
  
  int numero = Serial.parseInt();
  
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

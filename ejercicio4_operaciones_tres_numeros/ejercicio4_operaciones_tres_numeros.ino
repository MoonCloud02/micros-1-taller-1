/*
  Ejercicio 4: Operaciones con Tres Números
  
  Este programa permite realizar operaciones con tres números ingresados:
  1. Calcular el promedio de los tres números
  2. Determinar cuál es el número mayor
  3. Determinar cuál es el número menor
  4. Contar cuántos números son pares e impares
  
  El usuario ingresa tres números y luego selecciona la operación deseada
  mediante un menú interactivo.
 */

void setup() {
  // Inicializar comunicación serial a 115200 baudios
  Serial.begin(115200);
  while (!Serial) {
    ; // Esperar a que el puerto serie esté listo
  }
  
  // Mostrar título del programa
  Serial.println("=== OPERACIONES CON TRES NÚMEROS ===");
  Serial.println("Sistema de análisis de números");
  Serial.println();
}

void loop() {
  // Declaración de variables
  float num1, num2, num3;
  int opcion;
  
  // Solicitar los tres números al usuario
  Serial.println("Ingrese el primer número: ");
  num1 = leerNumero();
  
  Serial.println("Ingrese el segundo número: ");
  num2 = leerNumero();
  
  Serial.println("Ingrese el tercer número: ");
  num3 = leerNumero();
  
  // Mostrar los números ingresados
  Serial.println();
  Serial.println("Números ingresados:");
  Serial.print("  Número 1: ");
  Serial.println(num1, 2);
  Serial.print("  Número 2: ");
  Serial.println(num2, 2);
  Serial.print("  Número 3: ");
  Serial.println(num3, 2);
  Serial.println();
  
  // Mostrar menú de operaciones disponibles
  Serial.println("========== MENÚ DE OPERACIONES ==========");
  Serial.println("1. Calcular el promedio");
  Serial.println("2. Determinar el número mayor");
  Serial.println("3. Determinar el número menor");
  Serial.println("4. Contar números pares e impares");
  Serial.println("=========================================");
  Serial.print("Seleccione una opción (1-4): ");
  
  opcion = leerEntero();
  Serial.println();
  
  // Procesar la opción seleccionada
  switch (opcion) {
    case 1:
      {
        // Opción 1: Calcular el promedio de los tres números
        float promedio = (num1 + num2 + num3) / 3.0;
        Serial.println("--- CÁLCULO DEL PROMEDIO ---");
        Serial.print("Promedio = (");
        Serial.print(num1, 2);
        Serial.print(" + ");
        Serial.print(num2, 2);
        Serial.print(" + ");
        Serial.print(num3, 2);
        Serial.println(") / 3");
        Serial.print("Promedio = ");
        Serial.println(promedio, 4);
      }
      break;
      
    case 2:
      {
        // Opción 2: Determinar el número mayor
        float mayor = num1;
        
        if (num2 > mayor) {
          mayor = num2;
        }
        if (num3 > mayor) {
          mayor = num3;
        }
        
        Serial.println("--- NÚMERO MAYOR ---");
        Serial.print("El número mayor es: ");
        Serial.println(mayor, 2);
      }
      break;
      
    case 3:
      {
        // Opción 3: Determinar el número menor
        float menor = num1;
        
        if (num2 < menor) {
          menor = num2;
        }
        if (num3 < menor) {
          menor = num3;
        }
        
        Serial.println("--- NÚMERO MENOR ---");
        Serial.print("El número menor es: ");
        Serial.println(menor, 2);
      }
      break;
      
    case 4:
      {
        // Opción 4: Contar números pares e impares
        int pares = 0;
        int impares = 0;
        
        // Convertir los números a enteros para verificar paridad
        int n1 = (int)num1;
        int n2 = (int)num2;
        int n3 = (int)num3;
        
        // Verificar si el primer número es par o impar
        if (n1 % 2 == 0) {
          pares++;
        } else {
          impares++;
        }
        
        // Verificar si el segundo número es par o impar
        if (n2 % 2 == 0) {
          pares++;
        } else {
          impares++;
        }
        
        // Verificar si el tercer número es par o impar
        if (n3 % 2 == 0) {
          pares++;
        } else {
          impares++;
        }
        
        // Mostrar resultados detallados
        Serial.println("--- ANÁLISIS PAR/IMPAR ---");
        Serial.print("Número 1 (");
        Serial.print(n1);
        Serial.print("): ");
        Serial.println((n1 % 2 == 0) ? "PAR" : "IMPAR");
        
        Serial.print("Número 2 (");
        Serial.print(n2);
        Serial.print("): ");
        Serial.println((n2 % 2 == 0) ? "PAR" : "IMPAR");
        
        Serial.print("Número 3 (");
        Serial.print(n3);
        Serial.print("): ");
        Serial.println((n3 % 2 == 0) ? "PAR" : "IMPAR");
        
        Serial.println();
        Serial.print("Total de números PARES: ");
        Serial.println(pares);
        Serial.print("Total de números IMPARES: ");
        Serial.println(impares);
      }
      break;
      
    default:
      // Opción inválida
      Serial.println("Error: Opción no válida.");
      Serial.println("Por favor seleccione una opción entre 1 y 4.");
      break;
  }
  
  Serial.println();
  Serial.println("=========================================");
  // Esperar que el usuario presione Enter para continuar
  Serial.println("Presione Enter para realizar otra operación...");
  esperarEnter();
  Serial.println();
}

/*
  Lee un número decimal desde el puerto serial
  @return float - El número ingresado por el usuario
 */
float leerNumero() {
  while (Serial.available() == 0) {
    // Esperar entrada del usuario
  }
  
  float numero = Serial.parseFloat();
  
  // Limpiar el buffer del puerto serial
  while (Serial.available() > 0) {
    Serial.read();
  }
  
  return numero;
}

/*
  Lee un número entero desde el puerto serial
  @return int - El número entero ingresado
 */
int leerEntero() {
  while (Serial.available() == 0) {
    // Esperar entrada del usuario
  }
  
  int numero = Serial.parseInt();
  
  // Limpiar el buffer del puerto serial
  while (Serial.available() > 0) {
    Serial.read();
  }
  
  return numero;
}

/*
  Espera a que el usuario presione Enter
  Limpia el buffer antes y después de la espera
 */
void esperarEnter() {
  // Limpiar cualquier dato pendiente en el buffer
  while (Serial.available() > 0) {
    Serial.read();
  }
  
  // Esperar a que llegue nueva entrada
  while (Serial.available() == 0) {
    // Esperar
  }
  
  // Limpiar el buffer nuevamente
  while (Serial.available() > 0) {
    Serial.read();
  }
}

void setup() {
  Serial.begin(9600);
  while (!Serial) {
    ; 
  }
  
  Serial.println("=== OPERACIONES CON TRES NÚMEROS ===");
  Serial.println("Sistema de análisis de números");
  Serial.println();
}

void loop() {
  float num1, num2, num3;
  int opcion;
  
  Serial.println("Ingrese el primer número: ");
  num1 = leerNumero();
  
  Serial.println("Ingrese el segundo número: ");
  num2 = leerNumero();
  
  Serial.println("Ingrese el tercer número: ");
  num3 = leerNumero();
  
  Serial.println();
  Serial.println("Números ingresados:");
  Serial.print("  Número 1: ");
  Serial.println(num1);
  Serial.print("  Número 2: ");
  Serial.println(num2);
  Serial.print("  Número 3: ");
  Serial.println(num3);
  Serial.println();
  
  Serial.println("========== MENÚ DE OPERACIONES ==========");
  Serial.println("1. Calcular el promedio");
  Serial.println("2. Determinar el número mayor");
  Serial.println("3. Determinar el número menor");
  Serial.println("4. Contar números pares e impares");
  Serial.println("=========================================");
  Serial.print("Seleccione una opción (1-4): ");
  
  opcion = leerEntero();
  Serial.println();
  
  switch (opcion) {
    case 1:
      {
        float promedio = (num1 + num2 + num3) / 3;
        Serial.println("--- CÁLCULO DEL PROMEDIO ---");
        Serial.print("Promedio = (");
        Serial.print(num1);
        Serial.print(" + ");
        Serial.print(num2);
        Serial.print(" + ");
        Serial.print(num3);
        Serial.println(") / 3");
        Serial.print("Promedio = ");
        Serial.println(promedio);
      }
      break;
      
    case 2:
      {
        float mayor = num1;
        
        if (num2 > mayor) {
          mayor = num2;
        }
        if (num3 > mayor) {
          mayor = num3;
        }
        
        Serial.println("--- NÚMERO MAYOR ---");
        Serial.print("El número mayor es: ");
        Serial.println(mayor);
      }
      
    case 3:
      {
        float menor = num1;
        
        if (num2 < menor) {
          menor = num2;
        }
        if (num3 < menor) {
          menor = num3;
        }
        
        Serial.println("--- NÚMERO MENOR ---");
        Serial.print("El número menor es: ");
        Serial.println(menor);
      }
      break;
      
    case 4:
      {
        int pares = 0;
        int impares = 0;
        
        int n1 = (int)num1;
        int n2 = (int)num2;
        int n3 = (int)num3;
        
        if (n1 % 2 == 0) {
          pares++;
        } else {
          impares++;
        }
        
        if (n2 % 2 == 0) {
          pares++;
        } 
        
        if (n3 % 2 == 0) {
          pares++;
        } else {
          impares++;
        }
        
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
      Serial.println("Error: Opción no válida.");
      Serial.println("Por favor seleccione una opción entre 1 y 4.");
      break;
  }
  
  Serial.println();
  Serial.println("=========================================");
  Serial.println("Presione Enter para realizar otra operación...");
  esperarEnter();
  Serial.println();
}

float leerNumero() {
  while (Serial.available() == 0) {
  }
  
  float numero = Serial.parseFloat();
  
  while (Serial.available() > 0) {
    Serial.read();
  }
  
  return numero;
}

int leerEntero() {
  while (Serial.available() == 0) {
  }
  
  int numero = Serial.parseInt();
  
  while (Serial.available() > 0) {
    Serial.read();
  }
  
  return numero;
}

void esperarEnter() {
  while (Serial.available() > 0) {
    Serial.read();
  }
  
  while (Serial.available() == 0) {
  }
  
  while (Serial.available() > 0) {
    Serial.read();
  }
}

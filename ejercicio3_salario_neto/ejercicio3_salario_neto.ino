/*
  Ejercicio 3: Cálculo de Salario Neto
  
  Este programa calcula el salario neto de un empleado basándose en:
  - Salario base ingresado por el usuario
   
  Categorías:
  1: Bonificación 15%, Descuento 4%
  2: Bonificación 13%, Descuento 3%
  3: Bonificación 12%, Descuento 2%
  4: Bonificación 9.5%, Descuento 0%
 */

void setup() {
  // Inicializar comunicación serial a 115200 baudios
  Serial.begin(115200);
  while (!Serial) {
    ; // Esperar a que el puerto serie esté listo
  }
  
  // Mostrar título del programa
  Serial.println("=== CÁLCULO DE SALARIO NETO ===");
  Serial.println("Sistema de nomina por categorías");
  Serial.println();
}

void loop() {
  // Declaración de variables
  float salarioBase;
  int categoria;
  float bonificacion = 0;
  float descuento = 0;
  float salarioConBonificacion;
  float totalDescuento;
  float salarioNeto;
  
  // Solicitar el salario base al usuario
  Serial.println("Ingrese el salario base del empleado: ");
  salarioBase = leerNumeroPositivo();

  // Mostrar menú de categorías
  Serial.println("Ingrese la categoría del empleado (1-4): ");
  Serial.println("  1 - Categoría 1 (Bonif: 15%, Desc: 4%)");
  Serial.println("  2 - Categoría 2 (Bonif: 13%, Desc: 3%)");
  Serial.println("  3 - Categoría 3 (Bonif: 12%, Desc: 2%)");
  Serial.println("  4 - Categoría 4 (Bonif: 9.5%, Desc: 0%)");
  Serial.print("Opción: ");
  categoria = leerEntero();
  
  // Asignar bonificación y descuento según la categoría seleccionada
  switch (categoria) {
    case 1:
      bonificacion = 0.15;  // 15% de bonificación
      descuento = 0.04;     // 4% de descuento
      Serial.println("Categoría 1 seleccionada");
      break;
      
    case 2:
      bonificacion = 0.13;  // 13% de bonificación
      descuento = 0.03;     // 3% de descuento
      Serial.println("Categoría 2 seleccionada");
      break;
      
    case 3:
      bonificacion = 0.12;  // 12% de bonificación
      descuento = 0.02;     // 2% de descuento
      Serial.println("Categoría 3 seleccionada");
      break;
      
    case 4:
      bonificacion = 0.095; // 9.5% de bonificación
      descuento = 0.0;      // Sin descuento
      Serial.println("Categoría 4 seleccionada");
      break;
      
    default:
      Serial.println("Error: Categoría inválida. Usando categoría 4 por defecto.");
      bonificacion = 0.095;
      descuento = 0.0;
      break;
  }
  
  // Realizar los cálculos
  salarioConBonificacion = salarioBase + (salarioBase * bonificacion);
  totalDescuento = salarioConBonificacion * descuento;
  salarioNeto = salarioConBonificacion - totalDescuento;
  
  // Mostrar desglose detallado de la nómina
  Serial.println();
  Serial.println("========== DESGLOSE DE NÓMINA ==========");
  Serial.print("Salario base: $");
  Serial.println(salarioBase, 2);
  Serial.print("Bonificación (");
  Serial.print(bonificacion * 100, 1);
  Serial.print("%): $");
  Serial.println(salarioBase * bonificacion, 2);
  Serial.println("----------------------------------------");
  Serial.print("Salario + bonificación: $");
  Serial.println(salarioConBonificacion, 2);
  Serial.print("Descuento (");
  Serial.print(descuento * 100, 1);
  Serial.print("%): -$");
  Serial.println(totalDescuento, 2);
  Serial.println("========================================");
  Serial.print("SALARIO NETO: $");
  Serial.println(salarioNeto, 2);
  Serial.println("========================================");
  Serial.println();
  
  // Esperar que el usuario presione Enter para continuar
  Serial.println("Presione Enter para calcular otro salario...");
  esperarEnter();
  Serial.println();
}

/*
  Lee un número positivo desde el puerto serial
  Valida que el número sea mayor que cero
  @return float - El número positivo ingresado
 */
float leerNumeroPositivo() {
  while (Serial.available() == 0) {
    // Esperar entrada del usuario
  }
  
  float numero = Serial.parseFloat();
  
  // Limpiar el buffer del puerto serial
  while (Serial.available() > 0) {
    Serial.read();
  }
  
  // Validar que el número sea positivo
  if (numero <= 0) {
    Serial.println("Error: Debe ingresar un número positivo. Intente nuevamente.");
    return leerNumeroPositivo();
  }
  
  return numero;
}

/**
 * Lee un número entero desde el puerto serial
 * @return int - El número entero ingresado
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

void setup() {
  Serial.begin(9600);
  while (!Serial) {
    ; 
  }
  
  Serial.println("=== CÁLCULO DE SALARIO NETO ===");
  Serial.println("Sistema de nomina por categorías");
  Serial.println();
}

void loop() {
  float salarioBase;
  int categoria;
  float bonificacion = 0;
  float descuento = 0;
  float salarioConBonificacion;
  float totalDescuento;
  float salarioNeto;
  
  Serial.println("Ingrese el salario base del empleado: ");
  salarioBase = leerNumeroPositivo();

  Serial.println("Ingrese la categoría del empleado (1-4): ");
  Serial.println("  1 - Categoría 1 (Bonif: 15%, Desc: 4%)");
  Serial.println("  2 - Categoría 2 (Bonif: 13%, Desc: 3%)");
  Serial.println("  3 - Categoría 3 (Bonif: 12%, Desc: 2%)");
  Serial.println("  4 - Categoría 4 (Bonif: 9.5%, Desc: 0%)");
  Serial.print("Opción: ");
  categoria = leerEntero();
  
  switch (categoria) {
    case 1:
      bonificacion = 0.15; 
      descuento = 0.04;     
      Serial.println("Categoría 1 seleccionada");
      
    case 2:
      bonificacion = 0.13;  
      descuento = 0.03;     
      Serial.println("Categoría 2 seleccionada");
      break;
      
    case 3:
      bonificacion = 0.12;  
      descuento = 0.02;     
      Serial.println("Categoría 3 seleccionada");
      break;
      
    case 4:
      bonificacion = 0.095; 
      descuento = 0.0;      
      Serial.println("Categoría 4 seleccionada");
      break;
      
    default:
      Serial.println("Error: Categoría inválida. Usando categoría 4 por defecto.");
      bonificacion = 0.095;
      descuento = 0.0;
  }
  
  salarioConBonificacion = salarioBase + (salarioBase * bonificacion);
  totalDescuento = salarioConBonificacion * descuento;
  salarioNeto = salarioConBonificacion - totalDescuento;
  
  Serial.println();
  Serial.println("========== DESGLOSE DE NÓMINA ==========");
  Serial.print("Salario base: $");
  Serial.println(salarioBase);
  Serial.print("Bonificación (");
  Serial.print(bonificacion * 100);
  Serial.print("%): $");
  Serial.println(salarioBase * bonificacion);
  Serial.println("----------------------------------------");
  Serial.print("Salario + bonificación: $");
  Serial.println(salarioConBonificacion);
  Serial.print("Descuento (");
  Serial.print(descuento * 100);
  Serial.print("%): -$");
  Serial.println(totalDescuento);
  Serial.println("========================================");
  Serial.print("SALARIO NETO: $");
  Serial.println(salarioNeto);
  Serial.println("========================================");
  Serial.println();
  
  Serial.println("Presione Enter para calcular otro salario...");
  esperarEnter();
  Serial.println();
}

float leerNumeroPositivo() {
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

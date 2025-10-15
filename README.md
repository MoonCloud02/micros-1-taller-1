# Taller de Estructuras de Decisión en C para Microcontroladores

**Curso:** Microcontroladores 1 - Programación  
**Facultad:** Tecnología - Ingeniería Mecatrónica  
**Instructor:** Ing. Jeronimo Jaramillo Bejarano  
**Fecha:** Octubre 15 de 2025

## Objetivo

Familiarizar a los estudiantes con las estructuras básicas de decisión (`if`, `else`, `switch case`) de la programación en lenguaje C para microcontroladores.

## Requisitos

- **Hardware:** ESP32
- **Software:** Arduino IDE
- **Herramienta de diagramas:** Mermaid (integrado en GitHub)
- **Control de versiones:** Git/GitHub/GitLab

## Estructura del Proyecto

```
micros-1-taller-1/
├── ejercicio1_nota_definitiva/
│   └── ejercicio1_nota_definitiva.ino
├── ejercicio2_clasificar_numero/
│   └── ejercicio2_clasificar_numero.ino
├── ejercicio3_salario_neto/
│   └── ejercicio3_salario_neto.ino
├── ejercicio4_operaciones_tres_numeros/
│   └── ejercicio4_operaciones_tres_numeros.ino
├── ejercicio5_ley_ohm/
│   └── ejercicio5_ley_ohm.ino
└── README.md
```

## Ejercicios

### Ejercicio 1: Cálculo de Nota Definitiva
**Archivo:** `ejercicio1_nota_definitiva.ino`

Calcula la nota definitiva de programación con los siguientes porcentajes:
- Primer parcial: 30%
- Segundo parcial: 20%
- Tercer parcial: 20%
- Examen final: 30%

**Criterios de evaluación:**
- Si la nota ≥ 3.0: **APRUEBA**
- Si 2.5 ≤ nota < 3.0: **REPRUEBA**
- Si nota < 2.5: **TRANSICIÓN**

**Características:**
- Validación de notas en el rango 0-5
- Estructura de decisión múltiple (`if-else if-else`)
- Interfaz clara en el monitor serial

---

### Ejercicio 2: Clasificador de Números
**Archivo:** `ejercicio2_clasificar_numero.ino`

Determina si un número real ingresado es:
- **Positivo** (> 0)
- **Negativo** (< 0)
- **Cero** (= 0)

**Características:**
- Acepta números decimales
- Estructura de decisión múltiple
- Interfaz simple y clara

---

### Ejercicio 3: Cálculo de Salario Neto
**Archivo:** `ejercicio3_salario_neto.ino`

Calcula el salario neto según la categoría del empleado:

| Categoría | Bonificación | Descuento |
|-----------|--------------|-----------|
| 1         | 15%          | 4%        |
| 2         | 13%          | 3%        |
| 3         | 12%          | 2%        |
| 4         | 9.5%         | 0%        |

**Características:**
- Utiliza estructura `switch-case`
- Calcula: Salario + Bonificación - Descuento
- Muestra desglose detallado de nómina
- Validación de categorías

---

### Ejercicio 4: Operaciones con Tres Números
**Archivo:** `ejercicio4_operaciones_tres_numeros.ino`

Menú de operaciones con tres números:
1. **Calcular el promedio**
2. **Determinar el número mayor**
3. **Determinar el número menor**
4. **Contar números pares e impares**

**Características:**
- Estructura `switch-case` para el menú
- Manejo de números decimales
- Análisis completo de paridad

---

### Ejercicio 5: Calculadora Ley de Ohm
**Archivo:** `ejercicio5_ley_ohm.ino`

Calculadora basada en la Ley de Ohm: **V = I × R**

Permite calcular:
1. **Resistencia:** R = V / I
2. **Voltaje:** V = I × R
3. **Corriente:** I = V / R

**Características:**
- Estructura `switch-case` para el menú
- Validación de divisiones por cero
- Unidades claras (V, A, Ω)
- Formato de salida profesional

---

## Cómo Usar

### 1. Abrir un Ejercicio en Arduino IDE
1. Abre Arduino IDE
2. Ve a `Archivo > Abrir`
3. Navega a la carpeta del ejercicio deseado
4. Selecciona el archivo `.ino`

### 2. Configurar la ESP32
1. Ve a `Herramientas > Placa > ESP32 Arduino`
2. Selecciona tu modelo de ESP32
3. Selecciona el puerto COM correcto en `Herramientas > Puerto`

### 3. Subir el Código
1. Haz clic en el botón "Subir" (→)
2. Espera a que compile y cargue

### 4. Usar el Monitor Serial
1. Abre el Monitor Serial: `Herramientas > Monitor Serial`
2. Configura la velocidad a **115200 baudios**
3. Sigue las instrucciones en pantalla
4. Ingresa los datos cuando se soliciten
5. Presiona Enter para enviar

---

## Notas Técnicas

### Comunicación Serial
Todos los programas usan:
- **Velocidad:** 115200 baudios
- **Entrada:** Monitor Serial de Arduino IDE
- **Salida:** Monitor Serial de Arduino IDE

### Funciones Auxiliares
Cada programa incluye funciones reutilizables:
- `leerNumero()`: Lee números decimales del puerto serial
- `leerEntero()`: Lee números enteros
- `leerNumeroPositivo()`: Lee y valida números positivos
- `esperarEnter()`: Pausa el programa hasta presionar Enter

### Validaciones Implementadas
- Rangos válidos de entrada
- División por cero (Ejercicio 5)
- Conversión de valores negativos a positivos donde aplique
- Limpieza de buffer serial
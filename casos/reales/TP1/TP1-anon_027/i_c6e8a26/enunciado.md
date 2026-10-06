## 📋 Consigna y Enunciado — Trabajo Práctico 1: Introducción a C, Modularización y E/S en Consola

> 📌 **Origen del enunciado:** `configuración general (dredd.yaml: /home/mrtin/dev/p1/ripley/guias/TP1/guia.yaml)`

### Requerimientos por Ejercicio

#### `consola (Librería de Consola y Limpieza de Búfer)`

# Librería de Consola: Entrada/Salida Segura y Limpieza de Búfer

Implementá una biblioteca estática reutilizable en C (`libconsola.a`) que centralice las operaciones de entrada/salida tipadas desde la terminal estándar, garantizando robustez ante errores de tipeo del usuario y gestionando correctamente los caracteres residuales en el búfer de entrada (`stdin`).

## Justificación Técnica y Búfer de Entrada

En C, la función estándar `scanf` no consume automáticamente el salto de línea (`\n`) generado al pulsar Enter, ni limpia los caracteres no interpretados cuando el usuario ingresa un dato que no concuerda con el especificador de formato. Si este residuo no se descarta explícitamente:
1. Las lecturas de caracteres posteriores (`%c`) consumen de inmediato el `\n` residual en lugar de esperar la interacción del usuario.
2. Si la conversión numérica falla, los caracteres permanecen indefinidamente en el flujo, provocando bucles infinitos en esquemas de reintento.

El uso de `fflush(stdin)` está terminantemente prohibido, ya que el estándar ISO de C define que `fflush` solo es aplicable a flujos de salida (`stdout`, `stderr`); invocarlo sobre `stdin` constituye Comportamiento Indefinido (*Undefined Behavior*). La alternativa canónica y portable es descartar caracteres iterativamente hasta alcanzar el fin de línea o fin de archivo:

```c
void limpiar_buffer_entrada(void)
{
    int caracter = 0;
    while ((caracter = getchar()) != '\n' && caracter != EOF)
    {
    }
}
```

## Requerimientos de Implementación

Completá las funciones declaradas en `consola.h` dentro de `consola.c`:

1. **`void limpiar_buffer_entrada(void)`**: Descarte seguro del búfer `stdin`.
2. **`bool esta_en_rango_entero(int valor, int min, int max)`**: Determina si `min <= valor <= max`.
3. **`bool esta_en_rango_flotante(float valor, float min, float max)`**: Determina si `min <= valor <= max`.
4. **`int leer_entero(const char *mensaje)`**: Muestra el mensaje, lee con `scanf("%d", ...)`, limpia el búfer y reintenta si el usuario introdujo caracteres no numéricos.
5. **`int leer_entero_entre(const char *mensaje, int min, int max)`**: Solicita un entero y valida que pertenezca al rango especificado, informando límites ante fallos.
6. **`float leer_flotante(const char *mensaje)`**: Muestra el mensaje, lee con `scanf("%f", ...)`, limpia el búfer y valida lectura correcta.
7. **`float leer_flotante_entre(const char *mensaje, float min, float max)`**: Lee y valida un valor flotante acotado al rango `[min, max]`.
8. **`char leer_caracter(const char *mensaje)`**: Lee un único carácter descartando espacios en blanco iniciales y limpia el búfer posterior.
9. **`bool leer_logico(const char *mensaje)`**: Solicita confirmación interactiva aceptando `'s'`/`'S'` (true) o `'n'`/`'N'` (false).

**Pistas didácticas:**
- 1. En limpiar_buffer_entrada(), declará la variable del bucle como int para comparar correctamente contra EOF y \n.
- 2. Verificá siempre el valor de retorno de scanf: si retorna 0 o EOF, limpiá el búfer antes de pedir nuevamente el dato para evitar bucles infinitos.
- 3. Bajo el estándar C, fflush(stdin) produce Comportamiento Indefinido (Undefined Behavior); usá limpiar_buffer_entrada().

#### `ejercicio1 (Conversor de Temperatura Celsius y Fahrenheit)`

# Ejercicio 1: Conversor de Temperatura

Implementá un programa interactivo que permita convertir temperaturas entre las escalas **Celsius** (°C) y **Fahrenheit** (°F).

## Requerimientos
1. Implementá las funciones de conversión en `conversor.c`:
   - `float celsius_a_fahrenheit(float celsius);`
   - `float fahrenheit_a_celsius(float fahrenheit);`
2. En `main.c`, presentá un menú interactivo con las opciones:
   - `1`: Convertir de Celsius a Fahrenheit.
   - `2`: Convertir de Fahrenheit a Celsius.
3. Leé la opción y la temperatura usando las funciones validadas de `consola.h`.
4. Mostrá el resultado con 2 cifras decimales.
5. Preguntá al usuario si desea realizar otra conversión (`s/n`).

**Pistas didácticas:**
- 1. Recordá la fórmula de conversión: F = C * (9.0 / 5.0) + 32.0 y C = (F - 32.0) * (5.0 / 9.0).
- 2. Cuidá la división entera en C: 9 / 5 trunca a 1; usá literales float como 9.0f / 5.0f.
- 3. Para formatear números flotantes a dos decimales con printf usá %.2f.

#### `ejercicio2 (Calculadora Estadística Secuencial)`

# Ejercicio 2: Calculadora Estadística Secuencial

Implementá un programa interactivo que procese una secuencia de $N$ números flotantes en una única pasada, calculando estadísticos básicos en $O(1)$ de memoria (sin almacenar los datos en arreglos).

## Requerimientos
1. En `estadistica.c`, implementá:
   - `float calcular_promedio(float suma, int cantidad);`
   - `float actualizar_minimo(float actual_min, float nuevo_valor);`
   - `float actualizar_maximo(float actual_max, float nuevo_valor);`
2. En `main.c`, solicitá primero la cantidad $N > 0$ de valores a procesar.
3. Leé cada valor actualizando en línea la suma acumulada, el valor mínimo y el valor máximo.
4. Imprimí con 2 decimales:
   - Suma total.
   - Promedio.
   - Valor mínimo.
   - Valor máximo.
5. Preguntá si se desea procesar otra serie (`s/n`).

**Pistas didácticas:**
- 1. Procesá los números a medida que ingresan en una única pasada; no uses arreglos.
- 2. Inicializá el mínimo y el máximo con el primer valor ingresado (índice 0) para contemplar series puramente negativas.
- 3. El promedio es la división entre la suma acumulada y la cantidad de elementos ingresados convertida a float.

#### `ejercicio3 (Validador de Fechas y Año Bisiesto)`

# Ejercicio 3: Validador de Fechas y Año Bisiesto

Implementá un programa que verifique la validez de fechas en el calendario gregoriano y determine si el año ingresado es bisiesto.

## Requerimientos
1. En `fecha.c`, implementá:
   - `bool es_bisiesto(int anio);`
   - `int dias_en_mes(int mes, int anio);`
   - `bool es_fecha_valida(int dia, int mes, int anio);`
2. En `main.c`, solicitá:
   - Año ($> 0$).
   - Mes ($1..12$).
   - Día ($1..31$).
3. Informá si la fecha es válida o no.
4. Informá si el año es bisiesto o no.
5. Preguntá si se desea validar otra fecha (`s/n`).

**Pistas didácticas:**
- 1. Un año bisiesto gregoriano es divisible por 4 y no por 100, excepto que sea divisible por 400.
- 2. Meses con 31 días: 1, 3, 5, 7, 8, 10 y 12. Meses con 30 días: 4, 6, 9 y 11.
- 3. Febrero tiene 29 días en año bisiesto y 28 en año común. Fuera de 1..12 la fecha es inválida.

#### `ejercicio4 (Validador y Clasificador de Triángulos)`

# Ejercicio 4: Validador y Clasificador de Triángulos

Implementá un programa geométrico que determine la viabilidad de formar un triángulo a partir de tres longitudes de lado, clasifique su tipo e informe si es un triángulo rectángulo.

## Requerimientos
1. En `triangulo.c`, implementá:
   - `bool es_triangulo_valido(float lado_a, float lado_b, float lado_c);`
   - `int clasificar_triangulo(float lado_a, float lado_b, float lado_c);`
   - `bool es_triangulo_rectangulo(float lado_a, float lado_b, float lado_c);`
2. En `main.c`, solicitá las longitudes de los lados A, B y C.
3. Si los lados forman un triángulo válido:
   - Informá si es Equilátero, Isósceles o Escaleno.
   - Informá si es o no un triángulo rectángulo.
4. Si no forman un triángulo válido, mostrá el mensaje de error correspondiente.
5. Preguntá si se desea evaluar otro triángulo (`s/n`).

**Pistas didácticas:**
- 1. Desigualdad triangular: cada lado debe ser menor a la suma de los otros dos (a < b + c && b < a + c && c < a + b) y todos mayores a cero.
- 2. Clasificación: Equilátero (tres lados iguales), Isósceles (dos lados iguales) o Escaleno (tres lados distintos).
- 3. Rectángulo: verifica Pitágoras con tolerancia epsilon (fabsf(h*h - (c1*c1 + c2*c2)) < 0.001f) identificando primero cuál es el lado mayor.

#### `ejercicio5 (Desglose de Billetes de Cajero Automático)`

# Ejercicio 5: Desglose de Billetes de Cajero Automático

Implementá un sistema de cajero automático que desglose un importe monetario solicitado en la menor cantidad posible de billetes, empleando las denominaciones de curso legal vigentes.

## Denominaciones Soportadas
$20.000, $10.000, $5.000, $2.000, $1.000, $500, $200 y $100. Denominación mínima: $100.

## Requerimientos
1. En `cajero.c`, implementá:
   - `bool es_monto_valido(int monto);`
   - `int calcular_cantidad_billetes(int monto, int denominacion);`
   - `int calcular_resto_monto(int monto, int denominacion);`
2. En `main.c`, solicitá el monto a extraer.
3. Si el monto es válido ($> 0$ y múltiplo de 100), mostrá el desglose ordenado en forma descendente.
4. Si no es válido, mostrá el mensaje de error indicando las condiciones.
5. Preguntá si se desea realizar otra extracción (`s/n`).

**Pistas didácticas:**
- 1. Para determinar cuántos billetes de un valor facial entregar, usá la división entera monto / denominacion.
- 2. Para calcular el saldo remanente a cubrir con denominaciones menores, usá el operador residuo monto % denominacion.
- 3. Recorré las denominaciones en orden estrictamente descendente: 20000, 10000, 5000, 2000, 1000, 500, 200 y 100.


## Antipatrones Didácticos — Spunkmeyer

Se detectaron **5** observación(es) de antipatrones didácticos:

| Regla | Ubicación | Antipatrón | Diagnóstico | Sugerencia |
| :--- | :--- | :--- | :--- | :--- |
| `0x300Dh` | `ejercicio10.c:15` | **Número mágico literal en condición lógica** | Número mágico '0.0f' utilizado directamente en condición lógica. | Declarale un nombre significativo mediante una constante '#define' o 'enum'. |
| `0x300Dh` | `ejercicio10.c:25` | **Número mágico literal en condición lógica** | Número mágico '0.0f' utilizado directamente en condición lógica. | Declarale un nombre significativo mediante una constante '#define' o 'enum'. |
| `0x3002h` | `fecha.c:12` | **Retorno de puntero a variable local (Dangling Stack Pointer)** | Retorno de dirección de variable local '&var'. | Asigná memoria dinámica con malloc() o pasá el buffer como parámetro por referencia. |
| `0x3002h` | `fecha.c:53` | **Retorno de puntero a variable local (Dangling Stack Pointer)** | Retorno de dirección de variable local '&dia'. | Asigná memoria dinámica con malloc() o pasá el buffer como parámetro por referencia. |
| `0x7001h` | `main.c:17` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |

### 🔍 Detalle Pedagógico de Antipatrones

#### Regla `0x300Dh`: Número mágico literal en condición lógica
- **Ubicación:** `ejercicio10.c:15`
```c
    if (radio < 0.0f)
```
- **Explicación:** Los números mágicos oscurecen el significado del algoritmo e impiden la mantenibilidad del código.
- **Sugerencia:** Declarale un nombre significativo mediante una constante '#define' o 'enum'.
- **Ejemplo incorrecto:**
```c
if (estado == 404) { ... }
```
- **Ejemplo recomendado:**
```c
#define ESTADO_NOT_FOUND 404
if (estado == ESTADO_NOT_FOUND) { ... }
```

#### Regla `0x300Dh`: Número mágico literal en condición lógica
- **Ubicación:** `ejercicio10.c:25`
```c
    if (radio < 0.0f)
```
- **Explicación:** Los números mágicos oscurecen el significado del algoritmo e impiden la mantenibilidad del código.
- **Sugerencia:** Declarale un nombre significativo mediante una constante '#define' o 'enum'.
- **Ejemplo incorrecto:**
```c
if (estado == 404) { ... }
```
- **Ejemplo recomendado:**
```c
#define ESTADO_NOT_FOUND 404
if (estado == ESTADO_NOT_FOUND) { ... }
```

#### Regla `0x3002h`: Retorno de puntero a variable local (Dangling Stack Pointer)
- **Ubicación:** `fecha.c:12`
```c
    return (anio > 0 && (regla_comun || regla_secular));
```
- **Explicación:** Al finalizar la función, su stack frame se destruye. El puntero retornado apuntará a memoria inválida o sobrescribible.
- **Sugerencia:** Asigná memoria dinámica con malloc() o pasá el buffer como parámetro por referencia.
- **Ejemplo incorrecto:**
```c
int* fn(void) {
    int local = 42;
    return &local;
}
```
- **Ejemplo recomendado:**
```c
int* fn(void) {
    int *ptr = malloc(sizeof(*ptr));
    if (ptr) *ptr = 42;
    return ptr;
}
```

#### Regla `0x3002h`: Retorno de puntero a variable local (Dangling Stack Pointer)
- **Ubicación:** `fecha.c:53`
```c
    return (dia >= 1 && dia <= dias_max);
```
- **Explicación:** Al finalizar la función, su stack frame se destruye. El puntero retornado apuntará a memoria inválida o sobrescribible.
- **Sugerencia:** Asigná memoria dinámica con malloc() o pasá el buffer como parámetro por referencia.
- **Ejemplo incorrecto:**
```c
int* fn(void) {
    int local = 42;
    return &local;
}
```
- **Ejemplo recomendado:**
```c
int* fn(void) {
    int *ptr = malloc(sizeof(*ptr));
    if (ptr) *ptr = 42;
    return ptr;
}
```

#### Regla `0x7001h`: Declaración de variable mezclada tras sentencias ejecutables
- **Ubicación:** `main.c:17`
```c
    int clase = clasificar_numero(num);
```
- **Explicación:** En C90 y estilo tradicional de cátedra, las variables deben declararse al inicio del bloque para claridad de dependencias.
- **Sugerencia:** Agrupá las declaraciones al comienzo del bloque de la función.
- **Ejemplo incorrecto:**
```c
int a = 1;
a = a + 5;
int b = 2; // Declaración retrasada
```
- **Ejemplo recomendado:**
```c
int a = 1;
int b = 2;
a = a + 5;
```


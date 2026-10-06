## Antipatrones Didácticos — Spunkmeyer

Se detectaron **53** observación(es) de antipatrones didácticos:

| Regla | Ubicación | Antipatrón | Diagnóstico | Sugerencia |
| :--- | :--- | :--- | :--- | :--- |
| `0x7001h` | `main.c:31` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x3002h` | `fecha.c:12` | **Retorno de puntero a variable local (Dangling Stack Pointer)** | Retorno de dirección de variable local '&var'. | Asigná memoria dinámica con malloc() o pasá el buffer como parámetro por referencia. |
| `0x3002h` | `fecha.c:53` | **Retorno de puntero a variable local (Dangling Stack Pointer)** | Retorno de dirección de variable local '&dia'. | Asigná memoria dinámica con malloc() o pasá el buffer como parámetro por referencia. |
| `0x301Fh` | `prueba.c:58` | **Comparación de igualdad estricta en punto flotante** | Comparación de igualdad estricta ('==') sobre tipo de coma flotante. | Compará con una tolerancia épsilon: 'fabs(a - b) < 0.00001'. |
| `0x301Fh` | `prueba.c:59` | **Comparación de igualdad estricta en punto flotante** | Comparación de igualdad estricta ('==') sobre tipo de coma flotante. | Compará con una tolerancia épsilon: 'fabs(a - b) < 0.00001'. |
| `0x301Fh` | `prueba.c:62` | **Comparación de igualdad estricta en punto flotante** | Comparación de igualdad estricta ('==') sobre tipo de coma flotante. | Compará con una tolerancia épsilon: 'fabs(a - b) < 0.00001'. |
| `0x301Fh` | `prueba.c:63` | **Comparación de igualdad estricta en punto flotante** | Comparación de igualdad estricta ('==') sobre tipo de coma flotante. | Compará con una tolerancia épsilon: 'fabs(a - b) < 0.00001'. |
| `0x301Fh` | `prueba.c:64` | **Comparación de igualdad estricta en punto flotante** | Comparación de igualdad estricta ('==') sobre tipo de coma flotante. | Compará con una tolerancia épsilon: 'fabs(a - b) < 0.00001'. |
| `0x301Fh` | `prueba.c:65` | **Comparación de igualdad estricta en punto flotante** | Comparación de igualdad estricta ('==') sobre tipo de coma flotante. | Compará con una tolerancia épsilon: 'fabs(a - b) < 0.00001'. |
| `0x301Fh` | `prueba.c:66` | **Comparación de igualdad estricta en punto flotante** | Comparación de igualdad estricta ('==') sobre tipo de coma flotante. | Compará con una tolerancia épsilon: 'fabs(a - b) < 0.00001'. |
| `0x301Fh` | `prueba.c:67` | **Comparación de igualdad estricta en punto flotante** | Comparación de igualdad estricta ('==') sobre tipo de coma flotante. | Compará con una tolerancia épsilon: 'fabs(a - b) < 0.00001'. |
| `0x301Fh` | `prueba.c:70` | **Comparación de igualdad estricta en punto flotante** | Comparación de igualdad estricta ('==') sobre tipo de coma flotante. | Compará con una tolerancia épsilon: 'fabs(a - b) < 0.00001'. |
| `0x301Fh` | `prueba.c:71` | **Comparación de igualdad estricta en punto flotante** | Comparación de igualdad estricta ('==') sobre tipo de coma flotante. | Compará con una tolerancia épsilon: 'fabs(a - b) < 0.00001'. |
| `0x301Fh` | `prueba.c:72` | **Comparación de igualdad estricta en punto flotante** | Comparación de igualdad estricta ('==') sobre tipo de coma flotante. | Compará con una tolerancia épsilon: 'fabs(a - b) < 0.00001'. |
| `0x301Fh` | `prueba.c:77` | **Comparación de igualdad estricta en punto flotante** | Comparación de igualdad estricta ('==') sobre tipo de coma flotante. | Compará con una tolerancia épsilon: 'fabs(a - b) < 0.00001'. |
| `0x301Fh` | `prueba.c:78` | **Comparación de igualdad estricta en punto flotante** | Comparación de igualdad estricta ('==') sobre tipo de coma flotante. | Compará con una tolerancia épsilon: 'fabs(a - b) < 0.00001'. |
| `0x301Fh` | `prueba.c:79` | **Comparación de igualdad estricta en punto flotante** | Comparación de igualdad estricta ('==') sobre tipo de coma flotante. | Compará con una tolerancia épsilon: 'fabs(a - b) < 0.00001'. |
| `0x301Fh` | `prueba.c:80` | **Comparación de igualdad estricta en punto flotante** | Comparación de igualdad estricta ('==') sobre tipo de coma flotante. | Compará con una tolerancia épsilon: 'fabs(a - b) < 0.00001'. |
| `0x301Fh` | `prueba.c:81` | **Comparación de igualdad estricta en punto flotante** | Comparación de igualdad estricta ('==') sobre tipo de coma flotante. | Compará con una tolerancia épsilon: 'fabs(a - b) < 0.00001'. |
| `0x7001h` | `cajero.c:26` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `cajero.c:43` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `prueba.c:114` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `prueba.c:152` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `prueba.c:190` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `consola.c:62` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `consola.c:92` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `consola.c:121` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `consola.c:149` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x1005h` | `consola.c:178` | **Comparación booleana explícita redundante** | Comparar explícitamente 'if (cond == 1)' o 'if (cond == true)' es redundante. | Escribí 'if (cond)' o 'if (!cond)' directamente. |
| `0x7001h` | `main.c:31` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x3002h` | `fecha.c:12` | **Retorno de puntero a variable local (Dangling Stack Pointer)** | Retorno de dirección de variable local '&var'. | Asigná memoria dinámica con malloc() o pasá el buffer como parámetro por referencia. |
| `0x3002h` | `fecha.c:53` | **Retorno de puntero a variable local (Dangling Stack Pointer)** | Retorno de dirección de variable local '&dia'. | Asigná memoria dinámica con malloc() o pasá el buffer como parámetro por referencia. |
| `0x301Fh` | `prueba.c:49` | **Comparación de igualdad estricta en punto flotante** | Comparación de igualdad estricta ('==') sobre tipo de coma flotante. | Compará con una tolerancia épsilon: 'fabs(a - b) < 0.00001'. |
| `0x301Fh` | `prueba.c:50` | **Comparación de igualdad estricta en punto flotante** | Comparación de igualdad estricta ('==') sobre tipo de coma flotante. | Compará con una tolerancia épsilon: 'fabs(a - b) < 0.00001'. |
| `0x301Fh` | `prueba.c:53` | **Comparación de igualdad estricta en punto flotante** | Comparación de igualdad estricta ('==') sobre tipo de coma flotante. | Compará con una tolerancia épsilon: 'fabs(a - b) < 0.00001'. |
| `0x301Fh` | `prueba.c:54` | **Comparación de igualdad estricta en punto flotante** | Comparación de igualdad estricta ('==') sobre tipo de coma flotante. | Compará con una tolerancia épsilon: 'fabs(a - b) < 0.00001'. |
| `0x301Fh` | `prueba.c:55` | **Comparación de igualdad estricta en punto flotante** | Comparación de igualdad estricta ('==') sobre tipo de coma flotante. | Compará con una tolerancia épsilon: 'fabs(a - b) < 0.00001'. |
| `0x301Fh` | `prueba.c:56` | **Comparación de igualdad estricta en punto flotante** | Comparación de igualdad estricta ('==') sobre tipo de coma flotante. | Compará con una tolerancia épsilon: 'fabs(a - b) < 0.00001'. |
| `0x301Fh` | `prueba.c:57` | **Comparación de igualdad estricta en punto flotante** | Comparación de igualdad estricta ('==') sobre tipo de coma flotante. | Compará con una tolerancia épsilon: 'fabs(a - b) < 0.00001'. |
| `0x301Fh` | `prueba.c:58` | **Comparación de igualdad estricta en punto flotante** | Comparación de igualdad estricta ('==') sobre tipo de coma flotante. | Compará con una tolerancia épsilon: 'fabs(a - b) < 0.00001'. |
| `0x301Fh` | `prueba.c:61` | **Comparación de igualdad estricta en punto flotante** | Comparación de igualdad estricta ('==') sobre tipo de coma flotante. | Compará con una tolerancia épsilon: 'fabs(a - b) < 0.00001'. |
| `0x301Fh` | `prueba.c:62` | **Comparación de igualdad estricta en punto flotante** | Comparación de igualdad estricta ('==') sobre tipo de coma flotante. | Compará con una tolerancia épsilon: 'fabs(a - b) < 0.00001'. |
| `0x301Fh` | `prueba.c:63` | **Comparación de igualdad estricta en punto flotante** | Comparación de igualdad estricta ('==') sobre tipo de coma flotante. | Compará con una tolerancia épsilon: 'fabs(a - b) < 0.00001'. |
| `0x301Fh` | `prueba.c:68` | **Comparación de igualdad estricta en punto flotante** | Comparación de igualdad estricta ('==') sobre tipo de coma flotante. | Compará con una tolerancia épsilon: 'fabs(a - b) < 0.00001'. |
| `0x301Fh` | `prueba.c:69` | **Comparación de igualdad estricta en punto flotante** | Comparación de igualdad estricta ('==') sobre tipo de coma flotante. | Compará con una tolerancia épsilon: 'fabs(a - b) < 0.00001'. |
| `0x301Fh` | `prueba.c:70` | **Comparación de igualdad estricta en punto flotante** | Comparación de igualdad estricta ('==') sobre tipo de coma flotante. | Compará con una tolerancia épsilon: 'fabs(a - b) < 0.00001'. |
| `0x301Fh` | `prueba.c:71` | **Comparación de igualdad estricta en punto flotante** | Comparación de igualdad estricta ('==') sobre tipo de coma flotante. | Compará con una tolerancia épsilon: 'fabs(a - b) < 0.00001'. |
| `0x301Fh` | `prueba.c:72` | **Comparación de igualdad estricta en punto flotante** | Comparación de igualdad estricta ('==') sobre tipo de coma flotante. | Compará con una tolerancia épsilon: 'fabs(a - b) < 0.00001'. |
| `0x7001h` | `triangulo.c:51` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `prueba.c:114` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `prueba.c:152` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `prueba.c:190` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x1005h` | `consola.c:119` | **Comparación booleana explícita redundante** | Comparar explícitamente 'if (cond == 1)' o 'if (cond == true)' es redundante. | Escribí 'if (cond)' o 'if (!cond)' directamente. |

### 🔍 Detalle Pedagógico de Antipatrones

#### Regla `0x7001h`: Declaración de variable mezclada tras sentencias ejecutables
- **Ubicación:** `main.c:31`
```c
        float acumulador_suma = 0.0f;
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

#### Regla `0x301Fh`: Comparación de igualdad estricta en punto flotante
- **Ubicación:** `prueba.c:58`
```c
    assert(clasificar_triangulo(7.0f, 7.0f, 7.0f) == TIPO_EQUILATERO);
```
- **Explicación:** Por la representación IEEE-754 de precisión finita, los números flotantes rara vez coinciden de forma exacta.
- **Sugerencia:** Compará con una tolerancia épsilon: 'fabs(a - b) < 0.00001'.
- **Ejemplo incorrecto:**
```c
if (f == 0.0f) { ... }
```
- **Ejemplo recomendado:**
```c
if (fabs(f) < 1e-6) { ... }
```

#### Regla `0x301Fh`: Comparación de igualdad estricta en punto flotante
- **Ubicación:** `prueba.c:59`
```c
    assert(clasificar_triangulo(1.5f, 1.5f, 1.5f) == TIPO_EQUILATERO);
```
- **Explicación:** Por la representación IEEE-754 de precisión finita, los números flotantes rara vez coinciden de forma exacta.
- **Sugerencia:** Compará con una tolerancia épsilon: 'fabs(a - b) < 0.00001'.
- **Ejemplo incorrecto:**
```c
if (f == 0.0f) { ... }
```
- **Ejemplo recomendado:**
```c
if (fabs(f) < 1e-6) { ... }
```

#### Regla `0x301Fh`: Comparación de igualdad estricta en punto flotante
- **Ubicación:** `prueba.c:62`
```c
    assert(clasificar_triangulo(5.0f, 5.0f, 3.0f) == TIPO_ISOSCELES);
```
- **Explicación:** Por la representación IEEE-754 de precisión finita, los números flotantes rara vez coinciden de forma exacta.
- **Sugerencia:** Compará con una tolerancia épsilon: 'fabs(a - b) < 0.00001'.
- **Ejemplo incorrecto:**
```c
if (f == 0.0f) { ... }
```
- **Ejemplo recomendado:**
```c
if (fabs(f) < 1e-6) { ... }
```

#### Regla `0x301Fh`: Comparación de igualdad estricta en punto flotante
- **Ubicación:** `prueba.c:63`
```c
    assert(clasificar_triangulo(5.0f, 3.0f, 5.0f) == TIPO_ISOSCELES);
```
- **Explicación:** Por la representación IEEE-754 de precisión finita, los números flotantes rara vez coinciden de forma exacta.
- **Sugerencia:** Compará con una tolerancia épsilon: 'fabs(a - b) < 0.00001'.
- **Ejemplo incorrecto:**
```c
if (f == 0.0f) { ... }
```
- **Ejemplo recomendado:**
```c
if (fabs(f) < 1e-6) { ... }
```

#### Regla `0x301Fh`: Comparación de igualdad estricta en punto flotante
- **Ubicación:** `prueba.c:64`
```c
    assert(clasificar_triangulo(3.0f, 5.0f, 5.0f) == TIPO_ISOSCELES);
```
- **Explicación:** Por la representación IEEE-754 de precisión finita, los números flotantes rara vez coinciden de forma exacta.
- **Sugerencia:** Compará con una tolerancia épsilon: 'fabs(a - b) < 0.00001'.
- **Ejemplo incorrecto:**
```c
if (f == 0.0f) { ... }
```
- **Ejemplo recomendado:**
```c
if (fabs(f) < 1e-6) { ... }
```

#### Regla `0x301Fh`: Comparación de igualdad estricta en punto flotante
- **Ubicación:** `prueba.c:65`
```c
    assert(clasificar_triangulo(10.0f, 10.0f, 6.0f) == TIPO_ISOSCELES);
```
- **Explicación:** Por la representación IEEE-754 de precisión finita, los números flotantes rara vez coinciden de forma exacta.
- **Sugerencia:** Compará con una tolerancia épsilon: 'fabs(a - b) < 0.00001'.
- **Ejemplo incorrecto:**
```c
if (f == 0.0f) { ... }
```
- **Ejemplo recomendado:**
```c
if (fabs(f) < 1e-6) { ... }
```

#### Regla `0x301Fh`: Comparación de igualdad estricta en punto flotante
- **Ubicación:** `prueba.c:66`
```c
    assert(clasificar_triangulo(10.0f, 6.0f, 10.0f) == TIPO_ISOSCELES);
```
- **Explicación:** Por la representación IEEE-754 de precisión finita, los números flotantes rara vez coinciden de forma exacta.
- **Sugerencia:** Compará con una tolerancia épsilon: 'fabs(a - b) < 0.00001'.
- **Ejemplo incorrecto:**
```c
if (f == 0.0f) { ... }
```
- **Ejemplo recomendado:**
```c
if (fabs(f) < 1e-6) { ... }
```

#### Regla `0x301Fh`: Comparación de igualdad estricta en punto flotante
- **Ubicación:** `prueba.c:67`
```c
    assert(clasificar_triangulo(6.0f, 10.0f, 10.0f) == TIPO_ISOSCELES);
```
- **Explicación:** Por la representación IEEE-754 de precisión finita, los números flotantes rara vez coinciden de forma exacta.
- **Sugerencia:** Compará con una tolerancia épsilon: 'fabs(a - b) < 0.00001'.
- **Ejemplo incorrecto:**
```c
if (f == 0.0f) { ... }
```
- **Ejemplo recomendado:**
```c
if (fabs(f) < 1e-6) { ... }
```

#### Regla `0x301Fh`: Comparación de igualdad estricta en punto flotante
- **Ubicación:** `prueba.c:70`
```c
    assert(clasificar_triangulo(4.0f, 5.0f, 6.0f) == TIPO_ESCALENO);
```
- **Explicación:** Por la representación IEEE-754 de precisión finita, los números flotantes rara vez coinciden de forma exacta.
- **Sugerencia:** Compará con una tolerancia épsilon: 'fabs(a - b) < 0.00001'.
- **Ejemplo incorrecto:**
```c
if (f == 0.0f) { ... }
```
- **Ejemplo recomendado:**
```c
if (fabs(f) < 1e-6) { ... }
```

#### Regla `0x301Fh`: Comparación de igualdad estricta en punto flotante
- **Ubicación:** `prueba.c:71`
```c
    assert(clasificar_triangulo(3.0f, 4.0f, 5.0f) == TIPO_ESCALENO);
```
- **Explicación:** Por la representación IEEE-754 de precisión finita, los números flotantes rara vez coinciden de forma exacta.
- **Sugerencia:** Compará con una tolerancia épsilon: 'fabs(a - b) < 0.00001'.
- **Ejemplo incorrecto:**
```c
if (f == 0.0f) { ... }
```
- **Ejemplo recomendado:**
```c
if (fabs(f) < 1e-6) { ... }
```

#### Regla `0x301Fh`: Comparación de igualdad estricta en punto flotante
- **Ubicación:** `prueba.c:72`
```c
    assert(clasificar_triangulo(5.0f, 12.0f, 13.0f) == TIPO_ESCALENO);
```
- **Explicación:** Por la representación IEEE-754 de precisión finita, los números flotantes rara vez coinciden de forma exacta.
- **Sugerencia:** Compará con una tolerancia épsilon: 'fabs(a - b) < 0.00001'.
- **Ejemplo incorrecto:**
```c
if (f == 0.0f) { ... }
```
- **Ejemplo recomendado:**
```c
if (fabs(f) < 1e-6) { ... }
```

#### Regla `0x301Fh`: Comparación de igualdad estricta en punto flotante
- **Ubicación:** `prueba.c:77`
```c
    assert(clasificar_triangulo(1.0f, 1.0f, 5.0f) == TIPO_INVALIDO);
```
- **Explicación:** Por la representación IEEE-754 de precisión finita, los números flotantes rara vez coinciden de forma exacta.
- **Sugerencia:** Compará con una tolerancia épsilon: 'fabs(a - b) < 0.00001'.
- **Ejemplo incorrecto:**
```c
if (f == 0.0f) { ... }
```
- **Ejemplo recomendado:**
```c
if (fabs(f) < 1e-6) { ... }
```

#### Regla `0x301Fh`: Comparación de igualdad estricta en punto flotante
- **Ubicación:** `prueba.c:78`
```c
    assert(clasificar_triangulo(1.0f, 2.0f, 3.0f) == TIPO_INVALIDO);
```
- **Explicación:** Por la representación IEEE-754 de precisión finita, los números flotantes rara vez coinciden de forma exacta.
- **Sugerencia:** Compará con una tolerancia épsilon: 'fabs(a - b) < 0.00001'.
- **Ejemplo incorrecto:**
```c
if (f == 0.0f) { ... }
```
- **Ejemplo recomendado:**
```c
if (fabs(f) < 1e-6) { ... }
```

#### Regla `0x301Fh`: Comparación de igualdad estricta en punto flotante
- **Ubicación:** `prueba.c:79`
```c
    assert(clasificar_triangulo(0.0f, 4.0f, 4.0f) == TIPO_INVALIDO);
```
- **Explicación:** Por la representación IEEE-754 de precisión finita, los números flotantes rara vez coinciden de forma exacta.
- **Sugerencia:** Compará con una tolerancia épsilon: 'fabs(a - b) < 0.00001'.
- **Ejemplo incorrecto:**
```c
if (f == 0.0f) { ... }
```
- **Ejemplo recomendado:**
```c
if (fabs(f) < 1e-6) { ... }
```

#### Regla `0x301Fh`: Comparación de igualdad estricta en punto flotante
- **Ubicación:** `prueba.c:80`
```c
    assert(clasificar_triangulo(-2.0f, 3.0f, 4.0f) == TIPO_INVALIDO);
```
- **Explicación:** Por la representación IEEE-754 de precisión finita, los números flotantes rara vez coinciden de forma exacta.
- **Sugerencia:** Compará con una tolerancia épsilon: 'fabs(a - b) < 0.00001'.
- **Ejemplo incorrecto:**
```c
if (f == 0.0f) { ... }
```
- **Ejemplo recomendado:**
```c
if (fabs(f) < 1e-6) { ... }
```

#### Regla `0x301Fh`: Comparación de igualdad estricta en punto flotante
- **Ubicación:** `prueba.c:81`
```c
    assert(clasificar_triangulo(0.0f, 0.0f, 0.0f) == TIPO_INVALIDO);
```
- **Explicación:** Por la representación IEEE-754 de precisión finita, los números flotantes rara vez coinciden de forma exacta.
- **Sugerencia:** Compará con una tolerancia épsilon: 'fabs(a - b) < 0.00001'.
- **Ejemplo incorrecto:**
```c
if (f == 0.0f) { ... }
```
- **Ejemplo recomendado:**
```c
if (fabs(f) < 1e-6) { ... }
```

#### Regla `0x7001h`: Declaración de variable mezclada tras sentencias ejecutables
- **Ubicación:** `cajero.c:26`
```c
    int cantidad = 0;
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

#### Regla `0x7001h`: Declaración de variable mezclada tras sentencias ejecutables
- **Ubicación:** `cajero.c:43`
```c
    int resto = 0;
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

#### Regla `0x7001h`: Declaración de variable mezclada tras sentencias ejecutables
- **Ubicación:** `prueba.c:114`
```c
    int b10k = calcular_cantidad_billetes(monto, BILLETE_10000);
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

#### Regla `0x7001h`: Declaración de variable mezclada tras sentencias ejecutables
- **Ubicación:** `prueba.c:152`
```c
    int b10k = calcular_cantidad_billetes(monto, BILLETE_10000);
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

#### Regla `0x7001h`: Declaración de variable mezclada tras sentencias ejecutables
- **Ubicación:** `prueba.c:190`
```c
    int b10k = calcular_cantidad_billetes(monto, BILLETE_10000);
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

#### Regla `0x7001h`: Declaración de variable mezclada tras sentencias ejecutables
- **Ubicación:** `consola.c:62`
```c
    int resultado;
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

#### Regla `0x7001h`: Declaración de variable mezclada tras sentencias ejecutables
- **Ubicación:** `consola.c:92`
```c
    bool rango;
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

#### Regla `0x7001h`: Declaración de variable mezclada tras sentencias ejecutables
- **Ubicación:** `consola.c:121`
```c
    float valor;
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

#### Regla `0x7001h`: Declaración de variable mezclada tras sentencias ejecutables
- **Ubicación:** `consola.c:149`
```c
    bool rango;
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

#### Regla `0x1005h`: Comparación booleana explícita redundante
- **Ubicación:** `consola.c:178`
```c
    if (scanf(" %c", &caracter) == 1)
```
- **Explicación:** En C cualquier valor distinto de 0 evalúa a verdadero en estructuras de control.
- **Sugerencia:** Escribí 'if (cond)' o 'if (!cond)' directamente.
- **Ejemplo incorrecto:**
```c
if (es_valido == true) { ... }
```
- **Ejemplo recomendado:**
```c
if (es_valido) { ... }
```

#### Regla `0x7001h`: Declaración de variable mezclada tras sentencias ejecutables
- **Ubicación:** `main.c:31`
```c
        float acumulador_suma = 0.0f;
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

#### Regla `0x301Fh`: Comparación de igualdad estricta en punto flotante
- **Ubicación:** `prueba.c:49`
```c
    assert(clasificar_triangulo(7.0f, 7.0f, 7.0f) == TIPO_EQUILATERO);
```
- **Explicación:** Por la representación IEEE-754 de precisión finita, los números flotantes rara vez coinciden de forma exacta.
- **Sugerencia:** Compará con una tolerancia épsilon: 'fabs(a - b) < 0.00001'.
- **Ejemplo incorrecto:**
```c
if (f == 0.0f) { ... }
```
- **Ejemplo recomendado:**
```c
if (fabs(f) < 1e-6) { ... }
```

#### Regla `0x301Fh`: Comparación de igualdad estricta en punto flotante
- **Ubicación:** `prueba.c:50`
```c
    assert(clasificar_triangulo(1.5f, 1.5f, 1.5f) == TIPO_EQUILATERO);
```
- **Explicación:** Por la representación IEEE-754 de precisión finita, los números flotantes rara vez coinciden de forma exacta.
- **Sugerencia:** Compará con una tolerancia épsilon: 'fabs(a - b) < 0.00001'.
- **Ejemplo incorrecto:**
```c
if (f == 0.0f) { ... }
```
- **Ejemplo recomendado:**
```c
if (fabs(f) < 1e-6) { ... }
```

#### Regla `0x301Fh`: Comparación de igualdad estricta en punto flotante
- **Ubicación:** `prueba.c:53`
```c
    assert(clasificar_triangulo(5.0f, 5.0f, 3.0f) == TIPO_ISOSCELES);
```
- **Explicación:** Por la representación IEEE-754 de precisión finita, los números flotantes rara vez coinciden de forma exacta.
- **Sugerencia:** Compará con una tolerancia épsilon: 'fabs(a - b) < 0.00001'.
- **Ejemplo incorrecto:**
```c
if (f == 0.0f) { ... }
```
- **Ejemplo recomendado:**
```c
if (fabs(f) < 1e-6) { ... }
```

#### Regla `0x301Fh`: Comparación de igualdad estricta en punto flotante
- **Ubicación:** `prueba.c:54`
```c
    assert(clasificar_triangulo(5.0f, 3.0f, 5.0f) == TIPO_ISOSCELES);
```
- **Explicación:** Por la representación IEEE-754 de precisión finita, los números flotantes rara vez coinciden de forma exacta.
- **Sugerencia:** Compará con una tolerancia épsilon: 'fabs(a - b) < 0.00001'.
- **Ejemplo incorrecto:**
```c
if (f == 0.0f) { ... }
```
- **Ejemplo recomendado:**
```c
if (fabs(f) < 1e-6) { ... }
```

#### Regla `0x301Fh`: Comparación de igualdad estricta en punto flotante
- **Ubicación:** `prueba.c:55`
```c
    assert(clasificar_triangulo(3.0f, 5.0f, 5.0f) == TIPO_ISOSCELES);
```
- **Explicación:** Por la representación IEEE-754 de precisión finita, los números flotantes rara vez coinciden de forma exacta.
- **Sugerencia:** Compará con una tolerancia épsilon: 'fabs(a - b) < 0.00001'.
- **Ejemplo incorrecto:**
```c
if (f == 0.0f) { ... }
```
- **Ejemplo recomendado:**
```c
if (fabs(f) < 1e-6) { ... }
```

#### Regla `0x301Fh`: Comparación de igualdad estricta en punto flotante
- **Ubicación:** `prueba.c:56`
```c
    assert(clasificar_triangulo(10.0f, 10.0f, 6.0f) == TIPO_ISOSCELES);
```
- **Explicación:** Por la representación IEEE-754 de precisión finita, los números flotantes rara vez coinciden de forma exacta.
- **Sugerencia:** Compará con una tolerancia épsilon: 'fabs(a - b) < 0.00001'.
- **Ejemplo incorrecto:**
```c
if (f == 0.0f) { ... }
```
- **Ejemplo recomendado:**
```c
if (fabs(f) < 1e-6) { ... }
```

#### Regla `0x301Fh`: Comparación de igualdad estricta en punto flotante
- **Ubicación:** `prueba.c:57`
```c
    assert(clasificar_triangulo(10.0f, 6.0f, 10.0f) == TIPO_ISOSCELES);
```
- **Explicación:** Por la representación IEEE-754 de precisión finita, los números flotantes rara vez coinciden de forma exacta.
- **Sugerencia:** Compará con una tolerancia épsilon: 'fabs(a - b) < 0.00001'.
- **Ejemplo incorrecto:**
```c
if (f == 0.0f) { ... }
```
- **Ejemplo recomendado:**
```c
if (fabs(f) < 1e-6) { ... }
```

#### Regla `0x301Fh`: Comparación de igualdad estricta en punto flotante
- **Ubicación:** `prueba.c:58`
```c
    assert(clasificar_triangulo(6.0f, 10.0f, 10.0f) == TIPO_ISOSCELES);
```
- **Explicación:** Por la representación IEEE-754 de precisión finita, los números flotantes rara vez coinciden de forma exacta.
- **Sugerencia:** Compará con una tolerancia épsilon: 'fabs(a - b) < 0.00001'.
- **Ejemplo incorrecto:**
```c
if (f == 0.0f) { ... }
```
- **Ejemplo recomendado:**
```c
if (fabs(f) < 1e-6) { ... }
```

#### Regla `0x301Fh`: Comparación de igualdad estricta en punto flotante
- **Ubicación:** `prueba.c:61`
```c
    assert(clasificar_triangulo(4.0f, 5.0f, 6.0f) == TIPO_ESCALENO);
```
- **Explicación:** Por la representación IEEE-754 de precisión finita, los números flotantes rara vez coinciden de forma exacta.
- **Sugerencia:** Compará con una tolerancia épsilon: 'fabs(a - b) < 0.00001'.
- **Ejemplo incorrecto:**
```c
if (f == 0.0f) { ... }
```
- **Ejemplo recomendado:**
```c
if (fabs(f) < 1e-6) { ... }
```

#### Regla `0x301Fh`: Comparación de igualdad estricta en punto flotante
- **Ubicación:** `prueba.c:62`
```c
    assert(clasificar_triangulo(3.0f, 4.0f, 5.0f) == TIPO_ESCALENO);
```
- **Explicación:** Por la representación IEEE-754 de precisión finita, los números flotantes rara vez coinciden de forma exacta.
- **Sugerencia:** Compará con una tolerancia épsilon: 'fabs(a - b) < 0.00001'.
- **Ejemplo incorrecto:**
```c
if (f == 0.0f) { ... }
```
- **Ejemplo recomendado:**
```c
if (fabs(f) < 1e-6) { ... }
```

#### Regla `0x301Fh`: Comparación de igualdad estricta en punto flotante
- **Ubicación:** `prueba.c:63`
```c
    assert(clasificar_triangulo(5.0f, 12.0f, 13.0f) == TIPO_ESCALENO);
```
- **Explicación:** Por la representación IEEE-754 de precisión finita, los números flotantes rara vez coinciden de forma exacta.
- **Sugerencia:** Compará con una tolerancia épsilon: 'fabs(a - b) < 0.00001'.
- **Ejemplo incorrecto:**
```c
if (f == 0.0f) { ... }
```
- **Ejemplo recomendado:**
```c
if (fabs(f) < 1e-6) { ... }
```

#### Regla `0x301Fh`: Comparación de igualdad estricta en punto flotante
- **Ubicación:** `prueba.c:68`
```c
    assert(clasificar_triangulo(1.0f, 1.0f, 5.0f) == TIPO_INVALIDO);
```
- **Explicación:** Por la representación IEEE-754 de precisión finita, los números flotantes rara vez coinciden de forma exacta.
- **Sugerencia:** Compará con una tolerancia épsilon: 'fabs(a - b) < 0.00001'.
- **Ejemplo incorrecto:**
```c
if (f == 0.0f) { ... }
```
- **Ejemplo recomendado:**
```c
if (fabs(f) < 1e-6) { ... }
```

#### Regla `0x301Fh`: Comparación de igualdad estricta en punto flotante
- **Ubicación:** `prueba.c:69`
```c
    assert(clasificar_triangulo(1.0f, 2.0f, 3.0f) == TIPO_INVALIDO);
```
- **Explicación:** Por la representación IEEE-754 de precisión finita, los números flotantes rara vez coinciden de forma exacta.
- **Sugerencia:** Compará con una tolerancia épsilon: 'fabs(a - b) < 0.00001'.
- **Ejemplo incorrecto:**
```c
if (f == 0.0f) { ... }
```
- **Ejemplo recomendado:**
```c
if (fabs(f) < 1e-6) { ... }
```

#### Regla `0x301Fh`: Comparación de igualdad estricta en punto flotante
- **Ubicación:** `prueba.c:70`
```c
    assert(clasificar_triangulo(0.0f, 4.0f, 4.0f) == TIPO_INVALIDO);
```
- **Explicación:** Por la representación IEEE-754 de precisión finita, los números flotantes rara vez coinciden de forma exacta.
- **Sugerencia:** Compará con una tolerancia épsilon: 'fabs(a - b) < 0.00001'.
- **Ejemplo incorrecto:**
```c
if (f == 0.0f) { ... }
```
- **Ejemplo recomendado:**
```c
if (fabs(f) < 1e-6) { ... }
```

#### Regla `0x301Fh`: Comparación de igualdad estricta en punto flotante
- **Ubicación:** `prueba.c:71`
```c
    assert(clasificar_triangulo(-2.0f, 3.0f, 4.0f) == TIPO_INVALIDO);
```
- **Explicación:** Por la representación IEEE-754 de precisión finita, los números flotantes rara vez coinciden de forma exacta.
- **Sugerencia:** Compará con una tolerancia épsilon: 'fabs(a - b) < 0.00001'.
- **Ejemplo incorrecto:**
```c
if (f == 0.0f) { ... }
```
- **Ejemplo recomendado:**
```c
if (fabs(f) < 1e-6) { ... }
```

#### Regla `0x301Fh`: Comparación de igualdad estricta en punto flotante
- **Ubicación:** `prueba.c:72`
```c
    assert(clasificar_triangulo(0.0f, 0.0f, 0.0f) == TIPO_INVALIDO);
```
- **Explicación:** Por la representación IEEE-754 de precisión finita, los números flotantes rara vez coinciden de forma exacta.
- **Sugerencia:** Compará con una tolerancia épsilon: 'fabs(a - b) < 0.00001'.
- **Ejemplo incorrecto:**
```c
if (f == 0.0f) { ... }
```
- **Ejemplo recomendado:**
```c
if (fabs(f) < 1e-6) { ... }
```

#### Regla `0x7001h`: Declaración de variable mezclada tras sentencias ejecutables
- **Ubicación:** `triangulo.c:51`
```c
    float a_cuad = lado_a * lado_a;
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

#### Regla `0x7001h`: Declaración de variable mezclada tras sentencias ejecutables
- **Ubicación:** `prueba.c:114`
```c
    int b10k = calcular_cantidad_billetes(monto, BILLETE_10000);
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

#### Regla `0x7001h`: Declaración de variable mezclada tras sentencias ejecutables
- **Ubicación:** `prueba.c:152`
```c
    int b10k = calcular_cantidad_billetes(monto, BILLETE_10000);
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

#### Regla `0x7001h`: Declaración de variable mezclada tras sentencias ejecutables
- **Ubicación:** `prueba.c:190`
```c
    int b10k = calcular_cantidad_billetes(monto, BILLETE_10000);
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

#### Regla `0x1005h`: Comparación booleana explícita redundante
- **Ubicación:** `consola.c:119`
```c
        if (scanf(" %c", &logico) == 1)
```
- **Explicación:** En C cualquier valor distinto de 0 evalúa a verdadero en estructuras de control.
- **Sugerencia:** Escribí 'if (cond)' o 'if (!cond)' directamente.
- **Ejemplo incorrecto:**
```c
if (es_valido == true) { ... }
```
- **Ejemplo recomendado:**
```c
if (es_valido) { ... }
```


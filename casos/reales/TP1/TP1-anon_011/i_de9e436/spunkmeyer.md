## Antipatrones Didácticos — Spunkmeyer

Se detectaron **26** observación(es) de antipatrones didácticos:

| Regla | Ubicación | Antipatrón | Diagnóstico | Sugerencia |
| :--- | :--- | :--- | :--- | :--- |
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
| `0x7001h` | `prueba.c:114` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `prueba.c:152` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `prueba.c:190` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `consola.c:50` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `consola.c:101` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `consola.c:151` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x1008h` | `consola.c:195` | **Caso de switch sin break (Fallthrough no intencional)** | Bloque 'case' sin sentencia 'break' previa al siguiente caso. | Agregá 'break;' al final del caso o documentá explícitamente '// fallthrough'. |

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
- **Ubicación:** `consola.c:50`
```c
    int valor = 0;
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
- **Ubicación:** `consola.c:101`
```c
    float valor = 0;
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
- **Ubicación:** `consola.c:151`
```c
    char valor;
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

#### Regla `0x1008h`: Caso de switch sin break (Fallthrough no intencional)
- **Ubicación:** `consola.c:195`
```c
            default:
```
- **Explicación:** Omitir el 'break' provoca que la ejecución caiga directamente al caso siguiente (fallthrough), usualmente un error no deseado.
- **Sugerencia:** Agregá 'break;' al final del caso o documentá explícitamente '// fallthrough'.
- **Ejemplo incorrecto:**
```c
switch (op) {
case 1:
    hacer_1();
case 2:
    hacer_2();
    break;
}
```
- **Ejemplo recomendado:**
```c
switch (op) {
case 1:
    hacer_1();
    break;
case 2:
    hacer_2();
    break;
}
```


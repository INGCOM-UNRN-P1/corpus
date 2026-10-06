# Informe de Corrección — TP4 (3eaa653)

## Repositorio
**branch/revision:** `main` `3eaa653`
**Commit SHA:** `3eaa653b74e50211f41070662eef547be028aafd`
**Autor:** `anon_013`
**Fecha del commit:** `2026-10-03 18:19:28 -0300`
**Mensaje:** `Completado ejercicio6 y retoques al ejercicio4`
**Fecha de evaluación:** 2026-10-05 07:55:43
**Versión revisada:** `3eaa653`

## Especificación de la Guía
**Guía vinculada:** `Trabajo Práctico 4: Memoria Dinámica en C11 (Sin Structs)`
**Ejercicios requeridos:** `libvector (Biblioteca de Bloques Dinámicos (libvector))`, `libstring (Biblioteca de Cadenas Dinámicas (libstring))`, `ejercicio1 (Clonación y Filtrado Dinámico de Enteros)`, `ejercicio2 (Normalización y Recorte Dinámico de Cadenas)`, `ejercicio3 (Reversión y Particionado Dinámico de Cadenas)`, `ejercicio4 (Bloque Contiguo 2D Simulado en Heap)`, `ejercicio5 (Tokenización y Listas de Cadenas en Heap (char**))`, `ejercicio6 (Procesamiento de Texto Dinámico Multilínea)`

### Archivos contenidos
```text
.
├── ejercicios/
│   ├── ejercicio1/
│   │   ├── main.c
│   │   ├── Makefile
│   │   ├── prueba.c
│   │   ├── vector_enteros.c
│   │   └── vector_enteros.h
│   ├── ejercicio2/
│   │   ├── main.c
│   │   ├── Makefile
│   │   ├── prueba.c
│   │   ├── texto_dinamico.c
│   │   └── texto_dinamico.h
│   ├── ejercicio3/
│   │   ├── cadena_dinamica.c
│   │   ├── cadena_dinamica.h
│   │   ├── main.c
│   │   ├── Makefile
│   │   └── prueba.c
│   ├── ejercicio4/
│   │   ├── main.c
│   │   ├── Makefile
│   │   ├── matriz_dinamica.c
│   │   ├── matriz_dinamica.h
│   │   ├── matriz_invalida.csv
│   │   ├── matriz_valida.csv
│   │   └── prueba.c
│   ├── ejercicio5/
│   │   ├── main.c
│   │   ├── Makefile
│   │   ├── prueba.c
│   │   ├── registro_csv.c
│   │   └── registro_csv.h
│   └── ejercicio6/
│       ├── codigos_error.h
│       ├── codigos_estadistica.h
│       ├── consulta_csv.c
│       ├── consulta_csv.h
│       ├── estadistica.c
│       ├── estadistica.h
│       ├── intercambio.c
│       ├── intercambio.h
│       ├── main.c
│       ├── Makefile
│       ├── matriz_dinamica.c
│       ├── matriz_dinamica.h
│       ├── matriz_filtrada.csv
│       ├── matriz_origen.csv
│       ├── prueba.c
│       ├── recorrido.c
│       ├── recorrido.h
│       ├── registro_csv.c
│       └── registro_csv.h
├── libs/
│   ├── arreglos/
│   │   ├── arreglo.h
│   │   ├── arreglos.c
│   │   ├── arreglos.h
│   │   ├── Makefile
│   │   └── prueba.c
│   ├── p1_test/
│   │   ├── docs/
│   │   │   └── p1_test_manual.md
│   │   ├── include/
│   │   │   ├── p1_arrays.h
│   │   │   ├── p1_files.h
│   │   │   ├── p1_stdio.h
│   │   │   └── p1_test.h
│   │   ├── src/
│   │   │   └── p1_test.c
│   │   ├── library.json
│   │   ├── library.spec
│   │   ├── Makefile
│   │   ├── p1_arrays.h
│   │   ├── p1_files.h
│   │   ├── p1_stdio.h
│   │   ├── p1_test.h
│   │   └── prueba.c
│   ├── punteros/
│   │   ├── Makefile
│   │   ├── prueba.c
│   │   ├── punteros.c
│   │   └── punteros.h
│   ├── string/
│   │   ├── cadenas.c
│   │   ├── cadenas.h
│   │   ├── Makefile
│   │   └── prueba.c
│   └── vector/
│       ├── Makefile
│       ├── prueba.c
│       ├── vector.c
│       └── vector.h
├── Makefile
├── README.md
└── tp.sh
```

## Análisis de Código C e Informes de Herramientas

## Resumen de Evaluación por Archivo

| Archivo | Estado Compilación | Evaluación de Estilo | Valgrind (Fugas) | Observaciones Cátedra |
| :--- | :---: | :---: | :---: | :--- |
| `arreglos.c` | ❌ Falló Compilación | 9.5/10 | ✓ Limpio (0 fugas) | 8 advertencias |
| `cadena_dinamica.c` | ❌ Falló Compilación | 10.0/10 | ✓ Limpio (0 fugas) | 2 advertencias |
| `cadenas.c` | ❌ Falló Compilación | 10.0/10 | ✓ Limpio (0 fugas) | 8 advertencias |
| `consulta_csv.c` | ❌ Falló Compilación | 4.0/10 | ✓ Limpio (0 fugas) | 61 advertencias |
| `consulta_csv.h` | ❌ Falló Compilación | 5.0/10 | ✓ Limpio (0 fugas) | 10 advertencias |
| `estadistica.c` | ❌ Falló Compilación | 7.0/10 | ✓ Limpio (0 fugas) | 13 advertencias |
| `estadistica.h` | ❌ Falló Compilación | 5.0/10 | ✓ Limpio (0 fugas) | 10 advertencias |
| `intercambio.c` | ❌ Falló Compilación | 8.0/10 | ✓ Limpio (0 fugas) | 11 advertencias |
| `intercambio.h` | ❌ Falló Compilación | 5.5/10 | ✓ Limpio (0 fugas) | 9 advertencias |
| `main.c` | ❌ Falló Compilación | 0.0/10 | ✓ Limpio (0 fugas) | 135 advertencias |
| `matriz_dinamica.c` | ❌ Falló Compilación | 0.0/10 | ✓ Limpio (0 fugas) | 124 advertencias |
| `matriz_dinamica.h` | ❌ Falló Compilación | 0.0/10 | ✓ Limpio (0 fugas) | 28 advertencias |
| `prueba.c` | ❌ Falló Compilación | 0.0/10 | ✓ Limpio (0 fugas) | 229 advertencias |
| `punteros.c` | ❌ Falló Compilación | 10.0/10 | ✓ Limpio (0 fugas) | 6 advertencias |
| `recorrido.c` | ❌ Falló Compilación | 8.0/10 | ✓ Limpio (0 fugas) | 8 advertencias |
| `recorrido.h` | ❌ Falló Compilación | 7.0/10 | ✓ Limpio (0 fugas) | 6 advertencias |
| `registro_csv.c` | ❌ Falló Compilación | 1.0/10 | ✓ Limpio (0 fugas) | 42 advertencias |
| `registro_csv.h` | ❌ Falló Compilación | 0.0/10 | ✓ Limpio (0 fugas) | 26 advertencias |
| `texto_dinamico.c` | ❌ Falló Compilación | 10.0/10 | ✓ Limpio (0 fugas) | 7 advertencias |
| `vector.c` | ❌ Falló Compilación | 9.5/10 | ✓ Limpio (0 fugas) | 10 advertencias |
| `vector_enteros.c` | ❌ Falló Compilación | 10.0/10 | ✓ Limpio (0 fugas) | 5 advertencias |

## Compilación — Makefile raíz del Proyecto

❌ **Estado:** Falló la compilación mediante el Makefile de la raíz.

```text
In file included from ../../libs/p1_test/include/p1_arrays.h:13,
                 from prueba.c:9:
prueba.c: In function ‘_p1_test_func_prueba_arreglo_fusionar’:
prueba.c:140:17: warning: ‘destinonull’ is used uninitialized [-Wuninitialized]
  140 |         0, (int)arreglo_fusionar(arreglo1_2, 5, arreglo2_2, 5, destinonull, 6));
      |                 ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
../../libs/p1_test/include/p1_test.h:832:34: note: in definition of macro ‘ASSERT_INT_EQ_MSG’
  832 |     long long _act = (long long)(actual); \
      |                                  ^~~~~~
prueba.c:139:5: note: in expansion of macro ‘ASSERT_INT_EQ’
  139 |     ASSERT_INT_EQ(
      |     ^~~~~~~~~~~~~
prueba.c:138:10: note: ‘destinonull’ was declared here
  138 |     int *destinonull;
      |          ^~~~~~~~~~~
prueba.c:143:17: warning: ‘arreglonull’ is used uninitialized [-Wuninitialized]
  143 |         0, (int)arreglo_fusionar(arreglonull, 5, arreglo2_2, 5, destino_2, 6));
      |                 ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
../../libs/p1_test/include/p1_test.h:832:34: note: in definition of macro ‘ASSERT_INT_EQ_MSG’
  832 |     l
```

> 📄 **Salida completa:** registrada en `compilacion_3eaa653.log`.

## Observaciones de Calidad y Reglas P1 (Linter AST / Ripley)

Se detectaron **471** observación(es) en el código C:

| Regla | Ubicación | Severidad | Observación | Sugerencia |
| :--- | :--- | :---: | :--- | :--- |
| `0x0004h` | `main.c:1` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:15` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:23` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:34` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:37` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:47` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:52` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:64` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:67` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `main.c:72` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0xEEEEh` | `prueba.c:23` | ESTILO | Indentación no es múltiplo de 4 espacios (27 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `prueba.c:69` | ESTILO | Indentación no es múltiplo de 4 espacios (26 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0x0004h` | `prueba.c:1` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:14` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:35` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:55` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `prueba.c:66` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `prueba.c:66` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0xEEEEh` | `vector_enteros.c:27` | ESTILO | Indentación no es múltiplo de 4 espacios (27 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0x0004h` | `vector_enteros.c:1` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `vector_enteros.c:42` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `vector_enteros.c:48` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0018h` | `vector_enteros.c:48` | ESTILO | El asterisco del puntero debe estar junto al identificador (ej. 'int *ptr;'). | Escribir 'tipo *nombre_var' en lugar de 'tipo* nombre_var'. |
| `0x0004h` | `main.c:1` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:15` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:19` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:25` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:26` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `main.c:31` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `main.c:36` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:41` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:48` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:49` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `main.c:54` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0xEEEEh` | `prueba.c:61` | ESTILO | Indentación no es múltiplo de 4 espacios (26 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0x0004h` | `prueba.c:1` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:12` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:19` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:34` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:48` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:55` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `prueba.c:58` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `prueba.c:58` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0xEEEEh` | `texto_dinamico.c:50` | ESTILO | Indentación no es múltiplo de 4 espacios (38 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `texto_dinamico.c:70` | ESTILO | Indentación no es múltiplo de 4 espacios (19 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0x0004h` | `texto_dinamico.c:1` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0018h` | `texto_dinamico.c:59` | ESTILO | El asterisco del puntero debe estar junto al identificador (ej. 'int *ptr;'). | Escribir 'tipo *nombre_var' en lugar de 'tipo* nombre_var'. |
| `0x0018h` | `texto_dinamico.c:61` | ESTILO | El asterisco del puntero debe estar junto al identificador (ej. 'int *ptr;'). | Escribir 'tipo *nombre_var' en lugar de 'tipo* nombre_var'. |
| `0x0018h` | `texto_dinamico.c:69` | ESTILO | El asterisco del puntero debe estar junto al identificador (ej. 'int *ptr;'). | Escribir 'tipo *nombre_var' en lugar de 'tipo* nombre_var'. |
| `0x0018h` | `texto_dinamico.c:70` | ESTILO | El asterisco del puntero debe estar junto al identificador (ej. 'int *ptr;'). | Escribir 'tipo *nombre_var' en lugar de 'tipo* nombre_var'. |
| `0xEEEEh` | `cadena_dinamica.c:31` | ESTILO | Indentación no es múltiplo de 4 espacios (42 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0x0004h` | `cadena_dinamica.c:1` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:1` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:14` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:25` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `main.c:30` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `main.c:35` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:48` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `main.c:53` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0xEEEEh` | `prueba.c:74` | ESTILO | Indentación no es múltiplo de 4 espacios (26 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0x0004h` | `prueba.c:1` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:23` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:30` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:42` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:50` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:57` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:64` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `prueba.c:71` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `prueba.c:71` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:1` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `main.c:10` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `main.c:10` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:16` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:28` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:33` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:40` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `main.c:48` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0002h` | `main.c:53` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `main.c:58` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:65` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:69` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:72` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `main.c:79` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `main.c:84` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:96` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:99` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `main.c:106` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `main.c:111` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `matriz_dinamica.c:1` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `matriz_dinamica.c:8` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `matriz_dinamica.c:8` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0018h` | `matriz_dinamica.c:24` | ESTILO | El asterisco del puntero debe estar junto al identificador (ej. 'int *ptr;'). | Escribir 'tipo *nombre_var' en lugar de 'tipo* nombre_var'. |
| `0x0004h` | `matriz_dinamica.c:32` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0018h` | `matriz_dinamica.c:32` | ESTILO | El asterisco del puntero debe estar junto al identificador (ej. 'int *ptr;'). | Escribir 'tipo *nombre_var' en lugar de 'tipo* nombre_var'. |
| `0x0004h` | `matriz_dinamica.c:35` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0018h` | `matriz_dinamica.c:43` | ESTILO | El asterisco del puntero debe estar junto al identificador (ej. 'int *ptr;'). | Escribir 'tipo *nombre_var' en lugar de 'tipo* nombre_var'. |
| `0x0004h` | `matriz_dinamica.c:48` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `matriz_dinamica.c:55` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `matriz_dinamica.c:55` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `matriz_dinamica.c:56` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `matriz_dinamica.c:60` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `matriz_dinamica.c:67` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `matriz_dinamica.c:68` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `matriz_dinamica.c:76` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `matriz_dinamica.c:80` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `matriz_dinamica.c:84` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `matriz_dinamica.c:86` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `matriz_dinamica.c:95` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `matriz_dinamica.c:104` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `matriz_dinamica.c:106` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `matriz_dinamica.c:116` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `matriz_dinamica.c:119` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `matriz_dinamica.c:119` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `matriz_dinamica.c:123` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `matriz_dinamica.c:147` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `matriz_dinamica.c:154` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `matriz_dinamica.c:161` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `matriz_dinamica.c:168` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `matriz_dinamica.c:180` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `matriz_dinamica.c:236` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:1` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:13` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0005h` | `prueba.c:15` | ESTILO | La llave de apertura para `for` debe estar en una nueva línea. | Ubicar '{' en el renglón siguiente alineada verticalmente. |
| `0x0005h` | `prueba.c:16` | ESTILO | La llave de apertura para `for` debe estar en una nueva línea. | Ubicar '{' en el renglón siguiente alineada verticalmente. |
| `0x0004h` | `prueba.c:24` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:30` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:40` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:42` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:46` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:47` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `prueba.c:55` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0002h` | `prueba.c:58` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `prueba.c:73` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:79` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `prueba.c:81` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `prueba.c:82` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:87` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:88` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:89` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `prueba.c:116` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `prueba.c:116` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:1` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:34` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:43` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:44` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:46` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:50` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:53` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:56` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `main.c:64` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0002h` | `main.c:69` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `main.c:83` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:86` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:89` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `main.c:94` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `prueba.c:1` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:16` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:23` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:32` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:39` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:47` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:68` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:75` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:77` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:81` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:82` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `prueba.c:86` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `prueba.c:86` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `registro_csv.c:1` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `registro_csv.c:3` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `registro_csv.c:8` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `registro_csv.c:8` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `registro_csv.c:41` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `registro_csv.c:45` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `registro_csv.c:54` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `registro_csv.c:58` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `registro_csv.c:68` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `registro_csv.c:89` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `registro_csv.c:98` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `registro_csv.c:100` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `consulta_csv.c:1` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `consulta_csv.c:11` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `consulta_csv.c:18` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `consulta_csv.c:18` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `consulta_csv.c:32` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `consulta_csv.c:40` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `consulta_csv.c:46` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `consulta_csv.c:47` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0002h` | `consulta_csv.c:52` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `consulta_csv.c:60` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `consulta_csv.c:62` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `consulta_csv.c:62` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `consulta_csv.c:63` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `consulta_csv.c:63` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `consulta_csv.c:65` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `consulta_csv.c:87` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `consulta_csv.c:92` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `consulta_csv.c:93` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0018h` | `consulta_csv.c:93` | ESTILO | El asterisco del puntero debe estar junto al identificador (ej. 'int *ptr;'). | Escribir 'tipo *nombre_var' en lugar de 'tipo* nombre_var'. |
| `0x0004h` | `consulta_csv.c:94` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `consulta_csv.c:111` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `consulta_csv.c:111` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `consulta_csv.c:114` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `consulta_csv.c:118` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `consulta_csv.c:119` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `consulta_csv.c:124` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `consulta_csv.c:131` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `consulta_csv.c:137` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `consulta_csv.c:138` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `consulta_csv.c:154` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0018h` | `consulta_csv.c:154` | ESTILO | El asterisco del puntero debe estar junto al identificador (ej. 'int *ptr;'). | Escribir 'tipo *nombre_var' en lugar de 'tipo* nombre_var'. |
| `0x0004h` | `consulta_csv.c:157` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `consulta_csv.c:166` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `consulta_csv.c:173` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `consulta_csv.c:190` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `consulta_csv.c:191` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `consulta_csv.c:195` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `consulta_csv.c:204` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `consulta_csv.c:206` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `consulta_csv.c:206` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `consulta_csv.c:211` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `consulta_csv.c:211` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `consulta_csv.c:215` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `consulta_csv.c:217` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `consulta_csv.c:218` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `consulta_csv.c:218` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `consulta_csv.c:225` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `consulta_csv.c:250` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `consulta_csv.c:257` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `estadistica.c:1` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `estadistica.c:6` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0002h` | `estadistica.c:14` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0002h` | `estadistica.c:37` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `estadistica.c:48` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `estadistica.c:50` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `intercambio.c:1` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `intercambio.c:3` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0002h` | `intercambio.c:8` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `intercambio.c:18` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `intercambio.c:39` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0xEEEEh` | `main.c:44` | ESTILO | Indentación no es múltiplo de 4 espacios (23 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `main.c:45` | ESTILO | Indentación no es múltiplo de 4 espacios (23 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `main.c:46` | ESTILO | Indentación no es múltiplo de 4 espacios (23 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `main.c:47` | ESTILO | Indentación no es múltiplo de 4 espacios (23 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `main.c:48` | ESTILO | Indentación no es múltiplo de 4 espacios (23 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0x0004h` | `main.c:1` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `main.c:13` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `main.c:13` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:19` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:29` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:63` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:74` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:78` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:83` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:88` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:93` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:97` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:99` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `main.c:103` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `main.c:109` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:113` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:115` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `main.c:120` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `main.c:125` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:136` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `main.c:141` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `main.c:150` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `main.c:155` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `main.c:160` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:164` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:168` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:171` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:173` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:175` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:176` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `main.c:184` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `matriz_dinamica.c:1` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `matriz_dinamica.c:8` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `matriz_dinamica.c:8` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0018h` | `matriz_dinamica.c:15` | ESTILO | El asterisco del puntero debe estar junto al identificador (ej. 'int *ptr;'). | Escribir 'tipo *nombre_var' en lugar de 'tipo* nombre_var'. |
| `0x0004h` | `matriz_dinamica.c:21` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0018h` | `matriz_dinamica.c:21` | ESTILO | El asterisco del puntero debe estar junto al identificador (ej. 'int *ptr;'). | Escribir 'tipo *nombre_var' en lugar de 'tipo* nombre_var'. |
| `0x0004h` | `matriz_dinamica.c:24` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0018h` | `matriz_dinamica.c:30` | ESTILO | El asterisco del puntero debe estar junto al identificador (ej. 'int *ptr;'). | Escribir 'tipo *nombre_var' en lugar de 'tipo* nombre_var'. |
| `0x0004h` | `matriz_dinamica.c:35` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `matriz_dinamica.c:42` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `matriz_dinamica.c:42` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `matriz_dinamica.c:43` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `matriz_dinamica.c:47` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `matriz_dinamica.c:54` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `matriz_dinamica.c:55` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `matriz_dinamica.c:63` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `matriz_dinamica.c:67` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `matriz_dinamica.c:71` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `matriz_dinamica.c:73` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `matriz_dinamica.c:82` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `matriz_dinamica.c:91` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `matriz_dinamica.c:93` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `matriz_dinamica.c:103` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `matriz_dinamica.c:106` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `matriz_dinamica.c:106` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `matriz_dinamica.c:110` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `matriz_dinamica.c:134` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `matriz_dinamica.c:141` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `matriz_dinamica.c:148` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `matriz_dinamica.c:155` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `matriz_dinamica.c:167` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `matriz_dinamica.c:210` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0xEEEEh` | `prueba.c:35` | ESTILO | Indentación no es múltiplo de 4 espacios (21 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `prueba.c:36` | ESTILO | Indentación no es múltiplo de 4 espacios (21 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `prueba.c:37` | ESTILO | Indentación no es múltiplo de 4 espacios (21 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0x0004h` | `prueba.c:1` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `prueba.c:16` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `prueba.c:16` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:18` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0018h` | `prueba.c:25` | ESTILO | El asterisco del puntero debe estar junto al identificador (ej. 'int *ptr;'). | Escribir 'tipo *nombre_var' en lugar de 'tipo* nombre_var'. |
| `0x0004h` | `prueba.c:32` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:46` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:47` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:53` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:56` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:59` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:64` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:75` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:85` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:92` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:108` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:111` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:114` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:120` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:121` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:122` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:123` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:127` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:128` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:132` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:133` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:134` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:135` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:136` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:139` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:141` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:145` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:146` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:147` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:148` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:155` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:158` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:161` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:167` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:168` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:169` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:170` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:174` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:175` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:179` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:180` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:181` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:182` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:183` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:187` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:191` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:192` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:193` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:200` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:203` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:211` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:220` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:226` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:236` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:243` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:245` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `prueba.c:249` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `prueba.c:249` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `recorrido.c:1` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `recorrido.c:3` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0002h` | `recorrido.c:8` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `registro_csv.c:1` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `registro_csv.c:3` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `registro_csv.c:8` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `registro_csv.c:8` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `registro_csv.c:41` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `registro_csv.c:45` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `registro_csv.c:54` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `registro_csv.c:58` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `registro_csv.c:68` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `registro_csv.c:89` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `registro_csv.c:98` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `registro_csv.c:100` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0xEEEEh` | `arreglos.c:183` | ESTILO | Indentación no es múltiplo de 4 espacios (11 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0x0004h` | `arreglos.c:1` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `arreglos.c:35` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0002h` | `arreglos.c:113` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0002h` | `arreglos.c:140` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0002h` | `arreglos.c:172` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0xEEEEh` | `prueba.c:107` | ESTILO | Indentación no es múltiplo de 4 espacios (25 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `prueba.c:113` | ESTILO | Indentación no es múltiplo de 4 espacios (25 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `prueba.c:125` | ESTILO | Indentación no es múltiplo de 4 espacios (18 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `prueba.c:159` | ESTILO | Indentación no es múltiplo de 4 espacios (26 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0x0004h` | `prueba.c:1` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:33` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:40` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `prueba.c:156` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `prueba.c:156` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0xEEEEh` | `prueba.c:73` | ESTILO | Indentación no es múltiplo de 4 espacios (26 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0x0004h` | `prueba.c:1` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:17` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:24` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:26` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:30` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:37` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:49` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `prueba.c:70` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `prueba.c:70` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0xEEEEh` | `punteros.c:30` | ESTILO | Indentación no es múltiplo de 4 espacios (21 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0x0004h` | `punteros.c:1` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `punteros.c:9` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0002h` | `punteros.c:29` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `punteros.c:42` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `punteros.c:46` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0xEEEEh` | `cadenas.c:64` | ESTILO | Indentación no es múltiplo de 4 espacios (27 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `cadenas.c:86` | ESTILO | Indentación no es múltiplo de 4 espacios (19 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0x0004h` | `cadenas.c:1` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `cadenas.c:17` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0018h` | `cadenas.c:77` | ESTILO | El asterisco del puntero debe estar junto al identificador (ej. 'int *ptr;'). | Escribir 'tipo *nombre_var' en lugar de 'tipo* nombre_var'. |
| `0x0004h` | `cadenas.c:93` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `cadenas.c:101` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `cadenas.c:114` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0xEEEEh` | `prueba.c:153` | ESTILO | Indentación no es múltiplo de 4 espacios (26 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0x0004h` | `prueba.c:1` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:16` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:30` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:45` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:55` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:62` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:68` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:74` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:80` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:86` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:92` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:98` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:110` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:117` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:123` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:129` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:135` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:143` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `prueba.c:150` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `prueba.c:150` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0xEEEEh` | `prueba.c:108` | ESTILO | Indentación no es múltiplo de 4 espacios (26 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0x0004h` | `prueba.c:1` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:25` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:31` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:52` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:65` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:72` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:83` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:89` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:90` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:94` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:101` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `prueba.c:105` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `prueba.c:105` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0xEEEEh` | `vector.c:57` | ESTILO | Indentación no es múltiplo de 4 espacios (30 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `vector.c:86` | ESTILO | Indentación no es múltiplo de 4 espacios (31 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0x0004h` | `vector.c:1` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `vector.c:19` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `vector.c:27` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `vector.c:85` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `vector.c:92` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `vector.c:100` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |

## Pruebas del Proyecto — Makefile raíz (`make test`)

❌ **Estado:** Fallaron las pruebas del proyecto (`make test`).

```text
make: Entering directory '/home/mrtin/dev/p1/ripley/entregas/TP4/TP4-anon_013/repo'
Compilando librería en libs/arreglos...
make[1]: Entering directory '/home/mrtin/dev/p1/ripley/entregas/TP4/TP4-anon_013/repo/libs/arreglos'
make[1]: Nothing to be done for 'all'.
make[1]: Leaving directory '/home/mrtin/dev/p1/ripley/entregas/TP4/TP4-anon_013/repo/libs/arreglos'
Compilando librería en libs/p1_test...
make[1]: Entering directory '/home/mrtin/dev/p1/ripley/entregas/TP4/TP4-anon_013/repo/libs/p1_test'
make[1]: Nothing to be done for 'all'.
make[1]: Leaving directory '/home/mrtin/dev/p1/ripley/entregas/TP4
```

## Auditoría de Memoria Dinámica — Valgrind

✓ **Estado:** No se detectaron fugas de memoria durante las pruebas en sandbox.

## Linter de Estilo y Formato — Gaff

⚠️ Se detectaron **267** observación(es) de estilo arquitectónico:

| Regla | Ubicación | Observación | Sugerencia | Autofix |
| :--- | :--- | :--- | :--- | :---: |
| `GAFF009` | `main.c:13` | La línea tiene 116 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `main.c:45` | La línea tiene 116 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `main.c:13` | La línea tiene 116 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `main.c:34` | La línea tiene 116 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `0x0001h` | `prueba.c:45` | Identificador corto y poco expresivo 'rep' (3 caracteres). | Se recomienda utilizar identificadores más descriptivos del dominio del problema. | No |
| `GAFF009` | `main.c:12` | La línea tiene 116 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `main.c:33` | La línea tiene 116 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `main.c:26` | La línea tiene 116 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `main.c:37` | La línea tiene 86 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `main.c:44` | La línea tiene 83 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `main.c:56` | La línea tiene 116 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `main.c:69` | La línea tiene 99 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `main.c:75` | La línea tiene 83 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `main.c:84` | La línea tiene 81 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `main.c:96` | La línea tiene 99 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `main.c:102` | La línea tiene 83 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `main.c:111` | La línea tiene 81 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `matriz_dinamica.c:48` | La línea tiene 85 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `matriz_dinamica.c:55` | La línea tiene 92 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `matriz_dinamica.c:56` | La línea tiene 93 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `matriz_dinamica.c:73` | La línea tiene 101 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `matriz_dinamica.c:77` | La línea tiene 86 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `matriz_dinamica.c:86` | La línea tiene 107 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `matriz_dinamica.c:96` | La línea tiene 89 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `matriz_dinamica.c:117` | La línea tiene 88 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `matriz_dinamica.c:118` | La línea tiene 87 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `matriz_dinamica.c:122` | La línea tiene 88 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `matriz_dinamica.c:123` | La línea tiene 88 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `matriz_dinamica.c:133` | La línea tiene 85 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `matriz_dinamica.c:134` | La línea tiene 81 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `matriz_dinamica.c:136` | La línea tiene 86 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `matriz_dinamica.c:145` | La línea tiene 89 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `matriz_dinamica.c:147` | La línea tiene 137 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `matriz_dinamica.c:152` | La línea tiene 104 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `matriz_dinamica.c:154` | La línea tiene 129 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `matriz_dinamica.c:159` | La línea tiene 102 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `matriz_dinamica.c:161` | La línea tiene 145 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `matriz_dinamica.c:168` | La línea tiene 96 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `matriz_dinamica.c:180` | La línea tiene 93 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `matriz_dinamica.c:210` | La línea tiene 87 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `matriz_dinamica.c:211` | La línea tiene 84 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `matriz_dinamica.c:235` | La línea tiene 83 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `matriz_dinamica.c:245` | La línea tiene 81 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `matriz_dinamica.c:253` | La línea tiene 96 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `matriz_dinamica.c:257` | La línea tiene 102 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `0x0001h` | `matriz_dinamica.c:131` | Identificador corto y poco expresivo 'fin' (3 caracteres). | Se recomienda utilizar identificadores más descriptivos del dominio del problema. | No |
| `GAFF009` | `matriz_dinamica.h:35` | La línea tiene 82 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `matriz_dinamica.h:38` | La línea tiene 83 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `matriz_dinamica.h:39` | La línea tiene 86 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `matriz_dinamica.h:46` | La línea tiene 86 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `matriz_dinamica.h:52` | La línea tiene 85 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `matriz_dinamica.h:53` | La línea tiene 85 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `matriz_dinamica.h:66` | La línea tiene 84 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `matriz_dinamica.h:71` | La línea tiene 88 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `matriz_dinamica.h:81` | La línea tiene 81 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `matriz_dinamica.h:84` | La línea tiene 90 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `matriz_dinamica.h:86` | La línea tiene 96 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `matriz_dinamica.h:90` | La línea tiene 82 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `matriz_dinamica.h:92` | La línea tiene 87 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `matriz_dinamica.h:95` | La línea tiene 94 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `prueba.c:20` | La línea tiene 106 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `prueba.c:21` | La línea tiene 90 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `prueba.c:55` | La línea tiene 91 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `prueba.c:58` | La línea tiene 101 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `prueba.c:108` | La línea tiene 87 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `prueba.c:118` | La línea tiene 84 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `0x0001h` | `prueba.c:73` | Identificador de variable no descriptivo de una sola letra 'm'. | Los nombres de variables deben reflejar con precisión su propósito (salvo índices canónicos i, j, k, n, x, y, z, f, c, r). | No |
| `GAFF009` | `main.c:32` | La línea tiene 116 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `main.c:46` | La línea tiene 84 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `main.c:60` | La línea tiene 89 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `main.c:69` | La línea tiene 92 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `main.c:72` | La línea tiene 116 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `main.c:94` | La línea tiene 96 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `prueba.c:16` | La línea tiene 94 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `prueba.c:27` | La línea tiene 86 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `prueba.c:42` | La línea tiene 89 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `prueba.c:88` | La línea tiene 84 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `registro_csv.c:3` | La línea tiene 90 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `registro_csv.c:8` | La línea tiene 99 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `registro_csv.c:10` | La línea tiene 100 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `registro_csv.c:47` | La línea tiene 135 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `registro_csv.c:49` | La línea tiene 100 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `registro_csv.c:54` | La línea tiene 118 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `registro_csv.c:58` | La línea tiene 124 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `registro_csv.c:64` | La línea tiene 143 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `registro_csv.c:68` | La línea tiene 128 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `registro_csv.h:38` | La línea tiene 92 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `registro_csv.h:39` | La línea tiene 100 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `registro_csv.h:40` | La línea tiene 97 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `registro_csv.h:47` | La línea tiene 98 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `registro_csv.h:48` | La línea tiene 92 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `registro_csv.h:50` | La línea tiene 97 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `registro_csv.h:51` | La línea tiene 95 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `registro_csv.h:54` | La línea tiene 92 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `registro_csv.h:56` | La línea tiene 102 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `registro_csv.h:59` | La línea tiene 100 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `registro_csv.h:62` | La línea tiene 97 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `registro_csv.h:63` | La línea tiene 96 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `registro_csv.h:68` | La línea tiene 89 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `consulta_csv.c:5` | La línea tiene 88 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `consulta_csv.c:63` | La línea tiene 87 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `consulta_csv.c:65` | La línea tiene 83 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `consulta_csv.c:72` | La línea tiene 100 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `consulta_csv.c:87` | La línea tiene 88 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `consulta_csv.c:111` | La línea tiene 86 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `consulta_csv.c:119` | La línea tiene 85 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `consulta_csv.c:193` | La línea tiene 85 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `consulta_csv.c:208` | La línea tiene 84 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `consulta_csv.c:213` | La línea tiene 88 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `consulta_csv.c:218` | La línea tiene 87 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `consulta_csv.c:255` | La línea tiene 82 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `consulta_csv.h:27` | La línea tiene 97 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `consulta_csv.h:29` | La línea tiene 92 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `consulta_csv.h:31` | La línea tiene 84 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `consulta_csv.h:34` | La línea tiene 83 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `consulta_csv.h:72` | La línea tiene 83 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `consulta_csv.h:76` | La línea tiene 87 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `consulta_csv.h:78` | La línea tiene 84 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `consulta_csv.h:82` | La línea tiene 88 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `consulta_csv.h:99` | La línea tiene 84 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `consulta_csv.h:120` | La línea tiene 88 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `estadistica.c:12` | La línea tiene 86 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `estadistica.c:14` | La línea tiene 107 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `estadistica.c:16` | La línea tiene 97 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `estadistica.c:37` | La línea tiene 112 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `estadistica.c:50` | La línea tiene 153 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `0x0001h` | `estadistica.c:26` | Identificador corto y poco expresivo 'fin' (3 caracteres). | Se recomienda utilizar identificadores más descriptivos del dominio del problema. | No |
| `GAFF009` | `estadistica.h:12` | La línea tiene 82 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `estadistica.h:25` | La línea tiene 83 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `estadistica.h:27` | La línea tiene 82 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `estadistica.h:31` | La línea tiene 85 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `estadistica.h:42` | La línea tiene 83 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `estadistica.h:44` | La línea tiene 85 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `estadistica.h:45` | La línea tiene 81 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `estadistica.h:50` | La línea tiene 108 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `estadistica.h:53` | La línea tiene 81 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `estadistica.h:67` | La línea tiene 113 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `intercambio.c:3` | La línea tiene 84 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `intercambio.c:8` | La línea tiene 90 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `0x0001h` | `intercambio.c:25` | Identificador de variable no descriptivo de una sola letra 'a'. | Los nombres de variables deben reflejar con precisión su propósito (salvo índices canónicos i, j, k, n, x, y, z, f, c, r). | No |
| `0x0001h` | `intercambio.c:25` | Identificador de variable no descriptivo de una sola letra 'b'. | Los nombres de variables deben reflejar con precisión su propósito (salvo índices canónicos i, j, k, n, x, y, z, f, c, r). | No |
| `GAFF009` | `intercambio.h:19` | La línea tiene 84 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `intercambio.h:22` | La línea tiene 92 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `intercambio.h:26` | La línea tiene 89 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `intercambio.h:29` | La línea tiene 81 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `intercambio.h:30` | La línea tiene 81 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `intercambio.h:39` | La línea tiene 83 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `intercambio.h:49` | La línea tiene 89 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `0x0001h` | `intercambio.h:59` | Identificador de variable no descriptivo de una sola letra 'a'. | Los nombres de variables deben reflejar con precisión su propósito (salvo índices canónicos i, j, k, n, x, y, z, f, c, r). | No |
| `0x0001h` | `intercambio.h:59` | Identificador de variable no descriptivo de una sola letra 'b'. | Los nombres de variables deben reflejar con precisión su propósito (salvo índices canónicos i, j, k, n, x, y, z, f, c, r). | No |
| `GAFF009` | `main.c:34` | La línea tiene 82 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `main.c:61` | La línea tiene 116 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `main.c:78` | La línea tiene 104 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `main.c:83` | La línea tiene 87 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `main.c:86` | La línea tiene 116 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `main.c:93` | La línea tiene 115 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `main.c:97` | La línea tiene 102 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `main.c:99` | La línea tiene 86 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `main.c:109` | La línea tiene 113 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `main.c:113` | La línea tiene 98 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `main.c:123` | La línea tiene 116 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `main.c:130` | La línea tiene 85 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `main.c:144` | La línea tiene 92 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `main.c:158` | La línea tiene 116 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `main.c:162` | La línea tiene 86 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `main.c:180` | La línea tiene 84 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `matriz_dinamica.c:35` | La línea tiene 85 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `matriz_dinamica.c:42` | La línea tiene 92 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `matriz_dinamica.c:43` | La línea tiene 93 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `matriz_dinamica.c:60` | La línea tiene 101 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `matriz_dinamica.c:64` | La línea tiene 86 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `matriz_dinamica.c:73` | La línea tiene 107 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `matriz_dinamica.c:83` | La línea tiene 89 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `matriz_dinamica.c:104` | La línea tiene 88 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `matriz_dinamica.c:105` | La línea tiene 87 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `matriz_dinamica.c:109` | La línea tiene 88 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `matriz_dinamica.c:110` | La línea tiene 88 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `matriz_dinamica.c:120` | La línea tiene 85 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `matriz_dinamica.c:121` | La línea tiene 81 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `matriz_dinamica.c:123` | La línea tiene 86 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `matriz_dinamica.c:132` | La línea tiene 89 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `matriz_dinamica.c:134` | La línea tiene 137 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `matriz_dinamica.c:139` | La línea tiene 104 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `matriz_dinamica.c:141` | La línea tiene 129 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `matriz_dinamica.c:146` | La línea tiene 102 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `matriz_dinamica.c:148` | La línea tiene 145 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `matriz_dinamica.c:155` | La línea tiene 96 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `matriz_dinamica.c:167` | La línea tiene 81 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `matriz_dinamica.c:186` | La línea tiene 87 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `matriz_dinamica.c:187` | La línea tiene 84 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `matriz_dinamica.c:209` | La línea tiene 83 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `matriz_dinamica.c:217` | La línea tiene 81 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `matriz_dinamica.c:225` | La línea tiene 96 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `matriz_dinamica.c:229` | La línea tiene 102 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `0x0001h` | `matriz_dinamica.c:118` | Identificador corto y poco expresivo 'fin' (3 caracteres). | Se recomienda utilizar identificadores más descriptivos del dominio del problema. | No |
| `GAFF009` | `matriz_dinamica.h:26` | La línea tiene 82 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `matriz_dinamica.h:29` | La línea tiene 83 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `matriz_dinamica.h:30` | La línea tiene 86 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `matriz_dinamica.h:37` | La línea tiene 86 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `matriz_dinamica.h:43` | La línea tiene 85 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `matriz_dinamica.h:44` | La línea tiene 85 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `matriz_dinamica.h:57` | La línea tiene 84 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `matriz_dinamica.h:62` | La línea tiene 88 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `matriz_dinamica.h:72` | La línea tiene 81 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `matriz_dinamica.h:75` | La línea tiene 90 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `matriz_dinamica.h:77` | La línea tiene 96 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `matriz_dinamica.h:81` | La línea tiene 82 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `matriz_dinamica.h:83` | La línea tiene 87 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `matriz_dinamica.h:86` | La línea tiene 82 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `prueba.c:52` | La línea tiene 88 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `prueba.c:64` | La línea tiene 95 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `prueba.c:79` | La línea tiene 90 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `prueba.c:88` | La línea tiene 88 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `prueba.c:96` | La línea tiene 97 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `prueba.c:101` | La línea tiene 122 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `prueba.c:103` | La línea tiene 94 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `prueba.c:104` | La línea tiene 94 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `prueba.c:105` | La línea tiene 94 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `prueba.c:106` | La línea tiene 82 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `prueba.c:221` | La línea tiene 85 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `prueba.c:234` | La línea tiene 97 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `prueba.c:243` | La línea tiene 86 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `prueba.c:251` | La línea tiene 84 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `recorrido.c:3` | La línea tiene 84 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `recorrido.c:8` | La línea tiene 137 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `recorrido.c:27` | La línea tiene 112 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `0x0001h` | `recorrido.c:48` | Identificador corto y poco expresivo 'fin' (3 caracteres). | Se recomienda utilizar identificadores más descriptivos del dominio del problema. | No |
| `GAFF009` | `recorrido.h:16` | La línea tiene 81 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `recorrido.h:19` | La línea tiene 86 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `recorrido.h:24` | La línea tiene 81 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `recorrido.h:27` | La línea tiene 87 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `recorrido.h:43` | La línea tiene 138 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `recorrido.h:47` | La línea tiene 83 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `registro_csv.c:3` | La línea tiene 90 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `registro_csv.c:8` | La línea tiene 99 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `registro_csv.c:10` | La línea tiene 100 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `registro_csv.c:47` | La línea tiene 135 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `registro_csv.c:49` | La línea tiene 100 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `registro_csv.c:54` | La línea tiene 118 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `registro_csv.c:58` | La línea tiene 124 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `registro_csv.c:64` | La línea tiene 143 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `registro_csv.c:68` | La línea tiene 128 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `registro_csv.h:38` | La línea tiene 92 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `registro_csv.h:39` | La línea tiene 100 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `registro_csv.h:40` | La línea tiene 97 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `registro_csv.h:47` | La línea tiene 98 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `registro_csv.h:48` | La línea tiene 92 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `registro_csv.h:50` | La línea tiene 97 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `registro_csv.h:51` | La línea tiene 95 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `registro_csv.h:54` | La línea tiene 92 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `registro_csv.h:56` | La línea tiene 102 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `registro_csv.h:59` | La línea tiene 100 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `registro_csv.h:62` | La línea tiene 97 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `registro_csv.h:63` | La línea tiene 96 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `registro_csv.h:68` | La línea tiene 89 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `0x0001h` | `arreglos.c:74` | Identificador corto y poco expresivo 'fin' (3 caracteres). | Se recomienda utilizar identificadores más descriptivos del dominio del problema. | No |
| `0x0001h` | `prueba.c:52` | Identificador corto y poco expresivo 'par' (3 caracteres). | Se recomienda utilizar identificadores más descriptivos del dominio del problema. | No |
| `0x0001h` | `prueba.c:22` | Identificador de variable no descriptivo de una sola letra 'a'. | Los nombres de variables deben reflejar con precisión su propósito (salvo índices canónicos i, j, k, n, x, y, z, f, c, r). | No |
| `0x0001h` | `prueba.c:23` | Identificador de variable no descriptivo de una sola letra 'b'. | Los nombres de variables deben reflejar con precisión su propósito (salvo índices canónicos i, j, k, n, x, y, z, f, c, r). | No |
| `0x0001h` | `prueba.c:34` | Identificador corto y poco expresivo 'val' (3 caracteres). | Se recomienda utilizar identificadores más descriptivos del dominio del problema. | No |
| `0x0001h` | `prueba.c:13` | Identificador corto y poco expresivo 'dup' (3 caracteres). | Se recomienda utilizar identificadores más descriptivos del dominio del problema. | No |
| `0x0001h` | `prueba.c:41` | Identificador corto y poco expresivo 'ptr' (3 caracteres). | Se recomienda utilizar identificadores más descriptivos del dominio del problema. | No |
| `0x0001h` | `prueba.c:52` | Identificador corto y poco expresivo 'sub' (3 caracteres). | Se recomienda utilizar identificadores más descriptivos del dominio del problema. | No |
| `0x0001h` | `prueba.c:107` | Identificador corto y poco expresivo 'inv' (3 caracteres). | Se recomienda utilizar identificadores más descriptivos del dominio del problema. | No |
| `0x0001h` | `prueba.c:59` | Identificador de variable no descriptivo de una sola letra 'a'. | Los nombres de variables deben reflejar con precisión su propósito (salvo índices canónicos i, j, k, n, x, y, z, f, c, r). | No |
| `0x0001h` | `prueba.c:60` | Identificador de variable no descriptivo de una sola letra 'b'. | Los nombres de variables deben reflejar con precisión su propósito (salvo índices canónicos i, j, k, n, x, y, z, f, c, r). | No |
| `0x0001h` | `vector.c:15` | Identificador corto y poco expresivo 'ptr' (3 caracteres). | Se recomienda utilizar identificadores más descriptivos del dominio del problema. | No |

## Auditoría de Seguridad — Sandbox / Kaneda

✓ **Estado:** Código libre de llamadas del sistema restringidas o intentos de evasión de sandbox.

## Antipatrones Didácticos — Spunkmeyer

Se detectaron **110** observación(es) de antipatrones didácticos:

| Regla | Ubicación | Antipatrón | Diagnóstico | Sugerencia |
| :--- | :--- | :--- | :--- | :--- |
| `0x7001h` | `main.c:17` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `prueba.c:28` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `prueba.c:46` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `vector_enteros.c:17` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `vector_enteros.c:54` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `main.c:17` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `prueba.c:31` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `prueba.c:45` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `texto_dinamico.c:15` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `cadena_dinamica.c:15` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `cadena_dinamica.c:27` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `main.c:16` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `prueba.c:17` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `prueba.c:39` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `main.c:30` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `matriz_dinamica.c:24` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x3002h` | `matriz_dinamica.c:56` | **Puntero colgante sin asignar NULL tras free()** | Puntero 'matriz' liberado con free() pero no anulado con NULL posteriormente. | Asigná 'ptr = NULL;' inmediatamente después de 'free(ptr);'. |
| `0x7001h` | `matriz_dinamica.c:168` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `matriz_dinamica.c:196` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `prueba.c:13` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `prueba.c:40` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `prueba.c:73` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `main.c:38` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `prueba.c:16` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `prueba.c:74` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `registro_csv.c:54` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `consulta_csv.c:79` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `consulta_csv.c:146` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `consulta_csv.c:226` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x1005h` | `consulta_csv.c:255` | **Comparación booleana explícita redundante** | Comparar explícitamente 'if (cond == 1)' o 'if (cond == true)' es redundante. | Escribí 'if (cond)' o 'if (!cond)' directamente. |
| `0x7001h` | `estadistica.c:24` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `main.c:43` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `main.c:71` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `matriz_dinamica.c:15` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x3002h` | `matriz_dinamica.c:43` | **Puntero colgante sin asignar NULL tras free()** | Puntero 'matriz' liberado con free() pero no anulado con NULL posteriormente. | Asigná 'ptr = NULL;' inmediatamente después de 'free(ptr);'. |
| `0x7001h` | `matriz_dinamica.c:155` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `matriz_dinamica.c:174` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `prueba.c:61` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `prueba.c:118` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `prueba.c:165` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `prueba.c:209` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x4001h` | `prueba.c:222` | **Omisión de verificación de retorno NULL en fopen()** | Uso de descriptor de archivo 'archivo' devuelto por fopen() en línea 215 sin comprobación previa de NULL. | Verificá siempre 'if (f == NULL)' inmediatamente después de invocar 'fopen()'. |
| `0x4001h` | `prueba.c:235` | **Omisión de verificación de retorno NULL en fopen()** | Uso de descriptor de archivo 'archivo' devuelto por fopen() en línea 230 sin comprobación previa de NULL. | Verificá siempre 'if (f == NULL)' inmediatamente después de invocar 'fopen()'. |
| `0x200Ah` | `recorrido.c:8` | **Función con excesiva cantidad de parámetros (> 5)** | Función 'copiar_arreglo' declara 6 parámetros (máximo recomendado: 5). | Agrupá los parámetros relacionados en una estructura 'struct params_t'. |
| `0x1005h` | `recorrido.c:10` | **Comparación entre tipos enteros con y sin signo en condición** | Comparación entre tipos con signo ('int') y sin signo ('size_t') entre 'inicio' y 'cantidad_origen'. | Utilizá tipos consistentes (ambos 'size_t' o casteá de forma controlada tras verificar que i >= 0). |
| `0x7001h` | `recorrido.c:14` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `recorrido.c:47` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `registro_csv.c:54` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x1005h` | `arreglos.c:52` | **Comparación booleana explícita redundante** | Comparar explícitamente 'if (cond == 1)' o 'if (cond == true)' es redundante. | Escribí 'if (cond)' o 'if (!cond)' directamente. |
| `0x7001h` | `arreglos.c:73` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `arreglos.c:94` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `arreglos.c:119` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `arreglos.c:146` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x200Ah` | `arreglos.c:171` | **Función con excesiva cantidad de parámetros (> 5)** | Función 'arreglo_fusionar' declara 6 parámetros (máximo recomendado: 5). | Agrupá los parámetros relacionados en una estructura 'struct params_t'. |
| `0x7001h` | `arreglos.c:179` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `prueba.c:20` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `prueba.c:46` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `prueba.c:62` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `prueba.c:83` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `prueba.c:104` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x300Bh` | `prueba.c:107` | **Pointer decay en sizeof de arreglo parámetro** | Pointer decay al usar sizeof sobre el parámetro 'arreglo'. | Pasá la cantidad de elementos explícitamente como un parámetro adicional 'size_t n'. |
| `0x7001h` | `prueba.c:128` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x200Ah` | `p1_arrays.h:36` | **Función con excesiva cantidad de parámetros (> 5)** | Función '_p1_fail_array_double' declara 9 parámetros (máximo recomendado: 5). | Agrupá los parámetros relacionados en una estructura 'struct params_t'. |
| `0x200Ah` | `p1_arrays.h:54` | **Función con excesiva cantidad de parámetros (> 5)** | Función '_p1_fail_array_sorted' declara 8 parámetros (máximo recomendado: 5). | Agrupá los parámetros relacionados en una estructura 'struct params_t'. |
| `0x200Ah` | `p1_arrays.h:73` | **Función con excesiva cantidad de parámetros (> 5)** | Función '_p1_fail_str_array' declara 7 parámetros (máximo recomendado: 5). | Agrupá los parámetros relacionados en una estructura 'struct params_t'. |
| `0x200Ah` | `p1_arrays.h:93` | **Función con excesiva cantidad de parámetros (> 5)** | Función '_p1_fail_array_contains' declara 6 parámetros (máximo recomendado: 5). | Agrupá los parámetros relacionados en una estructura 'struct params_t'. |
| `0x200Ah` | `p1_files.h:21` | **Función con excesiva cantidad de parámetros (> 5)** | Función '_p1_fail_file_exists' declara 6 parámetros (máximo recomendado: 5). | Agrupá los parámetros relacionados en una estructura 'struct params_t'. |
| `0x200Ah` | `p1_files.h:40` | **Función con excesiva cantidad de parámetros (> 5)** | Función '_p1_fail_file_line' declara 7 parámetros (máximo recomendado: 5). | Agrupá los parámetros relacionados en una estructura 'struct params_t'. |
| `0x200Ah` | `p1_files.h:58` | **Función con excesiva cantidad de parámetros (> 5)** | Función '_p1_fail_file_contains' declara 6 parámetros (máximo recomendado: 5). | Agrupá los parámetros relacionados en una estructura 'struct params_t'. |
| `0x200Ah` | `p1_files.h:74` | **Función con excesiva cantidad de parámetros (> 5)** | Función '_p1_fail_file_bin' declara 7 parámetros (máximo recomendado: 5). | Agrupá los parámetros relacionados en una estructura 'struct params_t'. |
| `0x7001h` | `p1_stdio.h:133` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `p1_stdio.h:175` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `p1_test.h:132` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x200Ah` | `p1_test.h:216` | **Función con excesiva cantidad de parámetros (> 5)** | Función '_p1_fail_int' declara 7 parámetros (máximo recomendado: 5). | Agrupá los parámetros relacionados en una estructura 'struct params_t'. |
| `0x200Ah` | `p1_test.h:233` | **Función con excesiva cantidad de parámetros (> 5)** | Función '_p1_fail_int_between' declara 7 parámetros (máximo recomendado: 5). | Agrupá los parámetros relacionados en una estructura 'struct params_t'. |
| `0x200Ah` | `p1_test.h:250` | **Función con excesiva cantidad de parámetros (> 5)** | Función '_p1_fail_uint' declara 7 parámetros (máximo recomendado: 5). | Agrupá los parámetros relacionados en una estructura 'struct params_t'. |
| `0x200Ah` | `p1_test.h:267` | **Función con excesiva cantidad de parámetros (> 5)** | Función '_p1_fail_double' declara 7 parámetros (máximo recomendado: 5). | Agrupá los parámetros relacionados en una estructura 'struct params_t'. |
| `0x200Ah` | `p1_test.h:284` | **Función con excesiva cantidad de parámetros (> 5)** | Función '_p1_fail_double_rel' declara 7 parámetros (máximo recomendado: 5). | Agrupá los parámetros relacionados en una estructura 'struct params_t'. |
| `0x7001h` | `p1_test.h:288` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x200Ah` | `p1_test.h:305` | **Función con excesiva cantidad de parámetros (> 5)** | Función '_p1_fail_str' declara 7 parámetros (máximo recomendado: 5). | Agrupá los parámetros relacionados en una estructura 'struct params_t'. |
| `0x200Ah` | `p1_test.h:324` | **Función con excesiva cantidad de parámetros (> 5)** | Función '_p1_fail_ptr' declara 7 parámetros (máximo recomendado: 5). | Agrupá los parámetros relacionados en una estructura 'struct params_t'. |
| `0x200Ah` | `p1_test.h:345` | **Función con excesiva cantidad de parámetros (> 5)** | Función '_p1_fail_array_int' declara 7 parámetros (máximo recomendado: 5). | Agrupá los parámetros relacionados en una estructura 'struct params_t'. |
| `0x200Ah` | `p1_test.h:363` | **Función con excesiva cantidad de parámetros (> 5)** | Función '_p1_fail_mem' declara 10 parámetros (máximo recomendado: 5). | Agrupá los parámetros relacionados en una estructura 'struct params_t'. |
| `0x7001h` | `p1_test.h:375` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x1005h` | `p1_test.h:378` | **Comparación entre tipos enteros con y sin signo en condición** | Comparación entre tipos con signo ('int') y sin signo ('size_t') entre 'i' y 'end'. | Utilizá tipos consistentes (ambos 'size_t' o casteá de forma controlada tras verificar que i >= 0). |
| `0x1005h` | `p1_test.h:382` | **Comparación entre tipos enteros con y sin signo en condición** | Comparación entre tipos con signo ('int') y sin signo ('size_t') entre 'i' y 'end'. | Utilizá tipos consistentes (ambos 'size_t' o casteá de forma controlada tras verificar que i >= 0). |
| `0x7001h` | `p1_test.h:413` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `p1_test.h:506` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x1003h` | `p1_test.h:535` | **Modificación de variable de control dentro del cuerpo del for** | Variable de control 'i' modificada dentro del cuerpo del bucle for. | Si la lógica de avance no es regular o depende de condiciones dinámicas, utilizá un bucle 'while'. |
| `0x7001h` | `prueba.c:38` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `prueba.c:68` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x4001h` | `prueba.c:70` | **Omisión de verificación de retorno NULL en fopen()** | Uso de descriptor de archivo 'f' devuelto por fopen() en línea 68 sin comprobación previa de NULL. | Verificá siempre 'if (f == NULL)' inmediatamente después de invocar 'fopen()'. |
| `0x7001h` | `prueba.c:89` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `prueba.c:15` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `prueba.c:45` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `cadenas.c:121` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `cadenas.c:155` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `prueba.c:13` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `prueba.c:27` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `prueba.c:41` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x5004h` | `prueba.c:43` | **Uso de funciones inseguras de manipulación de cadenas (strcpy/sprintf)** | Uso de función insegura 'strcpy()' sin limitación de longitud. | Migrá a 'snprintf' o copiá controlando explícitamente el tamaño máximo del destino. |
| `0x7001h` | `prueba.c:52` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `prueba.c:107` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `prueba.c:16` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `prueba.c:38` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `prueba.c:59` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `prueba.c:81` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `vector.c:15` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `vector.c:39` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `vector.c:92` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |

### 🔍 Detalle Pedagógico de Antipatrones

#### Regla `0x7001h`: Declaración de variable mezclada tras sentencias ejecutables
- **Ubicación:** `main.c:17`
```c
    int origen[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
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
- **Ubicación:** `prueba.c:28`
```c
    int datos[] = {10, 20, 30, 40};
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
- **Ubicación:** `prueba.c:46`
```c
    int datos[] = {1, 4, 7, 8, 10, 13};
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
- **Ubicación:** `vector_enteros.c:17`
```c
    int *ptr_heap = calloc(cantidad, sizeof(int));
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
- **Ubicación:** `vector_enteros.c:54`
```c
        size_t j = 0;
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
- **Ubicación:** `main.c:17`
```c
    char cadena_origen[] = " asdfg ";
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
- **Ubicación:** `prueba.c:31`
```c
    char *limpio = cadena_recortar_espacios(" hola mundo ");
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
- **Ubicación:** `prueba.c:45`
```c
    char *rep = cadena_repetir("abc", 3);
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
- **Ubicación:** `texto_dinamico.c:15`
```c
    size_t cantidad_caracteres =
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
- **Ubicación:** `cadena_dinamica.c:15`
```c
    size_t longitud_cadena = strlen(origen);
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
- **Ubicación:** `cadena_dinamica.c:27`
```c
    size_t long_primera = strlen(primera);
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
- **Ubicación:** `main.c:16`
```c
    char cadena_origen[] = "Esta cadena va a ser clonada";
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
- **Ubicación:** `prueba.c:17`
```c
    char origen[] = "Este texto va a ser clonado";
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
- **Ubicación:** `prueba.c:39`
```c
    char *ptr_union = unir_cadenas_dinamicas("Texto 1 - ", "Texto 2");
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
- **Ubicación:** `main.c:30`
```c
    size_t filas = 3;
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
- **Ubicación:** `matriz_dinamica.c:24`
```c
    int *ptr_matriz = calloc(filas * columnas, sizeof(int));
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

#### Regla `0x3002h`: Puntero colgante sin asignar NULL tras free()
- **Ubicación:** `matriz_dinamica.c:56`
```c
    free(matriz);                        // una vez que liberado el bloque, libero el arreglo
```
- **Explicación:** Dejar la variable con la dirección anterior permite accesos accidentales Use-After-Free o Double-Free.
- **Sugerencia:** Asigná 'ptr = NULL;' inmediatamente después de 'free(ptr);'.
- **Ejemplo incorrecto:**
```c
free(ptr);
// más instrucciones donde ptr sigue apuntando a memoria liberada
```
- **Ejemplo recomendado:**
```c
free(ptr);
ptr = NULL;
```

#### Regla `0x7001h`: Declaración de variable mezclada tras sentencias ejecutables
- **Ubicación:** `matriz_dinamica.c:168`
```c
    bool sobran_caracteres = !es_linea_vacia(cursor);      // si sobra algo, hay columnas de más
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
- **Ubicación:** `matriz_dinamica.c:196`
```c
    FILE *archivo = fopen(ruta, "r");
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
- **Ubicación:** `prueba.c:13`
```c
    int **matriz = matriz_crear(3, 4, NULL);
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
- **Ubicación:** `prueba.c:40`
```c
    int **matriz = matriz_crear(2, 2, NULL);
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
- **Ubicación:** `prueba.c:73`
```c
    int **m = matriz_cargar_desde_csv(RUTA_TMP, &filas, &columnas, NULL);
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
- **Ubicación:** `main.c:38`
```c
    const char *linea = "Lautaro Costantini - Este TP esta re dicifil";
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
- **Ubicación:** `prueba.c:16`
```c
    char **tokens = dividir_linea_csv("Cadena separada exitosamente", ' ', &cantidad, &error);
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
- **Ubicación:** `prueba.c:74`
```c
    size_t cantidad = 0;
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
- **Ubicación:** `registro_csv.c:54`
```c
                    char **ptr_temp = realloc(bloque_punteros, (cantidad_elementos + 1) * (sizeof(*bloque_punteros)));
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
- **Ubicación:** `consulta_csv.c:79`
```c
    size_t cantidad_filas_validas = 0;
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
- **Ubicación:** `consulta_csv.c:146`
```c
    int *datos_columna = crear_bloque_enteros(filas);
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
- **Ubicación:** `consulta_csv.c:226`
```c
    FILE *archivo = fopen(ruta, "w");
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
- **Ubicación:** `consulta_csv.c:255`
```c
        if (salio_bien == true) // chequeo si hay error para no seguir escribiendo
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
- **Ubicación:** `estadistica.c:24`
```c
        long long suma = 0;
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
- **Ubicación:** `main.c:43`
```c
    bool exito = fputs("1,25,70,170\n"
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
- **Ubicación:** `main.c:71`
```c
    size_t filas = 0;
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
- **Ubicación:** `matriz_dinamica.c:15`
```c
    int *ptr_matriz = calloc(filas * columnas, sizeof(int));
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

#### Regla `0x3002h`: Puntero colgante sin asignar NULL tras free()
- **Ubicación:** `matriz_dinamica.c:43`
```c
    free(matriz);                        // una vez que liberado el bloque, libero el arreglo
```
- **Explicación:** Dejar la variable con la dirección anterior permite accesos accidentales Use-After-Free o Double-Free.
- **Sugerencia:** Asigná 'ptr = NULL;' inmediatamente después de 'free(ptr);'.
- **Ejemplo incorrecto:**
```c
free(ptr);
// más instrucciones donde ptr sigue apuntando a memoria liberada
```
- **Ejemplo recomendado:**
```c
free(ptr);
ptr = NULL;
```

#### Regla `0x7001h`: Declaración de variable mezclada tras sentencias ejecutables
- **Ubicación:** `matriz_dinamica.c:155`
```c
    bool sobran_caracteres = !es_linea_vacia(cursor);      // si sobra algo, hay columnas de más
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
- **Ubicación:** `matriz_dinamica.c:174`
```c
    FILE *archivo = fopen(ruta, "r");
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
- **Ubicación:** `prueba.c:61`
```c
    size_t filas_filtradas = 0;
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
- **Ubicación:** `prueba.c:118`
```c
    float *sumas = matriz_sumar_columnas(base, 4, 3);
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
- **Ubicación:** `prueba.c:165`
```c
    float *promedios = matriz_promedio_columnas(base, 4, 3);
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
- **Ubicación:** `prueba.c:209`
```c
    int valores[] = {1, 2, 3,
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

#### Regla `0x4001h`: Omisión de verificación de retorno NULL en fopen()
- **Ubicación:** `prueba.c:222`
```c
    fclose(archivo);
```
- **Explicación:** Si el archivo no existe o no tiene permisos de lectura/escritura, 'fopen()' retorna NULL. Desreferenciarlo en 'fread', 'fgets' o 'fgetc' causa caída inmediata por SIGSEGV.
- **Sugerencia:** Verificá siempre 'if (f == NULL)' inmediatamente después de invocar 'fopen()'.
- **Ejemplo incorrecto:**
```c
FILE *f = fopen("datos.txt", "r");
fread(&elem, sizeof(elem), 1, f);
```
- **Ejemplo recomendado:**
```c
FILE *f = fopen("datos.txt", "r");
if (f == NULL) return -1;
fread(&elem, sizeof(elem), 1, f);
```

#### Regla `0x4001h`: Omisión de verificación de retorno NULL en fopen()
- **Ubicación:** `prueba.c:235`
```c
    fclose(archivo);
```
- **Explicación:** Si el archivo no existe o no tiene permisos de lectura/escritura, 'fopen()' retorna NULL. Desreferenciarlo en 'fread', 'fgets' o 'fgetc' causa caída inmediata por SIGSEGV.
- **Sugerencia:** Verificá siempre 'if (f == NULL)' inmediatamente después de invocar 'fopen()'.
- **Ejemplo incorrecto:**
```c
FILE *f = fopen("datos.txt", "r");
fread(&elem, sizeof(elem), 1, f);
```
- **Ejemplo recomendado:**
```c
FILE *f = fopen("datos.txt", "r");
if (f == NULL) return -1;
fread(&elem, sizeof(elem), 1, f);
```

#### Regla `0x200Ah`: Función con excesiva cantidad de parámetros (> 5)
- **Ubicación:** `recorrido.c:8`
```c
bool copiar_arreglo (int *origen, size_t cantidad_origen, int *destino, size_t cantidad_destino, size_t inicio, size_t cantidad_a_copiar)
```
- **Explicación:** Las funciones con muchos parámetros aumentan el acoplamiento y dificultan la invocación correcta en la pila.
- **Sugerencia:** Agrupá los parámetros relacionados en una estructura 'struct params_t'.
- **Ejemplo incorrecto:**
```c
void config(int a, int b, int c, int d, int e, int f);
```
- **Ejemplo recomendado:**
```c
void config(const struct config_t *cfg);
```

#### Regla `0x1005h`: Comparación entre tipos enteros con y sin signo en condición
- **Ubicación:** `recorrido.c:10`
```c
    if (origen == NULL || destino == NULL || inicio > cantidad_origen)
```
- **Explicación:** En C, si un operando es con signo y el otro es sin signo del mismo o mayor rango, el valor con signo se convierte implícitamente a sin signo. Si 'i' es negativo (-1), se convierte a un número enorme mayor que cualquier límite positivo.
- **Sugerencia:** Utilizá tipos consistentes (ambos 'size_t' o casteá de forma controlada tras verificar que i >= 0).
- **Ejemplo incorrecto:**
```c
int i = -1;
size_t n = 10;
if (i < n) { ... }
```
- **Ejemplo recomendado:**
```c
size_t i = 0;
size_t n = 10;
if (i < n) { ... }
```

#### Regla `0x7001h`: Declaración de variable mezclada tras sentencias ejecutables
- **Ubicación:** `recorrido.c:14`
```c
    bool resultado = true;
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
- **Ubicación:** `recorrido.c:47`
```c
    int *inicio = arreglo;
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
- **Ubicación:** `registro_csv.c:54`
```c
                    char **ptr_temp = realloc(bloque_punteros, (cantidad_elementos + 1) * (sizeof(*bloque_punteros)));
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
- **Ubicación:** `arreglos.c:52`
```c
    if (encontrado == true)
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
- **Ubicación:** `arreglos.c:73`
```c
    size_t inicio = 0;
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
- **Ubicación:** `arreglos.c:94`
```c
    bool esta_ordenado = true;
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
- **Ubicación:** `arreglos.c:119`
```c
    size_t cantidad_ocurrencias = 0;
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
- **Ubicación:** `arreglos.c:146`
```c
    size_t indice_lector = 0;
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

#### Regla `0x200Ah`: Función con excesiva cantidad de parámetros (> 5)
- **Ubicación:** `arreglos.c:171`
```c
size_t arreglo_fusionar(const int primero[], size_t cantidad_uno,
```
- **Explicación:** Las funciones con muchos parámetros aumentan el acoplamiento y dificultan la invocación correcta en la pila.
- **Sugerencia:** Agrupá los parámetros relacionados en una estructura 'struct params_t'.
- **Ejemplo incorrecto:**
```c
void config(int a, int b, int c, int d, int e, int f);
```
- **Ejemplo recomendado:**
```c
void config(const struct config_t *cfg);
```

#### Regla `0x7001h`: Declaración de variable mezclada tras sentencias ejecutables
- **Ubicación:** `arreglos.c:179`
```c
    size_t recorrer_primero = 0;
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
- **Ubicación:** `prueba.c:20`
```c
    int valores[] = {1, 2, 3, 4, 5};
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
- **Ubicación:** `prueba.c:46`
```c
    int impar[] = {1, 2, 3, 4, 5};
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
- **Ubicación:** `prueba.c:62`
```c
    int unico[] = {42};
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
- **Ubicación:** `prueba.c:83`
```c
    int vacio[] = {1};
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
- **Ubicación:** `prueba.c:104`
```c
    int arreglo[] = {1, 0, 2, 0, 3, 0, 4, 0, 5, 0, 6, 0, 7, 0, 8, 0, 9};
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

#### Regla `0x300Bh`: Pointer decay en sizeof de arreglo parámetro
- **Ubicación:** `prueba.c:107`
```c
                         arreglo, sizeof(arreglo) / sizeof(arreglo[0]), 0));
```
- **Explicación:** En C los arreglos decaen a punteros simples al pasarse como argumentos, por lo que sizeof(arr) siempre devuelve el tamaño de un puntero (4 u 8 bytes).
- **Sugerencia:** Pasá la cantidad de elementos explícitamente como un parámetro adicional 'size_t n'.
- **Ejemplo incorrecto:**
```c
void foo(int vec[]) {
    size_t n = sizeof(vec) / sizeof(vec[0]);
}
```
- **Ejemplo recomendado:**
```c
void foo(const int *vec, size_t n) {
    // usar n recibido por parámetro
}
```

#### Regla `0x7001h`: Declaración de variable mezclada tras sentencias ejecutables
- **Ubicación:** `prueba.c:128`
```c
    int destino_2[6];
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

#### Regla `0x200Ah`: Función con excesiva cantidad de parámetros (> 5)
- **Ubicación:** `p1_arrays.h:36`
```c
static inline void _p1_fail_array_double(const char *file, int line, const char *expr,
```
- **Explicación:** Las funciones con muchos parámetros aumentan el acoplamiento y dificultan la invocación correcta en la pila.
- **Sugerencia:** Agrupá los parámetros relacionados en una estructura 'struct params_t'.
- **Ejemplo incorrecto:**
```c
void config(int a, int b, int c, int d, int e, int f);
```
- **Ejemplo recomendado:**
```c
void config(const struct config_t *cfg);
```

#### Regla `0x200Ah`: Función con excesiva cantidad de parámetros (> 5)
- **Ubicación:** `p1_arrays.h:54`
```c
static inline void _p1_fail_array_sorted(const char *file, int line, const char *expr,
```
- **Explicación:** Las funciones con muchos parámetros aumentan el acoplamiento y dificultan la invocación correcta en la pila.
- **Sugerencia:** Agrupá los parámetros relacionados en una estructura 'struct params_t'.
- **Ejemplo incorrecto:**
```c
void config(int a, int b, int c, int d, int e, int f);
```
- **Ejemplo recomendado:**
```c
void config(const struct config_t *cfg);
```

#### Regla `0x200Ah`: Función con excesiva cantidad de parámetros (> 5)
- **Ubicación:** `p1_arrays.h:73`
```c
static inline void _p1_fail_str_array(const char *file, int line, const char *expr,
```
- **Explicación:** Las funciones con muchos parámetros aumentan el acoplamiento y dificultan la invocación correcta en la pila.
- **Sugerencia:** Agrupá los parámetros relacionados en una estructura 'struct params_t'.
- **Ejemplo incorrecto:**
```c
void config(int a, int b, int c, int d, int e, int f);
```
- **Ejemplo recomendado:**
```c
void config(const struct config_t *cfg);
```

#### Regla `0x200Ah`: Función con excesiva cantidad de parámetros (> 5)
- **Ubicación:** `p1_arrays.h:93`
```c
static inline void _p1_fail_array_contains(const char *file, int line, const char *expr,
```
- **Explicación:** Las funciones con muchos parámetros aumentan el acoplamiento y dificultan la invocación correcta en la pila.
- **Sugerencia:** Agrupá los parámetros relacionados en una estructura 'struct params_t'.
- **Ejemplo incorrecto:**
```c
void config(int a, int b, int c, int d, int e, int f);
```
- **Ejemplo recomendado:**
```c
void config(const struct config_t *cfg);
```

#### Regla `0x200Ah`: Función con excesiva cantidad de parámetros (> 5)
- **Ubicación:** `p1_files.h:21`
```c
static inline void _p1_fail_file_exists(const char *file, int line, const char *expr,
```
- **Explicación:** Las funciones con muchos parámetros aumentan el acoplamiento y dificultan la invocación correcta en la pila.
- **Sugerencia:** Agrupá los parámetros relacionados en una estructura 'struct params_t'.
- **Ejemplo incorrecto:**
```c
void config(int a, int b, int c, int d, int e, int f);
```
- **Ejemplo recomendado:**
```c
void config(const struct config_t *cfg);
```

#### Regla `0x200Ah`: Función con excesiva cantidad de parámetros (> 5)
- **Ubicación:** `p1_files.h:40`
```c
static inline void _p1_fail_file_line(const char *file, int line, const char *expr,
```
- **Explicación:** Las funciones con muchos parámetros aumentan el acoplamiento y dificultan la invocación correcta en la pila.
- **Sugerencia:** Agrupá los parámetros relacionados en una estructura 'struct params_t'.
- **Ejemplo incorrecto:**
```c
void config(int a, int b, int c, int d, int e, int f);
```
- **Ejemplo recomendado:**
```c
void config(const struct config_t *cfg);
```

#### Regla `0x200Ah`: Función con excesiva cantidad de parámetros (> 5)
- **Ubicación:** `p1_files.h:58`
```c
static inline void _p1_fail_file_contains(const char *file, int line, const char *expr,
```
- **Explicación:** Las funciones con muchos parámetros aumentan el acoplamiento y dificultan la invocación correcta en la pila.
- **Sugerencia:** Agrupá los parámetros relacionados en una estructura 'struct params_t'.
- **Ejemplo incorrecto:**
```c
void config(int a, int b, int c, int d, int e, int f);
```
- **Ejemplo recomendado:**
```c
void config(const struct config_t *cfg);
```

#### Regla `0x200Ah`: Función con excesiva cantidad de parámetros (> 5)
- **Ubicación:** `p1_files.h:74`
```c
static inline void _p1_fail_file_bin(const char *file, int line, const char *expr,
```
- **Explicación:** Las funciones con muchos parámetros aumentan el acoplamiento y dificultan la invocación correcta en la pila.
- **Sugerencia:** Agrupá los parámetros relacionados en una estructura 'struct params_t'.
- **Ejemplo incorrecto:**
```c
void config(int a, int b, int c, int d, int e, int f);
```
- **Ejemplo recomendado:**
```c
void config(const struct config_t *cfg);
```

#### Regla `0x7001h`: Declaración de variable mezclada tras sentencias ejecutables
- **Ubicación:** `p1_stdio.h:133`
```c
        size_t n = fread(buf, 1, max_len - 1, _p1_stdio_ctx.capture_stdout_file);
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
- **Ubicación:** `p1_stdio.h:175`
```c
        size_t n = fread(buf, 1, max_len - 1, _p1_stdio_ctx.capture_stderr_file);
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
- **Ubicación:** `p1_test.h:132`
```c
    const char *term = getenv("TERM");
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

#### Regla `0x200Ah`: Función con excesiva cantidad de parámetros (> 5)
- **Ubicación:** `p1_test.h:216`
```c
static inline void _p1_fail_int(const char *file, int line, const char *expr,
```
- **Explicación:** Las funciones con muchos parámetros aumentan el acoplamiento y dificultan la invocación correcta en la pila.
- **Sugerencia:** Agrupá los parámetros relacionados en una estructura 'struct params_t'.
- **Ejemplo incorrecto:**
```c
void config(int a, int b, int c, int d, int e, int f);
```
- **Ejemplo recomendado:**
```c
void config(const struct config_t *cfg);
```

#### Regla `0x200Ah`: Función con excesiva cantidad de parámetros (> 5)
- **Ubicación:** `p1_test.h:233`
```c
static inline void _p1_fail_int_between(const char *file, int line, const char *expr,
```
- **Explicación:** Las funciones con muchos parámetros aumentan el acoplamiento y dificultan la invocación correcta en la pila.
- **Sugerencia:** Agrupá los parámetros relacionados en una estructura 'struct params_t'.
- **Ejemplo incorrecto:**
```c
void config(int a, int b, int c, int d, int e, int f);
```
- **Ejemplo recomendado:**
```c
void config(const struct config_t *cfg);
```

#### Regla `0x200Ah`: Función con excesiva cantidad de parámetros (> 5)
- **Ubicación:** `p1_test.h:250`
```c
static inline void _p1_fail_uint(const char *file, int line, const char *expr,
```
- **Explicación:** Las funciones con muchos parámetros aumentan el acoplamiento y dificultan la invocación correcta en la pila.
- **Sugerencia:** Agrupá los parámetros relacionados en una estructura 'struct params_t'.
- **Ejemplo incorrecto:**
```c
void config(int a, int b, int c, int d, int e, int f);
```
- **Ejemplo recomendado:**
```c
void config(const struct config_t *cfg);
```

#### Regla `0x200Ah`: Función con excesiva cantidad de parámetros (> 5)
- **Ubicación:** `p1_test.h:267`
```c
static inline void _p1_fail_double(const char *file, int line, const char *expr,
```
- **Explicación:** Las funciones con muchos parámetros aumentan el acoplamiento y dificultan la invocación correcta en la pila.
- **Sugerencia:** Agrupá los parámetros relacionados en una estructura 'struct params_t'.
- **Ejemplo incorrecto:**
```c
void config(int a, int b, int c, int d, int e, int f);
```
- **Ejemplo recomendado:**
```c
void config(const struct config_t *cfg);
```

#### Regla `0x200Ah`: Función con excesiva cantidad de parámetros (> 5)
- **Ubicación:** `p1_test.h:284`
```c
static inline void _p1_fail_double_rel(const char *file, int line, const char *expr,
```
- **Explicación:** Las funciones con muchos parámetros aumentan el acoplamiento y dificultan la invocación correcta en la pila.
- **Sugerencia:** Agrupá los parámetros relacionados en una estructura 'struct params_t'.
- **Ejemplo incorrecto:**
```c
void config(int a, int b, int c, int d, int e, int f);
```
- **Ejemplo recomendado:**
```c
void config(const struct config_t *cfg);
```

#### Regla `0x7001h`: Declaración de variable mezclada tras sentencias ejecutables
- **Ubicación:** `p1_test.h:288`
```c
    double diff = _p1_abs_double(expected - actual);
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

#### Regla `0x200Ah`: Función con excesiva cantidad de parámetros (> 5)
- **Ubicación:** `p1_test.h:305`
```c
static inline void _p1_fail_str(const char *file, int line, const char *expr,
```
- **Explicación:** Las funciones con muchos parámetros aumentan el acoplamiento y dificultan la invocación correcta en la pila.
- **Sugerencia:** Agrupá los parámetros relacionados en una estructura 'struct params_t'.
- **Ejemplo incorrecto:**
```c
void config(int a, int b, int c, int d, int e, int f);
```
- **Ejemplo recomendado:**
```c
void config(const struct config_t *cfg);
```

#### Regla `0x200Ah`: Función con excesiva cantidad de parámetros (> 5)
- **Ubicación:** `p1_test.h:324`
```c
static inline void _p1_fail_ptr(const char *file, int line, const char *expr,
```
- **Explicación:** Las funciones con muchos parámetros aumentan el acoplamiento y dificultan la invocación correcta en la pila.
- **Sugerencia:** Agrupá los parámetros relacionados en una estructura 'struct params_t'.
- **Ejemplo incorrecto:**
```c
void config(int a, int b, int c, int d, int e, int f);
```
- **Ejemplo recomendado:**
```c
void config(const struct config_t *cfg);
```

#### Regla `0x200Ah`: Función con excesiva cantidad de parámetros (> 5)
- **Ubicación:** `p1_test.h:345`
```c
static inline void _p1_fail_array_int(const char *file, int line, const char *expr,
```
- **Explicación:** Las funciones con muchos parámetros aumentan el acoplamiento y dificultan la invocación correcta en la pila.
- **Sugerencia:** Agrupá los parámetros relacionados en una estructura 'struct params_t'.
- **Ejemplo incorrecto:**
```c
void config(int a, int b, int c, int d, int e, int f);
```
- **Ejemplo recomendado:**
```c
void config(const struct config_t *cfg);
```

#### Regla `0x200Ah`: Función con excesiva cantidad de parámetros (> 5)
- **Ubicación:** `p1_test.h:363`
```c
static inline void _p1_fail_mem(const char *file, int line, const char *expr,
```
- **Explicación:** Las funciones con muchos parámetros aumentan el acoplamiento y dificultan la invocación correcta en la pila.
- **Sugerencia:** Agrupá los parámetros relacionados en una estructura 'struct params_t'.
- **Ejemplo incorrecto:**
```c
void config(int a, int b, int c, int d, int e, int f);
```
- **Ejemplo recomendado:**
```c
void config(const struct config_t *cfg);
```

#### Regla `0x7001h`: Declaración de variable mezclada tras sentencias ejecutables
- **Ubicación:** `p1_test.h:375`
```c
        size_t start = (diff_offset >= 4) ? (diff_offset - 4) : 0;
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

#### Regla `0x1005h`: Comparación entre tipos enteros con y sin signo en condición
- **Ubicación:** `p1_test.h:378`
```c
        for (size_t i = start; i < end; i++) {
```
- **Explicación:** En C, si un operando es con signo y el otro es sin signo del mismo o mayor rango, el valor con signo se convierte implícitamente a sin signo. Si 'i' es negativo (-1), se convierte a un número enorme mayor que cualquier límite positivo.
- **Sugerencia:** Utilizá tipos consistentes (ambos 'size_t' o casteá de forma controlada tras verificar que i >= 0).
- **Ejemplo incorrecto:**
```c
int i = -1;
size_t n = 10;
if (i < n) { ... }
```
- **Ejemplo recomendado:**
```c
size_t i = 0;
size_t n = 10;
if (i < n) { ... }
```

#### Regla `0x1005h`: Comparación entre tipos enteros con y sin signo en condición
- **Ubicación:** `p1_test.h:382`
```c
        for (size_t i = start; i < end; i++) {
```
- **Explicación:** En C, si un operando es con signo y el otro es sin signo del mismo o mayor rango, el valor con signo se convierte implícitamente a sin signo. Si 'i' es negativo (-1), se convierte a un número enorme mayor que cualquier límite positivo.
- **Sugerencia:** Utilizá tipos consistentes (ambos 'size_t' o casteá de forma controlada tras verificar que i >= 0).
- **Ejemplo incorrecto:**
```c
int i = -1;
size_t n = 10;
if (i < n) { ... }
```
- **Ejemplo recomendado:**
```c
size_t i = 0;
size_t n = 10;
if (i < n) { ... }
```

#### Regla `0x7001h`: Declaración de variable mezclada tras sentencias ejecutables
- **Ubicación:** `p1_test.h:413`
```c
    const char *sig_name = "SEÑAL FATAL";
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
- **Ubicación:** `p1_test.h:506`
```c
        size_t n = fread(out_buf, 1, max_buf - 1, _p1_capture_state.tmp_file);
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

#### Regla `0x1003h`: Modificación de variable de control dentro del cuerpo del for
- **Ubicación:** `p1_test.h:535`
```c
    for (int i = 1; i < argc; i++) {
```
- **Explicación:** Alterar la variable de control dentro del cuerpo oculta el paso del bucle y dificulta el razonamiento estructurado.
- **Sugerencia:** Si la lógica de avance no es regular o depende de condiciones dinámicas, utilizá un bucle 'while'.
- **Ejemplo incorrecto:**
```c
for (int i = 0; i < n; i++) {
    if (cond) i += 2;
}
```
- **Ejemplo recomendado:**
```c
int i = 0;
while (i < n) {
    if (cond) i += 2;
    else i++;
}
```

#### Regla `0x7001h`: Declaración de variable mezclada tras sentencias ejecutables
- **Ubicación:** `prueba.c:38`
```c
    int x = 5;
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
- **Ubicación:** `prueba.c:68`
```c
    FILE *f = fopen(f_path, "w");
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

#### Regla `0x4001h`: Omisión de verificación de retorno NULL en fopen()
- **Ubicación:** `prueba.c:70`
```c
    fputs("UNRN P1 Test Suite\n", f);
```
- **Explicación:** Si el archivo no existe o no tiene permisos de lectura/escritura, 'fopen()' retorna NULL. Desreferenciarlo en 'fread', 'fgets' o 'fgetc' causa caída inmediata por SIGSEGV.
- **Sugerencia:** Verificá siempre 'if (f == NULL)' inmediatamente después de invocar 'fopen()'.
- **Ejemplo incorrecto:**
```c
FILE *f = fopen("datos.txt", "r");
fread(&elem, sizeof(elem), 1, f);
```
- **Ejemplo recomendado:**
```c
FILE *f = fopen("datos.txt", "r");
if (f == NULL) return -1;
fread(&elem, sizeof(elem), 1, f);
```

#### Regla `0x7001h`: Declaración de variable mezclada tras sentencias ejecutables
- **Ubicación:** `prueba.c:89`
```c
    int num = 0;
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
- **Ubicación:** `prueba.c:15`
```c
    int x = 42;
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
- **Ubicación:** `prueba.c:45`
```c
    int datos[] = {14, -3, 8, 25, 0, -10, 4};
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
- **Ubicación:** `cadenas.c:121`
```c
    size_t longitud_extraida = longitud_util_cadena(origen, capacidad_max);
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
- **Ubicación:** `cadenas.c:155`
```c
    size_t longitud_util = longitud_util_cadena(origen, capacidad_max);
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
- **Ubicación:** `prueba.c:13`
```c
    char *dup = cadena_duplicar_segura("Programacion 1", 30);
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
- **Ubicación:** `prueba.c:27`
```c
    char *unida = cadena_unir_dinamica("Hola ", 10, "Mundo", 10);
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
- **Ubicación:** `prueba.c:41`
```c
    char *ptr = malloc(sizeof("Esta cadena en el heap va a ser liberada"));
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

#### Regla `0x5004h`: Uso de funciones inseguras de manipulación de cadenas (strcpy/sprintf)
- **Ubicación:** `prueba.c:43`
```c
    strcpy(ptr, "Esta cadena en el heap va a ser liberada");
```
- **Explicación:** 'strcpy' y 'sprintf' no limitan la cantidad de bytes escritos, causando desbordamiento de búfer (Buffer Overflow).
- **Sugerencia:** Migrá a 'snprintf' o copiá controlando explícitamente el tamaño máximo del destino.
- **Ejemplo incorrecto:**
```c
char buf[16];
sprintf(buf, "%s: %d", nombre, valor);
```
- **Ejemplo recomendado:**
```c
char buf[16];
snprintf(buf, sizeof(buf), "%s: %d", nombre, valor);
```

#### Regla `0x7001h`: Declaración de variable mezclada tras sentencias ejecutables
- **Ubicación:** `prueba.c:52`
```c
    char *sub = cadena_subcadena_dinamica("Hola Mundo", 20, 5, 5);
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
- **Ubicación:** `prueba.c:107`
```c
    char *inv = cadena_invertir_dinamica("hola", 10);
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
- **Ubicación:** `prueba.c:16`
```c
    int *bloque = crear_bloque_enteros(5);
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
- **Ubicación:** `prueba.c:38`
```c
    int *bloque = crear_bloque_enteros(2);
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
- **Ubicación:** `prueba.c:59`
```c
    int a[] = {1, 2, 3};
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
- **Ubicación:** `prueba.c:81`
```c
    int *bloque = NULL;
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
- **Ubicación:** `vector.c:15`
```c
    int *ptr = calloc(cantidad, sizeof(int));
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
- **Ubicación:** `vector.c:39`
```c
    int *ptr_aux = realloc(bloque, sizeof(int) * nueva_cantidad);
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
- **Ubicación:** `vector.c:92`
```c
    int *temp = realloc(*puntero_bloque, (*cantidad + 1) * sizeof(int));
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

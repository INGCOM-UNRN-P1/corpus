# Informe de Corrección — TP4 (bbbf0b9)

## Repositorio
**branch/revision:** `main` `bbbf0b9`
**Commit SHA:** `bbbf0b90d0aed1be965cfc4edbd546622dbfa02f`
**Autor:** `anon_001`
**Fecha del commit:** `2026-10-01 23:00:13 -0300`
**Mensaje:** `TP4 completado`
**Fecha de evaluación:** 2026-10-02 14:07:38
**Versión revisada:** `bbbf0b9`

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
│   │   └── prueba.c
│   ├── ejercicio5/
│   │   ├── main.c
│   │   ├── Makefile
│   │   ├── prueba.c
│   │   ├── registro_csv.c
│   │   └── registro_csv.h
│   └── ejercicio6/
│       ├── consulta_csv.c
│       ├── consulta_csv.h
│       ├── main.c
│       ├── Makefile
│       ├── prueba.c
│       └── test_salida.csv
├── libs/
│   ├── cadenas/
│   │   ├── cadenas_tp2.c
│   │   ├── cadenas_tp2.h
│   │   ├── cadenas_tp2.o
│   │   ├── libcadenas.a
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
| `[ARCHIVOS_BINARIOS]` | ❌ ERROR (2 filtrados) | 0.0/10 | — | Se detectaron binarios prohibidos (.o/.exe) en la entrega |
| `cadena_dinamica.c` | ❌ Falló Compilación | 9.5/10 | ✓ Limpio (0 fugas) | 5 advertencias |
| `cadenas.c` | ❌ Falló Compilación | 8.5/10 | ✓ Limpio (0 fugas) | 21 advertencias |
| `cadenas_tp2.c` | ❌ Falló Compilación | 10.0/10 | ✓ Limpio (0 fugas) | 5 advertencias |
| `consulta_csv.c` | ❌ Falló Compilación | 10.0/10 | ✓ Limpio (0 fugas) | 18 advertencias |
| `libs/cadenas/cadenas_tp2.o` | ❌ Falló Compilación | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `libs/cadenas/libcadenas.a` | ❌ Falló Compilación | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `main.c` | ❌ Falló Compilación | 10.0/10 | ✓ Limpio (0 fugas) | 36 advertencias |
| `matriz_dinamica.c` | ❌ Falló Compilación | 10.0/10 | ✓ Limpio (0 fugas) | 15 advertencias |
| `prueba.c` | ❌ Falló Compilación | 4.0/10 | ✓ Limpio (0 fugas) | 88 advertencias |
| `registro_csv.c` | ❌ Falló Compilación | 8.5/10 | ✓ Limpio (0 fugas) | 21 advertencias |
| `registro_csv.h` | ❌ Falló Compilación | 9.5/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `texto_dinamico.c` | ❌ Falló Compilación | 9.0/10 | ✓ Limpio (0 fugas) | 11 advertencias |
| `vector.c` | ❌ Falló Compilación | 9.5/10 | ✓ Limpio (0 fugas) | 14 advertencias |
| `vector_enteros.c` | ❌ Falló Compilación | 10.0/10 | ✓ Limpio (0 fugas) | 9 advertencias |

## ⚠️ Archivos Binarios Prohibidos Filtrados

> ❌ **ERROR DE ENTREGA:** Se detectaron archivos binarios precompilados o ejecutables en la entrega del estudiante. 
> Para mantener la reproducibilidad académica y evitar la ejecución de código no compilado desde fuentes, estos archivos fueron **filtrados y descartados** de la evaluación.

| Archivo Binario | Regla | Severidad | Detalle del Error | Sugerencia |
| :--- | :---: | :---: | :--- | :--- |
| `libs/cadenas/cadenas_tp2.o` | `0x000Fh` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'libs/cadenas/cadenas_tp2.o' (Extensión binaria prohibida '.o'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `libs/cadenas/libcadenas.a` | `0x000Fh` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'libs/cadenas/libcadenas.a' (Extensión binaria prohibida '.a'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |

**Acción Requerida:** Las entregas deben contener exclusivamente código fuente editable (`.c`, `.h`), archivos de configuración (`Makefile`) y documentación (`.md`, `.txt`). Ejecutá `make clean` antes de comprimir tu entrega y verificá tu archivo `.gitignore`.

## Compilación — Makefile raíz del Proyecto

❌ **Estado:** Falló la compilación mediante el Makefile de la raíz.

```text
In file included from prueba.c:9:
prueba.c: In function ‘main’:
../../libs/p1_test/include/p1_test.h:783:13: error: expected ‘)’ before ‘_p1_prev_segv’
  783 |     (void (*_p1_prev_segv)(int) = NULL; void (*_p1_prev_fpe)(int) = NULL;      \
      |             ^~~~~~~~~~~~~
../../libs/p1_test/include/p1_test.h:1108:9: note: in expansion of macro ‘_P1_SIG_VARS’
 1108 |         _P1_SIG_VARS;                                                          \
      |         ^~~~~~~~~~~~
prueba.c:80:5: note: in expansion of macro ‘RUN_TEST’
   80 |     RUN_TEST(prueba_cadena_longitud);
      |     ^~~~~~~~
../../libs/p1_test/include/p1_test.h:783:27: error: expected ‘)’ before ‘(’ token
  783 |     (void (*_p1_prev_segv)(int) = NULL; void (*_p1_prev_fpe)(int) = NULL;      \
      |     ~                     ^
../../libs/p1_test/include/p1_test.h:1108:9: note: in expansion of macro ‘_P1_SIG_VARS’
 1108 |         _P1_SIG_VARS;                                                          \
      |         ^~~~~~~~~~~~
prueba.c:80:5: note: in expansion of macro ‘RUN_TEST’
   80 |     RUN_TEST(prueba_cadena_longitud);
      |     ^~~~~~~~
../../libs/p1_test/include/p1_test.h:1109:27: error: ‘_p1_prev_s
```

> 📄 **Salida completa:** registrada en `compilacion_bbbf0b9.log`.

## Observaciones de Calidad y Reglas P1 (Linter AST / Ripley)

Se detectaron **200** observación(es) en el código C:

| Regla | Ubicación | Severidad | Observación | Sugerencia |
| :--- | :--- | :---: | :--- | :--- |
| `0x0004h` | `main.c:1` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `main.c:13` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0xEEEEh` | `prueba.c:23` | ESTILO | Indentación no es múltiplo de 4 espacios (27 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `prueba.c:69` | ESTILO | Indentación no es múltiplo de 4 espacios (26 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0x0004h` | `prueba.c:1` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:14` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:35` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:55` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `prueba.c:66` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `prueba.c:66` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0xEEEEh` | `vector_enteros.c:45` | ESTILO | Indentación no es múltiplo de 4 espacios (27 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0x0004h` | `vector_enteros.c:1` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `vector_enteros.c:10` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0018h` | `vector_enteros.c:22` | ESTILO | El asterisco del puntero debe estar junto al identificador (ej. 'int *ptr;'). | Escribir 'tipo *nombre_var' en lugar de 'tipo* nombre_var'. |
| `0x0004h` | `vector_enteros.c:36` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `vector_enteros.c:54` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `vector_enteros.c:59` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `vector_enteros.c:62` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `vector_enteros.c:65` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:1` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0xEEEEh` | `prueba.c:61` | ESTILO | Indentación no es múltiplo de 4 espacios (26 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0x0004h` | `prueba.c:1` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:12` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:19` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:34` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:48` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:55` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `prueba.c:58` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `prueba.c:58` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `texto_dinamico.c:1` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `texto_dinamico.c:10` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `texto_dinamico.c:23` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `texto_dinamico.c:27` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `texto_dinamico.c:30` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `texto_dinamico.c:55` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0018h` | `texto_dinamico.c:72` | ESTILO | El asterisco del puntero debe estar junto al identificador (ej. 'int *ptr;'). | Escribir 'tipo *nombre_var' en lugar de 'tipo* nombre_var'. |
| `0x0004h` | `cadena_dinamica.c:1` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `cadena_dinamica.c:10` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `cadena_dinamica.c:34` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:1` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:15` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:42` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:49` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0xEEEEh` | `prueba.c:82` | ESTILO | Indentación no es múltiplo de 4 espacios (26 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0x0004h` | `prueba.c:1` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `prueba.c:79` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `prueba.c:79` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:1` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:14` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:16` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:23` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:30` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:39` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:44` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:45` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:50` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:55` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0xEEEEh` | `matriz_dinamica.c:66` | ESTILO | Indentación no es múltiplo de 4 espacios (30 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0x0004h` | `matriz_dinamica.c:1` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `matriz_dinamica.c:8` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `matriz_dinamica.c:15` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `matriz_dinamica.c:15` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0018h` | `matriz_dinamica.c:21` | ESTILO | El asterisco del puntero debe estar junto al identificador (ej. 'int *ptr;'). | Escribir 'tipo *nombre_var' en lugar de 'tipo* nombre_var'. |
| `0x0004h` | `matriz_dinamica.c:26` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0018h` | `matriz_dinamica.c:26` | ESTILO | El asterisco del puntero debe estar junto al identificador (ej. 'int *ptr;'). | Escribir 'tipo *nombre_var' en lugar de 'tipo* nombre_var'. |
| `0x0018h` | `matriz_dinamica.c:34` | ESTILO | El asterisco del puntero debe estar junto al identificador (ej. 'int *ptr;'). | Escribir 'tipo *nombre_var' en lugar de 'tipo* nombre_var'. |
| `0x0004h` | `matriz_dinamica.c:39` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `matriz_dinamica.c:44` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `matriz_dinamica.c:57` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `matriz_dinamica.c:65` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `matriz_dinamica.c:78` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `matriz_dinamica.c:83` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0xEEEEh` | `prueba.c:58` | ESTILO | Indentación no es múltiplo de 4 espacios (26 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0x0004h` | `prueba.c:1` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:21` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:51` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `prueba.c:55` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `prueba.c:55` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:1` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:15` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:34` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:45` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:49` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0xEEEEh` | `prueba.c:87` | ESTILO | Indentación no es múltiplo de 4 espacios (26 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0x0004h` | `prueba.c:1` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:10` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:47` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:53` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:62` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:72` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:78` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:80` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `prueba.c:84` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `prueba.c:84` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0xEEEEh` | `registro_csv.c:20` | ESTILO | Indentación no es múltiplo de 4 espacios (25 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0x0004h` | `registro_csv.c:1` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `registro_csv.c:3` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `registro_csv.c:11` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `registro_csv.c:19` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `registro_csv.c:30` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `registro_csv.c:36` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0018h` | `registro_csv.c:36` | ESTILO | El asterisco del puntero debe estar junto al identificador (ej. 'int *ptr;'). | Escribir 'tipo *nombre_var' en lugar de 'tipo* nombre_var'. |
| `0x0004h` | `registro_csv.c:47` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `registro_csv.c:69` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `registro_csv.c:81` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0005h` | `registro_csv.c:82` | ESTILO | La llave de apertura para `if` debe estar en una nueva línea. | Ubicar '{' en el renglón siguiente alineada verticalmente. |
| `0x0005h` | `registro_csv.c:85` | ESTILO | La llave de apertura para `for` debe estar en una nueva línea. | Ubicar '{' en el renglón siguiente alineada verticalmente. |
| `0x0004h` | `registro_csv.c:86` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `registro_csv.c:88` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0xEEEEh` | `consulta_csv.c:23` | ESTILO | Indentación no es múltiplo de 4 espacios (33 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `consulta_csv.c:24` | ESTILO | Indentación no es múltiplo de 4 espacios (33 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `consulta_csv.c:150` | ESTILO | Indentación no es múltiplo de 4 espacios (25 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0x0004h` | `consulta_csv.c:1` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `consulta_csv.c:11` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `consulta_csv.c:22` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `consulta_csv.c:22` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `consulta_csv.c:23` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `consulta_csv.c:53` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0018h` | `consulta_csv.c:53` | ESTILO | El asterisco del puntero debe estar junto al identificador (ej. 'int *ptr;'). | Escribir 'tipo *nombre_var' en lugar de 'tipo* nombre_var'. |
| `0x0018h` | `consulta_csv.c:67` | ESTILO | El asterisco del puntero debe estar junto al identificador (ej. 'int *ptr;'). | Escribir 'tipo *nombre_var' en lugar de 'tipo* nombre_var'. |
| `0x0004h` | `consulta_csv.c:102` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `consulta_csv.c:110` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `consulta_csv.c:110` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0018h` | `consulta_csv.c:117` | ESTILO | El asterisco del puntero debe estar junto al identificador (ej. 'int *ptr;'). | Escribir 'tipo *nombre_var' en lugar de 'tipo* nombre_var'. |
| `0x0004h` | `consulta_csv.c:140` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `consulta_csv.c:149` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `consulta_csv.c:169` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0xEEEEh` | `main.c:62` | ESTILO | Indentación no es múltiplo de 4 espacios (11 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `main.c:75` | ESTILO | Indentación no es múltiplo de 4 espacios (15 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `main.c:109` | ESTILO | Indentación no es múltiplo de 4 espacios (19 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0x0004h` | `main.c:1` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:12` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:18` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0018h` | `main.c:18` | ESTILO | El asterisco del puntero debe estar junto al identificador (ej. 'int *ptr;'). | Escribir 'tipo *nombre_var' en lugar de 'tipo* nombre_var'. |
| `0x0018h` | `main.c:28` | ESTILO | El asterisco del puntero debe estar junto al identificador (ej. 'int *ptr;'). | Escribir 'tipo *nombre_var' en lugar de 'tipo* nombre_var'. |
| `0x0004h` | `main.c:43` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:50` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:63` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:65` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:69` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:82` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0xEEEEh` | `prueba.c:32` | ESTILO | Indentación no es múltiplo de 4 espacios (43 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `prueba.c:40` | ESTILO | Indentación no es múltiplo de 4 espacios (43 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `prueba.c:106` | ESTILO | Indentación no es múltiplo de 4 espacios (26 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0x0004h` | `prueba.c:1` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:12` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:52` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:68` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `prueba.c:103` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `prueba.c:103` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `cadenas_tp2.c:1` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `cadenas_tp2.c:27` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0002h` | `cadenas_tp2.c:46` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `cadenas_tp2.c:56` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `cadenas_tp2.c:64` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0xEEEEh` | `prueba.c:79` | ESTILO | Indentación no es múltiplo de 4 espacios (26 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0x0004h` | `prueba.c:1` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `prueba.c:76` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `prueba.c:76` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0xEEEEh` | `cadenas.c:50` | ESTILO | Indentación no es múltiplo de 4 espacios (27 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0x0004h` | `cadenas.c:1` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `cadenas.c:7` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `cadenas.c:10` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `cadenas.c:40` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `cadenas.c:76` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `cadenas.c:81` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `cadenas.c:85` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `cadenas.c:90` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `cadenas.c:100` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `cadenas.c:130` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `cadenas.c:160` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `cadenas.c:174` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0002h` | `cadenas.c:192` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `cadenas.c:202` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0xEEEEh` | `prueba.c:41` | ESTILO | Indentación no es múltiplo de 4 espacios (26 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0x0004h` | `prueba.c:1` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:16` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:30` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `prueba.c:38` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `prueba.c:38` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0xEEEEh` | `prueba.c:59` | ESTILO | Indentación no es múltiplo de 4 espacios (26 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0x0004h` | `prueba.c:1` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:25` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:31` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:52` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `prueba.c:56` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `prueba.c:56` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0xEEEEh` | `vector.c:95` | ESTILO | Indentación no es múltiplo de 4 espacios (31 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0x0004h` | `vector.c:1` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `vector.c:9` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `vector.c:25` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `vector.c:30` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `vector.c:34` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `vector.c:39` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0018h` | `vector.c:55` | ESTILO | El asterisco del puntero debe estar junto al identificador (ej. 'int *ptr;'). | Escribir 'tipo *nombre_var' en lugar de 'tipo* nombre_var'. |
| `0x0002h` | `vector.c:64` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `vector.c:86` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `vector.c:94` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `vector.c:101` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `vector.c:104` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |

## Pruebas del Proyecto — Makefile raíz (`make test`)

❌ **Estado:** Fallaron las pruebas del proyecto (`make test`).

```text
make: Entering directory '/home/mrtin/dev/p1/ripley/entregas/TP4/TP4-anon_001/repo'
Compilando librería en libs/cadenas...
make[1]: Entering directory '/home/mrtin/dev/p1/ripley/entregas/TP4/TP4-anon_001/repo/libs/cadenas'
Compilando prueba.c
cc -Wall -Wextra -std=c11 -pedantic -g -I../../libs/p1_test/include -I../../libs/p1_test -c prueba.c
make[1]: Leaving directory '/home/mrtin/dev/p1/ripley/entregas/TP4/TP4-anon_001/repo/libs/cadenas'
make: Leaving directory '/home/mrtin/dev/p1/ripley/entregas/TP4/TP4-anon_001/repo'

In file included from prueba.c:9:
prueba.c: In function ‘main’:
../../lib
```

## Auditoría de Memoria Dinámica — Valgrind

✓ **Estado:** No se detectaron fugas de memoria durante las pruebas en sandbox.

## Linter de Estilo y Formato — Gaff

⚠️ Se detectaron **23** observación(es) de estilo arquitectónico:

| Regla | Ubicación | Observación | Sugerencia | Autofix |
| :--- | :--- | :--- | :--- | :---: |
| `0x0001h` | `prueba.c:45` | Identificador corto y poco expresivo 'rep' (3 caracteres). | Se recomienda utilizar identificadores más descriptivos del dominio del problema. | No |
| `0x0001h` | `texto_dinamico.c:39` | Identificador corto y poco expresivo 'len' (3 caracteres). | Se recomienda utilizar identificadores más descriptivos del dominio del problema. | No |
| `0x0001h` | `texto_dinamico.c:68` | Identificador corto y poco expresivo 'len' (3 caracteres). | Se recomienda utilizar identificadores más descriptivos del dominio del problema. | No |
| `0x0001h` | `cadena_dinamica.c:21` | Identificador corto y poco expresivo 'len' (3 caracteres). | Se recomienda utilizar identificadores más descriptivos del dominio del problema. | No |
| `0x0001h` | `prueba.c:17` | Identificador corto y poco expresivo 's1' (2 caracteres). | Se recomienda utilizar identificadores más descriptivos del dominio del problema. | No |
| `0x0001h` | `prueba.c:17` | Identificador corto y poco expresivo 's2' (2 caracteres). | Se recomienda utilizar identificadores más descriptivos del dominio del problema. | No |
| `0x0001h` | `registro_csv.c:28` | Identificador de variable no descriptivo de una sola letra 'p'. | Los nombres de variables deben reflejar con precisión su propósito (salvo índices canónicos i, j, k, n, x, y, z, f, c, r). | No |
| `0x0001h` | `registro_csv.c:41` | Identificador corto y poco expresivo 'idx' (3 caracteres). | Se recomienda utilizar identificadores más descriptivos del dominio del problema. | No |
| `0x0001h` | `registro_csv.c:43` | Identificador de variable no descriptivo de una sola letra 'p'. | Los nombres de variables deben reflejar con precisión su propósito (salvo índices canónicos i, j, k, n, x, y, z, f, c, r). | No |
| `GAFF009` | `registro_csv.h:56` | La línea tiene 86 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `0x0001h` | `prueba.c:35` | Identificador corto y poco expresivo 'r0' (2 caracteres). | Se recomienda utilizar identificadores más descriptivos del dominio del problema. | No |
| `0x0001h` | `prueba.c:46` | Identificador corto y poco expresivo 'r0' (2 caracteres). | Se recomienda utilizar identificadores más descriptivos del dominio del problema. | No |
| `0x0001h` | `prueba.c:47` | Identificador corto y poco expresivo 'r1' (2 caracteres). | Se recomienda utilizar identificadores más descriptivos del dominio del problema. | No |
| `0x0001h` | `prueba.c:61` | Identificador corto y poco expresivo 'r0' (2 caracteres). | Se recomienda utilizar identificadores más descriptivos del dominio del problema. | No |
| `0x0001h` | `prueba.c:62` | Identificador corto y poco expresivo 'r1' (2 caracteres). | Se recomienda utilizar identificadores más descriptivos del dominio del problema. | No |
| `0x0001h` | `prueba.c:63` | Identificador corto y poco expresivo 'r2' (2 caracteres). | Se recomienda utilizar identificadores más descriptivos del dominio del problema. | No |
| `0x0001h` | `prueba.c:91` | Identificador corto y poco expresivo 'r0' (2 caracteres). | Se recomienda utilizar identificadores más descriptivos del dominio del problema. | No |
| `0x0001h` | `prueba.c:92` | Identificador corto y poco expresivo 'r1' (2 caracteres). | Se recomienda utilizar identificadores más descriptivos del dominio del problema. | No |
| `0x0001h` | `cadenas.c:19` | Identificador corto y poco expresivo 'len' (3 caracteres). | Se recomienda utilizar identificadores más descriptivos del dominio del problema. | No |
| `0x0001h` | `cadenas.c:106` | Identificador corto y poco expresivo 'len' (3 caracteres). | Se recomienda utilizar identificadores más descriptivos del dominio del problema. | No |
| `0x0001h` | `cadenas.c:142` | Identificador corto y poco expresivo 'len' (3 caracteres). | Se recomienda utilizar identificadores más descriptivos del dominio del problema. | No |
| `0x0001h` | `prueba.c:13` | Identificador corto y poco expresivo 'dup' (3 caracteres). | Se recomienda utilizar identificadores más descriptivos del dominio del problema. | No |
| `GAFF009` | `vector.c:64` | La línea tiene 137 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |

## Auditoría de Seguridad — Sandbox / Kaneda

⚠️ **Alerta:** Se detectaron **2** llamadas o patrones de riesgo de seguridad:

| Regla | Archivo:Línea | Severidad | Detalle | Sugerencia |
| :--- | :--- | :---: | :--- | :--- |
| `0x000Fh` | `libs/cadenas/cadenas_tp2.o:1` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'libs/cadenas/cadenas_tp2.o' (Extensión binaria prohibida '.o'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `0x000Fh` | `libs/cadenas/libcadenas.a:1` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'libs/cadenas/libcadenas.a' (Extensión binaria prohibida '.a'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |

## Antipatrones Didácticos — Spunkmeyer

Se detectaron **90** observación(es) de antipatrones didácticos:

| Regla | Ubicación | Antipatrón | Diagnóstico | Sugerencia |
| :--- | :--- | :--- | :--- | :--- |
| `0x7001h` | `prueba.c:28` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `prueba.c:46` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `vector_enteros.c:51` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x300Ah` | `vector_enteros.c:62` | **Casteo redundante de malloc()** | Castear el retorno de 'malloc()' es innecesario en C y puede enmascarar la falta de #include <stdlib.h>. | Escribí 'ptr = malloc(sizeof(*ptr) * n);' directamente. |
| `0x7001h` | `prueba.c:31` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `prueba.c:45` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `texto_dinamico.c:39` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x300Ah` | `texto_dinamico.c:40` | **Casteo redundante de malloc()** | Castear el retorno de 'malloc()' es innecesario en C y puede enmascarar la falta de #include <stdlib.h>. | Escribí 'ptr = malloc(sizeof(*ptr) * n);' directamente. |
| `0x7001h` | `texto_dinamico.c:72` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x300Ah` | `texto_dinamico.c:73` | **Casteo redundante de malloc()** | Castear el retorno de 'malloc()' es innecesario en C y puede enmascarar la falta de #include <stdlib.h>. | Escribí 'ptr = malloc(sizeof(*ptr) * n);' directamente. |
| `0x300Ah` | `texto_dinamico.c:84` | **Casteo redundante de malloc()** | Castear el retorno de 'malloc()' es innecesario en C y puede enmascarar la falta de #include <stdlib.h>. | Escribí 'ptr = malloc(sizeof(*ptr) * n);' directamente. |
| `0x300Ah` | `cadena_dinamica.c:25` | **Casteo redundante de malloc()** | Castear el retorno de 'malloc()' es innecesario en C y puede enmascarar la falta de #include <stdlib.h>. | Escribí 'ptr = malloc(sizeof(*ptr) * n);' directamente. |
| `0x300Ah` | `cadena_dinamica.c:56` | **Casteo redundante de malloc()** | Castear el retorno de 'malloc()' es innecesario en C y puede enmascarar la falta de #include <stdlib.h>. | Escribí 'ptr = malloc(sizeof(*ptr) * n);' directamente. |
| `0x7001h` | `main.c:39` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x3002h` | `main.c:53` | **Puntero colgante sin asignar NULL tras free()** | Puntero 'clon' liberado con free() pero no anulado con NULL posteriormente. | Asigná 'ptr = NULL;' inmediatamente después de 'free(ptr);'. |
| `0x3002h` | `main.c:54` | **Puntero colgante sin asignar NULL tras free()** | Puntero 'unida' liberado con free() pero no anulado con NULL posteriormente. | Asigná 'ptr = NULL;' inmediatamente después de 'free(ptr);'. |
| `0x3002h` | `prueba.c:28` | **Puntero colgante sin asignar NULL tras free()** | Puntero 'clon' liberado con free() pero no anulado con NULL posteriormente. | Asigná 'ptr = NULL;' inmediatamente después de 'free(ptr);'. |
| `0x3002h` | `prueba.c:38` | **Puntero colgante sin asignar NULL tras free()** | Puntero 'clon' liberado con free() pero no anulado con NULL posteriormente. | Asigná 'ptr = NULL;' inmediatamente después de 'free(ptr);'. |
| `0x3002h` | `prueba.c:57` | **Puntero colgante sin asignar NULL tras free()** | Puntero 'resultado' liberado con free() pero no anulado con NULL posteriormente. | Asigná 'ptr = NULL;' inmediatamente después de 'free(ptr);'. |
| `0x3002h` | `prueba.c:67` | **Puntero colgante sin asignar NULL tras free()** | Puntero 'resultado' liberado con free() pero no anulado con NULL posteriormente. | Asigná 'ptr = NULL;' inmediatamente después de 'free(ptr);'. |
| `0x7001h` | `main.c:30` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `matriz_dinamica.c:21` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x3002h` | `matriz_dinamica.c:51` | **Puntero colgante sin asignar NULL tras free()** | Puntero 'matriz' liberado con free() pero no anulado con NULL posteriormente. | Asigná 'ptr = NULL;' inmediatamente después de 'free(ptr);'. |
| `0x3002h` | `matriz_dinamica.c:52` | **Puntero colgante sin asignar NULL tras free()** | Puntero 'matriz' liberado con free() pero no anulado con NULL posteriormente. | Asigná 'ptr = NULL;' inmediatamente después de 'free(ptr);'. |
| `0x7001h` | `matriz_dinamica.c:73` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `main.c:34` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `prueba.c:23` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `registro_csv.c:27` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `consulta_csv.c:36` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x3001h` | `consulta_csv.c:63` | **Asignación múltiple a malloc en bucle sin liberación ante fallos parciales** | Reserva dinámica en bucle sin liberación de elementos previos ante fallos parciales. | En caso de fallo en una fila, liberá todas las filas asignadas previamente antes de retornar. |
| `0x7001h` | `consulta_csv.c:117` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `consulta_csv.c:157` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `main.c:15` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x3001h` | `main.c:26` | **Asignación múltiple a malloc en bucle sin liberación ante fallos parciales** | Reserva dinámica en bucle sin liberación de elementos previos ante fallos parciales. | En caso de fallo en una fila, liberá todas las filas asignadas previamente antes de retornar. |
| `0x3008h` | `main.c:72` | **Chequeo innecesario antes de free()** | Comprobar 'if (ptr != NULL)' antes de invocar 'free(ptr)' es redundante. | Invocá 'free(ptr);' directamente sin envolverlo en un if. |
| `0x7001h` | `main.c:90` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x3008h` | `main.c:92` | **Chequeo innecesario antes de free()** | Comprobar 'if (ptr != NULL)' antes de invocar 'free(ptr)' es redundante. | Invocá 'free(ptr);' directamente sin envolverlo en un if. |
| `0x7001h` | `main.c:95` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x3002h` | `main.c:101` | **Puntero colgante sin asignar NULL tras free()** | Puntero 'promedios' liberado con free() pero no anulado con NULL posteriormente. | Asigná 'ptr = NULL;' inmediatamente después de 'free(ptr);'. |
| `0x3002h` | `main.c:119` | **Puntero colgante sin asignar NULL tras free()** | Puntero 'filtrada' liberado con free() pero no anulado con NULL posteriormente. | Asigná 'ptr = NULL;' inmediatamente después de 'free(ptr);'. |
| `0x7001h` | `prueba.c:18` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x3002h` | `prueba.c:24` | **Puntero colgante sin asignar NULL tras free()** | Puntero 'matriz' liberado con free() pero no anulado con NULL posteriormente. | Asigná 'ptr = NULL;' inmediatamente después de 'free(ptr);'. |
| `0x7001h` | `prueba.c:35` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `prueba.c:79` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x301Fh` | `prueba.c:81` | **Comparación de igualdad estricta en punto flotante** | Comparación de igualdad estricta ('==') sobre tipo de coma flotante. | Compará con una tolerancia épsilon: 'fabs(a - b) < 0.00001'. |
| `0x301Fh` | `prueba.c:82` | **Comparación de igualdad estricta en punto flotante** | Comparación de igualdad estricta ('==') sobre tipo de coma flotante. | Compará con una tolerancia épsilon: 'fabs(a - b) < 0.00001'. |
| `0x301Fh` | `prueba.c:83` | **Comparación de igualdad estricta en punto flotante** | Comparación de igualdad estricta ('==') sobre tipo de coma flotante. | Compará con una tolerancia épsilon: 'fabs(a - b) < 0.00001'. |
| `0x3002h` | `prueba.c:85` | **Puntero colgante sin asignar NULL tras free()** | Puntero 'promedios' liberado con free() pero no anulado con NULL posteriormente. | Asigná 'ptr = NULL;' inmediatamente después de 'free(ptr);'. |
| `0x7001h` | `prueba.c:55` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `prueba.c:68` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x200Ah` | `p1_arrays.h:60` | **Función con excesiva cantidad de parámetros (> 5)** | Función '_p1_fail_array_double' declara 9 parámetros (máximo recomendado: 5). | Agrupá los parámetros relacionados en una estructura 'struct params_t'. |
| `0x200Ah` | `p1_arrays.h:98` | **Función con excesiva cantidad de parámetros (> 5)** | Función '_p1_fail_array_sorted' declara 8 parámetros (máximo recomendado: 5). | Agrupá los parámetros relacionados en una estructura 'struct params_t'. |
| `0x200Ah` | `p1_arrays.h:136` | **Función con excesiva cantidad de parámetros (> 5)** | Función '_p1_fail_str_array' declara 7 parámetros (máximo recomendado: 5). | Agrupá los parámetros relacionados en una estructura 'struct params_t'. |
| `0x200Ah` | `p1_arrays.h:172` | **Función con excesiva cantidad de parámetros (> 5)** | Función '_p1_fail_array_contains' declara 6 parámetros (máximo recomendado: 5). | Agrupá los parámetros relacionados en una estructura 'struct params_t'. |
| `0x200Ah` | `p1_files.h:23` | **Función con excesiva cantidad de parámetros (> 5)** | Función '_p1_fail_file_exists' declara 6 parámetros (máximo recomendado: 5). | Agrupá los parámetros relacionados en una estructura 'struct params_t'. |
| `0x200Ah` | `p1_files.h:68` | **Función con excesiva cantidad de parámetros (> 5)** | Función '_p1_fail_file_line' declara 7 parámetros (máximo recomendado: 5). | Agrupá los parámetros relacionados en una estructura 'struct params_t'. |
| `0x200Ah` | `p1_files.h:105` | **Función con excesiva cantidad de parámetros (> 5)** | Función '_p1_fail_file_contains' declara 6 parámetros (máximo recomendado: 5). | Agrupá los parámetros relacionados en una estructura 'struct params_t'. |
| `0x200Ah` | `p1_files.h:140` | **Función con excesiva cantidad de parámetros (> 5)** | Función '_p1_fail_file_bin' declara 7 parámetros (máximo recomendado: 5). | Agrupá los parámetros relacionados en una estructura 'struct params_t'. |
| `0x7001h` | `p1_stdio.h:173` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `p1_stdio.h:234` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `p1_test.h:182` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x200Ah` | `p1_test.h:330` | **Función con excesiva cantidad de parámetros (> 5)** | Función '_p1_fail_int' declara 7 parámetros (máximo recomendado: 5). | Agrupá los parámetros relacionados en una estructura 'struct params_t'. |
| `0x200Ah` | `p1_test.h:363` | **Función con excesiva cantidad de parámetros (> 5)** | Función '_p1_fail_int_between' declara 7 parámetros (máximo recomendado: 5). | Agrupá los parámetros relacionados en una estructura 'struct params_t'. |
| `0x200Ah` | `p1_test.h:398` | **Función con excesiva cantidad de parámetros (> 5)** | Función '_p1_fail_uint' declara 7 parámetros (máximo recomendado: 5). | Agrupá los parámetros relacionados en una estructura 'struct params_t'. |
| `0x200Ah` | `p1_test.h:432` | **Función con excesiva cantidad de parámetros (> 5)** | Función '_p1_fail_double' declara 7 parámetros (máximo recomendado: 5). | Agrupá los parámetros relacionados en una estructura 'struct params_t'. |
| `0x200Ah` | `p1_test.h:467` | **Función con excesiva cantidad de parámetros (> 5)** | Función '_p1_fail_double_rel' declara 7 parámetros (máximo recomendado: 5). | Agrupá los parámetros relacionados en una estructura 'struct params_t'. |
| `0x7001h` | `p1_test.h:473` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x200Ah` | `p1_test.h:507` | **Función con excesiva cantidad de parámetros (> 5)** | Función '_p1_fail_str' declara 7 parámetros (máximo recomendado: 5). | Agrupá los parámetros relacionados en una estructura 'struct params_t'. |
| `0x200Ah` | `p1_test.h:543` | **Función con excesiva cantidad de parámetros (> 5)** | Función '_p1_fail_ptr' declara 7 parámetros (máximo recomendado: 5). | Agrupá los parámetros relacionados en una estructura 'struct params_t'. |
| `0x200Ah` | `p1_test.h:583` | **Función con excesiva cantidad de parámetros (> 5)** | Función '_p1_fail_array_int' declara 7 parámetros (máximo recomendado: 5). | Agrupá los parámetros relacionados en una estructura 'struct params_t'. |
| `0x200Ah` | `p1_test.h:620` | **Función con excesiva cantidad de parámetros (> 5)** | Función '_p1_fail_mem' declara 10 parámetros (máximo recomendado: 5). | Agrupá los parámetros relacionados en una estructura 'struct params_t'. |
| `0x7001h` | `p1_test.h:638` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x1005h` | `p1_test.h:643` | **Comparación entre tipos enteros con y sin signo en condición** | Comparación entre tipos con signo ('int') y sin signo ('size_t') entre 'i' y 'end'. | Utilizá tipos consistentes (ambos 'size_t' o casteá de forma controlada tras verificar que i >= 0). |
| `0x1005h` | `p1_test.h:649` | **Comparación entre tipos enteros con y sin signo en condición** | Comparación entre tipos con signo ('int') y sin signo ('size_t') entre 'i' y 'end'. | Utilizá tipos consistentes (ambos 'size_t' o casteá de forma controlada tras verificar que i >= 0). |
| `0x7001h` | `p1_test.h:699` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `p1_test.h:842` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x1003h` | `p1_test.h:881` | **Modificación de variable de control dentro del cuerpo del for** | Variable de control 'i' modificada dentro del cuerpo del bucle for. | Si la lógica de avance no es regular o depende de condiciones dinámicas, utilizá un bucle 'while'. |
| `0x7001h` | `prueba.c:39` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `prueba.c:72` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x4001h` | `prueba.c:74` | **Omisión de verificación de retorno NULL en fopen()** | Uso de descriptor de archivo 'f' devuelto por fopen() en línea 72 sin comprobación previa de NULL. | Verificá siempre 'if (f == NULL)' inmediatamente después de invocar 'fopen()'. |
| `0x7001h` | `prueba.c:95` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x300Ah` | `cadenas.c:27` | **Casteo redundante de malloc()** | Castear el retorno de 'malloc()' es innecesario en C y puede enmascarar la falta de #include <stdlib.h>. | Escribí 'ptr = malloc(sizeof(*ptr) * n);' directamente. |
| `0x3008h` | `cadenas.c:83` | **Chequeo innecesario antes de free()** | Comprobar 'if (ptr != NULL)' antes de invocar 'free(ptr)' es redundante. | Invocá 'free(ptr);' directamente sin envolverlo en un if. |
| `0x7001h` | `prueba.c:13` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `prueba.c:27` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `prueba.c:16` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `prueba.c:38` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x300Ah` | `vector.c:20` | **Casteo redundante de malloc()** | Castear el retorno de 'malloc()' es innecesario en C y puede enmascarar la falta de #include <stdlib.h>. | Escribí 'ptr = malloc(sizeof(*ptr) * n);' directamente. |
| `0x3008h` | `vector.c:32` | **Chequeo innecesario antes de free()** | Comprobar 'if (ptr != NULL)' antes de invocar 'free(ptr)' es redundante. | Invocá 'free(ptr);' directamente sin envolverlo en un if. |
| `0x3002h` | `vector.c:51` | **Puntero colgante sin asignar NULL tras free()** | Puntero 'bloque' liberado con free() pero no anulado con NULL posteriormente. | Asigná 'ptr = NULL;' inmediatamente después de 'free(ptr);'. |

### 🔍 Detalle Pedagógico de Antipatrones

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
- **Ubicación:** `vector_enteros.c:51`
```c
        size_t i = 0;
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

#### Regla `0x300Ah`: Casteo redundante de malloc()
- **Ubicación:** `vector_enteros.c:62`
```c
            array_pares = (int *)malloc((*cantidad_pares) * sizeof(int));
```
- **Explicación:** En C, 'void*' se promociona automáticamente a cualquier tipo de puntero. Castear '(tipo*)malloc()' proviene de C++ y es una mala práctica en C.
- **Sugerencia:** Escribí 'ptr = malloc(sizeof(*ptr) * n);' directamente.
- **Ejemplo incorrecto:**
```c
int *ptr = (int *)malloc(sizeof(int) * 10);
```
- **Ejemplo recomendado:**
```c
int *ptr = malloc(sizeof(*ptr) * 10);
```

#### Regla `0x7001h`: Declaración de variable mezclada tras sentencias ejecutables
- **Ubicación:** `prueba.c:31`
```c
    char *limpio = cadena_recortar_espacios("   hola mundo   ");
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
- **Ubicación:** `texto_dinamico.c:39`
```c
            size_t len = (size_t)(ptr_fin - ptr_inicio) + 1;
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

#### Regla `0x300Ah`: Casteo redundante de malloc()
- **Ubicación:** `texto_dinamico.c:40`
```c
            nueva_cadena = (char *)malloc((len + 1) * sizeof(char));
```
- **Explicación:** En C, 'void*' se promociona automáticamente a cualquier tipo de puntero. Castear '(tipo*)malloc()' proviene de C++ y es una mala práctica en C.
- **Sugerencia:** Escribí 'ptr = malloc(sizeof(*ptr) * n);' directamente.
- **Ejemplo incorrecto:**
```c
int *ptr = (int *)malloc(sizeof(int) * 10);
```
- **Ejemplo recomendado:**
```c
int *ptr = malloc(sizeof(*ptr) * 10);
```

#### Regla `0x7001h`: Declaración de variable mezclada tras sentencias ejecutables
- **Ubicación:** `texto_dinamico.c:72`
```c
        size_t q_reservar = (len * veces) + 1;
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

#### Regla `0x300Ah`: Casteo redundante de malloc()
- **Ubicación:** `texto_dinamico.c:73`
```c
        nueva_cadena = (char *)calloc(q_reservar, sizeof(char));
```
- **Explicación:** En C, 'void*' se promociona automáticamente a cualquier tipo de puntero. Castear '(tipo*)malloc()' proviene de C++ y es una mala práctica en C.
- **Sugerencia:** Escribí 'ptr = malloc(sizeof(*ptr) * n);' directamente.
- **Ejemplo incorrecto:**
```c
int *ptr = (int *)malloc(sizeof(int) * 10);
```
- **Ejemplo recomendado:**
```c
int *ptr = malloc(sizeof(*ptr) * 10);
```

#### Regla `0x300Ah`: Casteo redundante de malloc()
- **Ubicación:** `texto_dinamico.c:84`
```c
        nueva_cadena = (char *)calloc(1, sizeof(char));
```
- **Explicación:** En C, 'void*' se promociona automáticamente a cualquier tipo de puntero. Castear '(tipo*)malloc()' proviene de C++ y es una mala práctica en C.
- **Sugerencia:** Escribí 'ptr = malloc(sizeof(*ptr) * n);' directamente.
- **Ejemplo incorrecto:**
```c
int *ptr = (int *)malloc(sizeof(int) * 10);
```
- **Ejemplo recomendado:**
```c
int *ptr = malloc(sizeof(*ptr) * 10);
```

#### Regla `0x300Ah`: Casteo redundante de malloc()
- **Ubicación:** `cadena_dinamica.c:25`
```c
        nueva_cadena = (char *)malloc((len + 1) * sizeof(char));
```
- **Explicación:** En C, 'void*' se promociona automáticamente a cualquier tipo de puntero. Castear '(tipo*)malloc()' proviene de C++ y es una mala práctica en C.
- **Sugerencia:** Escribí 'ptr = malloc(sizeof(*ptr) * n);' directamente.
- **Ejemplo incorrecto:**
```c
int *ptr = (int *)malloc(sizeof(int) * 10);
```
- **Ejemplo recomendado:**
```c
int *ptr = malloc(sizeof(*ptr) * 10);
```

#### Regla `0x300Ah`: Casteo redundante de malloc()
- **Ubicación:** `cadena_dinamica.c:56`
```c
        concatenada = (char *)calloc(len_total, sizeof(char));
```
- **Explicación:** En C, 'void*' se promociona automáticamente a cualquier tipo de puntero. Castear '(tipo*)malloc()' proviene de C++ y es una mala práctica en C.
- **Sugerencia:** Escribí 'ptr = malloc(sizeof(*ptr) * n);' directamente.
- **Ejemplo incorrecto:**
```c
int *ptr = (int *)malloc(sizeof(int) * 10);
```
- **Ejemplo recomendado:**
```c
int *ptr = malloc(sizeof(*ptr) * 10);
```

#### Regla `0x7001h`: Declaración de variable mezclada tras sentencias ejecutables
- **Ubicación:** `main.c:39`
```c
    char *clon = clonar_cadena(buffer1);
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
- **Ubicación:** `main.c:53`
```c
    free(clon);
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

#### Regla `0x3002h`: Puntero colgante sin asignar NULL tras free()
- **Ubicación:** `main.c:54`
```c
    free(unida);
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

#### Regla `0x3002h`: Puntero colgante sin asignar NULL tras free()
- **Ubicación:** `prueba.c:28`
```c
    free(clon);
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

#### Regla `0x3002h`: Puntero colgante sin asignar NULL tras free()
- **Ubicación:** `prueba.c:38`
```c
    free(clon);
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

#### Regla `0x3002h`: Puntero colgante sin asignar NULL tras free()
- **Ubicación:** `prueba.c:57`
```c
    free(resultado);
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

#### Regla `0x3002h`: Puntero colgante sin asignar NULL tras free()
- **Ubicación:** `prueba.c:67`
```c
    free(resultado);
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
- **Ubicación:** `main.c:30`
```c
    int **matriz = matriz_crear(filas, columnas);
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
- **Ubicación:** `matriz_dinamica.c:21`
```c
    int *datos = malloc(filas * columnas * sizeof(int));
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
- **Ubicación:** `matriz_dinamica.c:51`
```c
    free(matriz[0]);
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

#### Regla `0x3002h`: Puntero colgante sin asignar NULL tras free()
- **Ubicación:** `matriz_dinamica.c:52`
```c
    free(matriz);
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
- **Ubicación:** `matriz_dinamica.c:73`
```c
    FILE *f = fopen(ruta_archivo, "r");
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
- **Ubicación:** `main.c:34`
```c
    char **tokens = dividir_linea_csv(linea, delimitador, &cant_tokens);
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
- **Ubicación:** `prueba.c:23`
```c
    size_t i = 0;
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
- **Ubicación:** `registro_csv.c:27`
```c
    size_t cant = 1;
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
- **Ubicación:** `consulta_csv.c:36`
```c
    size_t contador = 0;
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

#### Regla `0x3001h`: Asignación múltiple a malloc en bucle sin liberación ante fallos parciales
- **Ubicación:** `consulta_csv.c:63`
```c
    while (i < filas && !error_memoria)
```
- **Explicación:** Si la asignación de la fila k falla y la función retorna NULL inmediatamente, las filas 0 a k-1 quedan como fugas de memoria irrecuperables (memory leak).
- **Sugerencia:** En caso de fallo en una fila, liberá todas las filas asignadas previamente antes de retornar.
- **Ejemplo incorrecto:**
```c
for (int i = 0; i < n; i++) {
    mat[i] = malloc(m * sizeof(int));
}
```
- **Ejemplo recomendado:**
```c
for (int i = 0; i < n; i++) {
    mat[i] = malloc(m * sizeof(int));
    if (!mat[i]) { /* liberar mat[0..i-1] y retornar NULL */ }
}
```

#### Regla `0x7001h`: Declaración de variable mezclada tras sentencias ejecutables
- **Ubicación:** `consulta_csv.c:117`
```c
    float *promedios = malloc(columnas * sizeof(float));
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
- **Ubicación:** `consulta_csv.c:157`
```c
    FILE *archivo = fopen(ruta_archivo, "w");
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
- **Ubicación:** `main.c:15`
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

#### Regla `0x3001h`: Asignación múltiple a malloc en bucle sin liberación ante fallos parciales
- **Ubicación:** `main.c:26`
```c
    while (i < filas)
```
- **Explicación:** Si la asignación de la fila k falla y la función retorna NULL inmediatamente, las filas 0 a k-1 quedan como fugas de memoria irrecuperables (memory leak).
- **Sugerencia:** En caso de fallo en una fila, liberá todas las filas asignadas previamente antes de retornar.
- **Ejemplo incorrecto:**
```c
for (int i = 0; i < n; i++) {
    mat[i] = malloc(m * sizeof(int));
}
```
- **Ejemplo recomendado:**
```c
for (int i = 0; i < n; i++) {
    mat[i] = malloc(m * sizeof(int));
    if (!mat[i]) { /* liberar mat[0..i-1] y retornar NULL */ }
}
```

#### Regla `0x3008h`: Chequeo innecesario antes de free()
- **Ubicación:** `main.c:72`
```c
    if (filtrada != NULL)
```
- **Explicación:** La especificación del estándar ISO C garantiza que 'free(NULL)' es una operación segura y no realiza ninguna acción.
- **Sugerencia:** Invocá 'free(ptr);' directamente sin envolverlo en un if.
- **Ejemplo incorrecto:**
```c
if (ptr != NULL) {
    free(ptr);
}
```
- **Ejemplo recomendado:**
```c
free(ptr);
```

#### Regla `0x7001h`: Declaración de variable mezclada tras sentencias ejecutables
- **Ubicación:** `main.c:90`
```c
        float *promedios =
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

#### Regla `0x3008h`: Chequeo innecesario antes de free()
- **Ubicación:** `main.c:92`
```c
        if (promedios != NULL)
```
- **Explicación:** La especificación del estándar ISO C garantiza que 'free(NULL)' es una operación segura y no realiza ninguna acción.
- **Sugerencia:** Invocá 'free(ptr);' directamente sin envolverlo en un if.
- **Ejemplo incorrecto:**
```c
if (ptr != NULL) {
    free(ptr);
}
```
- **Ejemplo recomendado:**
```c
free(ptr);
```

#### Regla `0x7001h`: Declaración de variable mezclada tras sentencias ejecutables
- **Ubicación:** `main.c:95`
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

#### Regla `0x3002h`: Puntero colgante sin asignar NULL tras free()
- **Ubicación:** `main.c:101`
```c
            free(promedios);
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

#### Regla `0x3002h`: Puntero colgante sin asignar NULL tras free()
- **Ubicación:** `main.c:119`
```c
        free(filtrada);
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
- **Ubicación:** `prueba.c:18`
```c
    size_t i = 0;
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
- **Ubicación:** `prueba.c:24`
```c
    free(matriz);
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
- **Ubicación:** `prueba.c:35`
```c
    int r0[] = {10, 20};
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
- **Ubicación:** `prueba.c:79`
```c
    float *promedios = matriz_calcular_promedios(filtrada, filas_filtradas, 3);
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

#### Regla `0x301Fh`: Comparación de igualdad estricta en punto flotante
- **Ubicación:** `prueba.c:81`
```c
    ASSERT_TRUE(promedios[0] == 25.0f); // (10 + 40) / 2
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
- **Ubicación:** `prueba.c:82`
```c
    ASSERT_TRUE(promedios[1] == 15.0f); // (20 + 10) / 2
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
- **Ubicación:** `prueba.c:83`
```c
    ASSERT_TRUE(promedios[2] == 45.0f); // (30 + 60) / 2
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

#### Regla `0x3002h`: Puntero colgante sin asignar NULL tras free()
- **Ubicación:** `prueba.c:85`
```c
    free(promedios);
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
- **Ubicación:** `prueba.c:55`
```c
    char limitado[8];
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
    size_t conteo = cadena_a_mayusculas(texto, sizeof(texto));
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
- **Ubicación:** `p1_arrays.h:60`
```c
    static inline void _p1_fail_array_double(const char *file, int line,
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
- **Ubicación:** `p1_arrays.h:98`
```c
    static inline void _p1_fail_array_sorted(const char *file, int line,
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
- **Ubicación:** `p1_arrays.h:136`
```c
    static inline void _p1_fail_str_array(const char *file, int line,
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
- **Ubicación:** `p1_arrays.h:172`
```c
    static inline void _p1_fail_array_contains(const char *file, int line,
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
- **Ubicación:** `p1_files.h:23`
```c
    static inline void _p1_fail_file_exists(const char *file, int line,
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
- **Ubicación:** `p1_files.h:68`
```c
    static inline void _p1_fail_file_line(const char *file, int line,
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
- **Ubicación:** `p1_files.h:105`
```c
    static inline void _p1_fail_file_contains(const char *file, int line,
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
- **Ubicación:** `p1_files.h:140`
```c
    static inline void _p1_fail_file_bin(const char *file, int line,
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
- **Ubicación:** `p1_stdio.h:173`
```c
            size_t n =
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
- **Ubicación:** `p1_stdio.h:234`
```c
            size_t n =
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
- **Ubicación:** `p1_test.h:182`
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
- **Ubicación:** `p1_test.h:330`
```c
    static inline void _p1_fail_int(const char *file, int line,
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
    static inline void _p1_fail_int_between(const char *file, int line,
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
- **Ubicación:** `p1_test.h:398`
```c
    static inline void _p1_fail_uint(const char *file, int line,
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
- **Ubicación:** `p1_test.h:432`
```c
    static inline void _p1_fail_double(const char *file, int line,
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
- **Ubicación:** `p1_test.h:467`
```c
    static inline void _p1_fail_double_rel(const char *file, int line,
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
- **Ubicación:** `p1_test.h:473`
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
- **Ubicación:** `p1_test.h:507`
```c
    static inline void _p1_fail_str(const char *file, int line,
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
- **Ubicación:** `p1_test.h:543`
```c
    static inline void _p1_fail_ptr(const char *file, int line,
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
- **Ubicación:** `p1_test.h:583`
```c
    static inline void _p1_fail_array_int(const char *file, int line,
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
- **Ubicación:** `p1_test.h:620`
```c
    static inline void _p1_fail_mem(const char *file, int line,
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
- **Ubicación:** `p1_test.h:638`
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
- **Ubicación:** `p1_test.h:643`
```c
            for (size_t i = start; i < end; i++)
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
- **Ubicación:** `p1_test.h:649`
```c
            for (size_t i = start; i < end; i++)
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
- **Ubicación:** `p1_test.h:699`
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
- **Ubicación:** `p1_test.h:842`
```c
            size_t n =
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
- **Ubicación:** `p1_test.h:881`
```c
        for (int i = 1; i < argc; i++)
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
- **Ubicación:** `prueba.c:39`
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
- **Ubicación:** `prueba.c:72`
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
- **Ubicación:** `prueba.c:74`
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
- **Ubicación:** `prueba.c:95`
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

#### Regla `0x300Ah`: Casteo redundante de malloc()
- **Ubicación:** `cadenas.c:27`
```c
        destino = (char *)malloc(len + 1);
```
- **Explicación:** En C, 'void*' se promociona automáticamente a cualquier tipo de puntero. Castear '(tipo*)malloc()' proviene de C++ y es una mala práctica en C.
- **Sugerencia:** Escribí 'ptr = malloc(sizeof(*ptr) * n);' directamente.
- **Ejemplo incorrecto:**
```c
int *ptr = (int *)malloc(sizeof(int) * 10);
```
- **Ejemplo recomendado:**
```c
int *ptr = malloc(sizeof(*ptr) * 10);
```

#### Regla `0x3008h`: Chequeo innecesario antes de free()
- **Ubicación:** `cadenas.c:83`
```c
    if (puntero_cadena != NULL && *puntero_cadena != NULL)
```
- **Explicación:** La especificación del estándar ISO C garantiza que 'free(NULL)' es una operación segura y no realiza ninguna acción.
- **Sugerencia:** Invocá 'free(ptr);' directamente sin envolverlo en un if.
- **Ejemplo incorrecto:**
```c
if (ptr != NULL) {
    free(ptr);
}
```
- **Ejemplo recomendado:**
```c
free(ptr);
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

#### Regla `0x300Ah`: Casteo redundante de malloc()
- **Ubicación:** `vector.c:20`
```c
        bloque_int = (int *)calloc(cantidad, sizeof(int));
```
- **Explicación:** En C, 'void*' se promociona automáticamente a cualquier tipo de puntero. Castear '(tipo*)malloc()' proviene de C++ y es una mala práctica en C.
- **Sugerencia:** Escribí 'ptr = malloc(sizeof(*ptr) * n);' directamente.
- **Ejemplo incorrecto:**
```c
int *ptr = (int *)malloc(sizeof(int) * 10);
```
- **Ejemplo recomendado:**
```c
int *ptr = malloc(sizeof(*ptr) * 10);
```

#### Regla `0x3008h`: Chequeo innecesario antes de free()
- **Ubicación:** `vector.c:32`
```c
    if (puntero_bloque != NULL && *puntero_bloque != NULL)
```
- **Explicación:** La especificación del estándar ISO C garantiza que 'free(NULL)' es una operación segura y no realiza ninguna acción.
- **Sugerencia:** Invocá 'free(ptr);' directamente sin envolverlo en un if.
- **Ejemplo incorrecto:**
```c
if (ptr != NULL) {
    free(ptr);
}
```
- **Ejemplo recomendado:**
```c
free(ptr);
```

#### Regla `0x3002h`: Puntero colgante sin asignar NULL tras free()
- **Ubicación:** `vector.c:51`
```c
        free(bloque);
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

# Informe de Corrección — TP4 (fc0a9b3)

## Repositorio
**branch/revision:** `main` `fc0a9b3`
**Commit SHA:** `fc0a9b3f2f09b0276d0077482adb785ae81924db`
**Autor:** `anon_020`
**Fecha del commit:** `2026-09-30 20:19:06 -0300`
**Mensaje:** `Librerias y Ejercicios completos`
**Fecha de evaluación:** 2026-10-02 14:03:51
**Versión revisada:** `fc0a9b3`

## Especificación de la Guía
**Guía vinculada:** `Trabajo Práctico 4: Memoria Dinámica en C11 (Sin Structs)`
**Ejercicios requeridos:** `libvector (Biblioteca de Bloques Dinámicos (libvector))`, `libstring (Biblioteca de Cadenas Dinámicas (libstring))`, `ejercicio1 (Clonación y Filtrado Dinámico de Enteros)`, `ejercicio2 (Normalización y Recorte Dinámico de Cadenas)`, `ejercicio3 (Reversión y Particionado Dinámico de Cadenas)`, `ejercicio4 (Bloque Contiguo 2D Simulado en Heap)`, `ejercicio5 (Tokenización y Listas de Cadenas en Heap (char**))`, `ejercicio6 (Procesamiento de Texto Dinámico Multilínea)`

### Archivos contenidos
```text
.
├── ejercicios/
│   ├── ejercicio1/
│   │   ├── main.c
│   │   ├── main.o
│   │   ├── Makefile
│   │   ├── programa
│   │   ├── prueba.c
│   │   ├── prueba.o
│   │   ├── test_bin
│   │   ├── vector_enteros.c
│   │   ├── vector_enteros.h
│   │   └── vector_enteros.o
│   ├── ejercicio2/
│   │   ├── main.c
│   │   ├── main.o
│   │   ├── Makefile
│   │   ├── programa
│   │   ├── prueba.c
│   │   ├── prueba.o
│   │   ├── test_bin
│   │   ├── texto_dinamico.c
│   │   ├── texto_dinamico.h
│   │   └── texto_dinamico.o
│   ├── ejercicio3/
│   │   ├── cadena_dinamica.c
│   │   ├── cadena_dinamica.h
│   │   ├── cadena_dinamica.o
│   │   ├── main.c
│   │   ├── main.o
│   │   ├── Makefile
│   │   ├── programa
│   │   ├── prueba.c
│   │   ├── prueba.o
│   │   └── test_bin
│   ├── ejercicio4/
│   │   ├── main.c
│   │   ├── main.o
│   │   ├── Makefile
│   │   ├── matriz_dinamica.c
│   │   ├── matriz_dinamica.h
│   │   ├── matriz_dinamica.o
│   │   ├── programa
│   │   ├── prueba.c
│   │   ├── prueba.o
│   │   └── test_bin
│   ├── ejercicio5/
│   │   ├── main.c
│   │   ├── main.o
│   │   ├── Makefile
│   │   ├── programa
│   │   ├── prueba.c
│   │   ├── prueba.o
│   │   ├── registro_csv.c
│   │   ├── registro_csv.h
│   │   ├── registro_csv.o
│   │   └── test_bin
│   └── ejercicio6/
│       ├── consulta_csv.c
│       ├── consulta_csv.h
│       ├── consulta_csv.o
│       ├── main.c
│       ├── Makefile
│       ├── prueba.c
│       ├── prueba.o
│       └── test_bin
├── libs/
│   ├── consola/
│   │   ├── consola.c
│   │   ├── consola.h
│   │   ├── consola.o
│   │   ├── libconsola.a
│   │   ├── Makefile
│   │   ├── prueba.c
│   │   ├── prueba.o
│   │   └── test_bin
│   ├── p1_test/
│   │   ├── build/
│   │   │   ├── libp1_test.a
│   │   │   └── p1_test.o
│   │   ├── docs/
│   │   │   └── p1_test_manual.md
│   │   ├── include/
│   │   │   ├── p1_arrays.h
│   │   │   ├── p1_files.h
│   │   │   ├── p1_stdio.h
│   │   │   └── p1_test.h
│   │   ├── src/
│   │   │   └── p1_test.c
│   │   ├── libp1_test.a
│   │   ├── library.json
│   │   ├── library.spec
│   │   ├── Makefile
│   │   ├── p1_arrays.h
│   │   ├── p1_files.h
│   │   ├── p1_stdio.h
│   │   ├── p1_test.h
│   │   ├── prueba.c
│   │   ├── prueba.o
│   │   └── test_bin
│   ├── punteros/
│   │   ├── libpunteros.a
│   │   ├── Makefile
│   │   ├── prueba.c
│   │   ├── prueba.o
│   │   ├── punteros.c
│   │   ├── punteros.h
│   │   ├── punteros.o
│   │   └── test_bin
│   ├── string/
│   │   ├── cadenas.c
│   │   ├── cadenas.h
│   │   ├── cadenas.o
│   │   ├── libstring.a
│   │   ├── Makefile
│   │   ├── prueba.c
│   │   ├── prueba.o
│   │   └── test_bin
│   └── vector/
│       ├── libvector.a
│       ├── Makefile
│       ├── prueba.c
│       ├── prueba.o
│       ├── test_bin
│       ├── vector.c
│       ├── vector.h
│       └── vector.o
├── Makefile
├── README.md
└── tp.sh
```

## Análisis de Código C e Informes de Herramientas

## Resumen de Evaluación por Archivo

| Archivo | Estado Compilación | Evaluación de Estilo | Valgrind (Fugas) | Observaciones Cátedra |
| :--- | :---: | :---: | :---: | :--- |
| `[ARCHIVOS_BINARIOS]` | ❌ ERROR (49 filtrados) | 0.0/10 | — | Se detectaron binarios prohibidos (.o/.exe) en la entrega |
| `cadena_dinamica.c` | ❌ Falló Compilación | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `cadenas.c` | ❌ Falló Compilación | 10.0/10 | ✓ Limpio (0 fugas) | 6 advertencias |
| `cadenas.h` | ❌ Falló Compilación | 7.5/10 | ✓ Limpio (0 fugas) | 5 advertencias |
| `consola.c` | ❌ Falló Compilación | 6.0/10 | ✓ Limpio (0 fugas) | 36 advertencias |
| `consola.h` | ❌ Falló Compilación | 6.0/10 | ✓ Limpio (0 fugas) | 8 advertencias |
| `consulta_csv.c` | ❌ Falló Compilación | 10.0/10 | ✓ Limpio (0 fugas) | 28 advertencias |
| `ejercicios/ejercicio1/main.o` | ❌ Falló Compilación | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `ejercicios/ejercicio1/programa` | ❌ Falló Compilación | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `ejercicios/ejercicio1/prueba.o` | ❌ Falló Compilación | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `ejercicios/ejercicio1/test_bin` | ❌ Falló Compilación | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `ejercicios/ejercicio1/vector_enteros.o` | ❌ Falló Compilación | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `ejercicios/ejercicio2/main.o` | ❌ Falló Compilación | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `ejercicios/ejercicio2/programa` | ❌ Falló Compilación | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `ejercicios/ejercicio2/prueba.o` | ❌ Falló Compilación | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `ejercicios/ejercicio2/test_bin` | ❌ Falló Compilación | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `ejercicios/ejercicio2/texto_dinamico.o` | ❌ Falló Compilación | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `ejercicios/ejercicio3/cadena_dinamica.o` | ❌ Falló Compilación | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `ejercicios/ejercicio3/main.o` | ❌ Falló Compilación | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `ejercicios/ejercicio3/programa` | ❌ Falló Compilación | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `ejercicios/ejercicio3/prueba.o` | ❌ Falló Compilación | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `ejercicios/ejercicio3/test_bin` | ❌ Falló Compilación | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `ejercicios/ejercicio4/main.o` | ❌ Falló Compilación | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `ejercicios/ejercicio4/matriz_dinamica.o` | ❌ Falló Compilación | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `ejercicios/ejercicio4/programa` | ❌ Falló Compilación | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `ejercicios/ejercicio4/prueba.o` | ❌ Falló Compilación | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `ejercicios/ejercicio4/test_bin` | ❌ Falló Compilación | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `ejercicios/ejercicio5/main.o` | ❌ Falló Compilación | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `ejercicios/ejercicio5/programa` | ❌ Falló Compilación | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `ejercicios/ejercicio5/prueba.o` | ❌ Falló Compilación | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `ejercicios/ejercicio5/registro_csv.o` | ❌ Falló Compilación | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `ejercicios/ejercicio5/test_bin` | ❌ Falló Compilación | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `ejercicios/ejercicio6/consulta_csv.o` | ❌ Falló Compilación | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `ejercicios/ejercicio6/prueba.o` | ❌ Falló Compilación | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `ejercicios/ejercicio6/test_bin` | ❌ Falló Compilación | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `libs/consola/consola.o` | ❌ Falló Compilación | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `libs/consola/libconsola.a` | ❌ Falló Compilación | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `libs/consola/prueba.o` | ❌ Falló Compilación | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `libs/consola/test_bin` | ❌ Falló Compilación | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `libs/p1_test/build/libp1_test.a` | ❌ Falló Compilación | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `libs/p1_test/build/p1_test.o` | ❌ Falló Compilación | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `libs/p1_test/libp1_test.a` | ❌ Falló Compilación | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `libs/p1_test/prueba.o` | ❌ Falló Compilación | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `libs/p1_test/test_bin` | ❌ Falló Compilación | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `libs/punteros/libpunteros.a` | ❌ Falló Compilación | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `libs/punteros/prueba.o` | ❌ Falló Compilación | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `libs/punteros/punteros.o` | ❌ Falló Compilación | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `libs/punteros/test_bin` | ❌ Falló Compilación | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `libs/string/cadenas.o` | ❌ Falló Compilación | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `libs/string/libstring.a` | ❌ Falló Compilación | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `libs/string/prueba.o` | ❌ Falló Compilación | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `libs/string/test_bin` | ❌ Falló Compilación | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `libs/vector/libvector.a` | ❌ Falló Compilación | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `libs/vector/prueba.o` | ❌ Falló Compilación | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `libs/vector/test_bin` | ❌ Falló Compilación | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `libs/vector/vector.o` | ❌ Falló Compilación | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `main.c` | ❌ Falló Compilación | 10.0/10 | ✓ Limpio (0 fugas) | 30 advertencias |
| `matriz_dinamica.c` | ❌ Falló Compilación | 9.0/10 | ✓ Limpio (0 fugas) | 24 advertencias |
| `matriz_dinamica.h` | ❌ Falló Compilación | 9.0/10 | ✓ Limpio (0 fugas) | 2 advertencias |
| `prueba.c` | ❌ Falló Compilación | 4.0/10 | ✓ Limpio (0 fugas) | 120 advertencias |
| `punteros.c` | ❌ Falló Compilación | 8.5/10 | ✓ Limpio (0 fugas) | 14 advertencias |
| `punteros.h` | ❌ Falló Compilación | 8.0/10 | ✓ Limpio (0 fugas) | 4 advertencias |
| `registro_csv.c` | ❌ Falló Compilación | 10.0/10 | ✓ Limpio (0 fugas) | 24 advertencias |
| `texto_dinamico.c` | ❌ Falló Compilación | 9.5/10 | ✓ Limpio (0 fugas) | 8 advertencias |
| `texto_dinamico.h` | ❌ Falló Compilación | 8.5/10 | ✓ Limpio (0 fugas) | 3 advertencias |
| `vector.c` | ❌ Falló Compilación | 9.5/10 | ✓ Limpio (0 fugas) | 15 advertencias |
| `vector.h` | ❌ Falló Compilación | 5.5/10 | ✓ Limpio (0 fugas) | 9 advertencias |
| `vector_enteros.c` | ❌ Falló Compilación | 9.5/10 | ✓ Limpio (0 fugas) | 3 advertencias |
| `vector_enteros.h` | ❌ Falló Compilación | 9.0/10 | ✓ Limpio (0 fugas) | 2 advertencias |

## ⚠️ Archivos Binarios Prohibidos Filtrados

> ❌ **ERROR DE ENTREGA:** Se detectaron archivos binarios precompilados o ejecutables en la entrega del estudiante. 
> Para mantener la reproducibilidad académica y evitar la ejecución de código no compilado desde fuentes, estos archivos fueron **filtrados y descartados** de la evaluación.

| Archivo Binario | Regla | Severidad | Detalle del Error | Sugerencia |
| :--- | :---: | :---: | :--- | :--- |
| `libs/consola/consola.o` | `0x000Fh` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'libs/consola/consola.o' (Extensión binaria prohibida '.o'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `libs/consola/libconsola.a` | `0x000Fh` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'libs/consola/libconsola.a' (Extensión binaria prohibida '.a'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `libs/consola/prueba.o` | `0x000Fh` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'libs/consola/prueba.o' (Extensión binaria prohibida '.o'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `libs/consola/test_bin` | `0x000Fh` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'libs/consola/test_bin' (Firma binaria ejecutable detectada (Formato ejecutable o archivo objeto Linux ELF)). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `libs/p1_test/libp1_test.a` | `0x000Fh` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'libs/p1_test/libp1_test.a' (Extensión binaria prohibida '.a'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `libs/p1_test/prueba.o` | `0x000Fh` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'libs/p1_test/prueba.o' (Extensión binaria prohibida '.o'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `libs/p1_test/test_bin` | `0x000Fh` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'libs/p1_test/test_bin' (Firma binaria ejecutable detectada (Formato ejecutable o archivo objeto Linux ELF)). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `libs/punteros/punteros.o` | `0x000Fh` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'libs/punteros/punteros.o' (Extensión binaria prohibida '.o'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `libs/punteros/libpunteros.a` | `0x000Fh` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'libs/punteros/libpunteros.a' (Extensión binaria prohibida '.a'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `libs/punteros/prueba.o` | `0x000Fh` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'libs/punteros/prueba.o' (Extensión binaria prohibida '.o'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `libs/punteros/test_bin` | `0x000Fh` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'libs/punteros/test_bin' (Firma binaria ejecutable detectada (Formato ejecutable o archivo objeto Linux ELF)). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `libs/string/cadenas.o` | `0x000Fh` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'libs/string/cadenas.o' (Extensión binaria prohibida '.o'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `libs/string/libstring.a` | `0x000Fh` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'libs/string/libstring.a' (Extensión binaria prohibida '.a'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `libs/string/prueba.o` | `0x000Fh` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'libs/string/prueba.o' (Extensión binaria prohibida '.o'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `libs/string/test_bin` | `0x000Fh` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'libs/string/test_bin' (Firma binaria ejecutable detectada (Formato ejecutable o archivo objeto Linux ELF)). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `libs/vector/vector.o` | `0x000Fh` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'libs/vector/vector.o' (Extensión binaria prohibida '.o'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `libs/vector/libvector.a` | `0x000Fh` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'libs/vector/libvector.a' (Extensión binaria prohibida '.a'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `libs/vector/prueba.o` | `0x000Fh` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'libs/vector/prueba.o' (Extensión binaria prohibida '.o'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `libs/vector/test_bin` | `0x000Fh` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'libs/vector/test_bin' (Firma binaria ejecutable detectada (Formato ejecutable o archivo objeto Linux ELF)). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `libs/p1_test/build/p1_test.o` | `0x000Fh` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'libs/p1_test/build/p1_test.o' (Extensión binaria prohibida '.o'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `libs/p1_test/build/libp1_test.a` | `0x000Fh` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'libs/p1_test/build/libp1_test.a' (Extensión binaria prohibida '.a'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `ejercicios/ejercicio1/main.o` | `0x000Fh` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'ejercicios/ejercicio1/main.o' (Extensión binaria prohibida '.o'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `ejercicios/ejercicio1/vector_enteros.o` | `0x000Fh` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'ejercicios/ejercicio1/vector_enteros.o' (Extensión binaria prohibida '.o'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `ejercicios/ejercicio1/programa` | `0x000Fh` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'ejercicios/ejercicio1/programa' (Firma binaria ejecutable detectada (Formato ejecutable o archivo objeto Linux ELF)). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `ejercicios/ejercicio1/prueba.o` | `0x000Fh` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'ejercicios/ejercicio1/prueba.o' (Extensión binaria prohibida '.o'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `ejercicios/ejercicio1/test_bin` | `0x000Fh` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'ejercicios/ejercicio1/test_bin' (Firma binaria ejecutable detectada (Formato ejecutable o archivo objeto Linux ELF)). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `ejercicios/ejercicio2/main.o` | `0x000Fh` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'ejercicios/ejercicio2/main.o' (Extensión binaria prohibida '.o'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `ejercicios/ejercicio2/texto_dinamico.o` | `0x000Fh` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'ejercicios/ejercicio2/texto_dinamico.o' (Extensión binaria prohibida '.o'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `ejercicios/ejercicio2/programa` | `0x000Fh` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'ejercicios/ejercicio2/programa' (Firma binaria ejecutable detectada (Formato ejecutable o archivo objeto Linux ELF)). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `ejercicios/ejercicio2/prueba.o` | `0x000Fh` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'ejercicios/ejercicio2/prueba.o' (Extensión binaria prohibida '.o'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `ejercicios/ejercicio2/test_bin` | `0x000Fh` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'ejercicios/ejercicio2/test_bin' (Firma binaria ejecutable detectada (Formato ejecutable o archivo objeto Linux ELF)). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `ejercicios/ejercicio3/main.o` | `0x000Fh` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'ejercicios/ejercicio3/main.o' (Extensión binaria prohibida '.o'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `ejercicios/ejercicio3/cadena_dinamica.o` | `0x000Fh` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'ejercicios/ejercicio3/cadena_dinamica.o' (Extensión binaria prohibida '.o'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `ejercicios/ejercicio3/programa` | `0x000Fh` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'ejercicios/ejercicio3/programa' (Firma binaria ejecutable detectada (Formato ejecutable o archivo objeto Linux ELF)). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `ejercicios/ejercicio3/prueba.o` | `0x000Fh` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'ejercicios/ejercicio3/prueba.o' (Extensión binaria prohibida '.o'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `ejercicios/ejercicio3/test_bin` | `0x000Fh` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'ejercicios/ejercicio3/test_bin' (Firma binaria ejecutable detectada (Formato ejecutable o archivo objeto Linux ELF)). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `ejercicios/ejercicio4/main.o` | `0x000Fh` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'ejercicios/ejercicio4/main.o' (Extensión binaria prohibida '.o'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `ejercicios/ejercicio4/matriz_dinamica.o` | `0x000Fh` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'ejercicios/ejercicio4/matriz_dinamica.o' (Extensión binaria prohibida '.o'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `ejercicios/ejercicio4/programa` | `0x000Fh` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'ejercicios/ejercicio4/programa' (Firma binaria ejecutable detectada (Formato ejecutable o archivo objeto Linux ELF)). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `ejercicios/ejercicio4/prueba.o` | `0x000Fh` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'ejercicios/ejercicio4/prueba.o' (Extensión binaria prohibida '.o'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `ejercicios/ejercicio4/test_bin` | `0x000Fh` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'ejercicios/ejercicio4/test_bin' (Firma binaria ejecutable detectada (Formato ejecutable o archivo objeto Linux ELF)). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `ejercicios/ejercicio5/main.o` | `0x000Fh` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'ejercicios/ejercicio5/main.o' (Extensión binaria prohibida '.o'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `ejercicios/ejercicio5/registro_csv.o` | `0x000Fh` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'ejercicios/ejercicio5/registro_csv.o' (Extensión binaria prohibida '.o'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `ejercicios/ejercicio5/programa` | `0x000Fh` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'ejercicios/ejercicio5/programa' (Firma binaria ejecutable detectada (Formato ejecutable o archivo objeto Linux ELF)). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `ejercicios/ejercicio5/prueba.o` | `0x000Fh` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'ejercicios/ejercicio5/prueba.o' (Extensión binaria prohibida '.o'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `ejercicios/ejercicio5/test_bin` | `0x000Fh` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'ejercicios/ejercicio5/test_bin' (Firma binaria ejecutable detectada (Formato ejecutable o archivo objeto Linux ELF)). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `ejercicios/ejercicio6/prueba.o` | `0x000Fh` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'ejercicios/ejercicio6/prueba.o' (Extensión binaria prohibida '.o'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `ejercicios/ejercicio6/consulta_csv.o` | `0x000Fh` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'ejercicios/ejercicio6/consulta_csv.o' (Extensión binaria prohibida '.o'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `ejercicios/ejercicio6/test_bin` | `0x000Fh` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'ejercicios/ejercicio6/test_bin' (Firma binaria ejecutable detectada (Formato ejecutable o archivo objeto Linux ELF)). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |

**Acción Requerida:** Las entregas deben contener exclusivamente código fuente editable (`.c`, `.h`), archivos de configuración (`Makefile`) y documentación (`.md`, `.txt`). Ejecutá `make clean` antes de comprimir tu entrega y verificá tu archivo `.gitignore`.

## Compilación — Makefile raíz del Proyecto

❌ **Estado:** Falló la compilación mediante el Makefile de la raíz.

```text
main.c: In function ‘main’:
main.c:54:9: error: implicit declaration of function ‘free’ [-Wimplicit-function-declaration]
   54 |         free(promedios);
      |         ^~~~
main.c:9:1: note: include ‘<stdlib.h>’ or provide a declaration of ‘free’
    8 | #include "consulta_csv.h"
  +++ |+#include <stdlib.h>
    9 | 
main.c:54:9: warning: incompatible implicit declaration of built-in function ‘free’ [-Wbuiltin-declaration-mismatch]
   54 |         free(promedios);
      |         ^~~~
main.c:54:9: note: include ‘<stdlib.h>’ or provide a declaration of ‘free’
make[1]: *** [Makefile:47: main.o] Error 1
make: *** [Makefile:24: ejercicios/ejercicio6] Error 1

```

> 📄 **Salida completa:** registrada en `compilacion_fc0a9b3.log`.

## Observaciones de Calidad y Reglas P1 (Linter AST / Ripley)

Se detectaron **262** observación(es) en el código C:

| Regla | Ubicación | Severidad | Observación | Sugerencia |
| :--- | :--- | :---: | :--- | :--- |
| `0x0004h` | `main.c:1` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:63` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:64` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:65` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:1` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `prueba.c:14` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0005h` | `prueba.c:22` | ESTILO | La llave de apertura para `for` debe estar en una nueva línea. | Ubicar '{' en el renglón siguiente alineada verticalmente. |
| `0x0004h` | `prueba.c:25` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:45` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `prueba.c:56` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `prueba.c:56` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0xEEEEh` | `vector_enteros.c:34` | ESTILO | Indentación no es múltiplo de 4 espacios (26 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0x0004h` | `vector_enteros.c:1` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:1` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:30` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:37` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:1` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:21` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:35` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:42` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `prueba.c:45` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `prueba.c:45` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0xEEEEh` | `texto_dinamico.c:40` | ESTILO | Indentación no es múltiplo de 4 espacios (42 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `texto_dinamico.c:71` | ESTILO | Indentación no es múltiplo de 4 espacios (39 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0x0004h` | `texto_dinamico.c:1` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0018h` | `texto_dinamico.c:70` | ESTILO | El asterisco del puntero debe estar junto al identificador (ej. 'int *ptr;'). | Escribir 'tipo *nombre_var' en lugar de 'tipo* nombre_var'. |
| `0x0004h` | `texto_dinamico.c:74` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `texto_dinamico.c:77` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `cadena_dinamica.c:1` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:1` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:1` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `prueba.c:54` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `prueba.c:54` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:1` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:44` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0xEEEEh` | `matriz_dinamica.c:32` | ESTILO | Indentación no es múltiplo de 4 espacios (18 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `matriz_dinamica.c:43` | ESTILO | Indentación no es múltiplo de 4 espacios (18 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `matriz_dinamica.c:102` | ESTILO | Indentación no es múltiplo de 4 espacios (30 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0x0004h` | `matriz_dinamica.c:1` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `matriz_dinamica.c:11` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0018h` | `matriz_dinamica.c:21` | ESTILO | El asterisco del puntero debe estar junto al identificador (ej. 'int *ptr;'). | Escribir 'tipo *nombre_var' en lugar de 'tipo* nombre_var'. |
| `0x0004h` | `matriz_dinamica.c:22` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `matriz_dinamica.c:31` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0018h` | `matriz_dinamica.c:39` | ESTILO | El asterisco del puntero debe estar junto al identificador (ej. 'int *ptr;'). | Escribir 'tipo *nombre_var' en lugar de 'tipo* nombre_var'. |
| `0x0002h` | `matriz_dinamica.c:42` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0018h` | `matriz_dinamica.c:50` | ESTILO | El asterisco del puntero debe estar junto al identificador (ej. 'int *ptr;'). | Escribir 'tipo *nombre_var' en lugar de 'tipo* nombre_var'. |
| `0x0002h` | `matriz_dinamica.c:58` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `matriz_dinamica.c:58` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `matriz_dinamica.c:60` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `matriz_dinamica.c:69` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0018h` | `matriz_dinamica.c:69` | ESTILO | El asterisco del puntero debe estar junto al identificador (ej. 'int *ptr;'). | Escribir 'tipo *nombre_var' en lugar de 'tipo* nombre_var'. |
| `0x0018h` | `matriz_dinamica.c:84` | ESTILO | El asterisco del puntero debe estar junto al identificador (ej. 'int *ptr;'). | Escribir 'tipo *nombre_var' en lugar de 'tipo* nombre_var'. |
| `0x0004h` | `matriz_dinamica.c:90` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `matriz_dinamica.c:101` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `matriz_dinamica.c:107` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0xEEEEh` | `prueba.c:57` | ESTILO | Indentación no es múltiplo de 4 espacios (45 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `prueba.c:92` | ESTILO | Indentación no es múltiplo de 4 espacios (26 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0x0004h` | `prueba.c:1` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:30` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:49` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:74` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `prueba.c:89` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `prueba.c:89` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:1` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:13` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:14` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:40` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:42` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:47` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:48` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:49` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:54` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0xEEEEh` | `prueba.c:68` | ESTILO | Indentación no es múltiplo de 4 espacios (26 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0x0004h` | `prueba.c:1` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:14` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:23` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:31` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:41` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:47` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:48` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:49` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:57` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:60` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:61` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `prueba.c:65` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `prueba.c:65` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0xEEEEh` | `registro_csv.c:13` | ESTILO | Indentación no es múltiplo de 4 espacios (25 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0x0004h` | `registro_csv.c:1` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `registro_csv.c:12` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `registro_csv.c:15` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `registro_csv.c:43` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `registro_csv.c:46` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `registro_csv.c:53` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `registro_csv.c:55` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `registro_csv.c:65` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `registro_csv.c:69` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `registro_csv.c:85` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `registro_csv.c:89` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `registro_csv.c:95` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `registro_csv.c:99` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `registro_csv.c:110` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `registro_csv.c:112` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `registro_csv.c:116` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `registro_csv.c:121` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `registro_csv.c:124` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `registro_csv.c:137` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `registro_csv.c:140` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `registro_csv.c:145` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `registro_csv.c:151` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `registro_csv.c:162` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `consulta_csv.c:1` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `consulta_csv.c:11` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `consulta_csv.c:17` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `consulta_csv.c:60` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0018h` | `consulta_csv.c:60` | ESTILO | El asterisco del puntero debe estar junto al identificador (ej. 'int *ptr;'). | Escribir 'tipo *nombre_var' en lugar de 'tipo* nombre_var'. |
| `0x0004h` | `consulta_csv.c:67` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0018h` | `consulta_csv.c:67` | ESTILO | El asterisco del puntero debe estar junto al identificador (ej. 'int *ptr;'). | Escribir 'tipo *nombre_var' en lugar de 'tipo* nombre_var'. |
| `0x0018h` | `consulta_csv.c:77` | ESTILO | El asterisco del puntero debe estar junto al identificador (ej. 'int *ptr;'). | Escribir 'tipo *nombre_var' en lugar de 'tipo* nombre_var'. |
| `0x0004h` | `consulta_csv.c:114` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `consulta_csv.c:115` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0002h` | `consulta_csv.c:116` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `consulta_csv.c:118` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0018h` | `consulta_csv.c:132` | ESTILO | El asterisco del puntero debe estar junto al identificador (ej. 'int *ptr;'). | Escribir 'tipo *nombre_var' en lugar de 'tipo* nombre_var'. |
| `0x0004h` | `consulta_csv.c:144` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0018h` | `consulta_csv.c:144` | ESTILO | El asterisco del puntero debe estar junto al identificador (ej. 'int *ptr;'). | Escribir 'tipo *nombre_var' en lugar de 'tipo* nombre_var'. |
| `0x0004h` | `consulta_csv.c:151` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0018h` | `consulta_csv.c:151` | ESTILO | El asterisco del puntero debe estar junto al identificador (ej. 'int *ptr;'). | Escribir 'tipo *nombre_var' en lugar de 'tipo* nombre_var'. |
| `0x0018h` | `consulta_csv.c:161` | ESTILO | El asterisco del puntero debe estar junto al identificador (ej. 'int *ptr;'). | Escribir 'tipo *nombre_var' en lugar de 'tipo* nombre_var'. |
| `0x0018h` | `consulta_csv.c:167` | ESTILO | El asterisco del puntero debe estar junto al identificador (ej. 'int *ptr;'). | Escribir 'tipo *nombre_var' en lugar de 'tipo* nombre_var'. |
| `0x0018h` | `consulta_csv.c:171` | ESTILO | El asterisco del puntero debe estar junto al identificador (ej. 'int *ptr;'). | Escribir 'tipo *nombre_var' en lugar de 'tipo* nombre_var'. |
| `0x0002h` | `consulta_csv.c:181` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `consulta_csv.c:193` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0018h` | `consulta_csv.c:193` | ESTILO | El asterisco del puntero debe estar junto al identificador (ej. 'int *ptr;'). | Escribir 'tipo *nombre_var' en lugar de 'tipo* nombre_var'. |
| `0x0018h` | `consulta_csv.c:205` | ESTILO | El asterisco del puntero debe estar junto al identificador (ej. 'int *ptr;'). | Escribir 'tipo *nombre_var' en lugar de 'tipo* nombre_var'. |
| `0x0002h` | `consulta_csv.c:215` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `consulta_csv.c:236` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0018h` | `consulta_csv.c:236` | ESTILO | El asterisco del puntero debe estar junto al identificador (ej. 'int *ptr;'). | Escribir 'tipo *nombre_var' en lugar de 'tipo* nombre_var'. |
| `0x0004h` | `consulta_csv.c:249` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0xEEEEh` | `main.c:46` | ESTILO | Indentación no es múltiplo de 4 espacios (38 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `main.c:59` | ESTILO | Indentación no es múltiplo de 4 espacios (42 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `main.c:60` | ESTILO | Indentación no es múltiplo de 4 espacios (42 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `main.c:70` | ESTILO | Indentación no es múltiplo de 4 espacios (23 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `main.c:75` | ESTILO | Indentación no es múltiplo de 4 espacios (47 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `main.c:76` | ESTILO | Indentación no es múltiplo de 4 espacios (47 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0x0004h` | `main.c:1` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:18` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:23` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:69` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:79` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0xEEEEh` | `prueba.c:61` | ESTILO | Indentación no es múltiplo de 4 espacios (42 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `prueba.c:75` | ESTILO | Indentación no es múltiplo de 4 espacios (42 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `prueba.c:83` | ESTILO | Indentación no es múltiplo de 4 espacios (47 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `prueba.c:100` | ESTILO | Indentación no es múltiplo de 4 espacios (38 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `prueba.c:151` | ESTILO | Indentación no es múltiplo de 4 espacios (41 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `prueba.c:157` | ESTILO | Indentación no es múltiplo de 4 espacios (26 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0x0004h` | `prueba.c:1` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:19` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:29` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:53` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:54` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:92` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:123` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:124` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:150` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `prueba.c:154` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `prueba.c:154` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `consola.c:13` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0002h` | `consola.c:23` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `consola.c:37` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `consola.c:39` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `consola.c:41` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `consola.c:48` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `consola.c:49` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `consola.c:60` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0002h` | `consola.c:66` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `consola.c:85` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `consola.c:87` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `consola.c:89` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `consola.c:96` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `consola.c:97` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `consola.c:108` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0002h` | `consola.c:114` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `consola.c:133` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `consola.c:139` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `consola.c:149` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `consola.c:153` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `prueba.c:15` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:16` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:19` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:22` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:23` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:24` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:25` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:26` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:27` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:47` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:48` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:51` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:54` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:55` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:56` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:57` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:58` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:59` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:64` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:183` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:189` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:1` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:18` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:25` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:27` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:31` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:38` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:50` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `prueba.c:97` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `prueba.c:97` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0xEEEEh` | `punteros.c:29` | ESTILO | Indentación no es múltiplo de 4 espacios (21 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0x0004h` | `punteros.c:1` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `punteros.c:9` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0002h` | `punteros.c:28` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `punteros.c:43` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `punteros.c:47` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `punteros.c:70` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `punteros.c:89` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0xEEEEh` | `cadenas.c:55` | ESTILO | Indentación no es múltiplo de 4 espacios (27 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `cadenas.c:112` | ESTILO | Indentación no es múltiplo de 4 espacios (31 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0x0004h` | `cadenas.c:1` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `cadenas.c:100` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `cadenas.c:107` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `cadenas.c:112` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `prueba.c:1` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:16` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:30` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:44` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:51` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:65` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `prueba.c:73` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `prueba.c:73` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:1` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0005h` | `prueba.c:18` | ESTILO | La llave de apertura para `for` debe estar en una nueva línea. | Ubicar '{' en el renglón siguiente alineada verticalmente. |
| `0x0004h` | `prueba.c:24` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:30` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:51` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:80` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:86` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:91` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `prueba.c:94` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `prueba.c:94` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0xEEEEh` | `vector.c:64` | ESTILO | Indentación no es múltiplo de 4 espacios (29 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `vector.c:106` | ESTILO | Indentación no es múltiplo de 4 espacios (29 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0x0004h` | `vector.c:1` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `vector.c:18` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `vector.c:27` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `vector.c:34` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `vector.c:48` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0018h` | `vector.c:48` | ESTILO | El asterisco del puntero debe estar junto al identificador (ej. 'int *ptr;'). | Escribir 'tipo *nombre_var' en lugar de 'tipo* nombre_var'. |
| `0x0004h` | `vector.c:83` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0018h` | `vector.c:83` | ESTILO | El asterisco del puntero debe estar junto al identificador (ej. 'int *ptr;'). | Escribir 'tipo *nombre_var' en lugar de 'tipo* nombre_var'. |
| `0x0004h` | `vector.c:105` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `vector.c:117` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0018h` | `vector.c:117` | ESTILO | El asterisco del puntero debe estar junto al identificador (ej. 'int *ptr;'). | Escribir 'tipo *nombre_var' en lugar de 'tipo* nombre_var'. |
| `0x0004h` | `vector.c:123` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |

## Pruebas del Proyecto — Makefile raíz (`make test`)

✓ **Estado:** Pruebas del proyecto aprobadas con éxito (`make test`).

## Auditoría de Memoria Dinámica — Valgrind

✓ **Estado:** No se detectaron fugas de memoria durante las pruebas en sandbox.

## Linter de Estilo y Formato — Gaff

⚠️ Se detectaron **61** observación(es) de estilo arquitectónico:

| Regla | Ubicación | Observación | Sugerencia | Autofix |
| :--- | :--- | :--- | :--- | :---: |
| `GAFF009` | `prueba.c:14` | La línea tiene 94 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `prueba.c:58` | La línea tiene 84 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `vector_enteros.c:3` | La línea tiene 83 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `vector_enteros.h:27` | La línea tiene 82 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `vector_enteros.h:28` | La línea tiene 84 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `prueba.c:47` | La línea tiene 84 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `0x0001h` | `prueba.c:32` | Identificador corto y poco expresivo 'rep' (3 caracteres). | Se recomienda utilizar identificadores más descriptivos del dominio del problema. | No |
| `0x0001h` | `texto_dinamico.c:13` | Identificador corto y poco expresivo 'fin' (3 caracteres). | Se recomienda utilizar identificadores más descriptivos del dominio del problema. | No |
| `GAFF009` | `texto_dinamico.h:12` | La línea tiene 95 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `texto_dinamico.h:13` | La línea tiene 90 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `texto_dinamico.h:23` | La línea tiene 103 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `prueba.c:56` | La línea tiene 84 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `0x0001h` | `matriz_dinamica.c:32` | Identificador corto y poco expresivo 'col' (3 caracteres). | Se recomienda utilizar identificadores más descriptivos del dominio del problema. | No |
| `0x0001h` | `matriz_dinamica.c:42` | Identificador corto y poco expresivo 'col' (3 caracteres). | Se recomienda utilizar identificadores más descriptivos del dominio del problema. | No |
| `0x0001h` | `matriz_dinamica.h:27` | Identificador corto y poco expresivo 'col' (3 caracteres). | Se recomienda utilizar identificadores más descriptivos del dominio del problema. | No |
| `0x0001h` | `matriz_dinamica.h:39` | Identificador corto y poco expresivo 'col' (3 caracteres). | Se recomienda utilizar identificadores más descriptivos del dominio del problema. | No |
| `0x0001h` | `consola.c:13` | Identificador corto y poco expresivo 'min' (3 caracteres). | Se recomienda utilizar identificadores más descriptivos del dominio del problema. | No |
| `0x0001h` | `consola.c:13` | Identificador corto y poco expresivo 'max' (3 caracteres). | Se recomienda utilizar identificadores más descriptivos del dominio del problema. | No |
| `0x0001h` | `consola.c:23` | Identificador corto y poco expresivo 'min' (3 caracteres). | Se recomienda utilizar identificadores más descriptivos del dominio del problema. | No |
| `0x0001h` | `consola.c:23` | Identificador corto y poco expresivo 'max' (3 caracteres). | Se recomienda utilizar identificadores más descriptivos del dominio del problema. | No |
| `0x0001h` | `consola.c:60` | Identificador corto y poco expresivo 'max' (3 caracteres). | Se recomienda utilizar identificadores más descriptivos del dominio del problema. | No |
| `0x0001h` | `consola.c:60` | Identificador corto y poco expresivo 'min' (3 caracteres). | Se recomienda utilizar identificadores más descriptivos del dominio del problema. | No |
| `0x0001h` | `consola.c:108` | Identificador corto y poco expresivo 'min' (3 caracteres). | Se recomienda utilizar identificadores más descriptivos del dominio del problema. | No |
| `0x0001h` | `consola.c:108` | Identificador corto y poco expresivo 'max' (3 caracteres). | Se recomienda utilizar identificadores más descriptivos del dominio del problema. | No |
| `0x0001h` | `consola.h:28` | Identificador corto y poco expresivo 'max' (3 caracteres). | Se recomienda utilizar identificadores más descriptivos del dominio del problema. | No |
| `0x0001h` | `consola.h:28` | Identificador corto y poco expresivo 'min' (3 caracteres). | Se recomienda utilizar identificadores más descriptivos del dominio del problema. | No |
| `0x0001h` | `consola.h:46` | Identificador corto y poco expresivo 'max' (3 caracteres). | Se recomienda utilizar identificadores más descriptivos del dominio del problema. | No |
| `0x0001h` | `consola.h:46` | Identificador corto y poco expresivo 'min' (3 caracteres). | Se recomienda utilizar identificadores más descriptivos del dominio del problema. | No |
| `0x0001h` | `consola.h:72` | Identificador corto y poco expresivo 'max' (3 caracteres). | Se recomienda utilizar identificadores más descriptivos del dominio del problema. | No |
| `0x0001h` | `consola.h:72` | Identificador corto y poco expresivo 'min' (3 caracteres). | Se recomienda utilizar identificadores más descriptivos del dominio del problema. | No |
| `0x0001h` | `consola.h:82` | Identificador corto y poco expresivo 'max' (3 caracteres). | Se recomienda utilizar identificadores más descriptivos del dominio del problema. | No |
| `0x0001h` | `consola.h:82` | Identificador corto y poco expresivo 'min' (3 caracteres). | Se recomienda utilizar identificadores más descriptivos del dominio del problema. | No |
| `GAFF009` | `prueba.c:99` | La línea tiene 84 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `0x0001h` | `prueba.c:23` | Identificador de variable no descriptivo de una sola letra 'a'. | Los nombres de variables deben reflejar con precisión su propósito (salvo índices canónicos i, j, k, n, x, y, z, f, c, r). | No |
| `0x0001h` | `prueba.c:24` | Identificador de variable no descriptivo de una sola letra 'b'. | Los nombres de variables deben reflejar con precisión su propósito (salvo índices canónicos i, j, k, n, x, y, z, f, c, r). | No |
| `0x0001h` | `prueba.c:35` | Identificador corto y poco expresivo 'val' (3 caracteres). | Se recomienda utilizar identificadores más descriptivos del dominio del problema. | No |
| `0x0001h` | `punteros.c:37` | Identificador corto y poco expresivo 'fin' (3 caracteres). | Se recomienda utilizar identificadores más descriptivos del dominio del problema. | No |
| `0x0001h` | `punteros.c:66` | Identificador corto y poco expresivo 'fin' (3 caracteres). | Se recomienda utilizar identificadores más descriptivos del dominio del problema. | No |
| `0x0001h` | `punteros.c:84` | Identificador corto y poco expresivo 'fin' (3 caracteres). | Se recomienda utilizar identificadores más descriptivos del dominio del problema. | No |
| `GAFF009` | `punteros.h:3` | La línea tiene 88 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `punteros.h:17` | La línea tiene 88 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `punteros.h:62` | La línea tiene 85 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `punteros.h:76` | La línea tiene 85 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `cadenas.h:13` | La línea tiene 89 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `cadenas.h:35` | La línea tiene 83 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `cadenas.h:36` | La línea tiene 85 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `cadenas.h:37` | La línea tiene 82 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `cadenas.h:50` | La línea tiene 94 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `prueba.c:75` | La línea tiene 82 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `0x0001h` | `prueba.c:13` | Identificador corto y poco expresivo 'dup' (3 caracteres). | Se recomienda utilizar identificadores más descriptivos del dominio del problema. | No |
| `GAFF009` | `prueba.c:96` | La línea tiene 82 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `vector.c:117` | La línea tiene 84 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `vector.h:3` | La línea tiene 91 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `vector.h:9` | La línea tiene 83 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `vector.h:11` | La línea tiene 90 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `vector.h:28` | La línea tiene 90 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `vector.h:45` | La línea tiene 83 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `vector.h:57` | La línea tiene 87 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `vector.h:59` | La línea tiene 81 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `vector.h:73` | La línea tiene 89 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `vector.h:76` | La línea tiene 82 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |

## Auditoría de Seguridad — Sandbox / Kaneda

⚠️ **Alerta:** Se detectaron **49** llamadas o patrones de riesgo de seguridad:

| Regla | Archivo:Línea | Severidad | Detalle | Sugerencia |
| :--- | :--- | :---: | :--- | :--- |
| `0x000Fh` | `libs/consola/consola.o:1` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'libs/consola/consola.o' (Extensión binaria prohibida '.o'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `0x000Fh` | `libs/consola/libconsola.a:1` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'libs/consola/libconsola.a' (Extensión binaria prohibida '.a'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `0x000Fh` | `libs/consola/prueba.o:1` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'libs/consola/prueba.o' (Extensión binaria prohibida '.o'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `0x000Fh` | `libs/consola/test_bin:1` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'libs/consola/test_bin' (Firma binaria ejecutable detectada (Formato ejecutable o archivo objeto Linux ELF)). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `0x000Fh` | `libs/p1_test/libp1_test.a:1` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'libs/p1_test/libp1_test.a' (Extensión binaria prohibida '.a'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `0x000Fh` | `libs/p1_test/prueba.o:1` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'libs/p1_test/prueba.o' (Extensión binaria prohibida '.o'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `0x000Fh` | `libs/p1_test/test_bin:1` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'libs/p1_test/test_bin' (Firma binaria ejecutable detectada (Formato ejecutable o archivo objeto Linux ELF)). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `0x000Fh` | `libs/punteros/punteros.o:1` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'libs/punteros/punteros.o' (Extensión binaria prohibida '.o'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `0x000Fh` | `libs/punteros/libpunteros.a:1` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'libs/punteros/libpunteros.a' (Extensión binaria prohibida '.a'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `0x000Fh` | `libs/punteros/prueba.o:1` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'libs/punteros/prueba.o' (Extensión binaria prohibida '.o'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `0x000Fh` | `libs/punteros/test_bin:1` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'libs/punteros/test_bin' (Firma binaria ejecutable detectada (Formato ejecutable o archivo objeto Linux ELF)). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `0x000Fh` | `libs/string/cadenas.o:1` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'libs/string/cadenas.o' (Extensión binaria prohibida '.o'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `0x000Fh` | `libs/string/libstring.a:1` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'libs/string/libstring.a' (Extensión binaria prohibida '.a'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `0x000Fh` | `libs/string/prueba.o:1` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'libs/string/prueba.o' (Extensión binaria prohibida '.o'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `0x000Fh` | `libs/string/test_bin:1` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'libs/string/test_bin' (Firma binaria ejecutable detectada (Formato ejecutable o archivo objeto Linux ELF)). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `0x000Fh` | `libs/vector/vector.o:1` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'libs/vector/vector.o' (Extensión binaria prohibida '.o'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `0x000Fh` | `libs/vector/libvector.a:1` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'libs/vector/libvector.a' (Extensión binaria prohibida '.a'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `0x000Fh` | `libs/vector/prueba.o:1` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'libs/vector/prueba.o' (Extensión binaria prohibida '.o'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `0x000Fh` | `libs/vector/test_bin:1` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'libs/vector/test_bin' (Firma binaria ejecutable detectada (Formato ejecutable o archivo objeto Linux ELF)). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `0x000Fh` | `libs/p1_test/build/p1_test.o:1` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'libs/p1_test/build/p1_test.o' (Extensión binaria prohibida '.o'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `0x000Fh` | `libs/p1_test/build/libp1_test.a:1` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'libs/p1_test/build/libp1_test.a' (Extensión binaria prohibida '.a'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `0x000Fh` | `ejercicios/ejercicio1/main.o:1` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'ejercicios/ejercicio1/main.o' (Extensión binaria prohibida '.o'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `0x000Fh` | `ejercicios/ejercicio1/vector_enteros.o:1` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'ejercicios/ejercicio1/vector_enteros.o' (Extensión binaria prohibida '.o'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `0x000Fh` | `ejercicios/ejercicio1/programa:1` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'ejercicios/ejercicio1/programa' (Firma binaria ejecutable detectada (Formato ejecutable o archivo objeto Linux ELF)). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `0x000Fh` | `ejercicios/ejercicio1/prueba.o:1` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'ejercicios/ejercicio1/prueba.o' (Extensión binaria prohibida '.o'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `0x000Fh` | `ejercicios/ejercicio1/test_bin:1` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'ejercicios/ejercicio1/test_bin' (Firma binaria ejecutable detectada (Formato ejecutable o archivo objeto Linux ELF)). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `0x000Fh` | `ejercicios/ejercicio2/main.o:1` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'ejercicios/ejercicio2/main.o' (Extensión binaria prohibida '.o'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `0x000Fh` | `ejercicios/ejercicio2/texto_dinamico.o:1` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'ejercicios/ejercicio2/texto_dinamico.o' (Extensión binaria prohibida '.o'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `0x000Fh` | `ejercicios/ejercicio2/programa:1` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'ejercicios/ejercicio2/programa' (Firma binaria ejecutable detectada (Formato ejecutable o archivo objeto Linux ELF)). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `0x000Fh` | `ejercicios/ejercicio2/prueba.o:1` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'ejercicios/ejercicio2/prueba.o' (Extensión binaria prohibida '.o'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `0x000Fh` | `ejercicios/ejercicio2/test_bin:1` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'ejercicios/ejercicio2/test_bin' (Firma binaria ejecutable detectada (Formato ejecutable o archivo objeto Linux ELF)). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `0x000Fh` | `ejercicios/ejercicio3/main.o:1` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'ejercicios/ejercicio3/main.o' (Extensión binaria prohibida '.o'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `0x000Fh` | `ejercicios/ejercicio3/cadena_dinamica.o:1` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'ejercicios/ejercicio3/cadena_dinamica.o' (Extensión binaria prohibida '.o'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `0x000Fh` | `ejercicios/ejercicio3/programa:1` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'ejercicios/ejercicio3/programa' (Firma binaria ejecutable detectada (Formato ejecutable o archivo objeto Linux ELF)). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `0x000Fh` | `ejercicios/ejercicio3/prueba.o:1` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'ejercicios/ejercicio3/prueba.o' (Extensión binaria prohibida '.o'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `0x000Fh` | `ejercicios/ejercicio3/test_bin:1` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'ejercicios/ejercicio3/test_bin' (Firma binaria ejecutable detectada (Formato ejecutable o archivo objeto Linux ELF)). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `0x000Fh` | `ejercicios/ejercicio4/main.o:1` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'ejercicios/ejercicio4/main.o' (Extensión binaria prohibida '.o'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `0x000Fh` | `ejercicios/ejercicio4/matriz_dinamica.o:1` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'ejercicios/ejercicio4/matriz_dinamica.o' (Extensión binaria prohibida '.o'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `0x000Fh` | `ejercicios/ejercicio4/programa:1` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'ejercicios/ejercicio4/programa' (Firma binaria ejecutable detectada (Formato ejecutable o archivo objeto Linux ELF)). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `0x000Fh` | `ejercicios/ejercicio4/prueba.o:1` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'ejercicios/ejercicio4/prueba.o' (Extensión binaria prohibida '.o'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `0x000Fh` | `ejercicios/ejercicio4/test_bin:1` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'ejercicios/ejercicio4/test_bin' (Firma binaria ejecutable detectada (Formato ejecutable o archivo objeto Linux ELF)). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `0x000Fh` | `ejercicios/ejercicio5/main.o:1` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'ejercicios/ejercicio5/main.o' (Extensión binaria prohibida '.o'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `0x000Fh` | `ejercicios/ejercicio5/registro_csv.o:1` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'ejercicios/ejercicio5/registro_csv.o' (Extensión binaria prohibida '.o'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `0x000Fh` | `ejercicios/ejercicio5/programa:1` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'ejercicios/ejercicio5/programa' (Firma binaria ejecutable detectada (Formato ejecutable o archivo objeto Linux ELF)). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `0x000Fh` | `ejercicios/ejercicio5/prueba.o:1` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'ejercicios/ejercicio5/prueba.o' (Extensión binaria prohibida '.o'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `0x000Fh` | `ejercicios/ejercicio5/test_bin:1` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'ejercicios/ejercicio5/test_bin' (Firma binaria ejecutable detectada (Formato ejecutable o archivo objeto Linux ELF)). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `0x000Fh` | `ejercicios/ejercicio6/prueba.o:1` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'ejercicios/ejercicio6/prueba.o' (Extensión binaria prohibida '.o'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `0x000Fh` | `ejercicios/ejercicio6/consulta_csv.o:1` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'ejercicios/ejercicio6/consulta_csv.o' (Extensión binaria prohibida '.o'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `0x000Fh` | `ejercicios/ejercicio6/test_bin:1` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'ejercicios/ejercicio6/test_bin' (Firma binaria ejecutable detectada (Formato ejecutable o archivo objeto Linux ELF)). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |

## Antipatrones Didácticos — Spunkmeyer

Se detectaron **99** observación(es) de antipatrones didácticos:

| Regla | Ubicación | Antipatrón | Diagnóstico | Sugerencia |
| :--- | :--- | :--- | :--- | :--- |
| `0x7001h` | `prueba.c:19` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `prueba.c:36` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x300Dh` | `vector_enteros.c:54` | **Número mágico literal en condición lógica** | Número mágico '0U' utilizado directamente en condición lógica. | Declarale un nombre significativo mediante una constante '#define' o 'enum'. |
| `0x7001h` | `prueba.c:18` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `prueba.c:32` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x300Dh` | `texto_dinamico.c:57` | **Número mágico literal en condición lógica** | Número mágico '0U' utilizado directamente en condición lógica. | Declarale un nombre significativo mediante una constante '#define' o 'enum'. |
| `0x3008h` | `main.c:35` | **Chequeo innecesario antes de free()** | Comprobar 'if (ptr != NULL)' antes de invocar 'free(ptr)' es redundante. | Invocá 'free(ptr);' directamente sin envolverlo en un if. |
| `0x3008h` | `main.c:43` | **Chequeo innecesario antes de free()** | Comprobar 'if (ptr != NULL)' antes de invocar 'free(ptr)' es redundante. | Invocá 'free(ptr);' directamente sin envolverlo en un if. |
| `0x7001h` | `prueba.c:14` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x3002h` | `prueba.c:17` | **Puntero colgante sin asignar NULL tras free()** | Puntero 'clon' liberado con free() pero no anulado con NULL posteriormente. | Asigná 'ptr = NULL;' inmediatamente después de 'free(ptr);'. |
| `0x3002h` | `prueba.c:23` | **Puntero colgante sin asignar NULL tras free()** | Puntero 'clon' liberado con free() pero no anulado con NULL posteriormente. | Asigná 'ptr = NULL;' inmediatamente después de 'free(ptr);'. |
| `0x7001h` | `prueba.c:32` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x3002h` | `prueba.c:35` | **Puntero colgante sin asignar NULL tras free()** | Puntero 'unida' liberado con free() pero no anulado con NULL posteriormente. | Asigná 'ptr = NULL;' inmediatamente después de 'free(ptr);'. |
| `0x3002h` | `prueba.c:41` | **Puntero colgante sin asignar NULL tras free()** | Puntero 'unida' liberado con free() pero no anulado con NULL posteriormente. | Asigná 'ptr = NULL;' inmediatamente después de 'free(ptr);'. |
| `0x3002h` | `prueba.c:47` | **Puntero colgante sin asignar NULL tras free()** | Puntero 'unida' liberado con free() pero no anulado con NULL posteriormente. | Asigná 'ptr = NULL;' inmediatamente después de 'free(ptr);'. |
| `0x3001h` | `matriz_dinamica.c:23` | **Comprobación de puntero nulo posterior a su desreferencia** | Comprobación de puntero nulo 'matriz_plana' posterior a su desreferencia en la línea 22. | Ubicá la comprobación 'if (ptr == NULL)' antes de cualquier acceso a sus datos. |
| `0x3002h` | `matriz_dinamica.c:55` | **Puntero colgante sin asignar NULL tras free()** | Puntero 'matriz_plana' liberado con free() pero no anulado con NULL posteriormente. | Asigná 'ptr = NULL;' inmediatamente después de 'free(ptr);'. |
| `0x3001h` | `matriz_dinamica.c:70` | **Comprobación de puntero nulo posterior a su desreferencia** | Comprobación de puntero nulo 'matriz_filas' posterior a su desreferencia en la línea 69. | Ubicá la comprobación 'if (ptr == NULL)' antes de cualquier acceso a sus datos. |
| `0x3002h` | `matriz_dinamica.c:97` | **Puntero colgante sin asignar NULL tras free()** | Puntero 'matriz_filas' liberado con free() pero no anulado con NULL posteriormente. | Asigná 'ptr = NULL;' inmediatamente después de 'free(ptr);'. |
| `0x3002h` | `matriz_dinamica.c:98` | **Puntero colgante sin asignar NULL tras free()** | Puntero 'matriz_filas' liberado con free() pero no anulado con NULL posteriormente. | Asigná 'ptr = NULL;' inmediatamente después de 'free(ptr);'. |
| `0x7001h` | `prueba.c:16` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `prueba.c:30` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `prueba.c:46` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x4001h` | `prueba.c:53` | **Omisión de verificación de retorno NULL en fopen()** | Uso de descriptor de archivo 'archivo_csv' devuelto por fopen() en línea 51 sin comprobación previa de NULL. | Verificá siempre 'if (f == NULL)' inmediatamente después de invocar 'fopen()'. |
| `0x4001h` | `prueba.c:81` | **Omisión de verificación de retorno NULL en fopen()** | Uso de descriptor de archivo 'archivo_csv' devuelto por fopen() en línea 79 sin comprobación previa de NULL. | Verificá siempre 'if (f == NULL)' inmediatamente después de invocar 'fopen()'. |
| `0x7001h` | `prueba.c:14` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `prueba.c:41` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x3001h` | `registro_csv.c:44` | **Comprobación de puntero nulo posterior a su desreferencia** | Comprobación de puntero nulo 'tokens' posterior a su desreferencia en la línea 43. | Ubicá la comprobación 'if (ptr == NULL)' antes de cualquier acceso a sus datos. |
| `0x3002h` | `registro_csv.c:68` | **Puntero colgante sin asignar NULL tras free()** | Puntero 'tokens' liberado con free() pero no anulado con NULL posteriormente. | Asigná 'ptr = NULL;' inmediatamente después de 'free(ptr);'. |
| `0x3001h` | `registro_csv.c:138` | **Comprobación de puntero nulo posterior a su desreferencia** | Comprobación de puntero nulo 'nuevo' posterior a su desreferencia en la línea 137. | Ubicá la comprobación 'if (ptr == NULL)' antes de cualquier acceso a sus datos. |
| `0x3002h` | `registro_csv.c:164` | **Puntero colgante sin asignar NULL tras free()** | Puntero 'lista' liberado con free() pero no anulado con NULL posteriormente. | Asigná 'ptr = NULL;' inmediatamente después de 'free(ptr);'. |
| `0x3001h` | `consulta_csv.c:61` | **Comprobación de puntero nulo posterior a su desreferencia** | Comprobación de puntero nulo 'matriz' posterior a su desreferencia en la línea 60. | Ubicá la comprobación 'if (ptr == NULL)' antes de cualquier acceso a sus datos. |
| `0x3001h` | `consulta_csv.c:68` | **Comprobación de puntero nulo posterior a su desreferencia** | Comprobación de puntero nulo 'bloque' posterior a su desreferencia en la línea 67. | Ubicá la comprobación 'if (ptr == NULL)' antes de cualquier acceso a sus datos. |
| `0x300Dh` | `consulta_csv.c:138` | **Número mágico literal en condición lógica** | Número mágico '0U' utilizado directamente en condición lógica. | Declarale un nombre significativo mediante una constante '#define' o 'enum'. |
| `0x3001h` | `consulta_csv.c:145` | **Comprobación de puntero nulo posterior a su desreferencia** | Comprobación de puntero nulo 'resultado' posterior a su desreferencia en la línea 144. | Ubicá la comprobación 'if (ptr == NULL)' antes de cualquier acceso a sus datos. |
| `0x3001h` | `consulta_csv.c:152` | **Comprobación de puntero nulo posterior a su desreferencia** | Comprobación de puntero nulo 'bloque' posterior a su desreferencia en la línea 151. | Ubicá la comprobación 'if (ptr == NULL)' antes de cualquier acceso a sus datos. |
| `0x3001h` | `consulta_csv.c:194` | **Comprobación de puntero nulo posterior a su desreferencia** | Comprobación de puntero nulo 'estadisticas' posterior a su desreferencia en la línea 193. | Ubicá la comprobación 'if (ptr == NULL)' antes de cualquier acceso a sus datos. |
| `0x3002h` | `consulta_csv.c:256` | **Puntero colgante sin asignar NULL tras free()** | Puntero 'matriz' liberado con free() pero no anulado con NULL posteriormente. | Asigná 'ptr = NULL;' inmediatamente después de 'free(ptr);'. |
| `0x3002h` | `consulta_csv.c:257` | **Puntero colgante sin asignar NULL tras free()** | Puntero 'matriz' liberado con free() pero no anulado con NULL posteriormente. | Asigná 'ptr = NULL;' inmediatamente después de 'free(ptr);'. |
| `0x3008h` | `main.c:47` | **Chequeo innecesario antes de free()** | Comprobar 'if (ptr != NULL)' antes de invocar 'free(ptr)' es redundante. | Invocá 'free(ptr);' directamente sin envolverlo en un if. |
| `0x3002h` | `main.c:54` | **Puntero colgante sin asignar NULL tras free()** | Puntero 'promedios' liberado con free() pero no anulado con NULL posteriormente. | Asigná 'ptr = NULL;' inmediatamente después de 'free(ptr);'. |
| `0x7001h` | `prueba.c:27` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `prueba.c:50` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `prueba.c:89` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x3002h` | `prueba.c:107` | **Puntero colgante sin asignar NULL tras free()** | Puntero 'promedios' liberado con free() pero no anulado con NULL posteriormente. | Asigná 'ptr = NULL;' inmediatamente después de 'free(ptr);'. |
| `0x7001h` | `prueba.c:119` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x1008h` | `consola.c:187` | **Caso de switch sin break (Fallthrough no intencional)** | Bloque 'case' sin sentencia 'break' previa al siguiente caso. | Agregá 'break;' al final del caso o documentá explícitamente '// fallthrough'. |
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
| `0x7001h` | `prueba.c:16` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `prueba.c:46` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `prueba.c:74` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `prueba.c:90` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `punteros.c:23` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `punteros.c:36` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `punteros.c:65` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `punteros.c:83` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `prueba.c:13` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `prueba.c:27` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `prueba.c:41` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `prueba.c:62` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `prueba.c:16` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `prueba.c:37` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `prueba.c:58` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x3002h` | `prueba.c:64` | **Puntero colgante sin asignar NULL tras free()** | Puntero 'fusionado' liberado con free() pero no anulado con NULL posteriormente. | Asigná 'ptr = NULL;' inmediatamente después de 'free(ptr);'. |
| `0x7001h` | `prueba.c:74` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x3001h` | `vector.c:19` | **Comprobación de puntero nulo posterior a su desreferencia** | Comprobación de puntero nulo 'arreglo' posterior a su desreferencia en la línea 18. | Ubicá la comprobación 'if (ptr == NULL)' antes de cualquier acceso a sus datos. |
| `0x3001h` | `vector.c:49` | **Comprobación de puntero nulo posterior a su desreferencia** | Comprobación de puntero nulo 'temp' posterior a su desreferencia en la línea 48. | Ubicá la comprobación 'if (ptr == NULL)' antes de cualquier acceso a sus datos. |
| `0x3001h` | `vector.c:84` | **Comprobación de puntero nulo posterior a su desreferencia** | Comprobación de puntero nulo 'resultado' posterior a su desreferencia en la línea 83. | Ubicá la comprobación 'if (ptr == NULL)' antes de cualquier acceso a sus datos. |
| `0x3001h` | `vector.c:118` | **Comprobación de puntero nulo posterior a su desreferencia** | Comprobación de puntero nulo 'nuevo_bloque' posterior a su desreferencia en la línea 117. | Ubicá la comprobación 'if (ptr == NULL)' antes de cualquier acceso a sus datos. |

### 🔍 Detalle Pedagógico de Antipatrones

#### Regla `0x7001h`: Declaración de variable mezclada tras sentencias ejecutables
- **Ubicación:** `prueba.c:19`
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
- **Ubicación:** `prueba.c:36`
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

#### Regla `0x300Dh`: Número mágico literal en condición lógica
- **Ubicación:** `vector_enteros.c:54`
```c
    if (cantidad_valida == 0U)
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

#### Regla `0x7001h`: Declaración de variable mezclada tras sentencias ejecutables
- **Ubicación:** `prueba.c:18`
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
- **Ubicación:** `prueba.c:32`
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

#### Regla `0x300Dh`: Número mágico literal en condición lógica
- **Ubicación:** `texto_dinamico.c:57`
```c
    if (veces == 0U)
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

#### Regla `0x3008h`: Chequeo innecesario antes de free()
- **Ubicación:** `main.c:35`
```c
    if (copiada != NULL)
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

#### Regla `0x3008h`: Chequeo innecesario antes de free()
- **Ubicación:** `main.c:43`
```c
    if (unida != NULL)
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
- **Ubicación:** `prueba.c:14`
```c
    char *clon = clonar_cadena("Hola");
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
- **Ubicación:** `prueba.c:17`
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
- **Ubicación:** `prueba.c:23`
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

#### Regla `0x7001h`: Declaración de variable mezclada tras sentencias ejecutables
- **Ubicación:** `prueba.c:32`
```c
    char *unida = unir_cadenas_dinamicas("Hola", " Mundo");
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
- **Ubicación:** `prueba.c:35`
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
- **Ubicación:** `prueba.c:41`
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
- **Ubicación:** `prueba.c:47`
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

#### Regla `0x3001h`: Comprobación de puntero nulo posterior a su desreferencia
- **Ubicación:** `matriz_dinamica.c:23`
```c
    if (matriz_plana == NULL)
```
- **Explicación:** Si el puntero hubiera sido NULL, el programa ya habría caído por Segmentation Fault en la línea de desreferencia anterior. La verificación tardía indica aserciones invertidas.
- **Sugerencia:** Ubicá la comprobación 'if (ptr == NULL)' antes de cualquier acceso a sus datos.
- **Ejemplo incorrecto:**
```c
*ptr = 10;
if (ptr != NULL) {
    // ...
}
```
- **Ejemplo recomendado:**
```c
if (ptr != NULL) {
    *ptr = 10;
}
```

#### Regla `0x3002h`: Puntero colgante sin asignar NULL tras free()
- **Ubicación:** `matriz_dinamica.c:55`
```c
    free(matriz_plana);
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

#### Regla `0x3001h`: Comprobación de puntero nulo posterior a su desreferencia
- **Ubicación:** `matriz_dinamica.c:70`
```c
    if (matriz_filas == NULL)
```
- **Explicación:** Si el puntero hubiera sido NULL, el programa ya habría caído por Segmentation Fault en la línea de desreferencia anterior. La verificación tardía indica aserciones invertidas.
- **Sugerencia:** Ubicá la comprobación 'if (ptr == NULL)' antes de cualquier acceso a sus datos.
- **Ejemplo incorrecto:**
```c
*ptr = 10;
if (ptr != NULL) {
    // ...
}
```
- **Ejemplo recomendado:**
```c
if (ptr != NULL) {
    *ptr = 10;
}
```

#### Regla `0x3002h`: Puntero colgante sin asignar NULL tras free()
- **Ubicación:** `matriz_dinamica.c:97`
```c
    free(matriz_filas[0]);
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
- **Ubicación:** `matriz_dinamica.c:98`
```c
    free(matriz_filas);
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
- **Ubicación:** `prueba.c:16`
```c
    int *matriz_plana = crear_matriz_plana(2, 3);
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
- **Ubicación:** `prueba.c:30`
```c
    int **matriz_por_filas = matriz_crear(2, 2);
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
    FILE *archivo_csv = NULL;
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
- **Ubicación:** `prueba.c:53`
```c
    fprintf(archivo_csv, "1,2,3\n4,5,6\n");
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
- **Ubicación:** `prueba.c:81`
```c
    fprintf(archivo_csv, "1,2,3\n4,5\n");
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
- **Ubicación:** `prueba.c:14`
```c
    char **tokens = NULL;
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
    char **lista = lista_cadenas_crear();
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

#### Regla `0x3001h`: Comprobación de puntero nulo posterior a su desreferencia
- **Ubicación:** `registro_csv.c:44`
```c
    if (tokens == NULL)
```
- **Explicación:** Si el puntero hubiera sido NULL, el programa ya habría caído por Segmentation Fault en la línea de desreferencia anterior. La verificación tardía indica aserciones invertidas.
- **Sugerencia:** Ubicá la comprobación 'if (ptr == NULL)' antes de cualquier acceso a sus datos.
- **Ejemplo incorrecto:**
```c
*ptr = 10;
if (ptr != NULL) {
    // ...
}
```
- **Ejemplo recomendado:**
```c
if (ptr != NULL) {
    *ptr = 10;
}
```

#### Regla `0x3002h`: Puntero colgante sin asignar NULL tras free()
- **Ubicación:** `registro_csv.c:68`
```c
                free(tokens);
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

#### Regla `0x3001h`: Comprobación de puntero nulo posterior a su desreferencia
- **Ubicación:** `registro_csv.c:138`
```c
    if (nuevo == NULL)
```
- **Explicación:** Si el puntero hubiera sido NULL, el programa ya habría caído por Segmentation Fault en la línea de desreferencia anterior. La verificación tardía indica aserciones invertidas.
- **Sugerencia:** Ubicá la comprobación 'if (ptr == NULL)' antes de cualquier acceso a sus datos.
- **Ejemplo incorrecto:**
```c
*ptr = 10;
if (ptr != NULL) {
    // ...
}
```
- **Ejemplo recomendado:**
```c
if (ptr != NULL) {
    *ptr = 10;
}
```

#### Regla `0x3002h`: Puntero colgante sin asignar NULL tras free()
- **Ubicación:** `registro_csv.c:164`
```c
    free(lista);
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

#### Regla `0x3001h`: Comprobación de puntero nulo posterior a su desreferencia
- **Ubicación:** `consulta_csv.c:61`
```c
    if (matriz == NULL)
```
- **Explicación:** Si el puntero hubiera sido NULL, el programa ya habría caído por Segmentation Fault en la línea de desreferencia anterior. La verificación tardía indica aserciones invertidas.
- **Sugerencia:** Ubicá la comprobación 'if (ptr == NULL)' antes de cualquier acceso a sus datos.
- **Ejemplo incorrecto:**
```c
*ptr = 10;
if (ptr != NULL) {
    // ...
}
```
- **Ejemplo recomendado:**
```c
if (ptr != NULL) {
    *ptr = 10;
}
```

#### Regla `0x3001h`: Comprobación de puntero nulo posterior a su desreferencia
- **Ubicación:** `consulta_csv.c:68`
```c
    if (bloque == NULL)
```
- **Explicación:** Si el puntero hubiera sido NULL, el programa ya habría caído por Segmentation Fault en la línea de desreferencia anterior. La verificación tardía indica aserciones invertidas.
- **Sugerencia:** Ubicá la comprobación 'if (ptr == NULL)' antes de cualquier acceso a sus datos.
- **Ejemplo incorrecto:**
```c
*ptr = 10;
if (ptr != NULL) {
    // ...
}
```
- **Ejemplo recomendado:**
```c
if (ptr != NULL) {
    *ptr = 10;
}
```

#### Regla `0x300Dh`: Número mágico literal en condición lógica
- **Ubicación:** `consulta_csv.c:138`
```c
    if (filas_filtradas == 0U)
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

#### Regla `0x3001h`: Comprobación de puntero nulo posterior a su desreferencia
- **Ubicación:** `consulta_csv.c:145`
```c
    if (resultado == NULL)
```
- **Explicación:** Si el puntero hubiera sido NULL, el programa ya habría caído por Segmentation Fault en la línea de desreferencia anterior. La verificación tardía indica aserciones invertidas.
- **Sugerencia:** Ubicá la comprobación 'if (ptr == NULL)' antes de cualquier acceso a sus datos.
- **Ejemplo incorrecto:**
```c
*ptr = 10;
if (ptr != NULL) {
    // ...
}
```
- **Ejemplo recomendado:**
```c
if (ptr != NULL) {
    *ptr = 10;
}
```

#### Regla `0x3001h`: Comprobación de puntero nulo posterior a su desreferencia
- **Ubicación:** `consulta_csv.c:152`
```c
    if (bloque == NULL)
```
- **Explicación:** Si el puntero hubiera sido NULL, el programa ya habría caído por Segmentation Fault en la línea de desreferencia anterior. La verificación tardía indica aserciones invertidas.
- **Sugerencia:** Ubicá la comprobación 'if (ptr == NULL)' antes de cualquier acceso a sus datos.
- **Ejemplo incorrecto:**
```c
*ptr = 10;
if (ptr != NULL) {
    // ...
}
```
- **Ejemplo recomendado:**
```c
if (ptr != NULL) {
    *ptr = 10;
}
```

#### Regla `0x3001h`: Comprobación de puntero nulo posterior a su desreferencia
- **Ubicación:** `consulta_csv.c:194`
```c
    if (estadisticas == NULL)
```
- **Explicación:** Si el puntero hubiera sido NULL, el programa ya habría caído por Segmentation Fault en la línea de desreferencia anterior. La verificación tardía indica aserciones invertidas.
- **Sugerencia:** Ubicá la comprobación 'if (ptr == NULL)' antes de cualquier acceso a sus datos.
- **Ejemplo incorrecto:**
```c
*ptr = 10;
if (ptr != NULL) {
    // ...
}
```
- **Ejemplo recomendado:**
```c
if (ptr != NULL) {
    *ptr = 10;
}
```

#### Regla `0x3002h`: Puntero colgante sin asignar NULL tras free()
- **Ubicación:** `consulta_csv.c:256`
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
- **Ubicación:** `consulta_csv.c:257`
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

#### Regla `0x3008h`: Chequeo innecesario antes de free()
- **Ubicación:** `main.c:47`
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

#### Regla `0x3002h`: Puntero colgante sin asignar NULL tras free()
- **Ubicación:** `main.c:54`
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
- **Ubicación:** `prueba.c:27`
```c
    size_t filas = 0U;
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
- **Ubicación:** `prueba.c:50`
```c
    size_t filas = 0U;
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
- **Ubicación:** `prueba.c:89`
```c
    size_t filas = 0U;
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
- **Ubicación:** `prueba.c:107`
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
- **Ubicación:** `prueba.c:119`
```c
    size_t filas = 0U;
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
- **Ubicación:** `consola.c:187`
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
- **Ubicación:** `prueba.c:16`
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
- **Ubicación:** `prueba.c:46`
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
- **Ubicación:** `prueba.c:74`
```c
    int arreglo[3] = {0, 0, 0};
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
- **Ubicación:** `prueba.c:90`
```c
    int arreglo[] = {7, 11, 99};
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
- **Ubicación:** `punteros.c:23`
```c
    int temporal = *primer;
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
- **Ubicación:** `punteros.c:36`
```c
    const int *cursor = arreglo;
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
- **Ubicación:** `punteros.c:65`
```c
    int *cursor = arreglo;
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
- **Ubicación:** `punteros.c:83`
```c
    const int *cursor = arreglo;
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
    char *subcadena = cadena_subcadena_dinamica("Programacion", 12, 3, 5);
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
    char *invertida = cadena_invertir_dinamica("abcd", 5);
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
- **Ubicación:** `prueba.c:37`
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
- **Ubicación:** `prueba.c:58`
```c
    int primero[] = {1, 2, 3};
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
- **Ubicación:** `prueba.c:64`
```c
    free(fusionado);
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
- **Ubicación:** `prueba.c:74`
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

#### Regla `0x3001h`: Comprobación de puntero nulo posterior a su desreferencia
- **Ubicación:** `vector.c:19`
```c
    if (arreglo == NULL)
```
- **Explicación:** Si el puntero hubiera sido NULL, el programa ya habría caído por Segmentation Fault en la línea de desreferencia anterior. La verificación tardía indica aserciones invertidas.
- **Sugerencia:** Ubicá la comprobación 'if (ptr == NULL)' antes de cualquier acceso a sus datos.
- **Ejemplo incorrecto:**
```c
*ptr = 10;
if (ptr != NULL) {
    // ...
}
```
- **Ejemplo recomendado:**
```c
if (ptr != NULL) {
    *ptr = 10;
}
```

#### Regla `0x3001h`: Comprobación de puntero nulo posterior a su desreferencia
- **Ubicación:** `vector.c:49`
```c
    if (temp == NULL)
```
- **Explicación:** Si el puntero hubiera sido NULL, el programa ya habría caído por Segmentation Fault en la línea de desreferencia anterior. La verificación tardía indica aserciones invertidas.
- **Sugerencia:** Ubicá la comprobación 'if (ptr == NULL)' antes de cualquier acceso a sus datos.
- **Ejemplo incorrecto:**
```c
*ptr = 10;
if (ptr != NULL) {
    // ...
}
```
- **Ejemplo recomendado:**
```c
if (ptr != NULL) {
    *ptr = 10;
}
```

#### Regla `0x3001h`: Comprobación de puntero nulo posterior a su desreferencia
- **Ubicación:** `vector.c:84`
```c
    if (resultado == NULL)
```
- **Explicación:** Si el puntero hubiera sido NULL, el programa ya habría caído por Segmentation Fault en la línea de desreferencia anterior. La verificación tardía indica aserciones invertidas.
- **Sugerencia:** Ubicá la comprobación 'if (ptr == NULL)' antes de cualquier acceso a sus datos.
- **Ejemplo incorrecto:**
```c
*ptr = 10;
if (ptr != NULL) {
    // ...
}
```
- **Ejemplo recomendado:**
```c
if (ptr != NULL) {
    *ptr = 10;
}
```

#### Regla `0x3001h`: Comprobación de puntero nulo posterior a su desreferencia
- **Ubicación:** `vector.c:118`
```c
    if (nuevo_bloque == NULL)
```
- **Explicación:** Si el puntero hubiera sido NULL, el programa ya habría caído por Segmentation Fault en la línea de desreferencia anterior. La verificación tardía indica aserciones invertidas.
- **Sugerencia:** Ubicá la comprobación 'if (ptr == NULL)' antes de cualquier acceso a sus datos.
- **Ejemplo incorrecto:**
```c
*ptr = 10;
if (ptr != NULL) {
    // ...
}
```
- **Ejemplo recomendado:**
```c
if (ptr != NULL) {
    *ptr = 10;
}
```

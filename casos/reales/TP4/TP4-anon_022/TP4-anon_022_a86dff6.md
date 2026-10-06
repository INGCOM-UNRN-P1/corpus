# Informe de Corrección — TP4 (a86dff6)

## Repositorio
**branch/revision:** `main` `a86dff6`
**Commit SHA:** `a86dff65c29d9da9c76816e016b974346c726823`
**Autor:** `anon_022`
**Fecha del commit:** `2026-10-02 02:54:37 -0300`
**Mensaje:** `Ejercicio 6`
**Fecha de evaluación:** 2026-10-02 14:08:20
**Versión revisada:** `a86dff6`

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
│       └── prueba.c
├── libs/
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
| `[ARCHIVOS_BINARIOS]` | ❌ ERROR (31 filtrados) | 0.0/10 | — | Se detectaron binarios prohibidos (.o/.exe) en la entrega |
| `cadena_dinamica.c` | ❌ Falló Compilación | 9.5/10 | ✓ Limpio (0 fugas) | 2 advertencias |
| `cadena_dinamica.h` | ❌ Falló Compilación | 9.0/10 | ✓ Limpio (0 fugas) | 2 advertencias |
| `cadenas.c` | ❌ Falló Compilación | 9.5/10 | ✓ Limpio (0 fugas) | 35 advertencias |
| `cadenas.h` | ❌ Falló Compilación | 5.5/10 | ✓ Limpio (0 fugas) | 9 advertencias |
| `consulta_csv.c` | ❌ Falló Compilación | 10.0/10 | ✓ Limpio (0 fugas) | 24 advertencias |
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
| `libs/p1_test/build/libp1_test.a` | ❌ Falló Compilación | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `libs/p1_test/build/p1_test.o` | ❌ Falló Compilación | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `libs/p1_test/libp1_test.a` | ❌ Falló Compilación | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `libs/p1_test/prueba.o` | ❌ Falló Compilación | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `libs/p1_test/test_bin` | ❌ Falló Compilación | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `libs/string/cadenas.o` | ❌ Falló Compilación | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `libs/string/libstring.a` | ❌ Falló Compilación | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `libs/string/prueba.o` | ❌ Falló Compilación | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `libs/string/test_bin` | ❌ Falló Compilación | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `libs/vector/libvector.a` | ❌ Falló Compilación | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `libs/vector/prueba.o` | ❌ Falló Compilación | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `libs/vector/test_bin` | ❌ Falló Compilación | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `libs/vector/vector.o` | ❌ Falló Compilación | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `main.c` | ❌ Falló Compilación | 10.0/10 | ✓ Limpio (0 fugas) | 40 advertencias |
| `matriz_dinamica.c` | ❌ Falló Compilación | 10.0/10 | ✓ Limpio (0 fugas) | 32 advertencias |
| `matriz_dinamica.h` | ❌ Falló Compilación | 8.5/10 | ✓ Limpio (0 fugas) | 3 advertencias |
| `prueba.c` | ❌ Falló Compilación | 3.5/10 | ✓ Limpio (0 fugas) | 92 advertencias |
| `registro_csv.c` | ❌ Falló Compilación | 9.5/10 | ✓ Limpio (0 fugas) | 13 advertencias |
| `texto_dinamico.c` | ❌ Falló Compilación | 9.5/10 | ✓ Limpio (0 fugas) | 5 advertencias |
| `texto_dinamico.h` | ❌ Falló Compilación | 9.5/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `vector.c` | ❌ Falló Compilación | 10.0/10 | ✓ Limpio (0 fugas) | 12 advertencias |
| `vector.h` | ❌ Falló Compilación | 6.0/10 | ✓ Limpio (0 fugas) | 8 advertencias |
| `vector_enteros.c` | ❌ Falló Compilación | 9.0/10 | ✓ Limpio (0 fugas) | 6 advertencias |
| `vector_enteros.h` | ❌ Falló Compilación | 7.5/10 | ✓ Limpio (0 fugas) | 5 advertencias |

## ⚠️ Archivos Binarios Prohibidos Filtrados

> ❌ **ERROR DE ENTREGA:** Se detectaron archivos binarios precompilados o ejecutables en la entrega del estudiante. 
> Para mantener la reproducibilidad académica y evitar la ejecución de código no compilado desde fuentes, estos archivos fueron **filtrados y descartados** de la evaluación.

| Archivo Binario | Regla | Severidad | Detalle del Error | Sugerencia |
| :--- | :---: | :---: | :--- | :--- |
| `libs/p1_test/libp1_test.a` | `0x000Fh` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'libs/p1_test/libp1_test.a' (Extensión binaria prohibida '.a'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `libs/p1_test/prueba.o` | `0x000Fh` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'libs/p1_test/prueba.o' (Extensión binaria prohibida '.o'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `libs/p1_test/test_bin` | `0x000Fh` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'libs/p1_test/test_bin' (Firma binaria ejecutable detectada (Formato ejecutable o archivo objeto Linux ELF)). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
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

**Acción Requerida:** Las entregas deben contener exclusivamente código fuente editable (`.c`, `.h`), archivos de configuración (`Makefile`) y documentación (`.md`, `.txt`). Ejecutá `make clean` antes de comprimir tu entrega y verificá tu archivo `.gitignore`.

## Compilación — Makefile raíz del Proyecto

❌ **Estado:** Falló la compilación mediante el Makefile de la raíz.

```text
In file included from prueba.c:7:
prueba.c: In function ‘_p1_test_func_prueba_matriz_destruir’:
prueba.c:74:17: error: ‘true’ undeclared (first use in this function)
   74 |     ASSERT_TRUE(true);
      |                 ^~~~
../../libs/p1_test/include/p1_test.h:811:11: note: in definition of macro ‘ASSERT_TRUE_MSG’
  811 |     if (!(cond)) { \
      |           ^~~~
prueba.c:74:5: note: in expansion of macro ‘ASSERT_TRUE’
   74 |     ASSERT_TRUE(true);
      |     ^~~~~~~~~~~
prueba.c:9:1: note: ‘true’ is defined in header ‘<stdbool.h>’; this is probably fixable by adding ‘#include <stdbool.h>’
    8 | #include "matriz_dinamica.h"
  +++ |+#include <stdbool.h>
    9 | 
prueba.c:74:17: note: each undeclared identifier is reported only once for each function it appears in
   74 |     ASSERT_TRUE(true);
      |                 ^~~~
../../libs/p1_test/include/p1_test.h:811:11: note: in definition of macro ‘ASSERT_TRUE_MSG’
  811 |     if (!(cond)) { \
      |           ^~~~
prueba.c:74:5: note: in expansion of macro ‘ASSERT_TRUE’
   74 |     ASSERT_TRUE(true);
      |     ^~~~~~~~~~~
make[1]: *** [Makefile:47: prueba.o] Error 1
make: *** [Makefile:24: ejercicios/ejercicio4] Error 1

```

> 📄 **Salida completa:** registrada en `compilacion_a86dff6.log`.

## Observaciones de Calidad y Reglas P1 (Linter AST / Ripley)

Se detectaron **239** observación(es) en el código C:

| Regla | Ubicación | Severidad | Observación | Sugerencia |
| :--- | :--- | :---: | :--- | :--- |
| `0x0004h` | `main.c:1` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:28` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:38` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:45` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:49` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:50` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:1` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `prueba.c:14` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0005h` | `prueba.c:22` | ESTILO | La llave de apertura para `for` debe estar en una nueva línea. | Ubicar '{' en el renglón siguiente alineada verticalmente. |
| `0x0004h` | `prueba.c:25` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:45` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `prueba.c:56` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `prueba.c:56` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `vector_enteros.c:1` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `vector_enteros.c:30` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `vector_enteros.c:47` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `vector_enteros.c:52` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:1` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:20` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:21` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:23` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:31` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:33` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:1` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:21` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:35` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:42` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `prueba.c:45` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `prueba.c:45` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `texto_dinamico.c:1` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0018h` | `texto_dinamico.c:55` | ESTILO | El asterisco del puntero debe estar junto al identificador (ej. 'int *ptr;'). | Escribir 'tipo *nombre_var' en lugar de 'tipo* nombre_var'. |
| `0x0018h` | `texto_dinamico.c:71` | ESTILO | El asterisco del puntero debe estar junto al identificador (ej. 'int *ptr;'). | Escribir 'tipo *nombre_var' en lugar de 'tipo* nombre_var'. |
| `0x0004h` | `cadena_dinamica.c:1` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:1` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:1` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:22` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:32` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:53` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:65` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:75` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:85` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:95` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `prueba.c:119` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `prueba.c:119` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:1` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:17` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0005h` | `main.c:19` | ESTILO | La llave de apertura para `if` debe estar en una nueva línea. | Ubicar '{' en el renglón siguiente alineada verticalmente. |
| `0x0005h` | `main.c:27` | ESTILO | La llave de apertura para `for` debe estar en una nueva línea. | Ubicar '{' en el renglón siguiente alineada verticalmente. |
| `0x0005h` | `main.c:28` | ESTILO | La llave de apertura para `for` debe estar en una nueva línea. | Ubicar '{' en el renglón siguiente alineada verticalmente. |
| `0x0005h` | `main.c:36` | ESTILO | La llave de apertura para `for` debe estar en una nueva línea. | Ubicar '{' en el renglón siguiente alineada verticalmente. |
| `0x0005h` | `main.c:37` | ESTILO | La llave de apertura para `for` debe estar en una nueva línea. | Ubicar '{' en el renglón siguiente alineada verticalmente. |
| `0x0004h` | `main.c:38` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0005h` | `main.c:58` | ESTILO | La llave de apertura para `if` debe estar en una nueva línea. | Ubicar '{' en el renglón siguiente alineada verticalmente. |
| `0x0005h` | `main.c:63` | ESTILO | La llave de apertura para `for` debe estar en una nueva línea. | Ubicar '{' en el renglón siguiente alineada verticalmente. |
| `0x0005h` | `main.c:64` | ESTILO | La llave de apertura para `for` debe estar en una nueva línea. | Ubicar '{' en el renglón siguiente alineada verticalmente. |
| `0x0004h` | `main.c:65` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0xEEEEh` | `matriz_dinamica.c:45` | ESTILO | Indentación no es múltiplo de 4 espacios (30 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `matriz_dinamica.c:46` | ESTILO | Indentación no es múltiplo de 4 espacios (30 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0x0004h` | `matriz_dinamica.c:1` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `matriz_dinamica.c:10` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `matriz_dinamica.c:10` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0005h` | `matriz_dinamica.c:12` | ESTILO | La llave de apertura para `if` debe estar en una nueva línea. | Ubicar '{' en el renglón siguiente alineada verticalmente. |
| `0x0018h` | `matriz_dinamica.c:16` | ESTILO | El asterisco del puntero debe estar junto al identificador (ej. 'int *ptr;'). | Escribir 'tipo *nombre_var' en lugar de 'tipo* nombre_var'. |
| `0x0005h` | `matriz_dinamica.c:17` | ESTILO | La llave de apertura para `if` debe estar en una nueva línea. | Ubicar '{' en el renglón siguiente alineada verticalmente. |
| `0x0004h` | `matriz_dinamica.c:21` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0018h` | `matriz_dinamica.c:21` | ESTILO | El asterisco del puntero debe estar junto al identificador (ej. 'int *ptr;'). | Escribir 'tipo *nombre_var' en lugar de 'tipo* nombre_var'. |
| `0x0005h` | `matriz_dinamica.c:22` | ESTILO | La llave de apertura para `if` debe estar en una nueva línea. | Ubicar '{' en el renglón siguiente alineada verticalmente. |
| `0x0005h` | `matriz_dinamica.c:27` | ESTILO | La llave de apertura para `for` debe estar en una nueva línea. | Ubicar '{' en el renglón siguiente alineada verticalmente. |
| `0x0018h` | `matriz_dinamica.c:28` | ESTILO | El asterisco del puntero debe estar junto al identificador (ej. 'int *ptr;'). | Escribir 'tipo *nombre_var' en lugar de 'tipo* nombre_var'. |
| `0x0004h` | `matriz_dinamica.c:34` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0005h` | `matriz_dinamica.c:36` | ESTILO | La llave de apertura para `if` debe estar en una nueva línea. | Ubicar '{' en el renglón siguiente alineada verticalmente. |
| `0x0004h` | `matriz_dinamica.c:44` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0005h` | `matriz_dinamica.c:48` | ESTILO | La llave de apertura para `if` debe estar en una nueva línea. | Ubicar '{' en el renglón siguiente alineada verticalmente. |
| `0x0005h` | `matriz_dinamica.c:54` | ESTILO | La llave de apertura para `if` debe estar en una nueva línea. | Ubicar '{' en el renglón siguiente alineada verticalmente. |
| `0x0005h` | `matriz_dinamica.c:63` | ESTILO | La llave de apertura para `while` debe estar en una nueva línea. | Ubicar '{' en el renglón siguiente alineada verticalmente. |
| `0x0004h` | `matriz_dinamica.c:65` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0005h` | `matriz_dinamica.c:65` | ESTILO | La llave de apertura para `if` debe estar en una nueva línea. | Ubicar '{' en el renglón siguiente alineada verticalmente. |
| `0x0005h` | `matriz_dinamica.c:68` | ESTILO | La llave de apertura para `for` debe estar en una nueva línea. | Ubicar '{' en el renglón siguiente alineada verticalmente. |
| `0x0005h` | `matriz_dinamica.c:69` | ESTILO | La llave de apertura para `if` debe estar en una nueva línea. | Ubicar '{' en el renglón siguiente alineada verticalmente. |
| `0x0004h` | `matriz_dinamica.c:78` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0005h` | `matriz_dinamica.c:78` | ESTILO | La llave de apertura para `if` debe estar en una nueva línea. | Ubicar '{' en el renglón siguiente alineada verticalmente. |
| `0x0004h` | `matriz_dinamica.c:85` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0005h` | `matriz_dinamica.c:87` | ESTILO | La llave de apertura para `if` debe estar en una nueva línea. | Ubicar '{' en el renglón siguiente alineada verticalmente. |
| `0x0005h` | `matriz_dinamica.c:92` | ESTILO | La llave de apertura para `for` debe estar en una nueva línea. | Ubicar '{' en el renglón siguiente alineada verticalmente. |
| `0x0005h` | `matriz_dinamica.c:94` | ESTILO | La llave de apertura para `for` debe estar en una nueva línea. | Ubicar '{' en el renglón siguiente alineada verticalmente. |
| `0x0004h` | `matriz_dinamica.c:96` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0005h` | `matriz_dinamica.c:96` | ESTILO | La llave de apertura para `if` debe estar en una nueva línea. | Ubicar '{' en el renglón siguiente alineada verticalmente. |
| `0x0005h` | `matriz_dinamica.c:102` | ESTILO | La llave de apertura para `if` debe estar en una nueva línea. | Ubicar '{' en el renglón siguiente alineada verticalmente. |
| `0x0004h` | `prueba.c:1` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:14` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:68` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0005h` | `prueba.c:88` | ESTILO | La llave de apertura para `if` debe estar en una nueva línea. | Ubicar '{' en el renglón siguiente alineada verticalmente. |
| `0x0004h` | `prueba.c:107` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `prueba.c:165` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `prueba.c:165` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:1` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:16` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:32` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:1` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:15` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:23` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:37` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:49` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:73` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:77` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:86` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `prueba.c:91` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `prueba.c:91` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0xEEEEh` | `registro_csv.c:11` | ESTILO | Indentación no es múltiplo de 4 espacios (25 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `registro_csv.c:12` | ESTILO | Indentación no es múltiplo de 4 espacios (25 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `registro_csv.c:79` | ESTILO | Indentación no es múltiplo de 4 espacios (29 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0x0004h` | `registro_csv.c:1` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `registro_csv.c:3` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `registro_csv.c:10` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `registro_csv.c:39` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0018h` | `registro_csv.c:39` | ESTILO | El asterisco del puntero debe estar junto al identificador (ej. 'int *ptr;'). | Escribir 'tipo *nombre_var' en lugar de 'tipo* nombre_var'. |
| `0x0004h` | `registro_csv.c:66` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `registro_csv.c:78` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `registro_csv.c:88` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `registro_csv.c:91` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0xEEEEh` | `consulta_csv.c:78` | ESTILO | Indentación no es múltiplo de 4 espacios (19 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `consulta_csv.c:79` | ESTILO | Indentación no es múltiplo de 4 espacios (19 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `consulta_csv.c:80` | ESTILO | Indentación no es múltiplo de 4 espacios (19 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `consulta_csv.c:81` | ESTILO | Indentación no es múltiplo de 4 espacios (19 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `consulta_csv.c:82` | ESTILO | Indentación no es múltiplo de 4 espacios (19 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `consulta_csv.c:138` | ESTILO | Indentación no es múltiplo de 4 espacios (31 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `consulta_csv.c:139` | ESTILO | Indentación no es múltiplo de 4 espacios (31 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `consulta_csv.c:166` | ESTILO | Indentación no es múltiplo de 4 espacios (35 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `consulta_csv.c:167` | ESTILO | Indentación no es múltiplo de 4 espacios (35 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `consulta_csv.c:187` | ESTILO | Indentación no es múltiplo de 4 espacios (18 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `consulta_csv.c:188` | ESTILO | Indentación no es múltiplo de 4 espacios (18 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `consulta_csv.c:189` | ESTILO | Indentación no es múltiplo de 4 espacios (18 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0x0004h` | `consulta_csv.c:47` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `consulta_csv.c:57` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `consulta_csv.c:63` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0018h` | `consulta_csv.c:95` | ESTILO | El asterisco del puntero debe estar junto al identificador (ej. 'int *ptr;'). | Escribir 'tipo *nombre_var' en lugar de 'tipo* nombre_var'. |
| `0x0018h` | `consulta_csv.c:108` | ESTILO | El asterisco del puntero debe estar junto al identificador (ej. 'int *ptr;'). | Escribir 'tipo *nombre_var' en lugar de 'tipo* nombre_var'. |
| `0x0018h` | `consulta_csv.c:119` | ESTILO | El asterisco del puntero debe estar junto al identificador (ej. 'int *ptr;'). | Escribir 'tipo *nombre_var' en lugar de 'tipo* nombre_var'. |
| `0x0018h` | `consulta_csv.c:123` | ESTILO | El asterisco del puntero debe estar junto al identificador (ej. 'int *ptr;'). | Escribir 'tipo *nombre_var' en lugar de 'tipo* nombre_var'. |
| `0x0018h` | `consulta_csv.c:124` | ESTILO | El asterisco del puntero debe estar junto al identificador (ej. 'int *ptr;'). | Escribir 'tipo *nombre_var' en lugar de 'tipo* nombre_var'. |
| `0x0018h` | `consulta_csv.c:157` | ESTILO | El asterisco del puntero debe estar junto al identificador (ej. 'int *ptr;'). | Escribir 'tipo *nombre_var' en lugar de 'tipo* nombre_var'. |
| `0x0004h` | `consulta_csv.c:209` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0018h` | `consulta_csv.c:210` | ESTILO | El asterisco del puntero debe estar junto al identificador (ej. 'int *ptr;'). | Escribir 'tipo *nombre_var' en lugar de 'tipo* nombre_var'. |
| `0x0004h` | `consulta_csv.c:228` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0xEEEEh` | `main.c:31` | ESTILO | Indentación no es múltiplo de 4 espacios (11 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `main.c:37` | ESTILO | Indentación no es múltiplo de 4 espacios (11 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0x0004h` | `main.c:1` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:20` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:38` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:43` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:48` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:65` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:92` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:93` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:126` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:127` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:1` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:38` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:71` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:147` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0018h` | `prueba.c:154` | ESTILO | El asterisco del puntero debe estar junto al identificador (ej. 'int *ptr;'). | Escribir 'tipo *nombre_var' en lugar de 'tipo* nombre_var'. |
| `0x0004h` | `prueba.c:158` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `prueba.c:164` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `prueba.c:164` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0xEEEEh` | `cadenas.c:103` | ESTILO | Indentación no es múltiplo de 4 espacios (22 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `cadenas.c:104` | ESTILO | Indentación no es múltiplo de 4 espacios (22 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `cadenas.c:105` | ESTILO | Indentación no es múltiplo de 4 espacios (22 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `cadenas.c:106` | ESTILO | Indentación no es múltiplo de 4 espacios (22 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `cadenas.c:170` | ESTILO | Indentación no es múltiplo de 4 espacios (27 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `cadenas.c:222` | ESTILO | Indentación no es múltiplo de 4 espacios (33 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `cadenas.c:223` | ESTILO | Indentación no es múltiplo de 4 espacios (33 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `cadenas.c:224` | ESTILO | Indentación no es múltiplo de 4 espacios (33 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0x0004h` | `cadenas.c:1` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0005h` | `cadenas.c:13` | ESTILO | La llave de apertura para `if` debe estar en una nueva línea. | Ubicar '{' en el renglón siguiente alineada verticalmente. |
| `0x0005h` | `cadenas.c:17` | ESTILO | La llave de apertura para `for` debe estar en una nueva línea. | Ubicar '{' en el renglón siguiente alineada verticalmente. |
| `0x0005h` | `cadenas.c:18` | ESTILO | La llave de apertura para `if` debe estar en una nueva línea. | Ubicar '{' en el renglón siguiente alineada verticalmente. |
| `0x0002h` | `cadenas.c:26` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0005h` | `cadenas.c:28` | ESTILO | La llave de apertura para `if` debe estar en una nueva línea. | Ubicar '{' en el renglón siguiente alineada verticalmente. |
| `0x0005h` | `cadenas.c:32` | ESTILO | La llave de apertura para `for` debe estar en una nueva línea. | Ubicar '{' en el renglón siguiente alineada verticalmente. |
| `0x0005h` | `cadenas.c:33` | ESTILO | La llave de apertura para `if` debe estar en una nueva línea. | Ubicar '{' en el renglón siguiente alineada verticalmente. |
| `0x0005h` | `cadenas.c:38` | ESTILO | La llave de apertura para `if` debe estar en una nueva línea. | Ubicar '{' en el renglón siguiente alineada verticalmente. |
| `0x0002h` | `cadenas.c:49` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0005h` | `cadenas.c:51` | ESTILO | La llave de apertura para `if` debe estar en una nueva línea. | Ubicar '{' en el renglón siguiente alineada verticalmente. |
| `0x0005h` | `cadenas.c:57` | ESTILO | La llave de apertura para `if` debe estar en una nueva línea. | Ubicar '{' en el renglón siguiente alineada verticalmente. |
| `0x0005h` | `cadenas.c:61` | ESTILO | La llave de apertura para `for` debe estar en una nueva línea. | Ubicar '{' en el renglón siguiente alineada verticalmente. |
| `0x0005h` | `cadenas.c:63` | ESTILO | La llave de apertura para `if` debe estar en una nueva línea. | Ubicar '{' en el renglón siguiente alineada verticalmente. |
| `0x0005h` | `cadenas.c:68` | ESTILO | La llave de apertura para `if` debe estar en una nueva línea. | Ubicar '{' en el renglón siguiente alineada verticalmente. |
| `0x0005h` | `cadenas.c:82` | ESTILO | La llave de apertura para `if` debe estar en una nueva línea. | Ubicar '{' en el renglón siguiente alineada verticalmente. |
| `0x0005h` | `cadenas.c:88` | ESTILO | La llave de apertura para `for` debe estar en una nueva línea. | Ubicar '{' en el renglón siguiente alineada verticalmente. |
| `0x0005h` | `cadenas.c:89` | ESTILO | La llave de apertura para `if` debe estar en una nueva línea. | Ubicar '{' en el renglón siguiente alineada verticalmente. |
| `0x0005h` | `cadenas.c:93` | ESTILO | La llave de apertura para `if` debe estar en una nueva línea. | Ubicar '{' en el renglón siguiente alineada verticalmente. |
| `0x0005h` | `cadenas.c:108` | ESTILO | La llave de apertura para `if` debe estar en una nueva línea. | Ubicar '{' en el renglón siguiente alineada verticalmente. |
| `0x0005h` | `cadenas.c:114` | ESTILO | La llave de apertura para `while` debe estar en una nueva línea. | Ubicar '{' en el renglón siguiente alineada verticalmente. |
| `0x0005h` | `cadenas.c:118` | ESTILO | La llave de apertura para `if` debe estar en una nueva línea. | Ubicar '{' en el renglón siguiente alineada verticalmente. |
| `0x0005h` | `cadenas.c:125` | ESTILO | La llave de apertura para `while` debe estar en una nueva línea. | Ubicar '{' en el renglón siguiente alineada verticalmente. |
| `0x0005h` | `cadenas.c:126` | ESTILO | La llave de apertura para `if` debe estar en una nueva línea. | Ubicar '{' en el renglón siguiente alineada verticalmente. |
| `0x0004h` | `cadenas.c:203` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `cadenas.c:210` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:1` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:16` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:30` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:44` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:51` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:58` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:72` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:79` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `prueba.c:87` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `prueba.c:87` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:1` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0005h` | `prueba.c:18` | ESTILO | La llave de apertura para `for` debe estar en una nueva línea. | Ubicar '{' en el renglón siguiente alineada verticalmente. |
| `0x0004h` | `prueba.c:24` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:30` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:51` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:72` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:83` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:89` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:106` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:120` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:128` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:137` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:138` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:139` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:146` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:152` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:158` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `prueba.c:161` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `prueba.c:161` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0xEEEEh` | `vector.c:58` | ESTILO | Indentación no es múltiplo de 4 espacios (30 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `vector.c:85` | ESTILO | Indentación no es múltiplo de 4 espacios (31 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `vector.c:86` | ESTILO | Indentación no es múltiplo de 4 espacios (31 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0x0004h` | `vector.c:1` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `vector.c:26` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `vector.c:33` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0018h` | `vector.c:47` | ESTILO | El asterisco del puntero debe estar junto al identificador (ej. 'int *ptr;'). | Escribir 'tipo *nombre_var' en lugar de 'tipo* nombre_var'. |
| `0x0005h` | `vector.c:60` | ESTILO | La llave de apertura para `if` debe estar en una nueva línea. | Ubicar '{' en el renglón siguiente alineada verticalmente. |
| `0x0004h` | `vector.c:84` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `vector.c:88` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `vector.c:89` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `vector.c:98` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |

## Pruebas del Proyecto — Makefile raíz (`make test`)

❌ **Estado:** Fallaron las pruebas del proyecto (`make test`).

```text
make: Entering directory '/home/mrtin/dev/p1/ripley/entregas/TP4/TP4-anon_022/repo'
Compilando librería en libs/p1_test...
make[1]: Entering directory '/home/mrtin/dev/p1/ripley/entregas/TP4/TP4-anon_022/repo/libs/p1_test'
make[1]: Nothing to be done for 'all'.
make[1]: Leaving directory '/home/mrtin/dev/p1/ripley/entregas/TP4/TP4-anon_022/repo/libs/p1_test'
Compilando librería en libs/string...
make[1]: Entering directory '/home/mrtin/dev/p1/ripley/entregas/TP4/TP4-anon_022/repo/libs/string'
make[1]: Nothing to be done for 'all'.
make[1]: Leaving directory '/home/mrtin/dev/p1/ripley/entregas/TP4/
```

## Auditoría de Memoria Dinámica — Valgrind

✓ **Estado:** No se detectaron fugas de memoria durante las pruebas en sandbox.

## Linter de Estilo y Formato — Gaff

⚠️ Se detectaron **47** observación(es) de estilo arquitectónico:

| Regla | Ubicación | Observación | Sugerencia | Autofix |
| :--- | :--- | :--- | :--- | :---: |
| `GAFF009` | `prueba.c:14` | La línea tiene 94 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `prueba.c:58` | La línea tiene 84 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `vector_enteros.c:3` | La línea tiene 83 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `vector_enteros.c:30` | La línea tiene 93 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `vector_enteros.h:12` | La línea tiene 83 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `vector_enteros.h:21` | La línea tiene 81 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `vector_enteros.h:23` | La línea tiene 86 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `vector_enteros.h:51` | La línea tiene 92 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `vector_enteros.h:64` | La línea tiene 94 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `prueba.c:47` | La línea tiene 84 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `0x0001h` | `prueba.c:32` | Identificador corto y poco expresivo 'rep' (3 caracteres). | Se recomienda utilizar identificadores más descriptivos del dominio del problema. | No |
| `0x0001h` | `texto_dinamico.c:33` | Identificador corto y poco expresivo 'fin' (3 caracteres). | Se recomienda utilizar identificadores más descriptivos del dominio del problema. | No |
| `GAFF009` | `texto_dinamico.h:17` | La línea tiene 86 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `cadena_dinamica.c:9` | La línea tiene 85 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `cadena_dinamica.h:17` | La línea tiene 83 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `cadena_dinamica.h:23` | La línea tiene 82 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `matriz_dinamica.h:19` | La línea tiene 82 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `matriz_dinamica.h:22` | La línea tiene 83 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `matriz_dinamica.h:23` | La línea tiene 86 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `prueba.c:93` | La línea tiene 84 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `registro_csv.c:3` | La línea tiene 90 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `cadenas.c:172` | La línea tiene 83 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `cadenas.h:3` | La línea tiene 94 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `cadenas.h:100` | La línea tiene 109 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `cadenas.h:112` | La línea tiene 84 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `cadenas.h:178` | La línea tiene 85 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `cadenas.h:198` | La línea tiene 83 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `cadenas.h:200` | La línea tiene 86 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `cadenas.h:209` | La línea tiene 109 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `cadenas.h:224` | La línea tiene 81 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `cadenas.h:228` | La línea tiene 107 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `prueba.c:89` | La línea tiene 82 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `0x0001h` | `prueba.c:13` | Identificador corto y poco expresivo 'dup' (3 caracteres). | Se recomienda utilizar identificadores más descriptivos del dominio del problema. | No |
| `GAFF009` | `prueba.c:120` | La línea tiene 101 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `prueba.c:137` | La línea tiene 81 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `prueba.c:138` | La línea tiene 81 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `prueba.c:139` | La línea tiene 81 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `prueba.c:152` | La línea tiene 89 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `prueba.c:163` | La línea tiene 82 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `vector.h:3` | La línea tiene 91 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `vector.h:9` | La línea tiene 83 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `vector.h:11` | La línea tiene 90 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `vector.h:51` | La línea tiene 85 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `vector.h:72` | La línea tiene 83 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `vector.h:101` | La línea tiene 87 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `vector.h:145` | La línea tiene 85 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `vector.h:153` | La línea tiene 85 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |

## Auditoría de Seguridad — Sandbox / Kaneda

⚠️ **Alerta:** Se detectaron **31** llamadas o patrones de riesgo de seguridad:

| Regla | Archivo:Línea | Severidad | Detalle | Sugerencia |
| :--- | :--- | :---: | :--- | :--- |
| `0x000Fh` | `libs/p1_test/libp1_test.a:1` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'libs/p1_test/libp1_test.a' (Extensión binaria prohibida '.a'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `0x000Fh` | `libs/p1_test/prueba.o:1` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'libs/p1_test/prueba.o' (Extensión binaria prohibida '.o'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `0x000Fh` | `libs/p1_test/test_bin:1` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'libs/p1_test/test_bin' (Firma binaria ejecutable detectada (Formato ejecutable o archivo objeto Linux ELF)). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
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

## Antipatrones Didácticos — Spunkmeyer

Se detectaron **91** observación(es) de antipatrones didácticos:

| Regla | Ubicación | Antipatrón | Diagnóstico | Sugerencia |
| :--- | :--- | :--- | :--- | :--- |
| `0x7001h` | `main.c:14` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `prueba.c:19` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `prueba.c:36` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `vector_enteros.c:16` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `vector_enteros.c:52` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `main.c:14` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `prueba.c:18` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `prueba.c:32` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `texto_dinamico.c:16` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `texto_dinamico.c:49` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `cadena_dinamica.c:18` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `cadena_dinamica.c:49` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `main.c:21` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `prueba.c:15` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `prueba.c:60` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `main.c:14` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `matriz_dinamica.c:16` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x3002h` | `matriz_dinamica.c:40` | **Puntero colgante sin asignar NULL tras free()** | Puntero 'matriz' liberado con free() pero no anulado con NULL posteriormente. | Asigná 'ptr = NULL;' inmediatamente después de 'free(ptr);'. |
| `0x3002h` | `matriz_dinamica.c:41` | **Puntero colgante sin asignar NULL tras free()** | Puntero 'matriz' liberado con free() pero no anulado con NULL posteriormente. | Asigná 'ptr = NULL;' inmediatamente después de 'free(ptr);'. |
| `0x7001h` | `matriz_dinamica.c:52` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `prueba.c:14` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `prueba.c:68` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `prueba.c:104` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `main.c:13` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `prueba.c:14` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `prueba.c:72` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `registro_csv.c:27` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `consulta_csv.c:17` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `consulta_csv.c:91` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `consulta_csv.c:146` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x3002h` | `consulta_csv.c:157` | **Modificación directa del puntero base asignado por malloc()** | Modificación directa del puntero base 'sumas' retornado por malloc/calloc. | Utilizá un puntero auxiliar iterador ('tipo *iter = ptr; iter++;') o indexación por corchetes ('ptr[i]'). |
| `0x7001h` | `consulta_csv.c:196` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `main.c:15` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x3002h` | `main.c:89` | **Puntero colgante sin asignar NULL tras free()** | Puntero 'sumas' liberado con free() pero no anulado con NULL posteriormente. | Asigná 'ptr = NULL;' inmediatamente después de 'free(ptr);'. |
| `0x3002h` | `main.c:90` | **Puntero colgante sin asignar NULL tras free()** | Puntero 'promedios' liberado con free() pero no anulado con NULL posteriormente. | Asigná 'ptr = NULL;' inmediatamente después de 'free(ptr);'. |
| `0x3002h` | `main.c:123` | **Puntero colgante sin asignar NULL tras free()** | Puntero 'sumas' liberado con free() pero no anulado con NULL posteriormente. | Asigná 'ptr = NULL;' inmediatamente después de 'free(ptr);'. |
| `0x3002h` | `main.c:124` | **Puntero colgante sin asignar NULL tras free()** | Puntero 'promedios' liberado con free() pero no anulado con NULL posteriormente. | Asigná 'ptr = NULL;' inmediatamente después de 'free(ptr);'. |
| `0x4001h` | `prueba.c:17` | **Omisión de verificación de retorno NULL en fopen()** | Uso de descriptor de archivo 'archivo' devuelto por fopen() en línea 15 sin comprobación previa de NULL. | Verificá siempre 'if (f == NULL)' inmediatamente después de invocar 'fopen()'. |
| `0x7001h` | `prueba.c:22` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x3002h` | `prueba.c:91` | **Puntero colgante sin asignar NULL tras free()** | Puntero 'sumas' liberado con free() pero no anulado con NULL posteriormente. | Asigná 'ptr = NULL;' inmediatamente después de 'free(ptr);'. |
| `0x3002h` | `prueba.c:111` | **Puntero colgante sin asignar NULL tras free()** | Puntero 'promedios' liberado con free() pero no anulado con NULL posteriormente. | Asigná 'ptr = NULL;' inmediatamente después de 'free(ptr);'. |
| `0x7001h` | `prueba.c:132` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
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
| `0x7001h` | `cadenas.c:55` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `cadenas.c:86` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `cadenas.c:112` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `cadenas.c:150` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `cadenas.c:177` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `cadenas.c:231` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `cadenas.c:265` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `prueba.c:13` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `prueba.c:27` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `prueba.c:41` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `prueba.c:69` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `prueba.c:16` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `prueba.c:37` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `prueba.c:59` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `prueba.c:113` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `vector.c:16` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `vector.c:47` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `vector.c:64` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |

### 🔍 Detalle Pedagógico de Antipatrones

#### Regla `0x7001h`: Declaración de variable mezclada tras sentencias ejecutables
- **Ubicación:** `main.c:14`
```c
    int origen[] = {3, 8, 5, 10, 7, 4};
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

#### Regla `0x7001h`: Declaración de variable mezclada tras sentencias ejecutables
- **Ubicación:** `vector_enteros.c:16`
```c
    int *nuevo_bloque = calloc(cantidad, sizeof(int));
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
- **Ubicación:** `vector_enteros.c:52`
```c
    int *resultado = crear_bloque_enteros(*cantidad_pares);
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
- **Ubicación:** `main.c:14`
```c
    const char *texto = "   Hola mundo   ";
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

#### Regla `0x7001h`: Declaración de variable mezclada tras sentencias ejecutables
- **Ubicación:** `texto_dinamico.c:16`
```c
    size_t largo = 0;
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
- **Ubicación:** `texto_dinamico.c:49`
```c
    size_t largo = 0;
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
- **Ubicación:** `cadena_dinamica.c:18`
```c
    size_t longitud = 0;
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
- **Ubicación:** `cadena_dinamica.c:49`
```c
    size_t longitud_primera = 0;
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
- **Ubicación:** `main.c:21`
```c
    size_t longitud_primera = cadena_longitud(primera, sizeof(primera));
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
    char origen[] = "Hola mundo";
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
- **Ubicación:** `prueba.c:60`
```c
    char *resultado = unir_cadenas_dinamicas("Hola", " mundo");
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
- **Ubicación:** `main.c:14`
```c
    size_t filas = 2;
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
- **Ubicación:** `matriz_dinamica.c:16`
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
- **Ubicación:** `matriz_dinamica.c:40`
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
- **Ubicación:** `matriz_dinamica.c:41`
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
- **Ubicación:** `matriz_dinamica.c:52`
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
- **Ubicación:** `prueba.c:14`
```c
    int **matriz = matriz_crear(3, 4);
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
    int **matriz = matriz_crear(3, 3);
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
- **Ubicación:** `main.c:13`
```c
    const char *linea = "UNRN,2026,Bariloche";
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
- **Ubicación:** `prueba.c:14`
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
- **Ubicación:** `prueba.c:72`
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
- **Ubicación:** `registro_csv.c:27`
```c
    size_t longitud_linea = 0;
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
- **Ubicación:** `consulta_csv.c:17`
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
- **Ubicación:** `consulta_csv.c:91`
```c
    size_t cantidad_filtradas = 0;
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
    float *sumas = calloc(columnas, sizeof(float));
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

#### Regla `0x3002h`: Modificación directa del puntero base asignado por malloc()
- **Ubicación:** `consulta_csv.c:157`
```c
            sumas[columna] += matriz[fila * columnas + columna];
```
- **Explicación:** Modificar el puntero original hace que se pierda la dirección de inicio del bloque asignado, impidiendo luego pasar la dirección correcta a 'free()' y generando fallas de liberación.
- **Sugerencia:** Utilizá un puntero auxiliar iterador ('tipo *iter = ptr; iter++;') o indexación por corchetes ('ptr[i]').
- **Ejemplo incorrecto:**
```c
char *p = malloc(100);
while (*p) p++;
free(p);
```
- **Ejemplo recomendado:**
```c
char *p = malloc(100);
char *iter = p;
while (*iter) iter++;
free(p);
```

#### Regla `0x7001h`: Declaración de variable mezclada tras sentencias ejecutables
- **Ubicación:** `consulta_csv.c:196`
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

#### Regla `0x7001h`: Declaración de variable mezclada tras sentencias ejecutables
- **Ubicación:** `main.c:15`
```c
    char ruta[256];
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
- **Ubicación:** `main.c:89`
```c
        free(sumas);
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
- **Ubicación:** `main.c:90`
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
- **Ubicación:** `main.c:123`
```c
    free(sumas);
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
- **Ubicación:** `main.c:124`
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

#### Regla `0x4001h`: Omisión de verificación de retorno NULL en fopen()
- **Ubicación:** `prueba.c:17`
```c
    fprintf(archivo, "10,20,30\n");
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
- **Ubicación:** `prueba.c:22`
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

#### Regla `0x3002h`: Puntero colgante sin asignar NULL tras free()
- **Ubicación:** `prueba.c:91`
```c
    free(sumas);
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
- **Ubicación:** `prueba.c:111`
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
- **Ubicación:** `prueba.c:132`
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
- **Ubicación:** `cadenas.c:55`
```c
    size_t longitud = cadena_longitud(destino, capacidad);
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
- **Ubicación:** `cadenas.c:86`
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
- **Ubicación:** `cadenas.c:112`
```c
    size_t posicion = 0;
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
- **Ubicación:** `cadenas.c:150`
```c
    size_t longitud = cadena_longitud(origen, capacidad_max);
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
- **Ubicación:** `cadenas.c:177`
```c
    size_t longitud_primera = cadena_longitud(primera, cap_primera);
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
- **Ubicación:** `cadenas.c:231`
```c
    size_t extraidos = 0;
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
- **Ubicación:** `cadenas.c:265`
```c
    size_t longitud = cadena_longitud(origen, capacidad_max);
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
    char *subcadena = cadena_subcadena_dinamica("Hola Mundo", 30, 0, 4);
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
- **Ubicación:** `prueba.c:69`
```c
    char *invertida = cadena_invertir_dinamica("Hola Mundo", 30);
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
- **Ubicación:** `prueba.c:59`
```c
    int primero[] = {10, 20, 30};
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
- **Ubicación:** `prueba.c:113`
```c
    int *bloque_existente = crear_bloque_enteros(3);
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
- **Ubicación:** `vector.c:16`
```c
    int *bloque = calloc(cantidad, sizeof(int));
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
- **Ubicación:** `vector.c:47`
```c
    int *temp = realloc(bloque, nueva_cantidad * sizeof(int));
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
- **Ubicación:** `vector.c:64`
```c
    int *total = malloc((cant_primero + cant_segundo) * sizeof(int));
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

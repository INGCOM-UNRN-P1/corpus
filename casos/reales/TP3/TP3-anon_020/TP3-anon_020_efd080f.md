# Informe de Corrección — TP3 (efd080f)

## Repositorio
**branch/revision:** `main` `efd080f`
**Commit SHA:** `efd080f24edec142e56dc76040eaa73939d09c60`
**Autor:** `anon_020`
**Fecha del commit:** `2026-09-23 20:22:52 -0300`
**Mensaje:** `Todos los ejercicios completos`
**Fecha de evaluación:** 2026-09-28 10:33:39
**Versión revisada:** `efd080f`

## Especificación de la Guía
**Guía vinculada:** `Trabajo Práctico 3: Punteros y Aritmética de Punteros`
**Ejercicios requeridos:** `libpunteros (Biblioteca de Punteros (libpunteros))`, `ejercicio1 (Ordenamiento de Pares, Tríos y Acumulación)`, `ejercicio2 (Estadísticas, Promedio y Rango con Punteros)`, `ejercicio3 (Copia e Inversión In-Place con Punteros)`, `ejercicio4 (Búsqueda con Retorno de Puntero y Distancia)`, `ejercicio5 (Copia y Concatenación de Cadenas con Punteros)`, `ejercicio6 (Ordenamiento por Selección con Aritmética de Punteros)`

### Archivos contenidos
```text
.
├── ejercicios/
│   ├── ejercicio1/
│   │   ├── intercambio.c
│   │   ├── intercambio.h
│   │   ├── intercambio.o
│   │   ├── main.c
│   │   ├── main.o
│   │   ├── Makefile
│   │   ├── programa
│   │   ├── prueba.c
│   │   ├── prueba.o
│   │   └── test_bin
│   ├── ejercicio2/
│   │   ├── estadistica.c
│   │   ├── estadistica.h
│   │   ├── estadistica.o
│   │   ├── main.c
│   │   ├── main.o
│   │   ├── Makefile
│   │   ├── programa
│   │   ├── prueba.c
│   │   ├── prueba.o
│   │   └── test_bin
│   ├── ejercicio3/
│   │   ├── main.c
│   │   ├── main.o
│   │   ├── Makefile
│   │   ├── programa
│   │   ├── prueba.c
│   │   ├── prueba.o
│   │   ├── recorrido.c
│   │   ├── recorrido.h
│   │   ├── recorrido.o
│   │   └── test_bin
│   ├── ejercicio4/
│   │   ├── busqueda.c
│   │   ├── busqueda.h
│   │   ├── busqueda.o
│   │   ├── main.c
│   │   ├── main.o
│   │   ├── Makefile
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
│   │   ├── puntero_cadena.c
│   │   ├── puntero_cadena.h
│   │   ├── puntero_cadena.o
│   │   └── test_bin
│   └── ejercicio6/
│       ├── main.c
│       ├── main.o
│       ├── Makefile
│       ├── ordenamiento.c
│       ├── ordenamiento.h
│       ├── ordenamiento.o
│       ├── programa
│       ├── prueba.c
│       ├── prueba.o
│       └── test_bin
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
│   └── punteros/
│       ├── libpunteros.a
│       ├── Makefile
│       ├── prueba.c
│       ├── prueba.o
│       ├── punteros.c
│       ├── punteros.h
│       ├── punteros.o
│       └── test_bin
├── Makefile
├── README.md
└── tp.sh
```

## Análisis de Código C e Informes de Herramientas

## Resumen de Evaluación por Archivo

| Archivo | Estado Compilación | Evaluación de Estilo | Valgrind (Fugas) | Observaciones Cátedra |
| :--- | :---: | :---: | :---: | :--- |
| `[ARCHIVOS_BINARIOS]` | ❌ ERROR (39 filtrados) | 0.0/10 | — | Se detectaron binarios prohibidos (.o/.exe) en la entrega |
| `busqueda.c` | ✓ Compilación OK | 9.0/10 | ✓ Limpio (0 fugas) | 6 advertencias |
| `busqueda.h` | ✓ Compilación OK | 9.0/10 | ✓ Limpio (0 fugas) | 2 advertencias |
| `ejercicios/ejercicio1/intercambio.o` | ✓ Compilación OK | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `ejercicios/ejercicio1/main.o` | ✓ Compilación OK | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `ejercicios/ejercicio1/programa` | ✓ Compilación OK | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `ejercicios/ejercicio1/prueba.o` | ✓ Compilación OK | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `ejercicios/ejercicio1/test_bin` | ✓ Compilación OK | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `ejercicios/ejercicio2/estadistica.o` | ✓ Compilación OK | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `ejercicios/ejercicio2/main.o` | ✓ Compilación OK | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `ejercicios/ejercicio2/programa` | ✓ Compilación OK | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `ejercicios/ejercicio2/prueba.o` | ✓ Compilación OK | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `ejercicios/ejercicio2/test_bin` | ✓ Compilación OK | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `ejercicios/ejercicio3/main.o` | ✓ Compilación OK | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `ejercicios/ejercicio3/programa` | ✓ Compilación OK | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `ejercicios/ejercicio3/prueba.o` | ✓ Compilación OK | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `ejercicios/ejercicio3/recorrido.o` | ✓ Compilación OK | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `ejercicios/ejercicio3/test_bin` | ✓ Compilación OK | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `ejercicios/ejercicio4/busqueda.o` | ✓ Compilación OK | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `ejercicios/ejercicio4/main.o` | ✓ Compilación OK | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `ejercicios/ejercicio4/programa` | ✓ Compilación OK | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `ejercicios/ejercicio4/prueba.o` | ✓ Compilación OK | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `ejercicios/ejercicio4/test_bin` | ✓ Compilación OK | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `ejercicios/ejercicio5/main.o` | ✓ Compilación OK | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `ejercicios/ejercicio5/programa` | ✓ Compilación OK | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `ejercicios/ejercicio5/prueba.o` | ✓ Compilación OK | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `ejercicios/ejercicio5/puntero_cadena.o` | ✓ Compilación OK | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `ejercicios/ejercicio5/test_bin` | ✓ Compilación OK | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `ejercicios/ejercicio6/main.o` | ✓ Compilación OK | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `ejercicios/ejercicio6/ordenamiento.o` | ✓ Compilación OK | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `ejercicios/ejercicio6/programa` | ✓ Compilación OK | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `ejercicios/ejercicio6/prueba.o` | ✓ Compilación OK | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `ejercicios/ejercicio6/test_bin` | ✓ Compilación OK | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `estadistica.c` | ✓ Compilación OK | 9.0/10 | ✓ Limpio (0 fugas) | 12 advertencias |
| `intercambio.c` | ✓ Compilación OK | 8.0/10 | ✓ Limpio (0 fugas) | 11 advertencias |
| `intercambio.h` | ✓ Compilación OK | 8.0/10 | ✓ Limpio (0 fugas) | 4 advertencias |
| `libs/p1_test/build/libp1_test.a` | ✓ Compilación OK | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `libs/p1_test/build/p1_test.o` | ✓ Compilación OK | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `libs/p1_test/libp1_test.a` | ✓ Compilación OK | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `libs/p1_test/prueba.o` | ✓ Compilación OK | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `libs/p1_test/test_bin` | ✓ Compilación OK | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `libs/punteros/libpunteros.a` | ✓ Compilación OK | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `libs/punteros/prueba.o` | ✓ Compilación OK | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `libs/punteros/punteros.o` | ✓ Compilación OK | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `libs/punteros/test_bin` | ✓ Compilación OK | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `main.c` | ✓ Compilación OK | 8.5/10 | ✓ Limpio (0 fugas) | 25 advertencias |
| `ordenamiento.c` | ✓ Compilación OK | 8.5/10 | ✓ Limpio (0 fugas) | 7 advertencias |
| `ordenamiento.h` | ✓ Compilación OK | 9.5/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `prueba.c` | ✓ Compilación OK | 0.0/10 | ✓ Limpio (0 fugas) | 81 advertencias |
| `puntero_cadena.c` | ✓ Compilación OK | 8.5/10 | ✓ Limpio (0 fugas) | 9 advertencias |
| `puntero_cadena.h` | ✓ Compilación OK | 9.5/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `punteros.c` | ✓ Compilación OK | 8.5/10 | ✓ Limpio (0 fugas) | 14 advertencias |
| `punteros.h` | ✓ Compilación OK | 8.0/10 | ✓ Limpio (0 fugas) | 4 advertencias |
| `recorrido.c` | ✓ Compilación OK | 8.5/10 | ✓ Limpio (0 fugas) | 7 advertencias |

## ⚠️ Archivos Binarios Prohibidos Filtrados

> ❌ **ERROR DE ENTREGA:** Se detectaron archivos binarios precompilados o ejecutables en la entrega del estudiante. 
> Para mantener la reproducibilidad académica y evitar la ejecución de código no compilado desde fuentes, estos archivos fueron **filtrados y descartados** de la evaluación.

| Archivo Binario | Regla | Severidad | Detalle del Error | Sugerencia |
| :--- | :---: | :---: | :--- | :--- |
| `libs/p1_test/libp1_test.a` | `0x000Fh` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'libs/p1_test/libp1_test.a' (Extensión binaria prohibida '.a'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `libs/p1_test/prueba.o` | `0x000Fh` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'libs/p1_test/prueba.o' (Extensión binaria prohibida '.o'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `libs/p1_test/test_bin` | `0x000Fh` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'libs/p1_test/test_bin' (Firma binaria ejecutable detectada (Formato ejecutable o archivo objeto Linux ELF)). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `libs/punteros/punteros.o` | `0x000Fh` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'libs/punteros/punteros.o' (Extensión binaria prohibida '.o'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `libs/punteros/libpunteros.a` | `0x000Fh` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'libs/punteros/libpunteros.a' (Extensión binaria prohibida '.a'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `libs/punteros/prueba.o` | `0x000Fh` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'libs/punteros/prueba.o' (Extensión binaria prohibida '.o'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `libs/punteros/test_bin` | `0x000Fh` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'libs/punteros/test_bin' (Firma binaria ejecutable detectada (Formato ejecutable o archivo objeto Linux ELF)). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `libs/p1_test/build/p1_test.o` | `0x000Fh` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'libs/p1_test/build/p1_test.o' (Extensión binaria prohibida '.o'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `libs/p1_test/build/libp1_test.a` | `0x000Fh` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'libs/p1_test/build/libp1_test.a' (Extensión binaria prohibida '.a'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `ejercicios/ejercicio1/main.o` | `0x000Fh` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'ejercicios/ejercicio1/main.o' (Extensión binaria prohibida '.o'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `ejercicios/ejercicio1/intercambio.o` | `0x000Fh` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'ejercicios/ejercicio1/intercambio.o' (Extensión binaria prohibida '.o'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `ejercicios/ejercicio1/programa` | `0x000Fh` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'ejercicios/ejercicio1/programa' (Firma binaria ejecutable detectada (Formato ejecutable o archivo objeto Linux ELF)). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `ejercicios/ejercicio1/prueba.o` | `0x000Fh` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'ejercicios/ejercicio1/prueba.o' (Extensión binaria prohibida '.o'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `ejercicios/ejercicio1/test_bin` | `0x000Fh` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'ejercicios/ejercicio1/test_bin' (Firma binaria ejecutable detectada (Formato ejecutable o archivo objeto Linux ELF)). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `ejercicios/ejercicio2/main.o` | `0x000Fh` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'ejercicios/ejercicio2/main.o' (Extensión binaria prohibida '.o'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `ejercicios/ejercicio2/estadistica.o` | `0x000Fh` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'ejercicios/ejercicio2/estadistica.o' (Extensión binaria prohibida '.o'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `ejercicios/ejercicio2/programa` | `0x000Fh` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'ejercicios/ejercicio2/programa' (Firma binaria ejecutable detectada (Formato ejecutable o archivo objeto Linux ELF)). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `ejercicios/ejercicio2/prueba.o` | `0x000Fh` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'ejercicios/ejercicio2/prueba.o' (Extensión binaria prohibida '.o'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `ejercicios/ejercicio2/test_bin` | `0x000Fh` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'ejercicios/ejercicio2/test_bin' (Firma binaria ejecutable detectada (Formato ejecutable o archivo objeto Linux ELF)). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `ejercicios/ejercicio3/main.o` | `0x000Fh` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'ejercicios/ejercicio3/main.o' (Extensión binaria prohibida '.o'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `ejercicios/ejercicio3/recorrido.o` | `0x000Fh` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'ejercicios/ejercicio3/recorrido.o' (Extensión binaria prohibida '.o'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `ejercicios/ejercicio3/programa` | `0x000Fh` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'ejercicios/ejercicio3/programa' (Firma binaria ejecutable detectada (Formato ejecutable o archivo objeto Linux ELF)). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `ejercicios/ejercicio3/prueba.o` | `0x000Fh` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'ejercicios/ejercicio3/prueba.o' (Extensión binaria prohibida '.o'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `ejercicios/ejercicio3/test_bin` | `0x000Fh` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'ejercicios/ejercicio3/test_bin' (Firma binaria ejecutable detectada (Formato ejecutable o archivo objeto Linux ELF)). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `ejercicios/ejercicio4/main.o` | `0x000Fh` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'ejercicios/ejercicio4/main.o' (Extensión binaria prohibida '.o'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `ejercicios/ejercicio4/busqueda.o` | `0x000Fh` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'ejercicios/ejercicio4/busqueda.o' (Extensión binaria prohibida '.o'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `ejercicios/ejercicio4/programa` | `0x000Fh` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'ejercicios/ejercicio4/programa' (Firma binaria ejecutable detectada (Formato ejecutable o archivo objeto Linux ELF)). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `ejercicios/ejercicio4/prueba.o` | `0x000Fh` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'ejercicios/ejercicio4/prueba.o' (Extensión binaria prohibida '.o'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `ejercicios/ejercicio4/test_bin` | `0x000Fh` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'ejercicios/ejercicio4/test_bin' (Firma binaria ejecutable detectada (Formato ejecutable o archivo objeto Linux ELF)). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `ejercicios/ejercicio5/main.o` | `0x000Fh` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'ejercicios/ejercicio5/main.o' (Extensión binaria prohibida '.o'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `ejercicios/ejercicio5/puntero_cadena.o` | `0x000Fh` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'ejercicios/ejercicio5/puntero_cadena.o' (Extensión binaria prohibida '.o'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `ejercicios/ejercicio5/programa` | `0x000Fh` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'ejercicios/ejercicio5/programa' (Firma binaria ejecutable detectada (Formato ejecutable o archivo objeto Linux ELF)). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `ejercicios/ejercicio5/prueba.o` | `0x000Fh` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'ejercicios/ejercicio5/prueba.o' (Extensión binaria prohibida '.o'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `ejercicios/ejercicio5/test_bin` | `0x000Fh` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'ejercicios/ejercicio5/test_bin' (Firma binaria ejecutable detectada (Formato ejecutable o archivo objeto Linux ELF)). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `ejercicios/ejercicio6/main.o` | `0x000Fh` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'ejercicios/ejercicio6/main.o' (Extensión binaria prohibida '.o'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `ejercicios/ejercicio6/ordenamiento.o` | `0x000Fh` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'ejercicios/ejercicio6/ordenamiento.o' (Extensión binaria prohibida '.o'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `ejercicios/ejercicio6/programa` | `0x000Fh` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'ejercicios/ejercicio6/programa' (Firma binaria ejecutable detectada (Formato ejecutable o archivo objeto Linux ELF)). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `ejercicios/ejercicio6/prueba.o` | `0x000Fh` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'ejercicios/ejercicio6/prueba.o' (Extensión binaria prohibida '.o'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `ejercicios/ejercicio6/test_bin` | `0x000Fh` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'ejercicios/ejercicio6/test_bin' (Firma binaria ejecutable detectada (Formato ejecutable o archivo objeto Linux ELF)). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |

**Acción Requerida:** Las entregas deben contener exclusivamente código fuente editable (`.c`, `.h`), archivos de configuración (`Makefile`) y documentación (`.md`, `.txt`). Ejecutá `make clean` antes de comprimir tu entrega y verificá tu archivo `.gitignore`.

## Compilación — Makefile raíz del Proyecto

✓ **Estado:** Compilación exitosa ejecutando el Makefile en la raíz (`make`).

> 📄 **Salida completa:** registrada en `compilacion_efd080f.log`.

## Observaciones de Calidad y Reglas P1 (Linter AST / Ripley)

Se detectaron **93** observación(es) en el código C:

| Regla | Ubicación | Severidad | Observación | Sugerencia |
| :--- | :--- | :---: | :--- | :--- |
| `0x0004h` | `intercambio.c:1` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `intercambio.c:3` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `intercambio.c:15` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `intercambio.c:33` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `main.c:1` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:21` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:23` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:26` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:1` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `prueba.c:13` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `prueba.c:20` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:27` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:34` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:42` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:50` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:57` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:64` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:71` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `prueba.c:95` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `prueba.c:95` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0xEEEEh` | `estadistica.c:13` | ESTILO | Indentación no es múltiplo de 4 espacios (26 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `estadistica.c:45` | ESTILO | Indentación no es múltiplo de 4 espacios (21 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0x0004h` | `estadistica.c:1` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `estadistica.c:6` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0002h` | `estadistica.c:12` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0002h` | `estadistica.c:44` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0002h` | `estadistica.c:45` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `estadistica.c:58` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0xEEEEh` | `main.c:47` | ESTILO | Indentación no es múltiplo de 4 espacios (15 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0x0004h` | `main.c:1` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:23` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:43` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:46` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:1` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `prueba.c:11` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0002h` | `prueba.c:12` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0002h` | `prueba.c:57` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `prueba.c:57` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:1` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:18` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:1` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `prueba.c:50` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `prueba.c:50` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `recorrido.c:1` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `recorrido.c:3` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `busqueda.c:1` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `busqueda.c:8` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `busqueda.c:20` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:1` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:20` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:33` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:1` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:36` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:37` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `prueba.c:40` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `prueba.c:40` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:1` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:17` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:20` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:32` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:1` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `prueba.c:49` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `prueba.c:49` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `puntero_cadena.c:1` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `puntero_cadena.c:8` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `puntero_cadena.c:19` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `puntero_cadena.c:31` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `puntero_cadena.c:40` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `puntero_cadena.c:52` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:1` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:17` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `ordenamiento.c:1` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `ordenamiento.c:20` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:1` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `prueba.c:41` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `prueba.c:41` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:1` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:17` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:24` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:26` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:30` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:37` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:49` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `prueba.c:70` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `prueba.c:70` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0xEEEEh` | `punteros.c:29` | ESTILO | Indentación no es múltiplo de 4 espacios (21 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0x0004h` | `punteros.c:1` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `punteros.c:9` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0002h` | `punteros.c:28` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `punteros.c:43` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `punteros.c:47` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `punteros.c:70` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `punteros.c:89` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |

## Pruebas del Proyecto — Makefile raíz (`make test`)

✓ **Estado:** Pruebas del proyecto aprobadas con éxito (`make test`).

## Auditoría de Memoria Dinámica — Valgrind

✓ **Estado:** No se detectaron fugas de memoria durante las pruebas en sandbox.

## Linter de Estilo y Formato — Gaff

⚠️ Se detectaron **62** observación(es) de estilo arquitectónico:

| Regla | Ubicación | Observación | Sugerencia | Autofix |
| :--- | :--- | :--- | :--- | :---: |
| `GAFF009` | `intercambio.c:3` | La línea tiene 84 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `0x0001h` | `intercambio.c:21` | Identificador de variable no descriptivo de una sola letra 'b'. | Los nombres de variables deben reflejar con precisión su propósito (salvo índices canónicos i, j, k, n, x, y, z, f, c, r). | No |
| `0x0001h` | `intercambio.c:21` | Identificador de variable no descriptivo de una sola letra 'a'. | Los nombres de variables deben reflejar con precisión su propósito (salvo índices canónicos i, j, k, n, x, y, z, f, c, r). | No |
| `0x0001h` | `intercambio.c:42` | Identificador corto y poco expresivo 'fin' (3 caracteres). | Se recomienda utilizar identificadores más descriptivos del dominio del problema. | No |
| `GAFF009` | `intercambio.h:11` | La línea tiene 82 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `intercambio.h:12` | La línea tiene 83 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `0x0001h` | `intercambio.h:29` | Identificador de variable no descriptivo de una sola letra 'a'. | Los nombres de variables deben reflejar con precisión su propósito (salvo índices canónicos i, j, k, n, x, y, z, f, c, r). | No |
| `0x0001h` | `intercambio.h:29` | Identificador de variable no descriptivo de una sola letra 'b'. | Los nombres de variables deben reflejar con precisión su propósito (salvo índices canónicos i, j, k, n, x, y, z, f, c, r). | No |
| `0x0001h` | `main.c:12` | Identificador de variable no descriptivo de una sola letra 'a'. | Los nombres de variables deben reflejar con precisión su propósito (salvo índices canónicos i, j, k, n, x, y, z, f, c, r). | No |
| `0x0001h` | `main.c:13` | Identificador de variable no descriptivo de una sola letra 'b'. | Los nombres de variables deben reflejar con precisión su propósito (salvo índices canónicos i, j, k, n, x, y, z, f, c, r). | No |
| `GAFF009` | `prueba.c:97` | La línea tiene 106 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `0x0001h` | `prueba.c:12` | Identificador de variable no descriptivo de una sola letra 'b'. | Los nombres de variables deben reflejar con precisión su propósito (salvo índices canónicos i, j, k, n, x, y, z, f, c, r). | No |
| `0x0001h` | `prueba.c:12` | Identificador de variable no descriptivo de una sola letra 'a'. | Los nombres de variables deben reflejar con precisión su propósito (salvo índices canónicos i, j, k, n, x, y, z, f, c, r). | No |
| `0x0001h` | `prueba.c:32` | Identificador corto y poco expresivo 'id1' (3 caracteres). | Se recomienda utilizar identificadores más descriptivos del dominio del problema. | No |
| `0x0001h` | `prueba.c:33` | Identificador corto y poco expresivo 'id2' (3 caracteres). | Se recomienda utilizar identificadores más descriptivos del dominio del problema. | No |
| `0x0001h` | `prueba.c:39` | Identificador corto y poco expresivo 'val' (3 caracteres). | Se recomienda utilizar identificadores más descriptivos del dominio del problema. | No |
| `0x0001h` | `prueba.c:49` | Identificador de variable no descriptivo de una sola letra 'b'. | Los nombres de variables deben reflejar con precisión su propósito (salvo índices canónicos i, j, k, n, x, y, z, f, c, r). | No |
| `0x0001h` | `prueba.c:49` | Identificador de variable no descriptivo de una sola letra 'a'. | Los nombres de variables deben reflejar con precisión su propósito (salvo índices canónicos i, j, k, n, x, y, z, f, c, r). | No |
| `0x0001h` | `prueba.c:63` | Identificador de variable no descriptivo de una sola letra 'e'. | Los nombres de variables deben reflejar con precisión su propósito (salvo índices canónicos i, j, k, n, x, y, z, f, c, r). | No |
| `0x0001h` | `prueba.c:63` | Identificador de variable no descriptivo de una sola letra 'd'. | Los nombres de variables deben reflejar con precisión su propósito (salvo índices canónicos i, j, k, n, x, y, z, f, c, r). | No |
| `0x0001h` | `prueba.c:70` | Identificador corto y poco expresivo 'v2' (2 caracteres). | Se recomienda utilizar identificadores más descriptivos del dominio del problema. | No |
| `0x0001h` | `prueba.c:70` | Identificador corto y poco expresivo 'v1' (2 caracteres). | Se recomienda utilizar identificadores más descriptivos del dominio del problema. | No |
| `0x0001h` | `estadistica.c:25` | Identificador corto y poco expresivo 'fin' (3 caracteres). | Se recomienda utilizar identificadores más descriptivos del dominio del problema. | No |
| `0x0001h` | `estadistica.c:54` | Identificador corto y poco expresivo 'fin' (3 caracteres). | Se recomienda utilizar identificadores más descriptivos del dominio del problema. | No |
| `GAFF009` | `main.c:44` | La línea tiene 81 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `prueba.c:10` | La línea tiene 91 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `prueba.c:11` | La línea tiene 108 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `prueba.c:12` | La línea tiene 113 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `prueba.c:32` | La línea tiene 85 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `prueba.c:33` | La línea tiene 81 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `prueba.c:34` | La línea tiene 81 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `prueba.c:59` | La línea tiene 99 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `prueba.c:52` | La línea tiene 84 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `recorrido.c:3` | La línea tiene 84 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `0x0001h` | `recorrido.c:16` | Identificador corto y poco expresivo 'fin' (3 caracteres). | Se recomienda utilizar identificadores más descriptivos del dominio del problema. | No |
| `0x0001h` | `recorrido.c:37` | Identificador corto y poco expresivo 'fin' (3 caracteres). | Se recomienda utilizar identificadores más descriptivos del dominio del problema. | No |
| `GAFF009` | `busqueda.c:3` | La línea tiene 87 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `0x0001h` | `busqueda.c:16` | Identificador corto y poco expresivo 'fin' (3 caracteres). | Se recomienda utilizar identificadores más descriptivos del dominio del problema. | No |
| `GAFF009` | `busqueda.h:14` | La línea tiene 81 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `busqueda.h:20` | La línea tiene 84 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `prueba.c:42` | La línea tiene 84 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `prueba.c:51` | La línea tiene 84 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `puntero_cadena.c:31` | La línea tiene 81 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `puntero_cadena.c:40` | La línea tiene 88 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `puntero_cadena.c:52` | La línea tiene 88 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `puntero_cadena.h:29` | La línea tiene 82 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `ordenamiento.c:3` | La línea tiene 88 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `0x0001h` | `ordenamiento.c:8` | Identificador corto y poco expresivo 'fin' (3 caracteres). | Se recomienda utilizar identificadores más descriptivos del dominio del problema. | No |
| `0x0001h` | `ordenamiento.c:43` | Identificador corto y poco expresivo 'fin' (3 caracteres). | Se recomienda utilizar identificadores más descriptivos del dominio del problema. | No |
| `0x0001h` | `ordenamiento.h:16` | Identificador corto y poco expresivo 'fin' (3 caracteres). | Se recomienda utilizar identificadores más descriptivos del dominio del problema. | No |
| `GAFF009` | `prueba.c:43` | La línea tiene 84 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `prueba.c:72` | La línea tiene 84 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `0x0001h` | `prueba.c:22` | Identificador de variable no descriptivo de una sola letra 'a'. | Los nombres de variables deben reflejar con precisión su propósito (salvo índices canónicos i, j, k, n, x, y, z, f, c, r). | No |
| `0x0001h` | `prueba.c:23` | Identificador de variable no descriptivo de una sola letra 'b'. | Los nombres de variables deben reflejar con precisión su propósito (salvo índices canónicos i, j, k, n, x, y, z, f, c, r). | No |
| `0x0001h` | `prueba.c:34` | Identificador corto y poco expresivo 'val' (3 caracteres). | Se recomienda utilizar identificadores más descriptivos del dominio del problema. | No |
| `0x0001h` | `punteros.c:37` | Identificador corto y poco expresivo 'fin' (3 caracteres). | Se recomienda utilizar identificadores más descriptivos del dominio del problema. | No |
| `0x0001h` | `punteros.c:66` | Identificador corto y poco expresivo 'fin' (3 caracteres). | Se recomienda utilizar identificadores más descriptivos del dominio del problema. | No |
| `0x0001h` | `punteros.c:84` | Identificador corto y poco expresivo 'fin' (3 caracteres). | Se recomienda utilizar identificadores más descriptivos del dominio del problema. | No |
| `GAFF009` | `punteros.h:3` | La línea tiene 88 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `punteros.h:17` | La línea tiene 88 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `punteros.h:62` | La línea tiene 85 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `punteros.h:76` | La línea tiene 85 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |

## Auditoría de Seguridad — Sandbox / Kaneda

⚠️ **Alerta:** Se detectaron **39** llamadas o patrones de riesgo de seguridad:

| Regla | Archivo:Línea | Severidad | Detalle | Sugerencia |
| :--- | :--- | :---: | :--- | :--- |
| `0x000Fh` | `libs/p1_test/libp1_test.a:1` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'libs/p1_test/libp1_test.a' (Extensión binaria prohibida '.a'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `0x000Fh` | `libs/p1_test/prueba.o:1` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'libs/p1_test/prueba.o' (Extensión binaria prohibida '.o'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `0x000Fh` | `libs/p1_test/test_bin:1` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'libs/p1_test/test_bin' (Firma binaria ejecutable detectada (Formato ejecutable o archivo objeto Linux ELF)). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `0x000Fh` | `libs/punteros/punteros.o:1` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'libs/punteros/punteros.o' (Extensión binaria prohibida '.o'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `0x000Fh` | `libs/punteros/libpunteros.a:1` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'libs/punteros/libpunteros.a' (Extensión binaria prohibida '.a'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `0x000Fh` | `libs/punteros/prueba.o:1` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'libs/punteros/prueba.o' (Extensión binaria prohibida '.o'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `0x000Fh` | `libs/punteros/test_bin:1` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'libs/punteros/test_bin' (Firma binaria ejecutable detectada (Formato ejecutable o archivo objeto Linux ELF)). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `0x000Fh` | `libs/p1_test/build/p1_test.o:1` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'libs/p1_test/build/p1_test.o' (Extensión binaria prohibida '.o'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `0x000Fh` | `libs/p1_test/build/libp1_test.a:1` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'libs/p1_test/build/libp1_test.a' (Extensión binaria prohibida '.a'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `0x000Fh` | `ejercicios/ejercicio1/main.o:1` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'ejercicios/ejercicio1/main.o' (Extensión binaria prohibida '.o'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `0x000Fh` | `ejercicios/ejercicio1/intercambio.o:1` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'ejercicios/ejercicio1/intercambio.o' (Extensión binaria prohibida '.o'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `0x000Fh` | `ejercicios/ejercicio1/programa:1` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'ejercicios/ejercicio1/programa' (Firma binaria ejecutable detectada (Formato ejecutable o archivo objeto Linux ELF)). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `0x000Fh` | `ejercicios/ejercicio1/prueba.o:1` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'ejercicios/ejercicio1/prueba.o' (Extensión binaria prohibida '.o'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `0x000Fh` | `ejercicios/ejercicio1/test_bin:1` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'ejercicios/ejercicio1/test_bin' (Firma binaria ejecutable detectada (Formato ejecutable o archivo objeto Linux ELF)). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `0x000Fh` | `ejercicios/ejercicio2/main.o:1` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'ejercicios/ejercicio2/main.o' (Extensión binaria prohibida '.o'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `0x000Fh` | `ejercicios/ejercicio2/estadistica.o:1` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'ejercicios/ejercicio2/estadistica.o' (Extensión binaria prohibida '.o'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `0x000Fh` | `ejercicios/ejercicio2/programa:1` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'ejercicios/ejercicio2/programa' (Firma binaria ejecutable detectada (Formato ejecutable o archivo objeto Linux ELF)). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `0x000Fh` | `ejercicios/ejercicio2/prueba.o:1` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'ejercicios/ejercicio2/prueba.o' (Extensión binaria prohibida '.o'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `0x000Fh` | `ejercicios/ejercicio2/test_bin:1` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'ejercicios/ejercicio2/test_bin' (Firma binaria ejecutable detectada (Formato ejecutable o archivo objeto Linux ELF)). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `0x000Fh` | `ejercicios/ejercicio3/main.o:1` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'ejercicios/ejercicio3/main.o' (Extensión binaria prohibida '.o'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `0x000Fh` | `ejercicios/ejercicio3/recorrido.o:1` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'ejercicios/ejercicio3/recorrido.o' (Extensión binaria prohibida '.o'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `0x000Fh` | `ejercicios/ejercicio3/programa:1` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'ejercicios/ejercicio3/programa' (Firma binaria ejecutable detectada (Formato ejecutable o archivo objeto Linux ELF)). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `0x000Fh` | `ejercicios/ejercicio3/prueba.o:1` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'ejercicios/ejercicio3/prueba.o' (Extensión binaria prohibida '.o'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `0x000Fh` | `ejercicios/ejercicio3/test_bin:1` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'ejercicios/ejercicio3/test_bin' (Firma binaria ejecutable detectada (Formato ejecutable o archivo objeto Linux ELF)). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `0x000Fh` | `ejercicios/ejercicio4/main.o:1` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'ejercicios/ejercicio4/main.o' (Extensión binaria prohibida '.o'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `0x000Fh` | `ejercicios/ejercicio4/busqueda.o:1` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'ejercicios/ejercicio4/busqueda.o' (Extensión binaria prohibida '.o'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `0x000Fh` | `ejercicios/ejercicio4/programa:1` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'ejercicios/ejercicio4/programa' (Firma binaria ejecutable detectada (Formato ejecutable o archivo objeto Linux ELF)). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `0x000Fh` | `ejercicios/ejercicio4/prueba.o:1` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'ejercicios/ejercicio4/prueba.o' (Extensión binaria prohibida '.o'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `0x000Fh` | `ejercicios/ejercicio4/test_bin:1` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'ejercicios/ejercicio4/test_bin' (Firma binaria ejecutable detectada (Formato ejecutable o archivo objeto Linux ELF)). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `0x000Fh` | `ejercicios/ejercicio5/main.o:1` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'ejercicios/ejercicio5/main.o' (Extensión binaria prohibida '.o'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `0x000Fh` | `ejercicios/ejercicio5/puntero_cadena.o:1` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'ejercicios/ejercicio5/puntero_cadena.o' (Extensión binaria prohibida '.o'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `0x000Fh` | `ejercicios/ejercicio5/programa:1` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'ejercicios/ejercicio5/programa' (Firma binaria ejecutable detectada (Formato ejecutable o archivo objeto Linux ELF)). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `0x000Fh` | `ejercicios/ejercicio5/prueba.o:1` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'ejercicios/ejercicio5/prueba.o' (Extensión binaria prohibida '.o'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `0x000Fh` | `ejercicios/ejercicio5/test_bin:1` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'ejercicios/ejercicio5/test_bin' (Firma binaria ejecutable detectada (Formato ejecutable o archivo objeto Linux ELF)). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `0x000Fh` | `ejercicios/ejercicio6/main.o:1` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'ejercicios/ejercicio6/main.o' (Extensión binaria prohibida '.o'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `0x000Fh` | `ejercicios/ejercicio6/ordenamiento.o:1` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'ejercicios/ejercicio6/ordenamiento.o' (Extensión binaria prohibida '.o'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `0x000Fh` | `ejercicios/ejercicio6/programa:1` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'ejercicios/ejercicio6/programa' (Firma binaria ejecutable detectada (Formato ejecutable o archivo objeto Linux ELF)). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `0x000Fh` | `ejercicios/ejercicio6/prueba.o:1` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'ejercicios/ejercicio6/prueba.o' (Extensión binaria prohibida '.o'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `0x000Fh` | `ejercicios/ejercicio6/test_bin:1` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'ejercicios/ejercicio6/test_bin' (Firma binaria ejecutable detectada (Formato ejecutable o archivo objeto Linux ELF)). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |

## Antipatrones Didácticos — Spunkmeyer

✓ **Estado:** No se detectaron antipatrones pedagógicos conocidos.

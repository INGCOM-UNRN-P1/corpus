# Informe de Corrección — TP2 (a8cb964)

## Repositorio
**branch/revision:** `main` `a8cb964`
**Commit SHA:** `a8cb96490d4ad7ee60a6a22fa44d3aa2f7916c82`
**Autor:** `anon_025`
**Fecha del commit:** `2026-09-15 23:22:17 -0300`
**Mensaje:** `TP2 completado: lib arreglos y lib cadenas pasaron los tests`
**Fecha de evaluación:** 2026-09-18 11:02:46
**Versión revisada:** `a8cb964`

## Especificación de la Guía
**Guía vinculada:** `Trabajo Práctico 2: Arreglos de Enteros y Cadenas Seguras`
**Ejercicios requeridos:** `libarreglos (Biblioteca de Arreglos de Enteros (libarreglos))`, `libcadenas (Biblioteca de Cadenas Seguras (libcadenas))`, `ejercicio1 (Aplicación de Estadísticas de Arreglos)`, `ejercicio2 (Procesador de Texto con Cadenas Seguras)`

### Archivos contenidos
```text
.
├── ejercicios/
│   ├── ejercicio1/
│   │   ├── main.c
│   │   ├── main.o
│   │   ├── Makefile
│   │   ├── operaciones.c
│   │   ├── operaciones.h
│   │   ├── operaciones.o
│   │   ├── programa
│   │   ├── prueba.c
│   │   ├── prueba.o
│   │   └── test_bin
│   └── ejercicio2/
│       ├── main.c
│       ├── main.o
│       ├── Makefile
│       ├── programa
│       ├── prueba.c
│       ├── prueba.o
│       ├── test_bin
│       ├── texto.c
│       ├── texto.h
│       └── texto.o
├── libs/
│   ├── arreglos/
│   │   ├── arreglo.h
│   │   ├── arreglos.c
│   │   ├── arreglos.h
│   │   ├── arreglos.o
│   │   ├── libarreglos.a
│   │   ├── Makefile
│   │   ├── prueba.c
│   │   ├── prueba.o
│   │   └── test_bin
│   ├── cadenas/
│   │   ├── cadena.h
│   │   ├── cadenas.c
│   │   ├── cadenas.h
│   │   ├── cadenas.o
│   │   ├── libcadenas.a
│   │   ├── Makefile
│   │   ├── prueba.c
│   │   ├── prueba.o
│   │   └── test_bin
│   └── p1_test/
│       ├── build/
│       │   ├── libp1_test.a
│       │   └── p1_test.o
│       ├── include/
│       │   ├── p1_arrays.h
│       │   ├── p1_files.h
│       │   ├── p1_stdio.h
│       │   └── p1_test.h
│       ├── src/
│       │   └── p1_test.c
│       ├── libp1_test.a
│       ├── library.json
│       ├── library.spec
│       ├── Makefile
│       ├── p1_arrays.h
│       ├── p1_files.h
│       ├── p1_stdio.h
│       ├── p1_test.h
│       ├── prueba.c
│       ├── prueba.o
│       └── test_bin
├── entorno.txt
├── Makefile
├── README.md
└── tp.sh
```

## Análisis de Código C e Informes de Herramientas

## Resumen de Evaluación por Archivo

| Archivo | Estado Compilación | Evaluación de Estilo | Valgrind (Fugas) | Observaciones Cátedra |
| :--- | :---: | :---: | :---: | :--- |
| `[ARCHIVOS_BINARIOS]` | ❌ ERROR (23 filtrados) | 0.0/10 | — | Se detectaron binarios prohibidos (.o/.exe) en la entrega |
| `arreglos.c` | ✓ Compilación OK | 8.5/10 | ✓ Limpio (0 fugas) | 10 advertencias |
| `arreglos.h` | ✓ Compilación OK | 6.5/10 | ✓ Limpio (0 fugas) | 7 advertencias |
| `cadenas.c` | ✓ Compilación OK | 9.0/10 | ✓ Limpio (0 fugas) | 9 advertencias |
| `cadenas.h` | ✓ Compilación OK | 8.0/10 | ✓ Limpio (0 fugas) | 4 advertencias |
| `ejercicios/ejercicio1/main.o` | ✓ Compilación OK | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `ejercicios/ejercicio1/operaciones.o` | ✓ Compilación OK | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `ejercicios/ejercicio1/programa` | ✓ Compilación OK | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `ejercicios/ejercicio1/prueba.o` | ✓ Compilación OK | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `ejercicios/ejercicio1/test_bin` | ✓ Compilación OK | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `ejercicios/ejercicio2/main.o` | ✓ Compilación OK | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `ejercicios/ejercicio2/programa` | ✓ Compilación OK | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `ejercicios/ejercicio2/prueba.o` | ✓ Compilación OK | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `ejercicios/ejercicio2/test_bin` | ✓ Compilación OK | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `ejercicios/ejercicio2/texto.o` | ✓ Compilación OK | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `libs/arreglos/arreglos.o` | ✓ Compilación OK | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `libs/arreglos/libarreglos.a` | ✓ Compilación OK | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `libs/arreglos/prueba.o` | ✓ Compilación OK | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `libs/arreglos/test_bin` | ✓ Compilación OK | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `libs/cadenas/cadenas.o` | ✓ Compilación OK | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `libs/cadenas/libcadenas.a` | ✓ Compilación OK | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `libs/cadenas/prueba.o` | ✓ Compilación OK | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `libs/cadenas/test_bin` | ✓ Compilación OK | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `libs/p1_test/build/libp1_test.a` | ✓ Compilación OK | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `libs/p1_test/build/p1_test.o` | ✓ Compilación OK | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `libs/p1_test/libp1_test.a` | ✓ Compilación OK | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `libs/p1_test/prueba.o` | ✓ Compilación OK | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `libs/p1_test/test_bin` | ✓ Compilación OK | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `main.c` | ✓ Compilación OK | 9.0/10 | ✓ Limpio (0 fugas) | 8 advertencias |
| `operaciones.c` | ✓ Compilación OK | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `prueba.c` | ✓ Compilación OK | 5.5/10 | ✓ Limpio (0 fugas) | 25 advertencias |

## ⚠️ Archivos Binarios Prohibidos Filtrados

> ❌ **ERROR DE ENTREGA:** Se detectaron archivos binarios precompilados o ejecutables en la entrega del estudiante. 
> Para mantener la reproducibilidad académica y evitar la ejecución de código no compilado desde fuentes, estos archivos fueron **filtrados y descartados** de la evaluación.

| Archivo Binario | Regla | Severidad | Detalle del Error | Sugerencia |
| :--- | :---: | :---: | :--- | :--- |
| `libs/arreglos/arreglos.o` | `0x000Fh` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'libs/arreglos/arreglos.o' (Extensión binaria prohibida '.o'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `libs/arreglos/libarreglos.a` | `0x000Fh` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'libs/arreglos/libarreglos.a' (Extensión binaria prohibida '.a'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `libs/arreglos/prueba.o` | `0x000Fh` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'libs/arreglos/prueba.o' (Extensión binaria prohibida '.o'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `libs/arreglos/test_bin` | `0x000Fh` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'libs/arreglos/test_bin' (Firma binaria ejecutable detectada (Formato ejecutable o archivo objeto Linux ELF)). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `libs/cadenas/cadenas.o` | `0x000Fh` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'libs/cadenas/cadenas.o' (Extensión binaria prohibida '.o'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `libs/cadenas/libcadenas.a` | `0x000Fh` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'libs/cadenas/libcadenas.a' (Extensión binaria prohibida '.a'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `libs/cadenas/prueba.o` | `0x000Fh` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'libs/cadenas/prueba.o' (Extensión binaria prohibida '.o'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `libs/cadenas/test_bin` | `0x000Fh` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'libs/cadenas/test_bin' (Firma binaria ejecutable detectada (Formato ejecutable o archivo objeto Linux ELF)). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `libs/p1_test/libp1_test.a` | `0x000Fh` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'libs/p1_test/libp1_test.a' (Extensión binaria prohibida '.a'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `libs/p1_test/prueba.o` | `0x000Fh` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'libs/p1_test/prueba.o' (Extensión binaria prohibida '.o'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `libs/p1_test/test_bin` | `0x000Fh` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'libs/p1_test/test_bin' (Firma binaria ejecutable detectada (Formato ejecutable o archivo objeto Linux ELF)). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `libs/p1_test/build/p1_test.o` | `0x000Fh` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'libs/p1_test/build/p1_test.o' (Extensión binaria prohibida '.o'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `libs/p1_test/build/libp1_test.a` | `0x000Fh` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'libs/p1_test/build/libp1_test.a' (Extensión binaria prohibida '.a'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `ejercicios/ejercicio1/main.o` | `0x000Fh` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'ejercicios/ejercicio1/main.o' (Extensión binaria prohibida '.o'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `ejercicios/ejercicio1/operaciones.o` | `0x000Fh` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'ejercicios/ejercicio1/operaciones.o' (Extensión binaria prohibida '.o'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `ejercicios/ejercicio1/programa` | `0x000Fh` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'ejercicios/ejercicio1/programa' (Firma binaria ejecutable detectada (Formato ejecutable o archivo objeto Linux ELF)). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `ejercicios/ejercicio1/prueba.o` | `0x000Fh` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'ejercicios/ejercicio1/prueba.o' (Extensión binaria prohibida '.o'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `ejercicios/ejercicio1/test_bin` | `0x000Fh` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'ejercicios/ejercicio1/test_bin' (Firma binaria ejecutable detectada (Formato ejecutable o archivo objeto Linux ELF)). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `ejercicios/ejercicio2/main.o` | `0x000Fh` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'ejercicios/ejercicio2/main.o' (Extensión binaria prohibida '.o'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `ejercicios/ejercicio2/texto.o` | `0x000Fh` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'ejercicios/ejercicio2/texto.o' (Extensión binaria prohibida '.o'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `ejercicios/ejercicio2/programa` | `0x000Fh` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'ejercicios/ejercicio2/programa' (Firma binaria ejecutable detectada (Formato ejecutable o archivo objeto Linux ELF)). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `ejercicios/ejercicio2/prueba.o` | `0x000Fh` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'ejercicios/ejercicio2/prueba.o' (Extensión binaria prohibida '.o'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `ejercicios/ejercicio2/test_bin` | `0x000Fh` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'ejercicios/ejercicio2/test_bin' (Firma binaria ejecutable detectada (Formato ejecutable o archivo objeto Linux ELF)). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |

**Acción Requerida:** Las entregas deben contener exclusivamente código fuente editable (`.c`, `.h`), archivos de configuración (`Makefile`) y documentación (`.md`, `.txt`). Ejecutá `make clean` antes de comprimir tu entrega y verificá tu archivo `.gitignore`.

## Compilación — Makefile raíz del Proyecto

✓ **Estado:** Compilación exitosa ejecutando el Makefile en la raíz (`make`).

> 📄 **Salida completa:** registrada en `compilacion_a8cb964.log`.

## Observaciones de Calidad y Reglas P1 (Linter AST / Ripley)

Se detectaron **35** observación(es) en el código C:

| Regla | Ubicación | Severidad | Observación | Sugerencia |
| :--- | :--- | :---: | :--- | :--- |
| `0x0004h` | `main.c:10` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:14` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:32` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `operaciones.c:14` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `prueba.c:1` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `prueba.c:27` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `prueba.c:27` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0xEEEEh` | `main.c:25` | ESTILO | Indentación no es múltiplo de 4 espacios (11 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0x0004h` | `main.c:9` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:24` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:1` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:15` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `prueba.c:26` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `prueba.c:26` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0xEEEEh` | `arreglos.c:123` | ESTILO | Indentación no es múltiplo de 4 espacios (1 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0x0004h` | `arreglos.c:1` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `arreglos.c:30` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `arreglos.c:50` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `arreglos.c:92` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0002h` | `arreglos.c:123` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `prueba.c:1` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:32` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:39` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `prueba.c:127` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `prueba.c:127` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `cadenas.c:1` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `cadenas.c:30` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0002h` | `cadenas.c:59` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `cadenas.c:94` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `cadenas.c:121` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `cadenas.c:149` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `cadenas.c:158` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:1` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `prueba.c:99` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `prueba.c:99` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |

## Pruebas del Proyecto — Makefile raíz (`make test`)

✓ **Estado:** Pruebas del proyecto aprobadas con éxito (`make test`).

## Auditoría de Memoria Dinámica — Valgrind

✓ **Estado:** No se detectaron fugas de memoria durante las pruebas en sandbox.

## Linter de Estilo y Formato — Gaff

⚠️ Se detectaron **27** observación(es) de estilo arquitectónico:

| Regla | Ubicación | Observación | Sugerencia | Autofix |
| :--- | :--- | :--- | :--- | :---: |
| `GAFF009` | `prueba.c:22` | La línea tiene 81 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `prueba.c:29` | La línea tiene 84 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `main.c:11` | La línea tiene 100 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `main.c:23` | La línea tiene 100 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `prueba.c:15` | La línea tiene 85 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `prueba.c:17` | La línea tiene 84 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `prueba.c:22` | La línea tiene 81 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `prueba.c:28` | La línea tiene 84 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `arreglos.c:72` | La línea tiene 87 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `arreglos.c:123` | La línea tiene 141 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `0x0001h` | `arreglos.c:58` | Identificador corto y poco expresivo 'fin' (3 caracteres). | Se recomienda utilizar identificadores más descriptivos del dominio del problema. | No |
| `GAFF009` | `arreglos.h:3` | La línea tiene 82 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `arreglos.h:11` | La línea tiene 90 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `arreglos.h:12` | La línea tiene 90 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `arreglos.h:13` | La línea tiene 87 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `arreglos.h:99` | La línea tiene 86 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `arreglos.h:122` | La línea tiene 144 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `arreglos.h:137` | La línea tiene 141 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `prueba.c:129` | La línea tiene 84 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `0x0001h` | `prueba.c:51` | Identificador corto y poco expresivo 'par' (3 caracteres). | Se recomienda utilizar identificadores más descriptivos del dominio del problema. | No |
| `GAFF009` | `cadenas.c:94` | La línea tiene 81 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `cadenas.c:121` | La línea tiene 108 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `cadenas.h:76` | La línea tiene 81 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `cadenas.h:95` | La línea tiene 81 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `cadenas.h:100` | La línea tiene 112 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `cadenas.h:115` | La línea tiene 109 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `prueba.c:101` | La línea tiene 83 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |

## Auditoría de Seguridad — Sandbox / Kaneda

⚠️ **Alerta:** Se detectaron **23** llamadas o patrones de riesgo de seguridad:

| Regla | Archivo:Línea | Severidad | Detalle | Sugerencia |
| :--- | :--- | :---: | :--- | :--- |
| `0x000Fh` | `libs/arreglos/arreglos.o:1` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'libs/arreglos/arreglos.o' (Extensión binaria prohibida '.o'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `0x000Fh` | `libs/arreglos/libarreglos.a:1` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'libs/arreglos/libarreglos.a' (Extensión binaria prohibida '.a'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `0x000Fh` | `libs/arreglos/prueba.o:1` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'libs/arreglos/prueba.o' (Extensión binaria prohibida '.o'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `0x000Fh` | `libs/arreglos/test_bin:1` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'libs/arreglos/test_bin' (Firma binaria ejecutable detectada (Formato ejecutable o archivo objeto Linux ELF)). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `0x000Fh` | `libs/cadenas/cadenas.o:1` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'libs/cadenas/cadenas.o' (Extensión binaria prohibida '.o'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `0x000Fh` | `libs/cadenas/libcadenas.a:1` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'libs/cadenas/libcadenas.a' (Extensión binaria prohibida '.a'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `0x000Fh` | `libs/cadenas/prueba.o:1` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'libs/cadenas/prueba.o' (Extensión binaria prohibida '.o'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `0x000Fh` | `libs/cadenas/test_bin:1` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'libs/cadenas/test_bin' (Firma binaria ejecutable detectada (Formato ejecutable o archivo objeto Linux ELF)). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `0x000Fh` | `libs/p1_test/libp1_test.a:1` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'libs/p1_test/libp1_test.a' (Extensión binaria prohibida '.a'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `0x000Fh` | `libs/p1_test/prueba.o:1` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'libs/p1_test/prueba.o' (Extensión binaria prohibida '.o'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `0x000Fh` | `libs/p1_test/test_bin:1` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'libs/p1_test/test_bin' (Firma binaria ejecutable detectada (Formato ejecutable o archivo objeto Linux ELF)). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `0x000Fh` | `libs/p1_test/build/p1_test.o:1` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'libs/p1_test/build/p1_test.o' (Extensión binaria prohibida '.o'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `0x000Fh` | `libs/p1_test/build/libp1_test.a:1` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'libs/p1_test/build/libp1_test.a' (Extensión binaria prohibida '.a'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `0x000Fh` | `ejercicios/ejercicio1/main.o:1` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'ejercicios/ejercicio1/main.o' (Extensión binaria prohibida '.o'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `0x000Fh` | `ejercicios/ejercicio1/operaciones.o:1` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'ejercicios/ejercicio1/operaciones.o' (Extensión binaria prohibida '.o'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `0x000Fh` | `ejercicios/ejercicio1/programa:1` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'ejercicios/ejercicio1/programa' (Firma binaria ejecutable detectada (Formato ejecutable o archivo objeto Linux ELF)). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `0x000Fh` | `ejercicios/ejercicio1/prueba.o:1` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'ejercicios/ejercicio1/prueba.o' (Extensión binaria prohibida '.o'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `0x000Fh` | `ejercicios/ejercicio1/test_bin:1` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'ejercicios/ejercicio1/test_bin' (Firma binaria ejecutable detectada (Formato ejecutable o archivo objeto Linux ELF)). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `0x000Fh` | `ejercicios/ejercicio2/main.o:1` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'ejercicios/ejercicio2/main.o' (Extensión binaria prohibida '.o'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `0x000Fh` | `ejercicios/ejercicio2/texto.o:1` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'ejercicios/ejercicio2/texto.o' (Extensión binaria prohibida '.o'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `0x000Fh` | `ejercicios/ejercicio2/programa:1` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'ejercicios/ejercicio2/programa' (Firma binaria ejecutable detectada (Formato ejecutable o archivo objeto Linux ELF)). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `0x000Fh` | `ejercicios/ejercicio2/prueba.o:1` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'ejercicios/ejercicio2/prueba.o' (Extensión binaria prohibida '.o'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `0x000Fh` | `ejercicios/ejercicio2/test_bin:1` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'ejercicios/ejercicio2/test_bin' (Firma binaria ejecutable detectada (Formato ejecutable o archivo objeto Linux ELF)). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |

## Antipatrones Didácticos — Spunkmeyer

✓ **Estado:** No se detectaron antipatrones pedagógicos conocidos.

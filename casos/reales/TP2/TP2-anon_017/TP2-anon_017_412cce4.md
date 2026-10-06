# Informe de Corrección — TP2 (412cce4)

## Repositorio
**branch/revision:** `main` `412cce4`
**Commit SHA:** `412cce47ab54e606732807a6b44975bed663c0d5`
**Autor:** `anon_017`
**Fecha del commit:** `2026-09-24 16:02:54 -0300`
**Mensaje:** `Se completa la libreria cadena`
**Fecha de evaluación:** 2026-09-28 10:38:06
**Versión revisada:** `412cce4`

## Especificación de la Guía
**Guía vinculada:** `Trabajo Práctico 2: Arreglos de Enteros y Cadenas Seguras`
**Ejercicios requeridos:** `libarreglos (Biblioteca de Arreglos de Enteros (libarreglos))`, `libcadenas (Biblioteca de Cadenas Seguras (libcadenas))`, `ejercicio1 (Aplicación de Estadísticas de Arreglos)`, `ejercicio2 (Procesador de Texto con Cadenas Seguras)`

### Archivos contenidos
```text
.
├── ejercicios/
│   ├── ejercicio1/
│   │   ├── main.c
│   │   ├── Makefile
│   │   ├── operaciones.c
│   │   ├── operaciones.h
│   │   └── prueba.c
│   └── ejercicio2/
│       ├── main.c
│       ├── Makefile
│       ├── prueba.c
│       ├── texto.c
│       └── texto.h
├── libs/
│   ├── arreglos/
│   │   ├── arreglos.c
│   │   ├── arreglos.h
│   │   ├── arreglos.o
│   │   ├── libarreglos.a
│   │   ├── Makefile
│   │   ├── prueba.c
│   │   ├── prueba.o
│   │   └── test_bin
│   ├── cadenas/
│   │   ├── cadenas.c
│   │   ├── cadenas.h
│   │   ├── Makefile
│   │   └── prueba.c
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
├── Makefile
├── README.md
└── tp.sh
```

## Análisis de Código C e Informes de Herramientas

## Resumen de Evaluación por Archivo

| Archivo | Estado Compilación | Evaluación de Estilo | Valgrind (Fugas) | Observaciones Cátedra |
| :--- | :---: | :---: | :---: | :--- |
| `[ARCHIVOS_BINARIOS]` | ❌ ERROR (9 filtrados) | 0.0/10 | — | Se detectaron binarios prohibidos (.o/.exe) en la entrega |
| `arreglos.c` | ✓ Compilación OK | 7.5/10 | ✓ Limpio (0 fugas) | 13 advertencias |
| `arreglos.h` | ✓ Compilación OK | 0.0/10 | ✓ Limpio (0 fugas) | 32 advertencias |
| `cadenas.c` | ✓ Compilación OK | 8.5/10 | ✓ Limpio (0 fugas) | 8 advertencias |
| `cadenas.h` | ✓ Compilación OK | 6.5/10 | ✓ Limpio (0 fugas) | 7 advertencias |
| `libs/arreglos/arreglos.o` | ✓ Compilación OK | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `libs/arreglos/libarreglos.a` | ✓ Compilación OK | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `libs/arreglos/prueba.o` | ✓ Compilación OK | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `libs/arreglos/test_bin` | ✓ Compilación OK | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `libs/p1_test/build/libp1_test.a` | ✓ Compilación OK | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `libs/p1_test/build/p1_test.o` | ✓ Compilación OK | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `libs/p1_test/libp1_test.a` | ✓ Compilación OK | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `libs/p1_test/prueba.o` | ✓ Compilación OK | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `libs/p1_test/test_bin` | ✓ Compilación OK | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `main.c` | ✓ Compilación OK | 9.0/10 | ✓ Limpio (0 fugas) | 8 advertencias |
| `operaciones.c` | ✓ Compilación OK | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `prueba.c` | ✓ Compilación OK | 3.0/10 | ✓ Limpio (0 fugas) | 30 advertencias |
| `texto.c` | ✓ Compilación OK | 9.0/10 | ✓ Limpio (0 fugas) | 3 advertencias |
| `texto.h` | ✓ Compilación OK | 8.5/10 | ✓ Limpio (0 fugas) | 3 advertencias |

## ⚠️ Archivos Binarios Prohibidos Filtrados

> ❌ **ERROR DE ENTREGA:** Se detectaron archivos binarios precompilados o ejecutables en la entrega del estudiante. 
> Para mantener la reproducibilidad académica y evitar la ejecución de código no compilado desde fuentes, estos archivos fueron **filtrados y descartados** de la evaluación.

| Archivo Binario | Regla | Severidad | Detalle del Error | Sugerencia |
| :--- | :---: | :---: | :--- | :--- |
| `libs/arreglos/arreglos.o` | `0x000Fh` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'libs/arreglos/arreglos.o' (Extensión binaria prohibida '.o'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `libs/arreglos/libarreglos.a` | `0x000Fh` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'libs/arreglos/libarreglos.a' (Extensión binaria prohibida '.a'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `libs/arreglos/prueba.o` | `0x000Fh` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'libs/arreglos/prueba.o' (Extensión binaria prohibida '.o'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `libs/arreglos/test_bin` | `0x000Fh` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'libs/arreglos/test_bin' (Firma binaria ejecutable detectada (Formato ejecutable o archivo objeto Linux ELF)). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `libs/p1_test/libp1_test.a` | `0x000Fh` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'libs/p1_test/libp1_test.a' (Extensión binaria prohibida '.a'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `libs/p1_test/prueba.o` | `0x000Fh` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'libs/p1_test/prueba.o' (Extensión binaria prohibida '.o'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `libs/p1_test/test_bin` | `0x000Fh` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'libs/p1_test/test_bin' (Firma binaria ejecutable detectada (Formato ejecutable o archivo objeto Linux ELF)). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `libs/p1_test/build/p1_test.o` | `0x000Fh` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'libs/p1_test/build/p1_test.o' (Extensión binaria prohibida '.o'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `libs/p1_test/build/libp1_test.a` | `0x000Fh` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'libs/p1_test/build/libp1_test.a' (Extensión binaria prohibida '.a'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |

**Acción Requerida:** Las entregas deben contener exclusivamente código fuente editable (`.c`, `.h`), archivos de configuración (`Makefile`) y documentación (`.md`, `.txt`). Ejecutá `make clean` antes de comprimir tu entrega y verificá tu archivo `.gitignore`.

## Compilación — Makefile raíz del Proyecto

✓ **Estado:** Compilación exitosa ejecutando el Makefile en la raíz (`make`).

> 📄 **Salida completa:** registrada en `compilacion_412cce4.log`.

## Observaciones de Calidad y Reglas P1 (Linter AST / Ripley)

Se detectaron **36** observación(es) en el código C:

| Regla | Ubicación | Severidad | Observación | Sugerencia |
| :--- | :--- | :---: | :--- | :--- |
| `0x0004h` | `main.c:10` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:14` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:32` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `operaciones.c:16` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `prueba.c:1` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `prueba.c:31` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `prueba.c:31` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0xEEEEh` | `main.c:25` | ESTILO | Indentación no es múltiplo de 4 espacios (11 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0x0004h` | `main.c:9` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:24` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:1` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:15` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `prueba.c:26` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `prueba.c:26` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `texto.c:4` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `arreglos.c:1` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `arreglos.c:30` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `arreglos.c:62` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `arreglos.c:114` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0002h` | `arreglos.c:144` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `arreglos.c:168` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `arreglos.c:169` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `arreglos.c:185` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `prueba.c:1` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:32` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:39` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `prueba.c:165` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `prueba.c:165` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `cadenas.c:1` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `cadenas.c:37` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0002h` | `cadenas.c:79` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `cadenas.c:136` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `cadenas.c:161` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `prueba.c:1` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `prueba.c:109` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `prueba.c:109` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |

## Pruebas del Proyecto — Makefile raíz (`make test`)

✓ **Estado:** Pruebas del proyecto aprobadas con éxito (`make test`).

## Auditoría de Memoria Dinámica — Valgrind

✓ **Estado:** No se detectaron fugas de memoria durante las pruebas en sandbox.

## Linter de Estilo y Formato — Gaff

⚠️ Se detectaron **68** observación(es) de estilo arquitectónico:

| Regla | Ubicación | Observación | Sugerencia | Autofix |
| :--- | :--- | :--- | :--- | :---: |
| `GAFF009` | `prueba.c:22` | La línea tiene 81 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `prueba.c:33` | La línea tiene 84 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `main.c:11` | La línea tiene 100 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `main.c:23` | La línea tiene 100 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `prueba.c:15` | La línea tiene 85 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `prueba.c:17` | La línea tiene 84 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `prueba.c:22` | La línea tiene 81 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `prueba.c:28` | La línea tiene 84 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `texto.c:4` | La línea tiene 125 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `texto.c:10` | La línea tiene 84 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `texto.h:23` | La línea tiene 81 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `texto.h:27` | La línea tiene 82 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `texto.h:32` | La línea tiene 81 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `arreglos.c:85` | La línea tiene 87 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `arreglos.c:159` | La línea tiene 87 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `arreglos.c:162` | La línea tiene 81 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `arreglos.c:185` | La línea tiene 139 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `arreglos.c:199` | La línea tiene 110 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `arreglos.h:3` | La línea tiene 82 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `arreglos.h:11` | La línea tiene 90 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `arreglos.h:12` | La línea tiene 90 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `arreglos.h:13` | La línea tiene 87 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `arreglos.h:34` | La línea tiene 81 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `arreglos.h:39` | La línea tiene 88 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `arreglos.h:40` | La línea tiene 86 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `arreglos.h:64` | La línea tiene 86 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `arreglos.h:65` | La línea tiene 86 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `arreglos.h:69` | La línea tiene 89 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `arreglos.h:70` | La línea tiene 85 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `arreglos.h:77` | La línea tiene 82 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `arreglos.h:97` | La línea tiene 91 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `arreglos.h:119` | La línea tiene 81 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `arreglos.h:150` | La línea tiene 86 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `arreglos.h:151` | La línea tiene 86 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `arreglos.h:155` | La línea tiene 86 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `arreglos.h:162` | La línea tiene 87 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `arreglos.h:176` | La línea tiene 86 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `arreglos.h:183` | La línea tiene 87 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `arreglos.h:184` | La línea tiene 85 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `arreglos.h:187` | La línea tiene 86 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `arreglos.h:188` | La línea tiene 86 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `arreglos.h:191` | La línea tiene 89 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `arreglos.h:192` | La línea tiene 81 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `arreglos.h:217` | La línea tiene 144 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `arreglos.h:219` | La línea tiene 84 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `arreglos.h:222` | La línea tiene 86 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `arreglos.h:223` | La línea tiene 89 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `arreglos.h:224` | La línea tiene 85 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `arreglos.h:227` | La línea tiene 86 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `arreglos.h:239` | La línea tiene 142 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `prueba.c:135` | La línea tiene 81 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `prueba.c:136` | La línea tiene 81 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `prueba.c:137` | La línea tiene 81 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `prueba.c:144` | La línea tiene 92 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `prueba.c:152` | La línea tiene 93 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `prueba.c:167` | La línea tiene 84 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `0x0001h` | `prueba.c:51` | Identificador corto y poco expresivo 'par' (3 caracteres). | Se recomienda utilizar identificadores más descriptivos del dominio del problema. | No |
| `GAFF009` | `cadenas.c:136` | La línea tiene 81 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `cadenas.c:161` | La línea tiene 104 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `cadenas.c:178` | La línea tiene 94 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `cadenas.h:38` | La línea tiene 86 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `cadenas.h:43` | La línea tiene 81 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `cadenas.h:126` | La línea tiene 81 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `cadenas.h:161` | La línea tiene 81 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `cadenas.h:166` | La línea tiene 112 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `cadenas.h:180` | La línea tiene 82 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `cadenas.h:187` | La línea tiene 105 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `prueba.c:111` | La línea tiene 83 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |

## Auditoría de Seguridad — Sandbox / Kaneda

⚠️ **Alerta:** Se detectaron **9** llamadas o patrones de riesgo de seguridad:

| Regla | Archivo:Línea | Severidad | Detalle | Sugerencia |
| :--- | :--- | :---: | :--- | :--- |
| `0x000Fh` | `libs/arreglos/arreglos.o:1` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'libs/arreglos/arreglos.o' (Extensión binaria prohibida '.o'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `0x000Fh` | `libs/arreglos/libarreglos.a:1` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'libs/arreglos/libarreglos.a' (Extensión binaria prohibida '.a'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `0x000Fh` | `libs/arreglos/prueba.o:1` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'libs/arreglos/prueba.o' (Extensión binaria prohibida '.o'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `0x000Fh` | `libs/arreglos/test_bin:1` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'libs/arreglos/test_bin' (Firma binaria ejecutable detectada (Formato ejecutable o archivo objeto Linux ELF)). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `0x000Fh` | `libs/p1_test/libp1_test.a:1` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'libs/p1_test/libp1_test.a' (Extensión binaria prohibida '.a'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `0x000Fh` | `libs/p1_test/prueba.o:1` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'libs/p1_test/prueba.o' (Extensión binaria prohibida '.o'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `0x000Fh` | `libs/p1_test/test_bin:1` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'libs/p1_test/test_bin' (Firma binaria ejecutable detectada (Formato ejecutable o archivo objeto Linux ELF)). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `0x000Fh` | `libs/p1_test/build/p1_test.o:1` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'libs/p1_test/build/p1_test.o' (Extensión binaria prohibida '.o'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `0x000Fh` | `libs/p1_test/build/libp1_test.a:1` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'libs/p1_test/build/libp1_test.a' (Extensión binaria prohibida '.a'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |

## Antipatrones Didácticos — Spunkmeyer

✓ **Estado:** No se detectaron antipatrones pedagógicos conocidos.

# Informe de Corrección — TP2 (ef5efe1)

## Repositorio
**branch/revision:** `main` `ef5efe1`
**Commit SHA:** `ef5efe1882be32e0c67c044287c4063ff296fd7c`
**Autor:** `anon_017`
**Fecha del commit:** `2026-09-16 23:22:27 -0300`
**Mensaje:** `Se sube el trabajo practico numero 2`
**Fecha de evaluación:** 2026-09-18 11:05:36
**Versión revisada:** `ef5efe1`

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
| `arreglos.c` | ❌ Falló Compilación | 0.0/10 | ✓ Limpio (0 fugas) | 46 advertencias |
| `arreglos.h` | ❌ Falló Compilación | 0.0/10 | ✓ Limpio (0 fugas) | 23 advertencias |
| `cadenas.c` | ❌ Falló Compilación | 7.0/10 | ✓ Limpio (0 fugas) | 10 advertencias |
| `cadenas.h` | ❌ Falló Compilación | 7.5/10 | ✓ Limpio (0 fugas) | 5 advertencias |
| `libs/arreglos/arreglos.o` | ❌ Falló Compilación | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `libs/arreglos/libarreglos.a` | ❌ Falló Compilación | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `libs/arreglos/prueba.o` | ❌ Falló Compilación | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `libs/arreglos/test_bin` | ❌ Falló Compilación | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `libs/p1_test/build/libp1_test.a` | ❌ Falló Compilación | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `libs/p1_test/build/p1_test.o` | ❌ Falló Compilación | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `libs/p1_test/libp1_test.a` | ❌ Falló Compilación | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `libs/p1_test/prueba.o` | ❌ Falló Compilación | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `libs/p1_test/test_bin` | ❌ Falló Compilación | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `main.c` | ❌ Falló Compilación | 9.0/10 | ✓ Limpio (0 fugas) | 8 advertencias |
| `operaciones.c` | ❌ Falló Compilación | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `prueba.c` | ❌ Falló Compilación | 5.5/10 | ✓ Limpio (0 fugas) | 25 advertencias |

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

❌ **Estado:** Falló la compilación mediante el Makefile de la raíz.

```text
In file included from prueba.c:9:
../../libs/p1_test/include/p1_test.h:573:32: warning: ‘_p1_test_func_prueba_arreglo_compactar’ defined but not used [-Wunused-function]
  573 | #define TEST(name) static void _p1_test_func_##name(void)
      |                                ^~~~~~~~~~~~~~
prueba.c:99:1: note: in expansion of macro ‘TEST’
   99 | TEST(prueba_arreglo_compactar)
      | ^~~~
cadenas.c: In function ‘cadena_longitud’:
cadenas.c:25:20: warning: ordered comparison of pointer with integer zero [-Wpedantic]
   25 |     else if(cadena > 0)
      |                    ^
cadenas.c:28:55: warning: comparison of integer expressions of different signedness: ‘int’ and ‘size_t’ {aka ‘long unsigned int’} [-Wsign-compare]
   28 |         while((cadena[contador] != '\0') && (contador < capacidad))
      |                                                       ^
cadenas.c: In function ‘cadena_copiar’:
cadenas.c:52:15: error: ‘i’ undeclared (first use in this function)
   52 |         while(i < capacacidad && arreglo[i] != 0)
      |               ^
cadenas.c:52:15: note: each undeclared identifier is reported only once for each function it appears in
cadenas.c:52:19: error: ‘capacacidad’
```

> 📄 **Salida completa:** registrada en `compilacion_ef5efe1.log`.

## Observaciones de Calidad y Reglas P1 (Linter AST / Ripley)

Se detectaron **31** observación(es) en el código C:

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
| `0x0004h` | `arreglos.c:1` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `arreglos.c:30` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `arreglos.c:62` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `arreglos.c:110` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0002h` | `arreglos.c:139` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `prueba.c:1` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:32` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:39` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `prueba.c:105` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `prueba.c:105` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `cadenas.c:1` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `cadenas.c:37` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0002h` | `cadenas.c:61` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `cadenas.c:74` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:1` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `prueba.c:76` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `prueba.c:76` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |

## Pruebas del Proyecto — Makefile raíz (`make test`)

❌ **Estado:** Fallaron las pruebas del proyecto (`make test`).

```text
make: Entering directory '/home/mrtin/dev/p1/ripley/entregas/TP2/TP2-anon_017/repo'
Compilando librería en libs/arreglos...
make[1]: Entering directory '/home/mrtin/dev/p1/ripley/entregas/TP2/TP2-anon_017/repo/libs/arreglos'
make[1]: Nothing to be done for 'all'.
make[1]: Leaving directory '/home/mrtin/dev/p1/ripley/entregas/TP2/TP2-anon_017/repo/libs/arreglos'
Compilando librería en libs/cadenas...
make[1]: Entering directory '/home/mrtin/dev/p1/ripley/entregas/TP2/TP2-anon_017/repo/libs/cadenas'
Compilando cadenas.c
cc -Wall -Wextra -std=c11 -pedantic -g -c cadenas.c
make[1]: Leaving dir
```

## Auditoría de Memoria Dinámica — Valgrind

✓ **Estado:** No se detectaron fugas de memoria durante las pruebas en sandbox.

## Linter de Estilo y Formato — Gaff

⚠️ Se detectaron **86** observación(es) de estilo arquitectónico:

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
| `GAFF010` | `arreglos.c:25` | Uso de tabuladores prohibido. Usar 4 espacios. | Configurá tu editor para usar 4 espacios en lugar de tabuladores. | ✓ Sí |
| `GAFF010` | `arreglos.c:44` | Uso de tabuladores prohibido. Usar 4 espacios. | Configurá tu editor para usar 4 espacios en lugar de tabuladores. | ✓ Sí |
| `GAFF010` | `arreglos.c:45` | Uso de tabuladores prohibido. Usar 4 espacios. | Configurá tu editor para usar 4 espacios en lugar de tabuladores. | ✓ Sí |
| `GAFF010` | `arreglos.c:46` | Uso de tabuladores prohibido. Usar 4 espacios. | Configurá tu editor para usar 4 espacios en lugar de tabuladores. | ✓ Sí |
| `GAFF010` | `arreglos.c:47` | Uso de tabuladores prohibido. Usar 4 espacios. | Configurá tu editor para usar 4 espacios en lugar de tabuladores. | ✓ Sí |
| `GAFF010` | `arreglos.c:48` | Uso de tabuladores prohibido. Usar 4 espacios. | Configurá tu editor para usar 4 espacios en lugar de tabuladores. | ✓ Sí |
| `GAFF010` | `arreglos.c:49` | Uso de tabuladores prohibido. Usar 4 espacios. | Configurá tu editor para usar 4 espacios en lugar de tabuladores. | ✓ Sí |
| `GAFF010` | `arreglos.c:50` | Uso de tabuladores prohibido. Usar 4 espacios. | Configurá tu editor para usar 4 espacios en lugar de tabuladores. | ✓ Sí |
| `GAFF010` | `arreglos.c:51` | Uso de tabuladores prohibido. Usar 4 espacios. | Configurá tu editor para usar 4 espacios en lugar de tabuladores. | ✓ Sí |
| `GAFF010` | `arreglos.c:52` | Uso de tabuladores prohibido. Usar 4 espacios. | Configurá tu editor para usar 4 espacios en lugar de tabuladores. | ✓ Sí |
| `GAFF010` | `arreglos.c:66` | Uso de tabuladores prohibido. Usar 4 espacios. | Configurá tu editor para usar 4 espacios en lugar de tabuladores. | ✓ Sí |
| `GAFF010` | `arreglos.c:67` | Uso de tabuladores prohibido. Usar 4 espacios. | Configurá tu editor para usar 4 espacios en lugar de tabuladores. | ✓ Sí |
| `GAFF010` | `arreglos.c:69` | Uso de tabuladores prohibido. Usar 4 espacios. | Configurá tu editor para usar 4 espacios en lugar de tabuladores. | ✓ Sí |
| `GAFF010` | `arreglos.c:71` | Uso de tabuladores prohibido. Usar 4 espacios. | Configurá tu editor para usar 4 espacios en lugar de tabuladores. | ✓ Sí |
| `GAFF010` | `arreglos.c:72` | Uso de tabuladores prohibido. Usar 4 espacios. | Configurá tu editor para usar 4 espacios en lugar de tabuladores. | ✓ Sí |
| `GAFF010` | `arreglos.c:73` | Uso de tabuladores prohibido. Usar 4 espacios. | Configurá tu editor para usar 4 espacios en lugar de tabuladores. | ✓ Sí |
| `GAFF010` | `arreglos.c:75` | Uso de tabuladores prohibido. Usar 4 espacios. | Configurá tu editor para usar 4 espacios en lugar de tabuladores. | ✓ Sí |
| `GAFF010` | `arreglos.c:76` | Uso de tabuladores prohibido. Usar 4 espacios. | Configurá tu editor para usar 4 espacios en lugar de tabuladores. | ✓ Sí |
| `GAFF010` | `arreglos.c:77` | Uso de tabuladores prohibido. Usar 4 espacios. | Configurá tu editor para usar 4 espacios en lugar de tabuladores. | ✓ Sí |
| `GAFF009` | `arreglos.c:85` | La línea tiene 87 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF010` | `arreglos.c:98` | Uso de tabuladores prohibido. Usar 4 espacios. | Configurá tu editor para usar 4 espacios en lugar de tabuladores. | ✓ Sí |
| `GAFF010` | `arreglos.c:99` | Uso de tabuladores prohibido. Usar 4 espacios. | Configurá tu editor para usar 4 espacios en lugar de tabuladores. | ✓ Sí |
| `GAFF010` | `arreglos.c:100` | Uso de tabuladores prohibido. Usar 4 espacios. | Configurá tu editor para usar 4 espacios en lugar de tabuladores. | ✓ Sí |
| `GAFF010` | `arreglos.c:101` | Uso de tabuladores prohibido. Usar 4 espacios. | Configurá tu editor para usar 4 espacios en lugar de tabuladores. | ✓ Sí |
| `GAFF010` | `arreglos.c:102` | Uso de tabuladores prohibido. Usar 4 espacios. | Configurá tu editor para usar 4 espacios en lugar de tabuladores. | ✓ Sí |
| `GAFF010` | `arreglos.c:103` | Uso de tabuladores prohibido. Usar 4 espacios. | Configurá tu editor para usar 4 espacios en lugar de tabuladores. | ✓ Sí |
| `GAFF010` | `arreglos.c:104` | Uso de tabuladores prohibido. Usar 4 espacios. | Configurá tu editor para usar 4 espacios en lugar de tabuladores. | ✓ Sí |
| `GAFF010` | `arreglos.c:124` | Uso de tabuladores prohibido. Usar 4 espacios. | Configurá tu editor para usar 4 espacios en lugar de tabuladores. | ✓ Sí |
| `GAFF010` | `arreglos.c:125` | Uso de tabuladores prohibido. Usar 4 espacios. | Configurá tu editor para usar 4 espacios en lugar de tabuladores. | ✓ Sí |
| `GAFF010` | `arreglos.c:127` | Uso de tabuladores prohibido. Usar 4 espacios. | Configurá tu editor para usar 4 espacios en lugar de tabuladores. | ✓ Sí |
| `GAFF010` | `arreglos.c:128` | Uso de tabuladores prohibido. Usar 4 espacios. | Configurá tu editor para usar 4 espacios en lugar de tabuladores. | ✓ Sí |
| `GAFF010` | `arreglos.c:129` | Uso de tabuladores prohibido. Usar 4 espacios. | Configurá tu editor para usar 4 espacios en lugar de tabuladores. | ✓ Sí |
| `GAFF010` | `arreglos.c:145` | Uso de tabuladores prohibido. Usar 4 espacios. | Configurá tu editor para usar 4 espacios en lugar de tabuladores. | ✓ Sí |
| `GAFF010` | `arreglos.c:146` | Uso de tabuladores prohibido. Usar 4 espacios. | Configurá tu editor para usar 4 espacios en lugar de tabuladores. | ✓ Sí |
| `GAFF010` | `arreglos.c:147` | Uso de tabuladores prohibido. Usar 4 espacios. | Configurá tu editor para usar 4 espacios en lugar de tabuladores. | ✓ Sí |
| `GAFF010` | `arreglos.c:149` | Uso de tabuladores prohibido. Usar 4 espacios. | Configurá tu editor para usar 4 espacios en lugar de tabuladores. | ✓ Sí |
| `GAFF010` | `arreglos.c:151` | Uso de tabuladores prohibido. Usar 4 espacios. | Configurá tu editor para usar 4 espacios en lugar de tabuladores. | ✓ Sí |
| `GAFF010` | `arreglos.c:152` | Uso de tabuladores prohibido. Usar 4 espacios. | Configurá tu editor para usar 4 espacios en lugar de tabuladores. | ✓ Sí |
| `GAFF010` | `arreglos.c:153` | Uso de tabuladores prohibido. Usar 4 espacios. | Configurá tu editor para usar 4 espacios en lugar de tabuladores. | ✓ Sí |
| `GAFF010` | `arreglos.c:154` | Uso de tabuladores prohibido. Usar 4 espacios. | Configurá tu editor para usar 4 espacios en lugar de tabuladores. | ✓ Sí |
| `GAFF010` | `arreglos.c:157` | Uso de tabuladores prohibido. Usar 4 espacios. | Configurá tu editor para usar 4 espacios en lugar de tabuladores. | ✓ Sí |
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
| `GAFF009` | `arreglos.h:185` | La línea tiene 86 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `arreglos.h:186` | La línea tiene 86 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `arreglos.h:189` | La línea tiene 83 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `arreglos.h:213` | La línea tiene 144 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `prueba.c:107` | La línea tiene 84 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `0x0001h` | `prueba.c:51` | Identificador corto y poco expresivo 'par' (3 caracteres). | Se recomienda utilizar identificadores más descriptivos del dominio del problema. | No |
| `GAFF010` | `cadenas.c:30` | Uso de tabuladores prohibido. Usar 4 espacios. | Configurá tu editor para usar 4 espacios en lugar de tabuladores. | ✓ Sí |
| `GAFF010` | `cadenas.c:31` | Uso de tabuladores prohibido. Usar 4 espacios. | Configurá tu editor para usar 4 espacios en lugar de tabuladores. | ✓ Sí |
| `GAFF010` | `cadenas.c:32` | Uso de tabuladores prohibido. Usar 4 espacios. | Configurá tu editor para usar 4 espacios en lugar de tabuladores. | ✓ Sí |
| `GAFF010` | `cadenas.c:54` | Uso de tabuladores prohibido. Usar 4 espacios. | Configurá tu editor para usar 4 espacios en lugar de tabuladores. | ✓ Sí |
| `GAFF010` | `cadenas.c:55` | Uso de tabuladores prohibido. Usar 4 espacios. | Configurá tu editor para usar 4 espacios en lugar de tabuladores. | ✓ Sí |
| `GAFF009` | `cadenas.c:74` | La línea tiene 81 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `cadenas.h:38` | La línea tiene 86 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `cadenas.h:43` | La línea tiene 81 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `cadenas.h:106` | La línea tiene 81 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `cadenas.h:125` | La línea tiene 81 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `cadenas.h:130` | La línea tiene 112 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `prueba.c:78` | La línea tiene 83 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |

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

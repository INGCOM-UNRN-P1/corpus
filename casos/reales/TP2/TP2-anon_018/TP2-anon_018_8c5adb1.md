# Informe de Corrección — TP2 (8c5adb1)

## Repositorio
**branch/revision:** `main` `8c5adb1`
**Commit SHA:** `8c5adb190bc0545d1124cdb29b9b277f008b450a`
**Autor:** `anon_018`
**Fecha del commit:** `2026-09-28 14:42:16 -0300`
**Mensaje:** `Agrego las funciones de cadenas y arreglos con sus respectivas pruebas`
**Fecha de evaluación:** 2026-09-29 16:21:57
**Versión revisada:** `8c5adb1`

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
│   │   ├── arreglo.h
│   │   ├── arreglos.c
│   │   ├── arreglos.h
│   │   ├── Makefile
│   │   └── prueba.c
│   ├── cadenas/
│   │   ├── cadena.h
│   │   ├── cadenas.c
│   │   ├── cadenas.h
│   │   ├── Makefile
│   │   └── prueba.c
│   └── p1_test/
│       ├── include/
│       │   ├── p1_arrays.h
│       │   ├── p1_files.h
│       │   ├── p1_stdio.h
│       │   └── p1_test.h
│       ├── src/
│       │   └── p1_test.c
│       ├── library.json
│       ├── library.spec
│       ├── Makefile
│       ├── p1_arrays.h
│       ├── p1_files.h
│       ├── p1_stdio.h
│       ├── p1_test.h
│       └── prueba.c
├── Makefile
├── README.md
└── tp.sh
```

## Análisis de Código C e Informes de Herramientas

## Resumen de Evaluación por Archivo

| Archivo | Estado Compilación | Evaluación de Estilo | Valgrind (Fugas) | Observaciones Cátedra |
| :--- | :---: | :---: | :---: | :--- |
| `arreglos.c` | ✓ Compilación OK | 9.5/10 | ✓ Limpio (0 fugas) | 8 advertencias |
| `arreglos.h` | ✓ Compilación OK | 5.0/10 | ✓ Limpio (0 fugas) | 10 advertencias |
| `cadenas.c` | ✓ Compilación OK | 8.0/10 | ✓ Limpio (0 fugas) | 12 advertencias |
| `cadenas.h` | ✓ Compilación OK | 1.5/10 | ✓ Limpio (0 fugas) | 17 advertencias |
| `main.c` | ✓ Compilación OK | 9.0/10 | ✓ Limpio (0 fugas) | 8 advertencias |
| `operaciones.c` | ✓ Compilación OK | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `prueba.c` | ✓ Compilación OK | 3.5/10 | ✓ Limpio (0 fugas) | 34 advertencias |

## Compilación — Makefile raíz del Proyecto

✓ **Estado:** Compilación exitosa ejecutando el Makefile en la raíz (`make`).

> 📄 **Salida completa:** registrada en `compilacion_8c5adb1.log`.

## Observaciones de Calidad y Reglas P1 (Linter AST / Ripley)

Se detectaron **38** observación(es) en el código C:

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
| `0xEEEEh` | `arreglos.c:109` | ESTILO | Indentación no es múltiplo de 4 espacios (1 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `arreglos.c:110` | ESTILO | Indentación no es múltiplo de 4 espacios (1 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `arreglos.c:126` | ESTILO | Indentación no es múltiplo de 4 espacios (1 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0x0004h` | `arreglos.c:1` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `arreglos.c:29` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0002h` | `arreglos.c:86` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0002h` | `arreglos.c:109` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `prueba.c:1` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:32` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:39` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:175` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:179` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `prueba.c:182` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `prueba.c:182` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `cadenas.c:1` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `cadenas.c:29` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0002h` | `cadenas.c:52` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0002h` | `cadenas.c:108` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0002h` | `cadenas.c:149` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `cadenas.c:197` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:1` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:118` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `prueba.c:130` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `prueba.c:130` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |

## Pruebas del Proyecto — Makefile raíz (`make test`)

✓ **Estado:** Pruebas del proyecto aprobadas con éxito (`make test`).

## Auditoría de Memoria Dinámica — Valgrind

✓ **Estado:** No se detectaron fugas de memoria durante las pruebas en sandbox.

## Linter de Estilo y Formato — Gaff

⚠️ Se detectaron **47** observación(es) de estilo arquitectónico:

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
| `GAFF009` | `arreglos.c:137` | La línea tiene 124 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `arreglos.h:3` | La línea tiene 82 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `arreglos.h:11` | La línea tiene 90 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `arreglos.h:12` | La línea tiene 90 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `arreglos.h:13` | La línea tiene 87 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `arreglos.h:111` | La línea tiene 88 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `arreglos.h:112` | La línea tiene 83 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `arreglos.h:149` | La línea tiene 86 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `arreglos.h:186` | La línea tiene 144 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `arreglos.h:199` | La línea tiene 84 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `arreglos.h:203` | La línea tiene 143 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `prueba.c:171` | La línea tiene 83 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `prueba.c:184` | La línea tiene 84 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `0x0001h` | `prueba.c:51` | Identificador corto y poco expresivo 'par' (3 caracteres). | Se recomienda utilizar identificadores más descriptivos del dominio del problema. | No |
| `0x0001h` | `prueba.c:159` | Identificador de variable no descriptivo de una sola letra 'a'. | Los nombres de variables deben reflejar con precisión su propósito (salvo índices canónicos i, j, k, n, x, y, z, f, c, r). | No |
| `0x0001h` | `prueba.c:160` | Identificador de variable no descriptivo de una sola letra 'b'. | Los nombres de variables deben reflejar con precisión su propósito (salvo índices canónicos i, j, k, n, x, y, z, f, c, r). | No |
| `GAFF009` | `cadenas.c:108` | La línea tiene 108 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `cadenas.c:133` | La línea tiene 96 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `0x0001h` | `cadenas.c:121` | Identificador corto y poco expresivo 'pos' (3 caracteres). | Se recomienda utilizar identificadores más descriptivos del dominio del problema. | No |
| `0x0001h` | `cadenas.c:180` | Identificador corto y poco expresivo 'pos' (3 caracteres). | Se recomienda utilizar identificadores más descriptivos del dominio del problema. | No |
| `GAFF009` | `cadenas.h:74` | La línea tiene 94 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `cadenas.h:134` | La línea tiene 81 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `cadenas.h:166` | La línea tiene 81 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `cadenas.h:171` | La línea tiene 112 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `cadenas.h:176` | La línea tiene 89 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `cadenas.h:180` | La línea tiene 88 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `cadenas.h:185` | La línea tiene 88 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `cadenas.h:187` | La línea tiene 85 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `cadenas.h:188` | La línea tiene 85 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `cadenas.h:191` | La línea tiene 86 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `cadenas.h:194` | La línea tiene 109 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `cadenas.h:217` | La línea tiene 91 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `cadenas.h:223` | La línea tiene 87 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `cadenas.h:224` | La línea tiene 88 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `cadenas.h:225` | La línea tiene 90 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `cadenas.h:228` | La línea tiene 94 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `cadenas.h:230` | La línea tiene 83 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `prueba.c:90` | La línea tiene 86 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `prueba.c:132` | La línea tiene 83 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |

## Auditoría de Seguridad — Sandbox / Kaneda

✓ **Estado:** Código libre de llamadas del sistema restringidas o intentos de evasión de sandbox.

## Antipatrones Didácticos — Spunkmeyer

✓ **Estado:** No se detectaron antipatrones pedagógicos conocidos.

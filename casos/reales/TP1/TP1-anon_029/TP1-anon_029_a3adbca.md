# Informe de Corrección — TP1 (a3adbca)

## Repositorio
**branch/revision:** `main` `a3adbca`
**Commit SHA:** `a3adbca2b58c112cf8cfa9ed7cfd26e1286b175c`
**Autor:** `anon_029`
**Fecha del commit:** `2026-09-09 10:46:10 -0300`
**Mensaje:** `tarea: Agregamos el reporte de configuracion del entorno`
**Fecha de evaluación:** 2026-09-17 14:44:58
**Versión revisada:** `a3adbca`

## Especificación de la Guía
**Guía vinculada:** `Trabajo Práctico 1: Introducción a C, Modularización y E/S en Consola`
**Ejercicios requeridos:** `consola (Librería de Consola y Limpieza de Búfer)`, `ejercicio1 (Conversor de Temperatura Celsius y Fahrenheit)`, `ejercicio2 (Calculadora Estadística Secuencial)`, `ejercicio3 (Validador de Fechas y Año Bisiesto)`, `ejercicio4 (Validador y Clasificador de Triángulos)`, `ejercicio5 (Desglose de Billetes de Cajero Automático)`

### Archivos contenidos
```text
.
├── ejercicios/
│   ├── ejercicio1/
│   │   ├── conversor.c
│   │   ├── conversor.h
│   │   ├── main.c
│   │   ├── Makefile
│   │   └── prueba.c
│   ├── ejercicio2/
│   │   ├── estadistica.c
│   │   ├── estadistica.h
│   │   ├── main.c
│   │   ├── Makefile
│   │   └── prueba.c
│   ├── ejercicio3/
│   │   ├── fecha.c
│   │   ├── fecha.h
│   │   ├── main.c
│   │   ├── Makefile
│   │   └── prueba.c
│   ├── ejercicio4/
│   │   ├── main.c
│   │   ├── Makefile
│   │   ├── prueba.c
│   │   ├── triangulo.c
│   │   └── triangulo.h
│   └── ejercicio5/
│       ├── cajero.c
│       ├── cajero.h
│       ├── main.c
│       ├── Makefile
│       └── prueba.c
├── libs/
│   └── consola/
│       ├── consola.c
│       ├── consola.h
│       ├── Makefile
│       └── prueba.c
├── entorno.txt
├── Makefile
├── README.md
└── tp.sh
```

## Análisis de Código C e Informes de Herramientas

## Resumen de Evaluación por Archivo

| Archivo | Estado Compilación | Evaluación de Estilo | Valgrind (Fugas) | Observaciones Cátedra |
| :--- | :---: | :---: | :---: | :--- |
| `cajero.c` | ❌ Falló Compilación | 10.0/10 | ✓ Limpio (0 fugas) | 9 advertencias |
| `consola.c` | ❌ Falló Compilación | 6.0/10 | ✓ Limpio (0 fugas) | 60 advertencias |
| `consola.h` | ❌ Falló Compilación | 6.0/10 | ✓ Limpio (0 fugas) | 8 advertencias |
| `conversor.c` | ❌ Falló Compilación | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `estadistica.c` | ❌ Falló Compilación | 10.0/10 | ✓ Limpio (0 fugas) | 3 advertencias |
| `fecha.c` | ❌ Falló Compilación | 8.5/10 | ✓ Limpio (0 fugas) | 8 advertencias |
| `fecha.h` | ❌ Falló Compilación | 7.0/10 | ✓ Limpio (0 fugas) | 6 advertencias |
| `main.c` | ❌ Falló Compilación | 5.0/10 | ✓ Limpio (0 fugas) | 34 advertencias |
| `prueba.c` | ❌ Falló Compilación | 3.5/10 | ✓ Limpio (0 fugas) | 69 advertencias |
| `triangulo.c` | ❌ Falló Compilación | 10.0/10 | ✓ Limpio (0 fugas) | 12 advertencias |

## Compilación — Makefile raíz del Proyecto

❌ **Estado:** Falló la compilación mediante el Makefile de la raíz.

```text
consola.c: In function ‘limpiar_buffer_entrada’:
consola.c:9:1: error: version control conflict marker in file
    9 | <<<<<<< HEAD
      | ^~~~~~~
consola.c:12:9: error: invalid suffix ‘f4143’ on integer constant
   12 | >>>>>>> 45f4143 (Entrega tp 1 completa)
      |         ^~~~~~~
consola.c: In function ‘esta_en_rango_entero’:
consola.c:18:1: error: version control conflict marker in file
   18 | <<<<<<< HEAD
      | ^~~~~~~
consola.c:28:9: error: invalid suffix ‘f4143’ on integer constant
   28 | >>>>>>> 45f4143 (Entrega tp 1 completa)
      |         ^~~~~~~
consola.c:16:31: warning: unused parameter ‘valor’ [-Wunused-parameter]
   16 | bool esta_en_rango_entero(int valor, int min, int max)
      |                           ~~~~^~~~~
consola.c:16:42: warning: unused parameter ‘min’ [-Wunused-parameter]
   16 | bool esta_en_rango_entero(int valor, int min, int max)
      |                                      ~~~~^~~
consola.c:16:51: warning: unused parameter ‘max’ [-Wunused-parameter]
   16 | bool esta_en_rango_entero(int valor, int min, int max)
      |                                               ~~~~^~~
consola.c: In function ‘esta_en_rango_flotante’:
consola.c:34:1: erro
```

> 📄 **Salida completa:** registrada en `compilacion_a3adbca.log`.

## Observaciones de Calidad y Reglas P1 — Ripley

Se detectaron **132** observación(es) en el código C:

| Regla | Ubicación | Severidad | Observación | Sugerencia |
| :--- | :--- | :---: | :--- | :--- |
| `0x0018h` | `conversor.c:9` | ESTILO | El asterisco del puntero debe estar junto al identificador (ej. 'int *ptr;'). | Escribir 'tipo *nombre_var' en lugar de 'tipo* nombre_var'. |
| `0x0004h` | `main.c:30` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:35` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:38` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `prueba.c:18` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0002h` | `estadistica.c:3` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0002h` | `estadistica.c:12` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0002h` | `estadistica.c:21` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0002h` | `main.c:7` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0002h` | `main.c:8` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `main.c:56` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `prueba.c:10` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `prueba.c:25` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:43` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:44` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:61` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:62` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `fecha.c:15` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0002h` | `fecha.c:43` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `main.c:14` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:15` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:19` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:23` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:35` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:52` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:73` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `main.c:26` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `main.c:62` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:25` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:39` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:49` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:52` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:80` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:86` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:94` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:99` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:104` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:117` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `triangulo.c:3` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `triangulo.c:5` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `triangulo.c:25` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `triangulo.c:28` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `triangulo.c:30` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `triangulo.c:53` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `triangulo.c:56` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `triangulo.c:58` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0018h` | `triangulo.c:68` | ESTILO | El asterisco del puntero debe estar junto al identificador (ej. 'int *ptr;'). | Escribir 'tipo *nombre_var' en lugar de 'tipo* nombre_var'. |
| `0x0018h` | `triangulo.c:69` | ESTILO | El asterisco del puntero debe estar junto al identificador (ej. 'int *ptr;'). | Escribir 'tipo *nombre_var' en lugar de 'tipo* nombre_var'. |
| `0x0018h` | `triangulo.c:70` | ESTILO | El asterisco del puntero debe estar junto al identificador (ej. 'int *ptr;'). | Escribir 'tipo *nombre_var' en lugar de 'tipo* nombre_var'. |
| `0x0004h` | `triangulo.c:78` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `cajero.c:5` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `cajero.c:17` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `cajero.c:20` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `cajero.c:22` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `cajero.c:33` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `cajero.c:37` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `cajero.c:39` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0018h` | `cajero.c:50` | ESTILO | El asterisco del puntero debe estar junto al identificador (ej. 'int *ptr;'). | Escribir 'tipo *nombre_var' en lugar de 'tipo* nombre_var'. |
| `0x0004h` | `cajero.c:53` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0xEEEEh` | `main.c:21` | ESTILO | Indentación no es múltiplo de 4 espacios (38 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `main.c:46` | ESTILO | Indentación no es múltiplo de 4 espacios (15 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0x0004h` | `main.c:25` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:30` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:57` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:26` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:27` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:28` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:29` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:30` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0xEEEEh` | `consola.c:213` | ESTILO | Indentación no es múltiplo de 4 espacios (15 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0x0004h` | `consola.c:9` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `consola.c:12` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `consola.c:16` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `consola.c:18` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `consola.c:28` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `consola.c:32` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `consola.c:34` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `consola.c:45` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `consola.c:50` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `consola.c:53` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `consola.c:55` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `consola.c:57` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `consola.c:65` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `consola.c:66` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `consola.c:69` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `consola.c:76` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `consola.c:80` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `consola.c:82` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `consola.c:87` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `consola.c:99` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `consola.c:101` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `consola.c:103` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `consola.c:109` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `consola.c:112` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `consola.c:114` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `consola.c:116` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `consola.c:124` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `consola.c:125` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `consola.c:133` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `consola.c:137` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `consola.c:139` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `consola.c:144` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `consola.c:156` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `consola.c:158` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `consola.c:160` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `consola.c:166` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `consola.c:169` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `consola.c:176` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `consola.c:184` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `consola.c:190` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `consola.c:193` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `consola.c:197` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `consola.c:216` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:14` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:15` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:18` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:21` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:22` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:23` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:24` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:25` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:26` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:46` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:47` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:50` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:53` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:54` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:55` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:56` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:57` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:58` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:63` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |

## Pruebas del Proyecto — Makefile raíz (`make test`)

❌ **Estado:** Fallaron las pruebas del proyecto (`make test`).

```text
make: Entering directory '/home/mrtin/dev/p1/ripley/entregas/TP1/TP1-anon_029/repo'
Compilando librería en libs/consola...
make[1]: Entering directory '/home/mrtin/dev/p1/ripley/entregas/TP1/TP1-anon_029/repo/libs/consola'
Compilando consola.c
cc -Wall -Wextra -pedantic -g -c consola.c
make[1]: Leaving directory '/home/mrtin/dev/p1/ripley/entregas/TP1/TP1-anon_029/repo/libs/consola'
make: Leaving directory '/home/mrtin/dev/p1/ripley/entregas/TP1/TP1-anon_029/repo'

consola.c: In function ‘limpiar_buffer_entrada’:
consola.c:9:1: error: version control conflict marker in file
    9 |
```

## Auditoría de Memoria Dinámica — Valgrind

✓ **Estado:** No se detectaron fugas de memoria durante las pruebas en sandbox.

## Linter de Estilo y Formato — Gaff

⚠️ Se detectaron **48** observación(es) de estilo arquitectónico:

| Regla | Ubicación | Observación | Sugerencia | Autofix |
| :--- | :--- | :--- | :--- | :---: |
| `GAFF009` | `main.c:30` | La línea tiene 86 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `main.c:35` | La línea tiene 86 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `0x0001h` | `main.c:29` | Identificador corto y poco expresivo 'res' (3 caracteres). | Se recomienda utilizar identificadores más descriptivos del dominio del problema. | No |
| `0x0001h` | `main.c:34` | Identificador corto y poco expresivo 'res' (3 caracteres). | Se recomienda utilizar identificadores más descriptivos del dominio del problema. | No |
| `0x0001h` | `prueba.c:39` | Identificador corto y poco expresivo 'c1' (2 caracteres). | Se recomienda utilizar identificadores más descriptivos del dominio del problema. | No |
| `0x0001h` | `prueba.c:40` | Identificador corto y poco expresivo 'c2' (2 caracteres). | Se recomienda utilizar identificadores más descriptivos del dominio del problema. | No |
| `0x0001h` | `prueba.c:41` | Identificador corto y poco expresivo 'c3' (2 caracteres). | Se recomienda utilizar identificadores más descriptivos del dominio del problema. | No |
| `0x0001h` | `prueba.c:42` | Identificador corto y poco expresivo 'f1' (2 caracteres). | Se recomienda utilizar identificadores más descriptivos del dominio del problema. | No |
| `GAFF009` | `main.c:24` | La línea tiene 82 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `main.c:53` | La línea tiene 84 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `0x0001h` | `fecha.c:15` | Identificador corto y poco expresivo 'mes' (3 caracteres). | Se recomienda utilizar identificadores más descriptivos del dominio del problema. | No |
| `0x0001h` | `fecha.c:43` | Identificador corto y poco expresivo 'dia' (3 caracteres). | Se recomienda utilizar identificadores más descriptivos del dominio del problema. | No |
| `0x0001h` | `fecha.c:43` | Identificador corto y poco expresivo 'mes' (3 caracteres). | Se recomienda utilizar identificadores más descriptivos del dominio del problema. | No |
| `GAFF009` | `fecha.h:18` | La línea tiene 85 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `fecha.h:31` | La línea tiene 82 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `fecha.h:33` | La línea tiene 83 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `0x0001h` | `fecha.h:28` | Identificador corto y poco expresivo 'mes' (3 caracteres). | Se recomienda utilizar identificadores más descriptivos del dominio del problema. | No |
| `0x0001h` | `fecha.h:41` | Identificador corto y poco expresivo 'dia' (3 caracteres). | Se recomienda utilizar identificadores más descriptivos del dominio del problema. | No |
| `0x0001h` | `fecha.h:41` | Identificador corto y poco expresivo 'mes' (3 caracteres). | Se recomienda utilizar identificadores más descriptivos del dominio del problema. | No |
| `0x0001h` | `main.c:14` | Identificador corto y poco expresivo 'mes' (3 caracteres). | Se recomienda utilizar identificadores más descriptivos del dominio del problema. | No |
| `0x0001h` | `main.c:15` | Identificador corto y poco expresivo 'dia' (3 caracteres). | Se recomienda utilizar identificadores más descriptivos del dominio del problema. | No |
| `0x0001h` | `main.c:26` | Identificador de variable no descriptivo de una sola letra 'a'. | Los nombres de variables deben reflejar con precisión su propósito (salvo índices canónicos i, j, k, n, x, y, z, f, c, r). | No |
| `0x0001h` | `main.c:26` | Identificador de variable no descriptivo de una sola letra 'b'. | Los nombres de variables deben reflejar con precisión su propósito (salvo índices canónicos i, j, k, n, x, y, z, f, c, r). | No |
| `0x0001h` | `prueba.c:117` | Identificador corto y poco expresivo 'b5k' (3 caracteres). | Se recomienda utilizar identificadores más descriptivos del dominio del problema. | No |
| `0x0001h` | `prueba.c:120` | Identificador corto y poco expresivo 'b2k' (3 caracteres). | Se recomienda utilizar identificadores más descriptivos del dominio del problema. | No |
| `0x0001h` | `prueba.c:123` | Identificador corto y poco expresivo 'b1k' (3 caracteres). | Se recomienda utilizar identificadores más descriptivos del dominio del problema. | No |
| `0x0001h` | `prueba.c:155` | Identificador corto y poco expresivo 'b5k' (3 caracteres). | Se recomienda utilizar identificadores más descriptivos del dominio del problema. | No |
| `0x0001h` | `prueba.c:158` | Identificador corto y poco expresivo 'b2k' (3 caracteres). | Se recomienda utilizar identificadores más descriptivos del dominio del problema. | No |
| `0x0001h` | `prueba.c:161` | Identificador corto y poco expresivo 'b1k' (3 caracteres). | Se recomienda utilizar identificadores más descriptivos del dominio del problema. | No |
| `0x0001h` | `prueba.c:193` | Identificador corto y poco expresivo 'b5k' (3 caracteres). | Se recomienda utilizar identificadores más descriptivos del dominio del problema. | No |
| `0x0001h` | `prueba.c:196` | Identificador corto y poco expresivo 'b2k' (3 caracteres). | Se recomienda utilizar identificadores más descriptivos del dominio del problema. | No |
| `0x0001h` | `prueba.c:199` | Identificador corto y poco expresivo 'b1k' (3 caracteres). | Se recomienda utilizar identificadores más descriptivos del dominio del problema. | No |
| `0x0001h` | `consola.c:16` | Identificador corto y poco expresivo 'min' (3 caracteres). | Se recomienda utilizar identificadores más descriptivos del dominio del problema. | No |
| `0x0001h` | `consola.c:16` | Identificador corto y poco expresivo 'max' (3 caracteres). | Se recomienda utilizar identificadores más descriptivos del dominio del problema. | No |
| `0x0001h` | `consola.c:32` | Identificador corto y poco expresivo 'min' (3 caracteres). | Se recomienda utilizar identificadores más descriptivos del dominio del problema. | No |
| `0x0001h` | `consola.c:32` | Identificador corto y poco expresivo 'max' (3 caracteres). | Se recomienda utilizar identificadores más descriptivos del dominio del problema. | No |
| `0x0001h` | `consola.c:80` | Identificador corto y poco expresivo 'min' (3 caracteres). | Se recomienda utilizar identificadores más descriptivos del dominio del problema. | No |
| `0x0001h` | `consola.c:80` | Identificador corto y poco expresivo 'max' (3 caracteres). | Se recomienda utilizar identificadores más descriptivos del dominio del problema. | No |
| `0x0001h` | `consola.c:137` | Identificador corto y poco expresivo 'max' (3 caracteres). | Se recomienda utilizar identificadores más descriptivos del dominio del problema. | No |
| `0x0001h` | `consola.c:137` | Identificador corto y poco expresivo 'min' (3 caracteres). | Se recomienda utilizar identificadores más descriptivos del dominio del problema. | No |
| `0x0001h` | `consola.h:28` | Identificador corto y poco expresivo 'min' (3 caracteres). | Se recomienda utilizar identificadores más descriptivos del dominio del problema. | No |
| `0x0001h` | `consola.h:28` | Identificador corto y poco expresivo 'max' (3 caracteres). | Se recomienda utilizar identificadores más descriptivos del dominio del problema. | No |
| `0x0001h` | `consola.h:46` | Identificador corto y poco expresivo 'max' (3 caracteres). | Se recomienda utilizar identificadores más descriptivos del dominio del problema. | No |
| `0x0001h` | `consola.h:46` | Identificador corto y poco expresivo 'min' (3 caracteres). | Se recomienda utilizar identificadores más descriptivos del dominio del problema. | No |
| `0x0001h` | `consola.h:72` | Identificador corto y poco expresivo 'max' (3 caracteres). | Se recomienda utilizar identificadores más descriptivos del dominio del problema. | No |
| `0x0001h` | `consola.h:72` | Identificador corto y poco expresivo 'min' (3 caracteres). | Se recomienda utilizar identificadores más descriptivos del dominio del problema. | No |
| `0x0001h` | `consola.h:82` | Identificador corto y poco expresivo 'max' (3 caracteres). | Se recomienda utilizar identificadores más descriptivos del dominio del problema. | No |
| `0x0001h` | `consola.h:82` | Identificador corto y poco expresivo 'min' (3 caracteres). | Se recomienda utilizar identificadores más descriptivos del dominio del problema. | No |

## Auditoría de Seguridad — Kaneda

✓ **Estado:** Código libre de llamadas del sistema restringidas o intentos de evasión de sandbox.

## Antipatrones Didácticos — Spunkmeyer

Se detectaron **29** observación(es) de antipatrones didácticos:

| Regla | Ubicación | Antipatrón | Diagnóstico | Sugerencia |
| :--- | :--- | :--- | :--- | :--- |
| `0x7001h` | `main.c:31` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x3002h` | `fecha.c:12` | **Retorno de puntero a variable local (Dangling Stack Pointer)** | Retorno de dirección de variable local '&var'. | Asigná memoria dinámica con malloc() o pasá el buffer como parámetro por referencia. |
| `0x3002h` | `fecha.c:53` | **Retorno de puntero a variable local (Dangling Stack Pointer)** | Retorno de dirección de variable local '&dia'. | Asigná memoria dinámica con malloc() o pasá el buffer como parámetro por referencia. |
| `0x301Fh` | `prueba.c:58` | **Comparación de igualdad estricta en punto flotante** | Comparación de igualdad estricta ('==') sobre tipo de coma flotante. | Compará con una tolerancia épsilon: 'fabs(a - b) < 0.00001'. |
| `0x301Fh` | `prueba.c:59` | **Comparación de igualdad estricta en punto flotante** | Comparación de igualdad estricta ('==') sobre tipo de coma flotante. | Compará con una tolerancia épsilon: 'fabs(a - b) < 0.00001'. |
| `0x301Fh` | `prueba.c:62` | **Comparación de igualdad estricta en punto flotante** | Comparación de igualdad estricta ('==') sobre tipo de coma flotante. | Compará con una tolerancia épsilon: 'fabs(a - b) < 0.00001'. |
| `0x301Fh` | `prueba.c:63` | **Comparación de igualdad estricta en punto flotante** | Comparación de igualdad estricta ('==') sobre tipo de coma flotante. | Compará con una tolerancia épsilon: 'fabs(a - b) < 0.00001'. |
| `0x301Fh` | `prueba.c:64` | **Comparación de igualdad estricta en punto flotante** | Comparación de igualdad estricta ('==') sobre tipo de coma flotante. | Compará con una tolerancia épsilon: 'fabs(a - b) < 0.00001'. |
| `0x301Fh` | `prueba.c:65` | **Comparación de igualdad estricta en punto flotante** | Comparación de igualdad estricta ('==') sobre tipo de coma flotante. | Compará con una tolerancia épsilon: 'fabs(a - b) < 0.00001'. |
| `0x301Fh` | `prueba.c:66` | **Comparación de igualdad estricta en punto flotante** | Comparación de igualdad estricta ('==') sobre tipo de coma flotante. | Compará con una tolerancia épsilon: 'fabs(a - b) < 0.00001'. |
| `0x301Fh` | `prueba.c:67` | **Comparación de igualdad estricta en punto flotante** | Comparación de igualdad estricta ('==') sobre tipo de coma flotante. | Compará con una tolerancia épsilon: 'fabs(a - b) < 0.00001'. |
| `0x301Fh` | `prueba.c:70` | **Comparación de igualdad estricta en punto flotante** | Comparación de igualdad estricta ('==') sobre tipo de coma flotante. | Compará con una tolerancia épsilon: 'fabs(a - b) < 0.00001'. |
| `0x301Fh` | `prueba.c:71` | **Comparación de igualdad estricta en punto flotante** | Comparación de igualdad estricta ('==') sobre tipo de coma flotante. | Compará con una tolerancia épsilon: 'fabs(a - b) < 0.00001'. |
| `0x301Fh` | `prueba.c:72` | **Comparación de igualdad estricta en punto flotante** | Comparación de igualdad estricta ('==') sobre tipo de coma flotante. | Compará con una tolerancia épsilon: 'fabs(a - b) < 0.00001'. |
| `0x301Fh` | `prueba.c:77` | **Comparación de igualdad estricta en punto flotante** | Comparación de igualdad estricta ('==') sobre tipo de coma flotante. | Compará con una tolerancia épsilon: 'fabs(a - b) < 0.00001'. |
| `0x301Fh` | `prueba.c:78` | **Comparación de igualdad estricta en punto flotante** | Comparación de igualdad estricta ('==') sobre tipo de coma flotante. | Compará con una tolerancia épsilon: 'fabs(a - b) < 0.00001'. |
| `0x301Fh` | `prueba.c:79` | **Comparación de igualdad estricta en punto flotante** | Comparación de igualdad estricta ('==') sobre tipo de coma flotante. | Compará con una tolerancia épsilon: 'fabs(a - b) < 0.00001'. |
| `0x301Fh` | `prueba.c:80` | **Comparación de igualdad estricta en punto flotante** | Comparación de igualdad estricta ('==') sobre tipo de coma flotante. | Compará con una tolerancia épsilon: 'fabs(a - b) < 0.00001'. |
| `0x301Fh` | `prueba.c:81` | **Comparación de igualdad estricta en punto flotante** | Comparación de igualdad estricta ('==') sobre tipo de coma flotante. | Compará con una tolerancia épsilon: 'fabs(a - b) < 0.00001'. |
| `0x7001h` | `cajero.c:26` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `cajero.c:43` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `prueba.c:114` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `prueba.c:152` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `prueba.c:190` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `consola.c:62` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `consola.c:92` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `consola.c:121` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x7001h` | `consola.c:149` | **Declaración de variable mezclada tras sentencias ejecutables** | Declaración de variable posterior a sentencias ejecutables dentro del mismo bloque. | Agrupá las declaraciones al comienzo del bloque de la función. |
| `0x1005h` | `consola.c:178` | **Comparación booleana explícita redundante** | Comparar explícitamente 'if (cond == 1)' o 'if (cond == true)' es redundante. | Escribí 'if (cond)' o 'if (!cond)' directamente. |

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
- **Ubicación:** `prueba.c:58`
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
- **Ubicación:** `prueba.c:59`
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
- **Ubicación:** `prueba.c:62`
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
- **Ubicación:** `prueba.c:63`
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
- **Ubicación:** `prueba.c:64`
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
- **Ubicación:** `prueba.c:65`
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
- **Ubicación:** `prueba.c:66`
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
- **Ubicación:** `prueba.c:67`
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
- **Ubicación:** `prueba.c:70`
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
- **Ubicación:** `prueba.c:71`
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
- **Ubicación:** `prueba.c:72`
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
- **Ubicación:** `prueba.c:77`
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
- **Ubicación:** `prueba.c:78`
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
- **Ubicación:** `prueba.c:79`
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
- **Ubicación:** `prueba.c:80`
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
- **Ubicación:** `prueba.c:81`
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
- **Ubicación:** `cajero.c:26`
```c
    int cantidad = 0;
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
- **Ubicación:** `cajero.c:43`
```c
    int resto = 0;
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
- **Ubicación:** `consola.c:62`
```c
    int resultado;
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
- **Ubicación:** `consola.c:92`
```c
    bool rango;
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
- **Ubicación:** `consola.c:121`
```c
    float valor;
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
- **Ubicación:** `consola.c:149`
```c
    bool rango;
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
- **Ubicación:** `consola.c:178`
```c
    if (scanf(" %c", &caracter) == 1)
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

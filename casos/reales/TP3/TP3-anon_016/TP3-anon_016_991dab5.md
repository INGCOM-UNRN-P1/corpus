# Informe de Corrección — TP3 (991dab5)

## Repositorio
**branch/revision:** `main` `991dab5`
**Commit SHA:** `991dab545eaa991b58e61fbc18bdb0490be01c99`
**Autor:** `anon_016`
**Fecha del commit:** `2026-09-23 00:35:42 -0300`
**Mensaje:** `tp 3 terminado`
**Fecha de evaluación:** 2026-09-28 10:30:17
**Versión revisada:** `991dab5`

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
│   │   ├── Makefile
│   │   ├── prueba.c
│   │   ├── prueba.o
│   │   └── test_bin
│   ├── ejercicio2/
│   │   ├── estadistica.c
│   │   ├── estadistica.h
│   │   ├── estadistica.o
│   │   ├── main.c
│   │   ├── Makefile
│   │   ├── prueba.c
│   │   ├── prueba.o
│   │   └── test_bin
│   ├── ejercicio3/
│   │   ├── main.c
│   │   ├── Makefile
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
│   │   ├── Makefile
│   │   ├── prueba.c
│   │   ├── prueba.o
│   │   └── test_bin
│   ├── ejercicio5/
│   │   ├── main.c
│   │   ├── Makefile
│   │   ├── prueba.c
│   │   ├── prueba.o
│   │   ├── puntero_cadena.c
│   │   ├── puntero_cadena.h
│   │   ├── puntero_cadena.o
│   │   └── test_bin
│   └── ejercicio6/
│       ├── main.c
│       ├── Makefile
│       ├── ordenamiento.c
│       ├── ordenamiento.h
│       ├── ordenamiento.o
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
| `[ARCHIVOS_BINARIOS]` | ❌ ERROR (27 filtrados) | 0.0/10 | — | Se detectaron binarios prohibidos (.o/.exe) en la entrega |
| `busqueda.c` | ❌ Falló Compilación | 9.0/10 | ✓ Limpio (0 fugas) | 18 advertencias |
| `busqueda.h` | ❌ Falló Compilación | 5.5/10 | ✓ Limpio (0 fugas) | 9 advertencias |
| `ejercicios/ejercicio1/intercambio.o` | ❌ Falló Compilación | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `ejercicios/ejercicio1/prueba.o` | ❌ Falló Compilación | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `ejercicios/ejercicio1/test_bin` | ❌ Falló Compilación | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `ejercicios/ejercicio2/estadistica.o` | ❌ Falló Compilación | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `ejercicios/ejercicio2/prueba.o` | ❌ Falló Compilación | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `ejercicios/ejercicio2/test_bin` | ❌ Falló Compilación | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `ejercicios/ejercicio3/prueba.o` | ❌ Falló Compilación | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `ejercicios/ejercicio3/recorrido.o` | ❌ Falló Compilación | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `ejercicios/ejercicio3/test_bin` | ❌ Falló Compilación | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `ejercicios/ejercicio4/busqueda.o` | ❌ Falló Compilación | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `ejercicios/ejercicio4/prueba.o` | ❌ Falló Compilación | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `ejercicios/ejercicio4/test_bin` | ❌ Falló Compilación | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `ejercicios/ejercicio5/prueba.o` | ❌ Falló Compilación | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `ejercicios/ejercicio5/puntero_cadena.o` | ❌ Falló Compilación | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `ejercicios/ejercicio5/test_bin` | ❌ Falló Compilación | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `ejercicios/ejercicio6/ordenamiento.o` | ❌ Falló Compilación | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `ejercicios/ejercicio6/prueba.o` | ❌ Falló Compilación | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `ejercicios/ejercicio6/test_bin` | ❌ Falló Compilación | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `estadistica.c` | ❌ Falló Compilación | 7.5/10 | ✓ Limpio (0 fugas) | 32 advertencias |
| `estadistica.h` | ❌ Falló Compilación | 8.0/10 | ✓ Limpio (0 fugas) | 4 advertencias |
| `intercambio.c` | ❌ Falló Compilación | 7.5/10 | ✓ Limpio (0 fugas) | 16 advertencias |
| `intercambio.h` | ❌ Falló Compilación | 7.5/10 | ✓ Limpio (0 fugas) | 5 advertencias |
| `libs/p1_test/build/libp1_test.a` | ❌ Falló Compilación | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `libs/p1_test/build/p1_test.o` | ❌ Falló Compilación | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `libs/p1_test/libp1_test.a` | ❌ Falló Compilación | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `libs/p1_test/prueba.o` | ❌ Falló Compilación | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `libs/p1_test/test_bin` | ❌ Falló Compilación | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `libs/punteros/libpunteros.a` | ❌ Falló Compilación | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `libs/punteros/prueba.o` | ❌ Falló Compilación | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `libs/punteros/punteros.o` | ❌ Falló Compilación | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `libs/punteros/test_bin` | ❌ Falló Compilación | 10.0/10 | ✓ Limpio (0 fugas) | 1 advertencias |
| `main.c` | ❌ Falló Compilación | 6.0/10 | ✓ Limpio (0 fugas) | 92 advertencias |
| `ordenamiento.c` | ❌ Falló Compilación | 8.5/10 | ✓ Limpio (0 fugas) | 19 advertencias |
| `ordenamiento.h` | ❌ Falló Compilación | 7.5/10 | ✓ Limpio (0 fugas) | 5 advertencias |
| `prueba.c` | ❌ Falló Compilación | 0.0/10 | ✓ Limpio (0 fugas) | 96 advertencias |
| `puntero_cadena.c` | ❌ Falló Compilación | 9.5/10 | ✓ Limpio (0 fugas) | 37 advertencias |
| `puntero_cadena.h` | ❌ Falló Compilación | 4.0/10 | ✓ Limpio (0 fugas) | 12 advertencias |
| `punteros.c` | ❌ Falló Compilación | 9.0/10 | ✓ Limpio (0 fugas) | 18 advertencias |
| `punteros.h` | ❌ Falló Compilación | 7.5/10 | ✓ Limpio (0 fugas) | 5 advertencias |
| `recorrido.c` | ❌ Falló Compilación | 8.5/10 | ✓ Limpio (0 fugas) | 26 advertencias |
| `recorrido.h` | ❌ Falló Compilación | 8.5/10 | ✓ Limpio (0 fugas) | 3 advertencias |

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
| `ejercicios/ejercicio1/prueba.o` | `0x000Fh` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'ejercicios/ejercicio1/prueba.o' (Extensión binaria prohibida '.o'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `ejercicios/ejercicio1/intercambio.o` | `0x000Fh` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'ejercicios/ejercicio1/intercambio.o' (Extensión binaria prohibida '.o'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `ejercicios/ejercicio1/test_bin` | `0x000Fh` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'ejercicios/ejercicio1/test_bin' (Firma binaria ejecutable detectada (Formato ejecutable o archivo objeto Linux ELF)). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `ejercicios/ejercicio2/prueba.o` | `0x000Fh` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'ejercicios/ejercicio2/prueba.o' (Extensión binaria prohibida '.o'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `ejercicios/ejercicio2/estadistica.o` | `0x000Fh` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'ejercicios/ejercicio2/estadistica.o' (Extensión binaria prohibida '.o'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `ejercicios/ejercicio2/test_bin` | `0x000Fh` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'ejercicios/ejercicio2/test_bin' (Firma binaria ejecutable detectada (Formato ejecutable o archivo objeto Linux ELF)). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `ejercicios/ejercicio3/prueba.o` | `0x000Fh` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'ejercicios/ejercicio3/prueba.o' (Extensión binaria prohibida '.o'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `ejercicios/ejercicio3/recorrido.o` | `0x000Fh` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'ejercicios/ejercicio3/recorrido.o' (Extensión binaria prohibida '.o'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `ejercicios/ejercicio3/test_bin` | `0x000Fh` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'ejercicios/ejercicio3/test_bin' (Firma binaria ejecutable detectada (Formato ejecutable o archivo objeto Linux ELF)). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `ejercicios/ejercicio4/prueba.o` | `0x000Fh` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'ejercicios/ejercicio4/prueba.o' (Extensión binaria prohibida '.o'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `ejercicios/ejercicio4/busqueda.o` | `0x000Fh` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'ejercicios/ejercicio4/busqueda.o' (Extensión binaria prohibida '.o'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `ejercicios/ejercicio4/test_bin` | `0x000Fh` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'ejercicios/ejercicio4/test_bin' (Firma binaria ejecutable detectada (Formato ejecutable o archivo objeto Linux ELF)). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `ejercicios/ejercicio5/prueba.o` | `0x000Fh` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'ejercicios/ejercicio5/prueba.o' (Extensión binaria prohibida '.o'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `ejercicios/ejercicio5/puntero_cadena.o` | `0x000Fh` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'ejercicios/ejercicio5/puntero_cadena.o' (Extensión binaria prohibida '.o'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `ejercicios/ejercicio5/test_bin` | `0x000Fh` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'ejercicios/ejercicio5/test_bin' (Firma binaria ejecutable detectada (Formato ejecutable o archivo objeto Linux ELF)). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `ejercicios/ejercicio6/prueba.o` | `0x000Fh` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'ejercicios/ejercicio6/prueba.o' (Extensión binaria prohibida '.o'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `ejercicios/ejercicio6/ordenamiento.o` | `0x000Fh` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'ejercicios/ejercicio6/ordenamiento.o' (Extensión binaria prohibida '.o'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `ejercicios/ejercicio6/test_bin` | `0x000Fh` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'ejercicios/ejercicio6/test_bin' (Firma binaria ejecutable detectada (Formato ejecutable o archivo objeto Linux ELF)). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |

**Acción Requerida:** Las entregas deben contener exclusivamente código fuente editable (`.c`, `.h`), archivos de configuración (`Makefile`) y documentación (`.md`, `.txt`). Ejecutá `make clean` antes de comprimir tu entrega y verificá tu archivo `.gitignore`.

## Compilación — Makefile raíz del Proyecto

❌ **Estado:** Falló la compilación mediante el Makefile de la raíz.

```text
main.c: In function ‘main’:
main.c:17:3: error: implicit declaration of function ‘ordenar_par’ [-Wimplicit-function-declaration]
   17 |   ordenar_par(&x, &y);
      |   ^~~~~~~~~~~
main.c:22:3: error: implicit declaration of function ‘probar_tria’ [-Wimplicit-function-declaration]
   22 |   probar_tria(1, 2, 3);
      |   ^~~~~~~~~~~
main.c:32:7: error: implicit declaration of function ‘sumar_acumulado’ [-Wimplicit-function-declaration]
   32 |   if (sumar_acumulado(datos, 5, &resultado))
      |       ^~~~~~~~~~~~~~~
make[1]: *** [Makefile:47: main.o] Error 1
make: *** [Makefile:24: ejercicios/ejercicio1] Error 1

```

> 📄 **Salida completa:** registrada en `compilacion_991dab5.log`.

## Observaciones de Calidad y Reglas P1 (Linter AST / Ripley)

Se detectaron **266** observación(es) en el código C:

| Regla | Ubicación | Severidad | Observación | Sugerencia |
| :--- | :--- | :---: | :--- | :--- |
| `0xEEEEh` | `intercambio.c:26` | ESTILO | Indentación no es múltiplo de 4 espacios (2 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `intercambio.c:27` | ESTILO | Indentación no es múltiplo de 4 espacios (2 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `intercambio.c:28` | ESTILO | Indentación no es múltiplo de 4 espacios (2 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0x0004h` | `intercambio.c:1` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `intercambio.c:3` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0002h` | `intercambio.c:8` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `intercambio.c:17` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `intercambio.c:32` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0xEEEEh` | `main.c:12` | ESTILO | Indentación no es múltiplo de 4 espacios (2 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `main.c:14` | ESTILO | Indentación no es múltiplo de 4 espacios (2 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `main.c:15` | ESTILO | Indentación no es múltiplo de 4 espacios (2 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `main.c:16` | ESTILO | Indentación no es múltiplo de 4 espacios (2 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `main.c:17` | ESTILO | Indentación no es múltiplo de 4 espacios (2 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `main.c:18` | ESTILO | Indentación no es múltiplo de 4 espacios (2 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `main.c:21` | ESTILO | Indentación no es múltiplo de 4 espacios (2 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `main.c:22` | ESTILO | Indentación no es múltiplo de 4 espacios (2 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `main.c:23` | ESTILO | Indentación no es múltiplo de 4 espacios (2 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `main.c:24` | ESTILO | Indentación no es múltiplo de 4 espacios (2 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `main.c:27` | ESTILO | Indentación no es múltiplo de 4 espacios (2 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `main.c:29` | ESTILO | Indentación no es múltiplo de 4 espacios (2 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `main.c:30` | ESTILO | Indentación no es múltiplo de 4 espacios (2 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `main.c:32` | ESTILO | Indentación no es múltiplo de 4 espacios (2 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `main.c:33` | ESTILO | Indentación no es múltiplo de 4 espacios (2 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `main.c:35` | ESTILO | Indentación no es múltiplo de 4 espacios (2 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `main.c:37` | ESTILO | Indentación no es múltiplo de 4 espacios (2 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0x0004h` | `main.c:1` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:16` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:17` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:18` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
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
| `0xEEEEh` | `estadistica.c:16` | ESTILO | Indentación no es múltiplo de 4 espacios (2 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `estadistica.c:18` | ESTILO | Indentación no es múltiplo de 4 espacios (2 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `estadistica.c:20` | ESTILO | Indentación no es múltiplo de 4 espacios (2 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `estadistica.c:22` | ESTILO | Indentación no es múltiplo de 4 espacios (2 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `estadistica.c:23` | ESTILO | Indentación no es múltiplo de 4 espacios (2 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `estadistica.c:25` | ESTILO | Indentación no es múltiplo de 4 espacios (2 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `estadistica.c:27` | ESTILO | Indentación no es múltiplo de 4 espacios (2 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `estadistica.c:28` | ESTILO | Indentación no es múltiplo de 4 espacios (2 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `estadistica.c:29` | ESTILO | Indentación no es múltiplo de 4 espacios (2 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `estadistica.c:31` | ESTILO | Indentación no es múltiplo de 4 espacios (2 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `estadistica.c:32` | ESTILO | Indentación no es múltiplo de 4 espacios (2 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `estadistica.c:35` | ESTILO | Indentación no es múltiplo de 4 espacios (2 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `estadistica.c:39` | ESTILO | Indentación no es múltiplo de 4 espacios (2 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `estadistica.c:44` | ESTILO | Indentación no es múltiplo de 4 espacios (2 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `estadistica.c:45` | ESTILO | Indentación no es múltiplo de 4 espacios (2 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `estadistica.c:47` | ESTILO | Indentación no es múltiplo de 4 espacios (2 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `estadistica.c:54` | ESTILO | Indentación no es múltiplo de 4 espacios (7 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `estadistica.c:55` | ESTILO | Indentación no es múltiplo de 4 espacios (7 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `estadistica.c:57` | ESTILO | Indentación no es múltiplo de 4 espacios (7 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `estadistica.c:58` | ESTILO | Indentación no es múltiplo de 4 espacios (7 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0x0004h` | `estadistica.c:1` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `estadistica.c:6` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0002h` | `estadistica.c:14` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0002h` | `estadistica.c:42` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `estadistica.c:54` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0xEEEEh` | `main.c:13` | ESTILO | Indentación no es múltiplo de 4 espacios (2 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `main.c:14` | ESTILO | Indentación no es múltiplo de 4 espacios (2 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `main.c:16` | ESTILO | Indentación no es múltiplo de 4 espacios (2 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `main.c:17` | ESTILO | Indentación no es múltiplo de 4 espacios (2 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `main.c:18` | ESTILO | Indentación no es múltiplo de 4 espacios (2 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `main.c:20` | ESTILO | Indentación no es múltiplo de 4 espacios (2 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `main.c:22` | ESTILO | Indentación no es múltiplo de 4 espacios (2 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `main.c:23` | ESTILO | Indentación no es múltiplo de 4 espacios (2 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `main.c:27` | ESTILO | Indentación no es múltiplo de 4 espacios (2 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `main.c:28` | ESTILO | Indentación no es múltiplo de 4 espacios (2 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `main.c:29` | ESTILO | Indentación no es múltiplo de 4 espacios (2 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `main.c:31` | ESTILO | Indentación no es múltiplo de 4 espacios (2 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `main.c:33` | ESTILO | Indentación no es múltiplo de 4 espacios (2 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `main.c:34` | ESTILO | Indentación no es múltiplo de 4 espacios (2 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `main.c:35` | ESTILO | Indentación no es múltiplo de 4 espacios (2 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `main.c:37` | ESTILO | Indentación no es múltiplo de 4 espacios (2 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `main.c:38` | ESTILO | Indentación no es múltiplo de 4 espacios (2 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `main.c:40` | ESTILO | Indentación no es múltiplo de 4 espacios (11 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `main.c:41` | ESTILO | Indentación no es múltiplo de 4 espacios (2 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `main.c:42` | ESTILO | Indentación no es múltiplo de 4 espacios (2 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `main.c:43` | ESTILO | Indentación no es múltiplo de 4 espacios (2 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `main.c:45` | ESTILO | Indentación no es múltiplo de 4 espacios (2 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0x0004h` | `main.c:1` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:39` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:1` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `prueba.c:11` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0002h` | `prueba.c:12` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0002h` | `prueba.c:57` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `prueba.c:57` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0xEEEEh` | `main.c:43` | ESTILO | Indentación no es múltiplo de 4 espacios (7 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0x0004h` | `main.c:17` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:28` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:46` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:1` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:22` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `prueba.c:53` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `prueba.c:53` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0xEEEEh` | `recorrido.c:12` | ESTILO | Indentación no es múltiplo de 4 espacios (2 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `recorrido.c:13` | ESTILO | Indentación no es múltiplo de 4 espacios (5 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `recorrido.c:15` | ESTILO | Indentación no es múltiplo de 4 espacios (6 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `recorrido.c:17` | ESTILO | Indentación no es múltiplo de 4 espacios (2 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `recorrido.c:18` | ESTILO | Indentación no es múltiplo de 4 espacios (2 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `recorrido.c:20` | ESTILO | Indentación no es múltiplo de 4 espacios (2 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `recorrido.c:21` | ESTILO | Indentación no es múltiplo de 4 espacios (2 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `recorrido.c:25` | ESTILO | Indentación no es múltiplo de 4 espacios (2 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `recorrido.c:26` | ESTILO | Indentación no es múltiplo de 4 espacios (2 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `recorrido.c:32` | ESTILO | Indentación no es múltiplo de 4 espacios (2 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `recorrido.c:34` | ESTILO | Indentación no es múltiplo de 4 espacios (6 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `recorrido.c:36` | ESTILO | Indentación no es múltiplo de 4 espacios (2 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `recorrido.c:37` | ESTILO | Indentación no es múltiplo de 4 espacios (2 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `recorrido.c:39` | ESTILO | Indentación no es múltiplo de 4 espacios (2 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `recorrido.c:40` | ESTILO | Indentación no es múltiplo de 4 espacios (2 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `recorrido.c:44` | ESTILO | Indentación no es múltiplo de 4 espacios (2 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `recorrido.c:45` | ESTILO | Indentación no es múltiplo de 4 espacios (2 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0x0004h` | `recorrido.c:1` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `recorrido.c:3` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0002h` | `recorrido.c:10` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `recorrido.c:32` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0xEEEEh` | `busqueda.c:17` | ESTILO | Indentación no es múltiplo de 4 espacios (3 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `busqueda.c:18` | ESTILO | Indentación no es múltiplo de 4 espacios (3 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `busqueda.c:19` | ESTILO | Indentación no es múltiplo de 4 espacios (3 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `busqueda.c:20` | ESTILO | Indentación no es múltiplo de 4 espacios (3 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `busqueda.c:21` | ESTILO | Indentación no es múltiplo de 4 espacios (5 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `busqueda.c:22` | ESTILO | Indentación no es múltiplo de 4 espacios (5 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `busqueda.c:23` | ESTILO | Indentación no es múltiplo de 4 espacios (9 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `busqueda.c:24` | ESTILO | Indentación no es múltiplo de 4 espacios (5 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `busqueda.c:25` | ESTILO | Indentación no es múltiplo de 4 espacios (5 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `busqueda.c:26` | ESTILO | Indentación no es múltiplo de 4 espacios (3 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `busqueda.c:32` | ESTILO | Indentación no es múltiplo de 4 espacios (5 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `busqueda.c:39` | ESTILO | Indentación no es múltiplo de 4 espacios (5 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0x0004h` | `busqueda.c:1` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `busqueda.c:10` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `busqueda.c:21` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0xEEEEh` | `main.c:26` | ESTILO | Indentación no es múltiplo de 4 espacios (5 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `main.c:33` | ESTILO | Indentación no es múltiplo de 4 espacios (9 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0x0004h` | `main.c:1` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:21` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `main.c:33` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `prueba.c:1` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `prueba.c:18` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `prueba.c:47` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:48` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:49` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `prueba.c:52` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `prueba.c:52` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0xEEEEh` | `main.c:15` | ESTILO | Indentación no es múltiplo de 4 espacios (9 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `main.c:18` | ESTILO | Indentación no es múltiplo de 4 espacios (5 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `main.c:20` | ESTILO | Indentación no es múltiplo de 4 espacios (9 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `main.c:25` | ESTILO | Indentación no es múltiplo de 4 espacios (9 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `main.c:30` | ESTILO | Indentación no es múltiplo de 4 espacios (9 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0x0004h` | `main.c:1` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:14` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:19` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:24` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:29` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:1` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `prueba.c:16` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0002h` | `prueba.c:35` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0002h` | `prueba.c:52` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `prueba.c:52` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0xEEEEh` | `puntero_cadena.c:11` | ESTILO | Indentación no es múltiplo de 4 espacios (3 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `puntero_cadena.c:12` | ESTILO | Indentación no es múltiplo de 4 espacios (3 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `puntero_cadena.c:14` | ESTILO | Indentación no es múltiplo de 4 espacios (3 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `puntero_cadena.c:16` | ESTILO | Indentación no es múltiplo de 4 espacios (3 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `puntero_cadena.c:17` | ESTILO | Indentación no es múltiplo de 4 espacios (3 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `puntero_cadena.c:18` | ESTILO | Indentación no es múltiplo de 4 espacios (3 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `puntero_cadena.c:20` | ESTILO | Indentación no es múltiplo de 4 espacios (3 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `puntero_cadena.c:21` | ESTILO | Indentación no es múltiplo de 4 espacios (3 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `puntero_cadena.c:23` | ESTILO | Indentación no es múltiplo de 4 espacios (5 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `puntero_cadena.c:24` | ESTILO | Indentación no es múltiplo de 4 espacios (5 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `puntero_cadena.c:25` | ESTILO | Indentación no es múltiplo de 4 espacios (3 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `puntero_cadena.c:26` | ESTILO | Indentación no es múltiplo de 4 espacios (3 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `puntero_cadena.c:27` | ESTILO | Indentación no es múltiplo de 4 espacios (3 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `puntero_cadena.c:29` | ESTILO | Indentación no es múltiplo de 4 espacios (3 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `puntero_cadena.c:33` | ESTILO | Indentación no es múltiplo de 4 espacios (3 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `puntero_cadena.c:46` | ESTILO | Indentación no es múltiplo de 4 espacios (3 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `puntero_cadena.c:47` | ESTILO | Indentación no es múltiplo de 4 espacios (3 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `puntero_cadena.c:48` | ESTILO | Indentación no es múltiplo de 4 espacios (5 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `puntero_cadena.c:49` | ESTILO | Indentación no es múltiplo de 4 espacios (3 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `puntero_cadena.c:50` | ESTILO | Indentación no es múltiplo de 4 espacios (3 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `puntero_cadena.c:51` | ESTILO | Indentación no es múltiplo de 4 espacios (3 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `puntero_cadena.c:53` | ESTILO | Indentación no es múltiplo de 4 espacios (5 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `puntero_cadena.c:54` | ESTILO | Indentación no es múltiplo de 4 espacios (5 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `puntero_cadena.c:55` | ESTILO | Indentación no es múltiplo de 4 espacios (3 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `puntero_cadena.c:56` | ESTILO | Indentación no es múltiplo de 4 espacios (3 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `puntero_cadena.c:57` | ESTILO | Indentación no es múltiplo de 4 espacios (3 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `puntero_cadena.c:60` | ESTILO | Indentación no es múltiplo de 4 espacios (3 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `puntero_cadena.c:62` | ESTILO | Indentación no es múltiplo de 4 espacios (3 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0x0004h` | `puntero_cadena.c:1` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `puntero_cadena.c:9` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `puntero_cadena.c:20` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `puntero_cadena.c:26` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `puntero_cadena.c:36` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `puntero_cadena.c:46` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `puntero_cadena.c:50` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `puntero_cadena.c:56` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0xEEEEh` | `main.c:11` | ESTILO | Indentación no es múltiplo de 4 espacios (2 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `main.c:12` | ESTILO | Indentación no es múltiplo de 4 espacios (2 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `main.c:14` | ESTILO | Indentación no es múltiplo de 4 espacios (2 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `main.c:15` | ESTILO | Indentación no es múltiplo de 4 espacios (2 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `main.c:20` | ESTILO | Indentación no es múltiplo de 4 espacios (2 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `main.c:22` | ESTILO | Indentación no es múltiplo de 4 espacios (2 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `main.c:23` | ESTILO | Indentación no es múltiplo de 4 espacios (2 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `main.c:25` | ESTILO | Indentación no es múltiplo de 4 espacios (2 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `main.c:26` | ESTILO | Indentación no es múltiplo de 4 espacios (2 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `main.c:28` | ESTILO | Indentación no es múltiplo de 4 espacios (2 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `main.c:30` | ESTILO | Indentación no es múltiplo de 4 espacios (2 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `main.c:31` | ESTILO | Indentación no es múltiplo de 4 espacios (2 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `main.c:33` | ESTILO | Indentación no es múltiplo de 4 espacios (2 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `main.c:34` | ESTILO | Indentación no es múltiplo de 4 espacios (2 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `main.c:35` | ESTILO | Indentación no es múltiplo de 4 espacios (2 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `main.c:37` | ESTILO | Indentación no es múltiplo de 4 espacios (2 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0x0004h` | `main.c:1` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:13` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `main.c:34` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0xEEEEh` | `ordenamiento.c:16` | ESTILO | Indentación no es múltiplo de 4 espacios (3 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `ordenamiento.c:18` | ESTILO | Indentación no es múltiplo de 4 espacios (3 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `ordenamiento.c:19` | ESTILO | Indentación no es múltiplo de 4 espacios (3 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `ordenamiento.c:22` | ESTILO | Indentación no es múltiplo de 4 espacios (11 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `ordenamiento.c:24` | ESTILO | Indentación no es múltiplo de 4 espacios (5 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `ordenamiento.c:25` | ESTILO | Indentación no es múltiplo de 4 espacios (3 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `ordenamiento.c:26` | ESTILO | Indentación no es múltiplo de 4 espacios (3 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `ordenamiento.c:35` | ESTILO | Indentación no es múltiplo de 4 espacios (7 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `ordenamiento.c:37` | ESTILO | Indentación no es múltiplo de 4 espacios (7 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `ordenamiento.c:38` | ESTILO | Indentación no es múltiplo de 4 espacios (7 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `ordenamiento.c:40` | ESTILO | Indentación no es múltiplo de 4 espacios (6 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `ordenamiento.c:44` | ESTILO | Indentación no es múltiplo de 4 espacios (6 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0x0004h` | `ordenamiento.c:1` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `ordenamiento.c:20` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0xEEEEh` | `prueba.c:61` | ESTILO | Indentación no es múltiplo de 4 espacios (5 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0x0004h` | `prueba.c:1` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:18` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:24` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:29` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `prueba.c:58` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `prueba.c:58` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:1` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:17` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:24` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:26` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:30` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:37` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `prueba.c:49` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `prueba.c:70` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `prueba.c:70` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0xEEEEh` | `punteros.c:41` | ESTILO | Indentación no es múltiplo de 4 espacios (7 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `punteros.c:42` | ESTILO | Indentación no es múltiplo de 4 espacios (7 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `punteros.c:44` | ESTILO | Indentación no es múltiplo de 4 espacios (7 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `punteros.c:53` | ESTILO | Indentación no es múltiplo de 4 espacios (7 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `punteros.c:54` | ESTILO | Indentación no es múltiplo de 4 espacios (7 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `punteros.c:56` | ESTILO | Indentación no es múltiplo de 4 espacios (7 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `punteros.c:57` | ESTILO | Indentación no es múltiplo de 4 espacios (7 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `punteros.c:58` | ESTILO | Indentación no es múltiplo de 4 espacios (6 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `punteros.c:60` | ESTILO | Indentación no es múltiplo de 4 espacios (6 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0xEEEEh` | `punteros.c:61` | ESTILO | Indentación no es múltiplo de 4 espacios (6 encontrados). | Ajustar indentación a múltiplos de 4 espacios. |
| `0x0004h` | `punteros.c:1` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0002h` | `punteros.c:9` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0002h` | `punteros.c:38` | ADVERTENCIA | Se encontraron múltiples declaraciones de variables en una sola línea. | Declarar cada variable en una línea independiente. |
| `0x0004h` | `punteros.c:53` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |
| `0x0004h` | `punteros.c:57` | ESTILO | Falta espacio antes y después de un operador. | Separar operadores con espacios (ej. 'a + b'). |

## Pruebas del Proyecto — Makefile raíz (`make test`)

✓ **Estado:** Pruebas del proyecto aprobadas con éxito (`make test`).

## Auditoría de Memoria Dinámica — Valgrind

✓ **Estado:** No se detectaron fugas de memoria durante las pruebas en sandbox.

## Linter de Estilo y Formato — Gaff

⚠️ Se detectaron **103** observación(es) de estilo arquitectónico:

| Regla | Ubicación | Observación | Sugerencia | Autofix |
| :--- | :--- | :--- | :--- | :---: |
| `GAFF009` | `intercambio.c:3` | La línea tiene 84 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `intercambio.c:8` | La línea tiene 90 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `0x0001h` | `intercambio.c:24` | Identificador de variable no descriptivo de una sola letra 'a'. | Los nombres de variables deben reflejar con precisión su propósito (salvo índices canónicos i, j, k, n, x, y, z, f, c, r). | No |
| `0x0001h` | `intercambio.c:24` | Identificador de variable no descriptivo de una sola letra 'b'. | Los nombres de variables deben reflejar con precisión su propósito (salvo índices canónicos i, j, k, n, x, y, z, f, c, r). | No |
| `0x0001h` | `intercambio.c:40` | Identificador corto y poco expresivo 'fin' (3 caracteres). | Se recomienda utilizar identificadores más descriptivos del dominio del problema. | No |
| `GAFF009` | `intercambio.h:19` | La línea tiene 84 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `intercambio.h:35` | La línea tiene 92 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `intercambio.h:52` | La línea tiene 87 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `intercambio.h:55` | La línea tiene 81 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `intercambio.h:56` | La línea tiene 81 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `prueba.c:97` | La línea tiene 106 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `0x0001h` | `prueba.c:12` | Identificador de variable no descriptivo de una sola letra 'a'. | Los nombres de variables deben reflejar con precisión su propósito (salvo índices canónicos i, j, k, n, x, y, z, f, c, r). | No |
| `0x0001h` | `prueba.c:12` | Identificador de variable no descriptivo de una sola letra 'b'. | Los nombres de variables deben reflejar con precisión su propósito (salvo índices canónicos i, j, k, n, x, y, z, f, c, r). | No |
| `0x0001h` | `prueba.c:32` | Identificador corto y poco expresivo 'id1' (3 caracteres). | Se recomienda utilizar identificadores más descriptivos del dominio del problema. | No |
| `0x0001h` | `prueba.c:33` | Identificador corto y poco expresivo 'id2' (3 caracteres). | Se recomienda utilizar identificadores más descriptivos del dominio del problema. | No |
| `0x0001h` | `prueba.c:39` | Identificador corto y poco expresivo 'val' (3 caracteres). | Se recomienda utilizar identificadores más descriptivos del dominio del problema. | No |
| `0x0001h` | `prueba.c:49` | Identificador de variable no descriptivo de una sola letra 'a'. | Los nombres de variables deben reflejar con precisión su propósito (salvo índices canónicos i, j, k, n, x, y, z, f, c, r). | No |
| `0x0001h` | `prueba.c:49` | Identificador de variable no descriptivo de una sola letra 'b'. | Los nombres de variables deben reflejar con precisión su propósito (salvo índices canónicos i, j, k, n, x, y, z, f, c, r). | No |
| `0x0001h` | `prueba.c:63` | Identificador de variable no descriptivo de una sola letra 'd'. | Los nombres de variables deben reflejar con precisión su propósito (salvo índices canónicos i, j, k, n, x, y, z, f, c, r). | No |
| `0x0001h` | `prueba.c:63` | Identificador de variable no descriptivo de una sola letra 'e'. | Los nombres de variables deben reflejar con precisión su propósito (salvo índices canónicos i, j, k, n, x, y, z, f, c, r). | No |
| `0x0001h` | `prueba.c:70` | Identificador corto y poco expresivo 'v1' (2 caracteres). | Se recomienda utilizar identificadores más descriptivos del dominio del problema. | No |
| `0x0001h` | `prueba.c:70` | Identificador corto y poco expresivo 'v2' (2 caracteres). | Se recomienda utilizar identificadores más descriptivos del dominio del problema. | No |
| `GAFF009` | `estadistica.c:12` | La línea tiene 86 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `estadistica.c:14` | La línea tiene 107 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `estadistica.c:42` | La línea tiene 112 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `0x0001h` | `estadistica.c:29` | Identificador corto y poco expresivo 'fin' (3 caracteres). | Se recomienda utilizar identificadores más descriptivos del dominio del problema. | No |
| `0x0001h` | `estadistica.c:50` | Identificador corto y poco expresivo 'fin' (3 caracteres). | Se recomienda utilizar identificadores más descriptivos del dominio del problema. | No |
| `GAFF009` | `estadistica.h:12` | La línea tiene 82 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `estadistica.h:25` | La línea tiene 83 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `estadistica.h:47` | La línea tiene 82 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `estadistica.h:51` | La línea tiene 85 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `main.c:20` | La línea tiene 84 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `prueba.c:10` | La línea tiene 91 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `prueba.c:11` | La línea tiene 108 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `prueba.c:12` | La línea tiene 113 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `prueba.c:32` | La línea tiene 85 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `prueba.c:33` | La línea tiene 81 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `prueba.c:34` | La línea tiene 81 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `prueba.c:59` | La línea tiene 99 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `0x0001h` | `main.c:13` | Identificador corto y poco expresivo 'fin' (3 caracteres). | Se recomienda utilizar identificadores más descriptivos del dominio del problema. | No |
| `GAFF009` | `prueba.c:55` | La línea tiene 84 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `0x0001h` | `prueba.c:36` | Identificador corto y poco expresivo 'par' (3 caracteres). | Se recomienda utilizar identificadores más descriptivos del dominio del problema. | No |
| `GAFF009` | `recorrido.c:3` | La línea tiene 84 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `0x0001h` | `recorrido.c:18` | Identificador corto y poco expresivo 'fin' (3 caracteres). | Se recomienda utilizar identificadores más descriptivos del dominio del problema. | No |
| `0x0001h` | `recorrido.c:37` | Identificador corto y poco expresivo 'fin' (3 caracteres). | Se recomienda utilizar identificadores más descriptivos del dominio del problema. | No |
| `GAFF009` | `recorrido.h:15` | La línea tiene 81 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `recorrido.h:34` | La línea tiene 86 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `recorrido.h:53` | La línea tiene 81 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `busqueda.c:3` | La línea tiene 87 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `0x0001h` | `busqueda.c:18` | Identificador corto y poco expresivo 'fin' (3 caracteres). | Se recomienda utilizar identificadores más descriptivos del dominio del problema. | No |
| `GAFF009` | `busqueda.h:14` | La línea tiene 85 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `busqueda.h:15` | La línea tiene 88 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `busqueda.h:16` | La línea tiene 86 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `busqueda.h:17` | La línea tiene 86 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `busqueda.h:22` | La línea tiene 81 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `busqueda.h:35` | La línea tiene 81 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `busqueda.h:36` | La línea tiene 86 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `busqueda.h:55` | La línea tiene 81 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `busqueda.h:58` | La línea tiene 81 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `main.c:21` | La línea tiene 101 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `main.c:37` | La línea tiene 89 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `main.c:38` | La línea tiene 89 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `prueba.c:54` | La línea tiene 84 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `0x0001h` | `prueba.c:30` | Identificador corto y poco expresivo 'val' (3 caracteres). | Se recomienda utilizar identificadores más descriptivos del dominio del problema. | No |
| `GAFF009` | `main.c:19` | La línea tiene 89 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `main.c:24` | La línea tiene 92 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `main.c:29` | La línea tiene 99 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `prueba.c:23` | La línea tiene 87 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `prueba.c:42` | La línea tiene 88 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `prueba.c:54` | La línea tiene 84 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `puntero_cadena.c:36` | La línea tiene 81 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `puntero_cadena.h:8` | La línea tiene 84 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `puntero_cadena.h:14` | La línea tiene 86 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `puntero_cadena.h:17` | La línea tiene 81 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `puntero_cadena.h:18` | La línea tiene 89 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `puntero_cadena.h:35` | La línea tiene 90 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `puntero_cadena.h:36` | La línea tiene 85 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `puntero_cadena.h:37` | La línea tiene 82 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `puntero_cadena.h:38` | La línea tiene 93 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `puntero_cadena.h:58` | La línea tiene 92 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `puntero_cadena.h:62` | La línea tiene 81 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `puntero_cadena.h:63` | La línea tiene 81 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `puntero_cadena.h:66` | La línea tiene 82 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `ordenamiento.c:3` | La línea tiene 88 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `0x0001h` | `ordenamiento.c:8` | Identificador corto y poco expresivo 'fin' (3 caracteres). | Se recomienda utilizar identificadores más descriptivos del dominio del problema. | No |
| `0x0001h` | `ordenamiento.c:31` | Identificador corto y poco expresivo 'fin' (3 caracteres). | Se recomienda utilizar identificadores más descriptivos del dominio del problema. | No |
| `GAFF009` | `ordenamiento.h:15` | La línea tiene 81 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `ordenamiento.h:16` | La línea tiene 82 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `ordenamiento.h:35` | La línea tiene 81 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `ordenamiento.h:59` | La línea tiene 81 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `0x0001h` | `ordenamiento.h:62` | Identificador corto y poco expresivo 'fin' (3 caracteres). | Se recomienda utilizar identificadores más descriptivos del dominio del problema. | No |
| `GAFF009` | `prueba.c:60` | La línea tiene 84 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `prueba.c:72` | La línea tiene 84 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `0x0001h` | `prueba.c:22` | Identificador de variable no descriptivo de una sola letra 'a'. | Los nombres de variables deben reflejar con precisión su propósito (salvo índices canónicos i, j, k, n, x, y, z, f, c, r). | No |
| `0x0001h` | `prueba.c:23` | Identificador de variable no descriptivo de una sola letra 'b'. | Los nombres de variables deben reflejar con precisión su propósito (salvo índices canónicos i, j, k, n, x, y, z, f, c, r). | No |
| `0x0001h` | `prueba.c:34` | Identificador corto y poco expresivo 'val' (3 caracteres). | Se recomienda utilizar identificadores más descriptivos del dominio del problema. | No |
| `GAFF009` | `punteros.c:38` | La línea tiene 83 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `0x0001h` | `punteros.c:49` | Identificador corto y poco expresivo 'fin' (3 caracteres). | Se recomienda utilizar identificadores más descriptivos del dominio del problema. | No |
| `GAFF009` | `punteros.h:3` | La línea tiene 88 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `punteros.h:17` | La línea tiene 88 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `punteros.h:64` | La línea tiene 81 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `punteros.h:83` | La línea tiene 82 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |
| `GAFF009` | `punteros.h:97` | La línea tiene 84 caracteres (máximo 80). | Dividí la sentencia o expresión en múltiples líneas. | No |

## Auditoría de Seguridad — Sandbox / Kaneda

⚠️ **Alerta:** Se detectaron **27** llamadas o patrones de riesgo de seguridad:

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
| `0x000Fh` | `ejercicios/ejercicio1/prueba.o:1` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'ejercicios/ejercicio1/prueba.o' (Extensión binaria prohibida '.o'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `0x000Fh` | `ejercicios/ejercicio1/intercambio.o:1` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'ejercicios/ejercicio1/intercambio.o' (Extensión binaria prohibida '.o'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `0x000Fh` | `ejercicios/ejercicio1/test_bin:1` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'ejercicios/ejercicio1/test_bin' (Firma binaria ejecutable detectada (Formato ejecutable o archivo objeto Linux ELF)). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `0x000Fh` | `ejercicios/ejercicio2/prueba.o:1` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'ejercicios/ejercicio2/prueba.o' (Extensión binaria prohibida '.o'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `0x000Fh` | `ejercicios/ejercicio2/estadistica.o:1` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'ejercicios/ejercicio2/estadistica.o' (Extensión binaria prohibida '.o'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `0x000Fh` | `ejercicios/ejercicio2/test_bin:1` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'ejercicios/ejercicio2/test_bin' (Firma binaria ejecutable detectada (Formato ejecutable o archivo objeto Linux ELF)). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `0x000Fh` | `ejercicios/ejercicio3/prueba.o:1` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'ejercicios/ejercicio3/prueba.o' (Extensión binaria prohibida '.o'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `0x000Fh` | `ejercicios/ejercicio3/recorrido.o:1` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'ejercicios/ejercicio3/recorrido.o' (Extensión binaria prohibida '.o'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `0x000Fh` | `ejercicios/ejercicio3/test_bin:1` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'ejercicios/ejercicio3/test_bin' (Firma binaria ejecutable detectada (Formato ejecutable o archivo objeto Linux ELF)). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `0x000Fh` | `ejercicios/ejercicio4/prueba.o:1` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'ejercicios/ejercicio4/prueba.o' (Extensión binaria prohibida '.o'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `0x000Fh` | `ejercicios/ejercicio4/busqueda.o:1` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'ejercicios/ejercicio4/busqueda.o' (Extensión binaria prohibida '.o'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `0x000Fh` | `ejercicios/ejercicio4/test_bin:1` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'ejercicios/ejercicio4/test_bin' (Firma binaria ejecutable detectada (Formato ejecutable o archivo objeto Linux ELF)). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `0x000Fh` | `ejercicios/ejercicio5/prueba.o:1` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'ejercicios/ejercicio5/prueba.o' (Extensión binaria prohibida '.o'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `0x000Fh` | `ejercicios/ejercicio5/puntero_cadena.o:1` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'ejercicios/ejercicio5/puntero_cadena.o' (Extensión binaria prohibida '.o'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `0x000Fh` | `ejercicios/ejercicio5/test_bin:1` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'ejercicios/ejercicio5/test_bin' (Firma binaria ejecutable detectada (Formato ejecutable o archivo objeto Linux ELF)). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `0x000Fh` | `ejercicios/ejercicio6/prueba.o:1` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'ejercicios/ejercicio6/prueba.o' (Extensión binaria prohibida '.o'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `0x000Fh` | `ejercicios/ejercicio6/ordenamiento.o:1` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'ejercicios/ejercicio6/ordenamiento.o' (Extensión binaria prohibida '.o'). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |
| `0x000Fh` | `ejercicios/ejercicio6/test_bin:1` | **ERROR** | Se detectó y filtró el archivo binario prohibido 'ejercicios/ejercicio6/test_bin' (Firma binaria ejecutable detectada (Formato ejecutable o archivo objeto Linux ELF)). Las entregas deben contener exclusivamente código fuente editable y makefiles. | Eliminá todos los archivos binarios (.o, .a, .exe, etc.) antes de entregar. Ejecutá 'make clean' y agregá estas extensiones a tu .gitignore. |

## Antipatrones Didácticos — Spunkmeyer

✓ **Estado:** No se detectaron antipatrones pedagógicos conocidos.

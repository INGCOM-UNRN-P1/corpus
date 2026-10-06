## Pruebas Funcionales y Casos de Test — Sandbox

**Resultado general:** 0 / 19 pruebas aprobadas (0.0% de éxito).

| Caso de Prueba | Estado | Código Retorno | Fuga Memoria | Diagnóstico |
| :--- | :---: | :---: | :---: | :--- |
| `make_test` | **❌ FALLÓ** | `0` | ✓ NO | test_bin: prueba.c:8: probar_esta_en_rango_entero: Assertion `esta_en_rango_entero(10, 10, 20)' failed. |
| `consola / 01_ingreso_valido` | **❌ FALLÓ** | `0` | ✓ NO | Salida esperada: |
| `consola / 02_reintento_rango` | **❌ FALLÓ** | `0` | ✓ NO | Salida esperada: |
| `consola / 03_rechazo_logico` | **❌ FALLÓ** | `0` | ✓ NO | Salida esperada: |
| `ejercicio1 / 01_celsius_a_fahrenheit` | **❌ FALLÓ** | `0` | ✓ NO | Salida esperada: |
| `ejercicio1 / 02_fahrenheit_a_celsius` | **❌ FALLÓ** | `0` | ✓ NO | Salida esperada: |
| `ejercicio1 / 03_temperatura_negativa` | **❌ FALLÓ** | `0` | ✓ NO | Salida esperada: |
| `ejercicio2 / 01_positivos` | **❌ FALLÓ** | `0` | ✓ NO | Salida esperada: |
| `ejercicio2 / 02_negativos` | **❌ FALLÓ** | `0` | ✓ NO | Salida esperada: |
| `ejercicio2 / 03_un_elemento` | **❌ FALLÓ** | `0` | ✓ NO | Salida esperada: |
| `ejercicio3 / 01_fecha_valida_bisiesto` | **❌ FALLÓ** | `0` | ✓ NO | Salida esperada: |
| `ejercicio3 / 02_fecha_invalida_febrero` | **❌ FALLÓ** | `0` | ✓ NO | Salida esperada: |
| `ejercicio3 / 03_anio_secular_no_bisiesto` | **❌ FALLÓ** | `0` | ✓ NO | Salida esperada: |
| `ejercicio4 / 01_rectangulo_escaleno` | **❌ FALLÓ** | `0` | ✓ NO | Salida esperada: |
| `ejercicio4 / 02_equilatero` | **❌ FALLÓ** | `0` | ✓ NO | Salida esperada: |
| `ejercicio4 / 03_invalido_degenerado` | **❌ FALLÓ** | `0` | ✓ NO | Salida esperada: |
| `ejercicio5 / 01_extraccion_completa` | **❌ FALLÓ** | `0` | ✓ NO | Salida esperada: |
| `ejercicio5 / 02_extraccion_simple` | **❌ FALLÓ** | `0` | ✓ NO | Salida esperada: |
| `ejercicio5 / 03_monto_invalido` | **❌ FALLÓ** | `0` | ✓ NO | Salida esperada: |

### 🔍 Detalle de Casos de Prueba Fallidos

#### Caso: `make_test`
- **Error / Diagnóstico:** test_bin: prueba.c:8: probar_esta_en_rango_entero: Assertion `esta_en_rango_entero(10, 10, 20)' failed.
make[1]: *** [Makefile:43: test] Aborted (core dumped)
make: *** [Makefile:40: test] Error 1

#### Caso: `consola / 01_ingreso_valido`
- **Entrada (`stdin`):**
```text
25
1.75
s
```
- **Salida esperada:**
```text
--- Validacion de Consola ---
Ingrese edad (1-120): Edad: 25
Ingrese altura (0.50-2.50): Altura: 1.75 m
Confirmar registro (s/n): Registro: Confirmado
```
- **Salida obtenida:**
```text
Gestor del Trabajo Práctico (tp.sh)
Uso: ./tp.sh <comando> [argumentos]

Comandos disponibles:
  sync                            Sincroniza y regenera todos los Makefiles del proyecto.
  add-lib <nombre> [url-git]      Agrega una librería. Si pasás una URL de Git, la clona.
                                    Si no, crea una plantilla local.
  remove-lib <nombre>             Remueve una librería del proyecto.
  add-ex <nombre> [libs]          Agrega un ejercicio localmente. 'libs' es una lista de librerías
                                    separadas por comas (ej: arreglos,cadenas).
  remove-ex <nombre>              Remueve un ejercicio del proyecto.
  list                            Lista todas las librerías y ejercicios instalados.
  build                           Compila todo el proyecto.
  run [ejercicio]                 Ejecuta un ejercicio en particular o todos si no indicás nada.
  test [nombre]                   Ejecuta los tests de un ejercicio o librería específica,
                                    o de todo el proyecto si no indicás nada.
  help                            Muestra este mensaje de ayuda.
```
- **Diferencia (Diff):**
```diff
--- Esperado
+++ Obtenido
- --- Validacion de Consola ---
Ingrese edad (1-120): Edad: 25
Ingrese altura (0.50-2.50): Altura: 1.75 m
Confirmar registro (s/n): Registro: Confirmado
+ Gestor del Trabajo Práctico (tp.sh)
Uso: ./tp.sh <comando> [argumentos]

Comandos disponibles:
  sync                            Sincroniza y regenera todos los Makefiles del proyecto.
  add-lib <nombre> [url-git]      Agrega una librería. Si pasás una URL de Git, la clona.
                                    Si no, crea una plantilla local.
  remove-lib <nombre>             Remueve una librería del proyecto.
  add-ex <nombre> [libs]          Agrega un ejercicio localmente. 'libs' es una lista de librerías
                                    separadas por comas (ej: arreglos,cadenas).
  remove-ex <nombre>              Remueve un ejercicio del proyecto.
  list                            Lista todas las librerías y ejercicios instalados.
  build                           Compila todo el proyecto.
  run [ejercicio]                 Ejecuta un ejercicio en particular o todos si no indicás nada.
  test [nombre]                   Ejecuta los tests de un ejercicio o librería específica,
                                    o de todo el proyecto si no indicás nada.
  help                            Muestra este mensaje de ayuda.
```
- **Error / Diagnóstico:** Salida esperada:
--- Validacion de Consola ---
Ingrese edad (1-120): Edad: 25
Ingrese altura (0.50-2.50): Altura: 1.75 m
Confirmar registro (s/n): Registro: Confirmado
Obtenida:
Gestor del Trabajo Práctico (tp.sh)
Uso: ./tp.sh <comando> [argumentos]

Comandos disponibles:
  sync                            Sincroniza y regenera todos los Makefiles del proyecto.
  add-lib <nombre> [url-git]      Agrega una librería. Si pasás una URL de Git, la clona.
                                    Si no, crea una plantilla local.
  remove-lib <nombre>             Remueve una librería del proyecto.
  add-ex <nombre> [libs]          Agrega un ejercicio localmente. 'libs' es una lista de librerías
                                    separadas por comas (ej: arreglos,cadenas).
  remove-ex <nombre>              Remueve un ejercicio del proyecto.
  list                            Lista todas las librerías y ejercicios instalados.
  build                           Compila todo el proyecto.
  run [ejercicio]                 Ejecuta un ejercicio en particular o todos si no indicás nada.
  test [nombre]                   Ejecuta los tests de un ejercicio o librería específica,
                                    o de todo el proyecto si no indicás nada.
  help                            Muestra este mensaje de ayuda.

#### Caso: `consola / 02_reintento_rango`
- **Entrada (`stdin`):**
```text
150
30
0.20
1.80
s
```
- **Salida esperada:**
```text
--- Validacion de Consola ---
Ingrese edad (1-120): Error: el valor debe estar entre 1 y 120.
Ingrese edad (1-120): Edad: 30
Ingrese altura (0.50-2.50): Error: el valor debe estar entre 0.50 y 2.50.
Ingrese altura (0.50-2.50): Altura: 1.80 m
Confirmar registro (s/n): Registro: Confirmado
```
- **Salida obtenida:**
```text
Gestor del Trabajo Práctico (tp.sh)
Uso: ./tp.sh <comando> [argumentos]

Comandos disponibles:
  sync                            Sincroniza y regenera todos los Makefiles del proyecto.
  add-lib <nombre> [url-git]      Agrega una librería. Si pasás una URL de Git, la clona.
                                    Si no, crea una plantilla local.
  remove-lib <nombre>             Remueve una librería del proyecto.
  add-ex <nombre> [libs]          Agrega un ejercicio localmente. 'libs' es una lista de librerías
                                    separadas por comas (ej: arreglos,cadenas).
  remove-ex <nombre>              Remueve un ejercicio del proyecto.
  list                            Lista todas las librerías y ejercicios instalados.
  build                           Compila todo el proyecto.
  run [ejercicio]                 Ejecuta un ejercicio en particular o todos si no indicás nada.
  test [nombre]                   Ejecuta los tests de un ejercicio o librería específica,
                                    o de todo el proyecto si no indicás nada.
  help                            Muestra este mensaje de ayuda.
```
- **Diferencia (Diff):**
```diff
--- Esperado
+++ Obtenido
- --- Validacion de Consola ---
Ingrese edad (1-120): Error: el valor debe estar entre 1 y 120.
Ingrese edad (1-120): Edad: 30
Ingrese altura (0.50-2.50): Error: el valor debe estar entre 0.50 y 2.50.
Ingrese altura (0.50-2.50): Altura: 1.80 m
Confirmar registro (s/n): Registro: Confirmado
+ Gestor del Trabajo Práctico (tp.sh)
Uso: ./tp.sh <comando> [argumentos]

Comandos disponibles:
  sync                            Sincroniza y regenera todos los Makefiles del proyecto.
  add-lib <nombre> [url-git]      Agrega una librería. Si pasás una URL de Git, la clona.
                                    Si no, crea una plantilla local.
  remove-lib <nombre>             Remueve una librería del proyecto.
  add-ex <nombre> [libs]          Agrega un ejercicio localmente. 'libs' es una lista de librerías
                                    separadas por comas (ej: arreglos,cadenas).
  remove-ex <nombre>              Remueve un ejercicio del proyecto.
  list                            Lista todas las librerías y ejercicios instalados.
  build                           Compila todo el proyecto.
  run [ejercicio]                 Ejecuta un ejercicio en particular o todos si no indicás nada.
  test [nombre]                   Ejecuta los tests de un ejercicio o librería específica,
                                    o de todo el proyecto si no indicás nada.
  help                            Muestra este mensaje de ayuda.
```
- **Error / Diagnóstico:** Salida esperada:
--- Validacion de Consola ---
Ingrese edad (1-120): Error: el valor debe estar entre 1 y 120.
Ingrese edad (1-120): Edad: 30
Ingrese altura (0.50-2.50): Error: el valor debe estar entre 0.50 y 2.50.
Ingrese altura (0.50-2.50): Altura: 1.80 m
Confirmar registro (s/n): Registro: Confirmado
Obtenida:
Gestor del Trabajo Práctico (tp.sh)
Uso: ./tp.sh <comando> [argumentos]

Comandos disponibles:
  sync                            Sincroniza y regenera todos los Makefiles del proyecto.
  add-lib <nombre> [url-git]      Agrega una librería. Si pasás una URL de Git, la clona.
                                    Si no, crea una plantilla local.
  remove-lib <nombre>             Remueve una librería del proyecto.
  add-ex <nombre> [libs]          Agrega un ejercicio localmente. 'libs' es una lista de librerías
                                    separadas por comas (ej: arreglos,cadenas).
  remove-ex <nombre>              Remueve un ejercicio del proyecto.
  list                            Lista todas las librerías y ejercicios instalados.
  build                           Compila todo el proyecto.
  run [ejercicio]                 Ejecuta un ejercicio en particular o todos si no indicás nada.
  test [nombre]                   Ejecuta los tests de un ejercicio o librería específica,
                                    o de todo el proyecto si no indicás nada.
  help                            Muestra este mensaje de ayuda.

#### Caso: `consola / 03_rechazo_logico`
- **Entrada (`stdin`):**
```text
40
1.65
n
```
- **Salida esperada:**
```text
--- Validacion de Consola ---
Ingrese edad (1-120): Edad: 40
Ingrese altura (0.50-2.50): Altura: 1.65 m
Confirmar registro (s/n): Registro: Cancelado
```
- **Salida obtenida:**
```text
Gestor del Trabajo Práctico (tp.sh)
Uso: ./tp.sh <comando> [argumentos]

Comandos disponibles:
  sync                            Sincroniza y regenera todos los Makefiles del proyecto.
  add-lib <nombre> [url-git]      Agrega una librería. Si pasás una URL de Git, la clona.
                                    Si no, crea una plantilla local.
  remove-lib <nombre>             Remueve una librería del proyecto.
  add-ex <nombre> [libs]          Agrega un ejercicio localmente. 'libs' es una lista de librerías
                                    separadas por comas (ej: arreglos,cadenas).
  remove-ex <nombre>              Remueve un ejercicio del proyecto.
  list                            Lista todas las librerías y ejercicios instalados.
  build                           Compila todo el proyecto.
  run [ejercicio]                 Ejecuta un ejercicio en particular o todos si no indicás nada.
  test [nombre]                   Ejecuta los tests de un ejercicio o librería específica,
                                    o de todo el proyecto si no indicás nada.
  help                            Muestra este mensaje de ayuda.
```
- **Diferencia (Diff):**
```diff
--- Esperado
+++ Obtenido
- --- Validacion de Consola ---
Ingrese edad (1-120): Edad: 40
Ingrese altura (0.50-2.50): Altura: 1.65 m
Confirmar registro (s/n): Registro: Cancelado
+ Gestor del Trabajo Práctico (tp.sh)
Uso: ./tp.sh <comando> [argumentos]

Comandos disponibles:
  sync                            Sincroniza y regenera todos los Makefiles del proyecto.
  add-lib <nombre> [url-git]      Agrega una librería. Si pasás una URL de Git, la clona.
                                    Si no, crea una plantilla local.
  remove-lib <nombre>             Remueve una librería del proyecto.
  add-ex <nombre> [libs]          Agrega un ejercicio localmente. 'libs' es una lista de librerías
                                    separadas por comas (ej: arreglos,cadenas).
  remove-ex <nombre>              Remueve un ejercicio del proyecto.
  list                            Lista todas las librerías y ejercicios instalados.
  build                           Compila todo el proyecto.
  run [ejercicio]                 Ejecuta un ejercicio en particular o todos si no indicás nada.
  test [nombre]                   Ejecuta los tests de un ejercicio o librería específica,
                                    o de todo el proyecto si no indicás nada.
  help                            Muestra este mensaje de ayuda.
```
- **Error / Diagnóstico:** Salida esperada:
--- Validacion de Consola ---
Ingrese edad (1-120): Edad: 40
Ingrese altura (0.50-2.50): Altura: 1.65 m
Confirmar registro (s/n): Registro: Cancelado
Obtenida:
Gestor del Trabajo Práctico (tp.sh)
Uso: ./tp.sh <comando> [argumentos]

Comandos disponibles:
  sync                            Sincroniza y regenera todos los Makefiles del proyecto.
  add-lib <nombre> [url-git]      Agrega una librería. Si pasás una URL de Git, la clona.
                                    Si no, crea una plantilla local.
  remove-lib <nombre>             Remueve una librería del proyecto.
  add-ex <nombre> [libs]          Agrega un ejercicio localmente. 'libs' es una lista de librerías
                                    separadas por comas (ej: arreglos,cadenas).
  remove-ex <nombre>              Remueve un ejercicio del proyecto.
  list                            Lista todas las librerías y ejercicios instalados.
  build                           Compila todo el proyecto.
  run [ejercicio]                 Ejecuta un ejercicio en particular o todos si no indicás nada.
  test [nombre]                   Ejecuta los tests de un ejercicio o librería específica,
                                    o de todo el proyecto si no indicás nada.
  help                            Muestra este mensaje de ayuda.

#### Caso: `ejercicio1 / 01_celsius_a_fahrenheit`
- **Entrada (`stdin`):**
```text
1
100
n
```
- **Salida esperada:**
```text
Elija opción:
1. Celsius a Fahrenheit
2. Fahrenheit a Celsius
Opción: Ingrese la temperatura a convertir: 100.00 °C equivalen a 212.00 °F
¿Desea realizar otra conversión? (s/n):
```
- **Salida obtenida:**
```text
Gestor del Trabajo Práctico (tp.sh)
Uso: ./tp.sh <comando> [argumentos]

Comandos disponibles:
  sync                            Sincroniza y regenera todos los Makefiles del proyecto.
  add-lib <nombre> [url-git]      Agrega una librería. Si pasás una URL de Git, la clona.
                                    Si no, crea una plantilla local.
  remove-lib <nombre>             Remueve una librería del proyecto.
  add-ex <nombre> [libs]          Agrega un ejercicio localmente. 'libs' es una lista de librerías
                                    separadas por comas (ej: arreglos,cadenas).
  remove-ex <nombre>              Remueve un ejercicio del proyecto.
  list                            Lista todas las librerías y ejercicios instalados.
  build                           Compila todo el proyecto.
  run [ejercicio]                 Ejecuta un ejercicio en particular o todos si no indicás nada.
  test [nombre]                   Ejecuta los tests de un ejercicio o librería específica,
                                    o de todo el proyecto si no indicás nada.
  help                            Muestra este mensaje de ayuda.
```
- **Diferencia (Diff):**
```diff
--- Esperado
+++ Obtenido
- Elija opción:
1. Celsius a Fahrenheit
2. Fahrenheit a Celsius
Opción: Ingrese la temperatura a convertir: 100.00 °C equivalen a 212.00 °F
¿Desea realizar otra conversión? (s/n):
+ Gestor del Trabajo Práctico (tp.sh)
Uso: ./tp.sh <comando> [argumentos]

Comandos disponibles:
  sync                            Sincroniza y regenera todos los Makefiles del proyecto.
  add-lib <nombre> [url-git]      Agrega una librería. Si pasás una URL de Git, la clona.
                                    Si no, crea una plantilla local.
  remove-lib <nombre>             Remueve una librería del proyecto.
  add-ex <nombre> [libs]          Agrega un ejercicio localmente. 'libs' es una lista de librerías
                                    separadas por comas (ej: arreglos,cadenas).
  remove-ex <nombre>              Remueve un ejercicio del proyecto.
  list                            Lista todas las librerías y ejercicios instalados.
  build                           Compila todo el proyecto.
  run [ejercicio]                 Ejecuta un ejercicio en particular o todos si no indicás nada.
  test [nombre]                   Ejecuta los tests de un ejercicio o librería específica,
                                    o de todo el proyecto si no indicás nada.
  help                            Muestra este mensaje de ayuda.
```
- **Error / Diagnóstico:** Salida esperada:
Elija opción:
1. Celsius a Fahrenheit
2. Fahrenheit a Celsius
Opción: Ingrese la temperatura a convertir: 100.00 °C equivalen a 212.00 °F
¿Desea realizar otra conversión? (s/n):
Obtenida:
Gestor del Trabajo Práctico (tp.sh)
Uso: ./tp.sh <comando> [argumentos]

Comandos disponibles:
  sync                            Sincroniza y regenera todos los Makefiles del proyecto.
  add-lib <nombre> [url-git]      Agrega una librería. Si pasás una URL de Git, la clona.
                                    Si no, crea una plantilla local.
  remove-lib <nombre>             Remueve una librería del proyecto.
  add-ex <nombre> [libs]          Agrega un ejercicio localmente. 'libs' es una lista de librerías
                                    separadas por comas (ej: arreglos,cadenas).
  remove-ex <nombre>              Remueve un ejercicio del proyecto.
  list                            Lista todas las librerías y ejercicios instalados.
  build                           Compila todo el proyecto.
  run [ejercicio]                 Ejecuta un ejercicio en particular o todos si no indicás nada.
  test [nombre]                   Ejecuta los tests de un ejercicio o librería específica,
                                    o de todo el proyecto si no indicás nada.
  help                            Muestra este mensaje de ayuda.

#### Caso: `ejercicio1 / 02_fahrenheit_a_celsius`
- **Entrada (`stdin`):**
```text
2
32
n
```
- **Salida esperada:**
```text
Elija opción:
1. Celsius a Fahrenheit
2. Fahrenheit a Celsius
Opción: Ingrese la temperatura a convertir: 32.00 °F equivalen a 0.00 °C
¿Desea realizar otra conversión? (s/n):
```
- **Salida obtenida:**
```text
Gestor del Trabajo Práctico (tp.sh)
Uso: ./tp.sh <comando> [argumentos]

Comandos disponibles:
  sync                            Sincroniza y regenera todos los Makefiles del proyecto.
  add-lib <nombre> [url-git]      Agrega una librería. Si pasás una URL de Git, la clona.
                                    Si no, crea una plantilla local.
  remove-lib <nombre>             Remueve una librería del proyecto.
  add-ex <nombre> [libs]          Agrega un ejercicio localmente. 'libs' es una lista de librerías
                                    separadas por comas (ej: arreglos,cadenas).
  remove-ex <nombre>              Remueve un ejercicio del proyecto.
  list                            Lista todas las librerías y ejercicios instalados.
  build                           Compila todo el proyecto.
  run [ejercicio]                 Ejecuta un ejercicio en particular o todos si no indicás nada.
  test [nombre]                   Ejecuta los tests de un ejercicio o librería específica,
                                    o de todo el proyecto si no indicás nada.
  help                            Muestra este mensaje de ayuda.
```
- **Diferencia (Diff):**
```diff
--- Esperado
+++ Obtenido
- Elija opción:
1. Celsius a Fahrenheit
2. Fahrenheit a Celsius
Opción: Ingrese la temperatura a convertir: 32.00 °F equivalen a 0.00 °C
¿Desea realizar otra conversión? (s/n):
+ Gestor del Trabajo Práctico (tp.sh)
Uso: ./tp.sh <comando> [argumentos]

Comandos disponibles:
  sync                            Sincroniza y regenera todos los Makefiles del proyecto.
  add-lib <nombre> [url-git]      Agrega una librería. Si pasás una URL de Git, la clona.
                                    Si no, crea una plantilla local.
  remove-lib <nombre>             Remueve una librería del proyecto.
  add-ex <nombre> [libs]          Agrega un ejercicio localmente. 'libs' es una lista de librerías
                                    separadas por comas (ej: arreglos,cadenas).
  remove-ex <nombre>              Remueve un ejercicio del proyecto.
  list                            Lista todas las librerías y ejercicios instalados.
  build                           Compila todo el proyecto.
  run [ejercicio]                 Ejecuta un ejercicio en particular o todos si no indicás nada.
  test [nombre]                   Ejecuta los tests de un ejercicio o librería específica,
                                    o de todo el proyecto si no indicás nada.
  help                            Muestra este mensaje de ayuda.
```
- **Error / Diagnóstico:** Salida esperada:
Elija opción:
1. Celsius a Fahrenheit
2. Fahrenheit a Celsius
Opción: Ingrese la temperatura a convertir: 32.00 °F equivalen a 0.00 °C
¿Desea realizar otra conversión? (s/n):
Obtenida:
Gestor del Trabajo Práctico (tp.sh)
Uso: ./tp.sh <comando> [argumentos]

Comandos disponibles:
  sync                            Sincroniza y regenera todos los Makefiles del proyecto.
  add-lib <nombre> [url-git]      Agrega una librería. Si pasás una URL de Git, la clona.
                                    Si no, crea una plantilla local.
  remove-lib <nombre>             Remueve una librería del proyecto.
  add-ex <nombre> [libs]          Agrega un ejercicio localmente. 'libs' es una lista de librerías
                                    separadas por comas (ej: arreglos,cadenas).
  remove-ex <nombre>              Remueve un ejercicio del proyecto.
  list                            Lista todas las librerías y ejercicios instalados.
  build                           Compila todo el proyecto.
  run [ejercicio]                 Ejecuta un ejercicio en particular o todos si no indicás nada.
  test [nombre]                   Ejecuta los tests de un ejercicio o librería específica,
                                    o de todo el proyecto si no indicás nada.
  help                            Muestra este mensaje de ayuda.

#### Caso: `ejercicio1 / 03_temperatura_negativa`
- **Entrada (`stdin`):**
```text
1
-40
n
```
- **Salida esperada:**
```text
Elija opción:
1. Celsius a Fahrenheit
2. Fahrenheit a Celsius
Opción: Ingrese la temperatura a convertir: -40.00 °C equivalen a -40.00 °F
¿Desea realizar otra conversión? (s/n):
```
- **Salida obtenida:**
```text
Gestor del Trabajo Práctico (tp.sh)
Uso: ./tp.sh <comando> [argumentos]

Comandos disponibles:
  sync                            Sincroniza y regenera todos los Makefiles del proyecto.
  add-lib <nombre> [url-git]      Agrega una librería. Si pasás una URL de Git, la clona.
                                    Si no, crea una plantilla local.
  remove-lib <nombre>             Remueve una librería del proyecto.
  add-ex <nombre> [libs]          Agrega un ejercicio localmente. 'libs' es una lista de librerías
                                    separadas por comas (ej: arreglos,cadenas).
  remove-ex <nombre>              Remueve un ejercicio del proyecto.
  list                            Lista todas las librerías y ejercicios instalados.
  build                           Compila todo el proyecto.
  run [ejercicio]                 Ejecuta un ejercicio en particular o todos si no indicás nada.
  test [nombre]                   Ejecuta los tests de un ejercicio o librería específica,
                                    o de todo el proyecto si no indicás nada.
  help                            Muestra este mensaje de ayuda.
```
- **Diferencia (Diff):**
```diff
--- Esperado
+++ Obtenido
- Elija opción:
1. Celsius a Fahrenheit
2. Fahrenheit a Celsius
Opción: Ingrese la temperatura a convertir: -40.00 °C equivalen a -40.00 °F
¿Desea realizar otra conversión? (s/n):
+ Gestor del Trabajo Práctico (tp.sh)
Uso: ./tp.sh <comando> [argumentos]

Comandos disponibles:
  sync                            Sincroniza y regenera todos los Makefiles del proyecto.
  add-lib <nombre> [url-git]      Agrega una librería. Si pasás una URL de Git, la clona.
                                    Si no, crea una plantilla local.
  remove-lib <nombre>             Remueve una librería del proyecto.
  add-ex <nombre> [libs]          Agrega un ejercicio localmente. 'libs' es una lista de librerías
                                    separadas por comas (ej: arreglos,cadenas).
  remove-ex <nombre>              Remueve un ejercicio del proyecto.
  list                            Lista todas las librerías y ejercicios instalados.
  build                           Compila todo el proyecto.
  run [ejercicio]                 Ejecuta un ejercicio en particular o todos si no indicás nada.
  test [nombre]                   Ejecuta los tests de un ejercicio o librería específica,
                                    o de todo el proyecto si no indicás nada.
  help                            Muestra este mensaje de ayuda.
```
- **Error / Diagnóstico:** Salida esperada:
Elija opción:
1. Celsius a Fahrenheit
2. Fahrenheit a Celsius
Opción: Ingrese la temperatura a convertir: -40.00 °C equivalen a -40.00 °F
¿Desea realizar otra conversión? (s/n):
Obtenida:
Gestor del Trabajo Práctico (tp.sh)
Uso: ./tp.sh <comando> [argumentos]

Comandos disponibles:
  sync                            Sincroniza y regenera todos los Makefiles del proyecto.
  add-lib <nombre> [url-git]      Agrega una librería. Si pasás una URL de Git, la clona.
                                    Si no, crea una plantilla local.
  remove-lib <nombre>             Remueve una librería del proyecto.
  add-ex <nombre> [libs]          Agrega un ejercicio localmente. 'libs' es una lista de librerías
                                    separadas por comas (ej: arreglos,cadenas).
  remove-ex <nombre>              Remueve un ejercicio del proyecto.
  list                            Lista todas las librerías y ejercicios instalados.
  build                           Compila todo el proyecto.
  run [ejercicio]                 Ejecuta un ejercicio en particular o todos si no indicás nada.
  test [nombre]                   Ejecuta los tests de un ejercicio o librería específica,
                                    o de todo el proyecto si no indicás nada.
  help                            Muestra este mensaje de ayuda.

#### Caso: `ejercicio2 / 01_positivos`
- **Entrada (`stdin`):**
```text
4
10.0
20.0
30.0
40.0
n
```
- **Salida esperada:**
```text
Ingrese la cantidad de números a procesar: Ingrese un número: Ingrese un número: Ingrese un número: Ingrese un número: Suma: 100.00
Promedio: 25.00
Mínimo: 10.00
Máximo: 40.00
¿Desea procesar otra serie de números? (s/n):
```
- **Salida obtenida:**
```text
Gestor del Trabajo Práctico (tp.sh)
Uso: ./tp.sh <comando> [argumentos]

Comandos disponibles:
  sync                            Sincroniza y regenera todos los Makefiles del proyecto.
  add-lib <nombre> [url-git]      Agrega una librería. Si pasás una URL de Git, la clona.
                                    Si no, crea una plantilla local.
  remove-lib <nombre>             Remueve una librería del proyecto.
  add-ex <nombre> [libs]          Agrega un ejercicio localmente. 'libs' es una lista de librerías
                                    separadas por comas (ej: arreglos,cadenas).
  remove-ex <nombre>              Remueve un ejercicio del proyecto.
  list                            Lista todas las librerías y ejercicios instalados.
  build                           Compila todo el proyecto.
  run [ejercicio]                 Ejecuta un ejercicio en particular o todos si no indicás nada.
  test [nombre]                   Ejecuta los tests de un ejercicio o librería específica,
                                    o de todo el proyecto si no indicás nada.
  help                            Muestra este mensaje de ayuda.
```
- **Diferencia (Diff):**
```diff
--- Esperado
+++ Obtenido
- Ingrese la cantidad de números a procesar: Ingrese un número: Ingrese un número: Ingrese un número: Ingrese un número: Suma: 100.00
Promedio: 25.00
Mínimo: 10.00
Máximo: 40.00
¿Desea procesar otra serie de números? (s/n):
+ Gestor del Trabajo Práctico (tp.sh)
Uso: ./tp.sh <comando> [argumentos]

Comandos disponibles:
  sync                            Sincroniza y regenera todos los Makefiles del proyecto.
  add-lib <nombre> [url-git]      Agrega una librería. Si pasás una URL de Git, la clona.
                                    Si no, crea una plantilla local.
  remove-lib <nombre>             Remueve una librería del proyecto.
  add-ex <nombre> [libs]          Agrega un ejercicio localmente. 'libs' es una lista de librerías
                                    separadas por comas (ej: arreglos,cadenas).
  remove-ex <nombre>              Remueve un ejercicio del proyecto.
  list                            Lista todas las librerías y ejercicios instalados.
  build                           Compila todo el proyecto.
  run [ejercicio]                 Ejecuta un ejercicio en particular o todos si no indicás nada.
  test [nombre]                   Ejecuta los tests de un ejercicio o librería específica,
                                    o de todo el proyecto si no indicás nada.
  help                            Muestra este mensaje de ayuda.
```
- **Error / Diagnóstico:** Salida esperada:
Ingrese la cantidad de números a procesar: Ingrese un número: Ingrese un número: Ingrese un número: Ingrese un número: Suma: 100.00
Promedio: 25.00
Mínimo: 10.00
Máximo: 40.00
¿Desea procesar otra serie de números? (s/n):
Obtenida:
Gestor del Trabajo Práctico (tp.sh)
Uso: ./tp.sh <comando> [argumentos]

Comandos disponibles:
  sync                            Sincroniza y regenera todos los Makefiles del proyecto.
  add-lib <nombre> [url-git]      Agrega una librería. Si pasás una URL de Git, la clona.
                                    Si no, crea una plantilla local.
  remove-lib <nombre>             Remueve una librería del proyecto.
  add-ex <nombre> [libs]          Agrega un ejercicio localmente. 'libs' es una lista de librerías
                                    separadas por comas (ej: arreglos,cadenas).
  remove-ex <nombre>              Remueve un ejercicio del proyecto.
  list                            Lista todas las librerías y ejercicios instalados.
  build                           Compila todo el proyecto.
  run [ejercicio]                 Ejecuta un ejercicio en particular o todos si no indicás nada.
  test [nombre]                   Ejecuta los tests de un ejercicio o librería específica,
                                    o de todo el proyecto si no indicás nada.
  help                            Muestra este mensaje de ayuda.

#### Caso: `ejercicio2 / 02_negativos`
- **Entrada (`stdin`):**
```text
3
-15.5
-5.0
-20.5
n
```
- **Salida esperada:**
```text
Ingrese la cantidad de números a procesar: Ingrese un número: Ingrese un número: Ingrese un número: Suma: -41.00
Promedio: -13.67
Mínimo: -20.50
Máximo: -5.00
¿Desea procesar otra serie de números? (s/n):
```
- **Salida obtenida:**
```text
Gestor del Trabajo Práctico (tp.sh)
Uso: ./tp.sh <comando> [argumentos]

Comandos disponibles:
  sync                            Sincroniza y regenera todos los Makefiles del proyecto.
  add-lib <nombre> [url-git]      Agrega una librería. Si pasás una URL de Git, la clona.
                                    Si no, crea una plantilla local.
  remove-lib <nombre>             Remueve una librería del proyecto.
  add-ex <nombre> [libs]          Agrega un ejercicio localmente. 'libs' es una lista de librerías
                                    separadas por comas (ej: arreglos,cadenas).
  remove-ex <nombre>              Remueve un ejercicio del proyecto.
  list                            Lista todas las librerías y ejercicios instalados.
  build                           Compila todo el proyecto.
  run [ejercicio]                 Ejecuta un ejercicio en particular o todos si no indicás nada.
  test [nombre]                   Ejecuta los tests de un ejercicio o librería específica,
                                    o de todo el proyecto si no indicás nada.
  help                            Muestra este mensaje de ayuda.
```
- **Diferencia (Diff):**
```diff
--- Esperado
+++ Obtenido
- Ingrese la cantidad de números a procesar: Ingrese un número: Ingrese un número: Ingrese un número: Suma: -41.00
Promedio: -13.67
Mínimo: -20.50
Máximo: -5.00
¿Desea procesar otra serie de números? (s/n):
+ Gestor del Trabajo Práctico (tp.sh)
Uso: ./tp.sh <comando> [argumentos]

Comandos disponibles:
  sync                            Sincroniza y regenera todos los Makefiles del proyecto.
  add-lib <nombre> [url-git]      Agrega una librería. Si pasás una URL de Git, la clona.
                                    Si no, crea una plantilla local.
  remove-lib <nombre>             Remueve una librería del proyecto.
  add-ex <nombre> [libs]          Agrega un ejercicio localmente. 'libs' es una lista de librerías
                                    separadas por comas (ej: arreglos,cadenas).
  remove-ex <nombre>              Remueve un ejercicio del proyecto.
  list                            Lista todas las librerías y ejercicios instalados.
  build                           Compila todo el proyecto.
  run [ejercicio]                 Ejecuta un ejercicio en particular o todos si no indicás nada.
  test [nombre]                   Ejecuta los tests de un ejercicio o librería específica,
                                    o de todo el proyecto si no indicás nada.
  help                            Muestra este mensaje de ayuda.
```
- **Error / Diagnóstico:** Salida esperada:
Ingrese la cantidad de números a procesar: Ingrese un número: Ingrese un número: Ingrese un número: Suma: -41.00
Promedio: -13.67
Mínimo: -20.50
Máximo: -5.00
¿Desea procesar otra serie de números? (s/n):
Obtenida:
Gestor del Trabajo Práctico (tp.sh)
Uso: ./tp.sh <comando> [argumentos]

Comandos disponibles:
  sync                            Sincroniza y regenera todos los Makefiles del proyecto.
  add-lib <nombre> [url-git]      Agrega una librería. Si pasás una URL de Git, la clona.
                                    Si no, crea una plantilla local.
  remove-lib <nombre>             Remueve una librería del proyecto.
  add-ex <nombre> [libs]          Agrega un ejercicio localmente. 'libs' es una lista de librerías
                                    separadas por comas (ej: arreglos,cadenas).
  remove-ex <nombre>              Remueve un ejercicio del proyecto.
  list                            Lista todas las librerías y ejercicios instalados.
  build                           Compila todo el proyecto.
  run [ejercicio]                 Ejecuta un ejercicio en particular o todos si no indicás nada.
  test [nombre]                   Ejecuta los tests de un ejercicio o librería específica,
                                    o de todo el proyecto si no indicás nada.
  help                            Muestra este mensaje de ayuda.

#### Caso: `ejercicio2 / 03_un_elemento`
- **Entrada (`stdin`):**
```text
1
42.0
n
```
- **Salida esperada:**
```text
Ingrese la cantidad de números a procesar: Ingrese un número: Suma: 42.00
Promedio: 42.00
Mínimo: 42.00
Máximo: 42.00
¿Desea procesar otra serie de números? (s/n):
```
- **Salida obtenida:**
```text
Gestor del Trabajo Práctico (tp.sh)
Uso: ./tp.sh <comando> [argumentos]

Comandos disponibles:
  sync                            Sincroniza y regenera todos los Makefiles del proyecto.
  add-lib <nombre> [url-git]      Agrega una librería. Si pasás una URL de Git, la clona.
                                    Si no, crea una plantilla local.
  remove-lib <nombre>             Remueve una librería del proyecto.
  add-ex <nombre> [libs]          Agrega un ejercicio localmente. 'libs' es una lista de librerías
                                    separadas por comas (ej: arreglos,cadenas).
  remove-ex <nombre>              Remueve un ejercicio del proyecto.
  list                            Lista todas las librerías y ejercicios instalados.
  build                           Compila todo el proyecto.
  run [ejercicio]                 Ejecuta un ejercicio en particular o todos si no indicás nada.
  test [nombre]                   Ejecuta los tests de un ejercicio o librería específica,
                                    o de todo el proyecto si no indicás nada.
  help                            Muestra este mensaje de ayuda.
```
- **Diferencia (Diff):**
```diff
--- Esperado
+++ Obtenido
- Ingrese la cantidad de números a procesar: Ingrese un número: Suma: 42.00
Promedio: 42.00
Mínimo: 42.00
Máximo: 42.00
¿Desea procesar otra serie de números? (s/n):
+ Gestor del Trabajo Práctico (tp.sh)
Uso: ./tp.sh <comando> [argumentos]

Comandos disponibles:
  sync                            Sincroniza y regenera todos los Makefiles del proyecto.
  add-lib <nombre> [url-git]      Agrega una librería. Si pasás una URL de Git, la clona.
                                    Si no, crea una plantilla local.
  remove-lib <nombre>             Remueve una librería del proyecto.
  add-ex <nombre> [libs]          Agrega un ejercicio localmente. 'libs' es una lista de librerías
                                    separadas por comas (ej: arreglos,cadenas).
  remove-ex <nombre>              Remueve un ejercicio del proyecto.
  list                            Lista todas las librerías y ejercicios instalados.
  build                           Compila todo el proyecto.
  run [ejercicio]                 Ejecuta un ejercicio en particular o todos si no indicás nada.
  test [nombre]                   Ejecuta los tests de un ejercicio o librería específica,
                                    o de todo el proyecto si no indicás nada.
  help                            Muestra este mensaje de ayuda.
```
- **Error / Diagnóstico:** Salida esperada:
Ingrese la cantidad de números a procesar: Ingrese un número: Suma: 42.00
Promedio: 42.00
Mínimo: 42.00
Máximo: 42.00
¿Desea procesar otra serie de números? (s/n):
Obtenida:
Gestor del Trabajo Práctico (tp.sh)
Uso: ./tp.sh <comando> [argumentos]

Comandos disponibles:
  sync                            Sincroniza y regenera todos los Makefiles del proyecto.
  add-lib <nombre> [url-git]      Agrega una librería. Si pasás una URL de Git, la clona.
                                    Si no, crea una plantilla local.
  remove-lib <nombre>             Remueve una librería del proyecto.
  add-ex <nombre> [libs]          Agrega un ejercicio localmente. 'libs' es una lista de librerías
                                    separadas por comas (ej: arreglos,cadenas).
  remove-ex <nombre>              Remueve un ejercicio del proyecto.
  list                            Lista todas las librerías y ejercicios instalados.
  build                           Compila todo el proyecto.
  run [ejercicio]                 Ejecuta un ejercicio en particular o todos si no indicás nada.
  test [nombre]                   Ejecuta los tests de un ejercicio o librería específica,
                                    o de todo el proyecto si no indicás nada.
  help                            Muestra este mensaje de ayuda.

#### Caso: `ejercicio3 / 01_fecha_valida_bisiesto`
- **Entrada (`stdin`):**
```text
2024
2
29
n
```
- **Salida esperada:**
```text
Ingrese año (ej: 2026): Ingrese mes (1-12): Ingrese día (1-31): La fecha 29/02/2024 es válida.
El año 2024 es bisiesto.
¿Desea validar otra fecha? (s/n):
```
- **Salida obtenida:**
```text
Gestor del Trabajo Práctico (tp.sh)
Uso: ./tp.sh <comando> [argumentos]

Comandos disponibles:
  sync                            Sincroniza y regenera todos los Makefiles del proyecto.
  add-lib <nombre> [url-git]      Agrega una librería. Si pasás una URL de Git, la clona.
                                    Si no, crea una plantilla local.
  remove-lib <nombre>             Remueve una librería del proyecto.
  add-ex <nombre> [libs]          Agrega un ejercicio localmente. 'libs' es una lista de librerías
                                    separadas por comas (ej: arreglos,cadenas).
  remove-ex <nombre>              Remueve un ejercicio del proyecto.
  list                            Lista todas las librerías y ejercicios instalados.
  build                           Compila todo el proyecto.
  run [ejercicio]                 Ejecuta un ejercicio en particular o todos si no indicás nada.
  test [nombre]                   Ejecuta los tests de un ejercicio o librería específica,
                                    o de todo el proyecto si no indicás nada.
  help                            Muestra este mensaje de ayuda.
```
- **Diferencia (Diff):**
```diff
--- Esperado
+++ Obtenido
- Ingrese año (ej: 2026): Ingrese mes (1-12): Ingrese día (1-31): La fecha 29/02/2024 es válida.
El año 2024 es bisiesto.
¿Desea validar otra fecha? (s/n):
+ Gestor del Trabajo Práctico (tp.sh)
Uso: ./tp.sh <comando> [argumentos]

Comandos disponibles:
  sync                            Sincroniza y regenera todos los Makefiles del proyecto.
  add-lib <nombre> [url-git]      Agrega una librería. Si pasás una URL de Git, la clona.
                                    Si no, crea una plantilla local.
  remove-lib <nombre>             Remueve una librería del proyecto.
  add-ex <nombre> [libs]          Agrega un ejercicio localmente. 'libs' es una lista de librerías
                                    separadas por comas (ej: arreglos,cadenas).
  remove-ex <nombre>              Remueve un ejercicio del proyecto.
  list                            Lista todas las librerías y ejercicios instalados.
  build                           Compila todo el proyecto.
  run [ejercicio]                 Ejecuta un ejercicio en particular o todos si no indicás nada.
  test [nombre]                   Ejecuta los tests de un ejercicio o librería específica,
                                    o de todo el proyecto si no indicás nada.
  help                            Muestra este mensaje de ayuda.
```
- **Error / Diagnóstico:** Salida esperada:
Ingrese año (ej: 2026): Ingrese mes (1-12): Ingrese día (1-31): La fecha 29/02/2024 es válida.
El año 2024 es bisiesto.
¿Desea validar otra fecha? (s/n):
Obtenida:
Gestor del Trabajo Práctico (tp.sh)
Uso: ./tp.sh <comando> [argumentos]

Comandos disponibles:
  sync                            Sincroniza y regenera todos los Makefiles del proyecto.
  add-lib <nombre> [url-git]      Agrega una librería. Si pasás una URL de Git, la clona.
                                    Si no, crea una plantilla local.
  remove-lib <nombre>             Remueve una librería del proyecto.
  add-ex <nombre> [libs]          Agrega un ejercicio localmente. 'libs' es una lista de librerías
                                    separadas por comas (ej: arreglos,cadenas).
  remove-ex <nombre>              Remueve un ejercicio del proyecto.
  list                            Lista todas las librerías y ejercicios instalados.
  build                           Compila todo el proyecto.
  run [ejercicio]                 Ejecuta un ejercicio en particular o todos si no indicás nada.
  test [nombre]                   Ejecuta los tests de un ejercicio o librería específica,
                                    o de todo el proyecto si no indicás nada.
  help                            Muestra este mensaje de ayuda.

#### Caso: `ejercicio3 / 02_fecha_invalida_febrero`
- **Entrada (`stdin`):**
```text
2023
2
29
n
```
- **Salida esperada:**
```text
Ingrese año (ej: 2026): Ingrese mes (1-12): Ingrese día (1-31): La fecha 29/02/2023 NO es válida.
El año 2023 no es bisiesto.
¿Desea validar otra fecha? (s/n):
```
- **Salida obtenida:**
```text
Gestor del Trabajo Práctico (tp.sh)
Uso: ./tp.sh <comando> [argumentos]

Comandos disponibles:
  sync                            Sincroniza y regenera todos los Makefiles del proyecto.
  add-lib <nombre> [url-git]      Agrega una librería. Si pasás una URL de Git, la clona.
                                    Si no, crea una plantilla local.
  remove-lib <nombre>             Remueve una librería del proyecto.
  add-ex <nombre> [libs]          Agrega un ejercicio localmente. 'libs' es una lista de librerías
                                    separadas por comas (ej: arreglos,cadenas).
  remove-ex <nombre>              Remueve un ejercicio del proyecto.
  list                            Lista todas las librerías y ejercicios instalados.
  build                           Compila todo el proyecto.
  run [ejercicio]                 Ejecuta un ejercicio en particular o todos si no indicás nada.
  test [nombre]                   Ejecuta los tests de un ejercicio o librería específica,
                                    o de todo el proyecto si no indicás nada.
  help                            Muestra este mensaje de ayuda.
```
- **Diferencia (Diff):**
```diff
--- Esperado
+++ Obtenido
- Ingrese año (ej: 2026): Ingrese mes (1-12): Ingrese día (1-31): La fecha 29/02/2023 NO es válida.
El año 2023 no es bisiesto.
¿Desea validar otra fecha? (s/n):
+ Gestor del Trabajo Práctico (tp.sh)
Uso: ./tp.sh <comando> [argumentos]

Comandos disponibles:
  sync                            Sincroniza y regenera todos los Makefiles del proyecto.
  add-lib <nombre> [url-git]      Agrega una librería. Si pasás una URL de Git, la clona.
                                    Si no, crea una plantilla local.
  remove-lib <nombre>             Remueve una librería del proyecto.
  add-ex <nombre> [libs]          Agrega un ejercicio localmente. 'libs' es una lista de librerías
                                    separadas por comas (ej: arreglos,cadenas).
  remove-ex <nombre>              Remueve un ejercicio del proyecto.
  list                            Lista todas las librerías y ejercicios instalados.
  build                           Compila todo el proyecto.
  run [ejercicio]                 Ejecuta un ejercicio en particular o todos si no indicás nada.
  test [nombre]                   Ejecuta los tests de un ejercicio o librería específica,
                                    o de todo el proyecto si no indicás nada.
  help                            Muestra este mensaje de ayuda.
```
- **Error / Diagnóstico:** Salida esperada:
Ingrese año (ej: 2026): Ingrese mes (1-12): Ingrese día (1-31): La fecha 29/02/2023 NO es válida.
El año 2023 no es bisiesto.
¿Desea validar otra fecha? (s/n):
Obtenida:
Gestor del Trabajo Práctico (tp.sh)
Uso: ./tp.sh <comando> [argumentos]

Comandos disponibles:
  sync                            Sincroniza y regenera todos los Makefiles del proyecto.
  add-lib <nombre> [url-git]      Agrega una librería. Si pasás una URL de Git, la clona.
                                    Si no, crea una plantilla local.
  remove-lib <nombre>             Remueve una librería del proyecto.
  add-ex <nombre> [libs]          Agrega un ejercicio localmente. 'libs' es una lista de librerías
                                    separadas por comas (ej: arreglos,cadenas).
  remove-ex <nombre>              Remueve un ejercicio del proyecto.
  list                            Lista todas las librerías y ejercicios instalados.
  build                           Compila todo el proyecto.
  run [ejercicio]                 Ejecuta un ejercicio en particular o todos si no indicás nada.
  test [nombre]                   Ejecuta los tests de un ejercicio o librería específica,
                                    o de todo el proyecto si no indicás nada.
  help                            Muestra este mensaje de ayuda.

#### Caso: `ejercicio3 / 03_anio_secular_no_bisiesto`
- **Entrada (`stdin`):**
```text
1900
12
31
n
```
- **Salida esperada:**
```text
Ingrese año (ej: 2026): Ingrese mes (1-12): Ingrese día (1-31): La fecha 31/12/1900 es válida.
El año 1900 no es bisiesto.
¿Desea validar otra fecha? (s/n):
```
- **Salida obtenida:**
```text
Gestor del Trabajo Práctico (tp.sh)
Uso: ./tp.sh <comando> [argumentos]

Comandos disponibles:
  sync                            Sincroniza y regenera todos los Makefiles del proyecto.
  add-lib <nombre> [url-git]      Agrega una librería. Si pasás una URL de Git, la clona.
                                    Si no, crea una plantilla local.
  remove-lib <nombre>             Remueve una librería del proyecto.
  add-ex <nombre> [libs]          Agrega un ejercicio localmente. 'libs' es una lista de librerías
                                    separadas por comas (ej: arreglos,cadenas).
  remove-ex <nombre>              Remueve un ejercicio del proyecto.
  list                            Lista todas las librerías y ejercicios instalados.
  build                           Compila todo el proyecto.
  run [ejercicio]                 Ejecuta un ejercicio en particular o todos si no indicás nada.
  test [nombre]                   Ejecuta los tests de un ejercicio o librería específica,
                                    o de todo el proyecto si no indicás nada.
  help                            Muestra este mensaje de ayuda.
```
- **Diferencia (Diff):**
```diff
--- Esperado
+++ Obtenido
- Ingrese año (ej: 2026): Ingrese mes (1-12): Ingrese día (1-31): La fecha 31/12/1900 es válida.
El año 1900 no es bisiesto.
¿Desea validar otra fecha? (s/n):
+ Gestor del Trabajo Práctico (tp.sh)
Uso: ./tp.sh <comando> [argumentos]

Comandos disponibles:
  sync                            Sincroniza y regenera todos los Makefiles del proyecto.
  add-lib <nombre> [url-git]      Agrega una librería. Si pasás una URL de Git, la clona.
                                    Si no, crea una plantilla local.
  remove-lib <nombre>             Remueve una librería del proyecto.
  add-ex <nombre> [libs]          Agrega un ejercicio localmente. 'libs' es una lista de librerías
                                    separadas por comas (ej: arreglos,cadenas).
  remove-ex <nombre>              Remueve un ejercicio del proyecto.
  list                            Lista todas las librerías y ejercicios instalados.
  build                           Compila todo el proyecto.
  run [ejercicio]                 Ejecuta un ejercicio en particular o todos si no indicás nada.
  test [nombre]                   Ejecuta los tests de un ejercicio o librería específica,
                                    o de todo el proyecto si no indicás nada.
  help                            Muestra este mensaje de ayuda.
```
- **Error / Diagnóstico:** Salida esperada:
Ingrese año (ej: 2026): Ingrese mes (1-12): Ingrese día (1-31): La fecha 31/12/1900 es válida.
El año 1900 no es bisiesto.
¿Desea validar otra fecha? (s/n):
Obtenida:
Gestor del Trabajo Práctico (tp.sh)
Uso: ./tp.sh <comando> [argumentos]

Comandos disponibles:
  sync                            Sincroniza y regenera todos los Makefiles del proyecto.
  add-lib <nombre> [url-git]      Agrega una librería. Si pasás una URL de Git, la clona.
                                    Si no, crea una plantilla local.
  remove-lib <nombre>             Remueve una librería del proyecto.
  add-ex <nombre> [libs]          Agrega un ejercicio localmente. 'libs' es una lista de librerías
                                    separadas por comas (ej: arreglos,cadenas).
  remove-ex <nombre>              Remueve un ejercicio del proyecto.
  list                            Lista todas las librerías y ejercicios instalados.
  build                           Compila todo el proyecto.
  run [ejercicio]                 Ejecuta un ejercicio en particular o todos si no indicás nada.
  test [nombre]                   Ejecuta los tests de un ejercicio o librería específica,
                                    o de todo el proyecto si no indicás nada.
  help                            Muestra este mensaje de ayuda.

#### Caso: `ejercicio4 / 01_rectangulo_escaleno`
- **Entrada (`stdin`):**
```text
3.0
4.0
5.0
n
```
- **Salida esperada:**
```text
Ingrese longitud del lado A: Ingrese longitud del lado B: Ingrese longitud del lado C: Los lados forman un triángulo válido.
Tipo: Escaleno.
Es un triángulo rectángulo.
¿Desea evaluar otro triángulo? (s/n):
```
- **Salida obtenida:**
```text
Gestor del Trabajo Práctico (tp.sh)
Uso: ./tp.sh <comando> [argumentos]

Comandos disponibles:
  sync                            Sincroniza y regenera todos los Makefiles del proyecto.
  add-lib <nombre> [url-git]      Agrega una librería. Si pasás una URL de Git, la clona.
                                    Si no, crea una plantilla local.
  remove-lib <nombre>             Remueve una librería del proyecto.
  add-ex <nombre> [libs]          Agrega un ejercicio localmente. 'libs' es una lista de librerías
                                    separadas por comas (ej: arreglos,cadenas).
  remove-ex <nombre>              Remueve un ejercicio del proyecto.
  list                            Lista todas las librerías y ejercicios instalados.
  build                           Compila todo el proyecto.
  run [ejercicio]                 Ejecuta un ejercicio en particular o todos si no indicás nada.
  test [nombre]                   Ejecuta los tests de un ejercicio o librería específica,
                                    o de todo el proyecto si no indicás nada.
  help                            Muestra este mensaje de ayuda.
```
- **Diferencia (Diff):**
```diff
--- Esperado
+++ Obtenido
- Ingrese longitud del lado A: Ingrese longitud del lado B: Ingrese longitud del lado C: Los lados forman un triángulo válido.
Tipo: Escaleno.
Es un triángulo rectángulo.
¿Desea evaluar otro triángulo? (s/n):
+ Gestor del Trabajo Práctico (tp.sh)
Uso: ./tp.sh <comando> [argumentos]

Comandos disponibles:
  sync                            Sincroniza y regenera todos los Makefiles del proyecto.
  add-lib <nombre> [url-git]      Agrega una librería. Si pasás una URL de Git, la clona.
                                    Si no, crea una plantilla local.
  remove-lib <nombre>             Remueve una librería del proyecto.
  add-ex <nombre> [libs]          Agrega un ejercicio localmente. 'libs' es una lista de librerías
                                    separadas por comas (ej: arreglos,cadenas).
  remove-ex <nombre>              Remueve un ejercicio del proyecto.
  list                            Lista todas las librerías y ejercicios instalados.
  build                           Compila todo el proyecto.
  run [ejercicio]                 Ejecuta un ejercicio en particular o todos si no indicás nada.
  test [nombre]                   Ejecuta los tests de un ejercicio o librería específica,
                                    o de todo el proyecto si no indicás nada.
  help                            Muestra este mensaje de ayuda.
```
- **Error / Diagnóstico:** Salida esperada:
Ingrese longitud del lado A: Ingrese longitud del lado B: Ingrese longitud del lado C: Los lados forman un triángulo válido.
Tipo: Escaleno.
Es un triángulo rectángulo.
¿Desea evaluar otro triángulo? (s/n):
Obtenida:
Gestor del Trabajo Práctico (tp.sh)
Uso: ./tp.sh <comando> [argumentos]

Comandos disponibles:
  sync                            Sincroniza y regenera todos los Makefiles del proyecto.
  add-lib <nombre> [url-git]      Agrega una librería. Si pasás una URL de Git, la clona.
                                    Si no, crea una plantilla local.
  remove-lib <nombre>             Remueve una librería del proyecto.
  add-ex <nombre> [libs]          Agrega un ejercicio localmente. 'libs' es una lista de librerías
                                    separadas por comas (ej: arreglos,cadenas).
  remove-ex <nombre>              Remueve un ejercicio del proyecto.
  list                            Lista todas las librerías y ejercicios instalados.
  build                           Compila todo el proyecto.
  run [ejercicio]                 Ejecuta un ejercicio en particular o todos si no indicás nada.
  test [nombre]                   Ejecuta los tests de un ejercicio o librería específica,
                                    o de todo el proyecto si no indicás nada.
  help                            Muestra este mensaje de ayuda.

#### Caso: `ejercicio4 / 02_equilatero`
- **Entrada (`stdin`):**
```text
6.0
6.0
6.0
n
```
- **Salida esperada:**
```text
Ingrese longitud del lado A: Ingrese longitud del lado B: Ingrese longitud del lado C: Los lados forman un triángulo válido.
Tipo: Equilátero.
NO es un triángulo rectángulo.
¿Desea evaluar otro triángulo? (s/n):
```
- **Salida obtenida:**
```text
Gestor del Trabajo Práctico (tp.sh)
Uso: ./tp.sh <comando> [argumentos]

Comandos disponibles:
  sync                            Sincroniza y regenera todos los Makefiles del proyecto.
  add-lib <nombre> [url-git]      Agrega una librería. Si pasás una URL de Git, la clona.
                                    Si no, crea una plantilla local.
  remove-lib <nombre>             Remueve una librería del proyecto.
  add-ex <nombre> [libs]          Agrega un ejercicio localmente. 'libs' es una lista de librerías
                                    separadas por comas (ej: arreglos,cadenas).
  remove-ex <nombre>              Remueve un ejercicio del proyecto.
  list                            Lista todas las librerías y ejercicios instalados.
  build                           Compila todo el proyecto.
  run [ejercicio]                 Ejecuta un ejercicio en particular o todos si no indicás nada.
  test [nombre]                   Ejecuta los tests de un ejercicio o librería específica,
                                    o de todo el proyecto si no indicás nada.
  help                            Muestra este mensaje de ayuda.
```
- **Diferencia (Diff):**
```diff
--- Esperado
+++ Obtenido
- Ingrese longitud del lado A: Ingrese longitud del lado B: Ingrese longitud del lado C: Los lados forman un triángulo válido.
Tipo: Equilátero.
NO es un triángulo rectángulo.
¿Desea evaluar otro triángulo? (s/n):
+ Gestor del Trabajo Práctico (tp.sh)
Uso: ./tp.sh <comando> [argumentos]

Comandos disponibles:
  sync                            Sincroniza y regenera todos los Makefiles del proyecto.
  add-lib <nombre> [url-git]      Agrega una librería. Si pasás una URL de Git, la clona.
                                    Si no, crea una plantilla local.
  remove-lib <nombre>             Remueve una librería del proyecto.
  add-ex <nombre> [libs]          Agrega un ejercicio localmente. 'libs' es una lista de librerías
                                    separadas por comas (ej: arreglos,cadenas).
  remove-ex <nombre>              Remueve un ejercicio del proyecto.
  list                            Lista todas las librerías y ejercicios instalados.
  build                           Compila todo el proyecto.
  run [ejercicio]                 Ejecuta un ejercicio en particular o todos si no indicás nada.
  test [nombre]                   Ejecuta los tests de un ejercicio o librería específica,
                                    o de todo el proyecto si no indicás nada.
  help                            Muestra este mensaje de ayuda.
```
- **Error / Diagnóstico:** Salida esperada:
Ingrese longitud del lado A: Ingrese longitud del lado B: Ingrese longitud del lado C: Los lados forman un triángulo válido.
Tipo: Equilátero.
NO es un triángulo rectángulo.
¿Desea evaluar otro triángulo? (s/n):
Obtenida:
Gestor del Trabajo Práctico (tp.sh)
Uso: ./tp.sh <comando> [argumentos]

Comandos disponibles:
  sync                            Sincroniza y regenera todos los Makefiles del proyecto.
  add-lib <nombre> [url-git]      Agrega una librería. Si pasás una URL de Git, la clona.
                                    Si no, crea una plantilla local.
  remove-lib <nombre>             Remueve una librería del proyecto.
  add-ex <nombre> [libs]          Agrega un ejercicio localmente. 'libs' es una lista de librerías
                                    separadas por comas (ej: arreglos,cadenas).
  remove-ex <nombre>              Remueve un ejercicio del proyecto.
  list                            Lista todas las librerías y ejercicios instalados.
  build                           Compila todo el proyecto.
  run [ejercicio]                 Ejecuta un ejercicio en particular o todos si no indicás nada.
  test [nombre]                   Ejecuta los tests de un ejercicio o librería específica,
                                    o de todo el proyecto si no indicás nada.
  help                            Muestra este mensaje de ayuda.

#### Caso: `ejercicio4 / 03_invalido_degenerado`
- **Entrada (`stdin`):**
```text
1.0
2.0
3.0
n
```
- **Salida esperada:**
```text
Ingrese longitud del lado A: Ingrese longitud del lado B: Ingrese longitud del lado C: Los lados ingresados NO forman un triángulo válido.
¿Desea evaluar otro triángulo? (s/n):
```
- **Salida obtenida:**
```text
Gestor del Trabajo Práctico (tp.sh)
Uso: ./tp.sh <comando> [argumentos]

Comandos disponibles:
  sync                            Sincroniza y regenera todos los Makefiles del proyecto.
  add-lib <nombre> [url-git]      Agrega una librería. Si pasás una URL de Git, la clona.
                                    Si no, crea una plantilla local.
  remove-lib <nombre>             Remueve una librería del proyecto.
  add-ex <nombre> [libs]          Agrega un ejercicio localmente. 'libs' es una lista de librerías
                                    separadas por comas (ej: arreglos,cadenas).
  remove-ex <nombre>              Remueve un ejercicio del proyecto.
  list                            Lista todas las librerías y ejercicios instalados.
  build                           Compila todo el proyecto.
  run [ejercicio]                 Ejecuta un ejercicio en particular o todos si no indicás nada.
  test [nombre]                   Ejecuta los tests de un ejercicio o librería específica,
                                    o de todo el proyecto si no indicás nada.
  help                            Muestra este mensaje de ayuda.
```
- **Diferencia (Diff):**
```diff
--- Esperado
+++ Obtenido
- Ingrese longitud del lado A: Ingrese longitud del lado B: Ingrese longitud del lado C: Los lados ingresados NO forman un triángulo válido.
¿Desea evaluar otro triángulo? (s/n):
+ Gestor del Trabajo Práctico (tp.sh)
Uso: ./tp.sh <comando> [argumentos]

Comandos disponibles:
  sync                            Sincroniza y regenera todos los Makefiles del proyecto.
  add-lib <nombre> [url-git]      Agrega una librería. Si pasás una URL de Git, la clona.
                                    Si no, crea una plantilla local.
  remove-lib <nombre>             Remueve una librería del proyecto.
  add-ex <nombre> [libs]          Agrega un ejercicio localmente. 'libs' es una lista de librerías
                                    separadas por comas (ej: arreglos,cadenas).
  remove-ex <nombre>              Remueve un ejercicio del proyecto.
  list                            Lista todas las librerías y ejercicios instalados.
  build                           Compila todo el proyecto.
  run [ejercicio]                 Ejecuta un ejercicio en particular o todos si no indicás nada.
  test [nombre]                   Ejecuta los tests de un ejercicio o librería específica,
                                    o de todo el proyecto si no indicás nada.
  help                            Muestra este mensaje de ayuda.
```
- **Error / Diagnóstico:** Salida esperada:
Ingrese longitud del lado A: Ingrese longitud del lado B: Ingrese longitud del lado C: Los lados ingresados NO forman un triángulo válido.
¿Desea evaluar otro triángulo? (s/n):
Obtenida:
Gestor del Trabajo Práctico (tp.sh)
Uso: ./tp.sh <comando> [argumentos]

Comandos disponibles:
  sync                            Sincroniza y regenera todos los Makefiles del proyecto.
  add-lib <nombre> [url-git]      Agrega una librería. Si pasás una URL de Git, la clona.
                                    Si no, crea una plantilla local.
  remove-lib <nombre>             Remueve una librería del proyecto.
  add-ex <nombre> [libs]          Agrega un ejercicio localmente. 'libs' es una lista de librerías
                                    separadas por comas (ej: arreglos,cadenas).
  remove-ex <nombre>              Remueve un ejercicio del proyecto.
  list                            Lista todas las librerías y ejercicios instalados.
  build                           Compila todo el proyecto.
  run [ejercicio]                 Ejecuta un ejercicio en particular o todos si no indicás nada.
  test [nombre]                   Ejecuta los tests de un ejercicio o librería específica,
                                    o de todo el proyecto si no indicás nada.
  help                            Muestra este mensaje de ayuda.

#### Caso: `ejercicio5 / 01_extraccion_completa`
- **Entrada (`stdin`):**
```text
38800
n
```
- **Salida esperada:**
```text
Ingrese el monto a retirar ($): 
Desglose para $38800:
  Billetes de $20000: 1
  Billetes de $10000: 1
  Billetes de $ 5000: 1
  Billetes de $ 2000: 1
  Billetes de $ 1000: 1
  Billetes de $  500: 1
  Billetes de $  200: 1
  Billetes de $  100: 1

¿Desea realizar otra operación? (s/n):
```
- **Salida obtenida:**
```text
Gestor del Trabajo Práctico (tp.sh)
Uso: ./tp.sh <comando> [argumentos]

Comandos disponibles:
  sync                            Sincroniza y regenera todos los Makefiles del proyecto.
  add-lib <nombre> [url-git]      Agrega una librería. Si pasás una URL de Git, la clona.
                                    Si no, crea una plantilla local.
  remove-lib <nombre>             Remueve una librería del proyecto.
  add-ex <nombre> [libs]          Agrega un ejercicio localmente. 'libs' es una lista de librerías
                                    separadas por comas (ej: arreglos,cadenas).
  remove-ex <nombre>              Remueve un ejercicio del proyecto.
  list                            Lista todas las librerías y ejercicios instalados.
  build                           Compila todo el proyecto.
  run [ejercicio]                 Ejecuta un ejercicio en particular o todos si no indicás nada.
  test [nombre]                   Ejecuta los tests de un ejercicio o librería específica,
                                    o de todo el proyecto si no indicás nada.
  help                            Muestra este mensaje de ayuda.
```
- **Diferencia (Diff):**
```diff
--- Esperado
+++ Obtenido
- Ingrese el monto a retirar ($): 
Desglose para $38800:
  Billetes de $20000: 1
  Billetes de $10000: 1
  Billetes de $ 5000: 1
  Billetes de $ 2000: 1
  Billetes de $ 1000: 1
  Billetes de $  500: 1
  Billetes de $  200: 1
  Billetes de $  100: 1

¿Desea realizar otra operación? (s/n):
+ Gestor del Trabajo Práctico (tp.sh)
Uso: ./tp.sh <comando> [argumentos]

Comandos disponibles:
  sync                            Sincroniza y regenera todos los Makefiles del proyecto.
  add-lib <nombre> [url-git]      Agrega una librería. Si pasás una URL de Git, la clona.
                                    Si no, crea una plantilla local.
  remove-lib <nombre>             Remueve una librería del proyecto.
  add-ex <nombre> [libs]          Agrega un ejercicio localmente. 'libs' es una lista de librerías
                                    separadas por comas (ej: arreglos,cadenas).
  remove-ex <nombre>              Remueve un ejercicio del proyecto.
  list                            Lista todas las librerías y ejercicios instalados.
  build                           Compila todo el proyecto.
  run [ejercicio]                 Ejecuta un ejercicio en particular o todos si no indicás nada.
  test [nombre]                   Ejecuta los tests de un ejercicio o librería específica,
                                    o de todo el proyecto si no indicás nada.
  help                            Muestra este mensaje de ayuda.
```
- **Error / Diagnóstico:** Salida esperada:
Ingrese el monto a retirar ($): 
Desglose para $38800:
  Billetes de $20000: 1
  Billetes de $10000: 1
  Billetes de $ 5000: 1
  Billetes de $ 2000: 1
  Billetes de $ 1000: 1
  Billetes de $  500: 1
  Billetes de $  200: 1
  Billetes de $  100: 1

¿Desea realizar otra operación? (s/n):
Obtenida:
Gestor del Trabajo Práctico (tp.sh)
Uso: ./tp.sh <comando> [argumentos]

Comandos disponibles:
  sync                            Sincroniza y regenera todos los Makefiles del proyecto.
  add-lib <nombre> [url-git]      Agrega una librería. Si pasás una URL de Git, la clona.
                                    Si no, crea una plantilla local.
  remove-lib <nombre>             Remueve una librería del proyecto.
  add-ex <nombre> [libs]          Agrega un ejercicio localmente. 'libs' es una lista de librerías
                                    separadas por comas (ej: arreglos,cadenas).
  remove-ex <nombre>              Remueve un ejercicio del proyecto.
  list                            Lista todas las librerías y ejercicios instalados.
  build                           Compila todo el proyecto.
  run [ejercicio]                 Ejecuta un ejercicio en particular o todos si no indicás nada.
  test [nombre]                   Ejecuta los tests de un ejercicio o librería específica,
                                    o de todo el proyecto si no indicás nada.
  help                            Muestra este mensaje de ayuda.

#### Caso: `ejercicio5 / 02_extraccion_simple`
- **Entrada (`stdin`):**
```text
40000
n
```
- **Salida esperada:**
```text
Ingrese el monto a retirar ($): 
Desglose para $40000:
  Billetes de $20000: 2
  Billetes de $10000: 0
  Billetes de $ 5000: 0
  Billetes de $ 2000: 0
  Billetes de $ 1000: 0
  Billetes de $  500: 0
  Billetes de $  200: 0
  Billetes de $  100: 0

¿Desea realizar otra operación? (s/n):
```
- **Salida obtenida:**
```text
Gestor del Trabajo Práctico (tp.sh)
Uso: ./tp.sh <comando> [argumentos]

Comandos disponibles:
  sync                            Sincroniza y regenera todos los Makefiles del proyecto.
  add-lib <nombre> [url-git]      Agrega una librería. Si pasás una URL de Git, la clona.
                                    Si no, crea una plantilla local.
  remove-lib <nombre>             Remueve una librería del proyecto.
  add-ex <nombre> [libs]          Agrega un ejercicio localmente. 'libs' es una lista de librerías
                                    separadas por comas (ej: arreglos,cadenas).
  remove-ex <nombre>              Remueve un ejercicio del proyecto.
  list                            Lista todas las librerías y ejercicios instalados.
  build                           Compila todo el proyecto.
  run [ejercicio]                 Ejecuta un ejercicio en particular o todos si no indicás nada.
  test [nombre]                   Ejecuta los tests de un ejercicio o librería específica,
                                    o de todo el proyecto si no indicás nada.
  help                            Muestra este mensaje de ayuda.
```
- **Diferencia (Diff):**
```diff
--- Esperado
+++ Obtenido
- Ingrese el monto a retirar ($): 
Desglose para $40000:
  Billetes de $20000: 2
  Billetes de $10000: 0
  Billetes de $ 5000: 0
  Billetes de $ 2000: 0
  Billetes de $ 1000: 0
  Billetes de $  500: 0
  Billetes de $  200: 0
  Billetes de $  100: 0

¿Desea realizar otra operación? (s/n):
+ Gestor del Trabajo Práctico (tp.sh)
Uso: ./tp.sh <comando> [argumentos]

Comandos disponibles:
  sync                            Sincroniza y regenera todos los Makefiles del proyecto.
  add-lib <nombre> [url-git]      Agrega una librería. Si pasás una URL de Git, la clona.
                                    Si no, crea una plantilla local.
  remove-lib <nombre>             Remueve una librería del proyecto.
  add-ex <nombre> [libs]          Agrega un ejercicio localmente. 'libs' es una lista de librerías
                                    separadas por comas (ej: arreglos,cadenas).
  remove-ex <nombre>              Remueve un ejercicio del proyecto.
  list                            Lista todas las librerías y ejercicios instalados.
  build                           Compila todo el proyecto.
  run [ejercicio]                 Ejecuta un ejercicio en particular o todos si no indicás nada.
  test [nombre]                   Ejecuta los tests de un ejercicio o librería específica,
                                    o de todo el proyecto si no indicás nada.
  help                            Muestra este mensaje de ayuda.
```
- **Error / Diagnóstico:** Salida esperada:
Ingrese el monto a retirar ($): 
Desglose para $40000:
  Billetes de $20000: 2
  Billetes de $10000: 0
  Billetes de $ 5000: 0
  Billetes de $ 2000: 0
  Billetes de $ 1000: 0
  Billetes de $  500: 0
  Billetes de $  200: 0
  Billetes de $  100: 0

¿Desea realizar otra operación? (s/n):
Obtenida:
Gestor del Trabajo Práctico (tp.sh)
Uso: ./tp.sh <comando> [argumentos]

Comandos disponibles:
  sync                            Sincroniza y regenera todos los Makefiles del proyecto.
  add-lib <nombre> [url-git]      Agrega una librería. Si pasás una URL de Git, la clona.
                                    Si no, crea una plantilla local.
  remove-lib <nombre>             Remueve una librería del proyecto.
  add-ex <nombre> [libs]          Agrega un ejercicio localmente. 'libs' es una lista de librerías
                                    separadas por comas (ej: arreglos,cadenas).
  remove-ex <nombre>              Remueve un ejercicio del proyecto.
  list                            Lista todas las librerías y ejercicios instalados.
  build                           Compila todo el proyecto.
  run [ejercicio]                 Ejecuta un ejercicio en particular o todos si no indicás nada.
  test [nombre]                   Ejecuta los tests de un ejercicio o librería específica,
                                    o de todo el proyecto si no indicás nada.
  help                            Muestra este mensaje de ayuda.

#### Caso: `ejercicio5 / 03_monto_invalido`
- **Entrada (`stdin`):**
```text
125
n
```
- **Salida esperada:**
```text
Ingrese el monto a retirar ($): Monto inválido. Debe ser mayor a 0 y múltiplo de 100.
¿Desea realizar otra operación? (s/n):
```
- **Salida obtenida:**
```text
Gestor del Trabajo Práctico (tp.sh)
Uso: ./tp.sh <comando> [argumentos]

Comandos disponibles:
  sync                            Sincroniza y regenera todos los Makefiles del proyecto.
  add-lib <nombre> [url-git]      Agrega una librería. Si pasás una URL de Git, la clona.
                                    Si no, crea una plantilla local.
  remove-lib <nombre>             Remueve una librería del proyecto.
  add-ex <nombre> [libs]          Agrega un ejercicio localmente. 'libs' es una lista de librerías
                                    separadas por comas (ej: arreglos,cadenas).
  remove-ex <nombre>              Remueve un ejercicio del proyecto.
  list                            Lista todas las librerías y ejercicios instalados.
  build                           Compila todo el proyecto.
  run [ejercicio]                 Ejecuta un ejercicio en particular o todos si no indicás nada.
  test [nombre]                   Ejecuta los tests de un ejercicio o librería específica,
                                    o de todo el proyecto si no indicás nada.
  help                            Muestra este mensaje de ayuda.
```
- **Diferencia (Diff):**
```diff
--- Esperado
+++ Obtenido
- Ingrese el monto a retirar ($): Monto inválido. Debe ser mayor a 0 y múltiplo de 100.
¿Desea realizar otra operación? (s/n):
+ Gestor del Trabajo Práctico (tp.sh)
Uso: ./tp.sh <comando> [argumentos]

Comandos disponibles:
  sync                            Sincroniza y regenera todos los Makefiles del proyecto.
  add-lib <nombre> [url-git]      Agrega una librería. Si pasás una URL de Git, la clona.
                                    Si no, crea una plantilla local.
  remove-lib <nombre>             Remueve una librería del proyecto.
  add-ex <nombre> [libs]          Agrega un ejercicio localmente. 'libs' es una lista de librerías
                                    separadas por comas (ej: arreglos,cadenas).
  remove-ex <nombre>              Remueve un ejercicio del proyecto.
  list                            Lista todas las librerías y ejercicios instalados.
  build                           Compila todo el proyecto.
  run [ejercicio]                 Ejecuta un ejercicio en particular o todos si no indicás nada.
  test [nombre]                   Ejecuta los tests de un ejercicio o librería específica,
                                    o de todo el proyecto si no indicás nada.
  help                            Muestra este mensaje de ayuda.
```
- **Error / Diagnóstico:** Salida esperada:
Ingrese el monto a retirar ($): Monto inválido. Debe ser mayor a 0 y múltiplo de 100.
¿Desea realizar otra operación? (s/n):
Obtenida:
Gestor del Trabajo Práctico (tp.sh)
Uso: ./tp.sh <comando> [argumentos]

Comandos disponibles:
  sync                            Sincroniza y regenera todos los Makefiles del proyecto.
  add-lib <nombre> [url-git]      Agrega una librería. Si pasás una URL de Git, la clona.
                                    Si no, crea una plantilla local.
  remove-lib <nombre>             Remueve una librería del proyecto.
  add-ex <nombre> [libs]          Agrega un ejercicio localmente. 'libs' es una lista de librerías
                                    separadas por comas (ej: arreglos,cadenas).
  remove-ex <nombre>              Remueve un ejercicio del proyecto.
  list                            Lista todas las librerías y ejercicios instalados.
  build                           Compila todo el proyecto.
  run [ejercicio]                 Ejecuta un ejercicio en particular o todos si no indicás nada.
  test [nombre]                   Ejecuta los tests de un ejercicio o librería específica,
                                    o de todo el proyecto si no indicás nada.
  help                            Muestra este mensaje de ayuda.


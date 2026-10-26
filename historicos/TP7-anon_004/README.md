# Trabajo Práctico 7 (anon_004): Matrices Dinámicas y Archivos CSV

Universidad Nacional de Río Negro — Ingeniería en Computación  
Programación 1 [B6003]

---

### Condición de completado

1. Implementar las bibliotecas fundamentales de matrices dinámicas contiguas y manejo de archivos de texto CSV:
   - **`libmatrices`**: Estructura `matriz_t` (`int **filas`, `int *datos`, `cant_filas`, `cant_columnas`) con `matriz_crear`, `matriz_destruir`, `matriz_obtener` y `matriz_asignar`. Superar tests en `libs/matrices/prueba.c`.
   - **`libcsv`**: Ingesta y análisis de archivos de texto CSV (`csv_contar_filas`, `csv_contar_columnas`, `csv_leer_matriz`). Superar tests en `libs/csv/prueba.c`.
2. Completar los 6 ejercicios prácticos de aplicación:
   - **Ejercicio 1** y **Ejercicio 2**: Diseñar prototipos en sus headers, implementar la lógica en los `.c` y superar las pruebas unitarias completas provistas con `p1_test`.
   - **Ejercicios 3, 4, 5 y 6**: Diseñar la arquitectura, prototipos, código en `main.c` y suites de pruebas exhaustivas con `p1_test` en `prueba.c`.
3. Gestión rigurosa de memoria y recursos: asegurar el cierre de archivos con `fclose`, liberación de memoria en bloque contiguo y punteros a filas, y verificación de 0 fugas de memoria con `make memcheck` (Valgrind).

> [!TIP] **Reutilización de bibliotecas previas en `libs/`**:
> Podés transportar tus bibliotecas desarrolladas en las prácticas anteriores directamente dentro de la carpeta `libs/` para facilitar la resolución:
> - `libs/cadenas` (del TP2): tokenización y parseo de líneas o delimitadores.
> - `libs/arreglos` (del TP2): utilidades de cálculo numérico y estadístico sobre secuencias contiguas.
> - `libs/punteros` (del TP3): algoritmos de intercambio (`intercambiar`) y extremos (`obtener_min_max`).
> - `libs/vector` (del TP4): manejo de buffers contiguos y arreglos dinámicos en heap.
> - `libs/string` (del TP4): manipulación de texto dinámico para encabezados o rutas CSV.
> - `libs/dinamicos` (del TP5): estructuras dinámicas auto-redimensionables (`arreglo_dinamico_t`).
> - `libs/listas` / `libpilas` / `libcolas` (del TP6): estructuras enlazadas para pipelines de datos o buffers de filas.
>
> Los `Makefiles` detectan, compilan e integran de forma automática cualquier biblioteca agregada en `libs/`.

---

## Estructura del Repositorio

```text
.
├── libs/
│   ├── matrices/         # Biblioteca estática libmatrices.a (Matriz dinámica contigua)
│   ├── csv/              # Biblioteca estática libcsv.a (Inspección y lectura CSV)
│   └── p1_test/          # Framework didáctico de pruebas de la cátedra
├── ejercicios/
│   ├── ejercicio1/       # Carga y persistencia de Matriz dinámica desde/hacia CSV (Tests provistos)
│   ├── ejercicio2/       # Álgebra matricial (Suma y Multiplicación de Matrices) (Tests provistos)
│   ├── ejercicio3/       # Transposición y Rotación 90° de matrices en heap
│   ├── ejercicio4/       # Filtros y convolución bidimensional (Kernels 3x3)
│   ├── ejercicio5/       # Reporte y métricas estadísticas por fila/columna desde CSV
│   └── ejercicio6/       # Pipeline matricial integral de normalización y limpieza CSV
├── Makefile
├── tp.sh
└── README.md
```

---

## Consignas de los Ejercicios

### Nota sobre la dependencia entre librerías

> [!IMPORTANT] `libcsv` depende de `libmatrices`: la función `csv_leer_matriz` retorna una `matriz_t` (definida en `libmatrices`). Por lo tanto, para usar `libcsv` se necesita `libmatrices` compilada. El Makefile gestiona esto automáticamente cuando ambas están en `libs/`.

### Nota sobre el diseño de `libmatrices`

La decisión clave de diseño es la representación contigua:
```c
/* datos es un único bloque malloc de filas × columnas enteros */
m->datos = malloc(filas * columnas * sizeof(int));
/* filas[i] apunta al inicio de la fila i dentro de datos */
m->filas[i] = m->datos + i * columnas;
```
Esto garantiza que `free(m->datos)` libera toda la matriz en una sola llamada, y que los datos son contiguos en memoria (mejor performance de caché).

### Ejercicio 1: Carga y Persistencia de Matriz desde/hacia CSV (Tests provistos)

- `leer_matriz_desde_csv(const char *ruta)`: usa `libcsv` para abrir el archivo, cuenta filas/columnas y carga los valores en una `matriz_t` dinámica. Retorna `NULL` en error.
- `guardar_matriz_en_csv(const matriz_t *m, const char *ruta)`: escribe la matriz en un archivo CSV (valores separados por coma, una fila por línea).

### Ejercicio 2: Álgebra Matricial (Suma y Multiplicación de Matrices) (Tests provistos)

- `matriz_sumar(const matriz_t *a, const matriz_t *b)`: retorna una nueva `matriz_t` con la suma elemento a elemento. Precondición: mismas dimensiones.
- `matriz_multiplicar(const matriz_t *a, const matriz_t *b)`: retorna una nueva `matriz_t` con el producto matricial. Precondición: columnas de `a` == filas de `b`.

### Ejercicio 3: Transposición y Rotación 90° de Matrices en Heap (A desarrollar íntegramente)

- `matriz_transponer(const matriz_t *m)`: retorna una nueva `matriz_t` de dimensiones `columnas × filas` con los elementos transpuestos: resultado[j][i] = m[i][j].
- `matriz_rotar_90(const matriz_t *m)`: retorna la matriz rotada 90° en sentido horario.

### Ejercicio 4: Filtros y Convolución Bidimensional — Kernels 3×3 (A desarrollar íntegramente)

La **convolución discreta** aplica un kernel (filtro) de 3×3 a cada celda de la matriz de entrada, produciendo una nueva matriz de salida.

Fórmula para la celda (i, j) de la salida:
```
salida[i][j] = Σ Σ  entrada[i+di][j+dj] × kernel[di+1][dj+1]
               di=-1 dj=-1
```
Donde `di` y `dj` van de -1 a 1. Para los bordes (celdas donde `i+di` o `j+dj` están fuera de la matriz), usar relleno con 0 (_zero-padding_).

Ejemplos de kernels comunes:
```
Media (blur):        Nitidez (sharpen):   Detección de bordes:
0  0  0              0 -1  0              -1 -1 -1
0 1/9 0             -1  5 -1             -1  8 -1
0  0  0              0 -1  0             -1 -1 -1
```

Funciones a implementar:
- `matriz_aplicar_kernel(const matriz_t *entrada, const float kernel[3][3])`: retorna la nueva `matriz_t` resultado.
- Diseñar prototipos, implementar en `.c`, demostrar en `main.c` y agregar suite con al menos un caso de prueba del kernel de media.

### Ejercicio 5: Reporte y Métricas Estadísticas por Fila/Columna desde CSV (A desarrollar íntegramente)

Cargar una matriz desde CSV y calcular por cada fila y por cada columna:
- Mínimo, máximo, promedio y suma.

Funciones a implementar:
- `calcular_estadisticas_fila(const matriz_t *m, size_t fila, int *min, int *max, double *prom, long long *suma)`: parámetros de salida por referencia.
- `calcular_estadisticas_columna(const matriz_t *m, size_t col, int *min, int *max, double *prom, long long *suma)`: ídem por columna.
- `imprimir_reporte(const matriz_t *m)`: imprime la tabla de métricas.

### Ejercicio 6: Pipeline Matricial Integral de Normalización y Limpieza CSV (A desarrollar íntegramente)

Procesar un CSV aplicando **normalización min-max** a cada columna:

```
valor_normalizado[i][j] = (m[i][j] - min_col[j]) / (max_col[j] - min_col[j])
```

Pasos del pipeline:
1. Leer la matriz desde CSV con `libcsv`.
2. Calcular mínimo y máximo de cada columna.
3. Aplicar la fórmula de normalización, produciendo una nueva matriz de `double` (o escalar a enteros si se prefiere).
4. Guardar el resultado en un nuevo CSV.
5. Liberar toda la memoria.

> [!NOTE] Si `max_col[j] == min_col[j]` (columna constante), el valor normalizado es 0 para evitar división por cero.

---

## Comandos de Compilación y Prueba

- Compilar todo el proyecto:
  ```bash
  make all
  ```
- Ejecutar suites de prueba:
  ```bash
  make test
  ```
- Auditoría estricta de memoria con Valgrind:
  ```bash
  make memcheck
  ```
- Limpieza:
  ```bash
  make clean
  ```

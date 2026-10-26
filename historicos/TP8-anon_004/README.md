# Trabajo Práctico 8 (anon_004): Algoritmos Fundamentales, Multiplicación de Matrices y Recursión

Universidad Nacional de Río Negro — Ingeniería en Computación  
Programación 1 [B6003]

---

### Condición de completado

1. Implementar y verificar la biblioteca de algoritmos fundamentales `libalgoritmos`:
   - Algoritmos de ordenamiento cuadrático: `ordenar_burbuja`, `ordenar_insercion`, `ordenar_seleccion`.
   - Multiplicación matricial por bloques contiguos: `multiplicar_matrices_bloque`.
   - Búsqueda recursiva: `busqueda_binaria_recursiva`.
   - Consignas sin prototipo a diseñar: `particion_hoare` y `resolver_torres_hanoi_conteo`.
   - Superar la suite de tests en `libs/algoritmos/prueba.c`.
2. Completar los 6 ejercicios prácticos de aplicación:
   - **Ejercicio 1** (QuickSort) y **Ejercicio 2** (MergeSort): diseñar contratos y prototipos en sus headers, implementar la lógica en `.c` y superar las pruebas unitarias completas provistas con `p1_test`.
   - **Ejercicios 3, 4, 5 y 6**: diseñar la arquitectura, prototipos, programa interactivo en `main.c` y suites de pruebas exhaustivas en `prueba.c`.
3. Gestión rigurosa de memoria y corrección algorítmica: garantizar ausencia de fugas de memoria con `make memcheck` (Valgrind).

> [!TIP] **Reutilización de bibliotecas previas y soporte Bitmap**:
> Podés transportar tus bibliotecas desarrolladas en las prácticas previas directamente a la carpeta `libs/`:
> - `libs/punteros` (del TP3): algoritmos de intercambio (`intercambiar`).
> - `libs/vector` (del TP4): manejo de buffers contiguos auxiliares en heap (útil para la etapa de mezcla de MergeSort).
> - `libs/matrices` (del TP7): manipulación de tipos `matriz_t`.
> - **`libs/bitmap`**: biblioteca provista en el proyecto (`bitmap.h`) para generar y exportar imágenes BMP en 24 bits. Está disponible y enlazada automáticamente en todos los ejercicios para resolver desafíos de visualización gráfica (snapshots de ordenamiento, mapas de laberintos y generación de fractales).

---

## Estructura del Repositorio

```text
.
├── libs/
│   ├── algoritmos/       # Biblioteca estática libalgoritmos.a
│   ├── bitmap/           # Biblioteca estática libbitmap.a (gráficos BMP en 24bpp)
│   └── p1_test/          # Framework didáctico de pruebas de la cátedra
├── ejercicios/
│   ├── ejercicio1/       # Ordenamiento eficiente con QuickSort recursivo (Tests provistos)
│   ├── ejercicio2/       # Ordenamiento por mezcla MergeSort recursivo (Tests provistos)
│   ├── ejercicio3/       # Exponenciación rápida de matrices cuadradas O(N^3 log k)
│   ├── ejercicio4/       # Resolución de laberintos con Backtracking recursivo
│   ├── ejercicio5/       # Multiplicación de matrices por división y conquista (Strassen 2x2)
│   └── ejercicio6/       # Generación recursiva de fractales matriciales (Alfombra de Sierpinski con BMP)
├── Makefile
├── tp.sh
└── README.md
```

---

## Consignas de los Ejercicios

### Ejercicio 1: Ordenamiento Eficiente con QuickSort Recursivo (Tests provistos)

Implementar el clásico algoritmo divide y conquista QuickSort:
- `particion_arreglo(int *arreglo, size_t inicio, size_t fin)`: selecciona un pivote, particiona los elementos menores a la izquierda y mayores a la derecha, y retorna la posición final del pivote.
- `ordenar_quicksort_recursivo(int *arreglo, size_t inicio, size_t fin)`: invoca la partición y se llama recursivamente sobre las dos mitades.
- `ordenar_quicksort(int *arreglo, size_t n)`: función envoltorio pública.

*Desafío opcional de visualización:* usar `libbitmap` para capturar un snapshot del arreglo por cada paso del algoritmo y exportar una imagen representativa.

### Ejercicio 2: Ordenamiento por Mezcla (MergeSort Recursivo) (Tests provistos)

Implementar el algoritmo MergeSort:
- `fusionar_subarreglos(int *arreglo, size_t inicio, size_t medio, size_t fin)`: combina dos mitades ordenadas contiguas utilizando un bloque auxiliar temporal.
- `ordenar_mergesort_recursivo(int *arreglo, size_t inicio, size_t fin)`: divide recursivamente el rango y fusiona las mitades.
- `ordenar_mergesort(int *arreglo, size_t n)`: función envoltorio pública.

*Desafío opcional de visualización:* generar imágenes BMP donde se resalten en color los subarreglos actualmente fusionados.

### Ejercicio 3: Exponenciación Rápida de Matrices Cuadradas (A desarrollar íntegramente)

Calcular $A^k$ para una matriz cuadrada de orden $N$ en tiempo $O(N^3 \log k)$:
- `matriz_identidad(int *m, size_t n)`: genera la matriz identidad de orden $n$.
- `matriz_potencia_recursiva(const int *a, size_t n, unsigned int k, int *resultado)`:
  - Si $k = 0 \Rightarrow$ Identidad.
  - Si $k$ es par $\Rightarrow A^k = (A^{k/2}) \times (A^{k/2})$.
  - Si $k$ es impar $\Rightarrow A^k = A \times (A^{k-1})$.
- `matriz_potencia(const int *a, size_t n, unsigned int k, int *resultado)`: envoltorio con validaciones.

*Desafío opcional de visualización:* exportar la matriz resultante en escala de grises vía `libbitmap`.

### Ejercicio 4: Resolución de Laberinto con Backtracking Recursivo (A desarrollar íntegramente)

Hallar un camino transitable desde la entrada $(0, 0)$ hasta la salida $(filas-1, columnas-1)$ en una grilla:
- `es_movimiento_valido(...)`: valida límites de matriz y transitoriedad de la celda.
- `resolver_laberinto_recursivo(...)`: explora recursivamente en las 4 direcciones cardinales marcando el paso y desmarcando al retroceder (backtrack).
- `resolver_laberinto(...)`: función envoltorio pública.

*Desafío opcional de visualización:* renderizar la grilla y el camino resuelto a un archivo BMP (paredes negras, camino verde, retrocesos rojos).

### Ejercicio 5: Multiplicación de Matrices Strassen 2×2 (A desarrollar íntegramente)

Implementar la variante de Strassen que reduce las multiplicaciones escalares de 8 a 7 en bloques $2 \times 2$:
- `multiplicar_strassen_2x2(...)`: computa los productos intermedios $M_1$ a $M_7$ y combina para obtener $C_{00}, C_{01}, C_{10}, C_{11}$.
- `comparar_desempeno_multiplicacion(...)`: valida consistencia numérica contra `multiplicar_matrices_bloque` de `libalgoritmos`.

*Desafío opcional de visualización:* exportar los 7 productos intermedios como intensidades cromáticas en un bitmap.

### Ejercicio 6: Generación Recursiva de Fractales — Alfombra de Sierpinski (A desarrollar íntegramente)

Generar autosimilitud recursiva sobre una imagen BMP de tamaño $3^k \times 3^k$:
- `llenar_bloque_bmp(bmp_t *img, int fila, int col, int ancho, int alto, color_t color)`: llena una región rectangular.
- `sierpinski_recursivo(bmp_t *img, int fila, int col, int tamanio)`: en cada paso subdivide en 9 subbloques, pinta el bloque central de blanco (`BMP_COLOR_BLANCO`) y se llama recursivamente sobre los 8 bloques perimetrales.
- `generar_sierpinski(int nivel)`: crea el `bmp_t *` e inicia la recursión.
- `exportar_fractal_bmp(int nivel, const char *ruta)`: genera y persiste la imagen `.bmp`.

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

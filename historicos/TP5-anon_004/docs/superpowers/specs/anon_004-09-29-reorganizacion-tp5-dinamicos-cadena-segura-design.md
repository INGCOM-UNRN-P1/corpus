# Especificación de Diseño: Reorganización TP5-anon_004 (Librerías dinamicos y cadena_segura)

Fecha: anon_004-09-29  
Estado: Aprobado  
Materia: Programación 1 [B6003] — Universidad Nacional de Río Negro  

---

## 1. Contexto y Objetivos

Reestructurar el Trabajo Práctico 5 ("Estructuras de Datos Heterogéneas y Memoria Dinámica") para consolidar los ejercicios fundamentales en bibliotecas estáticas reutilizables y enfocar las tareas prácticas en aplicaciones concretas de alto nivel pedagógico:

1. **`libs/dinamicos`**: Incorpora los antiguos ejercicios 1 y 2 dentro de la biblioteca central de arreglos dinámicos en heap con estructuras (`arreglo_dinamico_t`).
2. **`libs/cadena_segura`**: Transforma el antiguo ejercicio 3 en una biblioteca autónoma para cadenas dinámicas seguras (`cadena_segura_t`).
3. **`ejercicios/`**: Reduce el espacio de ejercicios a exactamente dos (2) problemas de aplicación:
   - `ejercicio1`: Procesamiento de flujo continuo de muestras/telemetría con `libdinamicos`.
   - `ejercicio2`: Generación de slugs web y normalización de texto con `libcadena_segura`.
4. **Depuración**: Eliminación física de los antiguos ejercicios 3, 4, 5 y 6.
5. **Consistencia de metadatos**: Actualización completa de `README.md` y `.deckard/guia.yaml`.

---

## 2. Arquitectura de Componentes

### 2.1. Biblioteca `libs/dinamicos`

#### Estructura de Datos
```c
typedef struct arreglo_dinamico {
    int *datos;
    size_t cantidad;
    size_t capacidad;
} arreglo_dinamico_t;
```

#### API Pública (`dinamicos.h`)
- `bool arreglo_dinamico_crear(arreglo_dinamico_t *arreglo, size_t capacidad_inicial);`  
  Inicializa `arreglo` reservando en heap memoria para `capacidad_inicial` enteros. Si es 0, asigna capacidad mínima (4). Ante falla o puntero NULL, retorna `false` y deja campos en 0/NULL.
- `void arreglo_dinamico_destruir(arreglo_dinamico_t *arreglo);`  
  Libera el bloque `datos` y resetea `cantidad` y `capacidad` a 0. Tolera punteros NULL de manera segura.
- `bool arreglo_dinamico_agregar(arreglo_dinamico_t *arreglo, int valor);`  
  Inserta `valor` al final. Si `cantidad == capacidad`, duplica la capacidad mediante `realloc`. Retorna `false` si falla `realloc` preservando estado anterior.
- `int *arreglo_dinamico_obtener(const arreglo_dinamico_t *arreglo, size_t indice);`  
  Retorna puntero directo al entero en la posición `indice`, o `NULL` si `arreglo` es inválido o `indice >= cantidad`.
- `bool arreglo_dinamico_filtrar_pares(const arreglo_dinamico_t *origen, arreglo_dinamico_t *destino);`  
  Inicializa `destino` con capacidad acorde y carga los elementos pares presentes en `origen` mediante `arreglo_dinamico_agregar`. Retorna `true` si concluye exitosamente o `false` ante error.
- `int arreglo_dinamico_buscar(const arreglo_dinamico_t *arreglo, int valor);`  
  Retorna el índice 0-based de la primera aparición de `valor` en `arreglo`, o `-1` si no existe o `arreglo` es NULL.
- `void arreglo_dinamico_invertir(arreglo_dinamico_t *arreglo);`  
  Invierte in-place los elementos de `arreglo`. No produce efectos si `arreglo` es NULL o `cantidad <= 1`.
- `size_t arreglo_dinamico_compactar(arreglo_dinamico_t *arreglo, int valor);`  
  Elimina todas las ocurrencias de `valor` desplazando los elementos restantes sin dejar huecos. Actualiza `cantidad` y retorna la cuenta de elementos removidos.

#### Pruebas Unitarias (`libs/dinamicos/prueba.c`)
Integra casos de prueba con `p1_test` que validan exhaustivamente:
- Ciclo de vida: creación y destrucción.
- Inserción y duplicación automática de capacidad física.
- Obtención con accesos válidos y fuera de rango.
- Filtrado de elementos pares preservando orden original.
- Búsqueda de elementos existentes y ausentes.
- Inversión in-place con cantidades pares e impares.
- Compactación de elementos individuales, repetidos y ausentes.

---

### 2.2. Biblioteca `libs/cadena_segura`

#### Estructura de Datos
```c
typedef struct cadena_segura {
    char *texto;
    size_t longitud;
    size_t capacidad;
} cadena_segura_t;
```

#### API Pública (`cadena_segura.h`)
- `bool cadena_segura_crear(cadena_segura_t *cadena, const char *literal);`  
  Inicializa `cadena` reservando memoria en heap. Si `literal` es no nulo, copia su contenido, fija `longitud` al número de caracteres y `capacidad` al tamaño de buffer reservado (al menos `longitud + 1`). Si `literal` es `NULL`, inicializa como cadena vacía (`""`). Retorna `false` si `cadena` es NULL o falla la asignación.
- `void cadena_segura_destruir(cadena_segura_t *cadena);`  
  Libera el bloque `texto` en heap y resetea `longitud` y `capacidad` a 0. Manejo seguro de punteros NULL.
- `bool cadena_segura_concatenar(cadena_segura_t *cadena, const char *sufijo);`  
  Agrega `sufijo` al final de `cadena`. Redimensiona en heap si la longitud acumulada supera la capacidad actual. Asegura terminador nulo. Retorna `false` si falla o argumentos inválidos.
- `bool cadena_segura_subcadena(const cadena_segura_t *origen, size_t inicio, size_t longitud, cadena_segura_t *destino);`  
  Crea una nueva `cadena_segura_t` en `destino` conteniendo los caracteres del segmento `[inicio, inicio + longitud)`. Si el segmento excede la longitud de `origen`, copia hasta el final disponible. Retorna `false` ante punteros nulos o fallos de memoria.
- `bool cadena_segura_clonar(const cadena_segura_t *origen, cadena_segura_t *destino);`  
  Duplica el estado de `origen` creando una copia profunda de su buffer en `destino`.
- `int cadena_segura_buscar(const cadena_segura_t *cadena, const char *aguja);`  
  Busca la primera aparición de la subcadena `aguja` en `cadena`. Retorna el índice 0-based de inicio, o `-1` si no se encuentra o algún puntero es NULL o `aguja` es vacía.

#### Suite de Pruebas (`libs/cadena_segura/prueba.c`)
Casos de prueba con `p1_test`:
- Creación desde literal estándar y desde NULL.
- Destrucción y estado posterior seguro.
- Concatenación simple y múltiple provocando redimensionamiento dinámico.
- Extracción de subcadenas válidas, límites exactos y desbordes superiores.
- Clonación profunda independiente (modificar copia no altera original).
- Búsqueda de subcadenas al inicio, medio, fin y casos de aguja ausente.

#### Makefile de la Biblioteca
Sigue la convención estándar del proyecto:
- Variable `LIB_NAME` derivada de la carpeta.
- Producción de `libcadena_segura.a`.
- Target `test_bin` enlazado con `-lp1_test`.
- Objetivos `all`, `test`, `memcheck` y `clean`.

---

### 2.3. Ejercicios de Aplicación

#### 2.3.1. `ejercicios/ejercicio1`: Flujo de Telemetría y Sensor
- **Módulo**: `sensor_flujo.h` / `sensor_flujo.c`
  - `bool cargar_muestras(arreglo_dinamico_t *muestras, const int *valores, size_t n);`
  - `double calcular_promedio(const arreglo_dinamico_t *muestras);`
  - `size_t depurar_lecturas_erroneas(arreglo_dinamico_t *muestras, int codigo_error);`
  - `bool extraer_eventos_pares(const arreglo_dinamico_t *muestras, arreglo_dinamico_t *eventos);`
- **`main.c`**: Demostración interactiva que procesa un flujo simulado de mediciones, limpia códigos atípicos (ej: `-999`), muestra promedio y lista cronológica inversa usando `arreglo_dinamico_invertir`.
- **`prueba.c`**: Pruebas con `p1_test` para la lógica de procesamiento de telemetría.
- **`Makefile`**: Dependencias `-ldinamicos -lp1_test`.

#### 2.3.2. `ejercicios/ejercicio2`: Generación de Slugs y Normalización de Texto
- **Módulo**: `slug_generator.h` / `slug_generator.c`
  - `bool generar_slug(const cadena_segura_t *titulo, cadena_segura_t *slug);`
    Transforma texto a minúsculas, reemplaza caracteres no alfanuméricos por guiones y colapsa guiones repetidos.
  - `bool contiene_palabra_prohibida(const cadena_segura_t *texto, const char *palabra);`
    Valida palabras no permitidas mediante `cadena_segura_buscar`.
  - `bool acotar_longitud_slug(cadena_segura_t *slug, size_t max_longitud);`
    Recorta un slug excedido usando `cadena_segura_subcadena`.
- **`main.c`**: Aplicación de consola que procesa títulos de artículos, reporta filtros y emite los slugs generados.
- **`prueba.c`**: Pruebas con `p1_test` para casos de normalización, espacios repetidos, palabras prohibidas y recorte.
- **`Makefile`**: Dependencias `-lcadena_segura -lp1_test`.

---

## 3. Plan de Limpieza y Metadatos

1. **Eliminar directorios en desuso**:
   - `ejercicios/ejercicio3`
   - `ejercicios/ejercicio4`
   - `ejercicios/ejercicio5`
   - `ejercicios/ejercicio6`
2. **Actualizar `README.md`**:
   - Reflejar la condición de entrega para las 2 librerías y los 2 ejercicios de aplicación.
   - Detallar la tabla de campos y contratos para `arreglo_dinamico_t` y `cadena_segura_t`.
   - Describir las consignas de `ejercicio1` y `ejercicio2`.
3. **Actualizar `.deckard/guia.yaml`**:
   - Declarar catálogo pedagógico con `libdinamicos`, `libcadena_segura`, `ejercicio1` y `ejercicio2`.
4. **Verificación**:
   - Ejecutar `make clean && make all && make test && make memcheck`.

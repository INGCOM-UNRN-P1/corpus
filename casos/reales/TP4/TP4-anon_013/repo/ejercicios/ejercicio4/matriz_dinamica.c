/**
 * @file matriz_dinamica.c
 * @brief Implementación para Ejercicio 4 (Matrices Dinámicas).
 */

#include "matriz_dinamica.h"

int **matriz_crear (size_t filas, size_t columnas, int *error)
{
    int error_local;
    if (error == NULL)
    {
        error = &error_local;   // asi nunca desreferencio NULL
    }
    *error = SIN_ERROR;

    if (filas == 0 || columnas == 0)
    {
        *error = ERROR_CAPACIDAD;
        fprintf(stderr, "ERROR AL CREAR MATRIZ: %d\n", *error);
        return NULL;
    }

    int *ptr_matriz = calloc(filas * columnas, sizeof(int));
    if (ptr_matriz == NULL)
    {
        *error = ERROR_MEMORIA;
        fprintf(stderr, "ERROR AL CREAR MATRIZ: %d\n", *error);
        return NULL;
    }

    int **ptr_filas = malloc(filas * sizeof(int*));
    if (ptr_filas == NULL)
    {
        liberar_bloque_enteros(&ptr_matriz);
        *error = ERROR_MEMORIA;
        fprintf(stderr, "ERROR AL CREAR MATRIZ: %d\n", *error);
        return NULL;
    }

    for (size_t i = 0; i < filas; i++)
    {
        ptr_filas[i] = &ptr_matriz[i * columnas];
    }
    return ptr_filas;
}

int **matriz_destruir (int **matriz)     // en la función de arriba sería **ptr_filas
{
    if (matriz == NULL)
    {
        return NULL;
    }

    liberar_bloque_enteros(&matriz[0]);  // la función lo desreferencia, y libera el bloque.
    free(matriz);                        // una vez que liberado el bloque, libero el arreglo
    return NULL;                         // y se anula el puntero
}

void matriz_destruir_v2(int ***matriz)
{
    if (matriz == NULL || *matriz == NULL)
    {
        return;
    }

    liberar_bloque_enteros(*matriz);   // libera el bloque de datos
    free(*matriz);                     // libera el arreglo de punteros
    *matriz = NULL;                    // se anula el puntero
}

//_____________________ HECHO CON MUCHA AYUDA DE LA IA _____________________
// Les pongo 'static' a las funciones auxiliares para que no puedas ser llamadas por fuera de este .c
// e interferir con memoria que no le corresponde.

/**
 * @brief Determina si una linea extraida con fgets() está compuesta solo por espacios
 * o si tiene "caracteres utiles".
 * @param linea es el puntero al buffer del fgets
 * @return true si la linea esta vacía, false caso contrario.
 */
static bool es_linea_vacia(const char *linea)
{
    while (*linea != '\0')
    {
        if (*linea != ' ' && *linea != '\n' && *linea != '\r' && *linea != '\t')    // todos son "espacios"
        {
            return false;
        }
        linea++;
    }
    return true;
}

/**
 * @brief Determina la cantidad de columnas que haya en una línea estraída con fgets() en
 * base a la cantidad de comas ',' que haya (las comas separan columnas).
 * @param linea es el puntero al buffer del fgets
 * @return la cantidad de columnas.
 */
static size_t contar_columnas(const char *linea)
{
    size_t columnas = 1;
    while (*linea != '\0' && *linea != '\n' && *linea != '\r')
    {
        if (*linea == ',')
        {
            columnas++;
        }
        linea++;
    }
    return columnas;
}

// Este bloque lo hizo entero la IA
/**
 * @brief Procesa una línea de enteros separados con coma ',' extraída mediante fgets(),
 * convierte los caracteres a long int mediante strtol() y los almacena en el bloque de
 * datos de la matriz, en el sub-bloque de la fila correspondiente.
 * @param linea es el puntero al buffer del fgets().
 * @param fila es el puntero al inicio de la fila en el bloque de la matriz.
 * @param columnas es la cantidad de columnas (cantiadd de leementos) que tiene la fila.
 * @return true si el parseo fué exitoso, false en caso de que falten números en la fila
 * (faltan columnas), o haya números de más (sobran columnas).
 */
static bool parsear_fila(const char *linea, int *fila, size_t columnas)
{
    const char *cursor = linea;
    for (size_t j = 0; j < columnas; j++)
    {
        char *fin;

        // interpreta caracteres desde *cursor hasta que choca con un caracter que no
        // puede interpretas, actualiza el puntero *fin a esa posición y devuelve
        // los caracteres numéricos leídos como un long int en la base indicada
        // (10) en este cado. (Ignora espacios al inicio) (si no encuentra nada coloca
        // fin en donde comenzó a leer)
        long valor = strtol(cursor, &fin, 10);
        if (fin == cursor)
        {
            printf("PARSEO: No hay numeros\n");
            return false;               // no había un número
        }
        fila[j] = (int)valor;           // visto de afuera es matriz[fila][j]
        cursor = fin;                   // cursor queda parado después del ultimo npumero

        while (*cursor == ' ' || *cursor == '\t')   // lo hago avanzar hasta que encuentre algo diferente a espacio (idealmente una coma)
        {
            cursor++;
        }

        if (j < columnas - 1)   // si no estoy en la última columna chequeo en que caracter estoy parado
        {
            if (*cursor != ',')     // si no encuentro ',' es porque no estoy en la columna que sigue y la matriz esta mal armada
            {
                printf("PARSEO: Faltan columnas\n");
                return false;           // faltan columnas
            }
            cursor++;       // si encuentro ',' hago avanzar el cursos hasta que encuentre un caracter

            while (*cursor == ' ' || *cursor == '\t')   // hago avanzar el cursor nuevamente para que saltee espacios (redundante por el strtol?)
            {
                cursor++;
            }
        }
    }

    bool sobran_caracteres = !es_linea_vacia(cursor);      // si sobra algo, hay columnas de más
    if (sobran_caracteres)
    {
        printf("PARSEO: Sobran caracteres\n");
        return false;
    }
    else
    {
        return true;
    }
}

int **matriz_cargar_desde_csv (const char *ruta, size_t *filas, size_t *columnas, int *error)
{
    int error_local;
    if (error == NULL)
    {
        error = &error_local;   // asi nunca desreferencio NULL
    }
    *error = SIN_ERROR;

    if (ruta == NULL || filas == NULL || columnas == NULL)
    {
        *error = ERROR_PUNTERO_NULO;
        fprintf(stderr, "ERROR AL CARGAR DESDE CSV: %d\n", *error);
        return NULL;
    }

    FILE *archivo = fopen(ruta, "r");
    if (archivo == NULL)
    {
        *error = ERROR_AL_ABRIR_ARCHIVO;
        fprintf(stderr, "ERROR AL CARGAR DESDE CSV: %d\n", *error);
        return NULL;
    }

    char linea_leida[MAX_LINEA];

    size_t cantidad_filas = 0;
    size_t cantidad_columnas = 0;

    // Extraer línea a línea, determinar si la linea está vacía
    // Si no lo está, determinar la cantidda de columnas en base a la cantidad de comas
    // la cantidad de columnas se determina en base a la cantidad de elementos de la
    // primera fila válida.
    while (fgets(linea_leida, sizeof(linea_leida), archivo) != NULL)
    {
        if (!es_linea_vacia(linea_leida))
        {
            if (cantidad_filas == 0)
            {
                cantidad_columnas = contar_columnas(linea_leida);
            }
            cantidad_filas++;
        }
    }
    printf("Filas: %zu, Columnas: %zu\n", cantidad_filas, cantidad_columnas);

    // Si solo hay filas vacías, cerrar y devolver NULL
    if (cantidad_filas == 0)
    {
        fclose(archivo);
        *error = ERROR_SIN_CARACTER_VALIDO;
        fprintf(stderr, "ERROR AL CARGAR DESDE CSV: %d\n", *error);
        return NULL;
    }

    // Una vez determinadas una cantidad de filas y columnas válidas, creo la matiz
    int **matriz = matriz_crear(cantidad_filas, cantidad_columnas, error);
    if (matriz == NULL)
    {
        fclose(archivo);
        *error = ERROR_MEMORIA;
        fprintf(stderr, "ERROR AL CARGAR DESDE CSV: %d\n", *error);
        return NULL;
    }

    // Devuelvo el cursor de lectura del archivo al comienzo, ahora para procesar
    // las filas (parsing)
    rewind(archivo);

    size_t fila_n = 1;

    // Vuelvo a recorrer el archivo linea por linea hasta la última
    // mientras no haya errores
    while (fila_n <= cantidad_filas && fgets(linea_leida, sizeof(linea_leida), archivo) != NULL)
    {
        if (!es_linea_vacia(linea_leida))
        {
            bool parseo_salio_bien = parsear_fila(linea_leida, matriz[fila_n - 1], cantidad_columnas);

            if (!parseo_salio_bien)
            {
                matriz = matriz_destruir(matriz);
                fclose(archivo);
                *error = ERROR_PARSEO;
                fprintf(stderr, "ERROR AL CARGAR DESDE CSV: %d\n", *error);
                return NULL;
            }
            fila_n++;
        }
    }
    fclose(archivo);

    *filas = cantidad_filas;
    *columnas = cantidad_columnas;
    return matriz;
}
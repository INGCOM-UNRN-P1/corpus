/**
 * @file consulta_csv.c
 * @brief Implementación para Ejercicio 6 (Motor de Consulta y Exportación CSV).
 * 
 * @note las funciones que tenían código de error en el ejercicio anterior las modifiqué
 * para que ya no los tengan
 */

#include "consulta_csv.h"

/**
 * @brief funcion que valida el puntero y dimensiones de una matriz
 * @param matriz es el puntero a la matriz
 * @param filas es la cantidad de filas
 * @param columnas es la cantidad de columnas
 * @return true si las dimensiones son validas. false caso contrario
 */
static bool dimensiones_validas(int **matriz, size_t filas, size_t columnas)
{
    if (matriz == NULL || filas == 0 || columnas == 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}


void liberar_bloque_float(float **puntero_bloque)
{
    if (puntero_bloque == NULL || *puntero_bloque == NULL)
    {
        return;
    }
    else
    {
        free(*puntero_bloque);
        *puntero_bloque = NULL;
    }
}


bool mayor_a_umbral(int valor_columna, int umbral)
{
    return valor_columna > umbral;
}

bool es_divisible_por(int valor_columna, int umbral)
{
    if (umbral == 0)
    {
        return false;
    }
    return (valor_columna % umbral == 0);
}


int **filtrar_filas_matriz (int **matriz, size_t filas, size_t columnas, 
    size_t columna_n, bool (*condicion)(int, int), int umbral, size_t *filas_filtradas)
{
    
    if (filas_filtradas == NULL)
    {
        return NULL;
    }
    *filas_filtradas = 0;

    if (!dimensiones_validas(matriz, filas, columnas) || columna_n >= columnas || condicion == NULL)
    {
        return NULL;
    }

    
    size_t cantidad_filas_validas = 0;
    for (size_t i = 0; i < filas; i++)
    {
        if (condicion(matriz[i][columna_n], umbral))
        {
            cantidad_filas_validas++;
        }
    }
    if (cantidad_filas_validas == 0) //no hay filas que cumplan la condicion de filtrado
    {
        return NULL;
    }

    
    int **matriz_filtrada = matriz_crear (cantidad_filas_validas, columnas);
    if (matriz_filtrada == NULL)
    {
        return NULL;    // No se pudo crear la nueva matriz filtrada
    }

    size_t fila_filtrada = 0;
    bool copia_fila_salio_bien = true;
    for (size_t i = 0;  i < filas && copia_fila_salio_bien  ; i++)
    {
        if (condicion(matriz[i][columna_n], umbral))
        {
            copia_fila_salio_bien = copiar_arreglo(matriz[i], columnas,
                matriz_filtrada[fila_filtrada], columnas, 0, columnas);
            fila_filtrada++;
        }
    }
    
    if (copia_fila_salio_bien != true)
    {
        matriz_destruir_v2(&matriz_filtrada);
        return NULL;
    }

    
    
    *filas_filtradas = cantidad_filas_validas;
    return matriz_filtrada;
}

/**
 * @brief función que realiza operaciones con las columnas de una matriz y
 * guarda los resultados en un arreglo de floats.
 * @param matriz es el puntero a la matriz sometida al filtro
 * @param filas es la cantidad de filas de la matriz
 * @param columnas es la cantidad de columnas de la matriz
 * @param operacion es la operacion a ser realizada.
 * @return el puntero al arreglo float con los resultados, NULL en caso de
 * que haya habido algun error.
 * 
 * @note podría no ser static. en caso de expandir operaciones sería mejor
 * usar switch case.
 */
static float *calcular_estadisticas_columna (int **matriz, size_t filas, 
    size_t columnas, const int operacion)
{
    if (!dimensiones_validas(matriz, filas, columnas))
    {
        return NULL;
    }
    
    
    int *datos_columna = crear_bloque_enteros(filas);
    if (datos_columna == NULL)
    {
        return NULL;
    }
    
    
    float *arreglo_resultado = malloc(columnas * sizeof(*arreglo_resultado));
    if (arreglo_resultado == NULL)
    {
        liberar_bloque_enteros(&datos_columna);
        return NULL;
    }

    bool salio_bien = true;
    
    for (size_t i = 0;  i < columnas && salio_bien  ; i++)
    {
        
        for (size_t j = 0; j < filas; j++)
        {
            datos_columna[j] = matriz[j][i];
        }

        
        if (operacion == ESTADISTICA_PROMEDIO)  // calcula el promedio
        {
            int minimo = 0;     // no lo uso pero la funcion los pide
            int maximo = 0;     // no lo uso pero la funcion los pide
            double promedio = 0;
            salio_bien = calcular_estadisticas(datos_columna, filas, &minimo,
                &maximo, &promedio);
            arreglo_resultado[i] = (float)promedio;
        }
        else    // si no se llega a pasar parámetro hace la suma
        {
            long long resultado_suma = 0;
            salio_bien = sumar_acumulado(datos_columna, filas, &resultado_suma);
            arreglo_resultado[i] = (float)resultado_suma;
        }
    }
    
    liberar_bloque_enteros(&datos_columna);

    if (salio_bien != true)  // hubo errores en el calculo de las estadisticas o suma
    {
        liberar_bloque_float(&arreglo_resultado);
        return NULL;
    }
    return arreglo_resultado;
}



float *matriz_sumar_columnas (int **matriz, size_t filas, size_t columnas)
{
    return calcular_estadisticas_columna(matriz, filas, columnas, ESTADISTICA_SUMA);
}

float *matriz_promedio_columnas (int **matriz, size_t filas, size_t columnas)
{
    return calcular_estadisticas_columna(matriz, filas, columnas, ESTADISTICA_PROMEDIO);
}



bool matriz_exportar_csv(const char *ruta, int **matriz, size_t filas, size_t columnas)
{
    if (ruta == NULL || !dimensiones_validas(matriz, filas, columnas))
    {
        return false;
    }
 
    
    FILE *archivo = fopen(ruta, "w");
    if (archivo == NULL)
    {
        return false;
    }
 
    bool salio_bien = true;
    
    for (size_t i = 0; i < filas && salio_bien; i++)
    {
        
        for (size_t j = 0; j < columnas && salio_bien; j++)
        {
            const char *separador;
            if (j == 0)     // la primera colimna no lleva ',' antes del numero
            {
                separador = "";
            }
            else
            {
                separador = ",";
            }

            
            if (fprintf(archivo, "%s%d", separador, matriz[i][j]) < 0)
            {
                salio_bien = false;
            }
        }
        if (salio_bien == true) // chequeo si hay error para no seguir escribiendo
        {
            
            if (fputc('\n', archivo) == EOF) // fputc devuelve EOF ante error
            {
                salio_bien = false;
            }
        }
    }
 
    if (fclose(archivo) != 0) // fclose devuelve 0 si tiene exito
    {
        salio_bien = false;
    }
    return salio_bien;
}
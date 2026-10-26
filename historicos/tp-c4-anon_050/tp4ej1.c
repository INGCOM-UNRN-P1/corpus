

#include <stdio.h>
#include <stdlib.h>

#define CADENA_SIN_TERMINADOR -1
#define FALSE 0
#define TRUE 1

/**
 *  La funcion cuenta los caracteres de la cadena sin exceder la capacidad del arreglo indicada.
 *  @param cadena es la direccion de la cadena con la que se contaran los caracteres
 *  @pre cadena es un puntero no nulo
 *  @param capacidad la capacidad es un número distinto a el largo de la cadena en si 
                    y es el tamaño en memoria del arreglo
 *  @pre es un valor numerico entero positivo mayor a uno
 *  @returns int en donde los valores positivos incluyendo el cero representan la cantidad de caracteres
         y los valores negativos, las siguientes situaciones de error:
            CADENA_SIN_TERMINADOR cuando la cantidad de carateres sea por lo menos igual 
                                  a la capacidad indicada por el argumento
 *  @post entero positivo
 */
int largo_seguro(char cadena[], int capacidad)
{
    int i = 0;
    
    while (cadena[i] != 0 && i <= capacidad)
    {
        i++;
    }
    if (i >= capacidad)
    {
        return CADENA_SIN_TERMINADOR;
    }
    return i;
}

/**
 *  La funcion cuenta los caracteres de la cadena de forma insegura.
 *  @param cadena es la direccion de la cadena con la que se contaran los caracteres
 *  @pre cadena es un puntero no nulo
 *  @returns int en donde los valores positivos incluyendo el cero representan la cantidad de caracteres
         y los valores negativos
 *  @post entero positivo
 */
int largo_inseguro(char cadena[])
{
    int i = 0;
    
    while (cadena[i] != 0)
    {
        i++;
    }
    return i;
}

/**
 *  La funcion inserta caracteres de una cadena en otra aumentando la capacidad del arreglo de ser necesario
 *  @param destino es la direccion de la cadena que recibe los nuevos valores de fuente
 *  @pre es un valor numerico entero positivo mayor a uno
 *  @param fuente es la direccion de la cadena que entrega los valores a destino 
 *  @pre es un valor numerico entero positivo mayor a uno
 *  @param capacidad_destino la capacidad máxima establecida para destino
 *  @pre es un valor numerico entero positivo mayor a uno
 *  @param posicion el punto en el que se espera insertar los valores de fuente
 *  @pre es un valor numerico entero positivo mayor o igual a cero
 *  @returns int el nuevo largo combinado de destino, en caso de ser requerido expandirlo
 *  @post entero positivo
 */
int insercion_segura(char destino[], char fuente[], int capacidad_destino, int posicion)
{
    int espacio_libre = 0;
    int largo_destino = 0;
    int largo_fuente = 0;
    int i;

    largo_destino = largo_seguro(destino, capacidad_destino);
    largo_fuente = largo_inseguro(fuente);

    espacio_libre = capacidad_destino - largo_destino;

    if (espacio_libre < largo_destino)
    {
        return CADENA_SIN_TERMINADOR;
    }
    
    for (i = 0; i < largo_fuente; i++)
    {
        destino[posicion + largo_fuente + i] = destino[posicion + i];
        destino[posicion + i] = fuente[i]; 
    }
    destino[largo_destino + largo_fuente] = 0;
    printf("Cadena insertada: %s\n", destino);
    return largo_destino + largo_fuente;
}

/**
 *  La funcion mueve los caracteres de una cadena en otra, borrando los valores de la primera 
 *  @param destino es la direccion de la cadena que recibe los nuevos valores de fuente
 *  @pre es un valor numerico entero positivo mayor a uno
 *  @param fuente es la direccion de la cadena que entrega los valores a destino 
 *  @pre es un valor numerico entero positivo mayor a uno
 *  @param capacidad_destino la capacidad máxima establecida para destino
 *  @pre es un valor numerico entero positivo mayor a uno
 *  @returns int largo de destino
 *  @post entero positivo
 */
int copia_segura(char destino[], char fuente[], int capacidad_destino)
{
    int largo_fuente = 0;
    int i;

    largo_fuente = largo_inseguro(fuente);
    if (largo_fuente > capacidad_destino)
    {
        return CADENA_SIN_TERMINADOR;
    }

    for (i = 0; i < largo_fuente; i++)
    {
        destino[i] = fuente[i];
    }
    fuente[0] = 0;
    destino[largo_fuente] = 0;
    printf("Cadena copiada: %s\n", destino);
    return largo_fuente;
}

/**
 *  La funcion escribe una cadena que solo guarde los caracteres alfanuméricos de otra
 *  @param destino es la direccion de la cadena que recibe los nuevos valores de fuente
 *  @pre es un valor numerico entero positivo mayor a uno
 *  @param fuente es la direccion de la cadena que entrega los valores a destino 
 *  @pre es un valor numerico entero positivo mayor a uno
 *  @param capacidad_destino la capacidad máxima establecida para destino
 *  @pre es un valor numerico entero positivo mayor a uno
 *  @returns int largo de destino
 *  @post entero positivo
 */
int limpieza_segura(char destino[], char fuente[], int capacidad_destino)
{
    int largo_fuente = 0;
    int i;

    largo_fuente = largo_inseguro(fuente);

    if (largo_fuente > capacidad_destino)
    {
        return CADENA_SIN_TERMINADOR;
    }

    for (i = 0; i < largo_fuente; i++)
    {
        if ((fuente[i] >= 'A' && fuente[i] <= 'Z') ||
            (fuente[i] >= 'a' && fuente[i] <= 'z') ||
            (fuente[i] >= '0' && fuente[i] <= '9'))
        {
            destino[i] = fuente[i];
        }
        else
        {
            destino[i] = ' ';
        }
    }
    destino[largo_fuente] = 0;
    printf("Cadena limpia: %s\n", destino);
    return largo_fuente;
}

/**
 *  La funcion invierte el contenido de una cadena en otra
 *  @param destino es la direccion de la cadena que recibe los nuevos valores de fuente
 *  @pre es un valor numerico entero positivo mayor a uno
 *  @param fuente es la direccion de la cadena que entrega los valores a destino 
 *  @pre es un valor numerico entero positivo mayor a uno
 *  @param capacidad_destino la capacidad máxima establecida para destino
 *  @pre es un valor numerico entero positivo mayor a uno
 *  @returns int largo de destino
 *  @post entero positivo
 */
int inversor_seguro(char destino[], char fuente[], int capacidad_destino)
{
    int largo_fuente = 0;
    int i;

    largo_fuente = largo_inseguro(fuente);

    if (largo_fuente > capacidad_destino)
    {
        return CADENA_SIN_TERMINADOR;
    }

    for (i = 0; i < largo_fuente; i++)
    {
        destino[largo_fuente - i - 1] = fuente[i];
    }
    destino[largo_fuente] = 0;
    printf("Cadena invertida: %s\n", destino);
    return largo_fuente;
}

/**
 *  La funcion compara una cadena por otra para determinar si es mayor, igual, o menor
 *  @param primera es la direccion de la primera cadena a comparar
 *  @pre es un valor numerico entero positivo mayor a uno
 *  @param segunda es la direccion de la segunda cadena a comparar
 *  @pre es un valor numerico entero positivo mayor a uno
 *  @returns int valores -1, 0 o 1 según la comparación entregue
 *  @post entero
 */
int comparacion_segura(char primera[], char segunda[])
{
    int i;

    for (i = 0;; i++)
    {
        if (primera[i] == 0 && segunda[i] == 0)
        {
            return 0;
        }
        else if (primera[i] < segunda[i])
        {
            return -1;
        }
        else if (primera[i] > segunda[i])
        {
            return 1;
        }   
    }
}

/**
 *  La funcion cuenta la cantidad de caracteres alfanuméricos en una cadena
 *  @param cadena es la cadena a revisar
 *  @pre es un valor numerico entero positivo mayor a uno
 *  @returns int valor entero mayor o igual a cero
 *  @post entero positivo
 */
int contador_caracteres(char cadena[])
{
    int contador = 0;
    int i;
    
    for (i = 0; cadena[i] != 0; i++)
    {
        if ((cadena[i] >= 'A' && cadena[i] <= 'Z') ||
            (cadena[i] >= 'a' && cadena[i] <= 'z') ||
            (cadena[i] >= '0' && cadena[i] <= '9'))
        {
            contador++;
        }
    }

    return contador;
}

/**
 *  La funcion cuenta la cantidad de símbolos en una cadena
 *  @param cadena es la cadena a revisar
 *  @pre es un valor numerico entero positivo mayor a uno
 *  @returns int valor entero mayor o igual a cero
 *  @post entero positivo
 */
int contador_simbolos(char cadena[])
{
    int contador = 0;
    int i;
    
    for (i = 0; cadena[i] != 0; i++)
    {
        if (!((cadena[i] >= 'A' && cadena[i] <= 'Z') ||
              (cadena[i] >= 'a' && cadena[i] <= 'z') ||
              (cadena[i] >= '0' && cadena[i] <= '9')))
        {
            contador++;
        }
    }

    return contador;
}

/**
 *  La funcion convierte los caracteres de una cadena en minúsculas
 *  @param cadena es la cadena a revisar
 *  @pre es un valor numerico entero positivo mayor a uno
 *  @returns
 *  @post 
 */
void minusculas(char cadena[])
{
    int i;
    
    for (i = 0; cadena[i] != 0; i++)
    {
        if (cadena[i] >= 'A' && cadena[i] <= 'Z')
        {
            cadena[i] += 32;
        }
    }
    printf("Cadena minúsculas: %s\n", cadena);
}

/**
 *  La funcion revisa si una cadena es un palíndromo
 *  @param cadena es la cadena a revisar
 *  @pre es un valor numerico entero positivo mayor a uno
 *  @returns TRUE o FALSE
 *  @post 
 */
int palindromo_seguro(char cadena[])
{
    int i;
    int largo_cadena = largo_inseguro(cadena);

    for (i = 0; i < largo_cadena / 2; i++)
    {
        if (cadena[i] != cadena[largo_cadena - i - 1])
        {
            return FALSE;
        }
    }
    return TRUE;
}

#define CAPACIDAD 32

int main(int argc, char *argv[])
{

    char *cadena1 = argv[1];
    char *cadena2 = argv[2];
    int posicion = atoi(argv[3]);
    char cadena_intermedia[CAPACIDAD];
    int resultado = 0;
    int i;

    printf("Cadena 1: %s\n", cadena1);
    printf("Cadena 2: %s\n", cadena2);


    printf("Largo de cadenas:\n");
    printf("Cadena 1: %i\n", largo_seguro(cadena1, CAPACIDAD));
    printf("Cadena 2: %i\n", largo_seguro(cadena2, CAPACIDAD));


    printf("\nInserción:\n");
    for (i = 0; i < CAPACIDAD; i++)
    {
        cadena_intermedia[i] = cadena2[i];
    }
    resultado = insercion_segura(cadena_intermedia, cadena1, CAPACIDAD, posicion);
    printf("Largo de cadena 1: %i\n", resultado);
    for (i = 0; i < CAPACIDAD; i++)
    {
        cadena_intermedia[i] = cadena1[i];
    }
    resultado = insercion_segura(cadena_intermedia, cadena2, CAPACIDAD, posicion);
    printf("Largo de cadena 2: %i\n", resultado);

    printf("\nLimpieza:\n");
    for (i = 0; i < CAPACIDAD; i++)
    {
        cadena_intermedia[i] = cadena1[i];
    }
    resultado = limpieza_segura(cadena_intermedia, cadena1, CAPACIDAD);
    printf("Largo de cadena 1: %i\n", resultado);
    for (i = 0; i < CAPACIDAD; i++)
    {
        cadena_intermedia[i] = cadena2[i];
    }
    resultado = limpieza_segura(cadena_intermedia, cadena2, CAPACIDAD);        
    printf("Largo de cadena 2: %i\n", resultado);


    printf("\nInversor:\n");
    for (i = 0; i < CAPACIDAD; i++)
    {
        cadena_intermedia[i] = cadena1[i];
    }    
    resultado = inversor_seguro(cadena_intermedia, cadena1, CAPACIDAD);
    printf("Largo de cadena 1: %i\n", resultado);
    for (i = 0; i < CAPACIDAD; i++)
    {
        cadena_intermedia[i] = cadena2[i];
    }    
    resultado = inversor_seguro(cadena_intermedia, cadena2, CAPACIDAD);
    printf("Largo de cadena 2: %i\n", resultado);


    printf("Comparación:\n");
    resultado = comparacion_segura(cadena1, cadena2);
    printf("%i\n", resultado);

    resultado = comparacion_segura(cadena2, cadena1);
    printf("%i\n", resultado);

    resultado = comparacion_segura(cadena1, cadena1);
    printf("%i\n", resultado);


    printf("Contar caracteres:\n");
    resultado = contador_caracteres(cadena1);
    printf("%i\n", resultado);

    resultado = contador_caracteres(cadena2);
    printf("%i\n", resultado);

    printf("Contar símbolos:\n");
    resultado = contador_simbolos(cadena1);
    printf("%i\n", resultado);

    resultado = contador_simbolos(cadena2);
    printf("%i\n", resultado); 


    printf("Minúsculas:\n");
    minusculas(cadena1);
    minusculas(cadena2); 

    printf("Palíndromo:\n");
    resultado = palindromo_seguro(cadena1);
    printf("%i\n", resultado);
    resultado = palindromo_seguro(cadena2);
    printf("%i\n", resultado);

    printf("\nCopia:\n");
    for (i = 0; i < CAPACIDAD; i++)
    {
        cadena_intermedia[i] = cadena1[i];
    }
    resultado = copia_segura(cadena_intermedia, cadena2, CAPACIDAD);
    printf("Largo de cadena 1: %i\n", resultado);
    for (i = 0; i < CAPACIDAD; i++)
    {
        cadena_intermedia[i] = cadena2[i];
    }
    resultado = copia_segura(cadena_intermedia, cadena1, CAPACIDAD);
    printf("Largo de cadena 2: %i\n", resultado);

    return 0;
}
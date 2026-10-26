

#include <stdio.h>

#define CADENA_SIN_TERMINADOR -1
#define TRUE 1
#define FALSE 0
#define BUFFER_SIZE 100

/**
 * La función muestra en pantalla un arreglo de largo especificado previamente.
 *  @param arreglo la cadena a mostrar en pantalla.
 *  @pre int válido con signo.
 *  @param capacidad la capacidad del arreglo, previamente estipulado por el usuario.
 *  @pre es un valor numerico entero positivo mayor a uno.
 *  @returns 0.
 *  @post 0.
 */
// int muestra_arreglo(int capacidad, char arreglo[])
// {
//     printf("El arreglo es:\n");
//     for (int i = 0; i < capacidad; i++)
//     {
//         printf("%d, ", arreglo[i]);
//     }
//     printf("\n");
//     return 0;
// }

/**
 * La función cuenta el largo de una cadena de manera segura.
 *  @param cadena la cadena a verificar.
 *  @pre char válidos, no nula con su caracter de terminación \0.
 *  @param capacidad la capacidad del arreglo, previamente estipulado por el usuario.
 *  @pre es un valor numerico entero positivo mayor a uno.
 *  @returns -1 o 1 dependiendo de si la cadena tiene su terminador.
 *  @post int.
 */
int largo_seguro(char cadena[], int capacidad)
{
    int i = 0;
    while (i < capacidad && cadena[i] != '\0')
    {
        i++;
    }
    if (i == capacidad)
    {
        return CADENA_SIN_TERMINADOR;
    }
    else
    {
        return i;
    }
}

/**
 * La función cuenta el largo de una cadena de manera segura.
 *  @param cadena la cadena a verificar.
 *  @pre char válidos, no nula con su caracter de terminación \0.
 *  @returns el número de caracteres en la cadena.
 *  @post int.
 */
int largo_inseguro(char cadena[])
{
    int i = 0;
    
    while (cadena[i] != '\0')
    {
        i++;
    }
    return i;
}

/**
 * La función cuenta el largo de una cadena de manera segura.
 *  @param original la cadena a copiar.
 *  @pre char válidos. Debe ser igual o más larga que la cadena copiada.
 *  @param copia la cadena copiada.
 *  @pre char válidos. Debe ser igual o más corta que la cadena original.
 *  @param capacidad_destino el largo máximo de la cadena copia.
 *  @pre int sin signo mayor a 1.
 *  @returns el largo de caracteres de la cadena.
 *  @post se copia la cadena original dentro de la cadena copia y devuelve el número de caracteres.
 */
int fotocopiadora_de_cadenas(char original[], char copia[], int capacidad_destino)
{
    int largo_fuente = 0;
    int i;
    int ret;
    
    largo_fuente = largo_inseguro(original);
    if (largo_fuente > capacidad_destino)
    {
        ret = CADENA_SIN_TERMINADOR;
    }
    else
    {
        for (i = 0; i < largo_fuente; i++)
        {
            copia[i] = original[i];
        }
            original[0] = 0;
            copia[largo_fuente] = 0;
            printf("Cadena copiada: %s\n", copia);
            ret = largo_fuente;
    }
    return ret;
}

/**
 *  La funcion inserta caracteres de una cadena en otra aumentando la capacidad del arreglo de ser necesario
 *  @param destino es la direccion de la cadena que recibe los nuevos valores de fuente.
 *  @pre char válidos, no nula con su caracter de terminación \0.
 *  @param fuente es la direccion de la cadena que entrega los valores a destino .
 *  @pre char válidos, no nula con su caracter de terminación \0.
 *  @param capacidad_destino la capacidad máxima establecida para destino.
 *  @pre int sin signo mayor a 1.
 *  @param posicion el punto en el que se espera insertar los valores de fuente.
 *  @pre int sin signo mayor o igual a 0.
 *  @returns int el nuevo largo combinado de destino, en caso de ser requerido expandirlo.
 *  @post largo total, int sin signo.
 */
int insertador_de_cadenas(char destino[], char fuente[], int capacidad_destino, int posicion)
{
    int espacio_libre = 0;
    int largo_destino = 0;
    int largo_fuente = 0;
    int i;
    int ret;

    largo_destino = largo_seguro(destino, capacidad_destino);
    largo_fuente = largo_inseguro(fuente);

    espacio_libre = capacidad_destino - largo_destino;

    if (espacio_libre < largo_destino)
    {
        ret = CADENA_SIN_TERMINADOR;
    }
    else
    {
        for (i = 0; i < largo_fuente; i++)
        {
            destino[posicion + largo_fuente + i] = destino[posicion + i];
            destino[posicion + i] = fuente[i];
        }
        destino[largo_destino + largo_fuente] = 0;
        printf("Cadena insertada: %s\n", destino);
        ret = largo_destino + largo_fuente;
    }
    return ret;
}

/**
 *  La funcion escribe una cadena que solo guarde los caracteres alfanuméricos de otra.
 *  @param destino es la direccion de la cadena que recibe los nuevos valores de fuente.
 *  @pre char válidos, no nula con su caracter de terminación \0.
 *  @param fuente es la direccion de la cadena que entrega los valores a destino.
 *  @pre char válidos, no nula con su caracter de terminación \0.
 *  @param capacidad_destino la capacidad máxima establecida para destino.
 *  @pre int sin signo mayor a 1.
 *  @returns numero de caracteres de la nueva cadena.
 *  @post int sin signo mayor a 1.
 */
int limpieza_de_cadenas(char destino[], char fuente[], int capacidad_destino)
{
    int i = 0;
    int j = 0;

    while (fuente[i] != '\0' && j < capacidad_destino - 1)
    {
        if ((fuente[i] >= 'A' && fuente[i] <= 'Z') ||
            (fuente[i] >= 'a' && fuente[i] <= 'z') ||
            (fuente[i] >= '0' && fuente[i] <= '9'))
        {
            destino[j] = fuente[i];
            j++;
        }
        i++;
    }

    destino[j] = '\0';
    printf("Cadena limpia: %s\n", destino);
    return j;
}

/**
 * La función indica y compara el ordenamiento alfabético de dos cadenas distintas.
 *  @param primera es la primer cadena a comparar. 
 *  @param segunda es la segunda cadena a comparar.
 *  @pre primera y segunda son char válidas con el caracter de terminación.
 *  @returns -1 si primera va antes, 1 si primera va después, 0 si son iguales.
 *  @post -1, 0, 1.
 */
int comparacion_de_cadenas(char primera[], char segunda[])
{
    int i;
    int ret;

    for (i = 0;; i++)
    {
        if (primera[i] == 0 && segunda[i] == 0)
        {
            ret = 0;
        }
        else if (primera[i] < segunda[i])
        {
            ret = -1;
        }
        else if (primera[i] > segunda[i])
        {
            ret = 1;
        }   
    }
    return ret;
}

/**
 * La función transforma una cadena reemplazando las mayúsculas por minúsculas.
 *  @param cadena es la cadena a operar.
 *  @pre cadena tiene char válidos con el caracter de terminación.
 *  @post cadena tiene todos sus char en minúscula.
 */
void minusculas(char cadena[])
{
    int i;
    for (i = 0; cadena[i] != 0; i++)
    {
        if (cadena[i] >= 'A' && cadena[i] <= 'Z')
        {
            cadena[i] = cadena[i] + 32; //ASCII tables magic
        }
    }
    printf("Cadena en minúsculas: %s\n", cadena);
}

/**
 * La función devuelve TRUE si la cadena es un palíndromo y FALSE si no lo es.
 *  @param cadena es la cadena a revisar.
 *  @pre cadena tiene char válidos con el caracter de terminación.
 *  @returns TRUE si cadena es palíndromo, FALSE si no lo es, o el error correspondiente.
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

int main()
{
    char cadena[BUFFER_SIZE];
    char copia[BUFFER_SIZE];
    char operar[BUFFER_SIZE];
    int capacidad = 100;
    int largo = 0;
    int largo_copia;
    int opcion;
    int resultado;
    int posicion;
    int i;

    printf("Ingrese una cadena de texto:\n");
    scanf("%[^\n]99s", cadena); //this wasn't on the guide
    largo = largo_seguro(cadena, capacidad);

    printf("Elija la tarea a realizar:\n1.Largo de cadena.\n");
    printf("2.Copia de cadenas.\n3.Inserción de cadenas.\n");
    printf("4.Limpieza.\n5.Comparación.\n6.A minúsculas.\n");
    printf("7.Palíndromo seguro.\n");

    do
    {
        printf("Seleccione la operación a realizar: ");
        scanf("%d", &opcion);

        switch (opcion)
        {
            case 0:
                break;
            case 1:
                printf("1.Largo de cadena.\n");
                if (largo >= 0)
                {
                    printf("El largo de la cadena escrita es %d.\n", largo);
                }
                else
                {
                    printf("Largo %d es erroneo.\n", largo);
                }

                printf("Por favor elija otra opción a realizar: ");
                scanf("%d", &opcion);
                break;
            case 2:
                printf("2.Copia de cadena.\n");
                resultado = fotocopiadora_de_cadenas(cadena, copia, BUFFER_SIZE);
                if (resultado == CADENA_SIN_TERMINADOR)
                {
                    printf("Espacio insuficiente.\n");
                    return 1;
                }

                printf("Por favor elija otra opción a realizar: ");
                scanf("%d", &opcion);
                break;
            case 3:
                printf("3.Inserción de cadenas.\n");
                printf("Escriba la cadena a insertar:\n");
                scanf("%99s", operar);
                printf("Escriba la posición donde insertar la nueva cadena:\n");
                scanf("%d", &posicion);
                
                resultado = insertador_de_cadenas(cadena, operar, BUFFER_SIZE, posicion);
                if (resultado == CADENA_SIN_TERMINADOR)
                {
                    printf("Espacio insuficiente.\n");
                    return 1;
                }

                printf("Por favor elija otra opción a realizar: ");
                scanf("%d", &opcion);
                break;
            case 4:
                printf("4.Limpieza.\n");
                
                resultado = limpieza_de_cadenas(operar, cadena, BUFFER_SIZE);
                
                if (resultado == CADENA_SIN_TERMINADOR)
                {
                    printf("Espacio insuficiente.\n");
                    return 1;
                }
                
                printf("Por favor elija otra opción a realizar: ");
                scanf("%d", &opcion);
                break;
            case 5:
                printf("Comparación.\n");
                printf("Ingrese la segunda cadena a comparar:\n");
                scanf("%99s", operar);
                resultado = comparacion_de_cadenas(cadena, operar);
                printf("El resultado de la comparación es %d.\n", resultado);

                printf("Por favor elija otra opción a realizar: ");
                scanf("%d", &opcion);
                break;
            case 6:
                printf("6.A minúsculas.\n");
                minusculas(cadena);

                printf("Por favor elija otra opción a realizar: ");
                scanf("%d", &opcion);
                break;
            case 7:
                printf("7.Palíndromo seguro.\n");
                resultado = palindromo_seguro(cadena);
                if (resultado == CADENA_SIN_TERMINADOR)
                {
                    printf("Espacio insuficiente.\n");
                    return 1;
                }
                printf("La cadena %s palíndromo.\n", resultado ? "es" : "no es");

                printf("Por favor elija otra opción a realizar: ");
                scanf("%d", &opcion);
                break;
        }
    } while (opcion > 0);
    
    return 0;
}
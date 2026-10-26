

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define CADENA_SIN_TERMINADOR -1
#define TAMANO_CADENA 100
#define TRUE 1
#define FALSE 0

#define UNO 1    //  1 indica que la función no ignora ningún caracterer
#define DOS 2    //  2 indica que la función ignora solamente las minusculas/mayusculas
#define TRES 3   //  3 indica que la función ignora solamente los simbolos
#define CUATRO 4 //  4 indica que la función ignora minusculas/mayusculas y simbolos

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
 *  @post devuelve la cantidad de caracteres de la cadena o un código de error que indica que no tiene terminador
 */
int largo_seguro(char cadena[], int capacidad)
{
    int caracter = 0;
    while (cadena[caracter] != '\0' && caracter <= capacidad)
    {
        caracter++;
    }
    if (caracter >= capacidad)
    {
        return CADENA_SIN_TERMINADOR;
    }
    return caracter;
}

/**
 *  La funcion copia una cadena en otra
 *  @param cadena es la direccion de la cadena que se copiará en la cadena_destino
 *  @pre cadena es un puntero no nulo
 *  @param cadena_destino es la direccion de la cadena en la que se copiara "cadena"
 *  @pre cadena es un puntero no nulo
 *  @param capacidad_cadena la capacidad_cadena es un número distinto a el largo de la cadena en si
 *                   y es el tamaño en memoria del arreglo
 *  @pre es un valor numerico entero positivo mayor a uno
 *  @param capacidad_cadena_destino la capacidad_cadena_destino un número distinto a el largo de la cadena en si
 *                   y es el tamaño en memoria del arreglo
 *  @pre es un valor numerico entero positivo mayor a uno
 *  @returns int en donde los valores positivos incluyendo el cero representan la longitud de cadena_destino
        y CADENA_SIN_TERMINADOR que representa que ocurrio algun error
 *  @post devuelve el largo de la cadena_destino o un código de error que indica un error
 */
int copia_cadenas_seguro(char cadena[], char cadena_destino[], int capacidad_cadena, int capacidad_cadena_destino)
{
    int longitud_cadena = largo_seguro(cadena, capacidad_cadena);
    int longitud_cadena_destino = largo_seguro(cadena_destino, capacidad_cadena_destino);
    for (int i = 0; i <= longitud_cadena; i++)
    {
        cadena_destino[longitud_cadena_destino + i] = cadena[i];
    }
    cadena_destino[longitud_cadena_destino + longitud_cadena] = '\0';
    return longitud_cadena + longitud_cadena_destino;
}

/**
 *  La función inserta una cadena en otra luego de la posición indicada de manera segura
 *  @param cadena es la direccion de la cadena que se insertará en la "cadena_destino"
 *  @pre cadena es un puntero no nulo
 *  @param cadena_destino es la direccion de la cadena en la que se insertará "cadena"
 *  @pre cadena es un puntero no nulo
 *  @param posicion posición de "cadena_destino" en la que se insertará "cadena"
 *  @pre es un valor numerico entero positivo mayor a uno dentro del rango de la longitud de "cadena_destino"
 *  @param capacidad_cadena la capacidad_cadena es un número distinto a el largo de la cadena en si
 *                   y es el tamaño en memoria del arreglo
 *  @pre es un valor numerico entero positivo mayor a uno
 *  @param capacidad_cadena_destino la capacidad_cadena_destino un número distinto a el largo de la cadena en si
 *                   y es el tamaño en memoria del arreglo
 *  @pre es un valor numerico entero positivo mayor a uno
 *  @returns int en donde los valores positivos incluyendo el cero representan la cantidad de caracteres
 *       y los valores negativos, las siguientes situaciones de error:
 *          CADENA_SIN_TERMINADOR cuando la posición de insersión sea mayor a la longitud de cadena_destino
 *  @post devuelve el largo de la cadena_destino o un código de error que indica la posición a insertar
 *          es mayor a la longitud de cadena_destino
 */
int insercion_cadenas_seguro(char cadena[], char cadena_destino[], int posicion, int capacidad_cadena, int capacidad_cadena_destino)
{
    char copia_cadena_destino[TAMANO_CADENA] = "";
    int longitud_cadena = largo_seguro(cadena, capacidad_cadena);
    int longitud_cadena_destino = largo_seguro(cadena_destino, capacidad_cadena_destino);
    int posicion_insercion = posicion + 1;
    copia_cadenas_seguro(cadena_destino, copia_cadena_destino, capacidad_cadena_destino, capacidad_cadena_destino);
    if (posicion_insercion > longitud_cadena_destino)
    {
        return CADENA_SIN_TERMINADOR;
    }
    for (int i = 0; i <= longitud_cadena_destino; i++)
    {
        if (i < posicion_insercion)
        {
            cadena_destino[i] = copia_cadena_destino[i];
        }
        if (i == posicion_insercion)
        {
            for (int j = 0; j < longitud_cadena; j++)
            {
                cadena_destino[i + j] = cadena[j];
            }
        }
        if (i >= posicion_insercion)
        {
            cadena_destino[i + longitud_cadena] = copia_cadena_destino[i];
        }
    }
    cadena_destino[longitud_cadena_destino + longitud_cadena] = '\0';
    return longitud_cadena_destino + longitud_cadena;
}

/**
 *  La funcion limpia la cade de todos los caracteres que no sean alfanumericos (AZaz09) menos el \0
 *  @param cadena es la direccion de la cadena a limpiar
 *  @pre cadena es un puntero no nulo
 *  @param cadena_limpia es la direccion de la copia de "cadena" con los caracteres limpiados
 *  @pre cadena es un puntero no nulo
 *  @param capacidad_cadena la capacidad_cadena es un número distinto a el largo de la cadena en si
 *                   y es el tamaño en memoria del arreglo
 *  @pre es un valor numerico entero positivo mayor a uno
 *  @param capacidad_cadena_limpia la capacidad_cadena_limpia un número distinto a el largo de la cadena en si
 *                   y es el tamaño en memoria del arreglo
 *  @pre es un valor numerico entero positivo mayor a uno
 *  @returns int en donde los valores positivos incluyendo el cero representan la longitud de cadena_limpia
        y CADENA_SIN_TERMINADOR que representa que ocurrio algun error
 *  @post devuelve el largo de la cadena_limpia o un código de error que indica un error
 */
int limpieza_cadena(char cadena[], char cadena_limpia[], int capacidad_cadena, int capacidad_cadena_limpia)
{
    int longitud_cadena = largo_seguro(cadena, capacidad_cadena);
    int longitud_cadena_limpia = 0;
    int cantidad_digitos_limpiados = 0;
    for (int i = 0; i <= longitud_cadena; i++)
    {
        if (isalnum(cadena[i]))
        {
            cadena_limpia[i - cantidad_digitos_limpiados] = cadena[i];
        }
        else
        {
            cantidad_digitos_limpiados++;
        }
    }
    longitud_cadena_limpia = largo_seguro(cadena_limpia, capacidad_cadena_limpia);
    cadena_limpia[longitud_cadena_limpia] = '\0';
    return longitud_cadena_limpia;
}

/**
 *  La funcion devuelve la cadena ingresada invertida
 *  @param cadena es la direccion de la cadena a invertir
 *  @pre cadena es un puntero no nulo
 *  @param capacidad_cadena la capacidad_cadena es un número distinto a el largo de la cadena en si
 *                   y es el tamaño en memoria del arreglo
 *  @pre es un valor numerico entero positivo mayor a uno
 *  @returns no retorna ningún valor (void)
 *  @post no retorna ningún valor (void)
 */
void inversor_cadena(char cadena[], int capacidad_cadena)
{
    int longitud_cadena = largo_seguro(cadena, capacidad_cadena);
    char cadena_copia_inversa[TAMANO_CADENA] = "";
    for (int i = 0; i < longitud_cadena; i++)
    {
        cadena_copia_inversa[i] = cadena[longitud_cadena - 1 - i];
    }
    for (int i = 0; i < longitud_cadena; i++)
    {
        cadena[i] = cadena_copia_inversa[i];
    }
}

/**
 *  La funcion compara las dos cadenas ingresadas y indica cual es el ordenamiento alfabetico
 *  @param cadena es la direccion de la cadena que se comparará con "otra_cadena"
 *  @pre cadena es un puntero no nulo
 *  @param otra_cadena es la direccion de la cadena que se comparará con "cadena"
 *  @pre cadena es un puntero no nulo
 *  @param capacidad_cadena la capacidad_cadena es un número distinto a el largo de la cadena en si
 *                   y es el tamaño en memoria del arreglo
 *  @pre es un valor numerico entero positivo mayor a uno
 *  @param capacidad_otra_cadena la capacidad_otra_cadena un número distinto a el largo de la cadena en si
 *                   y es el tamaño en memoria del arreglo
 *  @pre es un valor numerico entero positivo mayor a uno
 *  @returns int en donde los valores:
 *              -1 indica que la primera cadena va antes de que las segunda
 *              0 indica que ambas cadenas son iguales
 *              1 indica que la primera cadena va después que la segunda
 *  @post devuelve un entero que indica el ordenamiento alfabetico
 */
int comparacion_cadena(char cadena[], char otra_cadena[], int capacidad_cadena, int capacidad_otra_cadena)
{
    int longitud_cadena = largo_seguro(cadena, capacidad_cadena);
    int longitud_otra_cadena = largo_seguro(otra_cadena, capacidad_otra_cadena);
    if (longitud_cadena >= longitud_otra_cadena)
    {
        for (int i = 0; i < longitud_cadena; i++)
        {
            if (cadena[i] == otra_cadena[i])
            {
                continue;
            }
            else if (cadena[i] > otra_cadena[i])
            {
                return 1;
            }
            else
            {
                return -1;
            }
        }
    }
    else
    {
        for (int i = 0; i < longitud_otra_cadena; i++)
        {
            if (cadena[i] == otra_cadena[i])
            {
                continue;
            }
            else if (cadena[i] > otra_cadena[i])
            {
                return 1;
            }
            else
            {
                return -1;
            }
        }
    }
    return 0;
}

/**
 *  La funcion cuenta los caracteres alfanumericos de un arreglo
 *  @param cadena es la direccion de la cadena que se contarán sus caracteres
 *  @pre cadena es un puntero no nulo
 *  @param capacidad_cadena la capacidad_cadena es un número distinto a el largo de la cadena en si
 *                   y es el tamaño en memoria del arreglo
 *  @pre es un valor numerico entero positivo mayor a uno
 *  @returns int en donde los valores positivos incluyendo el cero representan la cantidad de caracteres
 *  @post devuelve la cantidad de caracteres alfanumericos de la cadena ingresada
 */
int contador_caracteres(char cadena[], int capacidad_cadena)
{
    char cadena_caracteres[TAMANO_CADENA] = "";
    int longitud_cadena_caracteres = limpieza_cadena(cadena, cadena_caracteres, capacidad_cadena, capacidad_cadena);
    return longitud_cadena_caracteres;
}

/**
 *  La funcion cuenta los simbolos de un arreglo
 *  @param cadena es la direccion de la cadena que se contarán sus simbolos
 *  @pre cadena es un puntero no nulo
 *  @param capacidad_cadena la capacidad_cadena es un número distinto a el largo de la cadena en si
 *                   y es el tamaño en memoria del arreglo
 *  @returns int en donde los valores positivos incluyendo el cero representan la cantidad de simbolos
 *  @post devuelve la cantidad de simbolos de la cadena ingresada
 */
int contador_simbolos(char cadena[], int capacidad_cadena)
{
    char cadena_simbolos[TAMANO_CADENA] = "";
    int longitud_cadena = largo_seguro(cadena, capacidad_cadena);
    int longitud_cadena_simbolos = 0;
    int cantidad_digitos_limpiados = 0;
    for (int i = 0; i < longitud_cadena; i++)
    {
        if (!isalnum(cadena[i]))
        {
            cadena_simbolos[i - cantidad_digitos_limpiados] = cadena[i];
        }
        else
        {
            cantidad_digitos_limpiados++;
        }
    }
    longitud_cadena_simbolos = largo_seguro(cadena_simbolos, capacidad_cadena);
    cadena_simbolos[longitud_cadena_simbolos] = '\0';
    return longitud_cadena_simbolos;
}

/**
 *  La funcion convierte un arreglo dejando todos sus caracteres en minusculas
 *  @param cadena es la direccion de la cadena que se pasará a minuscula
 *  @pre cadena es un puntero no nulo
 *  @param capacidad_cadena la capacidad_cadena es un número distinto a el largo de la cadena en si
 *                   y es el tamaño en memoria del arreglo
 *  @returns no retorna ningún valor (void)
 *  @post no retorna ningún valor (void)
 */
void convertir_a_minuscula(char cadena[], int capacidad_cadena)
{
    int longitud_cadena = largo_seguro(cadena, capacidad_cadena);
    for (int i = 0; i < longitud_cadena; i++)
    {
        cadena[i] = tolower(cadena[i]);
    }
}

/**
 *  La funcion convierte un arreglo dejando todos sus caracteres en mayuscula
 *  @param cadena es la direccion de la cadena que se pasará a mayuscula
 *  @pre cadena es un puntero no nulo
 *  @param capacidad_cadena la capacidad_cadena es un número distinto a el largo de la cadena en si
 *                   y es el tamaño en memoria del arreglo
 *  @returns no retorna ningún valor (void)
 *  @post no retorna ningún valor (void)
 */
void convertir_a_mayuscula(char cadena[], int capacidad_cadena)
{
    int longitud_cadena = largo_seguro(cadena, capacidad_cadena);
    for (int i = 0; i < longitud_cadena; i++)
    {
        cadena[i] = toupper(cadena[i]);
    }
}

/**
 *  La funcion indica si una cadena es un palindromo
 *  @param cadena es la direccion de la cadena que se evaluará si es palindromo
 *  @pre cadena es un puntero no nulo
 *  @param opcion es el numero entero que representa la opción de sensibilidad de la función:
 *              1 indica que la función no ignora ningún caracterer
 *              2 indica que la función ignora solamente las minusculas/mayusculas
 *              3 indica que la función ignora solamente los simbolos
 *              4 indica que la función ignora minusculas/mayusculas y simbolos
 *  @pre opcion es un numero entero entre 1 y 4 inclusives
 *  @param capacidad_cadena la capacidad_cadena es un número distinto a el largo de la cadena en si
 *                   y es el tamaño en memoria del arreglo
 *  @returns int en donde los valores:
 *              -2 indica que el valor de opcion ingresado no esta definido
 *              -1 indica que la cadena no posee '\0'
 *              0 indica que la cadena no es palindromo
 *              1 indica que la cadena si es palindromo
 *  @post devuelve un entero que indica si una cadena es palindromo
 */
int es_palindromo(char cadena[], int opcion, int capacidad_cadena)
{
    int longitud_texto = largo_seguro(cadena, capacidad_cadena);
    int contador_similitudes = 0;
    char cadena_limpia[TAMANO_CADENA] = "";
    if (opcion < UNO || opcion > CUATRO)
    {
        return -2;
    }
    if (opcion == DOS || opcion == TRES)
    {
        longitud_texto = limpieza_cadena(cadena, cadena_limpia, capacidad_cadena, capacidad_cadena);
    }
    else
    {
        longitud_texto = largo_seguro(cadena, capacidad_cadena);
    }
    if (longitud_texto == CADENA_SIN_TERMINADOR)
    {
        return CADENA_SIN_TERMINADOR;
    }
    for (int i = 0; i < longitud_texto; i++)
    {
        switch (opcion)
        {
        case UNO:
            if (cadena[i] == cadena[longitud_texto - 1 - i])
            {
                contador_similitudes = contador_similitudes + 1;
            }
            break;
        case DOS:
            if (tolower(cadena[i]) == tolower(cadena[longitud_texto - 1 - i]))
            {
                contador_similitudes = contador_similitudes + 1;
            }
            break;
        case TRES:
            if (cadena_limpia[i] == cadena_limpia[longitud_texto - 1 - i])
            {
                contador_similitudes = contador_similitudes + 1;
            }
            break;
        case CUATRO:
            if (tolower(cadena_limpia[i]) == tolower(cadena_limpia[longitud_texto - 1 - i]))
            {
                contador_similitudes = contador_similitudes + 1;
            }
            break;
        default:
            break;
        }
    }
    if (contador_similitudes == longitud_texto)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

int main(int argc, char *argv[])
{
    int posicion_insercion = atoi(argv[3]);
    int opcion_palindromo = atoi(argv[4]);
    char nombre_opcion_palindromo[TAMANO_CADENA] = "";
    int longitud_primer_parametro = largo_seguro(argv[1], TAMANO_CADENA);
    int longitud_segundo_parametro = largo_seguro(argv[2], TAMANO_CADENA);
    int longitud_cadena_insercion = 0;
    int longitud_cadena_copia = 0;
    int longitud_cadena_limpia = 0;
    int orden_cadenas = 0;
    int cantidad_caracteres_alfanumericos = 0;
    int cantidad_simbolos = 0;
    int es_palindromo_var = 0;
    char cadena[TAMANO_CADENA] = "";
    char cadena_limpia[TAMANO_CADENA] = "";
    char cadena_invertida[TAMANO_CADENA] = "";
    char cadena_minuscula[TAMANO_CADENA] = "";
    char cadena_mayuscula[TAMANO_CADENA] = "";
    char otra_cadena[TAMANO_CADENA] = "";
    char otra_cadena_insercion[TAMANO_CADENA] = "";
    char otra_cadena_copia[TAMANO_CADENA] = "";
    for (int i = 0; i <= longitud_primer_parametro; i++)
    {
        cadena[i] = argv[1][i];
        cadena_invertida[i] = argv[1][i];
        cadena_minuscula[i] = argv[1][i];
        cadena_mayuscula[i] = argv[1][i];
    }
    for (int j = 0; j <= longitud_segundo_parametro; j++)
    {
        otra_cadena[j] = argv[2][j];
        otra_cadena_insercion[j] = argv[2][j];
        otra_cadena_copia[j] = argv[2][j];
    }
    if (longitud_primer_parametro == -1 && longitud_segundo_parametro == -1)
    {
        printf("El parametro1 y el parametro 2 no tienen terminadores\n");
        return 0;
    }
    else if (longitud_primer_parametro == -1)
    {
        printf("El parametro1 no tiene terminador\n");
        return 0;
    }
    else if (longitud_segundo_parametro == -1)
    {
        printf("El parametro2 no tiene terminador\n");
        return 0;
    }
    printf("La longitud de '%s' es: %d\n", cadena, longitud_primer_parametro);
    printf("La longitud de '%s' es: %d\n", otra_cadena, longitud_segundo_parametro);
    longitud_cadena_insercion = insercion_cadenas_seguro(cadena, otra_cadena_insercion, posicion_insercion, TAMANO_CADENA, TAMANO_CADENA);
    if (longitud_cadena_insercion == -1)
    {
        printf("La posicion '%d' de insercion es mayor a la longitud de '%s'\n", posicion_insercion, otra_cadena);
    }
    else
    {
        printf("Longitud de insertar '%s' en la posicion %d de '%s' = %d -> '%s'\n", cadena, posicion_insercion,
                otra_cadena, longitud_cadena_insercion, otra_cadena_insercion);
    }
    longitud_cadena_copia = copia_cadenas_seguro(cadena, otra_cadena_copia, TAMANO_CADENA, TAMANO_CADENA);
    printf("Longitud de copiar '%s' en '%s' = %d -> '%s'\n", cadena, otra_cadena, longitud_cadena_copia, otra_cadena_copia);
    longitud_cadena_limpia = limpieza_cadena(cadena, cadena_limpia, TAMANO_CADENA, TAMANO_CADENA);
    printf("Longitud de limpiar '%s' = %d -> '%s'\n", cadena, longitud_cadena_limpia, cadena_limpia);
    inversor_cadena(cadena_invertida, TAMANO_CADENA);
    printf("Inversor: '%s' -> '%s'\n", cadena, cadena_invertida);
    printf("Comparacion cadenas:\n");
    orden_cadenas = comparacion_cadena(cadena, otra_cadena, TAMANO_CADENA, TAMANO_CADENA);
    if (orden_cadenas == -1)
    {
        printf("    1- %s\n    2- %s\n", cadena, otra_cadena);
    }
    else if (orden_cadenas == 1)
    {
        printf("    1- %s\n    2- %s\n", otra_cadena, cadena);
    }
    else
    {
        printf("    1- %s\n    1- %s\n", cadena, otra_cadena);
    }
    cantidad_caracteres_alfanumericos = contador_caracteres(cadena, TAMANO_CADENA);
    printf("Caracteres alfanumericos: '%s' -> '%d'\n", cadena, cantidad_caracteres_alfanumericos);
    cantidad_simbolos = contador_simbolos(cadena, TAMANO_CADENA);
    printf("Simbolos: '%s' -> '%d'\n", cadena, cantidad_simbolos);
    convertir_a_minuscula(cadena_minuscula, TAMANO_CADENA);
    printf("Convertir a minuscula: '%s' -> '%s'\n", cadena, cadena_minuscula);
    convertir_a_mayuscula(cadena_mayuscula, TAMANO_CADENA);
    printf("Convertir a mayuscula: '%s' -> '%s'\n", cadena, cadena_mayuscula);
    if (opcion_palindromo == 0)
    {
        printf("'%s' no es una opcion valida para la funcion es_palindromo()\n", argv[4]);
    }
    else
    {
        es_palindromo_var = es_palindromo(cadena, opcion_palindromo, TAMANO_CADENA);
        switch (opcion_palindromo)
        {
        case 1:
            copia_cadenas_seguro("Mayus/Minus ACTIVADO y Simbolos ACTIVADO", nombre_opcion_palindromo, TAMANO_CADENA, TAMANO_CADENA);
            break;
        case 2:
            copia_cadenas_seguro("Mayus/Minus DESCATIVADO y Simbolos ACTIVADO", nombre_opcion_palindromo, TAMANO_CADENA, TAMANO_CADENA);
            break;
        case 3:
            copia_cadenas_seguro("Mayus/Minus ACTIVADO y Simbolos DESACTIVADO", nombre_opcion_palindromo, TAMANO_CADENA, TAMANO_CADENA);
            break;
        case 4:
            copia_cadenas_seguro("Mayus/Minus DESACTIVADO y Simbolos DESACTIVADO", nombre_opcion_palindromo, TAMANO_CADENA, TAMANO_CADENA);
            break;
        default:
            break;
        }
        if (es_palindromo_var == TRUE)
        {
            printf("'%s' es palindromo (%s)? Si\n", cadena, nombre_opcion_palindromo);
        }
        else if (es_palindromo_var == FALSE)
        {
            printf("'%s' es palindromo (%s)? No\n", cadena, nombre_opcion_palindromo);
        }
        else if (es_palindromo_var == -2)
        {
            printf("'%d' no es una opcion valida para la funcion es_palindromo()\n", opcion_palindromo);
        }
        else
        {
            printf("'%s' no tiene terminador\n", cadena);
        }
    }
}
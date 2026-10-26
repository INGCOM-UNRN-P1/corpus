

#include <stdio.h>

#define TAMANO 10
#define TRUE 1
#define FALSE 0
#define CADENA_SIN_TERMINADOR -1
#define NO_HAY_LUGAR_INSERTAR -2

/**
 * La funcion permite el ingreso de caracteres para crear un cadena.
 *  @param cadena es la direccion de la cadena en la que se ingresaran los caracteres
 *  @pre es una cadena valida
 *  @returns 
 *  @post una cadena con valores ingresados por consola
 */
int cargar_cadena(char cadena[])
{
    printf("Ingrese una cadena para empezar el programa: ");
    scanf("%s", cadena);
}

/**
 * La funcion permite mostrar por pantalla una cadena.
 *  @param cadena es la direccion de la cadena en la que se ingresaran los caracteres
 *  @pre es una cadena valida
 *  @returns 
 *  @post muestra por consola el contenido de la caneda
 */
int muestra_cadena(char cadena[])
{
    printf("La cadena queda de la siguiente manera: %s \n", cadena);
}

/**
 * La funcion cuenta los caracteres de la cadena sin exceder la capacidad del arreglo indicada.
 *  @param cadena es la direccion de la cadena con la que se contaran los caracteres
 *  @pre cadena es una cadena valida
 *  @param capacidad la capacidad es es el tamaño en memoria de el arreglo
 *  @pre es un numero entero positivo mayor a uno
 *  @returns un numero entero en donde los valores positivos incluyendo el cero representan la cantidad de caracteres
         y los valores negativos, la siguiente situacion de error:
            CADENA_SIN_TERMINADOR cuando la cantidad de caracteres sea por lo menos igual a la capacidad indicada por el argumento
 *  @post es un valor numerico entero positivo o negativo
 */
int largo_seguro(char cadena[], int capacidad)
{
    int i;
    int largo = 0;

    for(i = 0;i < capacidad; i++)
    {
        if(cadena[i] == '\0')
        {
            return largo;
        }

        largo++;

        if(largo >= capacidad)
        {
            largo = CADENA_SIN_TERMINADOR;
        }
    }

    return largo;
}

/**
 * La funcion copia una cadena en otra y deja solo un \0 en la cadena destino.
 *  @param origen es la direccion de la cadena a la que se van a copiar los valores
 *  @pre origen es una cadena valida
 *  @param destino es la direccion de la cadena de donde se van a copiar los valores
 *  @pre destino es una cadena valida
 *  @param capacidad la capacidad es es el tamaño en memoria de el arreglo
 *  @pre es un numero entero positivo mayor a uno
 *  @returns un numero entero positivo que representa el largo de la cadena origen luego de ser copiada
 *  @post es un valor numerico entero positivo
 */
int copia_cadenas(char origen[], char destino[], int capacidad)
{
    int i;
    int largo_origen = largo_seguro(origen, capacidad);
    int largo_destino = largo_seguro(destino, capacidad);

    if(largo_origen > largo_destino)
    {
        for(i = 0;i < largo_origen; i++)
        {
            origen[i] = destino[i];
            destino[i] = '\0';
            printf("Copiando destino a origen... ");
            muestra_cadena(origen);
        }
    }
    else
    {
        for(i = 0;i < largo_destino; i++)
        {
            origen[i] = destino[i];
            destino[i] = '\0';
            printf("Copiando destino a origen... ");
            muestra_cadena(origen);
        }
    }

    return largo_seguro(origen, capacidad);
}

/**
 * La funcion inserta una cadena en otra en cierta posicion de manera segura.
 *  @param origen es la direccion de la cadena a la que se va a insertar una cadena
 *  @pre origen es una cadena valida
 *  @param insertar es la direccion de la cadena de donde se van a quitar los valores a insertar
 *  @pre insertar es una cadena valida
 *  @param capacidad la capacidad es es el tamaño en memoria de el arreglo
 *  @pre es un numero entero positivo mayor a uno
 *  @param posicion la posicion es el lugar en la cadena origen donde se va a insertar la otra cadena
 *  @pre es un numero entero positivo
 *  @returns un numero entero donde los valores positivos representan el largo de la cadena origen 
 *              luego de completar la insercion y los valores negativos, los siguientes errores:
 *                  CADENA_SIN_TERMINADOR cuando la cantidad de caracteres exceda la capacidad de la cadena
 *                  NO_HAY_LUGAR_INSERTAR cuando no hay lugar para insertar la cadena en origen
 *  @post es un valor numerico entero positivo o negativo
 */
int insercion_cadenas(char origen[], char insertar[], int capacidad, int posicion)
{
    int i;
    int z = 0;
    char temporal[capacidad];
    int largo_insertar = largo_seguro(insertar, capacidad);
    int largo_origen = largo_seguro(origen, capacidad);
    int largo_total = largo_insertar + largo_origen;

    if(largo_total >= capacidad)
	{
		return CADENA_SIN_TERMINADOR;
	}
    
    if(largo_origen < posicion)
    {
        return NO_HAY_LUGAR_INSERTAR;
    }

    for(i = posicion+1;i < largo_total; i++)
    {
        temporal[z] =+ origen[i];
        origen[i] = insertar[z];
        z++;
    }

    z = 0;
    int largo_temporal = largo_seguro(origen, capacidad);
    
    for(i = largo_temporal;i < capacidad; i++)
    {
        origen[i] = temporal[z];
        z++;
    }

    origen[largo_total] = '\0';

    return largo_seguro(origen, capacidad);
}

/**
 * La funcion "limpia" una cadena de todos los caracteres que no sean los alfanuméricos menos el \0 en una cadena diferente a la de entrada.
 *  @param cadena es la direccion de la cadena a limpiar
 *  @pre cadena es una cadena valida
 *  @param cadena_limpia es la direccion de la cadena donde se van a copiar los caracteres alfanúmericos
 *  @pre cadena_limpia es una cadena valida
 *  @param capacidad la capacidad es es el tamaño en memoria de el arreglo
 *  @pre es un numero entero positivo mayor a uno
 *  @returns un numero entero positivo que representa el largo de la cadena limpia
 *  @post es un valor numerico entero positivo
 */
int limpieza_cadena(char cadena[], char cadena_limpia[], int capacidad)
{
    int i;
    int z = 0;
    int largo_cadena = largo_seguro(cadena, capacidad);

    for(i = 0;i < largo_cadena; i++)
    {
        if(cadena[i] > 47 && cadena[i] < 58)
        {
            cadena_limpia[z] = cadena[i];
            z++;
        }
        else if(cadena[i] > 64 && cadena[i] < 91)
        {
            cadena_limpia[z] = cadena[i];
            z++;
        }
        else if(cadena[i] > 96 && cadena[i] < 123)
        {
            cadena_limpia[z] = cadena[i];
            z++;
        }
    }

    cadena_limpia[z] = '\0';

    return largo_seguro(cadena_limpia, capacidad);
}

/**
 * La funcion compara los caracteres de dos cadenas para indicar cual es menor, mayor o si son iguales(solo minúsculas).
 *  @param primer_cadena es la direccion de la primer cadena a comparar
 *  @pre primer_cadena es una cadena valida
 *  @param segunda_cadena es la direccion de la segunda cadena a comparar
 *  @pre segunda_cadena es una cadena valida
 *  @param capacidad la capacidad es es el tamaño en memoria de el arreglo
 *  @pre es un numero entero positivo mayor a uno
 *  @returns un numero entero positivo que representa la comparacion de las cadenas
 *  @post es un valor numerico entero positivo o negativo
 */
int comparacion_cadenas(char primer_cadena[], char segunda_cadena[], int capacidad)
{
    int i;
    int suma_caracteres = 0;
    int segunda_suma_caracteres = 0;
    int verificacion;
    int largo_primer_cadena = largo_seguro(primer_cadena, capacidad);
    int largo_segunda_cadena = largo_seguro(segunda_cadena, capacidad);

    for(i = 0;i < largo_primer_cadena; i++)
    {
        if(primer_cadena[i] > 96 && primer_cadena[i] < 123)
        {
            suma_caracteres += primer_cadena[i];
        }
    }

    for(i = 0;i < largo_segunda_cadena; i++)
    {
        if(segunda_cadena[i] > 96 && segunda_cadena[i] < 123)
        {
            segunda_suma_caracteres += segunda_cadena[i];
        }
    }

    if(suma_caracteres < segunda_suma_caracteres)
    {
        verificacion = -1;
    }
    else if(suma_caracteres > segunda_suma_caracteres)
    {
        verificacion = 1;
    }
    else
    {
        verificacion = 0;
    }

    return verificacion;
}

/**
 * La funcion modifica la cadena dejando todos sus caracteres en minúsculas.
 *  @param cadena es la direccion de la cadena a modificar sus caracteres en mayuscula
 *  @pre cadena es una cadena valida
 *  @param capacidad la capacidad es es el tamaño en memoria de el arreglo
 *  @pre es un numero entero positivo mayor a uno
 *  @returns
 *  @post la cadena sin caracteres en mayuscula
 */
void cadena_minusculas(char cadena[], int capacidad)
{
    int i;
    int largo_cadena = largo_seguro(cadena, capacidad);
    for(i = 0;i < largo_cadena; i++)
    {
        if(cadena[i] > 64 && cadena[i] < 91)
        {
            cadena[i] = cadena[i] + 32;
        }
    }
}

/**
 * La funcion indica si una cadena es palindromo o no.
 *  @param cadena es la direccion de la cadena a comparar sus caracteres
 *  @pre cadena es una cadena valida
 *  @param capacidad la capacidad es es el tamaño en memoria de el arreglo
 *  @pre es un numero entero positivo mayor a uno
 *  @returns un numero entero donde el valor positivo mayor a 0 representa si la cadena es palindromo
 *              y el valor negativo menor a 0 representa que la cadena no es palindromo
 *  @post es un valor numerico entero positivo o negativo que representa si es o no palindromo
 */
int palindromo(char cadena[], int capacidad)
{
    int i;
    int largo_cadena = largo_seguro(cadena, capacidad);
    int z = largo_cadena;
    int caracteres_iguales = 0;
    cadena_minusculas(cadena, capacidad);

    for(i = 0;i < largo_cadena; i++)
    {
        if(cadena[i] == cadena[z-1])
        {
            caracteres_iguales++;
        }
        z--;
    }

    if (caracteres_iguales == largo_cadena)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

int main()
{
    char cadena[TAMANO];
    char segunda_cadena[TAMANO];
    char cadena_limpia[TAMANO];
    int largo;
    int posicion;
    int verificacion;

    // ---- Cargar cadenas/largo cadenas ----

    cargar_cadena(cadena);
    largo = largo_seguro(cadena, TAMANO);

    if(largo < 0)
    {
        printf("Capacidad de cadena excedida.\n");
        return 0;
    }

    printf("Largo de la cadena: %d\n", largo);

    printf("------Segunda cadena------\n");
    cargar_cadena(segunda_cadena);
    largo = largo_seguro(segunda_cadena, TAMANO);

    if(largo < 0)
    {
        printf("Capacidad de cadena excedida.\n");
        return 0;
    }

    printf("Largo de la segunda cadena: %d\n", largo);

    //--- Limpieza ---

    largo = limpieza_cadena(cadena, cadena_limpia, TAMANO);
    printf("\nLuego de la limpieza... ");
    printf("Largo de la cadena limpia: %d\n", largo);
    muestra_cadena(cadena_limpia);

    //--- Comaparacion ---

    verificacion = comparacion_cadenas(cadena, segunda_cadena, TAMANO);
    printf("\nResultado de la comparacion de las cadenas: %d \n", verificacion);
    
    // --- Minusculas ---

    cadena_minusculas(cadena, TAMANO);
    printf("\nSin mayusculas... ");
    muestra_cadena(cadena);

    //--- Palindromo ---

    verificacion = palindromo(cadena, TAMANO);
    printf("\nResultado de palindromo: %d \n", verificacion);
    
    //--- Inserción ---

    printf("\nIngrese la posicion en la que desea insertar la segunda cadena a la primera: ");
    scanf("%d", &posicion);
    largo = insercion_cadenas(cadena, segunda_cadena, TAMANO, posicion);

    if(largo < 0)
    {
        printf("El largo de la insercion excede la capacidad total o la posicion ingresada no es valida.\n");
        return 0;
    }

    muestra_cadena(cadena);

    printf("Largo de la insercion: %d\n\n", largo);

    //--- Copia ---

    largo = copia_cadenas(cadena, segunda_cadena, TAMANO);
    printf("Largo de la copia: %d\n", largo);

    return 0;
}
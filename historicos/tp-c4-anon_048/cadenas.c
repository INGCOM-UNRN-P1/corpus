/****************************** INSTRUCCIONES PARA EL USO DE ARGC,ARGV *******************************
|                                                                                                    |   
|----------------------------------------------------------------------------------------------------|                      
|                       |                            Datos a Ingresar                                |
|-----------------------|----------------------------------------------------------------------------|                      
|    Funcion            |   Opciones seleccionada       Cadena1             Cadena2         Posicion-|
|----------------------------------------------------------------------------------------------------|
|   largo_seguro        |            1                  "Cadena 1.."           -               -     |
|   insercion_de_cadenas|            2                  "Cadena 1.."       "Cadena 2.."      numero  | 
|   copia_de_cadenas    |            3                  "Cadena 1.."       "Cadena 2.."        -     |
|   limpieza            |            4                  "Cadena 1.."           -               -     |
|   inversor            |            5                  "Cadena 1.."           -               -     |
|   comparacion         |            6                  "Cadena 1.."       "Cadena 2.."        -     |
|   contador_caracteres |            7                  "Cadena 1.."           -               -     |
|   contador_simbolos   |            8                  "Cadena 1.."           -               -     |
|   a_minusculas        |            9                  "Cadena 1.."           -               -     |
|   palindromo_seguro   |           10                  "Cadena 1.."           -               -     |
------------------------------------------------------------------------------------------------------
 */

#include <stdio.h>

#define CAPACIDAD 1000
#define CADENA_SIN_TERMINADOR -1
#define CAPACIDAD_INSUFICIENTE -2
#define A_MAYUSCULA 65
#define Z_MAYUSCULA 90
#define A_MINUSCULA 97
#define Z_MINUSCULA 122
#define CERO 48
#define NUEVE 57
#define OPCION_INGRESADA_ARGV 1
#define POSICION_CADENA1_INGRESADA_ARGV 2
#define POSICION_CADENA2_INGRESADA_ARGV 3
#define POSICION_DONDE_INSERTAR_ARGV 4
#define TRUE 1
#define FALSE 0

/**
 * La funcion cuenta los caracteres de la cadena1 sin exceder la capacidad del arreglo indicada.
 *  @param cadena1 es la direccion de la cadena1 con la que se contaran los caracteres
 *  @pre cadena1 es un puntero no nulo
 *  @param capacidad la capacidad es un número distinto a el largo_cadena_ingresada de la cadena1 en si
    y es el tamaño en memoria del arreglo
 *  @pre es un valor numerico entero positivo mayor a uno
 *  @returns int en donde los valores positivos incluyendo el cero representan la cantidad de caracteres
    y los valores negativos, las siguientes situaciones de error:
    CADENA_SIN_TERMINADOR cuando la cantidad de carateres sea por lo menos igual
    a la capacidad indicada por el argumento
 *  @post
 */
int largo_seguro(char cadena1[], int capacidad);

/**
 * La funcion inserta una cadena en otra luego de la posición indicada de manera segura.
 *  @param cadena_a_modificar es la direccion de la cadena1 que sera modificada
 *  @pre cadena1 es un puntero no nulo
 *  @param capacidad_cadena_a_modificar la capacidad es el tamaño en memoria del arreglo
 *  @pre es un valor numerico entero positivo mayor a uno.
 *  @param cadena_a_insertar es la direccion de la cadena2 que sera insertada en cadena1
 *  @pre cadena2 es un puntero no nulo
 *  @param capacidad_cadena_a_insertar la capacidad es el tamaño en memoria del arreglo
 *  @param posicion_donde_instar es la posicion donde se insertara la cadena2 en la cadena1
 *  @pre es un valor numerico entero positivo 
 *  @returns int en donde la función debe retornar el largo de la cadena destino 
 *  y los valores negativos, las siguientes situaciones de error:
 *  CADENA_SIN_TERMINADOR cuando la cantidad de carateres sea por lo menos igual
 *  a la capacidad indicada por el argumento
 *  CAPACIDAD_INSUFICIENTE la cadena a modificar no tiene espacio para agregar la cadena2
 *  @post
 */
int insercion_de_cadenas(char cadena_a_modificar[], int capacidad_cadena_a_modificar, char cadena_a_insertar[], 
int capacidad_cadena_a_insertar, int posicion_donde_insertar);

/**
 * La funcion copia una cadena en otra y deje solo un \0 en la cadena destino
 *  @param cadena_origen es la direccion de la cadena1 origen que se va a copiar
 *  @pre cadena1 es un puntero no nulo
 *  @param capacidad_cadena_origen la capacidad es el tamaño en memoria del arreglo
 *  @pre es un valor numerico entero positivo mayor a uno.
 *  @param cadena_destino es la direccion de la cadena2 donde se copiara la cadena1
 *  @pre cadena2 es un puntero no nulo
 *  @param capacidad_cadena_destino la capacidad es el tamaño en memoria del arreglo 
 *  @returns int en donde la función debe retornar el largo de la cadena destino 
 *  y los valores negativos, las siguientes situaciones de error:
 *  CADENA_SIN_TERMINADOR cuando la cantidad de carateres sea por lo menos igual
 *  a la capacidad indicada por el argumento
 *  CAPACIDAD_INSUFICIENTE la cadena destino no posee la capacidad necesaria para almacer cadena1
 *  @post
 */
int copia_de_cadenas(char cadena_origen[], int capacidad_cadena_origen, char cadena_destino[], int capacidad_cadena_destino);

/**
 *  La funcion limpia la cadena de todos los caracteres que no sean los alfanuméricos (AZaz09) menos
 *  el \0 en una cadena diferente a la de entrada.
 *  @param cadena1 es la direccion de la cadena1 que incluye caracteres no alfanumericos
 *  @pre cadena1 es un puntero no nulo
 *  @param capacidad_cadena1 la capacidad es el tamaño en memoria del arreglo
 *  @pre es un valor numerico entero positivo mayor a uno.
 *  @param cadena2 es la direccion de la cadena2 donde se copiara la cadena limpia solo caracteres alfanumericos
 *  @pre cadena2 es un puntero no nulo
 *  @param capacidad_cadena2 la capacidad es el tamaño en memoria del arreglo 
 *  @returns int en donde la función debe retornar el largo de la cadena destino 
 *  y los valores negativos, las siguientes situaciones de error:
 *  CADENA_SIN_TERMINADOR cuando la cantidad de carateres sea por lo menos igual
 *  a la capacidad indicada por el argumento
 *  CAPACIDAD_INSUFICIENTE la cadena destino no posee la capacidad necesaria para almacer cadena1
 *  @post
 */
int limpieza(char cadena1[], int capacidad_cadena1, char cadena2[], int capacidad_cadena2);

/**
 *  La funcion en un string destino devuelve el de origen invertido.
 *  @param cadena_origen es la direccion de la cadena1 con los caracteres que seran invertidos
 *  @pre cadena1 es un puntero no nulo
 *  @param capacidad_cadena_origen la capacidad es el tamaño en memoria del arreglo
 *  @pre es un valor numerico entero positivo mayor a uno.
 *  @param cadena_destino es la direccion de la cadena2 donde se invertira la cadena1
 *  @pre cadena2 es un puntero no nulo
 *  @param capacidad_cadena_destino la capacidad es el tamaño en memoria del arreglo 
 *  @returns int en donde la función debe retornar el largo de la cadena destino 
 *  y los valores negativos, las siguientes situaciones de error:
 *  CADENA_SIN_TERMINADOR cuando la cantidad de carateres sea por lo menos igual
 *  a la capacidad indicada por el argumento
 *  CAPACIDAD_INSUFICIENTE la cadena destino no posee la capacidad necesaria para almacer cadena1
 *  @post
 */
int inversor(char cadena_origen[], int capacidad_cadena_origen, char cadena_destino[], int capacidad_cadena_destino);

/**
 *  La funcion indica el ordenamiento alfabético de dos cadenas (solo minúsculas)
 *  @param cadena1 es la direccion de la cadena1 
 *  @pre cadena1 es un puntero no nulo
 *  @param capacidad_cadena1 la capacidad es el tamaño en memoria del arreglo
 *  @pre es un valor numerico entero positivo mayor a uno.
 *  @param cadena2 es la direccion de la cadena2 
 *  @pre cadena2 es un puntero no nulo
 *  @param capacidad_cadena2 la capacidad es el tamaño en memoria del arreglo 
 *  @returns int en donde la función debe retornar:
 * -1 la primera cadena va antes de que las segunda
 *  0 ambas cadenas son iguales
 *  1 la primera cadena va después que la segunda.  
 *  @post
 */
int comparacion(char cadena1[], int capacidad_cadena1, char cadena2[], int capacidad_cadena2);

/**
 * La funcion cuenta los caracteres alfanuméricos de una cadena (AZaz09)
 *  @param cadena1 es la direccion de la cadena1 en donde se contaran los caracteres alfanumerico
 *  @pre cadena1 es un puntero no nulo
 *  @param capacidad la capacidad es el tamaño en memoria del arreglo
 *  @pre es un valor numerico entero positivo mayor a uno
 *  @returns int es el numero de los caracteres alfanumericos total en la cadena
 *  @post
 */
int contador_carecteres(char cadena1[], int capacidad);

/**
 * La funcion cuenta los caracteres NO alfanuméricos de una cadena 
 *  @param cadena1 es la direccion de la cadena1 en donde se contaran los caracteres NO alfanumerico
 *  @pre cadena1 es un puntero no nulo
 *  @param capacidad la capacidad es el tamaño en memoria del arreglo
 *  @pre es un valor numerico entero positivo mayor a uno
 *  @returns int es el numero de los caracteres NO alfanumericos total en la cadena
 *  @post
 */
int contador_simbolos(char cadena1[], int capacidad);

/**
 * La funcion modifica la cadena dejando todos sus caracteres en minusculas.
 *  @param cadena1 es la direccion de la cadena1 que se modificara dejando sus caracteres en minuscula
 *  @pre cadena1 es un puntero no nulo
 *  @param capacidad la capacidad es el tamaño en memoria del arreglo
 *  @pre es un valor numerico entero positivo mayor a uno
 *  @returns sin retorno
 *  @post
 */
void a_minusculas(char cadena1[], int capacidad);

/**
 *  La funcion indica con TRUE si la cadena es un palindromo, con FALSE si no lo es o indica un error si no posee \0.
 *  @param cadena1 es la direccion de la cadena con la palabra original
 *  @pre cadena1 es un puntero no nulo
 *  @param capacidad1 la capacidad es el tamaño en memoria del arreglo
 *  @pre es un valor numerico entero positivo mayor a uno.
 *  @param cadena2 es la direccion de la cadena2 donde se haran modificaciones para poder comparar de manera eficiente
 *  @pre cadena2 es un puntero no nulo
 *  @param capacidad_cadena2 la capacidad es el tamaño en memoria del arreglo 
 *  @returns int TRUE(1) si la cadena es un palindromo, FALSE(0) si no lo es o un error(-1) si no posee \0. 
 *  @post
 */
int palindromo_seguro(char cadena1[], int capacidad1, char cadena2[], int capacidad2);


int main(int argc, char *argv[])
{
    int i;
    int largo_cadena_ingresada;
    int opcion_ingresada_int;
    int posicion_ingresada_int;
    int cant_alfanumericos;
    int cant_simbolos;
    int palindromo;
    char cadena1[CAPACIDAD];
    char cadena2[CAPACIDAD];

    if(argc > 1)
    {
        opcion_ingresada_int = atoi(argv[OPCION_INGRESADA_ARGV]);

        switch (opcion_ingresada_int)
        {
            case 1:
                largo_cadena_ingresada = largo_seguro(argv[POSICION_CADENA1_INGRESADA_ARGV], CAPACIDAD);
                printf("Largo de la cadena = %d\n", largo_cadena_ingresada);
                break;

            case 2:
                posicion_ingresada_int = atoi(argv[POSICION_DONDE_INSERTAR_ARGV]);
                printf("Cadena(1) ingresada: %s\n", argv[POSICION_CADENA1_INGRESADA_ARGV]);    
                printf("Cadena(2) ingresada: %s\n", argv[POSICION_CADENA2_INGRESADA_ARGV]);
                printf("Posicion en la Cadena(1) donde insertar la Cadena(2): %d\n", posicion_ingresada_int);
                insercion_de_cadenas(argv[POSICION_CADENA1_INGRESADA_ARGV], CAPACIDAD, argv[POSICION_CADENA2_INGRESADA_ARGV], 
                CAPACIDAD, posicion_ingresada_int);
                
                printf("Cadena modificada: %s\n", argv[POSICION_CADENA1_INGRESADA_ARGV]);
                break;

            case 3:
                printf("Cadena(1) ingresada: %s\n", argv[POSICION_CADENA1_INGRESADA_ARGV]);    
                printf("Cadena(2) ingresada: %s\n", argv[POSICION_CADENA2_INGRESADA_ARGV]);
                copia_de_cadenas(argv[POSICION_CADENA1_INGRESADA_ARGV], CAPACIDAD, argv[POSICION_CADENA2_INGRESADA_ARGV], CAPACIDAD);
                printf("Cadena(1) copiada en cadena(2): %s\n", argv[POSICION_CADENA2_INGRESADA_ARGV]);      
                break;    

            case 4:
                printf("Cadena(1) ingresada: %s\n", argv[POSICION_CADENA1_INGRESADA_ARGV]);  
                limpieza(argv[POSICION_CADENA1_INGRESADA_ARGV], CAPACIDAD, cadena2, CAPACIDAD);
                printf("Cadena limpia: %s\n", cadena2);      
                break;

            case 5:
                printf("Cadena ingresada: %s\n", argv[POSICION_CADENA1_INGRESADA_ARGV]);    
                inversor(argv[POSICION_CADENA1_INGRESADA_ARGV], CAPACIDAD, cadena2, CAPACIDAD);
                printf("Cadena inversa : %s\n", cadena2);      
                break;

            case 6:
                printf("Cadena(1) ingresada: %s\n", argv[POSICION_CADENA1_INGRESADA_ARGV]);    
                printf("Cadena(2) ingresada: %s\n", argv[POSICION_CADENA2_INGRESADA_ARGV]);               
                comparacion(argv[POSICION_CADENA1_INGRESADA_ARGV], CAPACIDAD, argv[POSICION_CADENA2_INGRESADA_ARGV], CAPACIDAD);
                break; 

            case 7:
                printf("Cadena ingresada: %s\n", argv[POSICION_CADENA1_INGRESADA_ARGV]);        
                cant_alfanumericos = contador_carecteres(argv[POSICION_CADENA1_INGRESADA_ARGV], CAPACIDAD);
                printf("Cantidad de caracteres alfanumericos: %d\n", cant_alfanumericos);
                break;

            case 8:
                printf("Cadena ingresada: %s\n", argv[POSICION_CADENA1_INGRESADA_ARGV]);        
                cant_simbolos = contador_simbolos(argv[POSICION_CADENA1_INGRESADA_ARGV], CAPACIDAD);
                printf("Cantidad de simbolos : %d\n", cant_simbolos);
                break;

            case 9:
                printf("Cadena ingresada: %s\n", argv[POSICION_CADENA1_INGRESADA_ARGV]);        
                a_minusculas(argv[POSICION_CADENA1_INGRESADA_ARGV], CAPACIDAD);
                printf("Cadena ingresada en minusculas : %s\n", argv[POSICION_CADENA1_INGRESADA_ARGV]);
                break;
    
            case 10:
                printf("Cadena ingresada: %s\n", argv[POSICION_CADENA1_INGRESADA_ARGV]);        
                palindromo = palindromo_seguro(argv[POSICION_CADENA1_INGRESADA_ARGV], CAPACIDAD, cadena2, CAPACIDAD);  
                if(palindromo == 1)
                {
                    printf("Es palindromo\n");
                }  
                else
                {
                    printf("No es palindromo\n");
                }         
                break; 

            default:
                printf("Opcion incorrecta\n");
                break;
        }
    }

    return 0;
}


int largo_seguro(char cadena1[], int capacidad)
{
    int caracteres = 0;

    while ((cadena1[caracteres] != '\0') && (caracteres < capacidad))
    {
        caracteres++;
    }

    if (caracteres == capacidad)
    {
        caracteres = CADENA_SIN_TERMINADOR;
    }
    return caracteres+1;    //largo incluyendo el \0
}


int insercion_de_cadenas(char cadena_a_modificar[], int capacidad_cadena_a_modificar, char cadena_a_insertar[], 
int capacidad_cadena_a_insertar, int posicion_donde_insertar)
{
    char auxiliar_segmento_final_cadena1[capacidad_cadena_a_modificar];
    int i;
    int largo_cadena_1;
    int largo_cadena_2;
    int largo_auxilar;
    int largo_segmento_cadena1_mas_largo_completo_cadena2;
    int posicion_inicial_insercion;
    int posicion_final_insercion;
    int funcion_devuelve;

    largo_cadena_1 = (largo_seguro(cadena_a_modificar, capacidad_cadena_a_modificar) -1);
    largo_cadena_2 = (largo_seguro(cadena_a_insertar, capacidad_cadena_a_modificar) -1);

    if ((largo_cadena_2 + largo_cadena_1 ) >= capacidad_cadena_a_modificar)     
    {
        funcion_devuelve = CAPACIDAD_INSUFICIENTE;
    }

    else
    {
        posicion_inicial_insercion = posicion_donde_insertar + 1;
        largo_segmento_cadena1_mas_largo_completo_cadena2 = largo_cadena_1  + largo_cadena_2  - posicion_donde_insertar;
        posicion_final_insercion = largo_cadena_2 + posicion_inicial_insercion;

        for (i = 0; i < (largo_segmento_cadena1_mas_largo_completo_cadena2); i++)
        {
            auxiliar_segmento_final_cadena1[i] = cadena_a_modificar[posicion_inicial_insercion + i];
            cadena_a_modificar[posicion_inicial_insercion + i] = cadena_a_insertar[i];
        }

        largo_auxilar = largo_seguro(auxiliar_segmento_final_cadena1, capacidad_cadena_a_modificar);

        for (i = 0; i < largo_auxilar; i++)
        {
            cadena_a_modificar[posicion_final_insercion + i] = auxiliar_segmento_final_cadena1[i];
        }

        funcion_devuelve = largo_cadena_1;
    }
    
    return funcion_devuelve;
}


int copia_de_cadenas(char cadena_origen[], int capacidad_cadena_origen, char cadena_destino[], int capacidad_cadena_destino)
{
    int largo_cadena_origen;
    int largo_cadena_destino;
    int i;
    int funcion_devuelve;

    largo_cadena_origen = largo_seguro(cadena_origen, capacidad_cadena_origen);
    largo_cadena_destino = largo_seguro(cadena_destino, capacidad_cadena_destino);

    if (largo_cadena_origen > capacidad_cadena_destino)
    {
        funcion_devuelve = CAPACIDAD_INSUFICIENTE;
    }

    else
    { 
        for (i = 0; i < largo_cadena_destino; i++)
        {
            cadena_destino[i] = '\0';
        }
    
        for (i = 0; i < largo_cadena_origen; i++)
        {
            cadena_destino[i] = cadena_origen[i];
        }
        
        largo_cadena_destino = largo_seguro(cadena_destino, capacidad_cadena_destino);
        funcion_devuelve = largo_cadena_destino;
    }

    return funcion_devuelve;
}


int limpieza(char cadena1[], int capacidad_cadena1, char cadena2[], int capacidad_cadena2)
{
    int i;
    int j = 0;
    int caracter_en_ascii;
    int largo_cadena_1;
    int largo_cadena_2;
    int funcion_devuelve;

    largo_cadena_1 = largo_seguro(cadena1, capacidad_cadena1);
    largo_cadena_2 = largo_seguro(cadena2, capacidad_cadena2);
    copia_de_cadenas(cadena1, capacidad_cadena1, cadena2, capacidad_cadena2);

    if(largo_cadena_1 > capacidad_cadena2)
    {
        funcion_devuelve = CAPACIDAD_INSUFICIENTE;
    }

    else
    {
        for (i = 0; i < largo_cadena_1; i++)
        {
            caracter_en_ascii = cadena1[i];

            if ((caracter_en_ascii >= A_MAYUSCULA && caracter_en_ascii <= Z_MAYUSCULA) || 
            (caracter_en_ascii >= A_MINUSCULA && caracter_en_ascii <= Z_MINUSCULA) || 
            (caracter_en_ascii >= CERO && caracter_en_ascii <= NUEVE) || caracter_en_ascii == 0)
            {
                cadena2[j] = cadena1[i];
                j = j + 1;
            }
        }

        funcion_devuelve = largo_cadena_2;
    }

    return funcion_devuelve;
}


int inversor(char cadena_origen[], int capacidad_cadena_origen, char cadena_destino[], int capacidad_cadena_destino)
{
    int largo_cadena_origen;
    int largo_cadena_destino;
    int i;
    int j = 0;
    int funcion_devuelve;

    largo_cadena_origen = largo_seguro(cadena_origen, capacidad_cadena_origen);

    if (largo_cadena_origen > capacidad_cadena_destino)
    {
        funcion_devuelve = CAPACIDAD_INSUFICIENTE;
    }

    else
    { 
        for (i = largo_cadena_origen-2; i >= 0; i--)
        {
            cadena_destino[j] = cadena_origen[i];
            j++;
        }

        cadena_destino[largo_cadena_origen-1] = '\0';
        largo_cadena_destino = largo_seguro(cadena_destino, capacidad_cadena_destino);
        funcion_devuelve = largo_cadena_destino;
    }

    return funcion_devuelve;
}


int comparacion(char cadena1[], int capacidad_cadena1, char cadena2[], int capacidad_cadena2)
{    
    int i;
    int caracter_en_ascii_cadena1;
    int caracter_en_ascii_cadena2;
    int largo_cadena_1;
    int largo_cadena_2;
    int funcion_devuelve;

    largo_cadena_1 = (largo_seguro(cadena1, capacidad_cadena1) -1);
    largo_cadena_2 = (largo_seguro(cadena1, capacidad_cadena1) -1);

    for (i = 0; i < largo_cadena_1; i++)
    {
        caracter_en_ascii_cadena1 = cadena1[i];        
        caracter_en_ascii_cadena2 = cadena2[i];
        
        if((caracter_en_ascii_cadena1 >= A_MINUSCULA && caracter_en_ascii_cadena1 <= Z_MINUSCULA) &&  // miramos solo las minusculas
        (caracter_en_ascii_cadena2 >= A_MINUSCULA && caracter_en_ascii_cadena2 <= Z_MINUSCULA))
        {
            if(caracter_en_ascii_cadena1 == caracter_en_ascii_cadena2)
            {
                if(i == largo_cadena_1 -1)
                {
                    funcion_devuelve = 0;
                }
                continue;
            }
            else if (caracter_en_ascii_cadena1 < caracter_en_ascii_cadena2)
            {
                funcion_devuelve = -1;
                break;
            }
            else
            {
                funcion_devuelve = 1;
                break;
            }
        }
    }

    return funcion_devuelve;
}


int contador_carecteres(char cadena1[], int capacidad)
{
    int i;
    int contador = 0;
    int caracter_en_ascii;
    int largo;

    largo = largo_seguro(cadena1, capacidad);

    for (i = 0; i < largo; i++)
        {
            caracter_en_ascii = cadena1[i];

            if ((caracter_en_ascii >= A_MAYUSCULA && caracter_en_ascii <= Z_MAYUSCULA) || 
            (caracter_en_ascii >= A_MINUSCULA && caracter_en_ascii <= Z_MINUSCULA) || 
            (caracter_en_ascii >= CERO && caracter_en_ascii <= NUEVE))
            {
                contador = contador + 1;
            }
        }
    return contador;
}


int contador_simbolos(char cadena1[], int capacidad)
{
    int i;
    int contador = 0;
    int caracter_en_ascii;
    int largo;

    largo = largo_seguro(cadena1, capacidad);

    for (i = 0; i < largo; i++)
        {
            caracter_en_ascii = cadena1[i];

            if((caracter_en_ascii >= 0 && caracter_en_ascii < CERO) || 
            (caracter_en_ascii > NUEVE && caracter_en_ascii < A_MAYUSCULA) || 
            (caracter_en_ascii > Z_MAYUSCULA && caracter_en_ascii < A_MINUSCULA) ||
            (caracter_en_ascii > Z_MINUSCULA))
            {
                contador = contador + 1;
            }
        }
        
    return contador;
}


void a_minusculas(char cadena1[], int capacidad)
{
    int i;
    int largo;
    int contador;

    largo = largo_seguro(cadena1, capacidad);

    for (i = 0; i < largo-1; i++)
        {
        contador = contador + 1;
        
        switch (cadena1[i])
        {
        case 'A':
            cadena1[i] = 'a';
            break;
        case 'B':
            cadena1[i] = 'b';
            break;
        case 'C':
            cadena1[i] = 'c';
            break;
        case 'D':
            cadena1[i] = 'd';
            break;
        case 'E':
            cadena1[i] = 'e';
            break;
        case 'F':
            cadena1[i] = 'f';
            break;
        case 'G':
            cadena1[i] = 'g';
            break;
        case 'H':
            cadena1[i] = 'h';
            break;
        case 'I':
            cadena1[i] = 'i';
            break;
        case 'J':
            cadena1[i] = 'j';
        case 'K':
            cadena1[i] = 'k';
            break;
        case 'L':
            cadena1[i] = 'l';
            break;
        case 'M':
            cadena1[i] = 'm';
            break;
        case 'N':
            cadena1[i] = 'n';
            break;
        case 'O':
            cadena1[i] = 'o';
            break;
        case 'P':
            cadena1[i] = 'p';
            break;
        case 'Q':
            cadena1[i] = 'q';
            break;
        case 'R':
            cadena1[i] = 'r';
            break;
        case 'S':
            cadena1[i] = 's';
            break;
        case 'T':
            cadena1[i] = 't';
            break;
        case 'U':
            cadena1[i] = 'u';
            break;
        case 'V':
            cadena1[i] = 'v';
            break;
        case 'W':
            cadena1[i] = 'w';
            break;
        case 'X':
            cadena1[i] = 'x';
            break;
        case 'Y':
            cadena1[i] = 'y';
            break;
        case 'Z':
            cadena1[i] = 'z';
            break;
        default:
            cadena1[i] = cadena1[i];
        }
    }
}


int palindromo_seguro(char cadena1[], int capacidad1, char cadena2[], int capacidad2)
{
    char auxiliar[CAPACIDAD];
    int resultado;
    int funcion_devuelve;
    int resultado_largo_seguro;

    limpieza(cadena1, capacidad1, cadena2, capacidad2);
    a_minusculas(cadena2, capacidad2);
    inversor(cadena2, capacidad2, auxiliar, CAPACIDAD);
    resultado = comparacion(cadena2, capacidad2, auxiliar, CAPACIDAD);

    if(resultado == 0)
    {
        funcion_devuelve = TRUE;
    }
    else
    {
        funcion_devuelve = FALSE;
    }

    resultado_largo_seguro = largo_seguro(cadena1, capacidad1);

    if (resultado_largo_seguro == -1)
    {
        funcion_devuelve = -1;
    }
    
    return funcion_devuelve;
}


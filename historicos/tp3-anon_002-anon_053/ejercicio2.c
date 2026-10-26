

#include <stdio.h>

#define LARGO_CADENA 50
// Definición de códigos de error
#define CADENA_SIN_TERMINADOR -1
#define CADENA_MUY_LARGA -2

#define CADENA1_ANTES_CADENA2 -1
#define CADENA1_DESPUES_CADENA2 1

#define TRUE 1
#define FALSE 0

int largo_seguro(char cadena[], int capacidad);
int copiar_cadena(char cadena_destino[], char cadena[]);
int insertar_cadena(char cadena_inicial[], char cadena_insertar[], int posicion);
int limpiar_cadena(char cadena_origen[], char cadena_destino[]);
int orden_alfabeticamente( char cadena1[], char cadena2[]);
int convertir_minusculas(char cadena[]);
int esPalindromo(char Cadena[]);


int main() 
{
    char cadena[LARGO_CADENA];
    printf("Ingrese texto: ");
    gets (cadena);// por el momento uso gets como prueba
    
    //sector largo seguro
    char cadena_final[LARGO_CADENA];
    int largo = largo_seguro(cadena, LARGO_CADENA);
    printf("Largo de cadena %d", largo);
    
    //sector copiar cadena
    copiar_cadena(cadena_final, cadena);
    printf("\nCadena copiada %s", cadena_final);

     //sector insetar cadena
    char cadena_inicial[LARGO_CADENA] = "HOLA";
    char cadena_insertar[] = "Mundo";
    int posicion = 3;
    
    int cambio = insertar_cadena(cadena_inicial, cadena_insertar, posicion);

    if (cambio == CADENA_MUY_LARGA)
    {
        printf("Cadena destino muy larga.\n");
    }
    else
    {
        printf("\nCadena resultante: %s\n", cadena_inicial);
    }
    
    //sector limpiar cadena
    char cadena_origen[] = "¡Hola, s o y k! a@ t $y!123";
    char cadena_destino[LARGO_CADENA];

    int limpiar = limpiar_cadena(cadena_origen, cadena_destino);

    if (limpiar == CADENA_SIN_TERMINADOR) 
    {
        printf("Cadena no posee un caracter nulo.\n");
    }
    else 
    {
        printf("Cadena limpiada: %s\n", cadena_destino);
        printf("Largo de la cadena limpiada: %d\n", limpiar);
    }

    // sector orden alfabetico 
    char cadena1[LARGO_CADENA] = "hola";
    char cadena2[LARGO_CADENA] = "adios";

    int orden = orden_alfabeticamente(cadena1, cadena2);
    printf("El orden alfabetico retorna: %d\n", orden); 

//sector convertir minusculas
    char miCadena[] = "HOLA, mi NOMBRE Es KaThErInA.";

    int conversion = convertir_minusculas(miCadena);

    if (conversion == 0) 
    {
        printf("Cadena en minusculas: %s\n", miCadena);
    } 
    else 
    {
        printf("Error al convertir la cadena.\n");
    }

    //sector palindromo
    char Cadena[] = "anilina";
    int palindromo = esPalindromo(Cadena);

    if (palindromo == TRUE) 
    {
        printf("La cadena es un palindromo.\n");
    } 
    else if (palindromo == FALSE) 
    {
        printf("La cadena no es un palindromo.\n");
    }
    else
    {
        printf("La cadena no posee un caracter nulo. \n");
    }

    return 0;
}


int largo_seguro(char cadena[], int capacidad) 
{
    int contador = 0;
    // Verificar si el primer carácter de la cadena es nulo
    if (cadena[0] == '\0') 
    {
        contador = CADENA_SIN_TERMINADOR;
    }
    // Inicializar el contador de largo

    // Recorrer la cadena y contar los caracteres hasta llegar a la longitud máxima
    while (cadena[contador] != '\0' && contador < capacidad) 
    {
        contador++;
    }

    // Verificar si la cadena es demasiado larga
    if (cadena[contador] != '\0' && contador == capacidad) 
    {
        contador = CADENA_MUY_LARGA;
    }

    return contador;
}


int copiar_cadena(char cadena_destino[], char cadena[])
{
    int contador = 0;
    int resultado = 0;

    while (cadena[contador] != '\0') 
    {
        cadena_destino[contador] = cadena[contador];
        contador++;
    }

    cadena_destino[contador] = '\0'; // Agregar el terminador nulo al final

    if (contador >= LARGO_CADENA) 
    {
        resultado = CADENA_MUY_LARGA;
    } 
    else if (cadena[contador] != '\0') 
    {
        resultado = CADENA_SIN_TERMINADOR;
    }

    return resultado;
}


int insertar_cadena(char cadena_inicial[], char cadena_insertar[], int posicion)
{
    int longitud_destino = 0;
    int longitud_a_insertar = 0;

    // Obtener la longitud de las cadenas
    while (cadena_inicial[longitud_destino] != '\0') 
    {
        longitud_destino++;
    }

    while (cadena_insertar[longitud_a_insertar] != '\0') 
    {
        longitud_a_insertar++;
    }

    int cadena_nueva = longitud_destino + longitud_a_insertar;


    // Desplazar los caracteres para hacer espacio para la cadena a insertar
    for (int i = longitud_destino; i >= posicion; i--) 
    {
        cadena_inicial[i + longitud_a_insertar] = cadena_inicial[i];
    }

    // Insertar la cadena en la posición indicada
    for (int i = 0; i < longitud_a_insertar; i++) 
    {
        cadena_inicial[posicion + i] = cadena_insertar[i];
    }

    return cadena_nueva;
}


int limpiar_cadena(char cadena_origen[], char cadena_destino[])
{
    int conclusion = 0;
    int contador_cadena_origen = 0;
    int contador_cadena_destino = 0;
    char alfanumerico = 0; // Declarar una variable para el carácter

    while (cadena_origen[contador_cadena_origen] != '\0' && contador_cadena_destino < LARGO_CADENA - 1) 
    {
        alfanumerico = cadena_origen[contador_cadena_origen]; // Obtener el carácter actual

        if ((alfanumerico >= 'A' && alfanumerico <= 'Z') || (alfanumerico >= 'a' && alfanumerico <= 'z') || (alfanumerico >= '0' && alfanumerico <= '9')) 
        {
            cadena_destino[contador_cadena_destino] = alfanumerico; // Copia el carácter al cadena_destino
            contador_cadena_destino++;
        }
        contador_cadena_origen++;
    }
    cadena_destino[contador_cadena_destino] = '\0'; // Agrega el terminador nulo al final

    if (cadena_origen[contador_cadena_origen] != '\0' && contador_cadena_destino == LARGO_CADENA - 1) 
    {
        conclusion = CADENA_SIN_TERMINADOR; //cadena_destino demasiado larga
    }
    conclusion = contador_cadena_destino;

    return conclusion; // Largo de la cadena cadena_destino
}


int orden_alfabeticamente( char cadena1[], char cadena2[])
{
    int contador = 0;
    int ordenado = 0;

    while (cadena1[contador] != '\0' && cadena2[contador] != '\0')
    {
        if (cadena1[contador] < cadena2[contador])
        {
            ordenado = CADENA1_DESPUES_CADENA2;}
        else if (cadena1[contador] > cadena2[contador])
        {
            ordenado = CADENA1_ANTES_CADENA2;
        }
        contador++;
    }
    return ordenado;
}


int convertir_minusculas(char cadena[]) 
{
    int contador = 0;
    while (cadena[contador] != '\0') 
    {
        if (cadena[contador] >= 'A' && cadena[contador] <= 'Z') 
        {
            cadena[contador] = cadena[contador] - 'A' + 'a'; // Convertir a minúscula
        }
        contador++;
    }

    return 0;
}


int esPalindromo(char Cadena[]) 
{
    // Verificar si la cadena tiene el carácter nulo ('\0')
    int eleccion = 1;
    int contador = 0;
    while (Cadena[contador] != '\0') 
    {
        contador++;
    }
    if (contador == 0) 
    {
        eleccion = CADENA_SIN_TERMINADOR;
    }

    // Verifica si la cadena es un palindromo 
    int inicio_cadena1 = 0;
    int fin_cadena2 = contador - 1;
    while (inicio_cadena1 < fin_cadena2) 
    {
        char cadena1 = (Cadena[inicio_cadena1]);
        char cadena2 = (Cadena[fin_cadena2]);

        if (cadena1 != cadena2) 
        {
            eleccion = FALSE;
        }
        inicio_cadena1++;
        fin_cadena2--;
    }

    return eleccion;
}
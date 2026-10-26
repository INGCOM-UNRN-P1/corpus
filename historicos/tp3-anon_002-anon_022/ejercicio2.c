

#include <stdio.h>
#include <string.h>
#define SIZE 100 
#define CADENA_SUPERADA -1
#define CANTIDAD_CADENA_SUPERADA -2
#define TRUE 1
#define FALSE 0



/**
 * La funcion cuenta los caracteres de la cadena sin exceder la capacidad del arreglo indicada.
 *  @param cadena es la direccion de la cadena con la que se contaran los caracteres
 *  @pre cadena es una cadena valida
 *  @param capacidad la capacidad es un número distinto a el largo de la cadena en si 
 *  y es el tamaño en memoria del arreglo
 *  @pre es un valor numerico entero positivo mayor a uno
 *  @returns un numero entero en donde los valores positivos incluyendo el cero representan la cantidad de caracteres
 *  y los valores negativos, las siguientes situaciones de error:
 *  CADENA_SIN_TERMINADOR cuando la cantidad de carateres sea por lo menos igual 
 *  a la capacidad indicada por el argumento. 
 */
int largo_seguro(char cadena[],int capacidad)
{
   int contador = 0;
   while (cadena[++contador] != 0){
      
      if (contador == capacidad)
      {
         contador = CADENA_SUPERADA;
      }
   }
   return contador;
}


/**
 * Copia una cadena de origen en una cadena de destino.
 * @param cadena_origen Cadena fuente a copiar.
 * @pre cadena_origen es un arreglo de caracteres válidos.
 * @param cadena_destino Cadena destino donde se copiará la cadena fuente.
 * @pre cadena_destino es un arreglo de caracteres válidos.
 * @post cadena_destino contiene una copia exacta de cadena_origen.
 */
int copiar_cadena(char cadena_origen[], char cadena_destino[]) 
{
   int i = 0;
   while (cadena_origen[i] != '\0')
   {
      cadena_destino[i] = cadena_origen[i];
      i++;
   }
   cadena_destino[i] = '\0'; 
}


/**
 * Inserta una cadena en otra en una posición dada.
 * @param origen Cadena donde se insertará la cadena destino.
 * @param destino Cadena que se insertará en la cadena origen.
 * @param capacidad Capacidad del arreglo (tamaño en memoria).
 * @param posicion Posición en la cadena origen donde se insertará la cadena destino.
 */
void insercion_cadenas(char origen[], char destino[], int capacidad, int posicion)
{
   int largo_origen = largo_seguro(origen, capacidad);
   int largo_destino = largo_seguro(destino, capacidad);

   if (posicion < 0 || posicion > largo_origen)
   {
      printf("Posición de inserción inválida.\n");
      return;
   }
   if (largo_origen + largo_destino >= capacidad)
   {
      printf("No hay suficiente espacio para la inserción.\n");
      return;
   }

   for (int i = largo_origen; i >= posicion; i--)
   {
      origen[i + largo_destino] = origen[i];
   }
   for (int i = 0; i < largo_destino; i++) {
      origen[posicion + i] = destino[i];
   }
}


/**
 * Limpia una cadena eliminando caracteres no deseados (AZaz09)y copia el resultado en otra cadena.
 * @param cadena Cadena origen que se limpiará.
 * @param cadena_salida Cadena destino donde se copiará la cadena limpiada.
 * @param capacidad Capacidad del arreglo (tamaño en memoria).
 * @pre cadena es una cadena de caracteres válida.
 * @pre capacidad es un número entero positivo mayor que 0.
 * @post cadena_salida contiene una copia de cadena con caracteres no deseados eliminados.
 */
void limpiar_cadena(char cadena[], char cadena_salida[], int capacidad)
{
   int i = 0;
   int j = 0;
    while (cadena[i] != '\0' && j < capacidad - 1) 
    {
        if ((cadena[i] >= 'A' && cadena[i] <= 'Z') ||
            (cadena[i] >= 'a' && cadena[i] <= 'z') ||
            (cadena[i] >= '0' && cadena[i] <= '9')) 
         {
            cadena_salida[j] = cadena[i];
            j++;
         }
        i++;
    }

    cadena_salida[j] = '\0';
}


/**
 * Compara dos cadenas y devuelve un valor negativo, cero o positivo según sean iguales, la primera menor o la primera mayor.
 * @param cadena1 Primera cadena a comparar.
 * @param cadena2 Segunda cadena a comparar.
 * @param capacidad Capacidad del arreglo (tamaño en memoria).
 * @pre cadena1 y cadena2 son arreglos de caracteres válidos.
 * @pre capacidad es un número entero positivo mayor que 0.
 * @return Valor negativo si cadena1 menor a cadena2, 0 si cadena1 es igual cadena2, valor positivo si cadena1 es mayor a cadena2.
 * @post El valor de retorno es un número entero.
 */
int comparar_cadenas(char cadena1[], char cadena2[], int capacidad)
{
   int i=0;
   int j=0;
   int resultado;
   while (cadena1[i] != '\0' && cadena2[i] != '\0') 
   {
      if (cadena1[i] < cadena2[i]) 
      {
         resultado = -1;
      } 
      else if (cadena1[i] > cadena2[i]) 
      {
         resultado = 1;
      }
      i++;
   }

   if (cadena1[i] == '\0' && cadena2[i] == '\0') 
   {
      resultado = 0;
   } 
   else if (cadena1[i] == '\0')
   {
      resultado = -1;
   }
   else 
   {
      resultado= 1;
   }
   return resultado;
}


/**
 * Convierte todos los caracteres de una cadena a minúsculas.
 * @param cadena Cadena a convertir a minúsculas.
 * @pre cadena es una cadena de caracteres válida.
 * @post Todos los caracteres en cadena han sido convertidos a minúsculas.
 */
void a_minusculas(char cadena[], int capacidad)
{
    int i = 0;
    while (i < capacidad && cadena[i] != '\0')
    {
      if (cadena[i] >= 'A' && cadena[i] <= 'Z') {
         cadena[i] = cadena[i] + ('a' - 'A');
      }
      i++;
   }
}


/**
 * Verifica si una cadena es un palíndromo (se lee igual de izquierda a derecha y de derecha a izquierda).
 * @param cadena Cadena a verificar.
 * @return 1 si la cadena es palíndromo, 0 si no lo es.
 * @pre cadena es una cadena de caracteres válida.
 * @post El valor de retorno es 0 o 1.
 */
int es_palindromo(char cadena[], int capacidad)
{
   int longitud = 0;
   while (cadena[longitud] != '\0' && longitud < capacidad)
   {
      longitud++;
   }

   for (int i = 0; i < longitud / 2; i++)
   {
      if (cadena[i] != cadena[longitud - i - 1])
      {
         return FALSE;
      }
   }
   return TRUE;
}

int main ()
{
   char cadena[SIZE];
   char cadena2[SIZE];
   int capacidad = SIZE;
   int largo;
   char copia_cadena[SIZE];
   int posicion;   
   char cadena_limpia[SIZE];
   int comparacion;
   printf("Ingrese la primera cadena: ");
   scanf("%s", cadena);
   printf("Ingrese la segunda cadena: ");
   scanf("%s", cadena2);
   largo = largo_seguro(cadena,capacidad);
   copiar_cadena(cadena,copia_cadena);
   printf("Copia de cadena 1: %s\n", copia_cadena);
   printf("Ingrese la posicion de insercion: ");
   scanf("%d", &posicion);
   insercion_cadenas(copia_cadena, cadena2, capacidad, posicion);
   printf("Cadena resultante de insercion: %s\n", copia_cadena);
   limpiar_cadena(cadena2, cadena_limpia, capacidad);
   printf("Cadena limpia: %s\n", cadena_limpia);   
   comparacion = comparar_cadenas(cadena,cadena2,capacidad);
   if (comparacion == 0)
   {
      printf("Las cadenas son iguales\n");
   }
   else if (comparacion<0)
   {
      printf("Cadena 1 es mayor que cadena 2\n");
   }
   else
   {
      printf("Cadena 2 es mayor que cadena 1\n");
   }
   a_minusculas(cadena,capacidad);
   printf("Cadena 1 en minusculas: %s\n", cadena);
   if (es_palindromo(cadena,capacidad))
   {
      printf("Cadena 1 es un palindromo\n");
   } 
   else
   {
      printf("Cadena 1 no es un palindromo\n");
   }
   return 0;
}


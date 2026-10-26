#include <stdio.h>
#include <stdlib.h>
#define ASCENDENTE 1
#define NO_ORDENADO 0
#define DESCENDENTE -1
#define MAX_NUMEROS 1000



/**
 *  Verifica si un archivo de numeros esta ordenado.
 *
 * Esta funcion verifica si los numeros en un archivo estan ordenados de forma
 * ascendente, descendente o no ordenados en absoluto. Devuelve un codigo que
 * indica el tipo de ordenamiento o si no esta ordenado.
 *
 * @param archivo Nombre del archivo que contiene los numeros a verificar.
 * @pre El archivo debe existir y ser accesible para lectura.
 * @pre Debe contener numeros enteros validos
 * @pre No debe estar vacio
 * @post Devolver correctamente la verificacion del archivo 
 * @return  ASCENDENTE: si los numeros estan ordenados de forma ascendente,
 *         DESCENDENTE: si estan ordenados de forma descendente.
 *         NO_ORDENADO: si no estan ordenados en absoluto.
 */
int esta_ordenado(char *archivo)
{
  int numero_anterior = -329181;
  int numero_actual;
  int resultado;
  int ascendente;
  int descendente;
  int primer_numero;
  FILE *f = fopen(archivo, "r");
  while (fscanf(f, "%d", &numero_actual) == 1)
  {
    if (!primer_numero)
    {
      if (numero_actual < numero_anterior)
      {
        ascendente = 0;
      }
      else if (numero_actual > numero_anterior)
      {
        descendente = 0;
      }
    }
    primer_numero = 0;
    numero_anterior = numero_actual;
  }
  fclose(f);
  if (ascendente)
  {
    resultado = ASCENDENTE;
  }
  else if (descendente)
  {
    resultado = DESCENDENTE;
  }
  else
  {
    resultado = NO_ORDENADO;
  }
  return resultado;
}



/**
* Ordena un arreglo de numeros en orden ascendente.
* Esta funcion ordena un arreglo de numeros enteros en orden ascendente utilizando
* el algoritmo de burbuja.
*
* @param numeros   Arreglo de numeros a ordenar.
* @param longitud  Longitud del arreglo.
* @pre El arreglo numeros deberia contener al menos un elemento.
* @post El arreglo numeros estara ordenado de manera ascendente al finalizar la ejecucion
*/
void ordenar_ascendente(int * numeros, int longitud)
{
    int temp;
    int i;
    int j;
    for (i=0; i<longitud-1; i++)
    {
        for (j=0; j< longitud - i; j++)
        {
            if (numeros[j] > numeros[j+1])
            {
                temp = numeros[j];
                numeros[j] = numeros[j+1];
                numeros[j+1]=temp;
            }

        }
    }

}


/**
* Ordena un arreglo de numeros en orden descendente.
* Esta funcion ordena un arreglo de numeros enteros en orden descendente utilizando
* el algoritmo de burbuja.
*
* @param numeros   Arreglo de numeros a ordenar.
* @param longitud  Longitud del arreglo.
* @pre El arreglo numeros deberia contener al menos un elemento.
* @post El arreglo numeros estara ordenado de manera descendete al finalizar la ejecucion
*/
void ordenar_descendente(int *numeros, int longitud)
{
    int temp;
    int i;
    int j;
    for (i=0; i<longitud-1; i++)
    {
        for (j=0;j<longitud-i-1;j++)
        {
            if (numeros[j]< numeros [j+1])
            {
                temp = numeros[j];
                numeros[j] = numeros[j+1];
                numeros[j+1] = temp;
            }
        }
    }
}



/**
* Lee numeros de un archivo, los ordena y los guarda en otro archivo.
*
* Esta funcion lee una secuencia de numeros desde un archivo de entrada,
* determina el sentido de ordenamiento (ascendente o descendente) segun el
* argumento 'sentido_ordenamiento' y luego ordena los numeros en consecuencia. Los
* numeros ordenados se guardan en un archivo de salida.
*
* @param archivo              Nombre al archivo de entrada que contiene los numeros a ordenar.
* @param sentido_ordenamiento Cadena de caracteres que indica el sentido de ordenamiento
*                             ('a' para ascendente, 'd' para descendente).
* @param archivo_ordenado     Nombre al archivo de salida donde se guardaran los numeros ordenados.
*
* @pre El archivo de entrada debe existir y ser accesible para lectura.
* @pre El archivo de salida debe estar accesible para escritura, en caso de no existir, se crea.
* @pre El argumento 'sentido_ordenamiento' debe ser una cadena valida que contenga solo 'a' o 'd'.
* @pre El archivo de entrada debe contener numeros enteros validos.
* @pre El archivo de entrada no debe estar vacio.
* @pre El numero maximo de numeros a leer desde el archivo de entrada es MAX_NUMEROS.
*
* @post El archivo de salida contendra los numeros ordenados segun el sentido.
* @post El archivo de salida se creara si no existe.
*/
void ordenar_numeros(char *archivo, char sentido_ordenamiento, char * archivo_ordenado)
{
  FILE *entrada = fopen(archivo, "r");
  if (archivo == NULL)
  {
   perror("fopen() fallo");
  }
  int contenido = 0;
  int numeros[MAX_NUMEROS];
  while (contenido < MAX_NUMEROS && fscanf(entrada, "%d", &numeros[contenido]) == 1)
  {
    contenido++;
  }
  fclose(archivo);
  int i = 0;
  int ascendente = 0;
  int descendente = 0;
  int resultado;
  while (sentido_ordenamiento[i] != '\0')
  {
    if (sentido_ordenamiento[i] != 'a')
    {
      ascendente = 0;
    }
    if (sentido_ordenamiento[i] != 'd')
    {
      descendente = 0;
    }
    i++;
  }
  if (ascendente && !descendente)
  {
    ordenar_ascendente(numeros,contenido);
  }
  else if (descendente && !ascendente)
  {
    ordenar_descendente(numeros,contenido);
  }
}


int main(int argc, char *argv[])
{
  if (argc != 4)
  {
    perror("No se ingresaron los argumentos adecuados para el funcionamiento del programa.\n");
    return 1; 
  }

  char *archivo = argv[1];
  char opcion = argv[2];
  char *archivo_ordenado = argv[3];

  int orden = esta_ordenado(archivo);

  if (orden == NO_ORDENADO)
  {
    printf("El archivo no esta ordenado.\n");
    return 1; 
  }

  if (strcmp(opcion, "a") == 0)
  {
    if (orden == ASCENDENTE)
    {
      printf("El archivo ya esta ordenado ascendentemente.\n");
    }
    else
    {
      ordenar_numeros(archivo, "ascendente", archivo_ordenado);
      printf("Archivo ordenado ascendentemente y guardado en %s\n", archivo_ordenado);
    }
  }
  else if (strcmp(opcion, "d") == 0)
  {
    if (orden == DESCENDENTE)
    {
      printf("El archivo ya esta ordenado descendentemente.\n");
    }
    else
    {
      ordenar_numeros(archivo, "descendente", archivo_ordenado);
      printf("Archivo ordenado descendentemente y guardado en %s\n", archivo_ordenado);
    }
  }
  else
  {
    perror("Opcion no valida. Debe ser 'a' para ascendente o 'd' para descendente.\n");
    return 1; 
  }

  return 0; 
}

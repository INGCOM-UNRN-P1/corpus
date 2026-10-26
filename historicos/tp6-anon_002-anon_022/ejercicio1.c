#include <stdio.h>
#include <stdlib.h>
#define DESCENDENTE -1
#define NO_ORDENADO 0
#define ASCENDENTE 1
#define ERROR 2

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

int main(int argc, char *argv[])
{
  char *archivo = argv[1];
  if (argc != 2)
  {
    printf("No se ingreso como argumento archivo_numeros.txt\n");
  }
  int resultado;
  resultado = esta_ordenado(archivo);
  if (resultado == ASCENDENTE)
  {
    printf("Si - Ascendente\n");
  }
  else if (resultado == DESCENDENTE)
  {
    printf("Si - Descendente\n");
  }
  else if (resultado == NO_ORDENADO)
  {
    printf("No esta ordenado\n");
  }
}

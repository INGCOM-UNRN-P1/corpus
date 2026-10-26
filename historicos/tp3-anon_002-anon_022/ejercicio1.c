

#include <stdio.h>
#define SIZE 1000


/**
 * Carga valores en un arreglo.
 * @param capacidad El tamaño máximo del arreglo.
 * @param arreglo El arreglo donde se cargarán los valores.
 * @return Ninguno, solo carga los valores
 * @pre El arreglo debe tener la capacidad suficiente para almacenar los valores.
 * @post El arreglo contendrá los valores cargados.
 */


void cargar_arreglo(int capacidad, int arreglo[])
{
   int i = 0;
   for (i=0;i<capacidad;i++)
   {
      scanf("%d", &arreglo[i]);
   }
}

/**
 * Muestra los elementos de un arreglo.
 * @param capacidad La cantidad de elementos en el arreglo.
 * @param arreglo El arreglo que se mostrará.
 * @return Ninguno, muestra por pantalla los elementos del arreglo
 * @pre El arreglo debe contener al menos capacidad elementos.
 * @post Los elementos del arreglo se mostrarán en la salida estándar.
 */

void mostrar_arreglo(int capacidad, int arreglo[])
{
   int i=0;
   for (i = 0; i<capacidad;i++)
   {
      printf("Posicion [%d] -> %d\n",i, arreglo[i]);
   }
}

/**
 * Fusiona dos arreglos en uno nuevo.
 * @param arreglo1 El primer arreglo a fusionar.
 * @param arreglo2 El segundo arreglo a fusionar.
 * @param capacidad1 La cantidad de elementos en arreglo1.
 * @param capacidad2 La cantidad de elementos en arreglo2.
 * @param arreglo_fusionado El arreglo resultante de la fusión.
 * @return void. En caso de que el arreglo fusionado no tenga capacidad, debe saltar error 
 * @pre Los arreglos deben tener suficiente capacidad para fusionarse en arreglo_fusionado.
 * @post arreglo_fusionado contendrá la fusión de arreglo1 y arreglo2.
 */

void fusionar_arreglos(int arreglo1[],int arreglo2[], int capacidad1, int capacidad2, int arreglo_fusionado[])
{
    for (int i = 0; i < capacidad1; i++) 
    {
        arreglo_fusionado[i] = arreglo1[i];
    }

    for (int i = 0; i < capacidad2; i++)
    {
        arreglo_fusionado[capacidad1 + i] = arreglo2[i];
    }
}
    

/**
 * Calcula el promedio de los elementos en un arreglo.
 * @param capacidad La cantidad de elementos en el arreglo.
 * @param arreglo El arreglo del cual se calculará el promedio.
 * @return El promedio de los elementos en el arreglo.
 * @pre El arreglo debe contener al menos un elemento.
 * @post No se modificará el arreglo ni sus elementos.
 */
float promedio(int capacidad, int arreglo[])
{
   int i = 0;
   float promedio = 0;
   float suma = 0;
   for (i; i<capacidad;i++)
   {
      suma = suma + arreglo[i];
   }
   promedio = suma/capacidad;
  return promedio;
}


/**
 * Encuentra el valor minimo en un arreglo.
 * @param capacidad La cantidad de elementos en el arreglo.
 * @param arreglo El arreglo en el que se buscara el valor mínimo.
 * @return El valor minimo en el arreglo.
 * @pre El arreglo debe contener al menos un elemento.
 * @post No se modificará el arreglo ni sus elementos.
 */

int minimo(int capacidad, int arreglo[])
{
   int i = 0;
   int min = arreglo[0];
   for (i; i<capacidad; i++)
   {
      if (arreglo[i]<min){
         min = arreglo [i];
      }
   }
   return min;
}


/**
 * Encuentra la posición del valor máximo en un arreglo.
 * @param capacidad La cantidad de elementos en el arreglo.
 * @param arreglo El arreglo en el que se buscará el valor máximo.
 * @return La posición del valor máximo en el arreglo.
 * @pre El arreglo debe contener al menos un elemento.
 * @post No se modificará el arreglo ni sus elementos.
 */

int posicion_maximo(int capacidad, int arreglo[])
{
   int i = 0;
   int max = arreglo[0];
   int posicion = 0;
   for (i; i<capacidad; i++)
   {
      if (arreglo[i]>max){
         max = arreglo[i];
         posicion = i;
      } 
   }
   return posicion;
}



int main()
{  
   int capacidad;
   int capacidad2;
   int capacidad_fusion;
   int arreglo[SIZE];
   int arreglo2[SIZE];
   int arreglo_fusion[SIZE];
   int minimo_arreglo;
   int posicion_max;
   float promedio_arreglo;
   printf("Ingrese la capacidad del arreglo 1: ");
   scanf("%d", &capacidad);
   printf("Ingrese la capacidad del arreglo 2: ");
   scanf("%d", &capacidad2);
   capacidad_fusion = capacidad + capacidad2;
   arreglo_fusion[capacidad_fusion];
   printf("Cargar primer arreglo: \n");
   cargar_arreglo(capacidad,arreglo);
   printf("Cargar segundo arreglo: \n");
   cargar_arreglo(capacidad2,arreglo2);
   printf("Primer arreglo: \n");
   mostrar_arreglo(capacidad,arreglo);
   printf("Segundo arreglo: \n");
   mostrar_arreglo(capacidad2,arreglo2);
   fusionar_arreglos(arreglo,arreglo2,capacidad,capacidad2,arreglo_fusion);
   printf("Arreglo fusionado: \n");
   mostrar_arreglo(capacidad_fusion,arreglo_fusion);
   promedio_arreglo = promedio(capacidad,arreglo);
   printf("PROMEDIO PRIMER ARREGLO INGRESADO: %.2f\n",promedio_arreglo);
   minimo_arreglo = minimo(capacidad,arreglo);
   printf("MINIMO PRIMER ARREGLO INGRESADO: %d\n",minimo_arreglo);
   posicion_max = posicion_maximo(capacidad,arreglo);
   printf("POSICION MAXIMA PRIMER ARREGLO -> [%d] ",posicion_max);
   return 0;
}



#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 20



int cargar_arreglo(int cantidad, int arreglo[SIZE]){
   int i = 0;
   for (i=0;i<cantidad;i++){
      scanf("%i", &arreglo[i]);
   }
}




int mostrar_arreglo(int cantidad, int arreglo[SIZE]){
   int i=0;
   for (i = 0; i<cantidad;i++){
      printf("Posicion [%d] -> %d\n",i, arreglo[i]);
   }
}




float promedio(int cantidad, int arreglo[SIZE]){
   int i = 0;
   float promedio = 0;
   float suma = 0;
   for (i; i<cantidad;i++){
      suma = suma + arreglo[i];
   }
   promedio = suma/cantidad;
  return promedio;
}



int minimo(int cantidad, int arreglo[SIZE]){
   int i = 0;
   int min = arreglo[0];
   for (i; i<cantidad; i++){
      if (arreglo[i]<min){
         min = arreglo [i];
      }
   }
   return min;
}



int maximo(int cantidad, int arreglo[SIZE]){
   int i = 0;
   int max = arreglo[0];
   for (i; i<cantidad; i++){
      if (arreglo[i]>max){
         max = arreglo[i];
      } 
   }
   return max;
}



int *menor_a_mayor(int cantidad, int arreglo[]){
   int i = 0;
   int aux;
   int j;
   for (i; i<cantidad-1; i++){
      for (j=i+1; j<cantidad; j++ ){
         if (arreglo[i]>arreglo[j]){
            aux = arreglo[i];
            arreglo[i] = arreglo[j];
            arreglo[j] = aux;
         }
      }
   }
   return arreglo;
}



int *mayor_a_menor(int cantidad, int arreglo[SIZE]){
   int i = 0;
   int aux; 
   int j;
   for (i; i<cantidad-1; i++){
      for (j=i+1; j<cantidad; j++ ){
         if (arreglo[i]<arreglo[j]){
            aux = arreglo[i];
            arreglo[i] = arreglo[j];
            arreglo[j] = aux;
         }
      }
   }
   return arreglo;
}



int main(int argc, char *argv[])
{
   int i;
   int argumentos;
   int cargarArreglo;
   int cantidad;
   int ingresar[SIZE];
   int mostrarArreglo;
   int minimoArreglo;
   int opcion;
   int maximoArreglo;
   int *menorAMayorArreglo;
   int *mayorAMenorArreglo;
   float calcularPromedio;
   if (argc > 1)
   {
      for (i = 1; i<argc;i++)
      {
         sscanf(argv[i],"%i",&argumentos);
         ingresar[i] = argumentos;
      }
      printf("Seleccione una de las siguientes opciones: \n1 Para mostrar el arreglo.\n2 Para calcular promedio.\n3 Para mostar el minimo del arreglo.\n4 Para mostrar el maximo del arreglo.\n5 Para ordenar de menor a mayor.\n6 Para ordenar de mayor a menor.\n7 Para hacer todo.\n");
      scanf("%d", &opcion);
      switch (opcion)
      {
         case 1:
            mostrarArreglo =mostrar_arreglo(argc,ingresar);
            break;
         case 2:
            calcularPromedio = promedio(argc, ingresar);
            printf("El promedio es: %.2f\n", calcularPromedio);
            break;
         case 3:
            minimoArreglo = minimo(argc,ingresar);
            printf("El minimo del arreglo es: %d\n",minimoArreglo);
            break;
         case 4:
            maximoArreglo = maximo(argc, ingresar);
            printf("El maximo del arreglo es: %d\n", maximoArreglo);
            break;
         case 5:
            menorAMayorArreglo = menor_a_mayor(argc, ingresar);
            printf("El arreglo ordenado de menor a mayor es: \n");
            mostrar_arreglo(argc,menorAMayorArreglo);
            break;
         case 6:
            mayorAMenorArreglo = mayor_a_menor(argc, ingresar);
            printf("El arreglo ordenado de mayor a menor es: \n");
            mostrar_arreglo(argc, mayorAMenorArreglo);
            break;
         case 7:  
            mostrar_arreglo(argc,ingresar);
            calcularPromedio = promedio(argc, ingresar);
            printf("El promedio es: %.2f\n", calcularPromedio);
            minimoArreglo = minimo(argc,ingresar);
            printf("El minimo es: %d\n",minimoArreglo);
            maximoArreglo = maximo(argc, ingresar);
            printf("El maximo del arreglo es: %d\n", maximoArreglo);
            menorAMayorArreglo = menor_a_mayor(argc, ingresar);
            printf("El arreglo ordenado de menor a mayor es: \n");
            mostrar_arreglo(argc,menorAMayorArreglo);
            mayorAMenorArreglo = mayor_a_menor(argc, ingresar);
            printf("El arreglo ordenado de mayor a menor es: \n");
            mostrar_arreglo(argc, mayorAMenorArreglo);
            break;

         default:
            printf("Ingrese una opcion valida\n");
            break;
         }
      }
      else 
      {
         printf("Ingrese la cantidad de elementos que va a poseer el arreglo: \n");
         scanf("%i", &cantidad);
         printf("Ingrese el contenido del arreglo: \n");
         cargarArreglo = cargar_arreglo(cantidad,ingresar);
         printf("Seleccione una de las siguientes opciones: \n1 Para mostrar el arreglo.\n2 Para calcular promedio.\n3 Para mostar el minimo del arreglo.\n4 Para mostrar el maximo del arreglo.\n5 Para ordenar de menor a mayor.\n6 Para ordenar de mayor a menor.\n7 Para hacer todo.\n");
         scanf("%d",&opcion);
         switch (opcion)
         {
            case 1:
               mostrarArreglo = mostrar_arreglo(cantidad,ingresar);
               break;
            case 2:
               calcularPromedio = promedio(cantidad, ingresar);
               printf("El promedio es: %.2f\n", calcularPromedio);
               break;
            case 3:
               minimoArreglo = minimo(cantidad,ingresar);
               printf("El minimo es: %d\n",minimoArreglo);
               break;
            case 4:
               maximoArreglo = maximo(cantidad, ingresar);
               printf("El maximo del arreglo es: %d\n", maximoArreglo);
               break;
            case 5:
               menorAMayorArreglo = menor_a_mayor(cantidad, ingresar);
               printf("El arreglo ordenado de menor a mayor es: \n");
               mostrar_arreglo(cantidad,menorAMayorArreglo);
            break;
            case 6:
               mayorAMenorArreglo = mayor_a_menor(cantidad, ingresar);
               printf("El arreglo ordenado de mayor a menor es: \n");
               mostrar_arreglo(cantidad, mayorAMenorArreglo);
               break;
            case 7:
               mostrar_arreglo(cantidad,ingresar);
               calcularPromedio = promedio(cantidad, ingresar);
               printf("El promedio es: %.2f\n", calcularPromedio);
               minimoArreglo = minimo(cantidad,ingresar);
               printf("El minimo del arreglo es: %d\n",minimoArreglo);
               maximoArreglo = maximo(cantidad, ingresar);
               printf("El maximo del arreglo es: %d\n", maximoArreglo);
               menorAMayorArreglo = menor_a_mayor(cantidad, ingresar);
               printf("El arreglo ordenado de menor a mayor es: \n");
               mostrar_arreglo(cantidad,menorAMayorArreglo);
               mayorAMenorArreglo = mayor_a_menor(cantidad, ingresar);
               printf("El arreglo ordenado de mayor a menor es: \n");
               mostrar_arreglo(cantidad, mayorAMenorArreglo);
               break;
            default:
               printf("Ingrese una opcion valida\n");
               break;
         }
      }
   return 0;
}



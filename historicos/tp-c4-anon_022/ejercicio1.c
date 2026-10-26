

#include <stdio.h>
#include <string.h>
#define SIZE 50 
#define CADENA_SUPERADA -1
#define CANTIDAD_CADENA_SUPERADA -2

int largo_seguro(char cadena[SIZE],int capacidad)
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


int insercion_cadenas(char origen[SIZE], char destino[SIZE],int capacidad, int posicion)
{
   int largo_origen = largo_seguro(origen, 10);
   int largo_final;
   char aux[SIZE];
   int i= 0;
   int j= 0;
   int actual=0;
   while (i<posicion)
   {
      aux[j] = destino[i];
      i++;
      j++;
      actual++;
   }
   while (origen[i] != '\0')
   {
      aux[j] = origen[i];
      i++;
      j++;
   }
   while (i< posicion+largo_origen)
   {
      aux[j] = destino[actual];
      j++;
      actual++;
   }
   largo_final = largo_seguro(aux,15);
   return largo_final;
}

char copiar(char origen[SIZE], char destino[SIZE])
{

}
int main(int argc, char *argv[])
{
   int insercion;
   int largo;
   int i;
   int j;
   if (argc>2)
   {
      for (i=1;i<argc;i++)
      {
         largo = largo_seguro(argv[i], 10);
         printf("largo de %s es %d\n", argv[i], largo);
      }
      for (i=1;i<argc;i++)
      {
         insercion= insercion_cadenas(argv[i], argv[i+1],15,2);
         printf("%d", insercion);
      }
   } else 
   {
      return CANTIDAD_CADENA_SUPERADA;
   }
   return 0;
}
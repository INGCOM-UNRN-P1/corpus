

#include <stdio.h>
#include <string.h>
#define SIZE 15
#define TRUE 1
#define FALSE 0

int es_palindromo(char palabra[]){
   int longitud = strlen(palabra);
   int inicio = 0;
   if (longitud<=1)
   {
      return 1;
   }
   int fin = longitud -1;
   while (palabra[inicio] = palabra[fin]){
      if (inicio >= fin) return 1;
      inicio++;
      fin--;
   }
   return 0;
}
    



int main(){
   char cadena[SIZE];
   int evaluar;
   printf("Ingrese para determinar si es palindromo o no: \n");
   fgets(cadena,SIZE,stdin);
   evaluar = es_palindromo(cadena);
   if (evaluar==1){
      printf("true");
   }
   else {
      printf("false");
   }
   return 0;
}


#include <stdio.h>

int esMultiplo(int numero, int multiplo){
    int resto = 0;
    while (numero>=multiplo){
        numero = numero - multiplo;
        resto = multiplo;
    }
    return resto;
}



int main()
{
   int numero;
   int multiplo;
   int evaluar;
   printf("Ingrese el numero: \n");
   scanf("%d", &numero);
   printf("Ingrese el posible multiplo: \n");
   scanf("%d", &multiplo);
   evaluar = esMultiplo(numero,multiplo);
   if (evaluar==0){
    printf("Es multiplo");

   } 
   else
   {
    printf("No es multiplo");
   }
   return 0;
}
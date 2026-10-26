

#include <stdio.h>
#define TRUE 1 
#define FALSE 0

int es_primo(int numero){
    int i;
    for (i=2; i<numero/2; i++){
        if (numero%i==0){
            return 0;
        }
    return 1;    
    }
}

int main()
{
   int numero;
   printf("Ingrese un numero: \n");
   scanf("%d", &numero);
   if (es_primo(numero)){
    printf("True");
   } else {
    printf("False");
   }
   return 0;
}
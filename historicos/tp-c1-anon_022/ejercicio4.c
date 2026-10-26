

#include <stdio.h>

int compara(int numero, int otro_numero){
    if(numero<otro_numero){
        return -1; 
    }else if (numero==otro_numero){
        return 0;
    }else{
        return 1;
    }
}

int main()
{
   int numero1;
   int numero2;
   int resultado;
   printf("Ingrese el primer numero: \n");
   scanf("%i", &numero1);
   printf("Ingrese el 2do numero: \n");
   scanf("%i", &numero2);
   resultado = compara(numero1,numero2);
   printf("%i", resultado);
   return 0;
}
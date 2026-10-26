

#include <stdio.h>


int suma_lenta(int numero, int otro_numero)
{
    while(otro_numero>0){
        numero=numero+(1);
        otro_numero =otro_numero-(1);
        printf("%d\n",numero);
    }
    
} 

int main()
{
   int numero1,numero2,resultado;
   printf("Ingrese el primer numero\n");
   scanf("%d", &numero1);
   printf("Ingrese el segundo numero\n");
   scanf("%d", &numero2);
   resultado = sumaa_lenta(numero1,numero2);
   printf("%i", resultado);
   return 0;   
}
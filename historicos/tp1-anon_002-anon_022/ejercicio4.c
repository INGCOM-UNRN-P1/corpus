


#include <stdio.h>

int compara(int numero, int otro_numero)
{
    if (numero > otro_numero)
    {
        return 1;
    }
    else if (numero == otro_numero)
    {
        return 0;
    } 
    else 
    {
        return -1;
    }
}


int main()
{
   int numero;
   int otro_num;
   printf("Ingrese el primer numero: \n");
   scanf("%d", &numero);
   printf("ingrese el otro numero: \n");
   scanf("%d", &otro_num);
   printf("%d\n",compara(numero,otro_num));
   return 0;
}




#include <stdio.h>

int suma_lenta(int numero, int otro_numero)
{
    int i = 0;
    if (otro_numero > 0) 
    {
        for (int i ; i < otro_numero; i++) 
        {
            numero++;
        }
    } 
    else if (otro_numero < 0) 
    {
        for (int i ; i > otro_numero; i--) 
        {
            numero--;
        }
    }
   return numero;
}

int main()
{
    int numero;
    int otro_num;
    int suma;
    printf("Ingrese el primer numero: \n");
    scanf("%d", &numero);
    printf("ingrese el otro numero: \n");
    scanf("%d", &otro_num);
    suma = suma_lenta(numero, otro_num);
    printf("Resultado usando suma lenta: %d",suma);
    return 0;
}

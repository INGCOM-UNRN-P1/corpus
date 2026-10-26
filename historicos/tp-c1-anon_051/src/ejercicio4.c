

#include <stdio.h>

int compara(int numero, int otro_numero)
{
    int resultado;
    if ((numero - otro_numero) < 0)
    {
        resultado = -1;
    }
    else if ((numero - otro_numero) >0)
    {
        resultado = 1;
    }
    else if((numero - otro_numero) == 0)
    {
        resultado = 0;
    }
    return resultado;
    
}
int main()
{
    int numero, otro_numero, resultado;
    printf("Ingresar un numero entero: \n");
    scanf("%d", &numero);
    printf("Ingresar otro numero entero: \n");
    scanf("%d", &otro_numero);
    resultado = compara(numero, otro_numero);
    printf("%d", resultado);
    return 0;
    
}


#include <stdio.h>
 
int main(int argc, char *argv[])
{
    int entrada;
    int i;
    int resultado;
    
    for(i = 0; i < 3; i++)
    {
        printf("Ingrese un número entero mayor a 100. \n \t");
        scanf("%d", &entrada);

        if(entrada > 100)
        {
            break;
        }
    }
    if (entrada <= 100)
    {
        printf("Máximo de intentos permitidos. Programa finalizado.");
        return 0;
    }

    for (i = 2; i <=6; i++)
    {
        resultado = entrada % i;

        if(resultado == 0)
        {
            printf("Es múltiplo de %d: SI \n", i);
        }
        else
        {
            printf("Es múltiplo de %d: NO \n", i);
        }
    }

}
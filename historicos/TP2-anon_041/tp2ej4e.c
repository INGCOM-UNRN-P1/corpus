/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
@anon_041 de GitHub
*************************/
#include <stdio.h>

int main(int argc, char *argv[])
{
    int n = 0;
    int i;
	int j;
	while(1)
    {
        printf("Ingrese un numero para crear un cuadrado de asteriscos de esa longitud: ");
        scanf("%d", &n);
        if(n > 0)
            break;
        else
        {
            printf("El numero no puede ser negativo ni 0");
        }
    }

	for(i = 0; i < n ; i = i + 1)
    {
        for(j = 0; j < n ; j = j + 1)
        {
            printf("*");
        }
        printf("\n");
    }
	
	return 0;
}
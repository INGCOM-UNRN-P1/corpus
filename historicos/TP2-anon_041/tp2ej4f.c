
#include <stdio.h>

int main(int argc, char *argv[])
{
    int n = 0;
    int i;
	int j;
	int lado = 1;
	while(1)
    {
        printf("Ingrese un numero para crear un triangulo rectangulo de asteriscos de esa longitud: ");
        scanf("%d", &n);
        if(n > 0)
            break;
        else
        {
            printf("El numero no puede ser negativo ni 0");
        }
    }

	for(i = 1; i <= n ; i = i + 1)
    {
        for(j = 1; j <= lado ; j = j + 1)
        {
            printf("*");
        }
        printf("\n");
		lado = lado + 1;
    }
	
	return 0;
}
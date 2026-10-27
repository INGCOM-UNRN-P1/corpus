
#include <stdio.h>

int main(int argc, char *argv[])
{
    int n = 0;
    int i;
	while(1)
    {
        printf("Ingrese un numero para crear una linea de asteriscos de esa cantidad: ");
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
        printf("*");
	}
	
	return 0;
}
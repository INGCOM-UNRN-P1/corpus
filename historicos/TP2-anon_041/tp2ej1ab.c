/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
@anon_041 de GitHub
*************************/
#include <stdio.h>

int raiz(int numero);

int main(int argc, char *argv[])
{
	int n;
	int m;
	int resultado_raiz_n;
	int resultado_raiz_m;
	while(1)
    {
        printf("Ingrese dos numeros naturales para saber la raiz de cada uno de ellos! \nPrimer numero: ");
		scanf("%d", &n);
        if(n > 0)
            break;
        else
        {
            printf("El numero no puede ser negativo ni 0\n");
        }
    }
	while(1)
	{
		printf("Segundo numero: ");
		scanf("%d", &m);
		if(m > 0)
            break;
        else
        {
            printf("El numero no puede ser negativo ni 0\n");
        }
	}
	resultado_raiz_n = raiz(n);
	resultado_raiz_m = raiz(m);
    printf("Raiz de su primer numero: %d\nRaiz de su segundo numero: %d", resultado_raiz_n, resultado_raiz_m);
	
	return 0;
}

int raiz(int numero)
{
	int x = 1;
    int i = 0;
	while (1)
    {
        i = i + 1;
        x = (numero / x + x) / 2;
        if (i == numero + 1)
		{ 	
			break;
		}
    }
	return x;
}

/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
@anon_041 de GitHub
*************************/
#include <stdio.h>

int combinatorio(int n, int k);
int factorial(int n);

int main(int argc, char *argv[])
{
	int n;
	int k;
	int resultado_combinatorio;
	while(1)
    {
        printf("Ingrese dos numeros naturales para hacer su combinatiorio!\nPrimer numero: ");
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
		scanf("%d", &k);
		if(k > 0)
            break;
        else
        {
            printf("El numero no puede ser negativo ni 0\n");
        }
	}
	resultado_combinatorio = combinatorio(n, k);
	printf("%d", resultado_combinatorio);
	
	return 0;
}


int combinatorio(int n, int k)
{
	int factorial_k;
	int factorial_n;
	int factorial_nk;
	int nk = n - k;
	int resultado;
	factorial_n = factorial(n);
	factorial_k = factorial(k);
	factorial_nk = factorial(nk);
	resultado = factorial_n / (factorial_k * factorial_nk);
	
	return resultado;
}



int factorial(int n)
{
	unsigned long long int multiplicar;
	unsigned long long int factorial = 1;
	for (multiplicar = 1; multiplicar <= n; multiplicar++)
	{
		factorial = factorial * multiplicar;
	}
	
	return factorial;
}
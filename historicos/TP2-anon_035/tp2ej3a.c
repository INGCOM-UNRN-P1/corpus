/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
Ramrio Salcedo - @anon_035
*************************/

#include <stdio.h>

int main(int argc, char *argv[])
{
	int i, n;
	double factorial = 1;
    
    
    printf("Ingresa numero para calcular factorial: \n");
	
    scanf("%d", &n);
    
   
    for (i = 1; i <= n; i++)
	{
		
        factorial = factorial * i;
		
    }

    
    printf("Factorial de %d es: %0.lf \n", n, factorial);

    return 0;
}
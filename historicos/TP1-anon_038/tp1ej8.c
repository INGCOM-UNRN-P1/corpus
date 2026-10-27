
#include <stdio.h>
 
int main(int argc, char *argv[])
{
	int numero;
	int i;
	int x = 0;
	int y = 1;
	int z = 1;
	
	printf("Ingresar un numero para los elementos de Fibonacci: #");
	scanf("%d", &numero);
	
	printf("1 \n");
	
	for (i=1;i<numero;i++)
		{
		z = x + y;
		x = y;
		y = z;
		
		printf("%d \n", z);
	
		}

	return 0;

}


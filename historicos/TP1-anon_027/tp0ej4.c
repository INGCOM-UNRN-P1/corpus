

#include <stdio.h>

int main()
{
	int numero;
	
	scanf("%d", &numero);
	
	for (int i=2;i<7;i++)
	{
		if (numero % i == 0)
		{
			printf("Multiplo de %d?: SI \n", i);
		}
		else
		{
			printf("Multiplo de %d?: NO \n", i);
		}
		
	}
	
}
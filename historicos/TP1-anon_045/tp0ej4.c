
#include <stdio.h>


int main(int argc, char *argv[])
{
	int num1; 
	
	do
	{
		printf("Ingrese un numero entero mayor a 100:\t");
		scanf("%d", &num1);
	}
	while(num1 <100);
	
	for (int i=2; i<7; i+=1)
	{
		if (num1 % i == 0)
		{
			printf("Es multiplo de %d : SI\n",i);
		}
		else
		{
			printf("Es multiplo de %d : NO\n",i);
		}
	}
	

	
}




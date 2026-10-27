
#include <stdio.h>
int main(int argc, char *argv[])
{	
	int n;
	int aux_n;
	int i;
	int factorial;
	printf("Ingrese el valor n: ");
	scanf("%d", &n);
	aux_n=n;
	factorial=1;
	if(aux_n>0)
	{
		for(i=1;i<=aux_n;i++)
		{
			factorial=factorial*i;
		}
		printf("El factorial de %d!: %d\n",aux_n,factorial);
	}else if(n==0)
	{
		printf("El factorial de %d!: ",n);
	}else
	{
		printf("No existe el factorial para numeros negativos");
	}
	return 0;
}

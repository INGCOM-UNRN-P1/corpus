#include<stdio.h>

int calcular_raiz(int n);


int main(int argc, char *argv[])
{
	int n, m, resultado1, resultado2;
	
	do
	{
		printf("Digite el primer numero natural: ");
		scanf("%d", &n);
		if(n < 1)
		{
			printf("Un numero natural!\n");
		}
	}
	while(n < 1);
	
	do
	{
		printf("Digite el segundo numero natural: ");
		scanf("%d", &m);
		if(m < 1)
		{
			printf("Un numero natural!\n");
		}
	}
	while(m < 1);
	
	resultado1 = calcular_raiz(n);
	resultado2 = calcular_raiz(m);	
	printf("La raiz de %d es: %d", n, resultado1);
	printf("\nLa raiz de %d es: %d", m, resultado2);
	return 0;
}


int calcular_raiz(int n)
{
	int i, maximo;
	
	maximo = 0;
	i = 0;
	
	while(maximo <= n)
	{	
		i = i + 1;
		maximo = i * i;
	}
	
	if(maximo > n)
	{
		i = i -1;
	}
	return i;
}


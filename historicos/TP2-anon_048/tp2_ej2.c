#include<stdio.h>

int producto(int n, int m);
int potencia(int n, int m);

int main(int argc, char *argv[])
{
	int n, m, multi, poten;
	
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
	
	multi = producto(n, m);
	poten = potencia(n, m);	
	printf("El producto de %d x %d es: %d\n", n, m, multi);
	printf("%d elevado a %d es: %d", n, m, poten);
	
	return 0;
}


int producto(int n, int m)
{
	return n * m;
}


int potencia(int n, int m)
{
	int i, potencia;
	potencia = n;
	i = 2;
	
	while(i <= m)
	{
		potencia = potencia * n;
		i = i + 1;
	}
	
	return potencia;
	
}




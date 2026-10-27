

#include <stdio.h>

int compara(int numero1, int numero2);

int main()
{
	int comparacion;
	comparacion = compara(4,4);
	printf(" %d\n", comparacion);
	return 0;
}

int compara(int numero1, int numero2)
{	
	
	printf("Ingrese un numero \n");
	scanf("%d", &numero1);
	
	printf("Ingrese otro numero \n");
	scanf("%d", &numero2);
	
	if(numero1<numero2)
		return -1;
	if(numero1==numero2)
		return 0;
	else
		return 1;
}
	
	
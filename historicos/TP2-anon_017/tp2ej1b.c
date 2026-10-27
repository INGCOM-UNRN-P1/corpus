

#include <stdio.h>

int raiz(int numero);
int raiz2(int numero2);


int main()
{
	int numero;
	int numero2;
	int resultado1;
	int resultado2;
	printf("ingrese un numero mayor a 0: ");
	scanf("%d",&numero);
	printf("ingrese un numero mayor a 0: ");
	scanf("%d",&numero2);
	
	resultado1=raiz(numero);
	printf("\n la raiz del primer numero es: %d \n", resultado1);
	resultado2=raiz2(numero2);
	printf("la raiz del segundo numero es: %d", resultado2);
	
	
	
}

int raiz(int numero)
{
	int contador1=1;
	int resultado1;
	
	while (contador1<numero)
	{
		contador1 +=1;
		if(contador1*contador1<=numero)
		{
		 resultado1=contador1;
		}
		else
		{	
			;
		}
	}
	return resultado1;		
}

int raiz2(int numero2)
{
	int contador2=1;
	int resultado2;
	while (contador2<numero2)
	{
		contador2 +=1;
		if(contador2*contador2<=numero2)
		{
		 resultado2=contador2;
		}
		else
		{	
			;
		}
	}
	return resultado2;
}
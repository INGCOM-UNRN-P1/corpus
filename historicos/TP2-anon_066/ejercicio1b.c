/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_066
*************************/
#include <stdio.h>
int raizentera(int a)
{
	int i;
	int raizentera;
	for(i=1; i<a;i++)
	{
		if(i*i<=a)
		{
			raizentera=i;
		}
	}
	return raizentera;
}

int main(int argc, char *argv[])
{	
	int natural1;
	int natural2;
	int raiz1;
	int raiz2;
	printf("Ingrese un numero natural: ");
	scanf("%d",&natural1);
	if(natural1>0)
	{
		raiz1 = raizentera(natural1);
		printf("La raiz natural de %d = %d",natural1,raiz1);
	}else{
		printf("El numero ingresao %d no es un natural",natural1);
	}
	printf("\nIngrese otro numero natural: ");
	scanf("%d",&natural2);
	if(natural2>0)
	{
		raiz2 = raizentera(natural2);
		printf("La raiz natural de %d = %d",natural2,raiz2);
	}else{
		printf("El numero ingresao %d no es un natural",natural2);
	}
	return 0;
	
	
}


#include <stdio.h>
int producto(int a,int b)
{
	return a*b;
}
int potencia(int a,int b)
{
	int resultado;
	int i;
	int a0;
	resultado=a;
	a0=a;
	for(i=1; i<b;i++)
	{
		resultado=producto(a,a0);
		a= resultado;
	}
	return resultado;
}

int main(int argc, char *argv[])
{	
	int natural1;
	int natural2;
	int producto1;
	int potencia1;
	printf("Ingrese un numero natural: ");
	scanf("%d",&natural1);
	
	if(natural1>0)
	{
		printf("\nIngrese otro numero natural: ");
		scanf("%d",&natural2);
		if(natural2>0)
		{
			producto1=producto(natural1,natural2);
			potencia1=potencia(natural1,natural2);
			printf("El producto de %d y %d = %d",natural1,natural2,producto1);
			printf("\nLa potencia de %d y %d = %d",natural1,natural2,potencia1);
		}else{
			printf("El numero ingresado %d no es un natural",natural2);
		}
	}else{
		printf("El numero ingresado %d no es un natural",natural1);
	}	
	return 0;
	
	
}

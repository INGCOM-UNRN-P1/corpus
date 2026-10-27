
#include <stdio.h>
double factorial(int a)
{
	int i;
	unsigned resultado=1;
	for(i=a;i>0;i--){
		resultado= resultado*i;
	}
	return resultado;
}

int main(int argc, char *argv[])
{	
	int natural1;
	double factorial1;
	printf("Ingrese un numero natural: ");
	scanf("%d",&natural1);
	
	if(natural1>0)
	{
		factorial1=factorial(natural1);
		printf("El factorial de %d es %.0f ",natural1,factorial1);
	}else{
		printf("El numero ingresado %d no es un natural",natural1);
	}	
	return 0;
	
	
}

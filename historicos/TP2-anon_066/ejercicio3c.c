
#include <stdio.h>
double factorial(int a)
{
	int i;
	double resultado=1;
	for(i=a;i>0;i--){
		resultado= resultado*i;
	}
	return resultado;
}
double combinatorio(double nfactorial, double kfactorial, double nkfactorial)
{
	double combinatorio;
    combinatorio =nfactorial/(kfactorial*nkfactorial);
	return combinatorio;
}
int main(int argc, char *argv[])
{	
	int naturala;
	int naturalb;
	int nmb;
	double n;
	double k;
	double nk;
	double numero_combinatorio;
	int i;
	naturala=0;
	naturalb=0;
	n=0;
	k=0;
	nk=0;
	numero_combinatorio=0;
	printf("Ingrese un numero natural mayor a 1: ");
	scanf("%d",&naturala);
	
	if(naturala>1)
	{
		n=factorial(naturala);
		for(i=1;i<naturala;i++)
		{
			naturalb=i;
			nmb=naturala-naturalb;
			k=factorial(naturalb);
			nk=factorial(nmb);
			numero_combinatorio = combinatorio(n,k,nk);
			printf("\nEl combinatorio (%d %d) es %.0f \n",naturala,naturalb,numero_combinatorio);
		}	
	}else{
		printf("El numero ingresado %d no es un natural mayor a 1",naturala);
	}	
	return 0;
	
	
}

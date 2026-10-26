/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_066
*************************/
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
	printf("Ingrese un numero natural: ");
	scanf("%d",&naturala);
	
	if(naturala>0)
	{
		printf("\nIngrese otro numero natural: ");
		scanf("%d",&naturalb);
		if(naturalb>0)
		{
			n=factorial(naturala);

			k=factorial(naturalb);
			nmb=naturala-naturalb;
			if(nmb<1){
				printf("\nNo se puede calcular el combinatorio de (%d %d) ",naturala,naturalb);
			}else{
				nk=factorial(nmb);
				numero_combinatorio = combinatorio(n,k,nk);
				printf("\nEl combinatorio (%d %d) es %.0f",naturala,naturalb,numero_combinatorio);
			}
		}else{
			printf("\nEl numero ingresado %d no es un natural",naturalb);
		}
		
	}else{
		printf("El numero ingresado %d no es un natural",naturala);
	}	
	return 0;
	
	
}

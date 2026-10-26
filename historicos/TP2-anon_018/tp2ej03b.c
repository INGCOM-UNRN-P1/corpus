/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
@anon_018
*************************/

#include <stdio.h>
double factorial();
double combinatorio();

int main(int argc, char *argv[])
{
	int numeroN, numeroM;
	double res;
	printf("El siguiente programa el combinatorio de n sobre m,\n");
	printf("Ingrese un numero natural para n: ");
	scanf("%d", &numeroN);
	printf("Ingrese un numero natural y menor o igual a n para m: ");
	scanf("%d", &numeroM);
	
	if (numeroN>=0 && numeroM>=0 && numeroM<=numeroN)
	{
		res = combinatorio(numeroN, numeroM);
		printf("El combinatorio de %d sobre %d es: %0.f", numeroN, numeroM, res);
	}
	return 0;
}

double combinatorio(int numeroN, int numeroM,double rescombinatorio)
{//esta funcion calcula el convinatorio de n sobre m.
	int dif;
	double facN, facM, facDIF;
	dif = numeroN - numeroM;
	facN = factorial(numeroN);
	facM = factorial(numeroM);
	facDIF = factorial(dif);
	rescombinatorio = facN / (facM * facDIF);
	return rescombinatorio;
}

double factorial(int numero, double resultado)
{//esta funcion retorna el factorial de numero.
	int i;
	resultado = 1;
	for (i=1;i<=numero;i++)
	{
		resultado = resultado * i;
	}
	return resultado;
}

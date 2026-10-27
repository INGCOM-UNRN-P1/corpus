

#include <stdio.h>

int producto(int factor, int otrofactor);
int potencia(int base, int exponente);


int main()
{
	int numerouno;
	int numerodos;
	int multiplicacion;
	int elevar;
	
	printf("Ingrese dos numeros naturales:\n");
	scanf("%d", &numerouno);
	scanf("%d", &numerodos);
	
	multiplicacion = producto(numerouno, numerodos);
	elevar = potencia(numerouno, numerodos);
	
	printf("El producto de multiplicar %d por %d es: %d\n", numerouno, numerodos, multiplicacion);
	printf("El resultado de %d elevado a %d es: %d\n", numerouno, numerodos, elevar);
}


int producto(int factor, int otrofactor)
{
	int i = 1;
	int res = factor;

	for (i; i < otrofactor; i++)
	{
		res = res + factor;
	}
	return res;
}

int potencia(int base, int exponente)
{
	int i = 1;
	int res = base;

	for (i; i < exponente; i++)
	{
		res = producto(res, base);
	}
	return res;
}
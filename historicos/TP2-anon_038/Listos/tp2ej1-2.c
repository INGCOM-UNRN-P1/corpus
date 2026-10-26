/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_038
*************************/
#include <stdio.h>

int parte_entera(int numero)
{
	float temp, raiz = 0;
	raiz = numero / 2;
	temp = 0;
	
	while (raiz != temp)
		{
		temp = raiz;
		raiz = (numero/temp + temp) / 2;
		}
	return raiz;
}
 
 
int main(int argc, char *argv[])
{
	int n, m = 0;
	
	printf("Ingrese un numero \n # ");
	scanf("%d", &n);
	
	printf("Ingrese otro numero \n # ");
	scanf("%d", &m);

	int resultado_parte_entera_n = parte_entera(n);
	int resultado_parte_entera_m = parte_entera(m);
	
	printf("La parte entera de la raiz de %d es %d \n", n, resultado_parte_entera_n);
	printf("La parte entera de la raiz de %d es %d \n", m, resultado_parte_entera_m);
}


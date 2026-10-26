/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_038
*************************/
#include <stdio.h>
 
int producto(int n, int m)
	{
	int resultado = 0;
	while (m != 0)
		{
		m--;
		resultado = resultado + n;
		}
	return resultado;
	}

int potencia(int n, int m)
	{
	int resultado = 1;
	while (m != 0)
		{
		m--;
		resultado = resultado * n;
		}
	return resultado;
	}

int main(int argc, char *argv[])
{
	int n, m = 0;
	
	printf("Ingrese un numero NATURAL \n");
	scanf("%d", &n);

	printf("Ingrese otro numero NATURAL \n");
	scanf("%d", &m);
	
	int resultado_producto = producto(n, m);
	int resultado_potencia = potencia(n, m);
	
	printf("El resultado de n*m es #%d \n", resultado_producto);
	printf("El resultado de n^m es #%d \n", resultado_potencia);
	
}


/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_033 de GitHub
*************************/
#include <stdio.h>

int main(int argc, char *argv[])
{
    int numero_ingresado,contador = 0;
	unsigned long long valor_a = 0, valor_b = 1, valor_c;
	printf("Ingrese numero entero mayor a 100: ");
	scanf("%d",&numero_ingresado);
	while(valor_a < numero_ingresado)
    {
        printf(" %llu,",valor_a);
        valor_c = valor_a + valor_b;
        valor_a = valor_b;
        valor_b = valor_c;
	}
	printf("\n");
	return 0;
}

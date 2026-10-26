/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_051 de GitHub
*************************/
#include <stdio.h>
int cuentas(int A, int B);
int main(int argc, char *argv[])
{
	int A;
	int B;
	int total;
	printf("Ingrese un numero entero para hacer sus operaciones aritmeticas: \n");
	scanf("%d", &A);
	printf("Ingrese otro numero entero para hacer sus operaciones aritmeticas: \n");
	scanf("%d", &B);
	total = cuentas(A, B);
	return total;
	
}
int cuentas(int A, int B)
{
	double conversion_A = A;
	double conversion_B = B;
	int multiplicacion = 0;
	double division = 0;
	int resto = 0;
	multiplicacion = A*B;
	resto = A%B;
	division = conversion_A/conversion_B;
	printf("La multiplicacion da como resultado %d \n", multiplicacion);
	printf("El resto da como resultado %d \n", resto);
	printf("La division da como resultado %g \n", division);

}
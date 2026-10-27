
#include <stdio.h>
 
int main(int argc, char *argv[])
{
	int numero_A = 0;
	int numero_B = 0;
	int division = 0;
	int multiplicacion = 0;
	int resto = 0;
	
	printf("Ingrese el primer numero (numero A)");
	scanf("%d",&numero_A);
	printf("Ingrese el segundo numero (numero B)");
	scanf("%d",&numero_B);
	
	division = numero_A/numero_B;
	multiplicacion = numero_A*numero_B;
	resto = numero_A%numero_B;
	
	printf("Primer Numero (A): %d \nSegundo Numero (B): %d \nOperacion de Division (A/B): %d \nOperacion de Multiplicacion (A*B): %d \nOperacion de Resto (A%B): %d \n", numero_A, numero_B, division, multiplicacion, resto);
}
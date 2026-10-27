
#include <stdio.h>

int main(int argc, char *argv[])
{
	int A, B, multiplicacion, resto, division;
	
	division = 0;
	multiplicacion = 0;
	resto = 0;
	
	printf("Digite un numero entero: ");
	scanf("%d", &A);
	printf("Digite otro numero entero: ");
	scanf("%d", &B);
	
	multiplicacion = A * B;
	resto = A % B;
    division = A / B;
	
	printf("Primer numero: A = %d\n", A);
	printf("Segundo numero: B = %d\n", B);
	printf("Operador multiplicacion: A*B = %d\n", multiplicacion);
	printf("Operador division: A/B = %d\n", division);
	printf("Operador resto: A%B = %d\n", resto);
	
	return 0;
}


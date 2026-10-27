

#include <stdio.h>

int main(int argc, char *argv[])
{
	int numero1, numero2, multiplicacion, division, resto;
	
	printf("Ingrese primer valor \n");
	scanf("%d", &numero1);
	printf("Ingrese el segundo numero \n");
	scanf("%d", &numero2);
	printf("\n");
	
	multiplicacion = numero1 * numero2;
	
	division = numero1 / numero2;
	
	resto = numero1 % numero2;
	
	printf("Primer numero: A = %d\n\n", numero1);
	
	printf("Segundo numero: B = %d\n\n", numero2);
	
    printf("Operador multiplicacion: A*B =  %d \n\n", multiplicacion);
	
	printf("Operador división: A/B = %d \n\n", division);
	
	printf("Operador resto: A%B = %d \n\n", resto);
	
    return 0;
}

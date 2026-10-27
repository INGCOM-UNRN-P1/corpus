
#include <stdio.h>
 
int main(int argc, char *argv[]){
	int variable_a, variable_b;
	float multiplicacion, division, resto;
	
	multiplicacion = 0;
	division = 0;
	resto = 0;
	
	printf("Vamos a realizar las operaciones arimetricas: multiplicacion, division, resto \n");
	printf("ingrese el primer numero: ");
	scanf("%d", &variable_a);
	printf("ingrese el segundo numero: ");
	scanf("%d", &variable_b);
	
	multiplicacion = variable_a * variable_b;
	division = variable_a / variable_b;
	resto = variable_a % variable_b;
	
	printf("el resultado de la multiplicacion es: %.2f \n", multiplicacion);
	printf("el resultado de la division es: %.2f \n", division);
	printf("el resultado de la resto es: %.2f \n", resto);
	return 0;
}

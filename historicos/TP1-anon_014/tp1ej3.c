
#include <stdio.h>
int numero1, numero2;

int main(int argc, char *argv[])
{

	printf("Introduce dos enteros separados por una coma ',': ");
	scanf("%d,%d", &numero1, &numero2);
	
	printf("A: %d \n", numero1);	
	printf("B: %d \n", numero2);
	
    printf("\n El producto es: %d", multiplicacion(numero1, numero2));
	printf("\n La division es: %d", division(numero1, numero2));
	printf("\n El resto es: %d", resto(numero1, numero2));
    
}
multiplicacion (int numero1, int numero2)
{
	return(numero1*numero2);
}
division(int numero1, int numero2)
{
	return (numero1/numero2);
}
resto(int numero1, int numero2)
{
	return(numero1%numero2);
}
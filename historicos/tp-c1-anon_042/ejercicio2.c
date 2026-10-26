



#include <stdio.h>

float convertir_a_fahrenheit(float centigrados){
	return (centigrados * 1.8 + 32);
}

float convertir_a_centigrados(float fahrenheit){
	return (fahrenheit -32)/ 1.8;
}

int main()
{
	float centigrados, fahrenheit, return_a, return_b;
    printf("Ingrese grados centigrados. \n");
	scanf("%f", &centigrados);
	printf("Ingrese grados fahrenheit. \n");
	scanf("%f", &fahrenheit);
	
	return_a = convertir_a_fahrenheit(centigrados);
	return_b = convertir_a_centigrados(fahrenheit);
	
	printf("La conversion de centigrados a fahrenheit es de %f. \n", return_a);
	printf("La conversion de fahrenheit a centigrados es de %f. \n", return_b);
	
    return 0;
}

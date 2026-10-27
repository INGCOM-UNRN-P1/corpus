



#include <stdio.h>

float convertir_a_fahrenheit(float centigrados);
float convertir_a_centigrados(float fahrenheit);


int main()
{
	float temperatura;
	float resultado;
	
	printf("Ingrese una temperatura en grados Centigrados: \n");
	scanf("%f", &temperatura);
	
	resultado = convertir_a_fahrenheit(temperatura);
	printf("%.2f grados Centigrados equivale a %.2f grados Fahrenheit\n", temperatura, resultado);
	
	printf("\n");
	printf("\n");
	
	printf("Ingrese una temperatura en grados Fahrenheit: \n");
	scanf("%f", &temperatura);
	
	resultado = convertir_a_centigrados(temperatura);
	printf("%.2f grados Fahrenheit equivale a %.2f grados Centigrados\n", temperatura, resultado);
	printf("\n");
}

float convertir_a_fahrenheit(float centigrados)
{
	float resultado = (centigrados * 1.8f) + 32;
	return resultado;	
}

float convertir_a_centigrados(float fahrenheit)
{
	float resultado = (fahrenheit - 32) / 1.8f;
	return resultado;
}
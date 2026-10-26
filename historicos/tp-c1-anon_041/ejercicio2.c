

#include <stdio.h>


float convertir_a_fahrrenheit(float centigrados)
{
	return (centigrados * 1.8) + 32;
}


float convertir_a_centigrados(float fahrenheit)
{
	return (fahrenheit - 32) * 0.5555555555555556;
}


int main()
{
	float fahrenheit;
	float centigrados;
	int convertir;
	float resultado;
	printf("Ingrese 1 para convertir C° a F°\nIngrese 2 para convertir F° a C°\n: ");
    scanf("%d", &convertir);
	
	if(convertir==1)
	{
		printf("Ingrese el número C°: \n");
		scanf("%f", &centigrados);
		resultado = convertir_a_fahrrenheit(centigrados);
		printf("La conversión a F° es: %f \n", resultado);
	}
	else if(convertir==2)
	{
		printf("Ingrese el número F°: \n");
		scanf("%f", &fahrenheit);
		resultado = convertir_a_centigrados(fahrenheit);
		printf("La conversión a C° es: %f \n", resultado);
	}
	
	else
	{
		printf("No ingresó ni 1 o 2. \n");
	}
	return 0;
}
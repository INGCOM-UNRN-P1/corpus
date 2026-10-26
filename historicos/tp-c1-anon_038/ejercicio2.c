

#include <stdio.h>






//Definicion de la funcion para pasar de centigrados a fahrenheit
float convertir_a_fahrenheit(float centigrados)
	{
		float valor_salida;
		
		valor_salida = (centigrados * 9/5) + 32;
		return valor_salida;		
	}
	    
//Definicion de la funcion para pasar de fahrenheit a centigrados
float convertir_a_centigrados(float fahrenheit)
{
	float valor_salida;
	valor_salida = (fahrenheit * 9/5) + 32;
	return valor_salida;
}

int main()
{
	int seleccion_usuario;
	float centigrados, resultado, fahrenheit;
	
	printf("Ingrese (1) si quiere transoformar fahrenheit a centigrados o (0) si quiere hacer la operacion inversa \n");
	scanf("%d", &seleccion_usuario);
	
	if (seleccion_usuario == 1)
	{
		printf("Ingrese los grados fahreheit para convertir a centigrados \n");
		scanf("%f", &centigrados);
		
		resultado = convertir_a_fahrenheit(centigrados);	
	}
	else if (seleccion_usuario == 0)
	{
		printf("Ingrese los grados centigrados para convertir a fahrenheit \n");
		scanf("%f", &fahrenheit);
		
		resultado = convertir_a_centigrados(fahrenheit);	
	}
	else
	{
		printf("Valor ingresado no valido (%d) \n", seleccion_usuario);
	}
	
	printf("Su grados equivalen a %f", resultado);
}

/*
2.Conversión de temperaturas
Juan Bautista Mangold Moro - 2022
Programacion 1 - Ingenieria en computacion
*/

#include <stdio.h>

float convertir_a_centigrados(float fahrenheit) {
    return (fahrenheit - 32) / 1.8f;
}

float convertir_a_fahrrenheit(float celsius) {
    return (celsius * 1.8f) + 32;
}


int main(int argc, char *argv[]) {
    
	float fahrenheit = 0, celsius = 0;
	
	printf("Grados fahrenheit:\n");
    
	scanf("%f", &fahrenheit);
    
	float igualdad = convertir_a_centigrados(fahrenheit);
	
	printf("Es igual a %f grados Celsius.\n", igualdad);
    
	printf("Dime los grados C:\n");
	
	scanf("%f", &celsius);
	
	igualdad = convertir_a_fahrrenheit(celsius);
   
    printf("Es igual a %f grados Fahrenheit.\n", igualdad);
    
    return 0;
}


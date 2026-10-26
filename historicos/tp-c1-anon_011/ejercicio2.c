

#include <stdio.h>
float convertir_a_fahrenheit(float centigrados) {
	
	float fahrenheit;
	farenheit = (centigrados * 9/5) + 32;
	return fahrenheit;
}
float convertir_a_centigrados(float fahrenheit) {
	
	float centigrados;
	centigrados = (fahrenheit - 32) * 5/9;
	return centigrados;
}
int main()
{
	float temperatura;
	int opcion;
	
	temperatura = 0;
	opcion = 0;
	
	printf("Ingrese los grados de la temperatura(en farenheit o en centigrados\n");
	scanf("%f", &temperatura);
	while(opcion != 1 && opcion != 2) {	
		printf("ingrese 1 si quiere convertir de centigrados a farenheit, o ingrese 2 si quiere convertir de grados farenheit a centigrados\n");
		scanf("%d", &opcion);
		if (opcion == 1) {
			printf("%.2f °C son %.2f °F\n", temperatura, convertir_a_fahrenheit(temperatura));
		} 
		else if (opcion == 2) {
			printf("%.2f °F son %.2f °C\n", temperatura, convertir_a_centigrados(temperatura));
		}
		else
			printf("opcion incorrecta\n");
	}
	
	return 0;
}
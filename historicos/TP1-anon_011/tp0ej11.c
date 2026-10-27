
#include <stdio.h>
int suma_lenta(int numero, int otronumero){
	int suma;
	suma = numero + otronumero;
	return suma;
}	
int main(int argc, char *argv[]){
	int num1, num2;
	
	do
	{
		printf("ingrese un numero(tiene que ser un numero natural): ");
		scanf("%d", &num1);
		if(num1 <= 0) {
			printf("tiene que ingresar un numero mayor a 0 \n");
		}
	}
	while(num1 <= 0);
	
	do
	{
	printf("ingrese otro numero(tiene que ser un numero natural):");
		scanf("%d", &num2);
		if(num2 <= 0) {
			printf("tiene que ingresar un numero mayor a 0\n");
		}
	}
	while(num2 <= 0);
	
	printf("la suma de esos dos numeros es de: %d", suma_lenta(num1, num2));
	
	return 0;
}

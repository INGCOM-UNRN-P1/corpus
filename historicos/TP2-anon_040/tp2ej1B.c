

#include <stdio.h>

int RaizCuadrada(int numero){
	float i = 0;
	float resto;
	
	do
	{
		i = i + 0.1;
		resto = i * i ;
	}while (numero >= resto);
	
	return i;
}


int main (int argc, char *argv[]){
	int numero1;
	int numero2;
	int raiz1;
	int raiz2;
	
	printf("Ingrese un numero: ");
	scanf("%d", &numero1);
	
	printf("Ingrese un numero: ");
	scanf("%d", &numero2);
	
	raiz1 = RaizCuadrada(numero1);
	raiz2 = RaizCuadrada(numero2);
	
	printf("\n");
	printf("El numero de la raiz cuadrada %d es %d \n", numero1, raiz1);
	printf("El numero de la raiz cuadrada %d es %d \n", numero2, raiz2);
	
	return 0;
}
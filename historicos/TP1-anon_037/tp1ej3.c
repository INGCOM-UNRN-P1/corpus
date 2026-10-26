/*************************
Ingeniería en Computación - UNRN Andina
Programación 1
@anon_037
*************************/

#include <stdio.h>
int main()
{
	int numero_uno;
	int numero_dos;
	int producto;
	float division;
	int resto;
	
	printf("Ingrese un numero ");
	scanf("%d", &numero_uno);
	
	printf("Ingrese otro numero ");
	scanf("%d", &numero_dos);
	
	producto = numero_uno*numero_dos;
	printf("El producto de la multiplicacion de ambos es: %d \n",producto);
	
	division = ((float)numero_uno)/numero_dos;
	printf("El resultado de dividir %d en %d es: %f \n",numero_uno, numero_dos, division);
	
	resto = numero_uno%numero_dos;
	printf("El resto de la division de %d y %d es: %d",numero_uno, numero_dos, resto);
}


/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_066
*************************/
#include <stdio.h>
int main(int argc, char *argv[])
{	
	int numero;
	int numero_auxiliar; 
	printf("Ingrese un numero entre 1 y 7: ");
	scanf("%d", &numero);
	numero_auxiliar=numero;
	if(numero_auxiliar>=1 && numero_auxiliar<=7)
	{
		switch(numero_auxiliar){
			case 1:
				printf("%d - lunes",numero_auxiliar);
				break;
			case 2:
				printf("%d - martes",numero_auxiliar);
				break;
			case 3:
				printf("%d - miercoles",numero_auxiliar);
				break;
			case 4:
				printf("%d - jueves",numero_auxiliar);
				break;
			case 5:
				printf("%d - viernes",numero_auxiliar);
				break;
			case 6:
				printf("%d - sabado",numero_auxiliar);
				break;
			case 7:
				printf("%d - domingo",numero_auxiliar);
				break;
		}
	}else{
		printf("El numero ingresado %d no esta en el rango solicitado",numero_auxiliar);
	}
	return 0;
}

/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_066
*************************/
#include <stdio.h>
int main(int argc, char *argv[])
{	
	int i;
	int numero;
	int numero_aux;
	printf("Ingrese un numero entero mayor a 100:");
	scanf("%d", &numero);
	numero_aux=numero;
	if(numero_aux<=100){
		printf("El numero no es mayor a 100");
	}else{
		for(i=2;i<7;i++){
			if(numero_aux%i==0)
			{
				printf("Es multiplo de %d: SI\n",i);
			}else{
				printf("Es multiplo de %d: NO\n",i);
			}
		}
	}
	return 0;
}

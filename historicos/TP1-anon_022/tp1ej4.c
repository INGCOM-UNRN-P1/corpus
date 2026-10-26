/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_022
*************************/
#include <stdio.h>
 
int main(int argc, char *argv[])
{
	int numero,contador;
	contador=2;
	while(numero < 100){
		printf("Ingrese un numero entero mayor a 100:");
		scanf("%d",&numero);
		}
	while(contador<=6){
		if(numero%contador!=0){
			printf("No es multiplo de %d\n",contador);
			}
		else{
			printf("Es multiplo de %d\n", contador);
		}
	contador=contador+1;
	}
	return 0;
	
		
}
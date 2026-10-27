
#include <stdio.h>

 
int main(){
	int numero, i, multiplos = 0;
	
	do{
	printf("Ingrese un numero entero mayor a 100: ");
	scanf("%d", &numero);
	}while(numero < 100);
	
	for(i=2; i<=6; i++){
		multiplos = numero % i;
		if(multiplos == 0){
			printf("\nEs multiplo de %d: Si", i);
		}
		else{
			printf("\nEs multiplo de %d: No", i);
		}
	}
	return 0; 
}
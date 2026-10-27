
#include <stdio.h>
 
int main(){
	int numero;
	
	
	do{
		printf("\nIngrese un numero entero: ");
		scanf("%d", &numero);
		if(numero < 100){
			printf("\nEl numero es menor a 100");
		}
		else if(numero == 100){
			printf("\nEl numero es igual a 100");
		}
		else{
			printf("\nEl numero es mayor a 100");
		}
	}while(numero < 100);
	
	return 0;

}
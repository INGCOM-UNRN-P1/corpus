
#include <stdio.h>
 
int main(){
	int a, b, numero, i, fibonacci;
	fibonacci = 0;
	a = 0;
	b = 1;
	do{
		printf("Ingrese un numero mayor a 10: ");
		scanf("%d", &numero);	
	}while(numero < 10);
	
	printf("Los primeros numeros de la serie son: 0, 1, ");
	for(i=1 ; i < numero - 2; i++){
		fibonacci = a + b;
		if(fibonacci < numero){
			printf("%d,", fibonacci);
			a = b;
			b= fibonacci;
		}
			
		
	}

	return 0;

}

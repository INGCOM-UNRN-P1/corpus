

#include <stdio.h>


int factorial(int num){
	int cont = 1;
	int res;
	int i;
	
	for(i = 1; i <= num; i++){
   
      cont = cont * i;    
	}    

	return cont;
}


int main(int argc, char *argv[]){
	int num, i;
	
	printf("Ingrese un numero para el factorial: ");
	scanf("%d", &num);
	
	printf("\n\n");
	
	for(i = num; i > 0; i--){
		int factor = factorial(i);
		printf("El factorial de %d!: %d\n", num, factor);
		
	}
	
	
	return 0;
}
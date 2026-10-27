

#include <stdio.h>


int main(int argc, char *argv[]){
	int num;
	
	do{
		printf("ingrese un numero: ");
		scanf("%d", &num);
		
		if(num > 100){
			printf("El numero %d es mayor que 100\n", num);
		}else{
			printf("El numero %d es menor que 100\n", num);
		}
	}while(num <100);
	
	return 0;
}
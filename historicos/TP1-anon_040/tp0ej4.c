/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
Ojeda Walter - @walter_ojeda
*************************/
#include <stdio.h>

int verificacion(int num){
	
	if (num > 100){
		return 1;
	}else{
		return 0;
	}
}

int multiplo (int num1, int num2){
	int res;

	res = (num2 % num1);
	
	if(res == 0){
		return 1;
	}else{
		return 0;
	}
}
	
int main(int argc, char *argv[]){
	int num, i;

	printf("Ingrese un numero: ");
	scanf("%d", &num);
	
	int verif = verificacion(num);
	
	if(verif == 1){
		
		for(i = 2; i < 7; i++){
			int pollo = multiplo(i, num);
			
			if (pollo == 1){
				printf("Es multiplo de %d: SI\n", i);
			}else{
				printf("Es multiplo de %d: NO\n", i);
			}
		}
		
	}else{
		printf("Numero ingresado no valido, intente nuevamente.");
	}
	
	return 0;
}




#include <stdio.h>
int compara(int numero, int otronumero);

 
int main(){
	int numero1, numero2, resultado;
	
	printf("Ingrese un numero # ");
	scanf("%d", &numero1);
	printf("\nIngrese otro numero # ");
	scanf("%d", &numero2);
	
	resultado = compara(numero1, numero2);
	printf("\n# %d", resultado);
	
	
	return 0;
}
int compara(int numero, int otronumero){
	if(numero < otronumero){
		return -1;
	}
	else if(numero == otronumero){
		return 0;
	}
	else{
		return 1;
	}
}

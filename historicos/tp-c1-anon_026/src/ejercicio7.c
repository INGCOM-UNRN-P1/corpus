

#include <stdio.h>
#define TRUE 1
#define FALSE 0

   

int es_primo(int numero);
   
int main()
{
	int numero;
	printf("Ingrese un número \n");
	scanf("%i", &numero);
	if(es_primo(numero))		{
		printf("Es primo");
	}else{
		printf("No es primo");
	}
		return 0;	   
}



int es_primo(int num1)   

{
	int i, contador=0;
	
	
	for (i=1; i<=num1;i++){
		if(num1%i==0){
			contador++;
		}
	}
	if(contador>2){
		return FALSE;
	}
	else{
		return TRUE;
	}
}
	

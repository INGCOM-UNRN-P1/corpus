

#include <stdio.h>
#define TRUE 1
#define FALSE 0


   


int es_multiplo(int numero, int multiplo);
   
int main()
{
	int numero, multiplo;
	int resultado;
	printf("Ingrese un número: \n");
	scanf("%d",&numero);
	printf("Ingrese el número a analizar: \n");
	scanf("%d",&multiplo);
	resultado=es_multiplo(numero,multiplo);
	if(resultado)	{
		printf("El segundo número es múltiplo del primero", numero, multiplo);
	}else{
		printf("El segundo número No es múltiplo del primero", numero, multiplo);
	}
		return 0;	   
}



int es_multiplo(int numero, int multiplo)
{
	int resta;
	int i;
	resta = multiplo;
	    for(i=numero;i<multiplo && resta >=0;resta = resta - i){
        if(resta=0)
		return TRUE;
		
	return FALSE;
		}
}
	
	
		
	
	
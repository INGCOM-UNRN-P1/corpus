

#include <stdio.h>
void divisiones(int dividendo, int divisor){
	int contador;
	int cociente;
	
	cociente = 0;
	
	while(dividendo >= divisor){
		dividendo = dividendo - divisor;
		cociente++;		
	}
	printf("El cociente es: %d \n", cociente);
	printf("El resto es: %d \n", dividendo);
}

int main(){
	int dividendo;
	int divisor;
	
	printf ("Escriba el dividendo: ");
	scanf("%d",&dividendo);
	
	printf ("Escriba el divisor: ");
	scanf("%d",&divisor);
	
	divisiones(dividendo, divisor);
	
	return 0;	
}

//precondicion: Se le pide al usuario dos numeros
//poscondicion: la funcion realiza la division entera de los dos numero y calcula el cociente y el resto, luego los imprime por pantalla

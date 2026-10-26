


#include <stdio.h>

int main(int argc, char *argv[]) {
	float numero, otro_numero, cociente;
	
	cociente = 0;
	
	printf ("Escriba un numero: ");
	scanf ("%f", &numero);
	
	printf ("Escriba otro numero: ");
	scanf ("%f", &otro_numero);
	
	while (numero >= otro_numero){
		numero = numero - otro_numero;
		cociente = cociente + 1;}
	
	printf("El cociente es: %f . \n",cociente );
	printf("El resto  es: %f . \n",numero );
	

return 0;

}



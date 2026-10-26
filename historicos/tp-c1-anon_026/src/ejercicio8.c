

#include <stdio.h>
#include <string.h>
#define TRUE 1
#define FALSE 0


   


int es_palindromo(char * texto);
   
int main()
{
	char texto[50];
	int resultado;
	printf("Escriba una cadena de hasta 50 caracteres: \n");
	scanf("%s", &texto);
	resultado = es_palindromo(texto);
	if(resultado) {
		printf("Es palíndromo\n", texto);
	} else {
		printf("No es palíndromo\n", texto);
	}
}


int es_palindromo(char * texto)
{
	int longitud = strlen(texto);
	int posicion_i = 0;
	int posicion_f = longitud -1;
	
	while (texto[posicion_i] == texto[posicion_f]){
		if(posicion_i>=posicion_f) return TRUE;
		posicion_i++;
		posicion_f--;
		
	}
	return FALSE;
}
	
	




#include <stdio.h>
#include <string.h> 
#define longitud 50

int es_palindromo(char palabra[]){
	int len = strlen(palabra);
	int r = len -1;
	int resultado;
	for(int i = 0; i<=len; i++){
		if (palabra[i]==palabra[r])
		{
			resultado=1;
		}
		else
		{
			resultado=0;
			break;
		}
		r--;
	}
	return resultado;
}

int main()
{
    char palabra[longitud];
	int resultado;
	printf("Ingresar una palabra \n");
	scanf ("%s", palabra);
	resultado=es_palindromo(palabra);
	printf("[1]si [0]no => el resultado es %d", resultado);
	return 0;
}
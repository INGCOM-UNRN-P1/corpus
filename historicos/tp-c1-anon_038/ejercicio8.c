


#include <string.h>
#include <stdio.h>

#define LENGTH 200
#define TRUE 1
#define FALSE 0




int es_palindromo(char string[])
{
	int temp = 0;
	int longitud = strlen(string);
	int longitud_limpia = longitud -1;
	int resultado;
	
	while (temp <= longitud)
	{
		if (string [temp] == string [longitud_limpia])
		{
			temp = temp + 1;
			resultado = 1;
		}
		else
		{
			resultado = 0;
			break;
		}
		longitud_limpia = longitud_limpia - 1;
		}
	
	
	return resultado;
}

int main()
{
	char string [LENGTH];
	
	printf("Ingrese un texto para analizar si es o no palindromo \n");
	scanf("%s", string);
	
	int resultado = es_palindromo(string);
	
	printf("El resultado es (%d) (1 es TRUE y 0 es FALSE)", resultado);

}
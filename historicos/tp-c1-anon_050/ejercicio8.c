

#include <stdio.h>
#include <string.h>
// Pre: string lista
// Post: string True o False
int es_palindromo(char palin[])
{
    int i = 0;
	int largo = strlen(palin) - 1;
	
	while (largo > i)
	{
		if(palin[i++] != palin[largo--])
		{
			return 1;
		}
	}
	return 0;
}

int main()
{
    char lista[20];
    
    printf("Escriba una cadena: \n");
    scanf("%s", lista);
    if (es_palindromo(lista) == 0)
    {
        printf("True\n");
    }
    else
    {
        printf("False\n");
    }
    return 0;
}


#include <stdio.h>
#define MAX 999999999

void agregar(unsigned int dimension, char tablero[][MAX]);
void imprimir(unsigned int dimension, char tablero[][MAX]);

int main(int argc, char *argv[])
{
	int numero;
	printf("Este programa imprimira un triangulo con n asteriscos de altura.\n");
	printf("Ingrese un valor natural para n: ");
	scanf("%d", &numero);
	
	char tablero[numero][numero];
	agregar(numero, tablero);
	imprimir(numero, tablero);

	return 0;
}
void agregar(unsigned int dimension, char tablero[][MAX])
{
	int i, j, asteriscos;
	asteriscos = dimension;
	for (j=0;j<dimension;j++)
	{
		for (i=0;i<dimension;i++)
		{
			tablero[j][i] = ' ';
		}
	}
	for (j=0;j<dimension;j++)
	{
		for (i=0;i<asteriscos;i++)
		{
			tablero[j][i] = '*';
		}
		asteriscos--;
	}
}
void imprimir(unsigned int dimension, char tablero[][MAX])
{
	int i, j;
	for(i=0;i<dimension;i++)
    {
        for(j=0;j<dimension;j++)
        {
            printf("%c ", tablero[i][j]);
        }
        printf("\n");
    }
}
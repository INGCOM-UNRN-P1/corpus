

#include <stdio.h>
#define MAX 999999999

void agregar(unsigned int ancho, char tablero[][MAX]);
void imprimir(unsigned int ancho, char tablero[][MAX]);

int main(int argc, char *argv[])
{
	unsigned int numero;
	int i, j;
	printf("Este programa imprimira una linea con n asteriscos.\n");
	printf("Ingrese un valor natural para n: ");
	scanf("%d", &numero);
	char tablero[1][numero];
	agregar(numero, tablero);
	imprimir(numero, tablero);
	return 0;
}
void agregar(unsigned int ancho, char tablero[][MAX])
{
	int j;
	for(j=0;j<ancho;j++)
	{
		tablero[0][j] = '*';
	}
}
void imprimir(unsigned int ancho, char tablero[][MAX])
{
	int j, i;
	for(i=0;i<1;i++)
    {
        for(j=0;j<ancho;j++)
        {
            printf("%c ", tablero[i][j]);
        }
        printf("\n");
    }
}
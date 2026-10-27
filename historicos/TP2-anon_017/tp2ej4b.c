
#include <stdio.h>

int asterisco(int numero);

int main()
{
	
    int numero;
           
    printf("Ingrese un numero para un cuadrado en asteriscos: ");
    scanf("%d",&numero);
	
    asterisco(numero);

}

int asterisco(int numero)
{
	int columna;
	int fila;
	fila=0;
	
	while (fila<numero)
	{
		columna=0;
		while (columna<numero)
		{
			printf("*");
			columna +=1;
			
		}
		printf("\n");
		fila +=1;
	}

   return 0;
}
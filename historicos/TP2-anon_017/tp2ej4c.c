
#include <stdio.h>

int triangulo(int numero);

int main()
{
	
    int numero;
           
    printf("Ingrese un numero: ");
    scanf("%d",&numero);
	
    triangulo(numero);

}

int triangulo(int numero)
{	
	int columna;
	int fila;
	fila=0;
	int contador=0;
	
	while (fila<=numero)
	{
		columna=0;
		while (columna<contador)
		{
			printf("*");
			columna +=1;
			
		}
		printf("\n");
		fila +=1;
		contador+=1;
	}

	return 0;
}  




#include <stdio.h>

int SumaLenta(int numero, int otronumero);
 
int main () 
{
	int numeroUno;
	int numeroDos;
	int resultado;
   
	printf("\n");
    printf("\nIngrese dos numeros naturales para ser sumados: ");
	scanf("%d %d", &numeroUno, &numeroDos);
		
	resultado = SumaLenta(numeroUno, numeroDos);
	printf("\nEl resultado de la suma de %d y %d es %d.", numeroUno, numeroDos, resultado);
	printf("\n");
	
}

int SumaLenta(int numero, int otroNumero)
{
	for(int i = 1; i<otroNumero+1; i++)
	{
		numero += 1;
	}
	return numero;
}


#include <stdio.h>

int compara(int numero, int otronumero)
{
	int valor;
	
	if(numero > otronumero)
		
	{
		valor = 1;
	}
	else
	
	{
		if(otronumero > numero)
						
		{
			
			valor = -1;
		
		}
		else
			
		{
			valor = 0;
		}
	}

	return valor;
}



int main(int argc, char *argv[])
{
	
    int resultado, numero, otronumero;
	
	printf("Ingrese primer numero \n");
	
	scanf("%d" , &numero);
	
	printf("Ingrese segundo numero \n");
	
	scanf("%d" , &otronumero);
	
	resultado = compara(numero, otronumero);
	
	printf("El retorno es: %d", resultado);
	
    return 0;
}
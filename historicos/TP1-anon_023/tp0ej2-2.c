

#include <stdio.h>
int suma_lenta(int numero, int otronumero)
{
	int i;
	if (otronumero > 0)
	{
        for(i=0; i<otronumero; i++)
		{
            numero++;
		}
		return numero; 
	}
    else if(otronumero < 0)
	{
        for(i=0; i<-otronumero; i++)
		{
            numero--;
		}
		return numero;
	}
    else
	{
        return numero;
	}
}

int main(int argc, char *argv[])
{
	int numero, otronumero, resultado;
	
	printf("Ingrese un numero: ");
	scanf("%d", &numero);
	printf("ingrese otro numero: ");
	scanf("%d", &otronumero);
	
	resultado = suma_lenta(numero, otronumero);
	printf("%d + %d = %d", numero, otronumero, resultado);
	return 0;
}
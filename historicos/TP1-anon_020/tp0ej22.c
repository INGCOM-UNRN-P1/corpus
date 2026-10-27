

#include <stdio.h>
int suma_lenta(int numero1, int numero2)
{
	int i;
	if (numero2 > 0)
	{
        for(i=0; i<numero2; i++)
		{
            numero1++;
		}
		return numero1; 
	}
    else if(numero2 < 0)
	{
        for(i=0; i<-numero2; i++)
		{
            numero1--;
		}
		return numero1;
	}
    else
	{
        return numero1;
	}
}

int main(int argc, char *argv[])
{
	int numero1, numero2, resultado;
	
	printf("Ingrese el primer numero: ");
	scanf("%d", &numero1);
	printf("ingrese el segundo numero: ");
	scanf("%d", &numero2);
	
	resultado = suma_lenta(numero1, numero2);
	printf("el resultado de la suma lenta es: %d", resultado);
	return 0;
}
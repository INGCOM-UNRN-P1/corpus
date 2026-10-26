

#include <stdio.h>

int suma_lenta(int numero, int otronumero)
{
    int i = 1;
    int suma = 0;
    int absoluto = 0;
    int unidad = 1;			

    absoluto = otronumero;
    suma = numero; 

    if (otronumero < 0)			
   	{					
	absoluto = (-1) * otronumero;	
      unidad = -1;
	}

    if (otronumero != 0)
	{
	for (i = 1; i < absoluto + 1; i++)
	    {
	    suma = suma + unidad;
	    }
	}
    

    return suma;
}


int main(int argc, char *argv[])
{
    int numero = 0;
    int otronumero = 0;
    int resultado = 0;

    printf("Ingrese su primer numero :  \n");
    scanf("%d",&numero);
    printf("Ingrese el segundo numero : \n");
    scanf("%d",&otronumero);

    resultado = suma_lenta(numero, otronumero);
    printf("%d", resultado);
    return 0;
}

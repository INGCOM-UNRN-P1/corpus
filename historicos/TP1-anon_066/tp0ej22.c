
#include <stdio.h>
int suma_lenta(int numero, int otronumero)
{
	while(numero!=0)
	{
		otronumero=otronumero+1;
		numero=numero-1;
	}
	return otronumero;
}
int main(int argc, char *argv[])
{	
	int numero1;
	int numero2;
	int resultadosumalenta;
	printf("Ingresa un numero: ");
	scanf("%d", &numero1);
    	printf("Ingrese otro numero: ");
	scanf("%d", &numero2);
	resultadosumalenta = suma_lenta(numero1,numero2);
    	printf("\nEl resultado de la suma lenta es: %d",resultadosumalenta);
	return 0;
}

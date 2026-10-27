
#include <stdio.h>
 
 
int suma_lenta(int numero, int otronumero);
int main(int argc, char *argv[])
{
	int numero1, numero2, resultado;
	printf("Ingrese el primer numero\n");
	scanf("%d", &numero1);
	printf("Ingrese el segundo numero\n");
	scanf("%d", &numero2);
	resultado=suma_lenta(numero1,numero2);
	
	return 0;
}

int suma_lenta(int  numero,  int otronumero);
{
	while(otronumero>0){
		numero=numero+1;
		otronumero=otronumero-1;
		printf("%d\n", numero);
	}
	return 0;
}

#include <stdio.h>
 
int compara(int numero, int otronumero);
int main(int argc, char *argv[])
{
	int numero1, numero2;
	printf("Ingrese el primer numero");
	scanf("%d",  &numero);
	printf("Ingrese el segundo numero");
	scanf("%d", &numero2);
	resultado=compara(numero1,numero2);
	printf("%d", resultado);
	
}

int compara(int numero, int otronumero);
{
	if numero>otronumero{
		return 1;
	else{
		if numero==otronumero{
			return 0;
		else{
			return -1;
		}
		}
	}
	}
}	
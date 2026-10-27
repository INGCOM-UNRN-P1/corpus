
#include <stdio.h>
 
int main(int argc, char *argv[])
{
	int numero;
	do{
		printf("Ingrese el numero/n")
		scanf("%d",&numero);
		if(numero<100){
			printf("El numero es menor a 100");
		}
	}while (numero>=100);
		printf("Ek numero es mayor o igual a 100");
	return 0;
}
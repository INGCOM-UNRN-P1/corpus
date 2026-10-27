
#include <stdio.h>
 
int main(int argc, char *argv[])
{
	int numero_1;
	int numero_2;
	int menor;
	int mayor;
	
	printf("Ingrese un numero ENTERO \n");
	scanf("%d", &numero_1);

	printf("Ingrese otro numero ENTERO \n");
	scanf("%d", &numero_2);

	if (numero_1<numero_2)
		{
		menor = numero_1;
		mayor = numero_2;
		}
	else 
		{
		menor = numero_2;
		mayor = numero_1;
		}

	while (menor <= mayor)
		{
		printf("\n %d \n", menor);
		menor++;
		}

	return 0;
}

